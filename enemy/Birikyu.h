#pragma once

#include <actor/ChibiEatData.h>
#include <actor/EatData.h>
#include <actor/Profile.h>
#include <collision/ActorCollisionHitCallback.h>
#include <effect/LevelEffect.h>
#include <enemy/Enemy.h>
#include <enemy/EnemyActorScaler.h>
#include <graphics/Light.h>

class BirikyuCB : public ActorCollisionHitCallback  // vtbl Address: 0x1005CD9C
{
public:
    // Address: 0x022CF75C
    bool ccCallback1(ActorCollisionCheck*, const sead::Vector2f&) override;
    // Address: 0x022CF7E8
    void ccCallback2(ActorCollisionCheck*, const sead::Vector2f&) override;
};
static_assert(sizeof(BirikyuCB) == sizeof(ActorCollisionHitCallback));

class BasicModel;

class Birikyu : public Enemy    // vtbl Address: 0x1005CDF4
{
public:
    // Address: 0x1005CC30
    static const ActorCreateInfo cActorCreateInfo;

public:
    Birikyu(const ActorCreateParam& param)
        : Enemy(param)
        , _18fc(0)
        , _1900(0.0f)
        , mEatData(mActorUniqueID)
        , mChibiEatData(mActorUniqueID)
        , mScaler(this)
        , mTouchTimer(0)
        , mIsTouchDone(false)
    {
    }

    virtual ~Birikyu()
    {
    }

protected:
    // Address: 0x022CE4B0
    s32 create_() override;
    // Address: 0x022CE7C8
    s32 execute_() override;
    // Address: 0x022CE9B4
    s32 draw_() override;
    // Address: 0x022D00E8
    s32 doDelete_() override;

public:
    // Address: 0x022CF414
    bool createIceActor() override;

    // Address: 0x022CE9E8
    void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022CED00
    void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022D0100
    bool hitCallback_WireNet(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override; // I think
    // Address: 0x022D00F0
    bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022CEBDC
    bool hitCallback_PenguinSlide(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022D00F8
    bool hitCallback_Cannon(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022CEB74
    bool hitCallback_Fire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // StateID_DieFall          Address: 0x101FEFFC
    // initializeState_DieFall  Address: 0x022CF174
    // executeState_DieFall     Address: 0x022CF39C
    // finalizeState_DieFall    Address: 0x022D0110
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Birikyu, DieFall)

protected:
    // Address: Deleted
    virtual void vf4E4();
    // Address: 0x022CF4C8
    virtual void initializeCc_();

    // Address: 0x022CE794
    void calcMdl_();

public:
    // StateID_Wait         Address: 0x101FEF88
    // initializeState_Wait Address: 0x022CEDC4
    // executeState_Wait    Address: 0x022CEECC
    // finalizeState_Wait   Address: 0x022D0108
    DECLARE_STATE_ID(Birikyu, Wait)
    // StateID_Attack           Address: 0x101FEFA8
    // initializeState_Attack   Address: 0x022CEF04
    // executeState_Attack      Address: 0x022CEFB0
    // finalizeState_Attack     Address: 0x022D010C
    DECLARE_STATE_ID(Birikyu, Attack)
    // StateID_Touch            Address: 0x101FEFC8
    // initializeState_Touch    Address: 0x022CF028
    // executeState_Touch       Address: 0x022CF0D0
    // finalizeState_Touch      Address: 0x022CF168
    DECLARE_STATE_ID(Birikyu, Touch)

protected:
    BasicModel*         mpBasicModel;
    sead::Vector3f      mEffectPos;
    LevelEffect         mEffect;
    s32                 mAttackTimer;
    u32                 _18fc;
    f32                 _1900;
    EatData             mEatData;
    ChibiEatData        mChibiEatData;
    Light               mLight;
    u8                  _1994; // bool?
    ActorCollisionCheck mCollisionCheck2;
    BirikyuCB           mCollisionHitCallback;
    EnemyActorScaler    mScaler;
    s32                 mTouchTimer;
    bool                mIsTouchDone;
    u8                  _1ae9[0x1AF0 - 0x1AE9];
};
static_assert(sizeof(Birikyu) == 0x1AF0);
