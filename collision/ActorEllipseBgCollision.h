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
    bool checkAreaBasic(BgCollisionCheckResultArea* p_res, const BasicBgCollisionCheck& bc, const sead::Vector2f& p0, const sead::Vector2f& p1, u8 hit_dir_mask) override;
    // Address: 0x021A035C
    bool checkAreaActor(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) override;
    // Address: 0x0219FCF4
    bool checkPointInside(bool* p_on_edge, const sead::Vector2f& p) const override;
    // Address: Deleted
    bool vf5C(u32*) override;
    // Address: 0x0219FDFC
    void vf64() override;
    // Address: 0x0219FE48
    void vf6C() override;
    void onBgCheckDataChange(const u64& bc_data) override { }
    // Address: 0x021A0100
    bool checkPointInsideOrWithinDistance(const sead::Vector2f& p, f32 distance) const override;

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

    sead::Vector2f getCenterPos() const
    {
        return getPos() + mCenterOffset;
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
