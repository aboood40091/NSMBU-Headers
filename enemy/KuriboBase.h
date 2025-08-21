#pragma once

#include <collision/ActorCollisionTouchDrcCallback.h>
#include <enemy/Enemy.h>
#include <enemy/EnemyActorScaler.h>
#include <enemy/EnemyChibiYoshiEatData.h>
#include <enemy/EnemyEatData.h>
#include <enemy/MiddleKuribo.h>
#include <graphics/CalcRatioSRT.h>

class KuriboBaseTouchDrcCB : public ActorCollisionTouchDrcCallback  // vtbl Address: 0x10091CD4
{
public:
    // Address: 0x023DDBF8
    bool ccSetTouchNormal(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
    // Address: 0x023DDC90
    void ccOnTouch(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
};
static_assert(sizeof(KuriboBaseTouchDrcCB) == sizeof(ActorCollisionTouchDrcCallback));

class BlendModel;
class ModelResource;
class TexturePatternAnimation;

class KuriboBase : public Enemy // vtbl Address: 0x100916DC
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA144
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA140
    SEAD_RTTI_OVERRIDE(KuriboBase, Enemy)

public:
    // Address: 0x023DBE54
    static void normal_collcheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

public:
    // Address: 0x023DAF04
    KuriboBase(const ActorCreateParam& param);

protected:
    // Address: 0x023DB070
    Result create_() override;
    // Address: 0x023DBC70
    bool execute_() override;
    // Address: 0x023DBE14
    bool draw_() override;
    // Address: 0x023DE5F4
    Result doDelete_() override;

    void blockHitInit_() override
    {
        if (_1a0b)
            return;

        Enemy::blockHitInit_();
    }

public:
    // Address: 0x023DDA28
    void removeCollisionCheck() override;
    // Address: 0x023DD97C
    void reviveCollisionCheck() override;
    // Address: 0x023DDBA8
    void allEnemyDeathEffSet() override;
    // Address: 0x023DCAC4
    void yoganSplashEffect(const sead::Vector3f&) override;

    // Address: 0x023DDAB4
    bool setDamage(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DBE44
    void calcMdl_Ice() override;
    // Address: 0x023DC1E8
    bool hitYoshiEat(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DBF0C
    void vsEnemyHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DBFB0
    void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DC0C4
    void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DC3B4
    void vsChibiYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
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
    // StateID_DieOther         Address: 0x102048A4
    // initializeState_DieOther Address: 0x023DD444
    // executeState_DieOther    Address: 0x023DD620
    // finalizeState_DieOther   Address: 0x023DD63C
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KuriboBase, DieOther)

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

    virtual void setTurnByEnemyHit(Actor* actor_self, Actor* actor_other)
    {
    }

    // Address: 0x023DC9B4
    virtual void setTurnByPlayerHit(Actor*);

    virtual void setWalkSpeed()
    {
    }

    virtual void walkEffect()
    {
    }

    // Address: 0x023DCA88
    virtual void reactFumiProc(Actor*);

    // Address: Deleted
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

    virtual bool disallowDrcTouchOnGround() // I think
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
    DECLARE_STATE_VIRTUAL_ID_BASE(KuriboBase, Touch)    // I believe this is the state for bouncing back when touched using DRC
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

    virtual bool isBgmSync() const
    {
        return true;
    }

    virtual void onDrcTouch()
    {
    }

    // Address: Deleted
    virtual void vf5E4()    // Somehow not deleted in Kuribo, sets info for DRC Touch (maybe) ActorCollisionCheck
    {
    }

    virtual void vf5EC()
    {
    }

    virtual void vf5F4()    // Changes state to Walk state in Kuribo & PataKuribo
    {
    }

protected:
    // Address: 0x023DC4AC
    void calcModel_(BlendModel* p_model);

    // Address: 0x023DD708
    static BlendModel* createModel_(ModelResource* p_mdl_res, const sead::SafeString& name, bool not_set_walk_anm);

protected:
    ModelResource*              mpModelResource;
    BlendModel*                 mpBlendModel;
    TexturePatternAnimation*    mpTexAnim;
    CalcRatioSRT                mCalcRatio;
    MiddleKuribo*               mpParentMiddleKuribo;
    ActorCollisionCheck         mCollisionCheckDrcTouch;    // Maybe?
    f32                         mWalkAnmRate;               // Stored, but never read
    f32                         mZOffset;
    f32                         _1a00;
    u32                         _1a04;                      // Some kind of angle (only used by Kakibo?)
    u8                          _1a08;
    u8                          _1a09;
    bool                        mAllowDrcTouchInAir;
    u8                          _1a0b;
    u8                          _1a0c;
    bool                        mIsKakibo;
    u8                          mType;                      // 0 = Kuribo, 1 = Kakibo
    u8                          _1a0f;
    u8                          _1a10;
    f32                         _1a14;
    EnemyEatData                mEatData;
    EnemyChibiYoshiEatData      mChibiYoshiEatData;
    EnemyActorScaler            mScaler;
    KuriboBaseTouchDrcCB        mTouchDrcCallback;
};
static_assert(sizeof(KuriboBase) == 0x1A88);
