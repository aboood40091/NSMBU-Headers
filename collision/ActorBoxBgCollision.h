#pragma once

#include <collision/SimpleBoxBgCollision.h>
#include <collision/LoopRideLineBgCollisionUtil.h>

class ActorBoxBgCollision : public SimpleBoxBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9D38
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FBC
    SEAD_RTTI_OVERRIDE(ActorBoxBgCollision, SimpleBoxBgCollision)

public:
    void setCommon(const FollowArg& follow_arg, const BoxInitArg& init_arg)
    {
        LoopRideLineBgCollisionUtil::setCommon(this, follow_arg, init_arg);
    }

    void set(Actor* p_owner, const BoxInitArg& arg)
    {
        LoopRideLineBgCollisionUtil::set(this, p_owner, arg);
    }

    void setOfs(const sead::Vector2f& p0, const sead::Vector2f& p1) // left top and right bottom
    {
        LoopRideLineBgCollisionUtil::setOfs(this, p0, p1);
    }
};
static_assert(sizeof(ActorBoxBgCollision) == sizeof(SimpleBoxBgCollision));
