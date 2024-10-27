#pragma once

#include <player/PlayerBase.h>

class PlayerObject : public PlayerBase
{
public:
    // ...
    bool setDamage(Actor*, DamageType) /* override */;  // vf8CC
    bool setDamageState(Actor*, u32) /* override */;    // vf8D4
    // ...
    bool isStar() const /* override */;                 // vf914
    // ...

    s32 getJumpFallType();

protected:
    u32 _2750[(0x34CC - 0x2750) / sizeof(u32)];
    f32 mJumpTimerF;
    s32 mJumpAnmID;
    s32 _34d4;  // Some random timer
};
static_assert(sizeof(PlayerObject) == 0x34D8);
