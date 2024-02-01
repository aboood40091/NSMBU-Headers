#pragma once

#include <collision/BgCheckUnitInfo.h>
#include <utility/Angle.h>

#include <math/seadVector.h>
#include <prim/seadBitFlag.h>

class BgCollision;

struct BgCollisionCheckResult
{
    sead::BitFlag8  hit_direction_flag;
    sead::Vector2f  _4;
    Angle           _c;
    Angle           _10;
  //u32             _14[4 / sizeof(u32)];   // Alignment???
    BgCheckUnitInfo bg_check_data;
    BgCollision*    bg_collision;
  //u32             _24[4 / sizeof(u32)];   // More alignment???
};
static_assert(sizeof(BgCollisionCheckResult) == 0x28);
