#pragma once

#include <actor/ActorState.h>
#include <audio/GameAudio.h>
#include <enemy/Combo.h>
#include <enemy/EnemyChibiYoshiAwaData.h>
#include <enemy/EnemyDeathInfo.h>
#include <enemy/IceMgr.h>
#include <player/PlayerEnum.h>
#include <state/FStateVirtualID.h>

#define ENEMY_DIE_FALL_INIT_SPEED_X     (1.5f)
#define ENEMY_DIE_FALL_INIT_SPEED_Y     (3.9f)
#define ENEMY_DIE_FALL_BOUND_SPEED_Y    (3.0f)

#define ENEMY_FUMI_JUMP_SPEED           (0.2815f)

// TODO: Move to own header
class Enemy;

class FumiCcInfo
{
public:
    FumiCcInfo(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other)
        : mpCcSelf(cc_self)
        , mpCcOther(cc_other)
    {
    }

    // Address: 0x023311B4
    f32 getFumiRev();

private:
    ActorCollisionCheck*    mpCcSelf;
    ActorCollisionCheck*    mpCcOther;
};

class UniqueFumiCheckInf
{
public:
    virtual bool operate(bool&, Enemy*, FumiCcInfo&) = 0;
};
static_assert(sizeof(UniqueFumiCheckInf) == 4);

class EnemyFumiCheck
{
public:
    EnemyFumiCheck(Enemy* p_enemy, UniqueFumiCheckInf* p_fumi_check_inf)
        : mpEnemy(p_enemy)
        , mpFumiCheckInf(p_fumi_check_inf)
        , mFumiRevType(0)
    {
    }

    void setFumiRevType(u8 type)
    {
        mFumiRevType = type;
    }

private:
    Enemy*              mpEnemy;
    UniqueFumiCheckInf* mpFumiCheckInf;
    u8                  mFumiRevType;
};
static_assert(sizeof(EnemyFumiCheck) == 0xC);

enum FumiType
{
    cFumiType_Hit = 0,
    cFumiType_Fumi,
    cFumiType_MameFumi,
    cFumiType_SpinFumi
};

class EnemyFumiProc
{
public:
    EnemyFumiProc(Enemy* p_enemy, UniqueFumiCheckInf* p_fumi_check_inf)
        : mFumiCheck(p_enemy, p_fumi_check_inf)
    {
    }

    void setFumiRevType(u8 type)
    {
        mFumiCheck.setFumiRevType(type);
    }

    // Address: 0x0232F818
    FumiType operate(FumiCcInfo& info);

    FumiType operate(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other)
    {
        FumiCcInfo info(cc_self, cc_other);
        return operate(info);
    }

private:
    EnemyFumiCheck  mFumiCheck;
};
static_assert(sizeof(EnemyFumiProc) == 0xC);

class NonUniqueFumiCheck : public UniqueFumiCheckInf
{
    static NonUniqueFumiCheck sInstance;

public:
    static UniqueFumiCheckInf* instance() { return &sInstance; }

public:
    bool operate(bool&, Enemy*, FumiCcInfo&) override;
};
static_assert(sizeof(NonUniqueFumiCheck) == sizeof(UniqueFumiCheckInf));

class EnemyCounter
{
public:
    EnemyCounter()
    {
        mTime.fill(0);
    }

    // Address: 0x0232B188
    void update();

    void reset(s32 player_no, u16 initial_time)
    {
        mTime[player_no] = initial_time;
    }

    u16 getTime(s32 player_no) const
    {
        return mTime[player_no];
    }

    bool isOver(s32 player_no) const
    {
        return getTime(player_no) == 0;
    }

private:
    sead::SafeArray<u16, cPlayerNum>    mTime;
};
static_assert(sizeof(EnemyCounter) == 8);

class ActorCollisionCheck;

class Enemy : public ActorMultiState    // vtbl Address: 0x1007209C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9EEC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9EF0
    SEAD_RTTI_OVERRIDE(Enemy, ActorMultiState)

