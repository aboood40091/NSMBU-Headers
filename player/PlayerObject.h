#pragma once

#include <actor/PropelParts.h>
#include <graphics/Light.h>
#include <map/CarryType.h>
#include <player/PlayerBase.h>
#include <player/PlayerEatData.h>
#include <player/PlayerModelMgr.h>
#include <player/PlyOrchestra.h>
#include <player/util/ChangeMgr.h>

class EventDie;
class EventPlayerChange;

class PlayerObject : public PlayerBase  // vtbl Address: 0x1016C150
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9C9C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CA0
    SEAD_RTTI_OVERRIDE(PlayerObject, PlayerBase)

public:
    enum CcSizeDataType
    {
        cCcSizeDataType_Mame = 0,
        cCcSizeDataType_Normal,
        cCcSizeDataType_Super,
        cCcSizeDataType_Propel,
        cCcSizeDataType_MameSit,
        cCcSizeDataType_NormalSit,
        cCcSizeDataType_SuperSit,
        cCcSizeDataType_NormalSwim,
        cCcSizeDataType_SuperSwim,
        cCcSizeDataType_NormalWaterWalk,
        cCcSizeDataType_SuperWaterWalk,
        cCcSizeDataType_PenguinSlid,
        cCcSizeDataType_12,             // Carry-related, but it's unknown what exactly it is used for
        cCcSizeDataType_TottenPole,
        cCcSizeDataType_Num
    };
    static_assert(cCcSizeDataType_Num == 14);

    enum CarryStep
    {
        cCarryStep_None = 0,
        cCarryStep_Carry_NoTimer,
        cCarryStep_LiftUp,
        cCarryStep_Carry
    };
    static_assert(sizeof(CarryStep) == 4);

    enum DokanCannonType
    {
        cDokanCannonType_ShootUp = 0,
        cDokanCannonType_ShootDiagonal,
        cDokanCannonType_WarpCannon
    };
    static_assert(sizeof(DokanCannonType) == 4);

    enum QuakeMode
    {
    };
    static_assert(sizeof(QuakeMode) == 4);

