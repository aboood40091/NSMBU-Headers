#pragma once

#include <player/PlayerBase.h>

class PlayerObject : public PlayerBase
{
public:
    bool vf8CC(Actor*, u32);
    bool setDamageState(Actor*, u32); // 8D4

    // ...
};