public:
    static const s32 cNoHitPlayerTimerDefault = 5;

    // Address: 0x10072064
    static const f32 cDieFallInitSpeedX[cDirType_NumX];

    // Address: 0x1007206C
    static const f32 cFumiJumpSpeed;
    // Address: 0x10072070
    static const f32 cDefaultGravity;
    // Address: 0x10072074
    static const f32 cDieFallBoundSpeedY;
    // Address: 0x10072078
    static const f32 cDefaultMaxFallSpeed;
    // Address: 0x1007207C
    static const f32 cDefaultMaxSpeedF;
    // Address: 0x10072080
    static const f32 cDefaultMaxSpeedY;

    // Address: 0x10072084
    static const f32 cWaterGravity;
    // Address: 0x10072088
    static const f32 cWaterBoundSpeedY;
    // Address: 0x1007208C
    static const f32 cWaterMaxFallSpeed;
    // Address: 0x10072090
    static const f32 cWaterRollDecRate;

    // Address: 0x10200DD8
    static const Angle cBaseAngleY[cDirType_NumX];
    // Address: 0x10200DE0
    static const Angle cBaseAngleYAdd[cDirType_NumX];

    // Address: 0x10072094
    static const s8 cEnMuki[cDirType_NumX];

    // Address: 0x10200DE8
    static const f32 cDeadNetSpeedX[cDirType_NumX];

    static f32 getDeadNetSpeedX()
    {
        return 1.125f;
    }

public:
    enum FumiSeType
    {
        cFumiSeType_Normal = 0,
        cFumiSeType_Step,
        cFumiSeType_NoEffect
    };

    enum EnFlag
    {
        cEnFlag_Shell               = 1 <<  0,
        cEnFlag_Carry               = 1 <<  1,
        cEnFlag_9                   = 1 <<  9,  // Immune to penguin slide?
        cEnFlag_16                  = 1 << 16,
        cEnFlag_NoCeilCheckPlayer   = 1 << 24
    };

    enum QuakeDeathType
    {
        cQuakeDeathType_NormalQuake = 0,
        cQuakeDeathType_BigQuake,
        cQuakeDeathType_Num
    };
    static_assert(cQuakeDeathType_Num == 2);

public:
    // Address: 0x02328494
    Enemy(const ActorCreateParam& param);

protected:
    // Address: 0x02328644
    bool preExecute_() override;

    // Address: 0x02328914
    void blockHitInit_() override;