public:
    // ------------------------------------ PlayerObject.cpp ------------------------------------ //

    // Address: 0x02923520
    PlayerObject(const ActorCreateParam& param);

    // Address: 0x02925258
    virtual void setCharacterVoice();

    // ------------------------------------ PlayerObjectCc.cpp ------------------------------------ //

    // Address: 0x0292E92C
    void getSpinLiftUpCcSizeInfo(sead::Vector2f* p_center_offset, sead::Vector2f* p_half_size);

    // Address: 0x0292E9C8
    virtual void setFireBallDamage(ActorCollisionCheck::Attack attack);

    // Address: 0x0292EA6C
    virtual CcSizeDataType getCcSizeDataType();

    // Address: 0x0292EB3C
    virtual bool setPlayerFlyDamage(PlayerBase* p_player_other, ActorCollisionCheck::Attack attack);

    // ------------------------------------ PlayerObjectDemo.cpp ------------------------------------ //

    // Address: 0x02931B34
    virtual bool canChangeTo(PlayerMode mode);

    // ------------------------------------ PlayerObjectDemoDokan.cpp ------------------------------------ //

    // Address: 0x02936020
    void initDemoInDokan(DokanDir dir) override;
    // Address: 0x02936130
    virtual void initDemoInDokanAngle(DokanDir dir);

    // ------------------------------------ PlayerObjectDemoDown.cpp ------------------------------------ //

    // Address: 0x02937794
    virtual void initPlayerDownCommonImpl();

    // ------------------------------------ PlayerObjectMain.cpp ------------------------------------ //

    // Address: 0x02948FCC
    bool setRideOffPlayerJump(f32 speed_y, f32 speed_f);

    // ------------------------------------ PlayerObjectPropel.cpp ------------------------------------ //

    // Address: 0x029480AC
    void setPropelFallSpin();

    // ------------------------------------ PlayerObjectSpin.cpp ------------------------------------ //

    // Address: 0x0294B5B8
    Angle getMissSpinAngle();

    // ------------------------------------ PlayerObjectStar.cpp ------------------------------------ //

    // Address: 0x0294FF20
    bool isStar() const override;

    // ------------------------------------ PlayerObjectVine.cpp ------------------------------------ //

    // Address: 0x02954840
    void VineActionNet();

    // Address: 0x02953D50
    bool checkVineEnd();
    // Address: 0x02953E2C
    void calcVineSpeed();
    // Address: 0x0295436C
    bool setVineToKaniHangAction();
    // Address: 0x02954560
    void vineWalk();

    // ------------------------------------ PlayerObjectWalk.cpp ------------------------------------ //

    // Address: 0x02957034
    virtual void setWalkAnm(s32 anm_id, AnmBlend blend, f32 rate);

    // Address: 0x029573A8
    virtual bool isIceSlipAnmPlay();

    // Address: 0x02957418
    bool isWaitFrameCountMax() override;

    // Address: 0x02957430
    virtual void setTurnAction_Turned();

    // ------------------------------------ PlayerObjectJump.cpp ------------------------------------ //

    // Address: 0x02940C38
    virtual void setFunsuiAscendAnm();

    // ------------------------------------ PlayerObjectSpin.cpp ------------------------------------ //

    // Address: 0x0294B37C
    virtual void getSpinJumpEffectPos(sead::Vector3f& pos);

    // Address: 0x0294B398
    virtual void setSpinJumpEffectSub();

    // ------------------------------------ PlayerObjectTarzanRope.cpp ------------------------------------ //

    // Address: 0x02952B58
    virtual void setRopeHasigoHangUpAngle();

    // ------------------------------------ PlayerObjectDamage.cpp ------------------------------------ //

    // Address: 0x02930858
    bool setDamage2(Actor* p_actor, DamageType type) override;

    // Address: 0x02930A8C
    virtual bool setFlyDamageAction(DamageType type, Actor* p_actor);

    // Address: 0x0293063C
    bool setFlyDamageActionImpl_Part1(DamageType type, Actor* p_actor);
    // Address: 0x02930B48
    virtual bool setFlyDamageActionImpl_Part2(DamageType type, bool, bool = false, bool = false);

    bool setFlyDamageActionImpl(DamageType type, Actor* p_actor)
    {
        if (setFlyDamageActionImpl_Part2(type, setFlyDamageActionImpl_Part1(type, p_actor)))
            return true;
        return false;
    }

    // Address: 0x02930D68
    virtual void setElecDamage();

    // Address: 0x02931368
    bool setDamage(Actor* p_actor, DamageType type) override;
    // Address: 0x02931458
    bool setForcedDamage(Actor* p_actor, DamageType type) override;

    // Address: 0x0293153C
    bool setFlyDamage(DamageType type, s32 dir, bool, bool, f32 speed_F, f32 speed_y) override;

    // Address: 0x02931678
    virtual void setRideOffDamage();

    // ------------------------------------ PlayerObjectCarry.cpp ------------------------------------ //

    // Address: 0x0292D138
    virtual bool setCarry(Actor* p_actor, CarryType type);

    // Address: 0x0292CEBC
    void cancelCarry(Actor* p_actor);

    // Address: 0x0292D564
    f32 getCarryStepRatio();

    // Address: 0x0292D704
    bool getCarryMtx(sead::Matrixf* p_mtx);

    ActorUniqueID getCarryActorID() const
    {
        return mCarryActorID;
    }

    CarryStep getCarryStep() const
    {
        return mCarryStep;
    }

    // ------------------------------------ PlayerObjectYoshi.cpp ------------------------------------ //

    // Address: 0x0295A7E4
    virtual bool vfAE4();

    // ------------------------------------ PlayerObjectHang.cpp ------------------------------------ //

    // Address: 0x0293DF70
    virtual bool isPlayerHang(PlayerObject* p_player_obj_parent);

    // ------------------------------------ PlayerObjectFukidashi.cpp ------------------------------------ //

    // Address: 0x0293D6AC
    virtual bool isDrawingCarryFukidashi();

    // Address: 0x0293D754
    virtual bool isEnableChibiYoshiFukidashi();

    // ------------------------------------ PlayerObjectStaff.cpp ------------------------------------ //

    // Address: 0x02950B50
    virtual bool updateEndingDanceImpl();

    // ------------------------------------ PlayerObjectRuiji.cpp ------------------------------------ //

    // Address: 0x0294A0D4
    virtual void onChangeRDashPhysics();

    // Address: 0x0294A130
    bool isEnableRDashLuigiPhysics() const override;
    // Address: 0x0294A168
    virtual bool isEnableRDashLuigiGravity();

    // ------------------------------------ Uncategorized ------------------------------------ //

    // StateID_Balloon          Address: 0x1022B18C
    // initializeState_Balloon  Address: 0x029265C0
    // executeState_Balloon     Address: 0x02926AA0
    // finalizeState_Balloon    Address: 0x02926EF4
    DECLARE_STATE_ID(PlayerObject, Balloon)

    bool isBalloon() const
    {
        return *mStateMgr.getStateID() == StateID_Balloon;
    }

    static s32 getParamPlayerNo(u32 param_0)
    {
        return param_0 & 0xF;
    }

    static PlayerMode getParamPlayerMode(u32 param_0)
    {
        return PlayerMode(param_0 >> 4 & 0xF);
    }

    static PlayerCharacter getParamPlayerCharacter(u32 param_0)
    {
        return PlayerCharacter(param_0 >> 8 & 0xF);
    }

    static PlayerModelBase::Type getParamPlayerModelType(u32 param_0)
    {
        switch (getParamPlayerCharacter(param_0))
        {
        case cPlayerCharacter_Mario:
        default:
            return PlayerModelBase::cType_Mario;
        case cPlayerCharacter_Luigi:
            return PlayerModelBase::cType_Luigi;
        case cPlayerCharacter_YellowToad:
            return PlayerModelBase::cType_YellowToad;
        case cPlayerCharacter_BlueToad:
            return PlayerModelBase::cType_BlueToad;
        case cPlayerCharacter_Nabbit:
            return PlayerModelBase::cType_Nabbit;
        case cPlayerCharacter_Mii:
            return PlayerModelBase::cType_Mii;
        }
    }

    static DirType getParamPlayerFacingDir(u32 param_0)
    {
        return DirType(param_0 >> 24 & 0xF);
    }

