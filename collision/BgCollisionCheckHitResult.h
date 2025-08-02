#pragma once

#include <utility/Angle.h>

#include <math/seadVector.h>

struct BgCollisionCheckHitResult
{
    u8              hit_direction_flag;
    sead::Vector2f  hit_pos;
    Angle           hit_angle;
};
static_assert(sizeof(BgCollisionCheckHitResult) == 0x10);
