#pragma once

#include <actor/Actor.h>

class ChibiYoshiAwa : public Actor  // vtbl Address: 0x10108010
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA250
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA254
    SEAD_RTTI_OVERRIDE(ChibiYoshiAwa, Actor)

public:
    // Address: 0x027296B4
    ChibiYoshiAwa(const ActorCreateParam& param);

    // Address: 0x0272A30C
    bool setBreak(Actor* p_actor = nullptr);

private:
    u32 _27c[(0x3B4 - 0x27C) / sizeof(u32)];
};
static_assert(sizeof(ChibiYoshiAwa) == 0x3B4);
