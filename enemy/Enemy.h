#pragma once

#include <actor/ActorState.h>
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
    // Address: 0x10200DD8
    static const Angle cBaseAngleY[DIRECTION_NUM_X];

public:
    enum FumiType
    {
        cFumiType_Hit = 0,
        cFumiType_Fumi,
        cFumiType_MameFumi,
        cFumiType_SpinFumi
    };

public:
    // Address: 0x02328494
    Enemy(const ActorCreateParam& param);
    virtual ~Enemy() { }

protected:
    // Address: 0x02328644
    s32 preExecute_() override;

public:
    // Address: 0x02328914
    void blockHitInit() override;
    // Address: 0x0232DC88
    void vf14C(Actor*) override;
    // Address: 0x0232E1A4
    bool vf154(const sead::Vector2f&) override;
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
    virtual void calcMdl();

    // Address: 0x0232A85C
    virtual bool vf1CC(); // Maybe related to the below?

    // Address: 0x023291F8
    virtual bool enemyDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329250
    virtual bool playerDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329520
    virtual bool vf1E4(bool*, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329578
    virtual bool vf1EC(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
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
    virtual void vsChibiYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // I think

    // Address: 0x0232CE84
    virtual bool hitCallback_Star(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232CF20
    virtual bool hitCallback_Slip(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D014
    virtual bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D0E4
    virtual bool hitCallback_WireNet(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // I think
    // Address: 0x0232D240
    virtual bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D3B4
    virtual bool hitCallback_YoshiHipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D48C
    virtual bool hitCallback_PenguinSlide(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D49C
    virtual bool hitCallback_Cannon(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232D56C
    virtual bool vf26C(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // Player slip 2
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
    virtual bool hitCallback_ChibiYoshiGlow(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // I think
    // Address: 0x0232DA14
    virtual bool hitCallback_ChibiYoshiStar(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232DA24
    virtual bool vf2B4(bool*, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232DAF0
    virtual void setDeathInfo_Quake(s32);
    // Address: 0x0232DD48
    virtual void setDeathInfo_IceBreak();
    // Address: 0x0232E048
    virtual bool setDeathInfo_Star(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232E2EC
    virtual bool isOnGround();

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

    // Address: 0x0232A240
    virtual void mamefumiSE(Actor*);
    // Address: 0x0232A24C
    virtual void mamefumiEffect(Actor*);

    // Address: 0x0232A250
    virtual void yoshifumiSE(Actor*);
    // Address: 0x0232A2D4
    virtual void yoshifumiEffect(Actor*); // or spinfumiEffect, unclear which one

    // Address: 0x0232A2E4
    virtual void vf34C(); // Adds 2.0f to y speed

    // Address: 0x0232A2FC
    virtual bool areaXYCheck(); // Checks if enemy is inside the camera view

    // Address: 0x0232A364
    virtual void vf35C(Actor*);
    // Address: 0x0232A418
    virtual void vf364(Actor*);
    // Address: 0x0232A4CC
    virtual void vf36C(Actor*);
    // Address: 0x0232A864
    virtual void vf374();

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
    // StateID_DieSmoke         Address: 0x10200FF8
    // initializeState_DieSmoke Address: 0x0232E72C
    // executeState_DieSmoke    Address: 0x0232E79C
    // finalizeState_DieSmoke   Address: 0x0232EED8
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieSmoke)
    // StateID_DieYoshiFumi         Address: 0x1020101C
    // initializeState_DieYoshiFumi Address: 0x0232E7A8
    // executeState_DieYoshiFumi    Address: 0x0232E7B8
    // finalizeState_DieYoshiFumi   Address: 0x0232EEDC
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieYoshiFumi)
    // StateID_DieIceVanish         Address: 0x10201040
    // initializeState_DieIceVanish Address: 0x0232E7C4
    // executeState_DieIceVanish    Address: 0x0232E7C8
    // finalizeState_DieIceVanish   Address: 0x0232EEE0
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieIceVanish)
    // StateID_DieGoal          Address: 0x10201064
    // initializeState_DieGoal  Address: 0x0232E7D4
    // executeState_DieGoal     Address: 0x0232EEE4
    // finalizeState_DieGoal    Address: 0x0232EEE8
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieGoal)
    // StateID_DieOther         Address: 0x10201088
    // initializeState_DieOther Address: 0x0232E7E0
    // executeState_DieOther    Address: 0x0232EEEC
    // finalizeState_DieOther   Address: 0x0232EEF0
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieOther)

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
    // StateID_HitSpin          Address: 0x102011F4
    // initializeState_HitSpin  Address: 0x023310FC
    // executeState_HitSpin     Address: 0x02331100
    // finalizeState_HitSpin    Address: 0x02331104
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, HitSpin)
    // StateID_Ice          Address: 0x10201218
    // initializeState_Ice  Address: 0x02330720
    // executeState_Ice     Address: 0x023307A0
    // finalizeState_Ice    Address: 0x02330944
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, Ice)

    // ---------------------------------------------------------------------------------------- //

    // Address: 0x02328C50
    static void normal_collcheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x02329A0C
    static void iceballInvalid(ActorCollisionCheck* cc_other);

    // Address: 0x0232CBA4
    void setDeathInfo_Fall(u8 direction, s8 player_no, s8 score_lyt_type);
    // Address: 0x0232CB08
    void setDeathInfo_Fall(const sead::Vector2f* speeds, u8 direction, s8 player_no, s8 score_lyt_type);
    // Address: 0x0232DA34
    void setDeathInfo_Fumi(Actor*, sead::Vector2f speed, const StateID& state_id);
    // Address: 0x0232CC98
    void setDeathInfo_SpinFumi(Actor*);
    // Address: 0x0232D31C
    void setDeathInfo_YoshiFumi(Actor*);

    // Address: 0x02329AA8
    void startSound(const char* name);

    // Address: 0x02329B88
    FumiType fumiCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other, s32);

    // Address: 0x02329168
    void bound(f32, f32, f32);

    // Address: 0x0232CAEC
    bool isNoRespawn() const;

protected:
    EnemyDeathInfo  mDeathInfo;
    u16             _17e4[4];
    u32             _17e8;
    IceMgr          mIceMgr;
    u32             mChibiBubbleData[0x20 / sizeof(u32)];   // TODO: ChibiBubbleData

    // This part is a struct
    Enemy*          _1860;
    void*           _1864;
    u8              _1868;

    u16             _186c;
    u16             _186e;
    u32             _1870;
    u8              mDieFallDirection;
    u8              _1875;
    u32             _1878;
    u8              _187c;
    u8              _187d;
    u8              _187e;
};
static_assert(sizeof(Enemy) == 0x1880);
