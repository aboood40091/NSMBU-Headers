#pragma once

#include <actor/Profile.h>
#include <collision/ActorCollisionHitCallback.h>
#include <effect/EffectDisposable.h>
#include <enemy/CarryEnemy.h>
#include <enemy/EnemyActorScaler.h>
#include <enemy/EnemyChibiEatData.h>
#include <enemy/EnemyEatData.h>
#include <graphics/Light.h>
#include <map_obj/MaskDraw.h>

class BomheiCB : public ActorCollisionHitCallback   // vtbl Address: 0x1005D73C
{
public:
    BomheiCB()
        : _4(0)
    {
    }

    // Address: 0x022D053C
    bool ccCallback1(ActorCollisionCheck*, const sead::Vector2f&) override;
    // Address: 0x022D0584
    void ccCallback2(ActorCollisionCheck*, const sead::Vector2f&) override;

protected:
    u32 _4;
};
static_assert(sizeof(BomheiCB) == 8);

class BlendModel;
class ModelResource;

class Bomhei : public CarryEnemy    // vtbl Address: 0x1005D794
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9F80
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FC4
    SEAD_RTTI_OVERRIDE(Bomhei, CarryEnemy)

public:
    // Address: 0x1005D49C
    static const ActorCreateInfo cActorCreateInfo;

public:
    // Address: 0x022D0334
    Bomhei(const ActorCreateParam& param);
    virtual ~Bomhei() { }

protected:
    // Address: 0x022D159C
    s32 create_() override;
    // Address: 0x022D19B8
    s32 execute_() override;
    // Address: 0x022D1BD0
    s32 draw_() override;
    // Address: 0x022D1C38
    s32 doDelete_() override;

public:
    // Address: 0x022D3F08
    void allEnemyDeathEffSet() override;
    // Address: 0x022D3F60
    void waterSplashEffect(const sead::Vector3f&) override;
    // Address: 0x022D3F74
    void yoganSplashEffect(const sead::Vector3f&) override;
    // Address: 0x022D3F88
    void poisonSplashEffect(const sead::Vector3f&) override;
    // Address: 0x022D2F48
    void blockHitInit() override;

    // Address: 0x022D3C3C
    bool vf174(f32) override;

    // Address: 0x022D42A8
    bool vf18C() override;

    // Address: 0x022D2D10
    bool createIceActor() override;
    // Address: 0x022D2F28
    void returnState_Ice() override;

    void calcMdl() override
    {
        calcMdl_();
    }

    // Address: 0x022D2B20
    bool etcDamageCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022D2274
    void vsEnemyHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022D24B0
    void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022D2B10
    bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022D26AC
    bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022D280C
    bool hitCallback_YoshiHipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022D2928
    bool hitCallback_Fire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022D2AB4
    bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022D2A00
    bool hitCallback_YoshiFire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022D214C
    void fumiScoreSet(Actor*) override;

    // StateID_DieFall          Address: 0x101FF288
    // initializeState_DieFall  Address: 0x022D6074
    // executeState_DieFall     Address: 0x022D60A8
    // finalizeState_DieFall    Address: 0x022D60AC
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, DieFall)
    // StateID_Ice          Address: 0x101FF2AC
    // initializeState_Ice  Address: 0x022D60B0
    // executeState_Ice     Address: 0x022D60C0
    // finalizeState_Ice    Address: 0x022D60C4
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Ice)

    // Address: 0x022D1FBC
    void reactFumiProc(Actor*) override;
    // Address: 0x022D20EC
    void reactSpinFumiProc(Actor*) override;
    // Address: 0x022D1C94
    void playerHitCheck_Awake(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022D30E0
    void playerHitCheck_Unknown(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022D4450
    void setDropChangeState(Actor*) override;
    // Address: 0x022D4468
    void setThrowChangeState(Actor*) override;

    // StateID_Carry            Address: 0x101FF21C
    // initializeState_Carry    Address: 0x022D512C
    // executeState_Carry       Address: 0x022D5170
    // finalizeState_Carry      Address: 0x022D5290
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Carry)
    // StateID_Sleep            Address: 0x101FF264
    // initializeState_Sleep    Address: 0x022D5E74
    // executeState_Sleep       Address: 0x022D5F1C
    // finalizeState_Sleep      Address: 0x022D6068
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Sleep)
    // StateID_Kick         Address: 0x101FF240
    // initializeState_Kick Address: 0x022D5BF0
    // executeState_Kick    Address: 0x022D5CC0
    // finalizeState_Kick   Address: 0x022D5E58
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Kick)

    // Address: 0x022D3F9C
    virtual s32 vf574(u32, f32*);

