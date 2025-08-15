#pragma once

#include <actor/ActorBase.h>
#include <actor/ActorCullRange.h>
#include <collision/ActorCollisionCheck.h>
#include <utility/Angle3.h>
#include <utility/Direction.h>

class ActorBgCollisionCheck;
class ChibiYoshiAwaData;
class ChibiYoshiEatData;
class EatData;
class PropelParts;

typedef s32 EffectID;

class Actor : public ActorBase  // vtbl Address: 0x10000268
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CBC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CC0
    SEAD_RTTI_OVERRIDE(Actor, ActorBase)

public:
    enum ActorType
    {
        cActorType_Generic  = 0,
        cActorType_Player,
        cActorType_Yoshi,
        cActorType_Enemy,
        cActorType_ChibiYoshi
    };

public:
    virtual void setPlayerNo(s8 id)
    {
        mPlayerNo = id;
    }

    s8 getPlayerNo() const
    {
        return mPlayerNo;
    }

    // Address: 0x020002CC
    virtual void removeCollisionCheck();
    // Address: 0x02000328
    virtual void reviveCollisionCheck();

    virtual ActorBgCollisionCheck* getBgCheck()
    {
        return nullptr;
    }

    virtual void setCarryFall(Actor*, s32)
    {
    }

    virtual bool isSpinLiftUpEnable()
    {
        return true;
    }

    virtual void setSpinLiftUpActor(Actor*)
    {
    }

    virtual void vfC4()
    {
    }

    virtual void vfCC()
    {
    }

    // Address: 0x02000394
    bool checkCarried(s32* p_player_no);

    s32 getComboCnt() const
    {
        return mComboCnt;
    }

    // Address: 0x02000418
    void clrComboCnt();
    // Address: 0x0200042C
    void incComboCnt();

    // Address: 0x02000454
    void slideComboSE(s32 combo_cnt, bool combo_type_2);

    // Address: 0x020005A4
    s32 searchNearPlayer(sead::Vector2f& out); // Returns -1 if no player found
    // Address: 0x020005EC
    u32 directionToPlayerH(const sead::Vector3f& position);
    // Address: 0x020006B4
    u32 directionToPlayerV(const sead::Vector3f& position);

    // Address: 0x020007A0
    bool screenOutCheck(u16 flag);

    // Address: 0x02002AD8
    virtual void allEnemyDeathEffSet(); // Spawn burst effect at instances where all enemies die (such as touching goal pole or defeating boss), called if profile flag bit 4, 5 or 7 is set
    // Address: 0x02002ADC
    virtual void waterSplashEffect(const sead::Vector3f& pos);
    // Address: 0x02002AE0
    virtual void yoganSplashEffect(const sead::Vector3f& pos);
    // Address: 0x02000960
    virtual void yoganWaveSplashEffect(const sead::Vector3f& pos);
    // Address: 0x02002AE4
    virtual void poisonSplashEffect(const sead::Vector3f& pos);

    // Address: 0x02000970
    f32 getEffectZPos() const;

    // Address: 0x02000A70
    bool checkEat() const;

    // Address: 0x02000774
    void deleteActor(bool no_respawn);

public:
    ActorCollisionCheck& getCollisionCheck()
    {
        return mCollisionCheck;
    }

    const ActorCollisionCheck& getCollisionCheck() const
    {
        return mCollisionCheck;
    }

    bool isExecEnable() const
    {
        return mIsExecEnable;
    }

    bool isDrawEnable() const
    {
        return mIsDrawEnable;
    }

    u32 getDirection() const
    {
        return mDirection;
    }

    void setDirection(u32 dir)
    {
        mDirection = dir;
    }

    sead::Vector3f& getPos()
    {
        return mPos;
    }

    const sead::Vector3f& getPos() const
    {
        return mPos;
    }

    sead::Vector2f& getPos2D()
    {
        return reinterpret_cast<sead::Vector2f&>(mPos.x);
    }

    const sead::Vector2f& getPos2D() const
    {
        return reinterpret_cast<const sead::Vector2f&>(mPos.x);
    }

    sead::Vector3f getCenterPos() const
    {
        return getPos() + mCenterOffset;
    }

    sead::Vector2f getCenterPos2D() const
    {
        return getPos2D() + reinterpret_cast<const sead::Vector2f&>(mCenterOffset.x);
    }

    sead::Vector3f& getSpeedVec()
    {
        return mSpeed;
    }

    const sead::Vector3f& getSpeedVec() const
    {
        return mSpeed;
    }

    sead::Vector3f& getScale()
    {
        return mScale;
    }

    const sead::Vector3f& getScale() const
    {
        return mScale;
    }

    Angle3& getAngle()
    {
        return mAngle;
    }

    const Angle3& getAngle() const
    {
        return mAngle;
    }

    ActorType getActorType() const
    {
        return ActorType(mActorType);
    }

    bool isNoRespawn() const
    {
        return mIsNoRespawn;
    }

