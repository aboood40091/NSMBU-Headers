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

    agl::RenderBuffer& getRenderBuffer()
    {
        return mRenderBuffer;
    }

    const agl::RenderBuffer& getRenderBuffer() const
    {
        return mRenderBuffer;
    }

    TextureInfo& getInfo()
    {
        return mInfo;
    }

    const TextureInfo& getInfo() const
    {
        return mInfo;
    }

    // Address: 0x024D5D3C
    void initColor(sead::Heap* heap);
    // Address: 0x024D5DC8
    void initDepth(sead::Heap* heap);

private:
    agl::RenderTargetColor  mColorTarget;
    agl::TextureData        mColorTexture;
    u8*                     mpColorImage;
    agl::RenderTargetDepth  mDepthTarget;
    agl::TextureData        mDepthTexture;
    u8*                     mpDepthImage;
    agl::RenderBuffer       mRenderBuffer;
    TextureInfo             mInfo;
};
static_assert(sizeof(CaptureRenderBuffer) == 0x450);
