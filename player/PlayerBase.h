#pragma once

#include <actor/Actor.h>
#include <player/PlayerKey.h>
#include <state/FStateMgr.h>

class PlayerBase : public Actor // vtbl Address: 0x10166E84
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CCC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CD0
    SEAD_RTTI_OVERRIDE(PlayerBase, Actor)

public:

    enum PowerUpState
    {
        cPowerUpState_Small = 0,
        cPowerUpState_Big,
        cPowerUpState_Fire,
        cPowerUpState_Mini,
        cPowerUpState_Propeller,
        cPowerUpState_Penguin,
        cPowerUpState_Ice,
        cPowerUpState_Acorn,
        cPowerUpState_PAcorn,
        cPowerUpState_Num
    };

    enum DamageType
    {
        cDamageType_Hit = 0, 
        cDamageType_Hit2,
        cDamageType_HitKnock,
        cDamageType_Hit3,
        cDamageType_Knock,
        cDamageType_Knock2,
        cDamageType_SmallKnock,
        cDamageType_SmallKnock2,
        cDamageType_SmallKnock3,
        cDamageType_Hit4,
        cDamageType_Lava,
        cDamageType_Ice,
        cDamageType_Ice2,
        cDamageType_Spark,
        cDamageType_Poison,
        cDamageType_Kill,
        cDamageType_Kill2,
        cDamageType_RunInPlace,
        cDamageType_RunInPlace2,
        cDamageType_SteppedOn,
        cDamageType_Num
    };

    enum TallType
    {
        cTallType_Mini = 0,
        cTallType_Small,
        cTallType_Big,
        cTallType_Num
    }

public:
    const PlayerKey& getPlayerKey() const
    {
        return mPlayerKey;
    }

    bool isTotten() const;

protected:
    u32                     _27c[(0x2A8 - 0x27C) / sizeof(u32)];
    PlayerKey               mPlayerKey;
    u32                     _33c[(0x490 - 0x33C) / sizeof(u32)];
    u32                     mStatusArray[9];
    u32                     _4b4[(0x1ACC - 0x4B4) / sizeof(u32)];
    u32                     _1acc;
    u32                     _1ad0[(0x219C - 0x1AD0) / sizeof(u32)];
    FStateMgr<PlayerBase>   mStateMgr;
    u32                     _21c0[(0x2750 - 0x21C0) / sizeof(u32)];
};
static_assert(sizeof(PlayerBase) == 0x2750);
