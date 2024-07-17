#pragma once

#include <basis/seadTypes.h>

enum WaterType
{
    cWaterType_None = 0,
    cWaterType_1,
    cWaterType_2,
    cWaterType_3,
    cWaterType_4,
    cWaterType_5,
    cWaterType_Quicksand
};
static_assert(sizeof(WaterType) == 4);
