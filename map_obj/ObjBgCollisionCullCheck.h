#pragma once

#include <math/seadVector.h>

class BgCollision;

class ObjBgCollisionCullCheck
{
public:
    // Address: 0x028292B0
    bool initialize(const sead::Vector3f& pos, const sead::Vector2f& center_ofs, const sead::Vector2f& size, const BgCollision& bg_collision);
    // Address: 0x02829148
    bool cullCheck(const sead::Vector3f& pos);

protected:
    const BgCollision*  mpBgCollision;
    sead::Vector2f      mCenterOffset;
    sead::Vector2f      mSize;
    struct
    {
        f32 up;
        f32 down;
        f32 left;
        f32 right;
    }                   mCameraBoxPad;
    bool                mIsEntry;
};
static_assert(sizeof(ObjBgCollisionCullCheck) == 0x28);
