#pragma once

#include <collision/BgCollision.h>

#include <container/seadBuffer.h>
#include <container/seadSafeArray.h>

class ActorBgCollisionPlayerCheck;

class PoleRopeBgCollision : public BgCollision
{
    SEAD_RTTI_OVERRIDE(PoleRopeBgCollision, BgCollision)

public:
    PoleRopeBgCollision();
    virtual ~PoleRopeBgCollision();

    bool vf24(u32*, u32) override;
    u32 vf2C(u32*) override;
    void vf34() override;
    void execute() override;
    bool vf44(ActorBgCollisionCheckResult*, u8*, sead::Vector2f*, sead::Vector2f*, u8) override { return false; }
    bool vf4C(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) override;
    bool vf54(u8*, sead::Vector2f*) override;
    bool vf5C(u32*) override;
    void vf64() override;
    void vf6C() override;
    void vf74(u32*) override { }
    bool vf7C(sead::Vector2f*, f32) override;

    void setCommon(const FollowArg& follow_arg, const PoleRopeInitArg& init_arg);

    void set(Actor* p_owner, const PoleRopeInitArg& arg);
    void set(Actor* p_owner, const PoleRopeInitArg& arg, s32 line_num, sead::Heap* heap = nullptr);

    const sead::Buffer<sead::Vector2f>& getPoints() const
    {
        return mPoint;
    }

    f32 getRange() const
    {
        return mRange;
    }

protected:
    LineNodeMgr<ActorBgCollisionPlayerCheck>    mPlayerBcList;
    sead::UnsafeArray<s32,              4>      _164;
    sead::UnsafeArray<sead::BitFlag32,  4>      _174;   // I think? (unused)
    sead::Buffer<u32>                           mLineAngle;
    sead::Buffer<sead::Vector2f>                mPoint;
    sead::Buffer<sead::Vector2f>                mPointPrev;
    sead::Vector2f                              mBaseStartPoint;
    f32                                         _1a4;
    f32                                         mLineLength;
    f32                                         mRange;
    f32                                         mLineLengthTotal;
    u8                                          _1b4[0x1B8 - 0x1B4];
};
static_assert(sizeof(PoleRopeBgCollision) == 0x1B8);
