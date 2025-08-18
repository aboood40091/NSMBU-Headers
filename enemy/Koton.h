#pragma once

#include <actor/EatData.h>
#include <actor/Profile.h>
#include <collision/ActorCollisionTouchDrcCallback.h>
#include <effect/EffectObj.h>
#include <enemy/Enemy.h>
#include <enemy/EnemyActorScaler.h>
#include <enemy/EnemyChibiYoshiEatData.h>

class KotonTouchDrcCB : public ActorCollisionTouchDrcCallback   // vtbl Address: 0x10090654
{
public:
    // Address: 0x023D5334
    bool ccSetTouchNormal(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
    // Address: 0x023D53C0
    void ccOnTouch(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
};
static_assert(sizeof(KotonTouchDrcCB) == sizeof(ActorCollisionTouchDrcCallback));

class AnimModel;

class Koton : public Enemy  // vtbl Address: 0x100906AC
{
public:
    // Address: 0x100904E0
    static const ActorCreateInfo cActorCreateInfo;

public:
    Koton(const ActorCreateParam& param)
        : Enemy(param)
        , mEatData(mActorUniqueID)
        , mChibiYoshiEatData(mActorUniqueID)
        , _1908(0)
        , mScaler(this)
    {
        _188d = 0;
    }

    virtual ~Koton()
    {
    }

protected:
    // Address: 0x023D3B10
    s32 create_() override;
    // Address: 0x023D3F30
    s32 execute_() override;
    // Address: 0x023D3FF0
    s32 draw_() override;
    // Address: 0x023D5E70
    s32 doDelete_() override;

public:
    // Address: 0x023D41F4
    void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023D411C
    bool hitCallback_PenguinSlide(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023D408C
    bool hitCallback_Shell(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023D4024
    bool hitCallback_Fire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023D5E78
    bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // StateID_DieFall          Address: 0x102045CC
    // initializeState_DieFall  Address: 0x023D4F0C
    // executeState_DieFall     Address: 0x023D50A4
    // finalizeState_DieFall    Address: 0x023D5EA8
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Koton, DieFall)

protected:
    // Address: 0x023D37A8
    virtual void setVisibleArea_();
    // Address: Deleted (nullsub)
    virtual void vf4EC();
    // Address: 0x023D5114
    virtual void setCc_();

protected:
    AnimModel*              mpAnimModel;
    u32                     mJumpTimer;
    u32                     _1888;
    bool                    mJumpLeft;
    u8                      _188d;
    f32                     _1890;
    f32                     _1894;
    EatData                 mEatData;
    EnemyChibiYoshiEatData  mChibiYoshiEatData;
    u32                     _18e0;
    sead::Vector3f          _18e4;
    f32                     _18f0;
    u8                      _18f4;
    f32                     _18f8;
    sead::Vector3f          _18fc;
    u8                      _1908;
    f32                     _190c;
    u32                     _1910;
    u32                     _1914;
    f32                     _1918;
    Effect                  mEffect1;
    EffectObj               mEffect2;
    u32                     _19c4;
    ActorCollisionCheck     mCollisionCheck2;
    KotonTouchDrcCB         mTouchDrcCallback;
    EnemyActorScaler        mScaler;
};
static_assert(sizeof(Koton) == 0x1B18);
