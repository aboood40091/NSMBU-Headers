#pragma once

#include <common/aglShaderProgramArchive.h>
#include <heap/seadHeap.h>

namespace Mii {

class IconFaceline
{
public:
    // Address: 0x024E90EC
    static void initializeShader(agl::ShaderProgramArchive* p_archive, sead::Heap* heap);
};

}