protected:
    // Address: 0x022D128C
    void calcMdl_();

public:
    // StateID_Walk         Address: 0x101FF0A8
    // initializeState_Walk Address: 0x022D46CC
    // executeState_Walk    Address: 0x022D4790
    // finalizeState_Walk   Address: 0x022D7BD8
    DECLARE_STATE_ID(Bomhei, Walk)
    // StateID_Turn         Address: 0x101FF0C8
    // initializeState_Turn Address: 0x022D48C0
    // executeState_Turn    Address: 0x022D48DC
    // finalizeState_Turn   Address: 0x022D7BDC
    DECLARE_STATE_ID(Bomhei, Turn)
    // StateID_Wakidashi            Address: 0x101FF0E8
    // initializeState_Wakidashi    Address: 0x022D4960
    // executeState_Wakidashi       Address: 0x022D4BC8
    // finalizeState_Wakidashi      Address: 0x022D4C20
    DECLARE_STATE_ID(Bomhei, Wakidashi)
    // StateID_InIceLump            Address: 0x101FF108
    // initializeState_InIceLump    Address: 0x022D4C78
    // executeState_InIceLump       Address: 0x022D7BE0
    // finalizeState_InIceLump      Address: 0x022D4D1C
    DECLARE_STATE_ID(Bomhei, InIceLump)
    // StateID_CannonHop            Address: 0x101FF128
    // initializeState_CannonHop    Address: 0x022D4D2C
    // executeState_CannonHop       Address: 0x022D4DA4
    // finalizeState_CannonHop      Address: 0x022D4F28
    DECLARE_STATE_ID(Bomhei, CannonHop)
    // StateID_Explode          Address: 0x101FF148
    // initializeState_Explode  Address: 0x022D4F5C
    // executeState_Explode     Address: 0x022D5048
    // finalizeState_Explode    Address: 0x022D7BE4
    DECLARE_STATE_ID(Bomhei, Explode)
    // StateID_ThrowKoopaJr_Single          Address: 0x101FF168
    // initializeState_ThrowKoopaJr_Single  Address: 0x022D52D0
    // executeState_ThrowKoopaJr_Single     Address: 0x022D53FC
    // finalizeState_ThrowKoopaJr_Single    Address: 0x022D5764
    DECLARE_STATE_ID(Bomhei, ThrowKoopaJr_Single)
    // StateID_ThrowKoopaJr_Double          Address: 0x101FF188
    // initializeState_ThrowKoopaJr_Double  Address: 0x022D57A4
    // executeState_ThrowKoopaJr_Double     Address: 0x022D58DC
    // finalizeState_ThrowKoopaJr_Double    Address: 0x022D5BB0
    DECLARE_STATE_ID(Bomhei, ThrowKoopaJr_Double)
    // StateID_Slide            Address: 0x101FF1A8
    // initializeState_Slide    Address: 0x022D60FC
    // executeState_Slide       Address: 0x022D622C
    // finalizeState_Slide      Address: 0x022D6404
    DECLARE_STATE_ID(Bomhei, Slide)
    // StateID_AfterIce         Address: 0x101FF1C8
    // initializeState_AfterIce Address: 0x022D6410
    // executeState_AfterIce    Address: 0x022D6448
    // finalizeState_AfterIce   Address: 0x022D7BE8
    DECLARE_STATE_ID(Bomhei, AfterIce)
    // StateID_Frozen           Address: 0x101FF1E8
    // initializeState_Frozen   Address: 0x022D65CC
    // executeState_Frozen      Address: 0x022D7BEC
    // finalizeState_Frozen     Address: 0x022D6634
    DECLARE_STATE_ID(Bomhei, Frozen)

    // Address: 0x022D0680
    void activateFuse();
    // Address: 0x022D0A30
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
    EffectDisposable    mEffect;
    EnemyActorScaler    mScaler;
    BomheiCB            mCollisionHitCallback;
    f32                 _1a44;
    ActorState*         mpKoopaJr;
    ActorCollisionCheck mCollisionCheck2;
    u8                  _1b74;
    u8                  _1b75;
    u32                 mKoopaJrBombId;
    u32                 _1b7c[4 / sizeof(u32)];
};
static_assert(sizeof(Bomhei) == 0x1B80);
