#pragma once

#include <collision/BgCollision.h>

class ActorEllipseBgCollision : public BgCollision
{
    SEAD_RTTI_OVERRIDE(ActorEllipseBgCollision, BgCollision)

public:
    ActorEllipseBgCollision();
    virtual ~ActorEllipseBgCollision();

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
    void vf74(u32*) override { }
    bool vf7C(sead::Vector2f*, f32) override;

    void setCommon(const FollowArg& follow_arg, const EllipseInitArg& init_arg);

    void set(Actor* p_owner, const EllipseInitArg& arg);

    f32 getCenterPosX() const
    {
        return getPosX() + mCenterOffset.x;
    }

    f32 getCenterPosY() const
    {
        return getPosY() + mCenterOffset.y;
    }

    const sead::Vector2f& getHalfSize() const
    {
        return mHalfSize;
    }

private:
    sead::Vector2f  mBaseCenterOffset;
    sead::Vector2f  mCenterOffset;
    sead::Vector2f  mCenterOffsetPrev;
    sead::Vector2f  mHalfSize;
    sead::Vector2f  mHalfSizePrev;
    u32             _180[0x10 / sizeof(u32)];
};
static_assert(sizeof(ActorEllipseBgCollision) == 0x190);
