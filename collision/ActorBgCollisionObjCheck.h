#pragma once

#include <collision/ActorBgCollisionCheck.h>

class ActorBgCollisionObjCheck : public ActorBgCollisionCheck   // vtbl Address: 0x1004165C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: Deleted
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: Deleted
    SEAD_RTTI_OVERRIDE(ActorBgCollisionObjCheck, ActorBgCollisionCheck)

public:
    // Address: 0x021933C0
    ActorBgCollisionObjCheck();

    // Address: 0x0219343C
    u32 vf3C() override;
    // Address: 0x02193444
    u32 vf44() override;
    // Address: 0x0219344C
    u32 vf4C() override;
};
static_assert(sizeof(ActorBgCollisionObjCheck) == sizeof(ActorBgCollisionCheck));
