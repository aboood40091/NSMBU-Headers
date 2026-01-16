#pragma once

#include <basis/seadTypes.h>

struct PlayerAirHIO
{
    f32 x_accel_def;
    f32 x_accel_stage0;
    f32 x_accel_stage1;
    f32 x_accel_stage1_dush;
    f32 x_accel_stage2;
    f32 x_accel_stage3;
    f32 turn_decel;
};
static_assert(sizeof(PlayerAirHIO) == 0x1C);

// Address: 0x10169664
extern const PlayerAirHIO cPlayerAirData[2][2]; // [mario/luigi][normal/star]
