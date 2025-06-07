#pragma once

#include <collision/BgCollision.h>

#include <container/seadBuffer.h>
#include <container/seadSafeArray.h>

class ActorBgCollisionPlayerCheck;

class PoleRopeBgCollision : public BgCollision  // vtbl Address: 0x10042828
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA380
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA384
    SEAD_RTTI_OVERRIDE(PoleRopeBgCollision, BgCollision)

public:
    // Address: 0x021AD424
    PoleRopeBgCollision();
    // Address: 0x021AD5C8
    virtual ~PoleRopeBgCollision();

    // Address: 0x021ADD60
    void vf34() override;
    // Address: 0x021AE0AC
    void execute() override;
    bool checkAreaBasic(BgCollisionCheckResultArea* p_res, const BasicBgCollisionCheck& bc, const sead::Vector2f& p0, const sead::Vector2f& p1, u8 hit_dir_mask) override { return false; }
    // Address: 0x021AE13C
    bool checkAreaActor(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) override;
    // Address: 0x021AEB48
    bool vf54(u8*, sead::Vector2f*) override;
    // Address: Deleted
    bool vf5C(u32*) override;
    // Address: 0x021AEE08
    void vf64() override;
    // Address: 0x021AEE6C
    void vf6C() override;
    void onBgCheckDataChange(const BgCheckUnitInfo& bc_data) override { }
    // Address: 0x021AF204
    bool checkPointInsideOrWithinDistance(const sead::Vector2f& p, f32 distance) const override;

    // Address: 0x021AD964
    void setCommon(const FollowArg& follow_arg, const PoleRopeInitArg& init_arg);

    // Address: 0x021ADACC
    void set(Actor* p_owner, const PoleRopeInitArg& arg);
    // Address: 0x021ADB34
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
    sead::Buffer<Angle>                         mLineAngle;
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
