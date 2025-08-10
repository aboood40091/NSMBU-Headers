#pragma once

#include <collision/BgCollisionCheckType.h>

#include <prim/seadBitFlag.h>

class BgHitCheckCallback;

struct BgCollisionCheckParam
{
    u8                      _0;
    bool                    ignore_quicksand;   // Ignore BgCollision with unit type == cType_Water & type info == cTypeInfo_Water_Numa
    u8                      layer;
    sead::BitFlag8          collision_mask;
    BgCollisionCheckType    type;
    BgHitCheckCallback*     callback;
};
static_assert(sizeof(BgCollisionCheckParam) == 0xC);
