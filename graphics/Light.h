#pragma once

#include <heap/seadDisposer.h>
#include <gfx/seadColor.h>
#include <math/seadVector.h>

class Light : public sead::IDisposer
{
public:
    // Address: 0x024E24BC
    Light();
    // Address: 0x024E2580
    virtual ~Light();

    // Address: 0x024E26BC
    bool update(u32 type, Vec3f* p_position, u32*, f32* p_radius, f32*, sead::Color4f* p_color, f32* = nullptr, f32* = nullptr);

private:
    bool            _10;
    void*           _14;
    Vec3f           mPosition;
    u32             _24;
    f32             mRadius;
    f32             _2C;
    sead::Color4f   mColor;
    u32             _40;
    f32             _44;
};
static_assert(sizeof(Light) == 0x48);
