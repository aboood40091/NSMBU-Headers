#pragma once

#include <actor/GenericChibiEatData.h>
#include <actor/GenericEatData.h>
#include <actor/Profile.h>
#include <collision/CollisionCallback.h>
#include <effect/LevelEffect.h>
#include <enemy/Enemy.h>
#include <enemy/EnemyActorScaler.h>
#include <graphics/Light.h>

class BirikyuCB : public CollisionCallback
{
public:
    bool ccCallback1(Actor*, ActorCollisionCheck*, const sead::Vector2f&) override;
    void ccCallback2(Actor*, ActorCollisionCheck*, const sead::Vector2f&) override;
};
static_assert(sizeof(BirikyuCB) == 4);

class BasicModel;

class Birikyu : public Enemy
{
public:
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
    s32 create_() override;
    s32 execute_() override;
    s32 draw_() override;
    s32 doDelete_() override;

public:
    bool createIceActor() override;

    void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    bool hitCallback_WireNet(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override; // I think
    bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    bool hitCallback_PenguinSlide(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    bool hitCallback_Cannon(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    bool hitCallback_Fire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Birikyu, DieFall)

protected:
    virtual void vf4E4(); // Deleted
    virtual void initializeCc_();

    void calcMdl_();

public:
    DECLARE_STATE_ID(Birikyu, Wait)
    DECLARE_STATE_ID(Birikyu, Attack)
    DECLARE_STATE_ID(Birikyu, Touch)

protected:
    BasicModel*         mpBasicModel;
    sead::Vector3f      mEffectPos;
    LevelEffect         mEffect;
    s32                 mAttackTimer;
    u32                 _18fc;
    f32                 _1900;
    GenericEatData      mEatData;
    GenericChibiEatData mChibiEatData;
    Light               mLight;
    u8                  _1994; // bool?
    ActorCollisionCheck mCollisionCheck2;
    BirikyuCB           mCollisionCB;
    EnemyActorScaler    mScaler;
    s32                 mTouchTimer;
    bool                mIsTouchDone;
    u8                  _1ae9[0x1AF0 - 0x1AE9];
};
static_assert(sizeof(Birikyu) == 0x1AF0);
