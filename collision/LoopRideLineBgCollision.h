#pragma once

#include <collision/BasicRideLine.h>
#include <collision/BgCollision.h>

#include <container/seadBuffer.h>

class LoopRideLineBgCollisionUtil;

class LoopRideLineBgCollision : public BgCollision
{
    SEAD_RTTI_OVERRIDE(LoopRideLineBgCollision, BgCollision)

public:
    LoopRideLineBgCollision();
    LoopRideLineBgCollision(s32 point_num, sead::Vector2f* point_buf, BasicRideLine* line_buf, BasicRideLine* line_prev_buf);
    virtual ~LoopRideLineBgCollision();

    void vf34() override;
    void execute() override;
    bool vf44(ActorBgCollisionCheckResult*, u8*, sead::Vector2f*, sead::Vector2f*, u8) override;
    bool vf4C(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) override;
    bool vf54(u8*, sead::Vector2f*) override;
    bool vf5C(u32*) override; // deleted
    void vf64() override;
    void vf6C() override;
    void vf74(u32*) override;
    bool vf7C(sead::Vector2f*, f32) override;

    virtual void vf84();

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

    friend class LoopRideLineBgCollisionUtil;
};
static_assert(sizeof(LoopRideLineBgCollision) == 0x170);
