#pragma once

#include <collision/BgUnitCode.h>
#include <utility/Angle.h>

#include <math/seadVector.h>

class BgCollision;

struct BgCollisionCheckResultPoint
{
    u64             bg_check_data;          // See BgUnitCode
    BgCollision*    p_bg_collision;
  //u32             _c[4 / sizeof(u32)];    // Alignment???
};
static_assert(sizeof(BgCollisionCheckResultPoint) == 0x10);

struct BgCollisionCheckResultArea
{
    u8              hit_direction_flag;
    sead::Vector2f  hit_pos;
    Angle           hit_angle;
    Angle           _10;
  //u32             _14[4 / sizeof(u32)];   // Alignment???
    u64             bg_check_data;          // See BgUnitCode
    BgCollision*    p_bg_collision;
  //u32             _24[4 / sizeof(u32)];   // More alignment???

    BgCollisionCheckResultArea()
    {
    }

    BgCollisionCheckResultArea(f32 x, f32 y)
        : hit_pos(x, y)
    {
    }
};
static_assert(sizeof(BgCollisionCheckResultArea) == 0x28);
