#pragma once

#include <actor/PropelParts.h>
#include <graphics/Light.h>
#include <map/CarryType.h>
#include <player/PlayerBase.h>
#include <player/PlayerEatData.h>
#include <player/PlayerModelMgr.h>
#include <player/PlyOrchestra.h>
#include <player/util/ChangeMgr.h>

class EventDown;
class EventPlayerChange;
class Yoshi;

class PlayerObject : public PlayerBase  // vtbl Address: 0x1016C150
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9C9C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CA0
    SEAD_RTTI_OVERRIDE(PlayerObject, PlayerBase)

public:
    enum CcSizeDataType
    {
        cCcSizeDataType_Mame = 0,
        cCcSizeDataType_Normal,
        cCcSizeDataType_Super,
        cCcSizeDataType_Propel,
        cCcSizeDataType_MameSit,
        cCcSizeDataType_NormalSit,
        cCcSizeDataType_SuperSit,
        cCcSizeDataType_NormalSwim,
        cCcSizeDataType_SuperSwim,
        cCcSizeDataType_NormalWaterWalk,
        cCcSizeDataType_SuperWaterWalk,
        cCcSizeDataType_PenguinSlid,
        cCcSizeDataType_12,             // Carry-related, but it's unknown what exactly it is used for
        cCcSizeDataType_TottenPole,
        cCcSizeDataType_Num
    };
    static_assert(cCcSizeDataType_Num == 14);

    enum CarryStep
    {
        cCarryStep_None = 0,
        cCarryStep_Carry_NoTimer,
        cCarryStep_LiftUp,
        cCarryStep_Carry
    };
    static_assert(sizeof(CarryStep) == 4);

    enum DokanCannonType
    {
        cDokanCannonType_ShootUp = 0,
        cDokanCannonType_ShootDiagonal,
        cDokanCannonType_WarpCannon
    };
    static_assert(sizeof(DokanCannonType) == 4);

    enum QuakeMode
    {
    };
    static_assert(sizeof(QuakeMode) == 4);

    enum ScrollMode
    {
        cScrollMode_0 = 0,
        cScrollMode_1,      // Cannot affect scroll?
        cScrollMode_2,
        cScrollMode_3,
        cScrollMode_4,
        cScrollMode_5,
        cScrollMode_6
    };
    static_assert(sizeof(ScrollMode) == 4);

    enum InvalidKeyType
    {
        cInvalidKeyType_All = 0,
        cInvalidKeyType_LR,
        cInvalidKeyType_Shake,
        cInvalidKeyType_Num
    };
    static_assert(cInvalidKeyType_Num == 3);

    enum InvalidKeyTimerType
    {
        cInvalidKeyTimerType_Normal = 0,
        cInvalidKeyTimerType_ResetOnGround,
        cInvalidKeyTimerType_ResetOnDescendOrGround
    };
    static_assert(sizeof(InvalidKeyTimerType) == 4);

    enum SpinActionMode
    {
        cSpinActionMode_Normal = 0,
        cSpinActionMode_Propel,
        cSpinActionMode_ChibiYoshiBalloon,
        cSpinActionMode_ChibiYoshiBubble,
        cSpinActionMode_ChibiYoshiLight,    // Maybe?
        cSpinActionMode_Musa
    };

public:
    // ------------------------------------ PlayerObject.cpp ------------------------------------ //

    // Address: 0x02923520
    PlayerObject(const ActorCreateParam& param);

    virtual ~PlayerObject()
    {
    }

protected:
    // Address: 0x02923DB0
    Result create_() override;
    // Address: 0x02923F04
    Result doDelete_() override;
    // Address: 0x02923F44
    bool preDraw_() override;
    // Address: 0x02923FA0
    bool draw_() override;
    // Address: 0x02923FF8
    bool preExecute_() override;
    // Address: 0x029242F4
    void postExecute_(MainState state) override;

public:
    // Address: 0x029246FC
    void executeLastPlayer() override;
    // Address: 0x02924BA0
    void executeLastAll() override;

    // Address: 0x02924CBC
    void setPlayerNo(s8 id) override;

    // Address: 0x02924E98
    void setPlayerModeImpl(PlayerMode mode, bool temporary) override;

private:
    inline void setPlayerData_();

