#pragma once

#include <gfx/seadColor.h>
#include <heap/seadDisposer.h>
#include <math/seadVector.h>

enum LightType;

class Light : public sead::IDisposer    // vtbl Address: 0x100BB350
{
public:
    // Address: 0x024E24BC
    Light();
    // Address: 0x024E2580
    virtual ~Light();

    // Address: 0x024E26BC
    bool update(
        LightType type,
        sead::Vector3f* position = nullptr,
        u32* = nullptr,
        f32* radius = nullptr,
        f32* = nullptr,
        sead::Color4f* color = nullptr,
        f32* = nullptr,
        f32* = nullptr
    );

private:
    bool            _10;
    void*           _14;
    sead::Vector3f  mPosition;
    u32             _24;
    f32             mRadius;
    f32             _2C;
    sead::Color4f   mColor;
    u32             _40;
    f32             _44;
};
static_assert(sizeof(Light) == 0x48);
