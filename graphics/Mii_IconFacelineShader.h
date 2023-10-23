#pragma once

#include <common/aglShaderProgramArchive.h>
#include <common/aglTextureSampler.h>
#include <container/seadSafeArray.h>
#include <heap/seadHeap.h>

namespace Mii {

class IconFacelineShader
{
public:
    // Address: 0x024E9078
    IconFacelineShader();

    // Address: 0x024E90EC
    static void initializeShader(agl::ShaderProgramArchive* p_archive, sead::Heap* heap);

private:
    agl::ShaderProgramArchive*              mpShaderArchive;
    agl::ShaderProgram*                     mpShaderProgram;
    sead::SafeArray<agl::TextureSampler, 2> mTextureSampler;
};
static_assert(sizeof(IconFacelineShader) == 0x348);

}
