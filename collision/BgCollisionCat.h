#pragma once

#include <basis/seadTypes.h>

enum BgCollisionCat
{
    // Higher value = higher priority
    cBgCollisionCat_WaterGeyser = 0,
    cBgCollisionCat_Ice,
    cBgCollisionCat_Quicksand,
    cBgCollisionCat_Normal,
    cBgCollisionCat_BgUnit,
    cBgCollisionCat_PairObjChild,
    cBgCollisionCat_Num
};
static_assert(sizeof(BgCollisionCat) == 4);
static_assert(cBgCollisionCat_Num == 6);
