#include <string> 
namespace slg { namespace ocl { 
std::string KernelSource_mapping_types = 
"#line 2 \"mapping_types.cl\"\n" 
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
"// TextureMapping2D\n" 
"//------------------------------------------------------------------------------\n" 
"typedef enum {\n" 
"UVMAPPING2D\n" 
"} TextureMapping2DType;\n" 
"typedef struct {\n" 
"float uScale, vScale, uDelta, vDelta;\n" 
"} UVMappingParam;\n" 
"typedef struct {\n" 
"TextureMapping2DType type;\n" 
"union {\n" 
"UVMappingParam uvMapping2D;\n" 
"};\n" 
"} TextureMapping2D;\n" 
"//------------------------------------------------------------------------------\n" 
"// TextureMapping3D\n" 
"//------------------------------------------------------------------------------\n" 
"typedef enum {\n" 
"UVMAPPING3D, GLOBALMAPPING3D, LOCALMAPPING3D\n" 
"} TextureMapping3DType;\n" 
"typedef struct {\n" 
"TextureMapping3DType type;\n" 
"Transform worldToLocal;\n" 
"//union {\n" 
"// UVMapping3D has no additional parameters\n" 
"// GlobalMapping3D has no additional parameters\n" 
"// LocalMapping3D has no additional parameters\n" 
"//};\n" 
"} TextureMapping3D;\n" 
; } } 
