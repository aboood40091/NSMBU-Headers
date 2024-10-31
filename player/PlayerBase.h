#pragma once

#include <actor/Actor.h>
#include <player/PlayerKey.h>

class PlayerBase : public Actor // vtbl Address: 0x10166E84
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CCC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CD0
    SEAD_RTTI_OVERRIDE(PlayerBase, Actor)

public:
    enum DamageType
    {
        cDamageType_Ice     = 11,
        cDamageType_Spark   = 13,
        cDamageType_Num     = 20
    };

public:
    const PlayerKey& getPlayerKey() const
    {
        return mPlayerKey;
    }

    bool isTotten() const;

protected:
    u32         _27c[(0x2A8 - 0x27C) / sizeof(u32)];
    PlayerKey   mPlayerKey;
    u32         _33c[(0x490 - 0x33C) / sizeof(u32)];
    u32         mStatusArray[9];
    u32         _4b4[(0x1ACC - 0x4B4) / sizeof(u32)];
    u32         _1acc;
    u32         _1ad0[(0x2750 - 0x1AD0) / sizeof(u32)];
};
static_assert(sizeof(PlayerBase) == 0x2750);
