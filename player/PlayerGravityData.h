#pragma once

#include <basis/seadTypes.h>

#define PLAYER_JUMP_GRAVITY_MAX_STAGES 5

struct PlayerJumpGravityData
{
    f32 thresholds[PLAYER_JUMP_GRAVITY_MAX_STAGES];
    f32 normal_gravity[PLAYER_JUMP_GRAVITY_MAX_STAGES + 1];
    f32 button_gravity[PLAYER_JUMP_GRAVITY_MAX_STAGES + 1];
};
static_assert(sizeof(PlayerJumpGravityData) == 0x44);

struct PlayerGravityData
{
    f32                     gravity;
    PlayerJumpGravityData   jump_data;
};
static_assert(sizeof(PlayerGravityData) == 0x48);
