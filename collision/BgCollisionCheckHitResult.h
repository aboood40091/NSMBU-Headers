#pragma once

#include <math/seadVector.h>

struct BgCollisionCheckHitResult
{
    bool            is_hit;
    sead::Vector2f  hit_pos;
    s32             hit_angle;
};
static_assert(sizeof(BgCollisionCheckHitResult) == 0x10);
