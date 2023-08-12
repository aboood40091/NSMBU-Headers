#pragma once

#include <actor/Profile.h>
#include <collision/CollisionCallback.h>
#include <effect/LevelEffect.h>
#include <enemy/CarryEnemy.h>
#include <enemy/EnemyActorScaler.h>
#include <enemy/EnemyChibiEatData.h>
#include <enemy/EnemyEatData.h>
#include <graphics/Light.h>
#include <map_obj/MaskDraw.h>

class BomheiCB : public CollisionCallback
{
public:
    bool ccCallback1(Actor*, ActorCollisionCheck*, const sead::Vector2f&) override;
    void ccCallback2(Actor*, ActorCollisionCheck*, const sead::Vector2f&) override;

protected:
    u32 _4;
};
static_assert(sizeof(BomheiCB) == 8);

class BlendModel;
class ModelResource;

class Bomhei : public CarryEnemy
{
    SEAD_RTTI_OVERRIDE(Bomhei, CarryEnemy)

public:
    static const ActorCreateInfo cActorCreateInfo;

public:
    Bomhei(const ActorCreateParam& param);
    virtual ~Bomhei() { }

protected:
    s32 create_() override;
    s32 execute_() override;
    s32 draw_() override;
    s32 doDelete_() override;

public:
    void killAtGoal() override;
    void splashWater(sead::Vector3f*) override;
    void splashLava(sead::Vector3f*) override;
    void splashPoison(sead::Vector3f*) override;
    void blockHitInit() override;

    bool vf174(f32) override;

    bool vf18C() override;

    bool createIceActor() override;
    void returnState_Ice() override;

    void calcMdl() override
    {
        calcMdl_();
    }

    bool etcDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    void vsEnemyHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    bool hitCallback_YoshiHipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    bool hitCallback_Fire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    bool hitCallback_YoshiFire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    void fumiScoreSet(Actor*) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, DieFall)
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Ice)

    void reactFumiProc(Actor*) override;
    void reactSpinFumiProc(Actor*) override;
    void playerHitCheck_Awake(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    void playerHitCheck_Unknown(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    void setDropChangeState(Actor*) override;
    void setThrowChangeState(Actor*) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Carry)
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Sleep)
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Kick)

    virtual s32 vf574(u32, f32*);

protected:
    void calcMdl_();

public:
    DECLARE_STATE_ID(Bomhei, Walk)
    DECLARE_STATE_ID(Bomhei, Turn)
  //DECLARE_STATE_ID(Bomhei, PipeEnemyGenerator)
  //DECLARE_STATE_ID(Bomhei, KamekFight)
  //DECLARE_STATE_ID(Bomhei, Cannon)
    DECLARE_STATE_ID(Bomhei, Explode)
  //DECLARE_STATE_ID(Bomhei, BowserJrFight)
  //DECLARE_STATE_ID(Bomhei, BowserJrFight2)
  //DECLARE_STATE_ID(Bomhei, State9)
  //DECLARE_STATE_ID(Bomhei, AfterUnfrozen)
  //DECLARE_STATE_ID(Bomhei, KamekFight2)

    void activateFuse();
    void explode();

protected:
    BlendModel*         mpBlendModel;
    ModelResource*      mpModelResource;
    s32                 mCurrentSklAnimIndex;
    sead::BitFlag16     mBomHeiFlag;
    EnemyEatData        mEatData;
    EnemyChibiEatData   mChibiEatData;
    u32                 mBehaviorType;
    u32                 mCannonDirection;
    u32                 _1918;  // nybble11 & 4
    s32                 mSpawnTimer;
    s32                 mFuseTimer;
    s32                 mDeleteTimer;
    u32                 _1928;
    bool                mIsEffectCreated;
    u8                  _192d;
    sead::Vector3f      _1930;
    u32                 mCoinsLeftToSpawn;  // Initialized to 3
    f32                 mLightAttenuation;
    CircleLightMask     mLightMask;
    Light               mLight;
    LevelEffect         mEffect;
    EnemyActorScaler    mScaler;
    BomheiCB            mCollisionCB;
    f32                 _1a44;
    ActorState*         mpKoopaJr;
    ActorCollisionCheck mCollisionCheck2;
    u8                  _1b74;
    u8                  _1b75;
    u32                 mKoopaJrBombId;
    u32                 _1b7c[4 / sizeof(u32)];
};
static_assert(sizeof(Bomhei) == 0x1B80);
