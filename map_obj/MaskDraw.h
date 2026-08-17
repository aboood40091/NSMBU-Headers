#pragma once

#include <map_obj/Mask.h>

#include <heap/seadHeap.h>
#include <math/seadVector.h>

class LightMask
{
public:
    virtual bool create(sead::Heap* heap, Mask::TexName) = 0;
    virtual bool execute() = 0;
    virtual bool draw() = 0;
};
static_assert(sizeof(LightMask) == 4);

class CircleLightMask : public LightMask
{
public:
    CircleLightMask();

    bool create(sead::Heap* heap, Mask::TexName) override;
    bool execute() override;
    bool draw() override;

    void setRadius(f32 radius)
    {
        mRadius = radius;
    }

    void setPosition(const sead::Vector3f& pos)
    {
        mPos = pos;
    }

protected:
    f32             mRadius;
    f32             _8;
    sead::Vector3f  mPos;
    Mask*           mpMask;
    Quad*           mpQuad;
    Mask::TexName   mMaskTexName;
    u32             _24;
};
static_assert(sizeof(CircleLightMask) == 0x28);