protected:
    // Address: 0x02000AC8
    Actor(const ActorCreateParam& param);
    // Address: 0x02000F18
    virtual ~Actor();

protected:
    // Address: 0x02000FB8
    void postCreate_(MainState state) override;

    // Address: 0x02000FE8
    s32 preExecute_() override;
    // Address: 0x020010BC
    void postExecute_(MainState state) override;

    // Address: 0x020011A0
    s32 preDraw_() override;

    // Address: 0x02001254
    virtual bool drawCullCheck_();

    virtual void blockHitInit_()
    {
    }

    // Address: 0x02001304
    void splashEffect_(const sead::Vector3f& pos, EffectID effect_id, u8 wave_scale, const char* sound_label);

    // Address: 0x020013D4
    void setAreaNo_();

    // Address: 0x020013E8
    void calcSpeedX_();
    // Address: 0x02001430
    void calcSpeedY_(f32 accel_y, f32 speed_max_y);
    void calcSpeedY_() { calcSpeedY_(mAccelY, mSpeedMax.y); }

    void calcSpeedF_() { sead::Mathf::chase(&mSpeedF, mSpeedFMax, mAccelF); }
    // Address: 0x0200144C
    void calcFallSpeed_(f32 accel_y, f32 fall_speed_max);
    void calcFallSpeed_() { calcFallSpeed_(mAccelY, mFallSpeedMax); }

    void posMove_(sead::Vector3f& delta)
    {
        mPos += delta;
    }

    void posMove_()
    {
        posMove_(mSpeed);
    }

    // Address: 0x02001A28
    void carryFukidashiCheck_(s32 action);
    // Address: 0x02001490
    void carryFukidashiCheck_(s32 action, const sead::Vector2f& range);
    // Address: 0x02001A64
    void carryFukidashiCancel_(s32 action, s32 player_no);

private:
    inline Actor* searchCarryFukidashiPlayer_(s32 action);

    // Address: 0x02000720
    u32 calcTottenToSrcDir_(const sead::BoundBox2f& src_range) const;

protected:
    u32                     mDirection;
    s8                      mPlayerNo;
    s8                      mControllerLytPlayerNo;
    u8                      mLayer;                     // Inited to ActorCreateParam::layer
    sead::BitFlag8          mCollisionMask;
    f32                     mSpeedF;                    // Horizontal speed
    f32                     mSpeedFMax;                 // Maximum horizontal speed
    f32                     mFallSpeedMax;              // Maximum fall speed
    f32                     mAccelY;                    // Vertical acceleration
    f32                     mAccelF;                    // Horizontal acceleration
    sead::Vector3f          mPos;
    sead::Vector3f          mSpeed;
    sead::Vector3f          mSpeedMax;
    sead::Vector3f          mScale;
    Angle3                  mAngle;
    Angle3                  mAnglePrev;
    sead::Vector2f          mPosDelta;                  // At start of every frame
    ActorCollisionCheck     mCollisionCheck;
    sead::Vector2f          mVisibleAreaOffset;         // Inited to ActorCreateInfo::spawn_range.offset
    sead::Vector2f          mVisibleAreaSize;           // Inited to ActorCreateInfo::spawn_range.half_size * 2
    sead::Vector2f          mSize;
    ActorCullRange          mCullLimit;                 // Inited to { 256.0 + ActorCreateInfo::cull_range.up,
                                                        //             256.0 + ActorCreateInfo::cull_range.down,
                                                        //              80.0 + ActorCreateInfo::cull_range.left,
                                                        //              80.0 + ActorCreateInfo::cull_range.right }
    u8                      mAreaNo;
    u8                      mActorType;                 // ActorType
    bool                    mIsExecEnable;
    bool                    mIsDrawEnable;
    bool                    mIsNoRespawn;
    u8                      _211;
    u8                      mCarryFlag;                 // & 2 = isCarry
    u8                      mSwitchFlag0;
    u8                      mSwitchFlag1;
    u16                     mCreateFlag;                // Inited to ActorCreateInfo::flag
    u32                     mBumpDamageTimer;
    u32                     mBumpDirection;
    u8                      _220;
    u32                     mCarryDirection;
    u32                     mThrowPlayerNo;
    s32                     mComboCnt;
    u32                     mProfFlag;                  // Inited to Profile::mFlag
    sead::Vector3f          mCenterOffset;
    sead::Vector3f          mPosPrev;                   // At frame start
    sead::Vector3f          mPosPrevPostExec;
    sead::Vector3f          mPosPrev2;                  // At frame end
    EatData*                mpEatData;
    ChibiYoshiEatData*      mpChibiYoshiEatData;
    PropelParts*            mpPropelParts;
    u8*                     _270;                       // Inited to ActorCreateParam::_28
    f32                     mThrowSpeed;
    ChibiYoshiAwaData*      mpChibiYoshiAwaData;

    // Address: 0x10000B64
    static const f32 cCullXLimit;
    // Address: 0x10000B68
    static const f32 cCullYLimit;
};
static_assert(sizeof(Actor) == 0x27C);
