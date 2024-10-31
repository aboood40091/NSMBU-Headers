#pragma once

#include <player/PlayerBase.h>

class Yoshi : public PlayerBase
{
    SEAD_RTTI_OVERRIDE(Yoshi, PlayerBase)

public:
    bool setDamage(Actor*, DamageType) /* override */;  // vf8CC
};
