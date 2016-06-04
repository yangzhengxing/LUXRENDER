#include <string> 
namespace luxrays { namespace ocl { 
std::string KernelSource_bvh_types = 
"#line 2 \"bvh_types.cl\"\n" 
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
"typedef struct {\n" 
"union {\n" 
"struct {\n" 
"// I can not use BBox here because objects with a constructor are not\n" 
"// allowed inside an union.\n" 
"float bboxMin[3];\n" 
"float bboxMax[3];\n" 
"} bvhNode;\n" 
"struct {\n" 
"unsigned int v[3];\n" 
"unsigned int meshIndex, triangleIndex;\n" 
"} triangleLeaf;\n" 
"struct {\n" 
"unsigned int leafIndex;\n" 
"unsigned int transformIndex, motionIndex; // transformIndex or motionIndex have to be NULL_INDEX (i.e. only one can be used)\n" 
"unsigned int meshOffsetIndex;\n" 
"} bvhLeaf; // Used by MBVH\n" 
"};\n" 
"// Most significant bit is used to mark leafs\n" 
"unsigned int nodeData;\n" 
"int pad0; // To align to float4\n" 
"} BVHAccelArrayNode;\n" 
; } } 
