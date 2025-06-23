#pragma once

#include <actor/EatData.h>
#include <collision/ActorBgCollisionEnemyCheck.h>
#include <collision/ActorCollisionTouchDrcCallback.h>
#include <effect/EffectObj.h>
#include <enemy/Enemy.h>
#include <enemy/EnemyActorScaler.h>

#include <math/seadMatrix.h>

class BrosBaseTouchDrcCB : public ActorCollisionTouchDrcCallback    // vtbl Address: 0x1005F6E8
{
public:
    // Address: 0x022DD974
    bool ccIsTouchEnable(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
    // Address: 0x022DDAEC
    void ccOnTouch(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
};
static_assert(sizeof(BrosBaseTouchDrcCB) == sizeof(ActorCollisionTouchDrcCallback));

class BlendModel;

class BrosBase : public Enemy   // vtbl Address: 0x1005F078
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA308
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA30C
    SEAD_RTTI_OVERRIDE(BrosBase, Enemy)

public:
    // Address: 0x022DA0AC
    BrosBase(const ActorCreateParam& param);

    virtual ~BrosBase()
    {
    }

protected:
    // Address: 0x022DA758
    s32 create_() override;
    // Address: 0x022DAFE8
    s32 execute_() override;
    // Address: 0x022DB08C
    s32 draw_() override;
    // Address: 0x022DE848
    s32 doDelete_() override;

public:
    // Address: 0x022DD66C
    void allEnemyDeathEffSet() override;

    // Address: 0x022DD264
    bool setDamage(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022DD3D8
    bool createIceActor() override;
    // Address: 0x022DD484
    void setIceAnm() override;
    // Address: 0x022DD3C0
    void returnState_Ice() override;
    // Address: 0x022DB0C0
    void calcMdl_Ice() override;
    // Address: 0x022DB0C4
    void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022DB210
    void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022DB6A0
    bool hitCallback_Star(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022DB318
    bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022DB50C
    bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022DB870
    bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022DB510
    bool hitCallback_YoshiBullet(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022DB954
    bool hitCallback_ChibiYoshiLight(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // StateID_DieFumi          Address: 0x101FF488
    // initializeState_DieFumi  Address: 0x022DCE14
    // executeState_DieFumi     Address: 0x022DCEA8
    // finalizeState_DieFumi    Address: 0x022DE860
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(BrosBase, DieFumi)
    // StateID_DieFall          Address: 0x101FF4AC
    // initializeState_DieFall  Address: 0x022DCEF4
    // executeState_DieFall     Address: 0x022DCF88
    // finalizeState_DieFall    Address: 0x022DE864
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(BrosBase, DieFall)

public:
    // StateID_Move         Address: 0x101FF3B0
    // initializeState_Move Address: 0x022DBE48
    // executeState_Move    Address: 0x022DC000
    // finalizeState_Move   Address: 0x022DE850
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, Move)
    // StateID_Attack           Address: 0x101FF3D4
    // initializeState_Attack   Address: 0x022DC294
    // executeState_Attack      Address: 0x022DC2D4
    // finalizeState_Attack     Address: 0x022DE854
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, Attack)
    // StateID_JumpSt           Address: 0x101FF3F8
    // initializeState_JumpSt   Address: 0x022DC5C8
    // executeState_JumpSt      Address: 0x022DC61C
    // finalizeState_JumpSt     Address: 0x022DE858
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, JumpSt)
    // StateID_Jump         Address: 0x101FF41C
    // initializeState_Jump Address: 0x022DC768
    // executeState_Jump    Address: 0x022DC878
    // finalizeState_Jump   Address: 0x022DC928
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, Jump)
    // StateID_JumpEd           Address: 0x101FF440
    // initializeState_JumpEd   Address: 0x022DC934
    // executeState_JumpEd      Address: 0x022DC9AC
    // finalizeState_JumpEd     Address: 0x022DE85C
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, JumpEd)
    // StateID_AirAttack            Address: 0x101FF464
    // initializeState_AirAttack    Address: 0x022DCA88
    // executeState_AirAttack       Address: 0x022DCAD4
    // finalizeState_AirAttack      Address: 0x022DCDFC
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, AirAttack)
    // StateID_Down         Address: 0x101FF4D0
    // initializeState_Down Address: 0x022DD000
    // executeState_Down    Address: 0x022DD094
    // finalizeState_Down   Address: 0x022DD21C
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, Down)

