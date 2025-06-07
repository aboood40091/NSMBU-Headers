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
    bool checkAreaBasic(BgCollisionCheckResultArea* p_res, const BasicBgCollisionCheck& bc, const sead::Vector2f& p0, const sead::Vector2f& p1, u8 hit_dir_mask) override;
    // Address: 0x02199F2C
    bool checkAreaActor(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) override;
    // Address: 0x0219A030
    bool vf54(u8*, sead::Vector2f*) override;
    // Address: Deleted
    bool vf5C(u32*) override;
    // Address: 0x0219A1BC
    void vf64() override;
    // Address: 0x0219A210
    void vf6C() override;
    void onBgCheckDataChange(const BgCheckUnitInfo& bc_data) override { }
    // Address: 0x0219A4B8
    bool checkPointInsideOrWithinDistance(const sead::Vector2f& p, f32 distance) const override;

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
