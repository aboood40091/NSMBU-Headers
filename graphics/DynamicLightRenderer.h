#pragma once

#include <common/aglShaderProgramArchive.h>
#include <heap/seadHeap.h>

class DynamicLightRenderer
{
public:
    // Address: 0x024DB5DC
    static void initializeShader(agl::ShaderProgramArchive* p_archive, sead::Heap* heap);
};
