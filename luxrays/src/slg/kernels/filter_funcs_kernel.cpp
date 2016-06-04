#include <string> 
namespace slg { namespace ocl { 
std::string KernelSource_filter_funcs = 
"#line 2 \"filter_funcs.cl\"\n" 
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
"// FilterDistribution\n" 
"//------------------------------------------------------------------------------\n" 
"void FilterDistribution_SampleContinuous(__global float *pixelFilterDistribution,\n" 
"const float u0, const float u1, float *su0, float *su1) {\n" 
"// Sample according the pixel filter distribution\n" 
"float2 uv;\n" 
"float distPdf;\n" 
"Distribution2D_SampleContinuous(pixelFilterDistribution, u0, u1, &uv, &distPdf);\n" 
"*su0 = (uv.x - .5f) * (2.f * PARAM_IMAGE_FILTER_WIDTH_X);\n" 
"*su1 = (uv.y - .5f) * (2.f * PARAM_IMAGE_FILTER_WIDTH_Y);\n" 
"}\n" 
"//------------------------------------------------------------------------------\n" 
"// Pixel related functions\n" 
"//------------------------------------------------------------------------------\n" 
"void PixelIndex2XY(const uint filmWidth, const uint index, uint *x, uint *y) {\n" 
"*y = index / filmWidth;\n" 
"*x = index - (*y) * filmWidth;\n" 
"}\n" 
"uint XY2PixelIndex(const uint filmWidth, const uint x, const uint y) {\n" 
"return x + y * filmWidth;\n" 
"}\n" 
"//------------------------------------------------------------------------------\n" 
"// Image filtering related functions\n" 
"//------------------------------------------------------------------------------\n" 
"#if (PARAM_IMAGE_FILTER_TYPE == 0)\n" 
"// Nothing\n" 
"#elif (PARAM_IMAGE_FILTER_TYPE == 1)\n" 
"// Box Filter\n" 
"float ImageFilter_Evaluate(const float x, const float y) {\n" 
"return 1.f;\n" 
"}\n" 
"#elif (PARAM_IMAGE_FILTER_TYPE == 2)\n" 
"float Gaussian(const float d, const float expv) {\n" 
"return max(0.f, exp(-PARAM_IMAGE_FILTER_GAUSSIAN_ALPHA * d * d) - expv);\n" 
"}\n" 
"// Gaussian Filter\n" 
"float ImageFilter_Evaluate(const float x, const float y) {\n" 
"return Gaussian(x,\n" 
"exp(-PARAM_IMAGE_FILTER_GAUSSIAN_ALPHA * PARAM_IMAGE_FILTER_WIDTH_X * PARAM_IMAGE_FILTER_WIDTH_X)) *\n" 
"Gaussian(y, \n" 
"exp(-PARAM_IMAGE_FILTER_GAUSSIAN_ALPHA * PARAM_IMAGE_FILTER_WIDTH_Y * PARAM_IMAGE_FILTER_WIDTH_Y));\n" 
"}\n" 
"#elif (PARAM_IMAGE_FILTER_TYPE == 3)\n" 
"float Mitchell1D(float x) {\n" 
"const float B = PARAM_IMAGE_FILTER_MITCHELL_B;\n" 
"const float C = PARAM_IMAGE_FILTER_MITCHELL_C;\n" 
"if (x >= 1.f)\n" 
"return 0.f;\n" 
"x = fabs(2.f * x);\n" 
"if (x > 1.f)\n" 
"return (((-B / 6.f - C) * x + (B + 5.f * C)) * x +\n" 
"(-2.f * B - 8.f * C)) * x + (4.f / 3.f * B + 4.f * C);\n" 
"else\n" 
"return ((2.f - 1.5f * B - C) * x +\n" 
"(-3.f + 2.f * B + C)) * x * x +\n" 
"(1.f - B / 3.f);\n" 
"}\n" 
"// Mitchell Filter\n" 
"float ImageFilter_Evaluate(const float x, const float y) {\n" 
"const float distance = native_sqrt(\n" 
"x * x * (1.f / (PARAM_IMAGE_FILTER_WIDTH_X * PARAM_IMAGE_FILTER_WIDTH_X)) +\n" 
"y * y * (1.f / (PARAM_IMAGE_FILTER_WIDTH_Y * PARAM_IMAGE_FILTER_WIDTH_Y)));\n" 
"return Mitchell1D(distance);\n" 
"}\n" 
"#elif (PARAM_IMAGE_FILTER_TYPE == 4)\n" 
"float Mitchell1D(float x) {\n" 
"const float B = PARAM_IMAGE_FILTER_MITCHELL_B;\n" 
"const float C = PARAM_IMAGE_FILTER_MITCHELL_C;\n" 
"if (x >= 1.f)\n" 
"return 0.f;\n" 
"x = fabs(2.f * x);\n" 
"if (x > 1.f)\n" 
"return (((-B / 6.f - C) * x + (B + 5.f * C)) * x +\n" 
"(-2.f * B - 8.f * C)) * x + (4.f / 3.f * B + 4.f * C);\n" 
"else\n" 
"return ((2.f - 1.5f * B - C) * x +\n" 
"(-3.f + 2.f * B + C)) * x * x +\n" 
"(1.f - B / 3.f);\n" 
"}\n" 
"// Mitchell Filter\n" 
"float ImageFilter_Evaluate(const float x, const float y) {\n" 
"const float distance = native_sqrt(\n" 
"x * x * (1.f / (PARAM_IMAGE_FILTER_WIDTH_X * PARAM_IMAGE_FILTER_WIDTH_X)) +\n" 
"y * y * (1.f / (PARAM_IMAGE_FILTER_WIDTH_Y * PARAM_IMAGE_FILTER_WIDTH_Y)));\n" 
"const float dist = distance / .6f;\n" 
"return PARAM_IMAGE_FILTER_MITCHELL_A1 * Mitchell1D(dist - 2.f / 3.f) +\n" 
"PARAM_IMAGE_FILTER_MITCHELL_A0 * Mitchell1D(dist) +\n" 
"PARAM_IMAGE_FILTER_MITCHELL_A1 * Mitchell1D(dist + 2.f / 3.f);\n" 
"}\n" 
"#elif (PARAM_IMAGE_FILTER_TYPE == 5)\n" 
"float BlackmanHarris1D(float x) {\n" 
"if (x < -1.f || x > 1.f)\n" 
"return 0.f;\n" 
"x = (x + 1.f) * .5f;\n" 
"x *= M_PI_F;\n" 
"const float A0 =  0.35875f;\n" 
"const float A1 = -0.48829f;\n" 
"const float A2 =  0.14128f;\n" 
"const float A3 = -0.01168f;\n" 
"return A0 + A1 * cos(2.f * x) + A2 * cos(4.f * x) + A3 * cos(6.f * x);\n" 
"}\n" 
"// Blackman-Harris Filter\n" 
"float ImageFilter_Evaluate(const float x, const float y) {\n" 
"return BlackmanHarris1D(x * (1.f / PARAM_IMAGE_FILTER_WIDTH_X)) *\n" 
"BlackmanHarris1D(y *  (1.f / PARAM_IMAGE_FILTER_WIDTH_Y));\n" 
"}\n" 
"#else\n" 
"Error: unknown image filter !!!\n" 
"#endif\n" 
; } } 