public:
    // Address: 0x02924CC0
    void setCenterOffset();
    // Address: 0x02924DC4
    void setSpeedData();
    // Address: 0x02924E5C
    void setModeGravity();

    // Address: 0x0292507C
    const PlayerGravityHIO* getGravityData() override;

    using PlayerBase::getTallType;
    // Address: 0x02925128
    PlayerTallType getTallType(PlayerMode mode) override;

    // Address: 0x0292513C
    void setZPosition() override;
    // Address: 0x029251E8
    void setZPosition(f32 z) override;
    // Address: 0x02925234
    void setZPositionDirect(f32 z) override;
    // Address: 0x02925248
    void offZPosSetNone() override;

    // Address: 0x02923D74
    void setScrollMode(ScrollMode mode);

    // Address: 0x0292406C
    void calcScroll();

    // Address: 0x02925258
    virtual void setCharacterVoice();
    // Address: 0x02923D7C
    void setSoundPlyMode();

    // Address: 0x029252DC
    void getMaskPos(sead::Vector3f& pos) override;
    // Address: 0x02925354
    void getMaskCaveCheckPos(sead::Vector3f* p_pos, f32* p_y_offset) override;

    // Address: 0x029254FC
    bool vf154() override;

    // Address: Deleted
    void setInvalidKeyTimer(s32 time, InvalidKeyTimerType type);
    // Address: 0x0292555C
    void setInvalidKeyTimer_LR(s32 time, InvalidKeyTimerType type);
    // Address: Deleted
    void setInvalidKeyTimer_Shake(s32 time, InvalidKeyTimerType type);
    // Address: 0x02925570
    void calcInvalidKeyTimer();

    // Address: 0x02925804
    void selectAction();

    // Address: 0x02925818
    void startQuakeShock(Quake::ShockType shock_type) override;
    // Address: 0x02925874
    void startPatternRumble(const char* pattern) override;

private:
    inline void calcModel_();

