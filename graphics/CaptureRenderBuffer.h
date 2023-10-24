#pragma once

#include <common/aglRenderBuffer.h>
#include <common/aglRenderTarget.h>

class CaptureRenderBuffer
{
public:
    struct TextureInfo
    {
        u32                 width;
        u32                 height;
        agl::TextureFormat  format;
    };
    static_assert(sizeof(TextureInfo) == 0xC);

public:
    CaptureRenderBuffer()
    {
    }

    const agl::TextureData& getColorTexture() const
    {
        return mColorTexture;
    }

    const agl::TextureData& getDepthTexture() const
    {
        return mDepthTexture;
    }

    const TextureInfo& getInfo() const
    {
        return mInfo;
    }

private:
    agl::RenderTargetColor  mColorTarget;
    agl::TextureData        mColorTexture;
    void*                   mpColorData;
    agl::RenderTargetDepth  mDepthTarget;
    agl::TextureData        mDepthTexture;
    void*                   mpDepthData;
    agl::RenderBuffer       mRenderBuffer;
    TextureInfo             mInfo;
};
static_assert(sizeof(CaptureRenderBuffer) == 0x450);
