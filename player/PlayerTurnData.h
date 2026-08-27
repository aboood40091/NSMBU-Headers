#pragma once

#include <basis/seadTypes.h>

struct PlayerTurnPowerData
{
    f32 normal;
    f32 saka_up;
    f32 saka_down;
    f32 air;
};
static_assert(sizeof(PlayerTurnPowerData) == 0x10);

struct PlayerTurnData
{
    PlayerTurnPowerData power_normal[2];    // [normal/star]
    PlayerTurnPowerData power_ice[2];       // ^^^
    PlayerTurnPowerData power_snow[2];      // ^^^
};
static_assert(sizeof(PlayerTurnData) == 0x60);