public:
    // Address: 0x02924A7C
    void calcModelRidePlayer();

    // Address: 0x029258D0
    void calcModelBalloon();

    // Address: 0x02924600
    Angle getModelAngleY();
    // Address: 0x02924630
    void getModelScaleBase(sead::Vector3f* p_scale);
    // Address: 0x02924690
    void getModelScale(sead::Vector3f* p_scale);

    // Address: 0x0292434C
    void calcModelWaitFlag();

    // Address: 0x02925964
    bool isFaceRot() override;
    // Address: 0x0292596C
    void setClampFaceRot();

    bool isClimb()
    {
        return isStatus(cStatus_PoleRope) ||
               isStatus(cStatus_Vine) ||
               isStatus(cStatus_Hang) ||
               isStatus(cStatus_KaniHang) ||
               isStatus(cStatus_Pole);
    }

    // Address: 0x02925974
    bool bouncePlayer1(f32 speed_y, f32 speed_F, bool enable_LR, BounceType bounce_type, JumpSe jump_se_type) override;
    // Address: 0x029259D0
    bool bouncePlayer2(f32 speed_y, f32 speed_F, bool enable_LR, BounceType bounce_type, JumpSe jump_se_type) override;
    // Address: 0x02925C70
    bool bouncePlayerSpin(f32 speed_y, f32 speed_F);

    // ------------------------------------ PlayerObjectBalloon.cpp ------------------------------------ //

    // StateID_Balloon          Address: 0x1022B18C
    // initializeState_Balloon  Address: 0x029265C0
    // executeState_Balloon     Address: 0x02926AA0
    // finalizeState_Balloon    Address: 0x02926EF4
    DECLARE_STATE_ID(PlayerObject, Balloon)

    bool isBalloon() const
    {
        return *mStateMgr.getStateID() == StateID_Balloon;
    }

    // Address: 0x02926574
    bool isNotBalloonCourse();

    // Address: 0x02926A24
    bool checkAllBalloonFade();

    // Address: 0x02927018
    bool setBalloonInCreate();
    // Address: 0x029270B0
    bool setBalloonInDamage();
    // Address: 0x02927190
    bool setBalloonDispOutBase();
    // Address: 0x02927294
    bool setBalloonButtonA();
    // Address: 0x0292746C
    bool setBalloonInDispOutBase(s32 type, bool by_yoshi);
    // Address: 0x029275EC
    bool setBalloonInDispOutByYoshi(s32 type);
    // Address: 0x029275F4
    bool setBalloonInNextgoto();
    // Address: 0x029276F8
    bool setBalloonInDispOut(s32 type) override;
    // Address: 0x02927740
    bool setBalloonDispOut() override;

    // Address: 0x029277C0
    void setBreakBalloonJump(Angle angle);

    // Address: 0x02927998
    void setDrawBalloonInPlayer(sead::Vector3f& pos);
    // Address: 0x02927A90
    void setDrawBalloonInPlayerEnable();

    // Address: 0x02927AA8
    void setBalloonHelpVoice();

    // Address: 0x02927B18
    void setBalloonCheckAllFade();

    // ------------------------------------ PlayerObjectBg.cpp ------------------------------------ //

    // Address: 0x02928DC0
    void initBcData();

    // Address: 0x02929B28
    f32 getBcAreaCenterY();

    // ------------------------------------ PlayerObjectCYoshi.cpp ------------------------------------ //

    // StateID_BalloonChibiYoshiFly         Address: 0x1022B24C
    // initializeState_BalloonChibiYoshiFly Address: 0x0292A2E4
    // executeState_BalloonChibiYoshiFly    Address: 0x0292A474
    // finalizeState_BalloonChibiYoshiFly   Address: 0x0292A8F8
    DECLARE_STATE_ID(PlayerObject, BalloonChibiYoshiFly)

    // Address: 0x0292AB0C
    bool setBalloonChibiYoshiFlySmall(f32 speed_y, f32 speed_F);

    // Address: 0x0292AEE4
    bool setChibiYoshiBubbleSpin();

    // Address: 0x02925EFC
    bool isEnableZoom();

    // ------------------------------------ PlayerObjectCc.cpp ------------------------------------ //

    // Address: 0x0292E92C
    void getSpinLiftUpCcSizeInfo(sead::Vector2f* p_center_offset, sead::Vector2f* p_half_size);

    // Address: 0x0292E9C8
    virtual void setFireBallDamage(ActorCollisionCheck::Attack attack);

    // Address: 0x0292EA6C
    virtual CcSizeDataType getCcSizeDataType();

    // Address: 0x0292EB3C
    virtual bool setPlayerFlyDamage(PlayerBase* p_player_other, ActorCollisionCheck::Attack attack);

    // Address: 0x0292EC18
    void initCcData();

    // ------------------------------------ PlayerObjectDemo.cpp ------------------------------------ //

    // Address: 0x02931B34
    virtual bool canChangeTo(PlayerMode mode);

    // Address: 0x02931D18
    bool setPlayerModeForce(PlayerMode mode);

    // ------------------------------------ PlayerObjectDemoDoa.cpp ------------------------------------ //

    // Address: 0x02935158
    void setModelDark();

    // ------------------------------------ PlayerObjectDemoDokan.cpp ------------------------------------ //

    // Address: 0x02936020
    void initDemoInDokan(DokanDir dir) override;
    // Address: 0x02936130
    virtual void initDemoInDokanAngle(DokanDir dir);

    // ------------------------------------ PlayerObjectDemoDown.cpp ------------------------------------ //

    // Address: 0x02937794
    virtual void initPlayerDownCommonImpl();

    // ------------------------------------ PlayerObjectDemoSubject.cpp ------------------------------------ //

    // Address: 0x02939720
    bool setShadowkunHouseReadAction();

    // ------------------------------------ PlayerObjectFire.cpp ------------------------------------ //

    // Address: 0x0293B3E4
    bool setFireBallAction();

    // ------------------------------------ PlayerObjectKani.cpp ------------------------------------ //

    // StateID_KaniJump         Address: 0x1022B34C
    // initializeState_KaniJump Address: 0x02941D98
    // executeState_KaniJump    Address: 0x02941E18
    // finalizeState_KaniJump   Address: 0x02941EA8
    DECLARE_STATE_ID(PlayerObject, KaniJump)

    // Address: 0x02941EE4
    bool setKaniHangAction();

    // ------------------------------------ PlayerObjectMonkey.cpp ------------------------------------ //

    // Address: 0x029457D8
    bool setHangAction();

    // ------------------------------------ PlayerObjectPole.cpp ------------------------------------ //

    // Address: 0x02947270
    bool setPoleAction();

    // ------------------------------------ PlayerObjectPropel.cpp ------------------------------------ //

    // StateID_Propel           Address: 0x1022B1EC
    // initializeState_Propel   Address: 0x029475C0
    // executeState_Propel      Address: 0x02947CF0
    // finalizeState_Propel     Address: 0x02947FA8
    DECLARE_STATE_ID(PlayerObject, Propel)

    // Address: 0x029480AC
    void setPropelFallSpin();

    void resetPropelFlyTime()
    {
        mPropelFlyTime = true;
    }

    // ------------------------------------ PlayerObjectRide.cpp ------------------------------------ //

    // Address: 0x029489B0
    PlayerObject* getRidePlayer(); // The player we are currently riding, or nullptr if we aren't riding anything

    // Address: 0x02948FCC
    bool setRideOffPlayerJump(f32 speed_y, f32 speed_f);

    // Address: 0x02949A28
    void setPlayerHandPos();

    // Address: 0x02949ACC
    bool checkRidePlayerRoofRidePress();

    // Address: 0x02949BB4
    void setJrCrownPos();

    // ------------------------------------ PlayerObjectStar.cpp ------------------------------------ //

    // Address: 0x0294FF20
    bool isStar() const override;

    // Address: 0x029500DC
    bool isStarLight();

    // ------------------------------------ PlayerObjectThrow.cpp ------------------------------------ //

    // Address: 0x02953494
    bool setThrowPlayer();

    // ------------------------------------ PlayerObjectVine.cpp ------------------------------------ //

    // Address: 0x02954840
    void VineActionNet();

    // Address: 0x02953D50
    bool checkVineEnd();
    // Address: 0x02953E2C
    void calcVineSpeed();
    // Address: 0x0295436C
    bool setVineToKaniHangAction();
    // Address: 0x02954560
    void vineWalk();

    // Address: 0x02954D8C
    bool setVineAction();

    // ------------------------------------ PlayerObjectWalk.cpp ------------------------------------ //

    // Address: 0x02957034
    virtual void setWalkAnm(s32 anm_id, AnmBlend blend, f32 rate);

    // Address: 0x029573A8
    virtual bool isIceSlipAnmPlay();

    // Address: 0x02957418
    bool isWaitFrameCountMax() override;

    // Address: 0x02957430
    virtual void setTurnAction_Turned();

    // ------------------------------------ PlayerObjectWallJump.cpp ------------------------------------ //

    // Address: 0x02959B04
    bool checkWallJump();

    // ------------------------------------ PlayerObjectJump.cpp ------------------------------------ //

    // StateID_Jump         Address: 0x1022B470
    // initializeState_Jump Address: 0x0293F214
    // executeState_Jump    Address: 0x0293FBFC
    // finalizeState_Jump   Address: 0x0293FCE4
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Jump)
    // StateID_Fall         Address: 0x1022B494
    // initializeState_Fall Address: 0x0293FD98
    // executeState_Fall    Address: 0x0293FE7C
    // finalizeState_Fall   Address: 0x0293FF8C
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Fall)
    // StateID_SitJump          Address: 0x1022B500
    // initializeState_SitJump  Address: 0x029401E8
    // executeState_SitJump     Address: 0x02940310
    // finalizeState_SitJump    Address: 0x029403E0
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, SitJump)

    // Address: 0x02940C38
    virtual void setFunsuiAscendAnm();

    // ------------------------------------ PlayerObjectSPIN.cpp ------------------------------------ //

    // StateID_SpinJump         Address: 0x1022B0AC
    // initializeState_SpinJump Address: 0x0294A36C
    // executeState_SpinJump    Address: 0x0294AAF4
    // finalizeState_SpinJump   Address: 0x0294AB78
    DECLARE_STATE_ID(PlayerObject, SpinJump)

    // Address: 0x0294AD14
    u16 makeSpinJumpParam(s32 type, JumpSe jump_se_type);

    // Address: 0x0294AD20
    bool setSpinActionReq();

    // Address: 0x0294AF60
    bool setSpinAction();

    // Address: 0x0294A87C
    SpinActionMode getSpinActionMode();

    // Address: 0x0294B37C
    virtual void getSpinJumpEffectPos(sead::Vector3f& pos);

    // Address: 0x0294B398
    virtual void setSpinJumpEffectSub();

    // Address: 0x0294B4B8
    void updateSpinJumpEffect();

    // Address: 0x0294B578
    void updateMissSpinJumpEffect();

    // Address: 0x0294B5B8
    Angle getMissSpinAngle();

    // ------------------------------------ PlayerObjectSWIM.cpp ------------------------------------ //

    // StateID_Swim         Address: 0x1022B5B4
    // initializeState_Swim Address: 0x0294BD5C
    // executeState_Swim    Address: 0x0294EA34
    // finalizeState_Swim   Address: 0x0294EE2C
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Swim)

    // Address: 0x0294EF64
    bool setSwimAction();

    // Address: 0x0294F190
    bool setSwimSpeed(f32 speed_y, f32 speed_F);

    // ------------------------------------ PlayerObjectTarzanRope.cpp ------------------------------------ //

    // Address: 0x029529A8
    bool setTarzanRopeAction();

    // Address: 0x02952B58
    virtual void setRopeHasigoHangUpAngle();

    // ------------------------------------ PlayerObjectDamage.cpp ------------------------------------ //

    // Address: 0x02930858
    bool setDamage2(Actor* p_actor, DamageType type) override;

    // Address: 0x02930A8C
    virtual bool setFlyDamageAction(DamageType type, Actor* p_actor);

    // Address: 0x0293063C
    bool setFlyDamageActionImpl_Part1(DamageType type, Actor* p_actor);
    // Address: 0x02930B48
    virtual bool setFlyDamageActionImpl_Part2(DamageType type, bool, bool = false, bool = false);

    bool setFlyDamageActionImpl(DamageType type, Actor* p_actor)
    {
        if (setFlyDamageActionImpl_Part2(type, setFlyDamageActionImpl_Part1(type, p_actor)))
            return true;
        return false;
    }

    // Address: 0x02930CEC
    bool setQuakeAction();

    // Address: 0x02930D68
    virtual void setElecDamage();

    // Address: 0x02931368
    bool setDamage(Actor* p_actor, DamageType type) override;
    // Address: 0x02931458
    bool setForcedDamage(Actor* p_actor, DamageType type) override;

    // Address: 0x0293153C
    bool setFlyDamage(DamageType type, s32 dir, bool, bool, f32 speed_F, f32 speed_y) override;

    // Address: 0x02931678
    virtual void setRideOffDamage();

    // ------------------------------------ PlayerObjectCarry.cpp ------------------------------------ //

    // Address: 0x0292C170
    PlayerObject* getCarryPlayer();

    // Address: 0x0292D048
    void releaseCarryActor();

    // Address: 0x0292D138
    virtual bool setCarry(Actor* p_actor, CarryType type);

    // Address: 0x0292CEBC
    void cancelCarry(Actor* p_actor);

    // Address: 0x0292D564
    f32 getCarryStepRatio();

    // Address: 0x0292D704
    bool getCarryMtx(sead::Matrixf* p_mtx);

    // Address: 0x0292D8A4
    void clearSpinLiftUpReserve();

    // Address: 0x0292D9A4
    void setSpinLiftUpReserve();

    // Address: 0x0292DAE8
    void calcLiftUpOffsetScale();

    ActorUniqueID getCarryActorID() const
    {
        return mCarryActorID;
    }

    CarryStep getCarryStep() const
    {
        return mCarryStep;
    }

    // ------------------------------------ PlayerObjectEat.cpp ------------------------------------ //

    // Address: 0x029398EC
    Yoshi* getEatYoshi(); // The Yoshi we are currently eaten by, or nullptr if we aren't being carried in a Yoshi's mouth

    // ------------------------------------ PlayerObjectYoshi.cpp ------------------------------------ //

    // Address: 0x0295A3EC
    void setYoshiBackPos();

    // Address: 0x0295A59C
    void calcModelRideYoshi();

    // Address: 0x0295A6F8
    Yoshi* getRideYoshi();

    // Address: 0x0295A7E4
    virtual bool vfAE4();

    // ------------------------------------ PlayerObjectFly.cpp ------------------------------------ //

    // Address: 0x0293D5DC
    void updateMusaEffect();

    // ------------------------------------ PlayerObjectHang.cpp ------------------------------------ //

    // Address: 0x0293DF70
    virtual bool isPlayerHang(PlayerObject* p_player_obj_parent);

    // ------------------------------------ PlayerObjectFukidashi.cpp ------------------------------------ //

    // Address: 0x0293D6AC
    virtual bool isDrawingCarryFukidashi();

    // Address: 0x0293D754
    virtual bool isEnableChibiYoshiFukidashi();

    // Address: 0x0293D908
    void resetPropelFukidashi();

    // ------------------------------------ PlayerObjectStf.cpp ------------------------------------ //

    // Address: 0x02950B50
    virtual bool updateEndingDanceImpl();

    // ------------------------------------ PlayerObjectRuiji.cpp ------------------------------------ //

    // Address: 0x0294A0D4
    virtual void onChangeRDashPhysics();

    // Address: 0x0294A130
    bool isEnableRDashLuigiPhysics() const override;
    // Address: 0x0294A168
    virtual bool isEnableRDashLuigiGravity();

    // ------------------------------------ Uncategorized ------------------------------------ //

    void executeMain() override;

    PlayerBgPointHIO* getBgPointData() override;

    f32 getStandHeadBgPointY() override;

    void checkBgCrossSub() override;
    void postBgCross() override;

    void clearJumpActionInfo() override;

    bool vf19C() override;

    void setFallDownDemo() override;

    void initializeDemoControl(bool carry_chibi_yoshi = true) override;

    bool isChange() override
    {
        return mChangeMgr.isChange();
    }

    bool setTimeOverDemo() override;
    bool vf504() override;

    void setDemoGoal(const sead::Vector2f& pos, f32 walk_target_pos_x, bool secret_exit) override;
    bool setHideNotGoalPlayer() override;
    bool vf51C(u32) override;
    bool setDoorDemo(Actor*, u32) override;
    void setGoalPoleCatchVoice() override;

    void executeDemoGoal_RideOffJump() override;
    void executeDemoGoal_Run() override;
    void executeDemoGoal_PreRun() override;
    void executeDemoGoal_Item() override;

    bool updateDemoKimePose(ClearType clear_type) override;
    void finDemoKimePose() override;

    bool isEnableDokanInStatus() override;
    bool isEnableMameDokanIn() override;

    f32 vf584() override;
    void getDokanWallBgPointData(ActorBgCollisionCheck::Sensor* p_sensor) override;

    void initDemoOutDokan() override;

    bool setOutDokanAngle() override;

    bool checkWalkNextAction() override;

    void setWaitActionAnm(AnmBlend blend) override;
    void setWalkActionAnm(AnmBlend blend) override;
    void walkActionInit_Wait(AnmBlend blend) override;

    void setSlipAction() override;

    bool checkSlipMoveEnd() override;

    bool setHipAttackOnEnemy(const sead::Vector3f& target_pos) override;
    void setHipBlockBreak() override;

    void setHipAttack_AttackStart() override;

    void setHipAttack_StandNormalEnd() override;

    bool checkCrouch() override;

    bool setHipAttackToKaniHangAction() override;

    bool vf7F4(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    void releaseFunsuiAction() override;

    f32 getCloudOffsetY() override;

    void setFallAction() override;

    f32 getJumpSpeed() override;
    f32 getMoveJumpSpeed() override;

    void setJumpSound(JumpSe jump_se_type) override;
    void vf8AC(bool) override;

    bool isNoDamage() override;
    bool isNoDamagePlayer() override;
    bool setNormalDamage(ActorCollisionCheck* p_cc) override;
    bool setPressBgDamage(DamageType type, bool) override;

    void clearStarCount() override { mStarCnt = 0; }
    s8 getStarCount() const override { return mStarCnt; }
    s8 calcStarCount(s32 max) override;
    void setStar(StarSet set_type = cStarSet_Default, s32 time = 0) override;
    void endStar() override;
    void setVirusStar(PlayerBase* p_other) override;

    EffectID getHipDropEffectID() override;
    EffectID getHipDropExEffectID() override;
    EffectID getHipDropSurfaceEffectID() override;
    EffectID getHipDropBlurEffectID() override;
    EffectID getSlipSmokeEffectID() override;
    EffectID getTurnBrakeEffectID() override;
    EffectID getTurnBrakeSmokeEffectID() override;
    EffectID getRunSmokeEffectID() override;
    EffectID getDashSmokeEffectID() override;
    EffectID getLandingSmokeEffectID() override;
    EffectID getWaterSplashEffectID(bool big) override;
    EffectID getWaterSplashSEffectID() override;
    EffectID getPoisonSplashEffectID(bool big) override;
    EffectID getLavaSplashEffectID(bool big) override;
    EffectID getLavaWaveSplashEffectID(bool big) override;

    void setSubjectCoinTimeUp() override;
    void setSubjectClear() override;
    void setSubjectFail() override;
    void setShadowFail() override;

    void setCarryFall(Actor*, s32) override;
    bool isSpinLiftUpEnable() override;
    void setSpinLiftUpActor(Actor* p_player) override;

    bool vf4F4() override;

    void throwCarryActor() override;

    bool isCarry() override;
    bool isLiftUp() override;
    bool isCarryMamePlayer() override;
    bool isLiftUpExceptMame() override;

    void resetLight() override;

    static s32 getParamPlayerNo(u32 param_0)
    {
        return param_0 & 0xF;
    }

    static PlayerMode getParamPlayerMode(u32 param_0)
    {
        return PlayerMode(param_0 >> 4 & 0xF);
    }

    static PlayerCharacter getParamPlayerCharacter(u32 param_0)
    {
        return PlayerCharacter(param_0 >> 8 & 0xF);
    }

    static PlayerModelBase::Type getParamPlayerModelType(u32 param_0)
    {
        switch (getParamPlayerCharacter(param_0))
        {
        case cPlayerCharacter_Mario:
        default:
            return PlayerModelBase::cType_Mario;
        case cPlayerCharacter_Luigi:
            return PlayerModelBase::cType_Luigi;
        case cPlayerCharacter_YellowToad:
            return PlayerModelBase::cType_YellowToad;
        case cPlayerCharacter_BlueToad:
            return PlayerModelBase::cType_BlueToad;
        case cPlayerCharacter_Nabbit:
            return PlayerModelBase::cType_Nabbit;
        case cPlayerCharacter_Mii:
            return PlayerModelBase::cType_Mii;
        }
    }

    static DirType getParamPlayerFacingDir(u32 param_0)
    {
        return DirType(param_0 >> 24 & 0xF);
    }

protected:
    PlayerModelMgr                  mModelMgr;
    ActorBgCollisionCheck::Sensor   _2760;
    PlayerMode                      mModePrev;                      // Maybe?
    PlayerMode                      mModeNext;                      // ^^^
    sead::Vector2f                  _2774;
    s32                             mStarTimer;
    s32                             mStarCnt;
    ActorUniqueID                   mCarryActorID;
    CarryStep                       mCarryStep;
    CarryStep                       mCarryStepPrev;
    f32                             mCarryStepTimer;
    f32                             mCarryStepLength;
    sead::SafeArray<
        s32,
        cInvalidKeyType_Num
    >                               mInvalidKeyTimer;               // [0] = all input, [1] = LR, [2] = shake
    sead::SafeArray<
        InvalidKeyTimerType,
        cInvalidKeyType_Num
    >                               mInvalidKeyTimerType;           // ^^^
    f32                             _27b0[2];
    f32                             _27b8[2];
    sead::Vector3f                  _27c0;
    u32                             _27cc;
    ScrollMode                      mScrollMode;
    PropelParts                     mPropelParts;
    Light                           mLight;
    s32                             _2998;
    s32                             _299c;
    u8                              _29a0;
    EventPlayerChange*              mpEventPlayerChange;
    ChangeMgr                       mChangeMgr;
    f32                             _29d0;
    u8                              _29d4;
    EventDown*                      mpEventDown;
    u8                              _29dc;
    bool                            mPlayerEatDieNow;
    sead::Vector3f                  _29e0;
    f32                             mEffectScale;
    DokanCannonType                 mDokanCannonType;
    sead::Vector2f                  mDemoInBossMoveTarget;
    u32                             mPMusaTransformStep;
    DirType                         _2a00;
    bool                            _2a04;
    u32                             _2a08;
    u32                             _2a0c;
    u32                             _2a10;
    u8                              _2a14;
    u32                             mWhichJump;
    u32                             _2a1c;
    u32                             _2a20;
    u32                             _2a24;
    u32                             _2a28;
    Angle                           mSpinRotStep;
    Angle                           mMissSpinAngle;
    u32                             _2a34;
    u32                             _2a38;
    f32                             _2a3c;
    u32                             _2a40;
    u32                             _2a44;
    f32                             _2a48;
    DirType                         mWallSlideDir;
    ActorUniqueID                   mLiftUpActorID;
    f32                             _2a54;
    f32                             mLiftUpOffsetRatio;
    u32                             _2a5c;
    s32                             mLiftUpCounter;
    f32                             mLiftUpOffsetScale;
    u8                              _2a68;
    s32                             _2a6c;
    s32                             _2a70;
    u32                             _2a74;
    s32                             _2a78;
    u8                              _2a7c;
    u32                             _2a80;
    u32                             _2a84;
    s32                             mBalloonHelpVoiceTimer;
    s32                             mBalloonCheckAllFadeTimer;
    u32                             mBalloonControllerConnectStatus;
    u32                             _2a94;
    sead::Vector3f                  _2a98;
    u32                             mCannonType;
    u32                             _2aa8;
    sead::Vector3f                  _2aac;
    f32                             _2ab8;
    f32                             _2abc;
    u32                             _2ac0;
    Angle                           _2ac4;
    u32                             _2ac8;
    s32                             _2acc;
    EffectObj                       _2ad0;
    u32                             _2b38;
    sead::Vector2f                  _2b3c;
    u8                              _2b44;
    u32                             _2b48;
    u32                             _2b4c;
    u32                             _2b50;
    u32                             _2b54;
    u32                             _2b58;
    f32                             _2b5c;
    sead::Vector2f                  _2b60;
    u32                             _2b68;
    f32                             _2b6c;
    f32                             _2b70;
    u32                             _2b74;
    u32                             _2b78;
    u8                              mPropelActionSubTimer;
    bool                            mPropelFlyTime;
    u32                             _2b80;
    s32                             _2b84;
    EffectObj                       mPropelFallSpinEffect;
    EffectObj                       _2bf0;
    Angle                           _2c58;
    EffectObj                       mSpinHipAttackEffect;
    u32                             _2cc4;
    u32                             _2cc8;
    ActorUniqueID                   mPlyIceActorID;
    QuakeMode                       mQuakeMode;
    s32                             mQuakeRumbleTimer;
    f32                             _2cd8;
    bool                            _2cdc;
    s32                             _2ce0;
    s32                             _2ce4;
    sead::BitFlag16                 mPenguinSwimFlag;
    u32                             mTarzanRopeBgType;              // 0 = ivy, 1 = kusari, 2 = rope(?)
    f32                             _2cf0;
    u32                             _2cf4;
    u32                             _2cf8;
    u32                             _2cfc;
    Angle                           mRopeAngleNow;
    Angle                           mRopeAngleDiffNow;
    Angle                           mRopeAngleOld;
    Angle                           mRopeAngleDiffOld;
    u32                             _2d10;
    f32                             mMameWallWalkSpeed;
    sead::Vector2f                  _2d18;
    u32                             _2d20;
    u32                             _2d24;
    u32                             _2d28;
    f32                             mKaniPosY;
    bool                            _2d30;
    u32                             mMusaJumpStep;
    f32                             _2d38;
    f32                             _2d3c;
    Angle                           _2d40;
    Angle                           _2d44;
    bool                            mMusaStartWallSlide;
    bool                            mMusaCanDoJump;
    u8                              _2d4a;
    u32                             _2d4c;
    u32                             _2d50;
    u32                             mMusaFlyStep;
    PlayerEatData                   mEatData;
    sead::Vector2f                  mEatPosOffset;
    bool                            _2d84;
    sead::Vector2f                  mEatPosReserve;
    DirType                         _2d90;
    ActorUniqueID                   mPlayerHangChildActorID;
    ActorUniqueID                   mPlayerHangParentActorID;
    u32                             _2d9c;
    sead::Matrixf                   mJrCrownMtx;
    u32                             _2dd0;
    u32                             mQuakeTimer;
    bool                            mQuakeEffectFlag;
    Effect                          mItemGetEffect1;
    Effect                          mItemGetEffect2;
    Effect                          mPowerUpEffect;
    EffectObj                       mSwimEffect;
    EffectObj                       mPaddleSwimEffectL;
    EffectObj                       mPaddleSwimEffectR;
    EffectObj                       _2fd4;
    EffectObj                       _303c;
    Effect                          mSpinJumpEffect;
    Effect                          mMissSpinJumpEffect;
    EffectObj                       _3124;
    EffectObj                       mMusaFlyEffect;
    s32                             mMusaFlyUpEffectIndex;
    sead::SafeArray<EffectObj, 2>   mMusaFlyUpEffectDoubleBuffer;
    u32                             mStarEffectStep;                // 0 = Idle, 1 = Active, 2 = Fading
    EffectObj                       mStarEffect;
    u32                             mPMusaEffectStep;               // ^^^
    EffectObj                       mPMusaEffect;
    u32                             mPMusaFlyEffectStep;            // ^^^
    EffectObj                       mPMusaFlyEffect;
    u32                             _340c;
    u32                             _3410;
    EffectObj                       _3414;
    PlyOrchestra                    mOrchestra;
    s32                             _3490;                          // Ending Dance related
    s32                             _3494;                          // ^^^
    sead::SafeArray<s32, 3>         _3498;                          // ^^^
    sead::BitFlag8                  _34a4;                          // ^^^
    s32                             mIdleCounter;                   // ^^^
    u32                             _34ac;                          // ^^^
    sead::SafeArray<s32, 5>         _34b0;                          // ^^^
    bool                            _34c4;                          // ^^^
    bool                            _34c5;                          // ^^^
    f32                             mJumpAnmRate;
    f32                             mJumpTimerF;
    s32                             mJumpAnmID;
    s32                             _34d4;                          // Some random timer
};
static_assert(sizeof(PlayerObject) == 0x34D8);