public:
    // Address: 0x02330404
    void changeState(const StateID& state_id) override;

    // Address: 0x02328608
    void setNicePoint_Death();

    // Address: 0x02328AEC
    bool area_XY_check(f32 x, f32 y);

    virtual bool vf18C() // is not carryable?
    {
        return false;
    }

    // Address: 0x0232A850
    bool lineBoundaryCheck();

    // Address: 0x02328B84
    virtual bool setDamage(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x02328C50
    static void normal_collcheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x02328C24
    static bool ceilCheck(f32 pos_y, ActorCollisionCheck* p_cc);

    // Address: 0x0232910C
    virtual bool checkComboClap(s32 combo_cnt);

    // Address: 0x02329130
    s32 calcComboPlFumiCnt(Actor* p_player);

    // Address: 0x02329168
    void bound(f32 eps_y, f32 scale_x, f32 scale_y);

    // Address: 0x0232CAEC
    bool isDead() const;
    // Address: 0x0232CCE8
    void setDeadMode(Actor* p_actor);

    // Address: 0x0232CE28
    void cancelCarry();

    // Address: 0x023304F8
    virtual bool createIceActor();
    // Address: 0x023310BC
    virtual void setIceAnm();
    // Address: 0x023310C0
    virtual void returnAnm_Ice();
    // Address: 0x02330568
    virtual void returnState_Ice();

    void killIce()
    {
        mIceMgr.removeIce();
    }

    // Address: 0x0232A858
    virtual void calcMdl_Base();

    // Address: 0x023291DC
    void calcMdl_Normal();  // Calls calcMdl_Base is not currently frozen 

    // Address: 0x0232A85C
    virtual bool vf1CC(); // Maybe related to the below?

    // Address: 0x023291F8
    virtual bool enemyDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329250
    virtual bool playerDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329520
    virtual bool enemyPreDamageCheck(bool* p_dead, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x02329578
    virtual void hitYoshiEat(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
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
    virtual bool hitCallback_ChibiYoshiUnk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232DA0C
    virtual bool hitCallback_ChibiYoshiLight(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x0232DA14
    virtual bool hitCallback_ChibiYoshiStar(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232DA24
    virtual bool hitCallback_AttackUnk27(bool* p_dead, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232DA34
    void setDeathInfo_Fumi(Actor* p_player, const sead::Vector2f& speed, const StateID& state_id);

    void setDeathInfo_Fumi(Actor* p_player, const sead::Vector2f& speed)
    {
        setDeathInfo_Fumi(p_player, speed, StateID_DieFumi);
    }

    void setDeathInfo_FumiFall(Actor* p_player, const sead::Vector2f& speed)
    {
        setDeathInfo_Fumi(p_player, speed, StateID_DieFall);
    }

    void setDeathInfo_FumiOther(Actor* p_player, const sead::Vector2f& speed)
    {
        setDeathInfo_Fumi(p_player, speed, StateID_DieOther);
    }

    // Address: 0x0232CBA4
    void setDeathInfo_Fall(DirType direction, s32 player_no = -1, ScoreMgr::ScoreType score_type = ScoreMgr::cScoreType_Invalid);
    // Address: 0x0232CB08
    void setDeathInfo_Fall(const sead::Vector2f* speeds, DirType direction, s32 player_no = -1, ScoreMgr::ScoreType score_type = ScoreMgr::cScoreType_Invalid);

    // Address: 0x0232DAF0
    virtual void setDeathInfo_Quake(QuakeDeathType type);

    // Address: 0x0232CC98
    void setDeathInfo_SpinFumi(Actor* p_player);
    // Address: 0x0232D31C
    void setDeathInfo_YoshiFumi(Actor* p_player);

protected:
    // Address: 0x0232DC88
    void setSmokeDamage_(Actor* p_actor) override;

public:
    // Address: 0x0232DD48
    virtual void setDeathInfo_IceBreak();
    // Address: 0x0232DD90
    void setDeathInfo_IceVanish();

    // Address: 0x0232DE90
    void setDeathInfo_Other(Actor* p_actor);

    // Address: 0x0232DF14
    void setDeathInfo_Hasami();

    // Address: 0x0232E048
    virtual bool setDeathInfo_Star(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x0232E144
    Angle applyWaterRollDec(Angle ang);

protected:
    // Address: 0x0232E1A4
    bool setTouchDrcDamage_(const sead::Vector3f& pos) override;

public:
    // Address: 0x0232E2EC
    virtual bool isQuakeDamage();   // Return if enemy is on ground && damageable by quake

    // Address: 0x0232E2F8
    virtual void setDeathSound_Fire();
    // Address: 0x0232E358
    virtual void setDeathSound_HipAttk();
    // Address: 0x0232CE94
    void setDeathSound_Slip(Actor* p_player);

    // Address: 0x0232E3FC
    void initDieState();

    // Address: 0x0232E4A8
    void setDeathInfo_Awa(Actor* p_awa);

    // Address: 0x0232D694
    void createUpCoin(DirType dir);

    static void fireballInvalid(ActorCollisionCheck* cc_other)  // Inline in NSMBU, but not NSMBW
    {
        GameAudio::getAudioObjMap()->startSound("SE_OBJ_FIREBALL_DISAPP", cc_other->getOwner()->getPos());
    }

    // Address: 0x02329A0C
    static void iceballInvalid(ActorCollisionCheck* cc_other);

    // Address: 0x02329B88
    FumiType fumiCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other, FumiSeType se_type);

    void spinFumiJumpSet(Actor* p_player)
    {
        fumiJumpSet(p_player);
    }

    // Address: 0x02329B6C
    void spinFumiScoreSet(Actor* p_player);

    // Address: 0x02329EA4
    virtual void fumiJumpSet(Actor* p_player);
    // Address: 0x02329FA8
    virtual void fumiScoreSet(Actor* p_player);

    // Address: 0x02329FAC
    virtual void yoshiFumiJumpSet(Actor* p_player);
    // Address: 0x02329FB0
    virtual void yoshiFumiScoreSet(Actor* p_player);

    // Address: 0x02329FC0
    virtual void mameFumiJumpSet(Actor* p_player);

    // Address: 0x02329E54
    static void playerFumiJump(Actor* p_player, f32 speed_y);

    // Address: 0x02329EC0
    void setFumiComboScore(Actor* p_player);

    void fumistepSE()
    {
        setFumiSound("SE_EMY_CMN_STEP");
    }

    // Address: 0x0232A094
    virtual void fumiSE(Actor* p_player);
    // Address: 0x0232A118
    virtual void fumiEffect(Actor* p_player);

    void spinfumistepSE()
    {
        fumistepSE();
    }

    // Address: 0x0232A1BC
    virtual void spinfumiSE(Actor* p_player);
    // Address: 0x02329B20
    void spinfumiEffect(Actor* p_player);   // No longer virtual...

    void mamefumistepSE()
    {
        setFumiSound("SE_EMY_MAME_STEP");
    }

    // Address: 0x0232A240
    virtual void mamefumiSE();
    // Address: 0x0232A24C
    virtual void mamefumiEffect(Actor* p_player);

    void yoshifumistepSE()
    {
        setFumiSound("SE_EMY_YOSHI_STEP");
    }

    // Address: 0x0232A250
    virtual void yoshifumiSE(Actor* p_player);
    // void yoshifumiEffect(Actor* p_player);   // Deleted from NSMBU

    // Address: 0x02329AA8
    void setFumiSound(const char* label);
    // Address: 0x0232A008
    void setFumiSound(s32 combo_cnt, const GameAudio::SoundID combo_se[], u32 combo_max);
    // Address: 0x0232A088
    void setFumiSound(Actor* p_player, const GameAudio::SoundID combo_se[], u32 combo_max);

    // Address: 0x023288BC
    void hitdamageEffect(const sead::Vector3f& pos);

    void hitdamageEffect(const sead::Vector2f& pos)
    {
        hitdamageEffect(sead::Vector3f(pos, 0.0f));
    }

    // Address: 0x0232A2D4
    virtual void hipatkEffect(const sead::Vector3f& effect_pos);

    // Address: 0x0232A2E4
    virtual void setQuakeJump();    // Adds 2.0f to y speed

    // Address: 0x0232A2FC
    virtual bool checkDispIn(); // Checks if enemy is inside the camera view

    // Address: 0x0232A364
    virtual void setAwaHit(Actor* p_awa); // Callback for ChibiYoshiAwaData
    // Address: 0x0232A418
    virtual void awaCatchMove(Actor* p_awa); // ^^^
    // Address: 0x0232A4CC
    virtual void setAwaCatchEnd(Actor* p_awa); // ^^^
    // Address: 0x0232A864
    virtual void setAwaInvalid(Actor* p_awa); // ^^^

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
    // StateID_DieAwa           Address: 0x10201088
    // initializeState_DieAwa   Address: 0x0232E7E0
    // executeState_DieAwa      Address: 0x0232EEEC
    // finalizeState_DieAwa     Address: 0x0232EEF0
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieAwa)

    // Address: 0x102010AC
    static const f32 cDieFallGravity; // 1.3 * cDefaultGravity
    // Address: 0x10072EA8
    static const f32 cDieFallInitSpeedY;
    // Address: 0x10072EAC
    static const f32 cDieFallMaxFallSpeed;

    static const s32 cDieFallSpinSpeed = 0x0C000000;

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

protected:
    EnemyDeathInfo          mDeathInfo;
    EnemyCounter            mPlayerNoHitTimer;
    sead::BitFlag32         mEnFlag;            // See EnFlag
    IceMgr                  mIceMgr;
    EnemyChibiYoshiAwaData  mChibiYoshiAwaData;

    EnemyFumiProc           mFumiProc;

    u16                     mStateTimer;
    u16                     mStateSubTimer;
    u32                     _1870;
    u8                      mDieDirection;
    u8                      mPreIceDirection;   // Maybe?
    Combo                   mCombo;
    bool                    mIsDamageFrame;
    bool                    mIsSpinFumiFrame;
    s8                      _187e;
};
static_assert(sizeof(Enemy) == 0x1880);

#define _ENEMY_MAKE_DEATH_INFO_ARG_COMMON(arg_name, p_state_id, score_type, player_no)    \
    EnemyDeathInfo::Arg arg_name = {    \
        sead::Vector2f(),               \
        0.0f,                           \
        0.0f,                           \
        p_state_id,                     \
        score_type,                     \
        0,                              \
        player_no                       \
    }

// --- Custom state ---

#define _ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM_COMMON(arg_name, score_type, player_no)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_COMMON(arg_name, nullptr, score_type, player_no)

#define ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM(arg_name)  \
    _ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM_COMMON(arg_name, 0, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM_NO_PLAYER(arg_name)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM_COMMON(arg_name, 0, -1)

#define ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM_ALL_PLAYER(arg_name)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM_COMMON(arg_name, 0, cPlayerNum)

#define ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM_NO_SCORE(arg_name) \
    _ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM_COMMON(arg_name, -1, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM_NO_SCORE_NO_PLAYER(arg_name)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_CUSTOM_COMMON(arg_name, -1, -1)

// --- DieFall ---

#define _ENEMY_MAKE_DEATH_INFO_ARG_FALL_COMMON(arg_name, score_type, player_no) \
    _ENEMY_MAKE_DEATH_INFO_ARG_COMMON(arg_name, &Enemy::StateID_DieFall, score_type, player_no)

#define ENEMY_MAKE_DEATH_INFO_ARG_FALL(arg_name)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_FALL_COMMON(arg_name, 0, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_FALL_NO_PLAYER(arg_name)  \
    _ENEMY_MAKE_DEATH_INFO_ARG_FALL_COMMON(arg_name, 0, -1)

#define ENEMY_MAKE_DEATH_INFO_ARG_FALL_ALL_PLAYER(arg_name) \
    _ENEMY_MAKE_DEATH_INFO_ARG_FALL_COMMON(arg_name, 0, cPlayerNum)

#define ENEMY_MAKE_DEATH_INFO_ARG_FALL_NO_SCORE(arg_name)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_FALL_COMMON(arg_name, -1, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_FALL_NO_SCORE_NO_PLAYER(arg_name) \
    _ENEMY_MAKE_DEATH_INFO_ARG_FALL_COMMON(arg_name, -1, -1)

// --- DieYoshiFumi ---

#define _ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI_COMMON(arg_name, score_type, player_no)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_COMMON(arg_name, &Enemy::StateID_DieYoshiFumi, score_type, player_no)

#define ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI(arg_name)  \
    _ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI_COMMON(arg_name, 0, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI_NO_PLAYER(arg_name)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI_COMMON(arg_name, 0, -1)

#define ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI_ALL_PLAYER(arg_name)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI_COMMON(arg_name, 0, cPlayerNum)

#define ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI_NO_SCORE(arg_name) \
    _ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI_COMMON(arg_name, -1, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI_NO_SCORE_NO_PLAYER(arg_name)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_YOSHI_FUMI_COMMON(arg_name, -1, -1)

// --- DieSmoke ---

#define _ENEMY_MAKE_DEATH_INFO_ARG_SMOKE_COMMON(arg_name, score_type, player_no)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_COMMON(arg_name, &Enemy::StateID_DieSmoke, score_type, player_no)

#define ENEMY_MAKE_DEATH_INFO_ARG_SMOKE(arg_name)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_SMOKE_COMMON(arg_name, 0, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_SMOKE_NO_PLAYER(arg_name) \
    _ENEMY_MAKE_DEATH_INFO_ARG_SMOKE_COMMON(arg_name, 0, -1)

#define ENEMY_MAKE_DEATH_INFO_ARG_SMOKE_ALL_PLAYER(arg_name)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_SMOKE_COMMON(arg_name, 0, cPlayerNum)

#define ENEMY_MAKE_DEATH_INFO_ARG_SMOKE_NO_SCORE(arg_name)  \
    _ENEMY_MAKE_DEATH_INFO_ARG_SMOKE_COMMON(arg_name, -1, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_SMOKE_NO_SCORE_NO_PLAYER(arg_name)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_SMOKE_COMMON(arg_name, -1, -1)

// --- DieIceVanish ---

#define _ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH_COMMON(arg_name, score_type, player_no)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_COMMON(arg_name, &Enemy::StateID_DieIceVanish, score_type, player_no)

#define ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH(arg_name)  \
    _ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH_COMMON(arg_name, 0, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH_NO_PLAYER(arg_name)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH_COMMON(arg_name, 0, -1)

#define ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH_ALL_PLAYER(arg_name)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH_COMMON(arg_name, 0, cPlayerNum)

#define ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH_NO_SCORE(arg_name) \
    _ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH_COMMON(arg_name, -1, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH_NO_SCORE_NO_PLAYER(arg_name)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_ICE_VANISH_COMMON(arg_name, -1, -1)

// --- DieOther ---

#define _ENEMY_MAKE_DEATH_INFO_ARG_OTHER_COMMON(arg_name, score_type, player_no)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_COMMON(arg_name, &Enemy::StateID_DieOther, score_type, player_no)

#define ENEMY_MAKE_DEATH_INFO_ARG_OTHER(arg_name)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_OTHER_COMMON(arg_name, 0, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_OTHER_NO_PLAYER(arg_name) \
    _ENEMY_MAKE_DEATH_INFO_ARG_OTHER_COMMON(arg_name, 0, -1)

#define ENEMY_MAKE_DEATH_INFO_ARG_OTHER_ALL_PLAYER(arg_name)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_OTHER_COMMON(arg_name, 0, cPlayerNum)

#define ENEMY_MAKE_DEATH_INFO_ARG_OTHER_NO_SCORE(arg_name)  \
    _ENEMY_MAKE_DEATH_INFO_ARG_OTHER_COMMON(arg_name, -1, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_OTHER_NO_SCORE_NO_PLAYER(arg_name)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_OTHER_COMMON(arg_name, -1, -1)

// --- DieAwa ---

#define _ENEMY_MAKE_DEATH_INFO_ARG_AWA_COMMON(arg_name, score_type, player_no)  \
    _ENEMY_MAKE_DEATH_INFO_ARG_COMMON(arg_name, &Enemy::StateID_DieAwa, score_type, player_no)

#define ENEMY_MAKE_DEATH_INFO_ARG_AWA(arg_name) \
    _ENEMY_MAKE_DEATH_INFO_ARG_AWA_COMMON(arg_name, 0, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_AWA_NO_PLAYER(arg_name)   \
    _ENEMY_MAKE_DEATH_INFO_ARG_AWA_COMMON(arg_name, 0, -1)

#define ENEMY_MAKE_DEATH_INFO_ARG_AWA_ALL_PLAYER(arg_name)  \
    _ENEMY_MAKE_DEATH_INFO_ARG_AWA_COMMON(arg_name, 0, cPlayerNum)

#define ENEMY_MAKE_DEATH_INFO_ARG_AWA_NO_SCORE(arg_name)    \
    _ENEMY_MAKE_DEATH_INFO_ARG_AWA_COMMON(arg_name, -1, 0)

#define ENEMY_MAKE_DEATH_INFO_ARG_AWA_NO_SCORE_NO_PLAYER(arg_name)  \
    _ENEMY_MAKE_DEATH_INFO_ARG_AWA_COMMON(arg_name, -1, -1)
