#pragma once

#include <actor/Actor.h>
#include <player/PlayerKey.h>

class PlayerBase : public Actor
{
public:
    const PlayerKey& getPlayerKey() const
    {
        return mPlayerKey;
    }

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
