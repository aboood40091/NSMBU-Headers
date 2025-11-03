#pragma once

#include <actor/ActorState.h>
#include <audio/GameAudio.h>
#include <enemy/Combo.h>
#include <enemy/EnemyChibiYoshiAwaData.h>
#include <enemy/EnemyDeathInfo.h>
#include <enemy/IceMgr.h>
#include <state/FStateVirtualID.h>

class ActorCollisionCheck;

class Enemy : public ActorMultiState    // vtbl Address: 0x1007209C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9EEC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9EF0
    SEAD_RTTI_OVERRIDE(Enemy, ActorMultiState)

public:
    // Address: 0x1007206C
    static const f32 cFumiJumpSpeed;
    // Address: 0x10072070
    static const f32 cDefaultAccelY;
    // Address: 0x10072078
    static const f32 cDefaultYSpeedMax;

    // Address: 0x10200DD8
    static const Angle cBaseAngleY[cDirType_NumX];
    // Address: 0x10072094
    static const s8 cDirSign[cDirType_NumX];    // Actual name unknown

    static const s32 cNoHitPlayerTimerDefault = 5;

public:
    enum FumiType
    {
        cFumiType_Hit = 0,
        cFumiType_Fumi,
        cFumiType_MameFumi,
        cFumiType_SpinFumi
    };

    enum FumiSeType
    {
        cFumiSeType_Normal = 0,
        cFumiSeType_Step
    };

public:
    // Address: 0x02328494
    Enemy(const ActorCreateParam& param);
    virtual ~Enemy() { }

protected:
    // Address: 0x02328644
    bool preExecute_() override;

    // Address: 0x02328914
    void blockHitInit_() override;

    // Address: 0x0232DC88
    void setSmokeDamage_(Actor*) override;
    // Address: 0x0232E1A4
    bool setTouchDrcDamage_(const sead::Vector2f& pos) override;

