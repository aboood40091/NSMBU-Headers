#pragma once

#include <actor/Actor.h>
#include <collision/ActorBgCollisionObjCheck.h>
#include <collision/BgCollisionCheckParam.h>

class ActorCollision : public Actor // vtbl Address: 0x1000084C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CD4
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CD8
    SEAD_RTTI_OVERRIDE(ActorCollision, Actor)

public:
    enum BgCheckFlag
    {
        cBgCheckFlag_Foot = 1 << 0,
        cBgCheckFlag_Head = 1 << 1,
        cBgCheckFlag_Wall = 1 << 2,

        cBgCheckFlag_None = 0
    };

public:
    // Address: 0x02002FB8
    ActorCollision(const ActorCreateParam& param);
    virtual ~ActorCollision() { }

protected:
    // Address: 0x0200354C
    void postCreate_(MainState state) override;

    // Address: 0x020035FC
    s32 preExecute_() override;
    // Address: 0x020036D8
    void postExecute_(MainState state) override;

    // Address: 0x02003724
    s32 doDelete_() override;

public:
    ActorBgCollisionCheck* getBgCheck() override
    {
        return &mBgCheckObj;
    }

    virtual void vf10C(u8 unk)
    {
        _179A = unk;
    }

    // Address: Deleted
    virtual u8 vf114();

    virtual void vf11C()
    {
    }

    virtual void vf124(f32)
    {
    }

    virtual bool vf12C()
    {
        return false;
    }

    // Address: Deleted
    virtual void vf134();
    // Address: 0x02004008
    virtual u32 vf13C();                // returns 0
    // Address: 0x0200375C
    virtual void vf144(bool);           // nullsub
    // Address: 0x02003760
    virtual void vf14C(Actor*);         // nullsub

    virtual bool setTouchDrcDamage(const sead::Vector2f& pos)
    {
        return false;
    }

    virtual void move(const sead::Vector2f& dst)
    {
        getPos2D() = dst;
    }

    virtual void setSpeedY(f32 speed)
    {
        mSpeed.y = speed;
    }

    virtual u32 vf16C()
    {
        return 1;
    }

    virtual bool vf174(f32)
    {
        return false;
    }

    virtual void getBox(sead::BoundBox2f& box)
    {
        box.set(
            mPos.x - 16.0f, mPos.y,
            mPos.x + 16.0f, mPos.y + 32.0f
        );
    }

    // Address: 0x020039AC
    void calcSpeedY();
    // Address: 0x020039F0
    void calcFallSpeed();
    // Address: 0x02003AE4
    void posMove();

    // Address: 0x020037F4
    BgCheckFlag bgCheck();
    // Address: 0x02003764
    bool bgCheckFoot() const;   // Must process mBgCheckObj before calling this, or just use bgCheck()
    // Address: 0x02003770
    bool bgCheckWall() const;   // ^^^

    bool checkForSuitableGround(const sead::Vector2f& offset)
    {
        BgCollisionCheckParam param = { 0 };
        param.layer = mLayer;
        param.collision_mask = mCollisionMask;

        BasicBgCollisionCheck tile_check(param);

        const sead::Vector2f& a = getPos2D();
        sead::Vector2f b(a + offset);

        return tile_check.checkArea(nullptr, a, b, 8);
    }

protected:
    u32                         _27C;
    ActorBgCollisionObjCheck    mBgCheckObj;
    f32                         mAdditionalSpeedF;
    f32                         mAdditionalAccelF;
    sead::Vector3f*             _1768;
    u8                          _176C;
    u32                         _1770;
    f32                         _1774;
    sead::Vector2f              _1778;
    sead::Vector2f              _1780;
    f32                         mLiquidSpeedMaxY_MaxClamp;
    f32                         mLiquidSpeedMaxY_MinClamp;
    f32                         mLiquidAccelY;
    u8                          _1794;
    bool                        mIsInQuicksand;
    bool                        mIsInLiquid;
    u8                          _1797;
    u8                          _1798;
    u8                          _1799;
    u8                          _179A;
    bool                        mIsOnGround;
    u32                         _179C;
};
static_assert(sizeof(ActorCollision) == 0x17A0);
