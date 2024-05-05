#pragma once

#include <common/aglShaderProgramArchive.h>
#include <common/aglTextureSampler.h>
#include <container/seadSafeArray.h>
#include <heap/seadHeap.h>
#include <math/seadMatrix.h>

namespace Mii {

class IconFacelineShader
{
public:
    enum Uniform
    {
        cUniform_WorldMtx = 0,
        cUniform_ViewMtx,
        cUniform_ProjMtx,
        cUniform_ResolutionX,
        cUniform_ResolutionY,
        cUniform_LineWidth,
        cUniform_Num
    };
    static_assert(cUniform_Num == 6);

    enum Sampler
    {
        cSampler_Depth = 0,
        cSampler_Color,
        cSampler_Num
    };
    static_assert(cSampler_Num == 2);

public:
    // Address: 0x024E9078
    IconFacelineShader();

    ~IconFacelineShader()
    {
        destroy();
    }

    // Address: 0x024E90EC
    static void initializeShader(agl::ShaderProgramArchive* archive, sead::Heap* heap);

    // Address: 0x024E92C0
    bool initialize();
    // Address: 0x024E9704
    void destroy();

    void activate() const
    {
        mShaderProgram->activate();
    }

    // Address: 0x024E92C4
    void setViewUniform(const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, const sead::Matrix34f& world_mtx) const;
    // Address: 0x024E93CC
    void setResolutionUniform(u32 width, u32 height) const;
    // Address: 0x024E94E8
    void setLineWidthUniform(s32 line_width) const;

    // Address: 0x024E9580
    bool activateTexture(const agl::TextureData& texture_data, Sampler sampler);

private:
    // Address: 0x024E9210
    bool initializeShader_();

private:
    const agl::ShaderProgramArchive*        mShaderArchive;
    const agl::ShaderProgram*               mShaderProgram;
    sead::SafeArray<agl::TextureSampler, 2> mTextureSampler;
};
static_assert(sizeof(IconFacelineShader) == 0x348);

}
