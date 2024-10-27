#pragma once

#include <player/PlayerBase.h>

class YoshiObject : public PlayerBase
{
    SEAD_RTTI_OVERRIDE(YoshiObject, PlayerBase)

public:
    bool setDamage(Actor*, DamageType) /* override */;  // vf8CC
};
