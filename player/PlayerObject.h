#pragma once

#include <map/CarryType.h>
#include <player/PlayerBase.h>
#include <player/PlayerModelMgr.h>

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

protected:
    PlayerModelMgr  mModelMgr;
    u32             _2760[(0x2784 - 0x2760) / sizeof(u32)];
    ActorUniqueID   mCarryActorID;
    CarryStep       mCarryStep;
    CarryStep       mCarryStepPrev;
    f32             mCarryStepTimer;
    f32             mCarryStepLength;
    u32             _2798[(0x2AC8 - 0x2798) / sizeof(u32)];
    u32             _2ac8;
    u32             _2acc;
    u32             _2ad0[(0x34CC - 0x2AD0) / sizeof(u32)];
    f32             mJumpTimerF;
    s32             mJumpAnmID;
    s32             _34d4;  // Some random timer
};
static_assert(sizeof(PlayerObject) == 0x34D8);
