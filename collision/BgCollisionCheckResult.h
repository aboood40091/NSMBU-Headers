#pragma once

#include <collision/BgCheckUnitInfo.h>

#include <prim/seadBitFlag.h>

class BgCollision;

struct BgCollisionCheckResult
{
    sead::BitFlag8  hit_direction_flag;
    sead::Vector2f  _4;
    u32             _c;     // Some sort of angle
    u32             _10;    // ^^^
  //u32             _14[4 / sizeof(u32)];   // Alignment???
    BgCheckUnitInfo bg_check_data;
    BgCollision*    p_bg_collision;
};
static_assert(sizeof(BgCollisionCheckResult) == 0x24);
