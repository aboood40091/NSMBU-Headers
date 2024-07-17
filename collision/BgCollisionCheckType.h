#pragma once

#include <basis/seadTypes.h>

enum BgCollisionCheckType
{
    cBgCollisionCheckType_Solid     = 0,    // Check for BgCollision with solid type != cSolidType_None
    cBgCollisionCheckType_NonSolid,         // Check for BgCollision with solid type == cSolidType_None & kind not in (cKind_CoinOutline, cKind_Coin, cKind_CoinBlue)
    cBgCollisionCheckType_Coin              // Check for BgCollision with solid type == cSolidType_None & kind in (cKind_CoinOutline, cKind_Coin, cKind_CoinBlue)
};
static_assert(sizeof(BgCollisionCheckType) == 4);
