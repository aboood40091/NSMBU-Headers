#pragma once

#include <collision/ActorBgCollisionCheck.h>

class ActorBgCollisionPlayerCheck : public ActorBgCollisionCheck    // vtbl Address: 0x100417C0
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: Deleted
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: Deleted
    SEAD_RTTI_OVERRIDE(ActorBgCollisionPlayerCheck, ActorBgCollisionCheck)

public:
    enum VineType
    {
        cVineType_None  = 0,
        cVineType_Ivy,
        cVineType_Rock,
        cVineType_Wire
    };
    static_assert(sizeof(VineType) == 4);

public:
    // Address: 0x021934C0
    ActorBgCollisionPlayerCheck();
    // Address: 0x021936A8
    virtual ~ActorBgCollisionPlayerCheck();

    // Address: 0x02193714
    void checkBg() override;
    // Address: 0x02193718
    void clearBg() override;
    // Address: 0x0219371C
    void atFrameStart() override;

    // Address: 0x02193828
    bool checkDokanDown(sead::Vector3f* p_pos, s32* p_dst_next_goto_no);
    // Address: 0x02193B38
    bool checkDokanUp(sead::Vector3f* p_pos, s32* p_dst_next_goto_no);
    // Address: 0x02193E54
    bool checkDokanLR(sead::Vector3f* p_pos, s32* p_dst_next_goto_no, u32 direction, const Sensor& wall);

    // Address: 0x0219587C
    Actor* getOwnerAtRevCheck(f32 bg_collision_pos_y) const override;
    // Address: 0x021958E8
    Actor* getOwnerAtHit(const BgCollision& bg_collision, u8 direction) const override;
    // Address: 0x02195830
    s8* vf4C(f32) const override;

    VineType getVineType() const
    {
        return mVineType;
    }

    BgCollision* getVineBgCollision() const
    {
        return mpVineBgCollision;
    }

    // Address: 0x021950D0
    bool checkGround(const sead::Vector3f& pos, f32 check_distance, BgCollisionCheckResultArea* p_res = nullptr);

    using ActorBgCollisionCheck::checkWall;

    // Address: 0x02195160
    bool checkWall(const sead::Vector3f& pos, f32 speed_x, f32* p_hit_pos_x = nullptr, bool use_callback = false);

    // Address: 0x021952D4
    bool checkRoof(const sead::Vector3f& pos, f32 check_distance, f32* p_hit_pos_y = nullptr, bool no_invis_block = false);

    // Address: 0x02195658
    bool checkQuicksand(const sead::Vector3f& pos, f32* p_hit_pos_y = nullptr);

    // Address: 0x0219574C
    bool checkKani(s32* type, f32* p_hit_pos_y, const sead::Vector3f& pos, f32 check_distance);

private:
    List::Node      _14e0;
    s8              mPlayerNo;
    sead::BitFlag16 _14ee;
    u8              _14f0;
    VineType        mVineType;
    BgCollision*    mpVineBgCollision;
    u32             _14fc[(0x15A0 - 0x14FC) / sizeof(u32)];
};
static_assert(sizeof(ActorBgCollisionPlayerCheck) == 0x15A0);
