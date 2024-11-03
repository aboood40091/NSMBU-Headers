#pragma once

#include <basis/seadTypes.h>

enum WaterType
{
    cWaterType_None = 0,
    cWaterType_Water_1,
    cWaterType_Water_2,
    cWaterType_Lava,
    cWaterType_LavaWave,
    cWaterType_Poison,
    cWaterType_Quicksand
};
static_assert(sizeof(WaterType) == 4);
