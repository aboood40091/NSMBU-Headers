#pragma once

#include <map_obj/ChibiYoshiBase.h>

class PlayerObject;

class BalloonChibiYoshi : public ChibiYoshiBase // vtbl Address: 0x100FA7FC
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EB178
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EB174
    SEAD_RTTI_OVERRIDE(BalloonChibiYoshi, ChibiYoshiBase)

public:
    // Address: 0x026E3AB4
    bool setShakeAction(PlayerObject* p_player); // TODO: virtual (0x33C)

    // Address: 0x026E3B54
    bool isBalloonFly();
    // Address: 0x026E3BB0
    bool setBalloonFlyEnd();

private:
    u32 _1f48[(0x3660 - 0x1F48) / sizeof(u32)];
};
static_assert(sizeof(BalloonChibiYoshi) == 0x3660);