public:
    // Address: 0x02330404
    void changeState(const StateID& state_id) override;

    virtual bool vf18C() // is not carryable?
    {
        return false;
    }

    // Address: 0x02328B84
    virtual bool setDamage(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232910C
    virtual bool checkComboClap(s32 combo_cnt);

    // Address: 0x023304F8
    virtual bool createIceActor();
    // Address: 0x023310BC
    virtual void setIceAnm();
    // Address: 0x023310C0
    virtual void returnAnm_Ice();
    // Address: 0x02330568
    virtual void returnState_Ice();
    // Address: 0x0232A858
    virtual void calcMdl_Ice();

    // Address: 0x0232A85C
    virtual bool vf1CC(); // Maybe related to the below?

    // Address: 0x023291F8
    virtual bool enemyDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329250
    virtual bool playerDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329520
    virtual bool enemyPreDamageCheck(bool* p_dead, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329578
    virtual bool hitYoshiEat(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232957C
    virtual bool yoshiDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x023296E8
    virtual bool chibiYoshiDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329800
    virtual bool etcDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x023299F0
    virtual void vsEnemyHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x023299F4
    virtual void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329A04
    virtual void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329A08
    virtual void vsChibiYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232CE84
    virtual bool hitCallback_Star(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232CF20
    virtual bool hitCallback_Slip(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D014
    virtual bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D0E4
    virtual bool hitCallback_WireNet(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D240
    virtual bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D3B4
    virtual bool hitCallback_YoshiHipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D48C
    virtual bool hitCallback_PenguinSlide(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D49C
    virtual bool hitCallback_Cannon(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D56C
    virtual bool hitCallback_AttackUnk25(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // Player slip 2
    // Address: 0x0232D57C
    virtual bool hitCallback_Shell(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D70C
    virtual bool hitCallback_Fire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D7A4
    virtual bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D824
    virtual bool hitCallback_YoshiBullet(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D938
    virtual bool hitCallback_YoshiFire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232DA04
    virtual bool hitCallback_ChibiYoshiBubble(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // I think
    // Address: 0x0232DA0C
    virtual bool hitCallback_ChibiYoshiLight(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232DA14
    virtual bool hitCallback_ChibiYoshiStar(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232DA24
    virtual bool hitCallback_AttackUnk27(bool* p_dead, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232DAF0
    virtual void setDeathInfo_Quake(s32);
    // Address: 0x0232DD48
    virtual void setDeathInfo_IceBreak();
    // Address: 0x0232E048
    virtual bool setDeathInfo_Star(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232E2EC
    virtual bool isQuakeDamage();   // Return if enemy is on ground && damageable by quake

    // Address: 0x0232E2F8
    virtual void setDeathSound_Fire();
    // Address: 0x0232E358
    virtual void setDeathSound_HipAttk();

    // Address: 0x02329EA4
    virtual void fumiJumpSet(Actor*);
    // Address: 0x02329FA8
    virtual void fumiScoreSet(Actor*);

    // Address: 0x02329FAC
    virtual void yoshiFumiJumpSet(Actor*);
    // Address: 0x02329FB0
    virtual void yoshiFumiScoreSet(Actor*);

    // Address: 0x02329FC0
    virtual void mameFumiJumpSet(Actor*);

    // Address: 0x0232A094
    virtual void fumiSE(Actor*);
    // Address: 0x0232A118
    virtual void fumiEffect(Actor*);

    // Address: 0x0232A1BC
    virtual void spinfumiSE(Actor*);
    // Address: 0x02329B20
    void spinfumiEffect(Actor*);    // No longer virtual...

    // Address: 0x0232A240
    virtual void mamefumiSE();
    // Address: 0x0232A24C
    virtual void mamefumiEffect(Actor*);

    // Address: 0x0232A250
    virtual void yoshifumiSE(Actor*);
    // void yoshifumiEffect(Actor*);    // Deleted from NSMBU

    // Address: 0x0232A2D4
    virtual void hipatkEffect(const sead::Vector3f& effect_pos);

    // Address: 0x0232A2E4
    virtual void vf34C(); // Adds 2.0f to y speed

    // Address: 0x0232A2FC
    virtual bool checkDispIn(); // Checks if enemy is inside the camera view

    // Address: 0x0232A364
    virtual void vf35C(Actor*); // Callback for ChibiYoshiAwaData
    // Address: 0x0232A418
    virtual void vf364(Actor*); // ^^^
    // Address: 0x0232A4CC
    virtual void vf36C(Actor*); // ^^^
    // Address: 0x0232A864
    virtual void vf374(Actor*); // ^^^

    // ------------------------------------ EnemyDeath.cpp ------------------------------------ //

    // StateID_DieFumi          Address: 0x10200FB0
    // initializeState_DieFumi  Address: 0x0232E518
    // executeState_DieFumi     Address: 0x0232E5E8
    // finalizeState_DieFumi    Address: 0x0232EED0
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieFumi)
    // StateID_DieFall          Address: 0x10200FD4
    // initializeState_DieFall  Address: 0x0232E63C
    // executeState_DieFall     Address: 0x0232E640
    // finalizeState_DieFall    Address: 0x0232EED4
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieFall)
    // StateID_DieYoshiFumi         Address: 0x10200FF8
    // initializeState_DieYoshiFumi Address: 0x0232E72C
    // executeState_DieYoshiFumi    Address: 0x0232E79C
    // finalizeState_DieYoshiFumi   Address: 0x0232EED8
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieYoshiFumi)
    // StateID_DieSmoke         Address: 0x1020101C
    // initializeState_DieSmoke Address: 0x0232E7A8
    // executeState_DieSmoke    Address: 0x0232E7B8
    // finalizeState_DieSmoke   Address: 0x0232EEDC
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieSmoke)
    // StateID_DieIceVanish         Address: 0x10201040
    // initializeState_DieIceVanish Address: 0x0232E7C4
    // executeState_DieIceVanish    Address: 0x0232E7C8
    // finalizeState_DieIceVanish   Address: 0x0232EEE0
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieIceVanish)
    // StateID_DieOther         Address: 0x10201064
    // initializeState_DieOther Address: 0x0232E7D4
    // executeState_DieOther    Address: 0x0232EEE4
    // finalizeState_DieOther   Address: 0x0232EEE8
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieOther)
    // StateID_DieUnk2          Address: 0x10201088
    // initializeState_DieUnk2  Address: 0x0232E7E0
    // executeState_DieUnk2     Address: 0x0232EEEC
    // finalizeState_DieUnk2    Address: 0x0232EEF0
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieUnk2)

    // ------------------------------------ EnemyState.cpp ------------------------------------ //

    // StateID_EatIn            Address: 0x1020111C
    // initializeState_EatIn    Address: 0x023305E4
    // executeState_EatIn       Address: 0x023305EC
    // finalizeState_EatIn      Address: 0x023310C4
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, EatIn)
    // StateID_EatNow           Address: 0x10201140
    // initializeState_EatNow   Address: 0x023310C8
    // executeState_EatNow      Address: 0x023310CC
    // finalizeState_EatNow     Address: 0x023310D0
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, EatNow)
    // StateID_EatOut           Address: 0x10201164
    // initializeState_EatOut   Address: 0x023310D4
    // executeState_EatOut      Address: 0x023310D8
    // finalizeState_EatOut     Address: 0x023310DC
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, EatOut)
    // StateID_ChibiEatIn           Address: 0x10201188
    // initializeState_ChibiEatIn   Address: 0x023306E8
    // executeState_ChibiEatIn      Address: 0x023306F0
    // finalizeState_ChibiEatIn     Address: 0x023310E0
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, ChibiEatIn)
    // StateID_ChibiEatNow          Address: 0x102011AC
    // initializeState_ChibiEatNow  Address: 0x023310E4
    // executeState_ChibiEatNow     Address: 0x023310E8
    // finalizeState_ChibiEatNow    Address: 0x023310EC
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, ChibiEatNow)
    // StateID_ChibiEatOut          Address: 0x102011D0
    // initializeState_ChibiEatOut  Address: 0x023310F0
    // executeState_ChibiEatOut     Address: 0x023310F4
    // finalizeState_ChibiEatOut    Address: 0x023310F8
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, ChibiEatOut)
    // StateID_EnemyUnk1            Address: 0x102011F4
    // initializeState_EnemyUnk1    Address: 0x023310FC
    // executeState_EnemyUnk1       Address: 0x02331100
    // finalizeState_EnemyUnk1      Address: 0x02331104
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, EnemyUnk1)
    // StateID_Ice          Address: 0x10201218
    // initializeState_Ice  Address: 0x02330720
    // executeState_Ice     Address: 0x023307A0
    // finalizeState_Ice    Address: 0x02330944
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, Ice)

    // ---------------------------------------------------------------------------------------- //

    // Address: 0x02328C24
    static bool ceilCheck(f32 pos_y, ActorCollisionCheck* p_cc);

    // Address: 0x02328C50
    static void normal_collcheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    static void fireballInvalid(ActorCollisionCheck* cc_other)  // Inline in NSMBU, but not NSMBW
    {
        GameAudio::getAudioObjMap()->startSound("SE_OBJ_FIREBALL_DISAPP", cc_other->getOwner()->getPos());
    }

    // Address: 0x02329A0C
    static void iceballInvalid(ActorCollisionCheck* cc_other);

    // Address: 0x0232CBA4
    void setDeathInfo_Fall(u8 direction, s8 player_no = -1, ScoreMgr::ScoreType score_type = ScoreMgr::cScoreType_Invalid);
    // Address: 0x0232CB08
    void setDeathInfo_Fall(const sead::Vector2f* speeds, u8 direction, s8 player_no = -1, ScoreMgr::ScoreType score_type = ScoreMgr::cScoreType_Invalid);
    // Address: 0x0232DA34
    void setDeathInfo_Fumi(Actor*, sead::Vector2f speed, const StateID& state_id);
    // Address: 0x0232CC98
    void setDeathInfo_SpinFumi(Actor*);
    // Address: 0x0232D31C
    void setDeathInfo_YoshiFumi(Actor*);

    // Address: 0x02329AA8
    void startSound(const char* name);

    // Address: 0x02329B88
    FumiType fumiCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other, FumiSeType se_type);

    // Address: 0x02329130
    s32 calcComboPlFumiCnt(Actor* p_player);

    // Address: 0x02329168
    void bound(f32, f32, f32);

    // Address: 0x0232CAEC
    bool isDead() const;

    // Address: 0x023288BC
    void hitdamageEffect(const sead::Vector3f& effect_pos);

    // Address: 0x0232E144
    Angle applyWaterRollDec(Angle ang);

    void killIce()
    {
        mIceMgr.removeIce();
    }

    void fumistepSE(Actor*)
    {
        startSound("SE_EMY_CMN_STEP");
    }

    void yoshifumistepSE(Actor*)
    {
        startSound("SE_EMY_YOSHI_STEP");
    }

    void spinFumiJumpSet(Actor* p_actor)
    {
        fumiJumpSet(p_actor);
    }

    // Address: 0x02329B6C
    void spinFumiScoreSet(Actor*);

protected:
    EnemyDeathInfo          mDeathInfo;
    sead::SafeArray<
        u16,
        4
    >                       mNoHitPlayerTimer;              // TODO: This is actually a class ("EnemyCounter"?)
    sead::BitFlag32         _17ec;                          // Bit 24: Collide with player even if above screen
    IceMgr                  mIceMgr;
    EnemyChibiYoshiAwaData  mChibiYoshiAwaData;

    // TODO: EnemyFumiProc
    Enemy*                  _1860;
    void*                   _1864;
    u8                      _1868;

    u16                     _186c;
    u16                     _186e;
    u32                     _1870;
    u8                      mDieFallDirection;
    u8                      mPreIceDirection;               // Maybe?
    Combo                   mCombo;
    u8                      _187c;
    u8                      _187d;
    s8                      _187e;
};
static_assert(sizeof(Enemy) == 0x1880);