protected:
    PlayerModelMgr                  mModelMgr;
    ActorBgCollisionCheck::Sensor   _2760;
    PlayerMode                      mModePrev;                      // Maybe?
    PlayerMode                      mModeNext;                      // ^^^
    sead::Vector2f                  _2774;
    s32                             mStarTimer;
    s32                             mStarCnt;
    ActorUniqueID                   mCarryActorID;
    CarryStep                       mCarryStep;
    CarryStep                       mCarryStepPrev;
    f32                             mCarryStepTimer;
    f32                             mCarryStepLength;
    sead::SafeArray<s32, 3>         _2798;
    sead::SafeArray<s32, 3>         _27a4;
    f32                             _27b0[2];
    f32                             _27b8[2];
    sead::Vector3f                  _27c0;
    u32                             _27cc;
    u32                             mScrollMode;
    PropelParts                     mPropelParts;
    Light                           mLight;
    s32                             _2998;
    s32                             _299c;
    u8                              _29a0;
    EventPlayerChange*              mpEventPlayerChange;
    ChangeMgr                       mChangeMgr;
    f32                             _29d0;
    u8                              _29d4;
    EventDie*                       mpEventDie;
    u8                              _29dc;
    bool                            mPlayerEatDieNow;
    sead::Vector3f                  _29e0;
    f32                             mEffectScale;
    DokanCannonType                 mDokanCannonType;
    sead::Vector2f                  mDemoInBossMoveTarget;
    u32                             mPMusaTransformStep;
    DirType                         _2a00;
    bool                            _2a04;
    u32                             _2a08;
    u32                             _2a0c;
    u32                             _2a10;
    u8                              _2a14;
    u32                             mWhichJump;
    u32                             _2a1c;
    u32                             _2a20;
    u32                             _2a24;
    u32                             _2a28;
    Angle                           mSpinRotStep;
    Angle                           mMissSpinAngle;
    u32                             _2a34;
    u32                             _2a38;
    f32                             _2a3c;
    u32                             _2a40;
    u32                             _2a44;
    f32                             _2a48;
    DirType                         mWallSlideDir;
    ActorUniqueID                   mLiftUpActorID;
    f32                             _2a54;
    f32                             _2a58;
    u32                             _2a5c;
    s32                             _2a60;
    f32                             _2a64;
    u8                              _2a68;
    s32                             _2a6c;
    s32                             _2a70;
    u32                             _2a74;
    s32                             _2a78;
    u8                              _2a7c;
    u32                             _2a80;
    u32                             _2a84;
    u32                             _2a88;
    s32                             _2a8c;
    u32                             mBalloonControllerConnectStatus;
    u32                             _2a94;
    sead::Vector3f                  _2a98;
    u32                             mCannonType;
    u32                             _2aa8;
    sead::Vector3f                  _2aac;
    f32                             _2ab8;
    f32                             _2abc;
    u32                             _2ac0;
    Angle                           _2ac4;
    u32                             _2ac8;
    s32                             _2acc;
    EffectObj                       _2ad0;
    u32                             _2b38;
    sead::Vector2f                  _2b3c;
    u8                              _2b44;
    u32                             _2b48;
    u32                             _2b4c;
    u32                             _2b50;
    u32                             _2b54;
    u32                             _2b58;
    f32                             _2b5c;
    sead::Vector2f                  _2b60;
    u32                             _2b68;
    f32                             _2b6c;
    f32                             _2b70;
    u32                             _2b74;
    u32                             _2b78;
    u8                              mPropelActionSubTimer;
    bool                            mPropelFlyTime;
    u32                             _2b80;
    s32                             _2b84;
    EffectObj                       mPropelFallSpinEffect;
    EffectObj                       _2bf0;
    Angle                           _2c58;
    EffectObj                       mSpinHipAttackEffect;
    u32                             _2cc4;
    u32                             _2cc8;
    ActorUniqueID                   mPlyIceActorID;
    QuakeMode                       mQuakeMode;
    s32                             mQuakeRumbleTimer;
    f32                             _2cd8;
    bool                            _2cdc;
    s32                             _2ce0;
    s32                             _2ce4;
    sead::BitFlag16                 mPenguinSwimFlag;
    u32                             mTarzanRopeBgType;              // 0 = ivy, 1 = kusari, 2 = rope(?)
    f32                             _2cf0;
    u32                             _2cf4;
    u32                             _2cf8;
    u32                             _2cfc;
    Angle                           mRopeAngleNow;
    Angle                           mRopeAngleDiffNow;
    Angle                           mRopeAngleOld;
    Angle                           mRopeAngleDiffOld;
    u32                             _2d10;
    f32                             mMameWallWalkSpeed;
    sead::Vector2f                  _2d18;
    u32                             _2d20;
    u32                             _2d24;
    u32                             _2d28;
    f32                             mKaniPosY;
    bool                            _2d30;
    u32                             mMusaJumpStep;
    f32                             _2d38;
    f32                             _2d3c;
    Angle                           _2d40;
    Angle                           _2d44;
    bool                            mMusaStartWallSlide;
    bool                            mMusaCanDoJump;
    u8                              _2d4a;
    u32                             _2d4c;
    u32                             _2d50;
    u32                             mMusaFlyStep;
    PlayerEatData                   mEatData;
    sead::Vector2f                  mEatPosOffset;
    bool                            _2d84;
    sead::Vector2f                  mEatPosReserve;
    DirType                         _2d90;
    ActorUniqueID                   mPlayerHangChildActorID;
    ActorUniqueID                   mPlayerHangParentActorID;
    u32                             _2d9c;
    sead::Matrix34f                 mJrCrownMtx;
    u32                             _2dd0;
    u32                             mQuakeTimer;
    bool                            mQuakeEffectFlag;
    Effect                          mItemGetEffect1;
    Effect                          mItemGetEffect2;
    Effect                          mPowerUpEffect;
    EffectObj                       mSwimEffect;
    EffectObj                       mPaddleSwimEffectL;
    EffectObj                       mPaddleSwimEffectR;
    EffectObj                       _2fd4;
    EffectObj                       _303c;
    Effect                          mSpinJumpEffect;
    Effect                          mMissSpinJumpEffect;
    EffectObj                       _3124;
    EffectObj                       mMusaFlyEffect;
    s32                             mMusaFlyUpEffectIndex;
    sead::SafeArray<EffectObj, 2>   mMusaFlyUpEffectDoubleBuffer;
    u32                             mStarEffectStep;                // 0 = Idle, 1 = Active, 2 = Fading
    EffectObj                       mStarEffect;
    u32                             mPMusaEffectStep;               // ^^^
    EffectObj                       mPMusaEffect;
    u32                             mPMusaFlyEffectStep;            // ^^^
    EffectObj                       mPMusaFlyEffect;
    u32                             _340c;
    u32                             _3410;
    EffectObj                       _3414;
    PlyOrchestra                    mOrchestra;
    s32                             _3490;                          // Ending Dance related
    s32                             _3494;                          // ^^^
    sead::SafeArray<s32, 3>         _3498;                          // ^^^
    sead::BitFlag8                  _34a4;                          // ^^^
    s32                             mIdleCounter;                   // ^^^
    u32                             _34ac;                          // ^^^
    sead::SafeArray<s32, 5>         _34b0;                          // ^^^
    bool                            _34c4;                          // ^^^
    bool                            _34c5;                          // ^^^
    f32                             mJumpAnmRate;
    f32                             mJumpTimerF;
    s32                             mJumpAnmID;
    s32                             _34d4;                          // Some random timer
};
static_assert(sizeof(PlayerObject) == 0x34D8);
