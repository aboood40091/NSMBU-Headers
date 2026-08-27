#pragma once

#include <player/PlayerAirData.h>

class PlayerMgr;

class PlayerHIO_Air
{
public:
    // Address: 0x10169664
    static const PlayerAirData cData[2][2]; // [mario/luigi][normal/star]

public:
    // Address: 0x029120F0
    PlayerHIO_Air(PlayerMgr& mgr);
};
static_assert(sizeof(PlayerHIO_Air) == 1);
