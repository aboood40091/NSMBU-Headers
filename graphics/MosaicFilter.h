#pragma once

#include <common/aglShaderProgramArchive.h>
#include <heap/seadHeap.h>

class MosaicFilter
{
public:
    // Address: 0x024F864C
    static void initializeShader(agl::ShaderProgramArchive* archive, sead::Heap* heap);
};
