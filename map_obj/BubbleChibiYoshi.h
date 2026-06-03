#pragma once

#include <map_obj/ChibiYoshiBase.h>

class PlayerObject;

class BubbleChibiYoshi : public ChibiYoshiBase  // vtbl Address: 0x101047EC
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EB280
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EB284
    SEAD_RTTI_OVERRIDE(BubbleChibiYoshi, ChibiYoshiBase)

public:
    // Address: 0x02717208
    bool setShakeAction(PlayerObject* p_player); // TODO: virtual (0x33C)

private:
    u32 _1f48[(0x1FB8 - 0x1F48) / sizeof(u32)];
};
static_assert(sizeof(BubbleChibiYoshi) == 0x1FB8);
