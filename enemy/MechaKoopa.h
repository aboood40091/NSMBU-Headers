#pragma once

#include <actor/Profile.h>
#include <collision/ActorCollisionDrcTouchCallback.h>
#include <enemy/CarryEnemy.h>
#include <enemy/EnemyActorScaler.h>

class MechaKoopaDrcTouchCB : public ActorCollisionDrcTouchCallback  // vtbl Address: 0x100945D4
{
public:
    // Address: 0x023E8F9C
    bool ccSetTouchNormal(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
    // Address: 0x023E8FA4
    void ccOnTouch(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
};
static_assert(sizeof(MechaKoopaDrcTouchCB) == sizeof(ActorCollisionDrcTouchCallback));

class AnimModel;
class ModelResource;

class MechaKoopa : public CarryEnemy    // vtbl Address: 0x10094064
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EAB30
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EAB34
    SEAD_RTTI_OVERRIDE(MechaKoopa, CarryEnemy)

public:
    // Address: 0x10093DD4
    static const ActorCreateInfo cActorCreateInfo;

public:
    // Address: 0x023E8A00
    MechaKoopa(const ActorCreateParam& param);

protected:
    // Address: 0x023E92E0
    Result create_() override;
    // Address: 0x023E95CC
    bool execute_() override;
    // Address: 0x023E9768
    bool draw_() override;

    // Address: 0x023EA184
    void blockHitInit_() override;

public:
    // Address: 0x023EB8C8
    bool isSpinLiftUpEnable() override;
    // Address: 0x023EA364
    void waterSplashEffect(const sead::Vector3f&) override;
    // Address: 0x023EA378
    void yoganSplashEffect(const sead::Vector3f&) override;
    // Address: 0x023EA38C
    void poisonSplashEffect(const sead::Vector3f&) override;

    // Address: 0x023EA3A0
    bool vf18C() override;
    // Address: 0x023EA058
    bool createIceActor() override;
    // Address: 0x023EA104
    void setIceAnm() override;
    // Address: 0x023EBAF4
    void calcMdl_Ice() override;
    // Address: 0x023E9E90
    bool etcDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023E99FC
    void vsEnemyHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023E9DD4
    bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023E9B8C
    bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023E9D6C
    bool hitCallback_Fire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // StateID_DieFall          Address: 0x10204D70
    // initializeState_DieFall  Address: 0x023EAEF0
    // executeState_DieFall     Address: 0x023EAF28
    // finalizeState_DieFall    Address: 0x023EAF64
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(MechaKoopa, DieFall)

    // Address: 0x023E979C
    void reactFumiProc(Actor*) override;
    // Address: 0x023E98C4
    void reactSpinFumiProc(Actor*) override;
    // Address: 0x023E98D4
    void playerHitCheck_Awake(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023E9990
    void playerHitCheck_Sleep(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023EA000
    void playerHitCheck_Sleep_Base(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023EA4B0
    void setPutOnChangeState(Actor* p_player) override;
    // Address: 0x023EA4C8
    void setThrowChangeState(Actor* p_player, bool hard) override;

    // StateID_Carry            Address: 0x10204D4C
    // initializeState_Carry    Address: 0x023EA834
    // executeState_Carry       Address: 0x023EA8A0
    // finalizeState_Carry      Address: 0x023EA99C
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(MechaKoopa, Carry)
    // StateID_Sleep            Address: 0x10204D28
    // initializeState_Sleep    Address: 0x023EA78C
    // executeState_Sleep       Address: 0x023EA7B4
    // finalizeState_Sleep      Address: 0x023EA824
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(MechaKoopa, Sleep)

    // StateID_Walk         Address: 0x10204C94
    // initializeState_Walk Address: 0x023EA4E0
    // executeState_Walk    Address: 0x023EA56C
    // finalizeState_Walk   Address: 0x023EBAF8
    DECLARE_STATE_ID(MechaKoopa, Walk)
    // StateID_Turn         Address: 0x10204CB4
    // initializeState_Turn Address: 0x023EA6C8
    // executeState_Turn    Address: 0x023EA6E4
    // finalizeState_Turn   Address: 0x023EBAFC
    DECLARE_STATE_ID(MechaKoopa, Turn)
    // StateID_Kick         Address: 0x10204CD4
    // initializeState_Kick Address: 0x023EA9DC
    // executeState_Kick    Address: 0x023EAC0C
    // finalizeState_Kick   Address: 0x023EAD6C
    DECLARE_STATE_ID(MechaKoopa, Kick)
    // StateID_Recover          Address: 0x10204CF4
    // initializeState_Recover  Address: 0x023EADC4
    // executeState_Recover     Address: 0x023EAE54
    // finalizeState_Recover    Address: 0x023EAEE0
    DECLARE_STATE_ID(MechaKoopa, Recover)

protected:
    ModelResource*          mpModelResource;
    AnimModel*              mpAnimModel;
    u32                     mNextTurnTimer;
    u32                     mDownTimer;
    u32                     mCurrentAnim;
    u8                      _18cc;
    u8                      _18cd;
    MechaKoopaDrcTouchCB    mDrcTouchCallback;
    EnemyActorScaler        mScaler;
    f32                     _18f4;
};
static_assert(sizeof(MechaKoopa) == 0x18F8);
