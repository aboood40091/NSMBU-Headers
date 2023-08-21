#pragma once

#include <collision/LoopRideLineBgCollision.h>

class LoopRideLineBgCollisionUtil
{
    // For setting a LoopRideLineBgCollision as a Box

public:
    // Address: 0x021AD2E0
    static void setCommon(LoopRideLineBgCollision* p_bg_collision, const FollowArg& follow_arg, const BgCollision::BoxInitArg& init_arg);
    // Address: 0x021AD3BC
    static void set(LoopRideLineBgCollision* p_bg_collision, Actor* p_owner, const BgCollision::BoxInitArg& arg);
    // Address: 0x021AD25C
    static void setOfs(LoopRideLineBgCollision* p_bg_collision, const sead::Vector2f& p0, const sead::Vector2f& p1);
};
