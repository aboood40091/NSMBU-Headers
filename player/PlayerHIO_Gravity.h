#pragma once

#include <basis/seadTypes.h>

struct PlayerPowerData
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
static_assert(sizeof(PlayerPowerData) == 0x24);

struct PlayerSpeedHIO
{
    // stage 0 max speed is always 0.5f
    f32 max_run_speed_lo; // stage 1 max speed
    f32 max_run_speed_md; // stage 2 max speed
    f32 max_run_speed_hi; // dush max speed
    PlayerPowerData power_data_normal;
    PlayerPowerData power_data_ice;
    PlayerPowerData power_data_snow;
};
static_assert(sizeof(PlayerSpeedHIO) == 0x78);

struct PlayerPowerTurnData
{
    f32 normal;
    f32 saka_up;
    f32 saka_down;
    f32 _c;
};
static_assert(sizeof(PlayerPowerTurnData) == 0x10);

struct PlayerTurnHIO
{
    PlayerPowerTurnData power_turn_normal[2]; // [normal/star]
    PlayerPowerTurnData power_turn_ice[2];
    PlayerPowerTurnData power_turn_snow[2];
};
static_assert(sizeof(PlayerTurnHIO) == 0x60);

#define PLAYER_JUMP_GRAVITY_MAX_STAGES 5

struct PlayerJumpGravityData
{
    f32 thresholds[PLAYER_JUMP_GRAVITY_MAX_STAGES];
    f32 normal_gravity[PLAYER_JUMP_GRAVITY_MAX_STAGES + 1];
    f32 button_gravity[PLAYER_JUMP_GRAVITY_MAX_STAGES + 1];
};
static_assert(sizeof(PlayerJumpGravityData) == 0x44);

struct PlayerGravityHIO
{
    f32                     gravity;
    PlayerJumpGravityData   jump_data;
};
static_assert(sizeof(PlayerGravityHIO) == 0x48);

// Address: 0x1016A760
extern const PlayerJumpGravityData cPlayerUnkJumpGravityData; /* = {
    {
        2.5f,
        1.5f,
        0.3f,
        -0.12f,
        -3.0f
    },
    {
        -0.04f,
        -0.06f,
        -0.09f,
        -0.06f,
        -0.09f,
        -0.09f
    },
    {
        -0.04f,
        -0.06f,
        -0.09f,
        -0.06f,
        -0.09f,
        -0.09f
    }
}; */

// Address: 0x1016AA7C
extern const PlayerTurnHIO cPlayerTurnData[2]; // [mario/luigi]
