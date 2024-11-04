#pragma once

#include <collision/BgCheckUnitInfo.h>
#include <utility/Angle.h>

#include <math/seadVector.h>

class BgCollision;

struct BgCollisionCheckResultPoint
{
    BgCheckUnitInfo bg_check_data;
    BgCollision*    p_bg_collision;
  //u32             _c[4 / sizeof(u32)];    // Alignment???
};
static_assert(sizeof(BgCollisionCheckResultPoint) == 0x10);

struct BgCollisionCheckResultArea
{
    u8              hit_direction_flag;
    sead::Vector2f  hit_pos;
    Angle           _c;
    Angle           _10;
  //u32             _14[4 / sizeof(u32)];   // Alignment???
    BgCheckUnitInfo bg_check_data;
    BgCollision*    p_bg_collision;
  //u32             _24[4 / sizeof(u32)];   // More alignment???

    BgCollisionCheckResultArea()
    {
    }

    BgCollisionCheckResultArea(f32 x, f32 y)
        : _4(x, y)
    {
    }
};
static_assert(sizeof(BgCollisionCheckResultArea) == 0x28);
