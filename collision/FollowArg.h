#pragma once

#include <math/seadVector.h>
#include <prim/seadBitFlag.h>

struct FollowArg
{
    FollowArg()
        : position(nullptr)
        , position_prev(nullptr)
        , layer(nullptr)
        , collision_mask(nullptr)
        , player_no(nullptr)
    {
    }

    sead::Vector3f* position;
    sead::Vector3f* position_prev;
    u8*             layer;
    sead::BitFlag8* collision_mask;
    u8*             player_no;
};
static_assert(sizeof(FollowArg) == 0x14);
