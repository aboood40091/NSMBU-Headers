#pragma once

#include <common/aglShaderProgramArchive.h>
#include <heap/seadHeap.h>

namespace Mii {

class Shader
{
public:
    // Address: 0x024EA39C
    static void initializeShader(agl::ShaderProgramArchive* p_archive, sead::Heap* heap);
};

}
