#pragma once

#include <player/PlayerGravityData.h>

class PlayerMgr;

class PlayerHIO_Gravity
{
public:
    // Address: 0x1016A7FC
    static const PlayerGravityData cData[2 * 2 + 1]; // [mario/luigi][normal/mini] + Unk (+ Peachette + Another Unk in NSMBUDX)

public:
    // Address: 0x02914938
    PlayerHIO_Gravity(PlayerMgr& mgr);
};
static_assert(sizeof(PlayerHIO_Gravity) == 1);
