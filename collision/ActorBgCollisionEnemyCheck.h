#pragma once

#include <collision/ActorBgCollisionCheck.h>

class ActorBgCollisionEnemyCheck : public ActorBgCollisionCheck // vtbl Address: 0x1004147C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: Deleted
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: Deleted
    SEAD_RTTI_OVERRIDE(ActorBgCollisionEnemyCheck, ActorBgCollisionCheck)

public:
    // Address: 0x02191CF4
    ActorBgCollisionEnemyCheck();

    // Address: 0x02191D48
    void process() override;

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

    // Address: 0x02192044
    void vf54() override;
    // Address: 0x021920FC
    void checkFoot() override;
    // Address: 0x0219215C
    void checkHead() override;
    // Address: 0x021921BC
    void checkWall(u8 direction) override;
};
static_assert(sizeof(ActorBgCollisionEnemyCheck) == sizeof(ActorBgCollisionCheck));
