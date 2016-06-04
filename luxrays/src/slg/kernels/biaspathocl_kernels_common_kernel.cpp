#include <string> 
namespace slg { namespace ocl { 
std::string KernelSource_biaspathocl_kernels_common = 
"#line 2 \"biaspathocl_kernel_common.cl\"\n" 
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
"//------------------------------------------------------------------------------\n" 
"// Kernel parameters\n" 
"//------------------------------------------------------------------------------\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_0)\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_0 \\\n" 
", __global float *filmRadianceGroup0\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_0\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_1)\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_1 \\\n" 
", __global float *filmRadianceGroup1\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_1\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_2)\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_2 \\\n" 
", __global float *filmRadianceGroup2\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_2\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_3)\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_3 \\\n" 
", __global float *filmRadianceGroup3\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_3\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_4)\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_4 \\\n" 
", __global float *filmRadianceGroup4\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_4\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_5)\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_5 \\\n" 
", __global float *filmRadianceGroup5\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_5\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_6)\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_6 \\\n" 
", __global float *filmRadianceGroup6\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_6\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_7)\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_7 \\\n" 
", __global float *filmRadianceGroup7\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_RADIANCE_GROUP_7\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_ALPHA)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_ALPHA \\\n" 
", __global float *filmAlpha\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_ALPHA\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_DEPTH)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_DEPTH \\\n" 
", __global float *filmDepth\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_DEPTH\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_POSITION)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_POSITION \\\n" 
", __global float *filmPosition\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_POSITION\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_GEOMETRY_NORMAL)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_GEOMETRY_NORMAL \\\n" 
", __global float *filmGeometryNormal\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_GEOMETRY_NORMAL\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_SHADING_NORMAL)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_SHADING_NORMAL \\\n" 
", __global float *filmShadingNormal\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_SHADING_NORMAL\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_MATERIAL_ID)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_MATERIAL_ID \\\n" 
", __global uint *filmMaterialID\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_MATERIAL_ID\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_DIRECT_DIFFUSE)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_DIRECT_DIFFUSE \\\n" 
", __global float *filmDirectDiffuse\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_DIRECT_DIFFUSE\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_DIRECT_GLOSSY)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_DIRECT_GLOSSY \\\n" 
", __global float *filmDirectGlossy\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_DIRECT_GLOSSY\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_EMISSION)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_EMISSION \\\n" 
", __global float *filmEmission\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_EMISSION\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_INDIRECT_DIFFUSE)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_INDIRECT_DIFFUSE \\\n" 
", __global float *filmIndirectDiffuse\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_INDIRECT_DIFFUSE\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_INDIRECT_GLOSSY)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_INDIRECT_GLOSSY \\\n" 
", __global float *filmIndirectGlossy\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_INDIRECT_GLOSSY\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_INDIRECT_SPECULAR)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_INDIRECT_SPECULAR \\\n" 
", __global float *filmIndirectSpecular\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_INDIRECT_SPECULAR\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_MATERIAL_ID_MASK)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_MATERIAL_ID_MASK \\\n" 
", __global float *filmMaterialIDMask\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_MATERIAL_ID_MASK\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_DIRECT_SHADOW_MASK)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_DIRECT_SHADOW_MASK \\\n" 
", __global float *filmDirectShadowMask\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_DIRECT_SHADOW_MASK\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_INDIRECT_SHADOW_MASK)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_INDIRECT_SHADOW_MASK \\\n" 
", __global float *filmIndirectShadowMask\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_INDIRECT_SHADOW_MASK\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_UV)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_UV \\\n" 
", __global float *filmUV\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_UV\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_RAYCOUNT)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_RAYCOUNT \\\n" 
", __global float *filmRayCount\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_RAYCOUNT\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_BY_MATERIAL_ID)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_BY_MATERIAL_ID \\\n" 
", __global float *filmByMaterialID\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_BY_MATERIAL_ID\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_IRRADIANCE)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_IRRADIANCE \\\n" 
", __global float *filmIrradiance\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_IRRADIANCE\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_OBJECT_ID)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_OBJECT_ID \\\n" 
", __global uint *filmObjectID\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_OBJECT_ID\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_OBJECT_ID_MASK)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_OBJECT_ID_MASK \\\n" 
", __global float *filmObjectIDMask\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_OBJECT_ID_MASK\n" 
"#endif\n" 
"#if defined(PARAM_FILM_CHANNELS_HAS_BY_OBJECT_ID)\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_BY_OBJECT_ID \\\n" 
", __global float *filmByObjectID\n" 
"#else\n" 
"#define KERNEL_ARGS_FILM_CHANNELS_BY_OBJECT_ID\n" 
"#endif\n" 
"#define KERNEL_ARGS_FILM \\\n" 
", const uint filmWidth, const uint filmHeight \\\n" 
", const uint filmSubRegion0, const uint filmSubRegion1 \\\n" 
", const uint filmSubRegion2, const uint filmSubRegion3 \\\n" 
"KERNEL_ARGS_FILM_RADIANCE_GROUP_0 \\\n" 
"KERNEL_ARGS_FILM_RADIANCE_GROUP_1 \\\n" 
"KERNEL_ARGS_FILM_RADIANCE_GROUP_2 \\\n" 
"KERNEL_ARGS_FILM_RADIANCE_GROUP_3 \\\n" 
"KERNEL_ARGS_FILM_RADIANCE_GROUP_4 \\\n" 
"KERNEL_ARGS_FILM_RADIANCE_GROUP_5 \\\n" 
"KERNEL_ARGS_FILM_RADIANCE_GROUP_6 \\\n" 
"KERNEL_ARGS_FILM_RADIANCE_GROUP_7 \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_ALPHA \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_DEPTH \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_POSITION \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_GEOMETRY_NORMAL \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_SHADING_NORMAL \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_MATERIAL_ID \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_DIRECT_DIFFUSE \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_DIRECT_GLOSSY \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_EMISSION \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_INDIRECT_DIFFUSE \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_INDIRECT_GLOSSY \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_INDIRECT_SPECULAR \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_MATERIAL_ID_MASK \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_DIRECT_SHADOW_MASK \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_INDIRECT_SHADOW_MASK \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_UV \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_RAYCOUNT \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_BY_MATERIAL_ID \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_IRRADIANCE \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_OBJECT_ID \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_OBJECT_ID_MASK \\\n" 
"KERNEL_ARGS_FILM_CHANNELS_BY_OBJECT_ID\n" 
"#if defined(PARAM_HAS_INFINITELIGHTS)\n" 
"#define KERNEL_ARGS_INFINITELIGHTS \\\n" 
", const float worldCenterX \\\n" 
", const float worldCenterY \\\n" 
", const float worldCenterZ \\\n" 
", const float worldRadius\n" 
"#else\n" 
"#define KERNEL_ARGS_INFINITELIGHTS\n" 
"#endif\n" 
"#if defined(PARAM_HAS_NORMALS_BUFFER)\n" 
"#define KERNEL_ARGS_NORMALS_BUFFER \\\n" 
", __global const Vector* restrict vertNormals\n" 
"#else\n" 
"#define KERNEL_ARGS_NORMALS_BUFFER\n" 
"#endif\n" 
"#if defined(PARAM_HAS_UVS_BUFFER)\n" 
"#define KERNEL_ARGS_UVS_BUFFER \\\n" 
", __global const UV* restrict vertUVs\n" 
"#else\n" 
"#define KERNEL_ARGS_UVS_BUFFER\n" 
"#endif\n" 
"#if defined(PARAM_HAS_COLS_BUFFER)\n" 
"#define KERNEL_ARGS_COLS_BUFFER \\\n" 
", __global const Spectrum* restrict vertCols\n" 
"#else\n" 
"#define KERNEL_ARGS_COLS_BUFFER\n" 
"#endif\n" 
"#if defined(PARAM_HAS_ALPHAS_BUFFER)\n" 
"#define KERNEL_ARGS_ALPHAS_BUFFER \\\n" 
", __global const float* restrict vertAlphas\n" 
"#else\n" 
"#define KERNEL_ARGS_ALPHAS_BUFFER\n" 
"#endif\n" 
"#if defined(PARAM_HAS_ENVLIGHTS)\n" 
"#define KERNEL_ARGS_ENVLIGHTS \\\n" 
", __global const uint* restrict envLightIndices \\\n" 
", const uint envLightCount\n" 
"#else\n" 
"#define KERNEL_ARGS_ENVLIGHTS\n" 
"#endif\n" 
"#if defined(PARAM_HAS_INFINITELIGHT)\n" 
"#define KERNEL_ARGS_INFINITELIGHT \\\n" 
", __global const float* restrict infiniteLightDistribution\n" 
"#else\n" 
"#define KERNEL_ARGS_INFINITELIGHT\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_0)\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_0 \\\n" 
", __global const ImageMap* restrict imageMapDescs, __global const float* restrict imageMapBuff0\n" 
"#else\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_0\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_1)\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_1 \\\n" 
", __global const float* restrict imageMapBuff1\n" 
"#else\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_1\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_2)\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_2 \\\n" 
", __global const float* restrict imageMapBuff2\n" 
"#else\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_2\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_3)\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_3 \\\n" 
", __global const float* restrict imageMapBuff3\n" 
"#else\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_3\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_4)\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_4 \\\n" 
", __global const float* restrict imageMapBuff4\n" 
"#else\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_4\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_5)\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_5 \\\n" 
", __global const float* restrict imageMapBuff5\n" 
"#else\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_5\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_6)\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_6 \\\n" 
", __global const float* restrict imageMapBuff6\n" 
"#else\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_6\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_7)\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_7 \\\n" 
", __global const float* restrict imageMapBuff7\n" 
"#else\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGE_7\n" 
"#endif\n" 
"#define KERNEL_ARGS_IMAGEMAPS_PAGES \\\n" 
"KERNEL_ARGS_IMAGEMAPS_PAGE_0 \\\n" 
"KERNEL_ARGS_IMAGEMAPS_PAGE_1 \\\n" 
"KERNEL_ARGS_IMAGEMAPS_PAGE_2 \\\n" 
"KERNEL_ARGS_IMAGEMAPS_PAGE_3 \\\n" 
"KERNEL_ARGS_IMAGEMAPS_PAGE_4 \\\n" 
"KERNEL_ARGS_IMAGEMAPS_PAGE_5 \\\n" 
"KERNEL_ARGS_IMAGEMAPS_PAGE_6 \\\n" 
"KERNEL_ARGS_IMAGEMAPS_PAGE_7\n" 
"#define KERNEL_ARGS \\\n" 
"const uint engineFilmWidth, const uint engineFilmHeight \\\n" 
", __global GPUTask *tasks \\\n" 
", __global GPUTaskDirectLight *tasksDirectLight \\\n" 
", __global GPUTaskPathVertexN *tasksPathVertexN \\\n" 
", __global GPUTaskStats *taskStats \\\n" 
", __global SampleResult *taskResults \\\n" 
", __global float *pixelFilterDistribution \\\n" 
"/* Film parameters */ \\\n" 
"KERNEL_ARGS_FILM \\\n" 
"/* Scene parameters */ \\\n" 
"KERNEL_ARGS_INFINITELIGHTS \\\n" 
", __global const Material* restrict mats \\\n" 
", __global const Texture* restrict texs \\\n" 
", __global const SceneObject* restrict sceneObjs \\\n" 
", __global const Mesh* restrict meshDescs \\\n" 
", __global const Point* restrict vertices \\\n" 
"KERNEL_ARGS_NORMALS_BUFFER \\\n" 
"KERNEL_ARGS_UVS_BUFFER \\\n" 
"KERNEL_ARGS_COLS_BUFFER \\\n" 
"KERNEL_ARGS_ALPHAS_BUFFER \\\n" 
", __global const Triangle* restrict triangles \\\n" 
", __global const Camera* restrict camera \\\n" 
"/* Lights */ \\\n" 
", __global const LightSource* restrict lights \\\n" 
"KERNEL_ARGS_ENVLIGHTS \\\n" 
", __global const uint* restrict meshTriLightDefsOffset \\\n" 
"KERNEL_ARGS_INFINITELIGHT \\\n" 
", __global const float* restrict lightsDistribution \\\n" 
"/* Images */ \\\n" 
"KERNEL_ARGS_IMAGEMAPS_PAGES \\\n" 
"ACCELERATOR_INTERSECT_PARAM_DECL\n" 
"//------------------------------------------------------------------------------\n" 
"// To initialize image maps page pointer table\n" 
"//------------------------------------------------------------------------------\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_0)\n" 
"#define INIT_IMAGEMAPS_PAGE_0 imageMapBuff[0] = imageMapBuff0;\n" 
"#else\n" 
"#define INIT_IMAGEMAPS_PAGE_0\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_1)\n" 
"#define INIT_IMAGEMAPS_PAGE_1 imageMapBuff[1] = imageMapBuff1;\n" 
"#else\n" 
"#define INIT_IMAGEMAPS_PAGE_1\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_2)\n" 
"#define INIT_IMAGEMAPS_PAGE_2 imageMapBuff[2] = imageMapBuff2;\n" 
"#else\n" 
"#define INIT_IMAGEMAPS_PAGE_2\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_3)\n" 
"#define INIT_IMAGEMAPS_PAGE_3 imageMapBuff[3] = imageMapBuff3;\n" 
"#else\n" 
"#define INIT_IMAGEMAPS_PAGE_3\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_4)\n" 
"#define INIT_IMAGEMAPS_PAGE_4 imageMapBuff[4] = imageMapBuff4;\n" 
"#else\n" 
"#define INIT_IMAGEMAPS_PAGE_4\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_5)\n" 
"#define INIT_IMAGEMAPS_PAGE_5 imageMapBuff[5] = imageMapBuff5;\n" 
"#else\n" 
"#define INIT_IMAGEMAPS_PAGE_5\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_6)\n" 
"#define INIT_IMAGEMAPS_PAGE_6 imageMapBuff[6] = imageMapBuff6;\n" 
"#else\n" 
"#define INIT_IMAGEMAPS_PAGE_6\n" 
"#endif\n" 
"#if defined(PARAM_IMAGEMAPS_PAGE_7)\n" 
"#define INIT_IMAGEMAPS_PAGE_7 imageMapBuff[7] = imageMapBuff7;\n" 
"#else\n" 
"#define INIT_IMAGEMAPS_PAGE_7\n" 
"#endif\n" 
"#if defined(PARAM_HAS_IMAGEMAPS)\n" 
"#define INIT_IMAGEMAPS_PAGES \\\n" 
"__global const float* restrict imageMapBuff[PARAM_IMAGEMAPS_COUNT]; \\\n" 
"INIT_IMAGEMAPS_PAGE_0 \\\n" 
"INIT_IMAGEMAPS_PAGE_1 \\\n" 
"INIT_IMAGEMAPS_PAGE_2 \\\n" 
"INIT_IMAGEMAPS_PAGE_3 \\\n" 
"INIT_IMAGEMAPS_PAGE_4 \\\n" 
"INIT_IMAGEMAPS_PAGE_5 \\\n" 
"INIT_IMAGEMAPS_PAGE_6 \\\n" 
"INIT_IMAGEMAPS_PAGE_7\n" 
"#else\n" 
"#define INIT_IMAGEMAPS_PAGES\n" 
"#endif\n" 
"//------------------------------------------------------------------------------\n" 
"// InitSeed Kernel\n" 
"//------------------------------------------------------------------------------\n" 
"__kernel __attribute__((work_group_size_hint(64, 1, 1))) void InitSeed(\n" 
"uint seedBase,\n" 
"__global GPUTask *tasks) {\n" 
"//if (get_global_id(0) == 0)\n" 
"//	printf(\"sizeof(BSDF) = %dbytes\\n\", sizeof(BSDF));\n" 
"//if (get_global_id(0) == 0)\n" 
"//	printf(\"sizeof(HitPoint) = %dbytes\\n\", sizeof(HitPoint));\n" 
"//if (get_global_id(0) == 0)\n" 
"//	printf(\"sizeof(GPUTask) = %dbytes\\n\", sizeof(GPUTask));\n" 
"//if (get_global_id(0) == 0)\n" 
"//	printf(\"sizeof(SampleResult) = %dbytes\\n\", sizeof(SampleResult));\n" 
"const size_t gid = get_global_id(0);\n" 
"// Initialize the task\n" 
"__global GPUTask *task = &tasks[gid];\n" 
"// For testing/debugging\n" 
"//MangleMemory((__global unsigned char *)task, sizeof(GPUTask));\n" 
"// Initialize random number generator\n" 
"Seed seed;\n" 
"Rnd_Init(seedBase + gid, &seed);\n" 
"// Save the seed\n" 
"task->seed.s1 = seed.s1;\n" 
"task->seed.s2 = seed.s2;\n" 
"task->seed.s3 = seed.s3;\n" 
"}\n" 
"//------------------------------------------------------------------------------\n" 
"// InitStats Kernel\n" 
"//------------------------------------------------------------------------------\n" 
"__kernel __attribute__((work_group_size_hint(64, 1, 1))) void InitStat(\n" 
"__global GPUTaskStats *taskStats) {\n" 
"const size_t gid = get_global_id(0);\n" 
"__global GPUTaskStats *taskStat = &taskStats[gid];\n" 
"taskStat->raysCount = 0;\n" 
"}\n" 
"//------------------------------------------------------------------------------\n" 
"// MergePixelSamples\n" 
"//------------------------------------------------------------------------------\n" 
"__kernel __attribute__((work_group_size_hint(64, 1, 1))) void MergePixelSamples(\n" 
"const uint pass,\n" 
"const uint tileStartX, const uint tileStartY,\n" 
"const uint tileWidth, const uint tileHeight,\n" 
"const uint tileTotalWidth, const uint tileTotalHeight,\n" 
"const uint engineFilmWidth, const uint engineFilmHeight,\n" 
"__global SampleResult *taskResults\n" 
"// Film parameters\n" 
"KERNEL_ARGS_FILM\n" 
") {\n" 
"const size_t gid = get_global_id(0);\n" 
"const uint pixelX = gid % tileTotalWidth;\n" 
"const uint pixelY = gid / tileTotalWidth;\n" 
"if ((gid >= tileTotalWidth * tileTotalHeight) ||\n" 
"(pixelX >= tileWidth) ||\n" 
"(pixelY >= tileHeight) ||\n" 
"(tileStartX + pixelX >= engineFilmWidth) ||\n" 
"(tileStartY + pixelY >= engineFilmHeight))\n" 
"return;\n" 
"uint index;\n" 
"if (!GetSampleResultIndex(pass, tileTotalWidth, tileTotalHeight, pixelX, pixelY, &index))\n" 
"return;\n" 
"__global SampleResult *sampleResult = &taskResults[index];\n" 
"//--------------------------------------------------------------------------\n" 
"// Initialize Film radiance group pointer table\n" 
"//--------------------------------------------------------------------------\n" 
"__global float *filmRadianceGroup[PARAM_FILM_RADIANCE_GROUP_COUNT];\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_0)\n" 
"filmRadianceGroup[0] = filmRadianceGroup0;\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_1)\n" 
"filmRadianceGroup[1] = filmRadianceGroup1;\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_2)\n" 
"filmRadianceGroup[2] = filmRadianceGroup2;\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_3)\n" 
"filmRadianceGroup[3] = filmRadianceGroup3;\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_4)\n" 
"filmRadianceGroup[4] = filmRadianceGroup4;\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_5)\n" 
"filmRadianceGroup[5] = filmRadianceGroup5;\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_6)\n" 
"filmRadianceGroup[6] = filmRadianceGroup6;\n" 
"#endif\n" 
"#if defined(PARAM_FILM_RADIANCE_GROUP_7)\n" 
"filmRadianceGroup[7] = filmRadianceGroup7;\n" 
"#endif\n" 
"//--------------------------------------------------------------------------\n" 
"// Radiance clamping\n" 
"//--------------------------------------------------------------------------\n" 
"// It is now done at tile level inside the TileRepository on the CPU\n" 
"//--------------------------------------------------------------------------\n" 
"// Merge all samples and accumulate statistics\n" 
"//--------------------------------------------------------------------------\n" 
"#if defined(RENDER_ENGINE_RTBIASPATHOCL)\n" 
"// .05f is just a fake weight to allow the preview samples to be fast out-weighted\n" 
"// by normal samples\n" 
"const float weight = RT_IsPreview(pass) ? .05f : (PARAM_AA_SAMPLES * PARAM_AA_SAMPLES);\n" 
"#else\n" 
"const float weight = PARAM_AA_SAMPLES * PARAM_AA_SAMPLES;\n" 
"#endif\n" 
"#if (PARAM_AA_SAMPLES == 1)\n" 
"Film_AddSample(pixelX, pixelY, sampleResult, weight\n" 
"FILM_PARAM);\n" 
"#else\n" 
"SampleResult result = sampleResult[0];\n" 
"for (uint i = 1; i < PARAM_AA_SAMPLES * PARAM_AA_SAMPLES; ++i)\n" 
"SR_Accumulate(&sampleResult[i], &result);\n" 
"SR_Normalize(&result, 1.f / (PARAM_AA_SAMPLES * PARAM_AA_SAMPLES));\n" 
"// I have to save result in __global space in order to be able\n" 
"// to use Film_AddSample(). OpenCL can be so stupid some time...\n" 
"sampleResult[0] = result;\n" 
"Film_AddSample(pixelX, pixelY, sampleResult, weight\n" 
"FILM_PARAM);\n" 
"#endif\n" 
"}\n" 
; } } 
