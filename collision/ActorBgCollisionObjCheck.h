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

    Actor* getOwnerAtRevCheck(f32 bg_collision_pos_y) const override
    {
        return mpOwner;
    }

    Actor* getOwnerAtHit(const BgCollision& bg_collision, u8 direction) const override
    {
        return mpOwner;
    }

    s8* vf4C(f32) const override
    {
        return mFollowArg.p_player_no;
    }
};
static_assert(sizeof(ActorBgCollisionObjCheck) == sizeof(ActorBgCollisionCheck));
