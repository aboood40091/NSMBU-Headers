#pragma once

#include <collision/BasicRideLine.h>
#include <collision/BgCollision.h>

#include <container/seadBuffer.h>

class BasicRideLineBgCollision : public BgCollision
{
    SEAD_RTTI_OVERRIDE(BasicRideLineBgCollision, BgCollision)

public:
    BasicRideLineBgCollision();
    BasicRideLineBgCollision(s32 point_num, sead::Vector2f* point_buf, BasicRideLine* line_buf, BasicRideLine* line_prev_buf);
    virtual ~BasicRideLineBgCollision();

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

    void setCommon(const FollowArg& follow_arg, const InitArg& init_arg);

    void set(Actor* p_owner, const InitArg& arg);
    void set(Actor* p_owner, const InitArg& arg, s32 point_num, sead::Heap* heap = nullptr);

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
    u8                              _174[0x178 - 0x174];
};
static_assert(sizeof(BasicRideLineBgCollision) == 0x178);
