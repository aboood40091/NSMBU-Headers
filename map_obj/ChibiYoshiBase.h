#pragma once

#include <actor/ActorCollision.h>

class ChibiYoshiBase : public ActorCollision    // vtbl Address: 0x101084FC
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9ED4
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9ED8
    SEAD_RTTI_OVERRIDE(ChibiYoshiBase, ActorCollision)

public:
    u32 _17a0[(0x1A78 - 0x17A0) / sizeof(u32)];
    u32 _1a78;
    u32 _1a7c[(0x1F48 - 0x1A7C) / sizeof(u32)];
};
static_assert(sizeof(ChibiYoshiBase) == 0x1F48);
