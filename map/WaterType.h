#pragma once

#include <basis/seadTypes.h>

enum WaterType
{
    cWaterType_None = 0,
    cWaterType_Water,
    cWaterType_AirWater,    // i.e., Floating Water Bubble
    cWaterType_Lava,
    cWaterType_LavaWave,
    cWaterType_Poison,
    cWaterType_Quicksand
};
static_assert(sizeof(WaterType) == 4);
