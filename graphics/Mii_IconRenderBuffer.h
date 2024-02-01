#pragma once

#include <graphics/CaptureRenderBuffer.h>

class ModelFFL;

namespace Mii {

class IconRenderBuffer : public sead::IDisposer, public CaptureRenderBuffer
{
public:
    IconRenderBuffer()
    {
    }

    virtual ~IconRenderBuffer()
    {
        destroy();
    }

    // Address: 0x024E9708
    void initialize(sead::Heap* heap, const TextureInfo& info);
    // Address: 0x024E9904
    void destroy();

    // Address: 0x024E9868
    bool registerModel(const ModelFFL* model);
};
static_assert(sizeof(IconRenderBuffer) == 0x460);

}
