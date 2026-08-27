#pragma once

#include <player/PlayerGravityData.h>

class PlayerMgr;

class PlayerHIO_ChibiYoshi
{
public:
    // Address: 0x1016A720
    static const f32 cBalloonCYFlyAccelF;
    // Address: 0x1016A724
    static const f32 cBalloonCYFlyMaxSpeedF;

    // Address: 0x1016a728
    static const f32 cBalloonCYFlyInitSpeedY;
    // Address: 0x1016a72C
    static const f32 cBalloonCYFlyInitSpeedYMax;
    // Address: 0x1016A730
    static const f32 cBalloonCYFlySmallInitSpeedYDecel;

    // Address: 0x1016A734
    static const f32 cBalloonCYFlySpinSpeedYMax;
    // Address: 0x1016A738
    static const f32 cBalloonCYFlySpinAddSpeedY;
    // Address: 0x1016A73C
    static const f32 cBalloonCYFlySpinTrigSpeedY;

    // Address: 0x1016A740
    static const s32 cBalloonCYFlyAscendMinTime;

    // Address: 0x1016A744
    static const f32 cBalloonCYFlyDescendStartSpeedY;
    // Address: 0x1016A748
    static const f32 cBalloonCYFlyAscendEndGravity;
    // Address: 0x1016A74C
    static const f32 cBalloonCYFlyDescendGravity;

    // Address: 0x1016A750
    static const f32 cBalloonCYFlyMaxFallSpeed;

    // Address: 0x1016A754
    static const s32 cBalloonCYFlyAscendGravityTime;
    // Address: 0x1016A758
    static const f32 cBalloonCYFlyAscendGravity;

    // Address: 0x1016A75C
    static const PlayerGravityData cUnkGravityData;

public:
    // Address: 0x029148E0
    PlayerHIO_ChibiYoshi(PlayerMgr& mgr);
};
static_assert(sizeof(PlayerHIO_ChibiYoshi) == 1);
