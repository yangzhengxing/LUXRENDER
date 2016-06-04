#include <string> 
namespace luxrays { namespace ocl { 
std::string KernelSource_qbvh = 
"#line 2 \"qbvh_kernel.cl\"\n" 
"/***************************************************************************\n" 
"* Copyright 1998-2015 by authors (see AUTHORS.txt)                        *\n" 
"*                                                                         *\n" 
"*   This file is part of LuxRender.                                       *\n" 
"*                                                                         *\n" 
"* Licensed under the Apache License, Version 2.0 (the \"License\");         *\n" 
"* you may not use this file except in compliance with the License.        *\n" 
"* You may obtain a copy of the License at                                 *\n" 
"*                                                                         *\n" 
"*     http://www.apache.org/licenses/LICENSE-2.0                          *\n" 
"*                                                                         *\n" 
"* Unless required by applicable law or agreed to in writing, software     *\n" 
"* distributed under the License is distributed on an \"AS IS\" BASIS,       *\n" 
"* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*\n" 
"* See the License for the specific language governing permissions and     *\n" 
"* limitations under the License.                                          *\n" 
"***************************************************************************/\n" 
"#if defined(QBVH_IS_EMPTY)\n" 
"#define ACCELERATOR_INTERSECT_PARAM_DECL\n" 
"#define ACCELERATOR_INTERSECT_PARAM\n" 
"#else\n" 
"#if defined(QBVH_USE_LOCAL_MEMORY)\n" 
"#define QBVH_LOCAL_MEMORY_PARAM_DECL , __local int *nodeStacks\n" 
"#define QBVH_LOCAL_MEMORY_PARAM , nodeStacks\n" 
"#else\n" 
"#define QBVH_LOCAL_MEMORY_PARAM_DECL\n" 
"#define QBVH_LOCAL_MEMORY_PARAM\n" 
"#endif\n" 
"#define ACCELERATOR_INTERSECT_PARAM_DECL ,__global const QBVHNode* restrict nodes, __global const QuadTiangle* restrict quadTris QBVH_LOCAL_MEMORY_PARAM_DECL\n" 
"#define ACCELERATOR_INTERSECT_PARAM , nodes, quadTris QBVH_LOCAL_MEMORY_PARAM\n" 
"#endif\n" 
"void Accelerator_Intersect(\n" 
"const Ray *ray,\n" 
"RayHit *rayHit\n" 
"ACCELERATOR_INTERSECT_PARAM_DECL\n" 
") {\n" 
"#if defined(QBVH_IS_EMPTY)\n" 
"rayHit->t = ray->maxt;\n" 
"rayHit->meshIndex = NULL_INDEX;\n" 
"rayHit->triangleIndex = NULL_INDEX;\n" 
"\n"  
"return;\n" 
"#else\n" 
"// Prepare the ray for intersection\n" 
"QuadRay ray4;\n" 
"ray4.ox = (float4)ray->o.x;\n" 
"ray4.oy = (float4)ray->o.y;\n" 
"ray4.oz = (float4)ray->o.z;\n" 
"ray4.dx = (float4)ray->d.x;\n" 
"ray4.dy = (float4)ray->d.y;\n" 
"ray4.dz = (float4)ray->d.z;\n" 
"ray4.mint = (float4)ray->mint;\n" 
"ray4.maxt = (float4)ray->maxt;\n" 
"const float4 invDir0 = (float4)(1.f / ray4.dx.s0);\n" 
"const float4 invDir1 = (float4)(1.f / ray4.dy.s0);\n" 
"const float4 invDir2 = (float4)(1.f / ray4.dz.s0);\n" 
"const int signs0 = signbit(ray4.dx.s0);\n" 
"const int signs1 = signbit(ray4.dy.s0);\n" 
"const int signs2 = signbit(ray4.dz.s0);\n" 
"const int isigns0 = 1 - signs0;\n" 
"const int isigns1 = 1 - signs1;\n" 
"const int isigns2 = 1 - signs2;\n" 
"rayHit->meshIndex = NULL_INDEX;\n" 
"rayHit->triangleIndex = NULL_INDEX;\n" 
"//------------------------------\n" 
"// Main loop\n" 
"int todoNode = 0; // the index in the stack\n" 
"// nodeStack leads to a lot of local memory banks conflicts however it has not real\n" 
"// impact on performances (I guess access latency is hidden by other stuff).\n" 
"// Avoiding conflicts is easy to do but it requires to know the work group\n" 
"// size (not worth doing if there are not performance benefits).\n" 
"#if defined(QBVH_USE_LOCAL_MEMORY)\n" 
"__local int *nodeStack = &nodeStacks[QBVH_STACK_SIZE * get_local_id(0)];\n" 
"#else\n" 
"int nodeStack[QBVH_STACK_SIZE];\n" 
"#endif\n" 
"nodeStack[0] = 0; // first node to handle: root node\n" 
"//int maxDepth = 0;\n" 
"while (todoNode >= 0) {\n" 
"const int nodeData = nodeStack[todoNode];\n" 
"--todoNode;\n" 
"// Leaves are identified by a negative index\n" 
"if (!QBVHNode_IsLeaf(nodeData)) {\n" 
"__global const QBVHNode* restrict node = &nodes[nodeData];\n" 
"const int4 visit = QBVHNode_BBoxIntersect(\n" 
"node->bboxes[signs0][0], node->bboxes[isigns0][0],\n" 
"node->bboxes[signs1][1], node->bboxes[isigns1][1],\n" 
"node->bboxes[signs2][2], node->bboxes[isigns2][2],\n" 
"&ray4,\n" 
"invDir0, invDir1, invDir2);\n" 
"const int4 children = node->children;\n" 
"// For some reason doing logic operations with int4 is very slow\n" 
"nodeStack[todoNode + 1] = children.s3;\n" 
"todoNode += (visit.s3 && !QBVHNode_IsEmpty(children.s3)) ? 1 : 0;\n" 
"nodeStack[todoNode + 1] = children.s2;\n" 
"todoNode += (visit.s2 && !QBVHNode_IsEmpty(children.s2)) ? 1 : 0;\n" 
"nodeStack[todoNode + 1] = children.s1;\n" 
"todoNode += (visit.s1 && !QBVHNode_IsEmpty(children.s1)) ? 1 : 0;\n" 
"nodeStack[todoNode + 1] = children.s0;\n" 
"todoNode += (visit.s0 && !QBVHNode_IsEmpty(children.s0)) ? 1 : 0;\n" 
"//maxDepth = max(maxDepth, todoNode);\n" 
"} else {\n" 
"// Perform intersection\n" 
"const uint nbQuadPrimitives = QBVHNode_NbQuadPrimitives(nodeData);\n" 
"const uint offset = QBVHNode_FirstQuadIndex(nodeData);\n" 
"for (uint primNumber = offset; primNumber < (offset + nbQuadPrimitives); ++primNumber) {\n" 
"__global const QuadTiangle* restrict quadTri = &quadTris[primNumber];\n" 
"const float4 origx = quadTri->origx;\n" 
"const float4 origy = quadTri->origy;\n" 
"const float4 origz = quadTri->origz;\n" 
"const float4 edge1x = quadTri->edge1x;\n" 
"const float4 edge1y = quadTri->edge1y;\n" 
"const float4 edge1z = quadTri->edge1z;\n" 
"const float4 edge2x = quadTri->edge2x;\n" 
"const float4 edge2y = quadTri->edge2y;\n" 
"const float4 edge2z = quadTri->edge2z;\n" 
"const uint4 meshIndex = quadTri->meshIndex;\n" 
"const uint4 triangleIndex = quadTri->triangleIndex;\n" 
"QuadTriangle_Intersect(\n" 
"origx, origy, origz,\n" 
"edge1x, edge1y, edge1z,\n" 
"edge2x, edge2y, edge2z,\n" 
"meshIndex, triangleIndex,\n" 
"&ray4, rayHit);\n" 
"}\n" 
"}\n" 
"}\n" 
"//printf(\"MaxDepth=%02d\\n\", maxDepth);\n" 
"#endif\n" 
"}\n" 
"__kernel __attribute__((work_group_size_hint(64, 1, 1))) void Accelerator_Intersect_RayBuffer(\n" 
"__global const Ray* restrict rays,\n" 
"__global RayHit *rayHits,\n" 
"const uint rayCount\n" 
"ACCELERATOR_INTERSECT_PARAM_DECL\n" 
") {\n" 
"// Select the ray to check\n" 
"const int gid = get_global_id(0);\n" 
"if (gid >= rayCount)\n" 
"return;\n" 
"Ray ray;\n" 
"Ray_ReadAligned4_Private(&rays[gid], &ray);\n" 
"RayHit rayHit;\n" 
"Accelerator_Intersect(\n" 
"&ray,\n" 
"&rayHit\n" 
"ACCELERATOR_INTERSECT_PARAM\n" 
");\n" 
"// Write result\n" 
"__global RayHit *memRayHit = &rayHits[gid];\n" 
"memRayHit->t = rayHit.t;\n" 
"memRayHit->b1 = rayHit.b1;\n" 
"memRayHit->b2 = rayHit.b2;\n" 
"memRayHit->meshIndex = rayHit.meshIndex;\n" 
"memRayHit->triangleIndex = rayHit.triangleIndex;\n" 
"}\n" 
; } } 
