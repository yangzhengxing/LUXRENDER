#include <string> 
namespace luxrays { namespace ocl { 
std::string KernelSource_color_funcs = 
"#line 2 \"specturm_funcs.cl\"\n" 
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
"bool Spectrum_IsEqual(const float3 a, const float3 b) {\n" 
"return all(isequal(a, b));\n" 
"}\n" 
"bool Spectrum_IsBlack(const float3 a) {\n" 
"return Spectrum_IsEqual(a, BLACK);\n" 
"}\n" 
"float Spectrum_Filter(const float3 s)  {\n" 
"return (s.s0 + s.s1 + s.s2) * 0.33333333f;\n" 
"}\n" 
"float Spectrum_Y(const float3 s) {\n" 
"return 0.212671f * s.s0 + 0.715160f * s.s1 + 0.072169f * s.s2;\n" 
"}\n" 
"float3 Spectrum_Clamp(const float3 s) {\n" 
"return clamp(s, BLACK, WHITE);\n" 
"}\n" 
"float3 Spectrum_Exp(const float3 s) {\n" 
"return (float3)(exp(s.x), exp(s.y), exp(s.z));\n" 
"}\n" 
"float3 Spectrum_Pow(const float3 s, const float e) {\n" 
"return (float3)(pow(s.x, e), pow(s.y, e), pow(s.z, e));\n" 
"}\n" 
"float3 Spectrum_Sqrt(const float3 s) {\n" 
"return (float3)(sqrt(s.x), sqrt(s.y), sqrt(s.z));\n" 
"}\n" 
"float3 Spectrum_ScaledClamp(const float3 c, const float low, const float high) {\n" 
"float3 ret = c;\n" 
"const float maxValue = fmax(c.x, fmax(c.y, c.z));\n" 
"if (maxValue > 0.f) {\n" 
"if (maxValue > high) {\n" 
"const float scale = high / maxValue;\n" 
"ret *= scale;\n" 
"}\n" 
"if (maxValue < low) {\n" 
"const float scale = low / maxValue;\n" 
"ret *= scale;\n" 
"}\n" 
"}\n" 
"return ret;\n" 
"}\n" 
; } } 
