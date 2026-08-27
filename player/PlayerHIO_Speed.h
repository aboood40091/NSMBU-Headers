#pragma once

#include <player/PlayerSpeedData.h>

class PlayerMgr;

class PlayerHIO_Speed
{
public:
    // Address: 0x1016A964
    static const f32 cMaxRunSpeedLo;
    // Address: 0x1016A968
    static const f32 cMaxRunSpeedMd;
    // Address: 0x1016A96C
    static const f32 cMaxRunSpeedHi;
    // Address: 0x1016A970
    static const f32 cMaxRunSpeedHi_Star;

    // Address: 0x101E5078
    static const PlayerSpeedData cData[2 * 2 * 2]; // [mario/luigi][mini/normal][normal/star]
                                                   // ({[normal/toadette][mario/luigi][mini/normal] + nabbit mario + nabbit luigi}[normal/star] in NSMBUDX)

public:
    // Address: 0x02914964
    PlayerHIO_Speed(PlayerMgr& mgr);
};
static_assert(sizeof(PlayerHIO_Speed) == 1);
