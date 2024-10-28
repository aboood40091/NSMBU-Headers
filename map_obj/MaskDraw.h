#pragma once

#include <heap/seadHeap.h>
#include <math/seadVector.h>

// TODO: Figure out where this enum belongs
enum MaskTextureType
{
    cMaskTexture_Cave = 0,
    cMaskTexture_CaveSmall,
    cMaskTexture_Dark,
    cMaskTexture_DeepSea,
    cMaskTexture_FlashlightA,
    cMaskTexture_FlashlightB,
    cMaskTexture_DrcBlock,
    cMaskTexture_DrcTouch,
    cMaskTexture_UserType
};

class LightMask
{
public:
    virtual bool create(sead::Heap* heap, MaskTextureType) = 0;
    virtual bool execute() = 0;
    virtual bool draw() = 0;
};
static_assert(sizeof(LightMask) == 4);

class Mask;
class Quad;

class CircleLightMask : public LightMask
{
public:
    CircleLightMask();

    bool create(sead::Heap* heap, MaskTextureType) override;
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
    MaskTextureType mMaskTextureType;
    u32             _24;
};
static_assert(sizeof(CircleLightMask) == 0x28);
