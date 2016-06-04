#include <string> 
namespace slg { namespace ocl { 
std::string KernelSource_materialdefs_funcs_clearvol = 
"#line 2 \"materialdefs_funcs_clearvol.cl\"\n" 
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
"// ClearVol material\n" 
"//\n" 
"// ClearVol hasn't scattering so none of the below functions is really used.\n" 
"//------------------------------------------------------------------------------\n" 
"#if defined (PARAM_ENABLE_MAT_CLEAR_VOL)\n" 
"BSDFEvent ClearVolMaterial_GetEventTypes() {\n" 
"return DIFFUSE | REFLECT;\n" 
"}\n" 
"float3 ClearVolMaterial_Evaluate(\n" 
"__global HitPoint *hitPoint, const float3 lightDir, const float3 eyeDir,\n" 
"BSDFEvent *event, float *directPdfW) {\n" 
"return BLACK;\n" 
"}\n" 
"float3 ClearVolMaterial_Sample(\n" 
"__global HitPoint *hitPoint, const float3 fixedDir, float3 *sampledDir,\n" 
"const float u0, const float u1, \n" 
"#if defined(PARAM_HAS_PASSTHROUGH)\n" 
"const float passThroughEvent,\n" 
"#endif\n" 
"float *pdfW, float *cosSampledDir, BSDFEvent *event,\n" 
"const BSDFEvent requestedEvent) {\n" 
"return BLACK;\n" 
"}\n" 
"#endif\n" 
; } } 
