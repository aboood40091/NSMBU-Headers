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

    virtual void setWaterFunsui(bool enable)
    {
        mIsWaterFunsui = enable;
    }

    // Address: Deleted
    virtual bool isWaterFunsui() const
    {
        return mIsWaterFunsui;
    }

    virtual void beginFunsui()
    {
    }

    virtual void endFunsui(f32 speed_y)
    {
    }

    virtual bool isFunsui() const
    {
        return false;
    }

    // Address: Deleted
    virtual void vf134(f32 speed)
    {
        mSpeed.y = speed;
    }

    // Address: 0x02004008
    virtual bool vf13C();               // returns false, Determines whether vf144 should be called
    // Address: 0x0200375C
    virtual void vf144(s32);            // nullsub, parameter is based on the flag bit in Quake (either 0 or 1, can even be 2 in NSMB2 but that was removed here)
    // Address: 0x02003760
    virtual void setSmokeDamage(Actor*);

    virtual bool setTouchDrcDamage(const sead::Vector2f& pos)
    {
        return false;
    }

    virtual void setFunsuiPos(sead::Vector2f dst)
    {
        getPos2D() = dst;
    }

    virtual void setFunsuiSpeedY(f32 speed)
    {
        mSpeed.y = speed;
    }

    virtual bool smokeDamageEnable_Yogan(f32 surface_pos_y)
    {
        return true;
    }

    virtual bool smokeDamageEnable_Poison(f32 surface_pos_y)
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

protected:
    // Address: 0x020039AC
    void calcSpeedY_();
    // Address: 0x020039F0
    void calcFallSpeed_();
    // Address: 0x02003AE4
    void posMove_();
    // Address: 0x02003C10
    void calcAdditionalSpeedF_();

public:
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
    bool                        mIsWaterFunsui;
    bool                        mIsOnGround;
    u32                         _179C;
};
static_assert(sizeof(ActorCollision) == 0x17A0);
