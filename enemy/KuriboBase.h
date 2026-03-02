#pragma once

#include <actor/Profile.h>
#include <collision/ActorCollisionDrcTouchCallback.h>
#include <enemy/Enemy.h>
#include <enemy/EnemyBoyoMgr.h>
#include <enemy/EnemyChibiYoshiEatData.h>
#include <enemy/EnemyEatData.h>
#include <enemy/MiddleKuribo.h>
#include <graphics/CalcRatioSRT.h>

class BlendModel;
class ModelResource;
class TexturePatternAnimation;

class KuriboBase : public Enemy // vtbl Address: 0x100916DC
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA144
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA140
    SEAD_RTTI_OVERRIDE(KuriboBase, Enemy)

protected:
    class DrcTouchCB : public ActorCollisionDrcTouchCallback    // vtbl Address: 0x10091CD4
    {
    public:
        // Address: 0x023DDBF8
        bool ccSetTouchNormal(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
        // Address: 0x023DDC90
        void ccOnTouch(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
    };
    static_assert(sizeof(DrcTouchCB) == sizeof(ActorCollisionDrcTouchCallback));

    enum ModelType
    {
        cModelType_Normal = 0,
        cModelType_Kakibo
    };

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
        if (mBlockHitImmune)
            return;

        Enemy::blockHitInit_();
    }

public:
    // Address: 0x023DBE44
    void calcMdl_Base() override;

    // Address: 0x023DBE54
    static void normal_collcheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x023DBF0C
    void vsEnemyHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x023DBFB0
    void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x023DC0C4
    void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DC1E8
    void hitYoshiEat(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DC2B4
    bool hitCallback_YoshiHipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x023DC3B4
    void vsChibiYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DC3C4
    bool hitCallback_ChibiYoshiUnk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023DC490
    void setAwaHit(Actor* p_awa) override;

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
    virtual void reactFumiProc(Actor* p_player);

    // Address: Deleted
    virtual void reactMameFumiProc(Actor* p_player)
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

    // Address: 0x023DCAC4
    void yoganSplashEffect(const sead::Vector3f& pos) override;

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

    // StateID_DieOther         Address: 0x102048A4
    // initializeState_DieOther Address: 0x023DD444
    // executeState_DieOther    Address: 0x023DD620
    // finalizeState_DieOther   Address: 0x023DD63C
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KuriboBase, DieOther)
    // StateID_DieFall          Address: 0x102048C8
    // initializeState_DieFall  Address: 0x023DD640
    // executeState_DieFall     Address: 0x023DD6D0
    // finalizeState_DieFall    Address: 0x023DD704
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KuriboBase, DieFall)

    // Address: 0x023DD708
    static BlendModel* createModel(ModelResource* p_mdl_res, const sead::SafeString& name, bool not_set_walk_anm);

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

    // Address: 0x023DD97C
    void reviveCollisionCheck() override;
    // Address: 0x023DDA28
    void removeCollisionCheck() override;

    // Address: 0x023DDAB4
    bool setDamage(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x023DDBA8
    void allEnemyDeathEffSet() override;

protected:
    // Address: 0x023DC4AC
    void calcModelBase_(BlendModel* p_blend_model);

    void calcModelBase_()
    {
        calcModelBase_(mpBlendModel);
    }

    // Address: 0x023DB42C
    bool checkRyusa_();

    // Address: 0x023DB388
    void setLayerPos_();

    // Address: 0x023DB1F0
    void setCcLine_();

    // Address: 0x023DB4E8
    bool checkGround_();

    // Address: 0x023DB588
    void landonEffect_();

    // Address: 0x023DBA74
    u8 checkBgIn_();

    // Address: 0x023DBB48
    void setDeathInfo_Hasami_();

protected:
    ModelResource*              mpModelResource;
    BlendModel*                 mpBlendModel;
    TexturePatternAnimation*    mpTexAnim;
    CalcRatioSRT                mCalcRatio;
    MiddleKuribo*               mpParentMiddleKuribo;
    ActorCollisionCheck         mCollisionCheckDrcTouch;
    f32                         mWalkAnmRate;               // Stored, but never read
    f32                         mZOffset;
    f32                         mKakiboHaScale;
    Angle                       mKakiboHaAngleZ;
    bool                        mHasLanded;
    bool                        mForceLanded;
    bool                        mAllowDrcTouchInAir;
    bool                        mBlockHitImmune;
    bool                        mIsDrcTouch;
    bool                        mIsKakibo;
    u8                          mModelType;
    s8                          mSubstate;
    bool                        mDisableScreenOutCheck;
    f32                         mEnemyHitRevX;
    EnemyEatData                mEatData;
    EnemyChibiYoshiEatData      mChibiYoshiEatData;
    EnemyBoyoMgr                mBoyoMgr;
    DrcTouchCB                  mDrcTouchCallback;

    // Address: 0x10091658
    static const f32 cPataTurnMaxSpeedX;    // 1.0f
    // Address: 0x1009165C
    static const f32 cPataWalkMaxSpeedY;    // -4.0f

    // Address: 0x10091660
    static const ActorCreateInfo cActorCreateInfo;

    // Address: 0x10091684
    static const ActorCollisionCheck::CollisionData cCcData_Normal;
    // Address: 0x100916B0
    static const ActorCollisionCheck::CollisionData cCcData_DrcTouch;
};
static_assert(sizeof(KuriboBase) == 0x1A88);
