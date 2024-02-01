#pragma once

#include <collision/BasicRideLine.h>
#include <collision/BgCollision.h>

#include <container/seadBuffer.h>

class LoopRideLineBgCollisionUtil;

class LoopRideLineBgCollision : public BgCollision  // vtbl Address: 0x10042688
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9D30
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FB4
    SEAD_RTTI_OVERRIDE(LoopRideLineBgCollision, BgCollision)

public:
    // Address: 0x021A7844
    LoopRideLineBgCollision();
    // Address: 0x021A7904
    LoopRideLineBgCollision(s32 point_num, sead::Vector2f* point_buf, BasicRideLine* line_buf, BasicRideLine* line_prev_buf);
    // Address: 0x021A7A04
    virtual ~LoopRideLineBgCollision();

    // Address: 0x021A7E34
    void vf34() override;
    // Address: 0x021A871C
    void execute() override;
    // Address: 0x021A8780
    bool vf44(BgCollisionCheckResult*, u8*, sead::Vector2f*, sead::Vector2f*, u8) override;
    // Address: 0x021ABFD8
    bool vf4C(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) override;
    // Address: 0x021AC158
    bool vf54(u8*, sead::Vector2f*) override;
    // Address: Deleted
    bool vf5C(u32*) override;
    // Address: 0x021ACB50
    void vf64() override;
    // Address: 0x021ACBB4
    void vf6C() override;
    // Address: 0x021ACE40
    void vf74(u32*) override;
    // Address: 0x021ACE8C
    bool vf7C(sead::Vector2f*, f32) override;

    // Address: 0x021AC8F8
    virtual void vf84();

    // Address: 0x021A7A58
    void setCommon(const FollowArg& follow_arg, const InitArg& init_arg);

    // Address: 0x021A7B88
    void set(Actor* owner, const InitArg& arg);
    // Address: 0x021A7BF0
    void set(Actor* owner, const InitArg& arg, s32 point_num, sead::Heap* heap = nullptr);

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