public:
    // Address: Deleted
    virtual void vf58C();

    virtual f32 getCreateWeaponFrm() const
    {
        return 0.0f;
    }

    virtual f32 getAttackFrm() const
    {
        return 0.0f;
    }

    virtual void setSpeed()
    {
    }

    // Address: Deleted
    virtual bool checkAtkArea();

    virtual s32 getColor()
    {
        return -1;
    }

    virtual void setAtkTimer()
    {
    }

    // Address: Deleted
    virtual sead::Vector3f getAdjustOffset();

    // Address: 0x022DD500
    virtual void calcMoveDir();

    virtual void setWeaponPos()
    {
    }

    virtual void weaponCreate()
    {
    }

    virtual void weaponAttack()
    {
    }

    virtual void setJumpCnt()
    {
    }

    virtual void setJump()
    {
    }

    virtual void beginJump()
    {
        setJump();
        changeState(StateID_AirAttack);
    }

    virtual bool isInvalidBg()
    {
        return false;
    }

    virtual bool isAttackOK() const
    {
        return true;
    }

    virtual void beginAttk()
    {
        mRepeatedAttackCount = 1;
        changeState(StateID_Attack);
    }

    // Address: 0x022DD598
    virtual void setAttackAnm();

    virtual void initMoveCnt()
    {
        mMoveCnt = 0;
    }

    virtual void initPosLv()
    {
    }

    virtual void initType()
    {
    }

    // Address: Deleted
    virtual void vf63C();
    // Address: Deleted
    virtual void vf644();

    virtual void vf64C()    // Never overridden
    {
    }

    virtual void vf654()    // "Drop weapon on kock down" Maybe? (Deletes weapon)
    {
    }

    // Address: 0x022DD768
    virtual bool vf65C();   // "Can be knocked down?" Maybe?

    virtual void entryHIO()
    {
    }

    virtual void removeHIO()
    {
    }

public:
    // Address: 0x022DBEEC
    bool calcTurnAngle();

protected:
    BlendModel*                 mpBlendModel;
    sead::Matrixf               mBone6Transform;
    sead::Matrixf               mBone4Transform;
    sead::Matrixf               mBone0Transform;
    sead::Matrixf               mBone14Transform;
    sead::Matrixf               mBone11Transform;
    s32                         mAtkTimer;
    s32                         mJumpCnt;
    s32                         mMoveCnt;
    u32                         _1980;
    u32                         _1984;
    u32                         mRepeatedAttackCount;
    u32                         _198c;
    u32                         _1990;
    f32                         _1994;
    f32                         _1998;
    u32                         _199c;
    u32                         _19a0;
    sead::Vector3f              mStartPos;
    u8                          mMoveDir;
    ActorUniqueID               mWeaponID;              // I think?
    bool                        _19b8;
    EffectObj                   mEffect;
    EatData                     mEatData;
    u32                         _1a48;
    ActorBgCollisionEnemyCheck  mBgCheckEnemy;
    u32                         _2f30;
    u32                         _2f34;
    u8                          _2f38;
    bool                        _2f39;
    ActorCollisionCheck         mCollisionCheck2;       // For DRC touch???
    BrosBaseTouchDrcCB          mTouchDrcCallback;
    EnemyActorScaler            mScaler;
    u8                          _3088;
    u8                          _3089;
};
static_assert(sizeof(BrosBase) == 0x3090);
