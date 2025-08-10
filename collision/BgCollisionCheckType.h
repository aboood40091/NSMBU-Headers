#pragma once

#include <basis/seadTypes.h>

enum BgCollisionCheckType
{
    cBgCollisionCheckType_Solid     = 0,    // Check for BgCollision with hit type != cHitType_None
    cBgCollisionCheckType_NonSolid,         // Check for BgCollision with hit type == cHitType_None & unit type not in (cType_WakuCoin, cType_Coin, cType_ClearCoin)
    cBgCollisionCheckType_Coin              // Check for BgCollision with hit type == cHitType_None & unit type in (cType_WakuCoin, cType_Coin, cType_ClearCoin)
};
static_assert(sizeof(BgCollisionCheckType) == 4);
