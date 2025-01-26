#pragma once

#include <collision/BasicRideLine.h>
#include <collision/BgCollision.h>

#include <container/seadBuffer.h>

class BasicRideLineBgCollision : public BgCollision // vtbl Address: 0x10042238
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9D48
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FA8
    SEAD_RTTI_OVERRIDE(BasicRideLineBgCollision, BgCollision)

public:
    // Address: 0x021A1D38
    BasicRideLineBgCollision();
    // Address: 0x021A1E04
    BasicRideLineBgCollision(s32 point_num, sead::Vector2f* point_buf, BasicRideLine* line_buf, BasicRideLine* line_prev_buf);
    // Address: 0x021A1F18
    virtual ~BasicRideLineBgCollision();

    // Address: 0x021A25B4
    void vf34() override;
    // Address: 0x021A2E0C
    void execute() override;
    // Address: 0x021A2E64
    bool checkAreaBasic(BgCollisionCheckResultArea* p_res, const BasicBgCollisionCheck& bc, const sead::Vector2f& p0, const sead::Vector2f& p1, u8 hit_dir_mask) override;
    // Address: 0x021A4994
    bool checkAreaActor(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) override;
    bool vf54(u8*, sead::Vector2f*) override { return false; }
    // Address: Deleted
    bool vf5C(u32*) override;
    // Address: 0x021A4C4C
    void vf64() override;
    // Address: 0x021A4CB0
    void vf6C() override;
    // Address: 0x021A4FDC
    void onBgCheckDataChange(const BgCheckUnitInfo& bc_data) override;
    bool vf7C(sead::Vector2f*, f32) override { return false; }

    // Address: 0x021A21DC
    void setCommon(const FollowArg& follow_arg, const InitArg& init_arg);

    // Address: 0x021A2310
    void set(Actor* p_owner, const InitArg& arg);
    // Address: 0x021A2378
    void set(Actor* p_owner, const InitArg& arg, s32 point_num, sead::Heap* heap = nullptr);

    sead::Buffer<sead::Vector2f>& getPoints()
    {
        return mPoint;
    }

    const sead::Buffer<sead::Vector2f>& getPoints() const
    {
        return mPoint;
    }

    const sead::Buffer<BasicRideLine>& getRideLine() const
    {
        return mRideLine;
    }

    const sead::Buffer<BasicRideLine>& getRideLinePrev() const
    {
        return mRideLinePrev;
    }

protected:
    sead::Buffer<sead::Vector2f>    mPoint;
    sead::Buffer<BasicRideLine>     mRideLine;
    sead::Buffer<BasicRideLine>     mRideLinePrev;
    f32                             _170;
};
static_assert(sizeof(BasicRideLineBgCollision) == 0x178);
