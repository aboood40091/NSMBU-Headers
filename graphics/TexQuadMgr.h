#pragma once

#include <common/aglShaderProgramArchive.h>
#include <heap/seadHeap.h>

class TexQuadMgr
{
public:
    static void initializeShader(agl::ShaderProgramArchive* archive, sead::Heap* heap);
};
