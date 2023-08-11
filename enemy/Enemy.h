#pragma once

#include <actor/ActorState.h>
#include <enemy/EnemyDeathInfo.h>
#include <state/StateVirtualID.h>

class ActorCollisionCheck;

class Enemy : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(Enemy, ActorMultiState)

public:
    enum FumiType
    {
        cFumiType_NoFumi = 0,
        cFumiType_Fumi,
        cFumiType_MameFumi,
        cFumiType_SpinFumi
    };

public:
    Enemy(const ActorCreateParam& param);
    virtual ~Enemy() { }

protected:
    s32 preExecute_() override;

public:
    void blockHitInit() override;
    void vf14C(Actor*) override;
    bool vf154(const sead::Vector2f&) override;
    void changeState(const IStateID& state_id) override;

    virtual bool vf18C() // is frozen?
    {
        return false;
    }

    virtual bool setDamage(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    virtual bool checkComboClap(s32 combo_cnt);

    virtual bool createIceActor();
    virtual void setIceAnm();
    virtual void returnAnm_Ice();
    virtual void returnState_Ice();

    virtual void calcMdl();

    virtual bool vf1CC(); // Maybe related to the below?

    virtual bool enemyDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool playerDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool vf1E4(bool*, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool vf1EC(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool yoshiDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool chibiYoshiDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool etcDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    virtual void vsEnemyHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual void vsChibiYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // I think

    virtual bool hitCallback_Star(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_Slip(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_WireNet(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // I think
    virtual bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_YoshiHipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_PenguinSlide(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_Cannon(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool vf26C(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // Player slip 2
    virtual bool hitCallback_Shell(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_Fire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_YoshiBullet(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_YoshiFire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool hitCallback_ChibiYoshiBubble(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // I think
    virtual bool hitCallback_ChibiYoshiGlow(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other); // I think
    virtual bool hitCallback_ChibiYoshiStar(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    virtual bool vf2B4(bool*, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    virtual void setDeathInfo_Quake(s32);
    virtual void setDeathInfo_IceBreak();
    virtual bool setDeathInfo_Star(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    virtual bool isOnGround();

    virtual void setDeathSound_Fire();
    virtual void setDeathSound_HipAttk();

    virtual void fumiJumpSet(Actor*);
    virtual void fumiScoreSet(Actor*);

    virtual void yoshiFumiJumpSet(Actor*);
    virtual void yoshiFumiScoreSet(Actor*);

    virtual void mameFumiJumpSet(Actor*);

    virtual void fumiSE(Actor*);
    virtual void fumiEffect(Actor*);

    virtual void spinfumiSE(Actor*);

    virtual void mamefumiSE(Actor*);
    virtual void mamefumiEffect(Actor*);

    virtual void yoshifumiSE(Actor*);
    virtual void yoshifumiEffect(Actor*); // or spinfumiEffect, unclear which one

    virtual void vf34C(); // Adds 2.0f to y speed

    virtual bool areaXYCheck(); // Checks if enemy is inside the camera view

    virtual void vf35C(Actor*);
    virtual void vf364(Actor*);
    virtual void vf36C(Actor*);
    virtual void vf374();

    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieFumi)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieFall)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieSmoke)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieYoshiFumi)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieIceVanish)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieGoal)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieOther)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, EatIn)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, EatNow)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, EatOut)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, ChibiEatIn)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, ChibiEatNow)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, ChibiEatOut)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, HitSpin)
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, Ice)

    static void normal_collcheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    static void iceballInvalid(ActorCollisionCheck* cc_other);

    void setDeathInfo_Fall(u8 direction, s8 player_no, s8 score_lyt_type);
    void setDeathInfo_Fall(const sead::Vector2f* speeds, u8 direction, s8 player_no, s8 score_lyt_type);
    void setDeathInfo_Fumi(Actor*, sead::Vector2f speed, const IStateID& state_id);
    void setDeathInfo_SpinFumi(Actor*);
    void setDeathInfo_YoshiFumi(Actor*);

    void startSound(const char* name);

    FumiType fumiCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other, s32);

    void bound(f32, f32, f32);

    bool isNoRespawn() const;

protected:
    EnemyDeathInfo  mDeathInfo;
    u16             _17e4[4];
    u32             _17e8;
    u32             mIceMgr[0x50 / sizeof(u32)];            // TODO: IceMgr
    u32             mChibiBubbleData[0x20 / sizeof(u32)];   // TODO: ChibiBubbleData
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
