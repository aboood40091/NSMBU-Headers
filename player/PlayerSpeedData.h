#pragma once

#include <basis/seadTypes.h>

struct PlayerSpeedPowerData
{
    f32 x_accel_def;
    f32 stop_x_accel;
    f32 stop_turn_decel;
    f32 turn_decel;
    f32 x_accel_stage0;
    f32 x_accel_stage1;
    f32 x_accel_stage1_dush;
    f32 x_accel_stage2;
    f32 x_accel_stage3;
};
static_assert(sizeof(PlayerSpeedPowerData) == 0x24);

struct PlayerSpeedData
{
    // stage 0 max speed is always 0.5f
    f32 max_run_speed_lo; // stage 1 max speed
    f32 max_run_speed_md; // stage 2 max speed
    f32 max_run_speed_hi; // dush max speed
    PlayerSpeedPowerData power_normal;
    PlayerSpeedPowerData power_ice;
    PlayerSpeedPowerData power_snow;
};
static_assert(sizeof(PlayerSpeedData) == 0x78);
