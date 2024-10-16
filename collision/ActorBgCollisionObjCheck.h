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

    Actor* vf3C(f32) const override
    {
        return mpOwner;
    }

    Actor* vf44(const BgCollision&, s32) const override
    {
        return mpOwner;
    }

    u8* vf4C(f32) const override
    {
        return mFollowArg.p_player_no;
    }
};
static_assert(sizeof(ActorBgCollisionObjCheck) == sizeof(ActorBgCollisionCheck));
