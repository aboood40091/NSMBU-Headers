#pragma once

#include <layer/aglLayer.h>

// No idea what the actual name of this class is

class Layer : public agl::lyr::Layer    // vtbl Address: 0x100BD6B8
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9E5C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA070
    SEAD_RTTI_OVERRIDE(Layer, agl::lyr::Layer)

public:
    // Address: 0x024F9290
    Layer();
    // Address: 0x024F92EC
    virtual ~Layer();

    // Address: 0x024F9340
    void preDraw(const agl::lyr::RenderInfo& render_info) const override;
    // Address: 0x024F9344
    void postDraw(const agl::lyr::RenderInfo& render_info) const override;

    // ...

protected:
    u8  _41c;
};
static_assert(sizeof(Layer) == 0x420);
