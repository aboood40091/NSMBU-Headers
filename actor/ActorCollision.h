#pragma once

#include <actor/Actor.h>
#include <collision/ActorBgCollisionObjCheck.h>
#include <collision/BgCollisionCheckParam.h>

class ActorCollision : public Actor // vtbl Address: 0x1000084C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CD4
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CD8
    SEAD_RTTI_OVERRIDE(ActorCollision, Actor)

protected:
    enum BgCheckFlag
    {
        cBgCheckFlag_Foot = 1 << 0,
        cBgCheckFlag_Head = 1 << 1,
        cBgCheckFlag_Wall = 1 << 2,

        cBgCheckFlag_None = 0
    };

    enum WaterCalcType
    {
        cWaterCalcType_Normal = 0,
        cWaterCalcType_EnablePreCheck,
        cWaterCalcType_ForceOut
    };

protected:
    friend BgCheckFlag operator|(const BgCheckFlag& lhs, const BgCheckFlag& rhs)
    {
        return (BgCheckFlag)((u32)lhs | (u32)rhs);
    }

    friend BgCheckFlag& operator|=(BgCheckFlag& lhs, const BgCheckFlag& rhs)
    {
        lhs = lhs | rhs;
        return lhs;
    }

public:
    ActorBgCollisionCheck* getBgCheck() override
    {
        return &mBgCheckObj;
    }

protected:
    // Address: 0x02002FB8
    ActorCollision(const ActorCreateParam& param);
    virtual ~ActorCollision() { }

    // Address: 0x0200354C
    void postCreate_(MainState state) override;

    // Address: 0x020035FC
    bool preExecute_() override;
    // Address: 0x020036D8
    void postExecute_(MainState state) override;

    // Address: 0x02003724
    Result doDelete_() override;

    virtual void setWaterFunsui_(bool enable)
    {
        mIsWaterFunsui = enable;
    }

    // Address: Deleted
    virtual bool isWaterFunsui_() const
    {
        return mIsWaterFunsui;
    }

    virtual void beginFunsui_()
    {
    }

    virtual void endFunsui_(f32 speed_y)
    {
    }

    virtual bool isFunsui_() const
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
    virtual void setSmokeDamage_(Actor* p_actor);

    virtual bool setTouchDrcDamage_(const sead::Vector2f& pos)
    {
        return false;
    }

    virtual void setFunsuiPos_(sead::Vector2f dst)
    {
        getPos2D() = dst;
    }

    virtual void setFunsuiSpeedY_(f32 speed)
    {
        mSpeed.y = speed;
    }

    virtual bool smokeDamageEnable_Yogan_(f32 surface_pos_y)
    {
        return true;
    }

    virtual bool smokeDamageEnable_Poison_(f32 surface_pos_y)
    {
        return false;
    }

    virtual void getBox_(sead::BoundBox2f& box)
    {
        box.set(
            mPos.x - 16.0f, mPos.y,
            mPos.x + 16.0f, mPos.y + 32.0f
        );
    }

    // Address: 0x020037F4
    BgCheckFlag bgCheck_();
    // Address: 0x02003764
    bool bgCheckFoot_() const;   // Must process mBgCheckObj before calling this, or just use bgCheck_()
    // Address: 0x02003770
    bool bgCheckWall_() const;   // ^^^

    // Address: 0x02003878
    void clampMoveDistance_(BgCollision& bg_collision);

    // Address: 0x020038D8
    bool isHitBgCollision_(const BgCollision& bg_collision) const;

    // Address: 0x020039AC
    void calcSpeedY_();
    // Address: 0x020039F0
    void calcFallSpeed_();
    // Address: 0x02003AE4
    void posMove_();
    // Address: 0x02003A70
    void posMoveCalcJump_();
    // Address: 0x02003C10
    void calcJumpSpeedF_();

    // Address: 0x02003120
    void enterWater_();

    bool checkForSuitableGround_(const sead::Vector2f& offset) const
    {
        BgCollisionCheckParam param = { 0 };
        param.layer = mLayer;
        param.collision_mask = mCollisionMask;

        BasicBgCollisionCheck tile_check(param);

        const sead::Vector2f& a = getPos2D();
        sead::Vector2f b(a + offset);

        return tile_check.checkArea(nullptr, a, b, 1 << cDirType_Down);
    }

private:
    // Address: 0x0200339C
    void calcWater_();

    // Address: 0x02003148
    WaterType checkEnterWater_(f32* p_surface_pos_y, const sead::Vector3f& check_pos);
    // Address: 0x020030F4
    void clampWaterSpeedY_();

    // Address: 0x02003590
    void calcBgSpeed_();

    // Address: 0x02003A34
    f32 chaseZero_(f32 value, f32 step) const;

protected:
  //u32                         _27c[4 / sizeof(u32)];  // Alignment???
    ActorBgCollisionObjCheck    mBgCheckObj;
    f32                         mJumpSpeedF;
    f32                         mJumpAccelF;
    sead::Vector3f*             mpWaterCheckPos;
    bool                        mUseWaterTypeOverride;
    WaterType                   mWaterTypeOverride;
    f32                         _1774;
    sead::Vector2f              mBgSpeed;
    sead::Vector2f              mBgSpeedPrev;
    f32                         mWaterSpeedMaxY;        // Maximum ascension speed
    f32                         mWaterFallSpeedMax;
    f32                         mWaterGravity;
    bool                        mCheckWaterNeeded;
    bool                        mIsInQuicksand;
    bool                        mIsSubmerged;
    bool                        mNoWaterCalc;
    u8                          mWaterCalcType;
    u8                          mNoLavaSplashTimer;
    bool                        mIsWaterFunsui;
    bool                        mIsOnGround;
    u32                         mJumpFrame;
};
static_assert(sizeof(ActorCollision) == 0x17A0);
