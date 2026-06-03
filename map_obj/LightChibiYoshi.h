#pragma once

#include <map_obj/ChibiYoshiBase.h>

class PlayerObject;

class LightChibiYoshi : public ChibiYoshiBase   // vtbl Address: 0x10132E40
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA85C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA860
    SEAD_RTTI_OVERRIDE(LightChibiYoshi, ChibiYoshiBase)

public:
    // Address: 0x027FD5C0
    bool setShakeAction(PlayerObject* p_player); // TODO: virtual (0x33C)

private:
    u32 _1f48[(0x2138 - 0x1F48) / sizeof(u32)];
};
static_assert(sizeof(LightChibiYoshi) == 0x2138);
