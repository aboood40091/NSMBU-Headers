#pragma once

#include <collision/BgCollision.h>
#include <utility/Angle.h>

class ActorCircleBgCollision : public BgCollision   // vtbl Address: 0x10041B28
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9F88
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA398
    SEAD_RTTI_OVERRIDE(ActorCircleBgCollision, BgCollision)

public:
    // Address: 0x02197C88
    ActorCircleBgCollision();
    virtual ~ActorCircleBgCollision() { }

    // Address: 0x0219A6D0 (TODO: This should be inline)
    bool vf24(u32*, u32) override;
    // Address: 0x0219A710 (TODO: This should be inline)
    u32 vf2C(u32*) override;
    // Address: 0x021980B0
    void vf34() override;
    // Address: 0x02198614
    void execute() override;
    // Address: 0x02198930
    bool vf44(BgCollisionCheckResult*, u8*, sead::Vector2f*, sead::Vector2f*, u8) override;
    // Address: 0x02199F2C
    bool vf4C(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) override;
    // Address: 0x0219A030
    bool vf54(u8*, sead::Vector2f*) override;
    // Address: Deleted
    bool vf5C(u32*) override;
    // Address: 0x0219A1BC
    void vf64() override;
    // Address: 0x0219A210
    void vf6C() override;
    void vf74(u32*) override { }
    // Address: 0x0219A4B8
    bool vf7C(sead::Vector2f*, f32) override;

private:
    // Address: 0x02197F0C
    void setCommon_(const FollowArg& follow_arg, const CircleInitArg& init_arg);

public:
    // Address: 0x02197FF0
    void set(Actor* p_owner, const CircleInitArg& arg);
    // Address: 0x02198058
    void set(Actor* p_owner, const CircleInitArg& arg, Angle angle_start, Angle angle_end);

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

    Angle getArcStart() const
    {
        return mArcStart;
    }

    Angle getArcEnd() const
    {
        return mArcEnd;
    }

private:
    sead::Vector2f  mBaseCenterOffset;
    sead::Vector2f  mCenterOffset;
    sead::Vector2f  mCenterOffsetPrev;
    f32             mRadius;
    f32             mRadiusPrev;
    Angle           mBaseArcStart;
    Angle           mBaseArcEnd;
    Angle           mArcStart;
    Angle           mArcEnd;
    Angle           mArcStartPrev;
    Angle           mArcEndPrev;
};
static_assert(sizeof(ActorCircleBgCollision) == 0x190);
