#include <string> 
namespace slg { namespace ocl { 
std::string KernelSource_materialdefs_template_mix = 
"#line 2 \"materialdefs_funcs_mix.cl\"\n" 
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
"// Mix material\n" 
"//\n" 
"// One instance of this file for each Mix material is used in Compiled scene\n" 
"// class after having expanded the following parameters.\n" 
"//\n" 
"// Preprocessing parameters:\n" 
"//  <<CS_MIX_MATERIAL_INDEX>>\n" 
"//  <<CS_MAT_A_MATERIAL_INDEX>>\n" 
"//  <<CS_MAT_A_PREFIX>>\n" 
"//  <<CS_MAT_A_POSTFIX>>\n" 
"//  <<CS_MAT_B_MATERIAL_INDEX>>\n" 
"//  <<CS_MAT_B_PREFIX>>\n" 
"//  <<CS_MAT_B_POSTFIX>>\n" 
"//  <<CS_FACTOR_TEXTURE>>\n" 
"//------------------------------------------------------------------------------\n" 
"BSDFEvent Material_Index<<CS_MIX_MATERIAL_INDEX>>_GetEventTypes(__global const Material *material\n" 
"MATERIALS_PARAM_DECL) {\n" 
"return\n" 
"<<CS_MAT_A_PREFIX>>_GetEventTypes<<CS_MAT_A_POSTFIX>>(&mats[<<CS_MAT_A_MATERIAL_INDEX>>]\n" 
"MATERIALS_PARAM) |\n" 
"<<CS_MAT_B_PREFIX>>_GetEventTypes<<CS_MAT_B_POSTFIX>>(&mats[<<CS_MAT_B_MATERIAL_INDEX>>]\n" 
"MATERIALS_PARAM);\n" 
"}\n" 
"bool Material_Index<<CS_MIX_MATERIAL_INDEX>>_IsDelta(__global const Material *material\n" 
"MATERIALS_PARAM_DECL) {\n" 
"return\n" 
"<<CS_MAT_A_PREFIX>>_IsDelta<<CS_MAT_A_POSTFIX>>(&mats[<<CS_MAT_A_MATERIAL_INDEX>>]\n" 
"MATERIALS_PARAM) &&\n" 
"<<CS_MAT_B_PREFIX>>_IsDelta<<CS_MAT_B_POSTFIX>>(&mats[<<CS_MAT_B_MATERIAL_INDEX>>]\n" 
"MATERIALS_PARAM);\n" 
"}\n" 
"#if defined(PARAM_HAS_PASSTHROUGH)\n" 
"float3 Material_Index<<CS_MIX_MATERIAL_INDEX>>_GetPassThroughTransparency(__global const Material *material,\n" 
"__global HitPoint *hitPoint, const float3 localFixedDir, const float passThroughEvent\n" 
"MATERIALS_PARAM_DECL) {\n" 
"const uint transpTexIndex = material->transpTexIndex;\n" 
"if (transpTexIndex != NULL_INDEX) {\n" 
"return DefaultMaterial_GetPassThroughTransparency(material, hitPoint, localFixedDir, passThroughEvent\n" 
"TEXTURES_PARAM);\n" 
"} else {\n" 
"const float factor = <<CS_FACTOR_TEXTURE>>;\n" 
"const float weight2 = clamp(factor, 0.f, 1.f);\n" 
"const float weight1 = 1.f - weight2;\n" 
"if (passThroughEvent < weight1)\n" 
"return <<CS_MAT_A_PREFIX>>_GetPassThroughTransparency<<CS_MAT_A_POSTFIX>>(&mats[<<CS_MAT_A_MATERIAL_INDEX>>],\n" 
"hitPoint, localFixedDir, passThroughEvent / weight1 MATERIALS_PARAM);\n" 
"else\n" 
"return <<CS_MAT_B_PREFIX>>_GetPassThroughTransparency<<CS_MAT_B_POSTFIX>>(&mats[<<CS_MAT_B_MATERIAL_INDEX>>],\n" 
"hitPoint, localFixedDir, (passThroughEvent - weight1) / weight2 MATERIALS_PARAM);\n" 
"}\n" 
"}\n" 
"#endif\n" 
"float3 Material_Index<<CS_MIX_MATERIAL_INDEX>>_Evaluate(__global const Material *material,\n" 
"__global HitPoint *hitPoint, const float3 lightDir, const float3 eyeDir,\n" 
"BSDFEvent *event, float *directPdfW\n" 
"MATERIALS_PARAM_DECL) {\n" 
"/*#if defined(PARAM_HAS_BUMPMAPS)\n" 
"const float3 shadeN = VLOAD3F(&hitPoint->shadeN.x);\n" 
"const float3 dpdu = VLOAD3F(&hitPoint->dpdu.x);\n" 
"const float3 dpdv = VLOAD3F(&hitPoint->dpdv.x);\n" 
"Frame frame;\n" 
"Frame_Set_Private(&frame, dpdu, dpdv, shadeN);\n" 
"#endif*/\n" 
"float3 result = BLACK;\n" 
"const float factor = <<CS_FACTOR_TEXTURE>>;\n" 
"const float weight2 = clamp(factor, 0.f, 1.f);\n" 
"const float weight1 = 1.f - weight2;\n" 
"if (directPdfW)\n" 
"*directPdfW = 0.f;\n" 
"//--------------------------------------------------------------------------\n" 
"// Evaluate material A\n" 
"//--------------------------------------------------------------------------\n" 
"BSDFEvent eventMatA = NONE;\n" 
"if (weight1 > 0.f) {\n" 
"const float3 lightDirA = lightDir;\n" 
"const float3 eyeDirA = eyeDir;\n" 
"float directPdfWMatA;\n" 
"const float3 matAResult = <<CS_MAT_A_PREFIX>>_Evaluate<<CS_MAT_A_POSTFIX>>(&mats[<<CS_MAT_A_MATERIAL_INDEX>>],\n" 
"hitPoint, lightDirA, eyeDirA, &eventMatA, &directPdfWMatA\n" 
"MATERIALS_PARAM);\n" 
"if (!Spectrum_IsBlack(matAResult)) {\n" 
"result += weight1 * matAResult;\n" 
"if (directPdfW)\n" 
"*directPdfW += weight1 * directPdfWMatA;\n" 
"}\n" 
"}\n" 
"\n"  
"//--------------------------------------------------------------------------\n" 
"// Evaluate material B\n" 
"//--------------------------------------------------------------------------\n" 
"\n"  
"BSDFEvent eventMatB = NONE;\n" 
"if (weight2 > 0.f) {\n" 
"const float3 lightDirB = lightDir;\n" 
"const float3 eyeDirB = eyeDir;\n" 
"float directPdfWMatB;\n" 
"const float3 matBResult = <<CS_MAT_B_PREFIX>>_Evaluate<<CS_MAT_B_POSTFIX>>(&mats[<<CS_MAT_B_MATERIAL_INDEX>>],\n" 
"hitPoint, lightDirB, eyeDirB, &eventMatB, &directPdfWMatB\n" 
"MATERIALS_PARAM);\n" 
"if (!Spectrum_IsBlack(matBResult)) {\n" 
"result += weight2 * matBResult;\n" 
"if (directPdfW)\n" 
"*directPdfW += weight2 * directPdfWMatB;\n" 
"}\n" 
"}\n" 
"*event = eventMatA | eventMatB;\n" 
"return result;\n" 
"}\n" 
"float3 Material_Index<<CS_MIX_MATERIAL_INDEX>>_Sample(__global const Material *material,\n" 
"__global HitPoint *hitPoint, const float3 fixedDir, float3 *sampledDir, const float u0, const float u1,\n" 
"#if defined(PARAM_HAS_PASSTHROUGH)\n" 
"const float passThroughEvent,\n" 
"#endif\n" 
"float *pdfW, float *cosSampledDir, BSDFEvent *event, const BSDFEvent requestedEvent\n" 
"MATERIALS_PARAM_DECL) {\n" 
"const float factor = <<CS_FACTOR_TEXTURE>>;\n" 
"const float weight2 = clamp(factor, 0.f, 1.f);\n" 
"const float weight1 = 1.f - weight2;\n" 
"const bool sampleMatA = (passThroughEvent < weight1);\n" 
"const float weightFirst = sampleMatA ? weight1 : weight2;\n" 
"const float weightSecond = sampleMatA ? weight2 : weight1;\n" 
"const float passThroughEventFirst = sampleMatA ? (passThroughEvent / weight1) : (passThroughEvent - weight1) / weight2;\n" 
"__global const Material *matA = &mats[<<CS_MAT_A_MATERIAL_INDEX>>];\n" 
"__global const Material *matB = &mats[<<CS_MAT_B_MATERIAL_INDEX>>];\n" 
"const float3 fixedDirFirst = fixedDir;\n" 
"float3 result = sampleMatA ?\n" 
"<<CS_MAT_A_PREFIX>>_Sample<<CS_MAT_A_POSTFIX>>(matA, hitPoint, fixedDirFirst, sampledDir,\n" 
"u0, u1,\n" 
"#if defined(PARAM_HAS_PASSTHROUGH)\n" 
"passThroughEventFirst,\n" 
"#endif\n" 
"pdfW, cosSampledDir, event, requestedEvent MATERIALS_PARAM):\n" 
"<<CS_MAT_B_PREFIX>>_Sample<<CS_MAT_B_POSTFIX>>(matB, hitPoint, fixedDirFirst, sampledDir,\n" 
"u0, u1,\n" 
"#if defined(PARAM_HAS_PASSTHROUGH)\n" 
"passThroughEventFirst,\n" 
"#endif\n" 
"pdfW, cosSampledDir, event, requestedEvent MATERIALS_PARAM);\n" 
"if (Spectrum_IsBlack(result))\n" 
"return BLACK;\n" 
"*pdfW *= weightFirst;\n" 
"result *= *pdfW;\n" 
"BSDFEvent eventSecond;\n" 
"float pdfWSecond;\n" 
"const float3 fixedDirSecond = fixedDir;\n" 
"const float3 sampledDirSecond = *sampledDir;\n" 
"float3 evalSecond = sampleMatA ?\n" 
"<<CS_MAT_B_PREFIX>>_Evaluate<<CS_MAT_B_POSTFIX>>(matB, hitPoint,\n" 
"sampledDirSecond, fixedDirSecond, &eventSecond, &pdfWSecond\n" 
"MATERIALS_PARAM) :\n" 
"<<CS_MAT_A_PREFIX>>_Evaluate<<CS_MAT_A_POSTFIX>>(matA, hitPoint,\n" 
"sampledDirSecond, fixedDirSecond, &eventSecond, &pdfWSecond\n" 
"MATERIALS_PARAM);\n" 
"if (!Spectrum_IsBlack(evalSecond)) {\n" 
"result += weightSecond * evalSecond;\n" 
"*pdfW += weightSecond * pdfWSecond;\n" 
"}\n" 
"return result / *pdfW;\n" 
"}\n" 
"float3 Material_Index<<CS_MIX_MATERIAL_INDEX>>_GetEmittedRadiance(__global const Material *material,\n" 
"__global HitPoint *hitPoint\n" 
"MATERIALS_PARAM_DECL) {\n" 
"if (material->emitTexIndex != NULL_INDEX)\n" 
"return Material_GetEmittedRadianceWithoutDynamic(material, hitPoint MATERIALS_PARAM);\n" 
"else {\n" 
"float3 result = BLACK;\n" 
"const float factor = <<CS_FACTOR_TEXTURE>>;\n" 
"const float weight2 = clamp(factor, 0.f, 1.f);\n" 
"const float weight1 = 1.f - weight2;\n" 
"if (weight1 > 0.f)\n" 
"result += weight1 * <<CS_MAT_A_PREFIX>>_GetEmittedRadiance<<CS_MAT_A_POSTFIX>>(&mats[<<CS_MAT_A_MATERIAL_INDEX>>],\n" 
"hitPoint\n" 
"MATERIALS_PARAM);\n" 
"if (weight2 > 0.f)\n" 
"result += weight2 * <<CS_MAT_B_PREFIX>>_GetEmittedRadiance<<CS_MAT_B_POSTFIX>>(&mats[<<CS_MAT_B_MATERIAL_INDEX>>],\n" 
"hitPoint\n" 
"MATERIALS_PARAM);\n" 
"return result;\n" 
"}\n" 
"}\n" 
"#if defined(PARAM_HAS_VOLUMES)\n" 
"uint Material_Index<<CS_MIX_MATERIAL_INDEX>>_GetInteriorVolume(__global const Material *material,\n" 
"__global HitPoint *hitPoint, const float passThroughEvent\n" 
"MATERIALS_PARAM_DECL) {\n" 
"if (material->interiorVolumeIndex != NULL_INDEX)\n" 
"return material->interiorVolumeIndex;\n" 
"const float factor = <<CS_FACTOR_TEXTURE>>;\n" 
"const float weight2 = clamp(factor, 0.f, 1.f);\n" 
"const float weight1 = 1.f - weight2;\n" 
"if (passThroughEvent < weight1)\n" 
"return <<CS_MAT_A_PREFIX>>_GetInteriorVolume<<CS_MAT_A_POSTFIX>>(&mats[<<CS_MAT_A_MATERIAL_INDEX>>],\n" 
"hitPoint, passThroughEvent / weight1\n" 
"MATERIALS_PARAM);\n" 
"else\n" 
"return <<CS_MAT_B_PREFIX>>_GetInteriorVolume<<CS_MAT_B_POSTFIX>>(&mats[<<CS_MAT_B_MATERIAL_INDEX>>],\n" 
"hitPoint, (passThroughEvent - weight1) / weight2\n" 
"MATERIALS_PARAM);\n" 
"}\n" 
"uint Material_Index<<CS_MIX_MATERIAL_INDEX>>_GetExteriorVolume(__global const Material *material,\n" 
"__global HitPoint *hitPoint, const float passThroughEvent\n" 
"MATERIALS_PARAM_DECL) {\n" 
"if (material->exteriorVolumeIndex != NULL_INDEX)\n" 
"return material->exteriorVolumeIndex;\n" 
"const float factor = <<CS_FACTOR_TEXTURE>>;\n" 
"const float weight2 = clamp(factor, 0.f, 1.f);\n" 
"const float weight1 = 1.f - weight2;\n" 
"if (passThroughEvent < weight1)\n" 
"return <<CS_MAT_A_PREFIX>>_GetExteriorVolume<<CS_MAT_A_POSTFIX>>(&mats[<<CS_MAT_A_MATERIAL_INDEX>>],\n" 
"hitPoint, passThroughEvent / weight1\n" 
"MATERIALS_PARAM);\n" 
"else\n" 
"return <<CS_MAT_B_PREFIX>>_GetExteriorVolume<<CS_MAT_B_POSTFIX>>(&mats[<<CS_MAT_B_MATERIAL_INDEX>>],\n" 
"hitPoint, (passThroughEvent - weight1) / weight2\n" 
"MATERIALS_PARAM);\n" 
"}\n" 
"#endif\n" 
; } } 
