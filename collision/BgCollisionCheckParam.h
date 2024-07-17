#pragma once

#include <collision/BgCollisionCheckType.h>

#include <prim/seadBitFlag.h>

class BgHitCheckCallback;

struct BgCollisionCheckParam
{
    u8                      _0;
    bool                    ignore_quicksand;   // Ignore BgCollision with kind == cKind_Liquid & param0 == 4
    u8                      layer;
    sead::BitFlag8          collision_mask;
    BgCollisionCheckType    type;
    BgHitCheckCallback*     callback;
};
static_assert(sizeof(BgCollisionCheckParam) == 0xC);
