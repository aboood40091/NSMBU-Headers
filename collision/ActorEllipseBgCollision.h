#pragma once

#include <collision/BgCollision.h>

class ActorEllipseBgCollision : public BgCollision  // vtbl Address: 0x10041F08
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA39C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA3A0
    SEAD_RTTI_OVERRIDE(ActorEllipseBgCollision, BgCollision)

public:
    // Address: 0x0219EA1C
    ActorEllipseBgCollision();
    virtual ~ActorEllipseBgCollision() { }

    // Address: 0x021A02E0 (TODO: This should be inline)
    bool vf24(u32*, u32) override;
    // Address: 0x021A0320 (TODO: This should be inline)
    u32 vf2C(u32*) override;
    // Address: 0x0219EDE8
    void vf34() override;
    // Address: 0x0219EDF8
    void execute() override;
    // Address: 0x0219F260
    bool vf44(BgCollisionCheckResult*, u8*, sead::Vector2f*, sead::Vector2f*, u8) override;
    // Address: 0x021A035C
    bool vf4C(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) override;
    // Address: 0x0219FCF4
    bool vf54(u8*, sead::Vector2f*) override;
    // Address: Deleted
    bool vf5C(u32*) override;
    // Address: 0x0219FDFC
    void vf64() override;
    // Address: 0x0219FE48
    void vf6C() override;
    void vf74(u32*) override { }
    // Address: 0x021A0100
    bool vf7C(sead::Vector2f*, f32) override;

    // Address: 0x0219EC88
    void setCommon(const FollowArg& follow_arg, const EllipseInitArg& init_arg);

    // Address: 0x0219ED80
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
