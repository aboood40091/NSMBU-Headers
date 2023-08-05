#pragma once

#include <collision/BgCollision.h>

class ActorCircleBgCollision : public BgCollision
{
    SEAD_RTTI_OVERRIDE(ActorCircleBgCollision, BgCollision)

public:
    ActorCircleBgCollision();
    virtual ~ActorCircleBgCollision();

    bool vf24(u32*, u32) override;
    u32 vf2C(u32*) override;
    void vf34() override;
    void execute() override;
    bool vf44(ActorBgCollisionCheckResult*, u8*, sead::Vector2f*, sead::Vector2f*, u8) override;
    bool vf4C(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) override;
    bool vf54(u8*, sead::Vector2f*) override;
    bool vf5C(u32*) override;
    void vf64() override;
    void vf6C() override;
    void vf74(u32*) override;
    bool vf7C(sead::Vector2f*, f32) override;

private:
    void setCommon_(const FollowArg& follow_arg, const CircleInitArg& init_arg);

public:
    void set(Actor* p_owner, const CircleInitArg& arg);
    void set(Actor* p_owner, const CircleInitArg& arg, const u32& angle_start, const u32& angle_end);

    f32 getCenterPosX() const
    {
        return getPosX() + mCenterOffset.x;
    }

    f32 getCenterPosY() const
    {
        return getPosY() + mCenterOffset.y;
    }

    f32 getRadius() const
    {
        return mRadius;
    }

    u32 getArcStart() const
    {
        return mArcStart;
    }

    u32 getArcEnd() const
    {
        return mArcEnd;
    }

private:
    sead::Vector2f  mBaseCenterOffset;
    sead::Vector2f  mCenterOffset;
    sead::Vector2f  mCenterOffsetPrev;
    f32             mRadius;
    f32             mRadiusPrev;
    u32             mBaseArcStart;
    u32             mBaseArcEnd;
    u32             mArcStart;
    u32             mArcEnd;
    u32             mArcStartPrev;
    u32             mArcEndPrev;
};
static_assert(sizeof(ActorCircleBgCollision) == 0x190);
