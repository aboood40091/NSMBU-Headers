#pragma once

#include <basis/seadTypes.h>

class PlayerMgr;

class PlayerHIO_FlyMusa
{
public:
    // Address: 0x1016A7F0
    static const f32 cSpinJumpSpeed;

public:
    // Address: 0x0291490C
    PlayerHIO_FlyMusa(PlayerMgr& mgr);
};
static_assert(sizeof(PlayerHIO_FlyMusa) == 1);
