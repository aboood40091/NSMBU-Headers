#pragma once

#include <collision/ActorCollisionHitCallback.h>
#include <enemy/Enemy.h>
#include <enemy/EnemyActorScaler.h>
#include <enemy/EnemyChibiEatData.h>
#include <enemy/EnemyEatData.h>
#include <enemy/MiddleKuribo.h>
#include <graphics/CalcRatioSRT.h>

class KuriboBaseCB : public ActorCollisionHitCallback   // vtbl Address: 0x10091CD4
{
public:
    // Address: 0x023DDBF8
    bool ccCallback1(ActorCollisionCheck*, const sead::Vector2f&) override;
    // Address: 0x023DDC90
    void ccCallback2(ActorCollisionCheck*, const sead::Vector2f&) override;
};
static_assert(sizeof(KuriboBaseCB) == sizeof(ActorCollisionHitCallback));

class BlendModel;
class ModelResource;
class TexturePatternAnimation;

class KuriboBase : public Enemy // vtbl Address: 0x100916DC
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA144
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA140
    SEAD_RTTI_OVERRIDE(KuriboBase, Enemy)

public:
    // Address: 0x023DAF04
    KuriboBase(const ActorCreateParam& param);

protected:
    // Address: 0x023DB070
    s32 create_() override;
    // Address: 0x023DBC70
    s32 execute_() override;
    // Address: 0x023DBE14
    s32 draw_() override;
    // Address: 0x023DE5F4
    s32 doDelete_() override;

public:
    // Address: 0x023DDA28
    void removeCollisionCheck() override;
    // Address: 0x023DD97C
    void reviveCollisionCheck() override;
    // Address: 0x023DDBA8
    void allEnemyDeathEffSet() override;
    // Address: 0x023DCAC4
    void yoganSplashEffect(const sead::Vector3f&) override;

    void blockHitInit() override
    {
        if (_1a0b)
            return;

        Enemy::blockHitInit();
    }

    // Address: 0x023DDAB4
    bool setDamage(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DBE44
    void calcMdl() override;
    // Address: 0x023DC1E8
    bool vf1EC(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DBF0C
    void vsEnemyHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DBFB0
    void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DC0C4
    void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DC3B4
    void vsChibiYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override; // I think
    // Address: 0x023DC2B4
    bool hitCallback_YoshiHipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DC3C4
    bool hitCallback_ChibiYoshiBubble(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override; // I think
    // Address: 0x023DC490
    void vf35C(Actor*) override;

    // StateID_DieFall          Address: 0x102048C8
    // initializeState_DieFall  Address: 0x023DD640
    // executeState_DieFall     Address: 0x023DD6D0
    // finalizeState_DieFall    Address: 0x023DD704
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KuriboBase, DieFall)
    // StateID_DieGoal          Address: 0x102048A4
    // initializeState_DieGoal  Address: 0x023DD444
    // executeState_DieGoal     Address: 0x023DD620
    // finalizeState_DieGoal    Address: 0x023DD63C
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KuriboBase, DieGoal)

public:
    virtual void initialize()
    {
    }

    virtual void calcModel()
    {
    }

    virtual void drawModel()
    {
    }

    virtual void setTurnByEnemyHit()
    {
    }

    // Address: 0x023DC9B4
    virtual void setTurnByPlayerHit(Actor*);

    virtual void setWalkSpeed()
    {
    }

    virtual void vf514()
    {
    }

    // Address: 0x023DCA88
    virtual void reactFumiProc(Actor*);

    virtual void reactMameFumiProc(Actor*)
    {
    }

    virtual void reactSpinFumiProc(Actor* p_player)
    {
        setDeathInfo_SpinFumi(p_player);
    }

    virtual void reactYoshiFumiProc(Actor* p_yoshi)
    {
        if (mpParentMiddleKuribo != nullptr)
            mpParentMiddleKuribo->_1b0c++;

        setDeathInfo_YoshiFumi(p_yoshi);
    }

    virtual void vf53C(const ActorCollisionCheck&)  // Seems to detach the actor from its balloon in Kuribo
    {
    }

    virtual bool vf544()
    {
        return false;
    }

    virtual bool vf54C()
    {
        return false;
    }

    virtual bool vf554()    // Checks if current state ID is StateID_Touch in Kuribo
    {
        return false;
    }

    // StateID_Walk         Address: 0x10204814
    // initializeState_Walk Address: 0x023DCB48
    // executeState_Walk    Address: 0x023DCC38
    // finalizeState_Walk   Address: 0x023DE660
    DECLARE_STATE_VIRTUAL_ID_BASE(KuriboBase, Walk)
    // StateID_Turn         Address: 0x10204838
    // initializeState_Turn Address: 0x023DCDC4
    // executeState_Turn    Address: 0x023DCE60
    // finalizeState_Turn   Address: 0x023DE664
    DECLARE_STATE_VIRTUAL_ID_BASE(KuriboBase, Turn)
    // StateID_Touch            Address: 0x1020485C
    // initializeState_Touch    Address: 0x023DCF90
    // executeState_Touch       Address: 0x023DCFE8
    // finalizeState_Touch      Address: 0x023DD288
    DECLARE_STATE_VIRTUAL_ID_BASE(KuriboBase, Touch)    // ?
    // StateID_TrplnJump            Address: 0x10204880
    // initializeState_TrplnJump    Address: 0x023DD294
    // executeState_TrplnJump       Address: 0x023DD2D8
    // finalizeState_TrplnJump      Address: 0x023DE668
    DECLARE_STATE_VIRTUAL_ID_BASE(KuriboBase, TrplnJump)

    // Address: 0x023DD7E4
    virtual void setWalkAnm();

    virtual bool isWakidashi() const
    {
        return false;
    }

    // Address: Deleted
    virtual u32 vf5CC()
    {
        return 0;
    }

    virtual u32 vf5D4()
    {
        return 1;
    }

    virtual void vf5DC()
    {
    }

    // Address: Deleted (Only in KuriboBase)
    virtual void vf5E4()    // Sets info for DRC Touch (maybe) ActorCollisionCheck
    {
    }

    virtual void vf5EC()
    {
    }

    virtual void vf5F4()    // Changes state to Walk state in Kuribo
    {
    }

protected:
    ModelResource*              mpModelResource;
    BlendModel*                 mpBlendModel;
    TexturePatternAnimation*    mpTexAnim;
    CalcRatioSRT                mCalcRatio;
    MiddleKuribo*               mpParentMiddleKuribo;
    ActorCollisionCheck         mCollisionCheckDrcTouch;    // Maybe?
    f32                         _19f8;
    f32                         mZOffset;
    f32                         _1a00;
    u32                         _1a04;                      // Some kind of angle (only used by Kakibo?)
    u8                          _1a08;
    u8                          _1a09;
    u8                          _1a0a;
    u8                          _1a0b;
    u8                          _1a0c;
    bool                        mIsKakibo;
    u8                          mType;                      // 0 = Kuribo, 1 = Kakibo
    u8                          _1a0f;
    u8                          _1a10;
    f32                         _1a14;
    EnemyEatData                mEatData;
    EnemyChibiEatData           mChibiEatData;
    EnemyActorScaler            mScaler;
    KuriboBaseCB                mCollisionHitCallback;
};
static_assert(sizeof(KuriboBase) == 0x1A88);
