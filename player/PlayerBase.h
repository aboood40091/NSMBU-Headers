#pragma once

#include <actor/Actor.h>
#include <actor/AttentionLookat.h>
#include <audio/GameAudio.h>
#include <collision/ActorBgCollisionPlayerCheck.h>
#include <effect/EffectObj.h>
#include <game/Quake.h>
#include <player/PlayerDrcTouchCB.h>
#include <player/PlayerEnum.h>
#include <player/PlayerKey.h>
#include <player/util/HipdropExEffect.h>
#include <state/FStateMgr.h>
#include <state/FStateVirtualID.h>

#include <container/seadRingBuffer.h>

class   ActorBoxBgCollision;
struct  PlayerBgPointHIO;
struct  PlayerGravityHIO;
class   PlayerModelBaseMgr;
struct  PlayerSpeedHIO;

class PlayerBase : public Actor // vtbl Address: 0x10166E84
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CCC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CD0
    SEAD_RTTI_OVERRIDE(PlayerBase, Actor)

public:
    // Address: 0x10166BC4
    static const f32 cFireShootFrame;

public:
    enum DamageType
    {
        cDamageType_Hit = 0, 
        cDamageType_Hit2,
        cDamageType_HitKnock,
        cDamageType_Hit3,
        cDamageType_Knock,
        cDamageType_Knock2,
        cDamageType_SmallKnock,
        cDamageType_SmallKnock2,
        cDamageType_SmallKnock3,
        cDamageType_Fire,           // Damages player first if he isn't small or mini, otherwise same as Fire2
        cDamageType_Fire2,          // Immediately kills the player regardless of the powerup
        cDamageType_Ice,            // Freezes player if he isn't small or mini, otherwise just kills him
        cDamageType_Ice2,           // Always freezes the player regardless of the powerup, never kills him
        cDamageType_Spark,
        cDamageType_Poison,
        cDamageType_Kill,           // Instant kill, no damage first
        cDamageType_DeathCloud,
        cDamageType_Eaten,          // Instant kill
        cDamageType_Eaten2,         // Damages player first(?) if he isn't small or mini, otherwise same as Eaten
        cDamageType_SteppedOn,      // i.e., by another player
        cDamageType_Num
    };

    enum Status
    {
        cStatus_1                   =   1,  // NSMBW: Bit 0x01
        cStatus_2,                          // NSMBW: Bit 0x7D

        cStatus_7                   =   7,  // NSMBW: Bit 0xB9

        cStatus_9                   =   9,

        cStatus_10                  =  10,  // Force-disable jump (accelY = 0)
        cStatus_11,

        cStatus_36                  =  36,  // NSMBW: Bit 0x13

        cStatus_46                  =  46,
        cStatus_47,                         // NSMBW: Bit 0x1A

        cStatus_60                  =  60,  // Disable block-hit bounce

        cStatus_63                  =  63,

        cStatus_71                  =  71,  // NSMBW: Bit 0x2D

        cStatus_93                  =  93,

        cStatus_97                  =  97,
        cStatus_98,                         // NSMBW: Bit 0x3B

        cStatus_105                 = 105,
        cStatus_106,

        cStatus_113                 = 113,  // NSMBW: Bit 0x4A

        cStatus_117                 = 117,
        cStatus_118,

        cStatus_122                 = 122,  // NSMBW: Bit 0x53
        cStatus_123,                        // Make visible next frame

        cStatus_127                 = 127,  // NSMBW: Bit 0x58 (Ride Nat target reached)
        cStatus_RideNat,                    // NSMBW: Bit 0x59

        cStatus_130                 = 130,  // NSMBW: Bit 0x5C
        cStatus_131,                        // NSMBW: Bit 0x5D

        cStatus_133                 = 133,  // NSMBW: Bit 0x5E
        cStatus_134,                        // NSMBW: Bit 0x61

        cStatus_136                 = 136,  // NSMBW: Bit 0x62
        cStatus_137,

        cStatus_138                 = 138,

        cStatus_141                 = 141,

        cStatus_146                 = 146,  // NSMBW: Bit 0x87
        cStatus_147,                        // NSMBW: Bit 0x88
        cStatus_148,                        // NSMBW: Bit 0x89

        cStatus_151                 = 151,  // NSMBW: Bit 0x8B
        cStatus_152,                        // NSMBW: Bit 0x8C
        cStatus_153,                        // NSMBW: Bit 0x8D

        cStatus_171                 = 171,

        cStatus_FollowMameKuribo    = 174,  // NSMBW: Bit 0xAC
        cStatus_Invisible,                  // NSMBW: Bit 0xBB
        cStatus_HideTemporarily,            // NSMBW: Bit 0xBC

        cStatus_178                 = 178,  // NSMBW: Bit 0xBE

        cStatus_209                 = 209,  // NSMBW: Bit 0x64
        cStatus_210,

        cStatus_244                 = 244,  // NSMBW: Bit 0x5F

        cStatus_250                 = 250,

        cStatus_255                 = 255,  // NSMBW: Bit 0x82
        cStatus_256,                        // NSMBW: Bit 0x83

        cStatus_270                 = 270,  // NSMBW: Bit 0x84

        cStatus_280                 = 280,  // NSMBW: Bit 0xCA

        cStatus_282                 = 282,

        cStatus_LastBit             = 286,  // Not sure if bit 287 is used
        cStatus_BitNum,
        cStatus_MaxBitNum = (cStatus_BitNum + 31) / 32 * 32
    };

    enum BgCross
    {
        cBgCross_IsFoot = 0,            // NSMBW Bit: 0x00
        cBgCross_IsHead,                // NSMBW Bit: 0x01

        cBgCross_IsWallPressL = 3,
        cBgCross_IsWallPressR,
        cBgCross_IsWallTouchL,          // NSMBW Bit: 0x05
        cBgCross_IsWallTouchR,          // NSMBW Bit: 0x06

        cBgCross_WallWalkEnableL = 11,
        cBgCross_WallWalkEnableR,
        cBgCross_IsWatterPillarL,       // Maybe?
        cBgCross_IsWatterPillarR,       // ^^^

        cBgCross_IsWater = 18,

        cBgCross_IsSinkSand = 34,
        cBgCross_IsSlightlyInsideSinkSand,
        cBgCross_IsPartiallySubmergedInSinkSand,
        cBgCross_IsCompletelySubmergedInSinkSand,

        cBgCross_IsOnHorizontalPipe = 46,

        cBgCross_IsSaka = 48,

        cBgCross_55 = 55,

        cBgCross_IsPole = 58,

        cBgCross_HitBgActorYuka = 73,

        cBgCross_LastBit = 76,          // Explicitly checked in function 0x029586DC
        cBgCross_BitNum,
        cBgCross_MaxBitNum = (cBgCross_BitNum + 31) / 32 * 32
    };

    static const s32 cOldBgCrossFootNum = 10;

    enum BgAttr
    {
        cBgAttr_Rock = 0,
        cBgAttr_Snow,
        cBgAttr_Sand,
        cBgAttr_Ice,
        cBgAttr_Dirt,
        cBgAttr_Water,
        cBgAttr_Cloud,
        cBgAttr_SandFunsui, // i.e., sand pillar
        cBgAttr_Manta,      // Used for beanstalk
        cBgAttr_Beach,
        cBgAttr_Carpet,
        cBgAttr_Leaf,
        cBgAttr_Wood,
        cBgAttr_WaterPillar,
        cBgAttr_Num
    };
    static_assert(cBgAttr_Num == 14);
    static_assert(sizeof(BgAttr) == 4);

    enum DokanDir
    {
        cDokanDir_Up = 0,   // i.e., Player should hold **up**    & the pipe is facing **down**
        cDokanDir_Down,     // i.e., Player should hold **down**  & the pipe is facing **up**
        cDokanDir_Left,     // i.e., Player should hold **left**  & the pipe is facing **right**
        cDokanDir_Right,    // i.e., Player should hold **right** & the pipe is facing **left**
        cDokanDir_Num
    };
    static_assert(cDokanDir_Num == 4);
    static_assert(sizeof(DokanDir) == 4);

    enum DokanType
    {
        cDokanType_Invalid = 0,
        cDokanType_Normal,
        cDokanType_ForwardPipe      // Broken (most likely leftover from NSMBW that wasn't fully stripped)
    };
    static_assert(sizeof(DokanType) == 4);

    struct JumpInf;

    enum WalkAction
    {
        cWalkAction_Wait,
        cWalkAction_Move
    };
    static_assert(sizeof(WalkAction) == 4);

    enum HipAction
    {
        cHipAction_Ready = 0,
        cHipAction_AttackStart,
        cHipAction_AttackFall,
        cHipAction_Ground,
        cHipAction_StandNormal,
        cHipAction_StandNormalEnd,
        cHipAction_ToStoop
    };
    static_assert(sizeof(HipAction) == 4);

    enum JumpAction
    {
        cJumpAction_TakeOff = 0,
        cJumpAction_Air
    };
    static_assert(sizeof(JumpAction) == 4);

    enum PoleAction
    {
        cPoleAction_Start = 0,
        cPoleAction_Wait,
        cPoleAction_Up,
        cPoleAction_Down
    };
    static_assert(sizeof(PoleAction) == 4);

    enum VineAction
    {
        cVineAction_Ivy     = 0,
        cVineAction_Net,
        cVineAction_Attack,
        cVineAction_Roll
    };
    static_assert(sizeof(VineAction) == 4);

    enum CrouchAction
    {
        cCrouchAction_Ground = 0,
        cCrouchAction_Water
    };
    static_assert(sizeof(CrouchAction) == 4);

    enum SlipAction
    {
        cSlipAction_Move = 0,
        cSlipAction_1,
        cSlipAction_ToStoop,
        cSlipAction_ToEnd
    };
    static_assert(sizeof(SlipAction) == 4);

    enum CloudAction
    {
        cCloudAction_Idle,
        cCloudAction_Move,
        cCloudAction_Crouch,
        cCloudAction_CrouchEnd,
        cCloudAction_FireCreate,
        cCloudAction_FireCreateEnd,
        cCloudAction_6,
        cCloudAction_Throw,
        cCloudAction_ThrowEnd
    };
    static_assert(sizeof(CloudAction) == 4);

    enum SwimAction
    {
        cSwimAction_Swim = 0,
        cSwimAction_Walk,
        cSwimAction_Penguin,
        cSwimAction_FireBall,
        cSwimAction_SwimWithChibi,
        cSwimAction_SwimWithChibi_CantSpinMaybe
    };
    static_assert(sizeof(SwimAction) == 4);

    enum JumpDaiAction
    {
        cJumpDaiAction_0 = 0,
        cJumpDaiAction_1
    };
    static_assert(sizeof(JumpDaiAction) == 4);

    enum PlayerJumpDaiAction
    {
        cPlayerJumpDaiAction_0 = 0,
        cPlayerJumpDaiAction_1
    };
    static_assert(sizeof(PlayerJumpDaiAction) == 4);

    enum FireAction
    {
        cFireAction_0 = 0,
        cFireAction_1
    };
    static_assert(sizeof(FireAction) == 4);

    enum ThrowAction
    {
        cThrowAction_0 = 0,
        cThrowAction_1,
        cThrowAction_2
    };
    static_assert(sizeof(ThrowAction) == 4);

    enum WallSlideAction
    {
        cWallSlideAction_Normal = 0,
        cWallSlideAction_MusasabiSlide
    };
    static_assert(sizeof(WallSlideAction) == 4);

    enum CarryPlayerAction
    {
        cCarryPlayerAction_Move = 0,
        cCarryPlayerAction_Crouch,
        cCarryPlayerAction_2,
        cCarryPlayerAction_Fire,
        cCarryPlayerAction_FireEnd
    };
    static_assert(sizeof(CarryPlayerAction) == 4);

    enum FlyDamageAction
    {
        cFlyDamageAction_0 = 0,
        cFlyDamageAction_1,
        cFlyDamageAction_2,
        cFlyDamageAction_3,
        cFlyDamageAction_4,
        cFlyDamageAction_5,
        cFlyDamageAction_6
    };
    static_assert(sizeof(FlyDamageAction) == 4);

    enum BalloonAction
    {
        cBalloonAction_0 = 0,
        cBalloonAction_1,
        cBalloonAction_2,
        cBalloonAction_3,
        cBalloonAction_4,
        cBalloonAction_5,
        cBalloonAction_6
    };
    static_assert(sizeof(BalloonAction) == 4);

    enum CannonJumpAction
    {
        cCannonJumpAction_0 = 0,
        cCannonJumpAction_1,
        cCannonJumpAction_2
    };
    static_assert(sizeof(CannonJumpAction) == 4);

    enum PropelAction
    {
        cPropelAction_BigFly = 0,
        cPropelAction_Fly,
        cPropelAction_Fall
    };
    static_assert(sizeof(PropelAction) == 4);

    enum SpinHipAttackAction
    {
        cSpinHipAttackAction_Fall = 0,
        cSpinHipAttackAction_Land
    };
    static_assert(sizeof(SpinHipAttackAction) == 4);

    enum PenguinSlideAction
    {
        cPenguinSlideAction_Move,
        cPenguinSlideAction_1,
        cPenguinSlideAction_ToCrouch,
        cPenguinSlideAction_StandUp
    };
    static_assert(sizeof(PenguinSlideAction) == 4);

    enum BalloonChibiYoshiAction
    {
        cBalloonChibiYoshiAction_Fly = 0,
        cBalloonChibiYoshiAction_FallMaybe,
        cBalloonChibiYoshiAction_PreFallIdk
    };
    static_assert(sizeof(BalloonChibiYoshiAction) == 4);

    enum TarzanRopeAction
    {
        cTarzanRopeAction_Start = 0,
        cTarzanRopeAction_Wait,
        cTarzanRopeAction_Up,
        cTarzanRopeAction_Down,
        cTarzanRopeAction_HasigoMove,
        cTarzanRopeAction_5,
        cTarzanRopeAction_6
    };
    static_assert(sizeof(TarzanRopeAction) == 4);

    enum KaniAction
    {
        cKaniAction_Walk = 0,
        cKaniAction_HangInit,
        cKaniAction_JumpHangInit,
        cKaniAction_Hang,
        cKaniAction_HangFall,
        cKaniAction_HangUp,
        cKaniAction_HangUpVine
    };
    static_assert(sizeof(KaniAction) == 4);

    enum HangAction
    {
        cHangAction_Start = 0,
        cHangAction_Wait,
        cHangAction_Move
    };
    static_assert(sizeof(HangAction) == 4);

    union ActionType
    {
        WalkAction              walk;
        HipAction               hip;
        JumpAction              jump;
        PoleAction              pole;
        VineAction              vine;
        CrouchAction            crouch;
        SlipAction              slip;
        CloudAction             cloud;
        SwimAction              swim;
        JumpDaiAction           jump_dai;
        PlayerJumpDaiAction     player_jump_dai;
        FireAction              fire;
        ThrowAction             throw_;
        WallSlideAction         wall_slide;
        CarryPlayerAction       carry_player;
        FlyDamageAction         fly_damage;
        BalloonAction           balloon;
        CannonJumpAction        cannon_jump;
        PropelAction            propel;
        SpinHipAttackAction     spin_hip_attack;
        PenguinSlideAction      penguin_slide;
        BalloonChibiYoshiAction balloon_chibi_yoshi;
        TarzanRopeAction        tarzan_rope;
        KaniAction              kani;
        HangAction              hang;
        // And still many more...
    };
    static_assert(sizeof(ActionType) == 4);

    enum FunsuiType
    {
        cFunsuiType_Sand = 0,
        cFunsuiType_Water
    };
    static_assert(sizeof(FunsuiType) == 4);

    enum DemoType
    {
    };

    enum AnmBlend
    {
        cAnmBlend_Disable = 0,
        cAnmBlend_Enable
    };

    enum StarSet
    {
        cStarSet_Num = 3
    };

    enum BounceType
    {
        cBounceType_Normal = 0,
        cBounceType_1,
        cBounceType_2
    };

    enum JumpSe
    {
        cJumpSe_None = 0,
        cJumpSe_Normal,
        cJumpSe_High
    };
    static_assert(sizeof(JumpSe) == 4);

    // Address: 0x10166E60
    static const f32 cDirSpeed[cDirType_NumX];
    // Address: 0x10166E68
    static const f32 cJumpSpeed;                    // 3.628f
    // Address: 0x10166E74
    static const f32 cMaxFallSpeed;                 // -4.0f
    // Address: 0x10166E78
    static const f32 cMaxFallSpeed_Foot;            // -2.0f
    // Address: 0x10166E7C
    static const f32 cTurnPowerUpRate;              // 3.0f

public:
    // Address: 0x028F23C0
    PlayerBase(const ActorCreateParam& param);
    // Address: 0x028F2CA8
    virtual ~PlayerBase();

protected:
    // Address: 0x028F2E78
    Result create_() override;
    // Address: 0x028F2F0C
    bool preExecute_() override;
    // Address: 0x028F3078
    bool execute_() override;
    // Address: 0x028F3534
    void postExecute_(MainState state) override;
    // Address: 0x028F36BC
    bool preDraw_() override;

    // Address: 0x028F372C
    void blockHitInit_() override;

public:
    ActorBgCollisionCheck* getBgCheck() override
    {
        return &mBgCheckPlayer;
    }

    virtual void executeMain() = 0;
    virtual void executeLastPlayer() = 0;
    virtual void executeLastAll() = 0;

    virtual void setPlayerMode(PlayerMode mode, bool temporary)
    {
        setPlayerModeImpl(mode, temporary);
    }

    virtual void setPlayerModeImpl(PlayerMode mode, bool temporary) = 0;

    virtual bool isEnableRDashLuigiPhysics() const
    {
        return false;
    }

    PlayerTallType getTallType()
    {
        return getTallType(mMode);
    }

    virtual PlayerTallType getTallType(PlayerMode mode) = 0;

    virtual void getMaskPos(sead::Vector3f& pos) = 0;
    virtual void getMaskCaveCheckPos(sead::Vector3f* p_pos, f32* p_y_offset) = 0;

    // Address: 0x028F3854
    virtual bool vf154();

    virtual PlayerBgPointHIO* getBgPointData() = 0;
    virtual f32 getStandHeadBgPointY() = 0;

    virtual void checkBgCrossSub() = 0;
    virtual void postBgCross() = 0;

    virtual void clearJumpActionInfo() = 0;

    // Address: 0x028F9858
    virtual void initCollision(const ActorCollisionCheck::CollisionData& cc_data_react, const ActorCollisionCheck::CollisionData& cc_data_attack);
    // Address: 0x028F98FC
    virtual void releaseCcData();
    // Address: 0x028F9A78
    virtual void clearCcData();

    virtual bool vf19C() = 0;

    // Address: 0x028FA8D8
    virtual void initStampReduction();
    // Address: 0x028FA910
    virtual void calcJumpDaiReductionScale(s32, s32);
    // Address: 0x028FA97C
    virtual void setReductionBoyon();

    // Address: 0x028FA990
    virtual bool getHeadTopPos(sead::Vector3f& pos);

    // Address: 0x028F93F8
    virtual void vf1C4();

    virtual void setFallDownDemo() = 0;

    virtual bool setBalloonInDispOut(s32) = 0;
    virtual bool vf1DC() = 0;

    // Address: 0x028FD318
    virtual void setCreate(const sead::Vector3f& pos, s32 next_goto_type, s32 dir);
    // Address: 0x028FD394
    virtual void reset();

    // Address: 0x028FD684
    virtual void initialNormal(s32 next_goto_type);
    // Address: 0x028FDD4C
    virtual void initialDoor(s32 next_goto_type);
    // Address: 0x028FD6D0
    virtual void initialDokan(s32 next_goto_type);
    // Address: 0x028FD7B4
    virtual void initialFall(s32 next_goto_type);
    // Address: 0x028FD800
    virtual void initialHipAttack(s32 next_goto_type);
    // Address: 0x028FD84C
    virtual void initialSlip(s32 next_goto_type);
    // Address: 0x028FDD50
    virtual void initialJump(s32 next_goto_type);
    // Address: 0x028FDD54
    virtual void initialVine(s32 next_goto_type);
    // Address: 0x028FDD58
    virtual void initialShiroBoss(s32 next_goto_type);
    // Address: 0x028FDD5C
    virtual void initialFinalBoss(s32 next_goto_type);
    // Address: 0x028FDD60
    virtual void initialUnk10(s32 next_goto_type);
    // Address: 0x028FD8A4
    virtual void initialUnk27(s32 next_goto_type);
    // Address: 0x028FDD64
    virtual void initialBoxingKoopaJr(s32 next_goto_type);
    // Address: 0x028FDD68
    virtual void initialTitle(s32 next_goto_type);

    // StateID_DemoCreate           Address: 0x1022A008
    // initializeState_DemoCreate   Address: 0x028FD8B4
    // executeState_DemoCreate      Address: 0x028FD8B8
    // finalizeState_DemoCreate     Address: 0x028FDD6C
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoCreate)
    // StateID_DemoNone         Address: 0x1022A02C
    // initializeState_DemoNone Address: 0x028FAC40
    // executeState_DemoNone    Address: 0x028FACDC
    // finalizeState_DemoNone   Address: 0x028FD244
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoNone)
    // StateID_DemoState3           Address: 0x1022A050
    // initializeState_DemoState3   Address: 0x028FD248
    // executeState_DemoState3      Address: 0x028FD24C
    // finalizeState_DemoState3     Address: 0x028FD250
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoState3)
    // StateID_DemoState4           Address: 0x1022A074
    // initializeState_DemoState4   Address: 0x028FAEB0
    // executeState_DemoState4      Address: 0x028FAFB4
    // finalizeState_DemoState4     Address: 0x028FB05C
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoState4)
    // StateID_DemoGoal         Address: 0x1022A098
    // initializeState_DemoGoal Address: 0x02901D7C
    // executeState_DemoGoal    Address: 0x02902988
    // finalizeState_DemoGoal   Address: 0x02902AE0
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoGoal)
    // StateID_DemoStartWait            Address: 0x1022A0BC
    // initializeState_DemoStartWait    Address: 0x028FD938
    // executeState_DemoStartWait       Address: 0x028FD9E0
    // finalizeState_DemoStartWait      Address: 0x028FDD70
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoStartWait)
    // StateID_DemoWait         Address: 0x1022A0E0
    // initializeState_DemoWait Address: 0x028FDAAC
    // executeState_DemoWait    Address: 0x028FDB30
    // finalizeState_DemoWait   Address: 0x028FDD18
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoWait)
    // StateID_DemoOutDokanU            Address: 0x1022A104
    // initializeState_DemoOutDokanU    Address: 0x028FDFB4
    // executeState_DemoOutDokanU       Address: 0x028FE1E4
    // finalizeState_DemoOutDokanU      Address: 0x028FE21C
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoOutDokanU)
    // StateID_DemoOutDokanD            Address: 0x1022A128
    // initializeState_DemoOutDokanD    Address: 0x028FE220
    // executeState_DemoOutDokanD       Address: 0x028FE228
    // finalizeState_DemoOutDokanD      Address: 0x028FE22C
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoOutDokanD)
    // StateID_DemoOutDokanR            Address: 0x1022A14C
    // initializeState_DemoOutDokanR    Address: 0x028FE3B4
    // executeState_DemoOutDokanR       Address: 0x028FE67C
    // finalizeState_DemoOutDokanR      Address: 0x028FE680
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoOutDokanR)
    // StateID_DemoOutDokanL            Address: 0x1022A170
    // initializeState_DemoOutDokanL    Address: 0x028FE684
    // executeState_DemoOutDokanL       Address: 0x028FE68C
    // finalizeState_DemoOutDokanL      Address: 0x028FE690
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoOutDokanL)
    // StateID_DemoOutDokanRollUD           Address: 0x1022A194
    // initializeState_DemoOutDokanRollUD   Address: 0x028FE7E4
    // executeState_DemoOutDokanRollUD      Address: 0x028FE824
    // finalizeState_DemoOutDokanRollUD     Address: 0x028FEBD0
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoOutDokanRollUD)
    // StateID_DemoOutDokanRollLR           Address: 0x1022A1B8
    // initializeState_DemoOutDokanRollLR   Address: 0x028FEBD4
    // executeState_DemoOutDokanRollLR      Address: 0x028FEC34
    // finalizeState_DemoOutDokanRollLR     Address: 0x028FEDC4
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoOutDokanRollLR)
    // StateID_DemoInDokanU         Address: 0x1022A1DC
    // initializeState_DemoInDokanU Address: 0x028FEDC8
    // executeState_DemoInDokanU    Address: 0x028FF344
    // finalizeState_DemoInDokanU   Address: 0x028FF3A8
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoInDokanU)
    // StateID_DemoInDokanD         Address: 0x1022A200
    // initializeState_DemoInDokanD Address: 0x028FF3AC
    // executeState_DemoInDokanD    Address: 0x028FF4B8
    // finalizeState_DemoInDokanD   Address: 0x028FF4BC
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoInDokanD)
    // StateID_DemoInDokanR         Address: 0x1022A224
    // initializeState_DemoInDokanR Address: 0x028FF54C
    // executeState_DemoInDokanR    Address: 0x028FF554
    // finalizeState_DemoInDokanR   Address: 0x028FF558
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoInDokanR)
    // StateID_DemoInDokanL         Address: 0x1022A248
    // initializeState_DemoInDokanL Address: 0x028FF55C
    // executeState_DemoInDokanL    Address: 0x028FF564
    // finalizeState_DemoInDokanL   Address: 0x028FF568
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoInDokanL)
    // StateID_DemoOutDoor          Address: 0x1022A26C
    // initializeState_DemoOutDoor  Address: 0x028FD254
    // executeState_DemoOutDoor     Address: 0x028FD258
    // finalizeState_DemoOutDoor    Address: 0x028FD25C
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoOutDoor)
    // StateID_DemoInDoor           Address: 0x1022A290
    // initializeState_DemoInDoor   Address: 0x028FD260
    // executeState_DemoInDoor      Address: 0x028FD264
    // finalizeState_DemoInDoor     Address: 0x028FD268
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoInDoor)
    // StateID_DemoNextGotoBlock            Address: 0x1022A2B4
    // initializeState_DemoNextGotoBlock    Address: 0x028FB068
    // executeState_DemoNextGotoBlock       Address: 0x028FB404
    // finalizeState_DemoNextGotoBlock      Address: 0x028FB51C
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoNextGotoBlock)
    // StateID_DemoDown         Address: 0x1022A2D8
    // initializeState_DemoDown Address: 0x02901CF8
    // executeState_DemoDown    Address: 0x02901CFC
    // finalizeState_DemoDown   Address: 0x02901D00
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoDown)
    // StateID_DemoControl          Address: 0x1022A2FC
    // initializeState_DemoControl  Address: 0x02900350
    // executeState_DemoControl     Address: 0x02900420
    // finalizeState_DemoControl    Address: 0x02900644
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoControl)
    // StateID_DemoState23          Address: 0x1022A320
    // initializeState_DemoState23  Address: 0x029031E8
    // executeState_DemoState23     Address: 0x02903288
    // finalizeState_DemoState23    Address: 0x0290338C
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoState23)
    // StateID_DemoState24          Address: 0x1022A344
    // initializeState_DemoState24  Address: 0x0290339C
    // executeState_DemoState24     Address: 0x029033BC
    // finalizeState_DemoState24    Address: 0x0290340C
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoState24)
    // StateID_DemoState25          Address: 0x1022A368
    // initializeState_DemoState25  Address: 0x02903F24
    // executeState_DemoState25     Address: 0x02903F28
    // finalizeState_DemoState25    Address: 0x02903F2C
    DECLARE_STATE_ID_VIRTUAL_FUNC_BASE(PlayerBase, DemoState25)

    virtual void initializeDemoControl(bool carry_chibi_yoshi) = 0;

    // Address: 0x028FB6EC
    virtual void onDemoType(DemoType type);
    // Address: 0x028FB704
    virtual void offDemoType(DemoType type);
    // Address: 0x028FB71C
    virtual void offDemoMode();
    // Address: 0x028FB728
    virtual bool isDemoMode() const;
    // Address: 0x028FB738
    virtual bool isDemoType(DemoType type);

    virtual bool isChange() = 0;

    virtual bool vf4F4()
    {
        return false;
    }

    virtual bool setTimeOverDemo() = 0;

    virtual bool vf504() = 0;
    virtual void vf50C(const sead::Vector2f& pos, f32 walk_target_pos_x, bool secret_exit) = 0; // Goal-related
    virtual bool vf514() = 0;
    virtual bool vf51C(u32) = 0;
    virtual bool setDoorDemo(Actor*, u32) = 0;
    virtual void setGoalPoleCatchVoice() = 0;

    // Address: 0x02902ECC
    virtual void vf534();

    virtual void executeDemoGoal_RideOffJump() = 0;
    virtual void executeDemoGoal_Run() = 0;
    virtual void executeDemoGoal_PreRun() = 0;
    virtual void executeDemoGoal_Item() = 0;
    virtual bool setGoalPutOnCapAnm(s32 course_clear_type) = 0;
    virtual void finDemoKimePose() = 0;

    virtual bool isEnableDokanInStatus() = 0;
    virtual bool isEnableMameDokanIn() = 0;     // I think...?

    // Address: 0x028FFFD4
    virtual bool setDokanIn(DokanDir dir);

    virtual f32 vf584() = 0;
    virtual void vf58C(ActorBgCollisionCheck::Sensor&) = 0;

    // Address: 0x02900088
    virtual void setDokanWaitAnm(bool);

    virtual void initDemoOutDokan() = 0;
    virtual bool setDokanOutAngle() = 0;
    virtual void initDemoInDokan(DokanDir dir) = 0;

    // Address: Deleted
    virtual void vf5B4();

    // Bounce player
    virtual bool bouncePlayer1(f32 speed_y, f32 speed_F, bool, BounceType bounce_type, JumpSe jump_se_type) = 0;   // Does lots of checks that can cancel the bounce, calls bouncePlayer2 otherwise
    virtual bool bouncePlayer2(f32 speed_y, f32 speed_F, bool, BounceType bounce_type, JumpSe jump_se_type) = 0;

    // StateID_None         Address: 0x1022A484
    // initializeState_None Address: 0x02908AE4
    // executeState_None    Address: 0x02908AE8
    // finalizeState_None   Address: 0x02908AEC
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, None)
    // StateID_Walk         Address: 0x1022A4A8
    // initializeState_Walk Address: 0x02908AF0
    // executeState_Walk    Address: 0x02906488
    // finalizeState_Walk   Address: 0x02906530
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Walk)
    // StateID_Jump         Address: 0x1022A4CC
    // initializeState_Jump Address: 0x02908C30
    // executeState_Jump    Address: 0x02908CC8
    // finalizeState_Jump   Address: 0x02908D70
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Jump)
    // StateID_Fall         Address: 0x1022A4F0
    // initializeState_Fall Address: 0x02908E34
    // executeState_Fall    Address: 0x02908F00
    // finalizeState_Fall   Address: 0x02908F1C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Fall)
    // StateID_Land         Address: 0x1022A514
    // initializeState_Land Address: 0x02909208
    // executeState_Land    Address: 0x0290920C
    // finalizeState_Land   Address: 0x02909210
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Land)
    // StateID_Crouch           Address: 0x1022A538
    // initializeState_Crouch   Address: 0x02908AF4
    // executeState_Crouch      Address: 0x02908AF8
    // finalizeState_Crouch     Address: 0x02908AFC
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Crouch)
    // StateID_SitJump          Address: 0x1022A55C
    // initializeState_SitJump  Address: 0x02909214
    // executeState_SitJump     Address: 0x02909218
    // finalizeState_SitJump    Address: 0x0290921C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, SitJump)
    // StateID_Slip         Address: 0x1022A580
    // initializeState_Slip Address: 0x0290AB70
    // executeState_Slip    Address: 0x0290B418
    // finalizeState_Slip   Address: 0x0290B6E4
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Slip)
    // StateID_Turn         Address: 0x1022A5A4
    // initializeState_Turn Address: 0x02908B00
    // executeState_Turn    Address: 0x02908B04
    // finalizeState_Turn   Address: 0x02908B08
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Turn)
    // StateID_HipAttack            Address: 0x1022A5C8
    // initializeState_HipAttack    Address: 0x02909E44
    // executeState_HipAttack       Address: 0x02909EE4
    // finalizeState_HipAttack      Address: 0x02909FBC
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, HipAttack)
    // StateID_Funsui           Address: 0x1022A5EC
    // initializeState_Funsui   Address: 0x02906540
    // executeState_Funsui      Address: 0x02906650
    // finalizeState_Funsui     Address: 0x029068B0
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Funsui)
    // StateID_Cloud            Address: 0x1022A610
    // initializeState_Cloud    Address: 0x029068D8
    // executeState_Cloud       Address: 0x02908B0C
    // finalizeState_Cloud      Address: 0x02906970
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Cloud)
    // StateID_Cloud2           Address: 0x1022A634
    // initializeState_Cloud2   Address: 0x029069B4
    // executeState_Cloud2      Address: 0x02908B10
    // finalizeState_Cloud2     Address: 0x029069E8
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Cloud2)   // Unused, but functions almost exactly the same as Cloud
    // StateID_Swim         Address: 0x1022A658
    // initializeState_Swim Address: 0x02908B14
    // executeState_Swim    Address: 0x02908B18
    // finalizeState_Swim   Address: 0x02908B1C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Swim)
    // StateID_JumpDai          Address: 0x1022A67C
    // initializeState_JumpDai  Address: 0x0290928C
    // executeState_JumpDai     Address: 0x02909368
    // finalizeState_JumpDai    Address: 0x02909404
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, JumpDai)
    // StateID_PlayerJumpDai            Address: 0x1022A6A0
    // initializeState_PlayerJumpDai    Address: 0x02909524
    // executeState_PlayerJumpDai       Address: 0x02909654
    // finalizeState_PlayerJumpDai      Address: 0x02909BA8
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, PlayerJumpDai)
    // StateID_WaitJump         Address: 0x1022A6C4
    // initializeState_WaitJump Address: 0x02908F58
    // executeState_WaitJump    Address: 0x02908FC0
    // finalizeState_WaitJump   Address: 0x02909038
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, WaitJump)
    // StateID_AnimePlay            Address: 0x1022A6E8
    // initializeState_AnimePlay    Address: 0x02900E58
    // executeState_AnimePlay       Address: 0x029017FC
    // finalizeState_AnimePlay      Address: 0x02901A04
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, AnimePlay)

    virtual bool checkWalkNextAction() = 0;

    virtual void setWaitActionAnm(AnmBlend blend) = 0;
    virtual void setWalkActionAnm(AnmBlend blend) = 0;
    virtual void walkActionInit_Wait(AnmBlend blend) = 0;

    virtual bool isWaitFrameCountMax()
    {
        return false;
    }

    virtual void setSlipAction() = 0;
    virtual bool vf7AC() = 0;

    virtual bool setHipAttackOnEnemy(const sead::Vector3f&) = 0;
    virtual void setHipBlockBreak() = 0;
    virtual void setHipAttack_AttackStart() = 0;
    virtual void setHipAttack_StandNormalEnd() = 0;

    virtual bool checkCrouch() = 0;
    // Address: 0x029071E8
    virtual bool setCancelCrouch();
    // Address: 0x029072EC
    virtual bool setCrouchJump();

    virtual bool vf7EC() = 0;

    virtual bool vf7F4(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) = 0;

    virtual void releaseFunsuiAction() = 0;

    virtual f32 getCloudOffsetY() = 0;

    virtual void throwCarryActor()
    {
    }

    // Address: 0x02901A68
    virtual void DemoAnm_Unk10();

    // Address: 0x028F3ED0
    virtual void calcTimerProc();

    // Address: 0x028F3FB4
    virtual void startQuakeShock(Quake::ShockType shock_type);
    // Address: 0x028F3FD8
    virtual void startPatternRumble(const char* pattern);

    virtual bool isCarry()
    {
        return false;
    }

    virtual bool isLiftUp()
    {
        return false;
    }

    virtual bool isCarryMamePlayer()
    {
        return false;
    }

    virtual bool isLiftUpExceptMame()
    {
        return false;
    }

    virtual void setZPosition() = 0;
    virtual void setZPosition(f32 z) = 0;
    virtual void setZPositionDirect(f32 z) = 0;
    virtual void offZPosSetNone() = 0;

    virtual bool isFaceRot()
    {
        return false;
    }

    virtual PlayerGravityHIO* getGravityData()
    {
        return mpGravityData;
    }

    // Address: 0x02904CF4
    virtual void maxFallSpeedSet();

    virtual void setFallAction() = 0;

    virtual f32 getJumpSpeed() = 0;
    virtual f32 vf89C() = 0;
    virtual void setJumpSound(JumpSe jump_se_type) = 0;
    virtual void vf8AC(bool) = 0;

    virtual bool isNoDamage() = 0;
    virtual bool isNoDamagePlayer() = 0;  // Only used by Yoshi, called at 0x0295FAF8
    virtual bool setNormalDamage(ActorCollisionCheck* p_cc) = 0;
    virtual bool setDamage(Actor* p_actor, DamageType type) = 0;
    virtual bool setForcedDamage(Actor* p_actor, DamageType type) = 0;
    virtual bool setFlyDamage(DamageType type, s32 dir, bool, bool, f32 speed_F, f32 speed_y) = 0;
    virtual bool setDamage2(Actor* p_actor, DamageType type) = 0;
    virtual bool setPressBgDamage(DamageType type, bool) = 0;

    virtual void clearStarCount() = 0;
    virtual s8 getStarCount() const = 0;
    virtual s8 calcStarCount(s32 max) = 0;
    virtual void setStar(StarSet, s32 time) = 0;
    virtual bool isStar() const = 0;
    virtual void endStar() = 0;
    virtual void setVirusStar(PlayerBase* p_other) = 0;

    virtual void resetLight() // Not exactly sure
    {
        onStatus(cStatus_133);
    }

    virtual EffectID getHipDropEffectID() = 0;
    virtual EffectID getHipDropExEffectID() = 0;
    virtual EffectID getHipDropSurfaceEffectID() = 0;
    virtual EffectID getHipDropBlurEffectID() = 0;
    virtual EffectID getSlipSmokeEffectID() = 0;
    virtual EffectID getTurnBrakeEffectID() = 0;
    virtual EffectID getTurnBrakeSmokeEffectID() = 0;
    virtual EffectID getRunSmokeEffectID() = 0;
    virtual EffectID getDashSmokeEffectID() = 0;
    virtual EffectID getLandingSmokeEffectID() = 0;
    virtual EffectID getWaterSplashEffectID(bool big) = 0;
    virtual EffectID getWaterSplashSEffectID() = 0;
    virtual EffectID getPoisonSplashEffectID(bool big) = 0;
    virtual EffectID getLavaSplashEffectID(bool big) = 0;
    virtual EffectID getLavaWaveSplashEffectID(bool) = 0;

    // Address: 0x02904284
    virtual void setTurnSmokeEffect(bool with_brake);

    // StateID_ChallengeState1          Address: 0x1022A3B8
    // initializeState_ChallengeState1  Address: 0x02903F30
    // executeState_ChallengeState1     Address: 0x02903504
    // finalizeState_ChallengeState1    Address: 0x02903F34
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, ChallengeState1)
    // StateID_ChallengeState2          Address: 0x1022A3DC
    // initializeState_ChallengeState2  Address: 0x02903628
    // executeState_ChallengeState2     Address: 0x02903638
    // finalizeState_ChallengeState2    Address: 0x02903F38
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, ChallengeState2)
    // StateID_ChallengeState3          Address: 0x1022A400
    // initializeState_ChallengeState3  Address: 0x02903F3C
    // executeState_ChallengeState3     Address: 0x0290363C
    // finalizeState_ChallengeState3    Address: 0x02903F40
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, ChallengeState3)
    // StateID_ChallengeState4          Address: 0x1022A424
    // initializeState_ChallengeState4  Address: 0x02903654
    // executeState_ChallengeState4     Address: 0x02903778
    // finalizeState_ChallengeState4    Address: 0x0290379C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, ChallengeState4)
    // StateID_ChallengeState5          Address: 0x1022A448
    // initializeState_ChallengeState5  Address: 0x029037B0
    // executeState_ChallengeState5     Address: 0x029037FC
    // finalizeState_ChallengeState5    Address: 0x0290387C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, ChallengeState5)

    virtual void vfA2C() = 0;
    virtual void vfA34() = 0;
    virtual void vfA3C() = 0;
    virtual void vfA44() = 0;

public:
    const PlayerKey& getPlayerKey() const
    {
        return mPlayerKey;
    }

    void onStatus(s32 bit)
    {
        mStatus.setBit(bit);
    }

    void offStatus(s32 bit)
    {
        mStatus.resetBit(bit);
    }

    bool isStatus(s32 bit)
    {
        return mStatus.isOnBit(bit);
    }

    void onNowBgCross(s32 bit)
    {
        mNowBgCross.setBit(bit);
    }

    void offNowBgCross(s32 bit)
    {
        mNowBgCross.resetBit(bit);
    }

    bool isNowBgCross(s32 bit)
    {
        return mNowBgCross.isOnBit(bit);
    }

    void onOldBgCross(s32 bit)
    {
        mOldBgCross.setBit(bit);
    }

    void offOldBgCross(s32 bit)
    {
        mOldBgCross.resetBit(bit);
    }

    bool isOldBgCross(s32 bit)
    {
        return mOldBgCross.isOnBit(bit);
    }

    PlayerMode getPlayerMode() const
    {
        return mMode;
    }

    // Address: 0x028F31A0
    void clearFollowMameKuribo();

    // Address: 0x028F31C0
    void calcMaskPos();

    // Address: 0x028F37A8
    bool isTotten() const;

    // Address: 0x028F4D48
    bool setJump(u8, u32);

    // Address: 0x028F77B4
    void bgCheck(bool side_view_check);

    // Address: 0x028FA108
    void clearCcPlayerRev();

    // Address: 0x028FAF1C
    void changeDemoState(const StateID& state_id, s32 param);

    // Address: 0x0290345C
    void changeChallengeState(const StateID& state_id);

    // Address: 0x029065F0
    Angle getMukiAngle(u32 dir);

    // Address: 0x02906B04
    void changeState(const StateID& state_id, s32 param);
    // Address: 0x02906B0C
    void changeState(const StateID& state_id, const JumpInf& jmp_inf);

    // Address: 0x0290B9A4
    void startSound(const char* label, u32 = 0);

protected:
    s32                             mExecuteFreezeTimer;
    PlayerModelBaseMgr*             mpModelBaseMgr;
    sead::Vector3f                  _284;
    s32                             mMaskPosInterpSrcType;  // Interpolation source; 1 = ankle joints center pos, everything else = player pos
    s32                             mMaskPosInterpTimer;
    sead::Vector3f                  mMaskPos;
    s32                             _2a4;
    PlayerKey                       mPlayerKey;
    GameAudio::AudioObjctPly        mAudioObj;
    AttentionLookat                 mAttentionLookat;
    Bitfield<cStatus_MaxBitNum>     mStatus;
    f32                             mCenterOffsetY;
    u32                             _4b8;
    sead::Vector3f                  mFrameEndPosDelta;
    sead::Vector3f                  _4c8;
    PlayerSpeedHIO*                 mpSpeedData_Normal;
    PlayerSpeedHIO*                 mpSpeedData_Star;
    PlayerGravityHIO*               mpGravityData;
    s32                             _4e0;
    f32                             _4e4;
    bool                            _4e8;
    sead::Vector3f                  mNextFrameSpeed;
    s8                              mPriority;
    s8                              mTreadCnt;
    s8                              mComboCnt;
    PlayerCharacter                 mCharacter;
    PlayerMode                      mMode;
    ActorBgCollisionPlayerCheck     mBgCheckPlayer;
    ActorBgCollisionCheck::Sensor   mBcSensorHead;
    ActorBgCollisionCheck::Sensor   mBcSensorFoot;
    ActorBgCollisionCheck::Sensor   mBcSensorWall;
    Bitfield<cBgCross_MaxBitNum>    mNowBgCross;
    Bitfield<cBgCross_MaxBitNum>    mOldBgCross;
    sead::SafeArray<
        BOOL,
        cOldBgCrossFootNum
    >                               mOldBgCrossFoot;        // Array of cBgCross_IsFoot of the past 10 frames
    f32                             _1b0c;
    f32                             _1b10;
    ActorBgCollisionCheck::SakaType mSakaType;
    Angle                           mSakaAngle;
    Angle                           _1b1c;
    Angle                           _1b20;
    Angle                           _1b24;
    sead::Vector3f                  _1b28;
    BgAttr                          mBgAttr;
    Angle                           _1b38;
    f32                             mWaterTopPosY;          // Maybe?
    f32                             mWaterTopPosY2;         // ^^^
    WaterType                       mWaterType;
    s32                             mWaterDepthType;        // TODO: enum
    sead::Vector3f                  mAirWaterHitPos;        // "AirWater" = Floating Water Bubble
    Angle                           mAirWaterHitAngle;
    f32                             mSinkSandSurfacePosY;
    sead::Vector2f                  _1b60;
    sead::Vector2f                  _1b68;
    f32                             _1b70;
    f32                             _1b74;
    u8                              _1b78;
    u32                             _1b7c;
    sead::FixedRingBuffer<
        ActorUniqueID,
        2
    >                               mBgPressIDBuffer;
    ActorUniqueID                   mLineSpinLiftID;
    u32                             _1b9c;
    s32                             mNoHitObjBgTimer;
    f32                             _1ba4;
    f32                             _1ba8;
    f32                             _1bac;
    f32                             _1bb0;
    s32                             _1bb4;
    ActorCollisionCheck             mCollisionCheck2_React; // First collision check is also for react
    ActorCollisionCheck             mCollisionCheck3_React;
    ActorCollisionCheck             mCollisionCheck4_Attack;
    ActorCollisionCheck             mCollisionCheck5_Attack;
    PlayerDrcTouchCB                mDrcTouchCallback;
    s32                             _205c;
    s32                             _2060;
    s32                             _2064;
    s32                             _2068;
    s32                             _206c;
    s32                             _2070;
    f32                             _2074;
    f32                             _2078;
    f32                             _207c;
    f32                             _2080;
    u8                              _2084;
    u8                              _2085;
    s32                             mNoHitPlayerTimer;
    ActorUniqueID                   mNoHitPlayerID;
    u32                             _2090;
    u32                             _2094;
    f32                             _2098;
    s32                             _209c;
    s32                             _20a0;
    sead::SafeArray<u32, 2>         _20a4;
    sead::SafeArray<f32, 2>         _20ac;
    FStateMgr<PlayerBase>           mDemoStateMgr;
    s32                             mChangeDemoStateParam;
    sead::BitFlag32                 mDemoTypeFlag;
    s32                             mDemoMode;              // TODO: Union
    s32                             mDemoAction;            // ^^^
    u32                             _20e8;
    u32                             _20ec;
    ActorUniqueID                   mPlayerJumpDaiID;
    s32                             mDstNextGotoID;
    s32                             mNextGotoType;          // i.e., "Create Action", TODO: enum
    u32                             _20fc;
    sead::Vector2f                  _2100;                  // Target for movement in a specific direction
    sead::Vector2f                  _2108;                  // Speed ^^^
    sead::Vector3f                  mFaderPos;
    bool                            mIsLastPlayer;          // Maybe?
    f32                             _2120;
    f32                             _2124;
    s32                             _2128;
    s32                             _212c;
    f32                             mGoalBasePosY;
    s32                             _2134;
    u32                             _2138;
    sead::Vector3f                  _213c;
    u32                             _2148;
    s32                             _214c;
    DokanDir                        mDokanDir;
    sead::Vector3f                  mDokanPos;
    sead::Vector3f                  mDokanPosPrev;
    sead::Vector2f                  mDokanPosMoveDelta;
    DokanType                       mDokanType;
    f32                             _2178;
    f32                             _217c;
    u32                             _2180;
    u32                             _2184;
    ActorBoxBgCollision*            mpDokanBgCollision;
    bool                            mIsDokanSwim;           // Maybe?
    f32                             _2190;
    u32                             _2194;
    bool                            _2198;
    FStateMgr<PlayerBase>           mStateMgr;
    JumpInf*                        mpChangeStateJmpInf;
    s32                             mChangeStateParam;
    s32                             mAction;                // See ActionType
    s32                             mActionTimer;
    u32                             mStunMode;
    ActorUniqueID                   mRideActorID;
    s32                             _21d8;
    u32                             _21dc;
    s32                             _21e0;
    s32                             _21e4;
    s32                             _21e8;
    FunsuiType                      mFunsuiType;
    sead::Vector2f                  mFunsuiPos;
    f32                             mJumpDaiSpeedFReserve;
    sead::Vector3f                  mRidePlayerPosDelta;
    sead::Vector3f                  _2208;
    u32                             mHipdropEffectStep;     // Maybe?
    f32                             mRideNat;
    s32                             mFrameEndFollowMameKuribo;
    s32                             mFollowMameKuribo;
    s32                             mPenguinSlideCooldown;  // Maybe?
    s32                             mAnimePlayStep;
    EffectObj                       mEffectObjCommon;       // Used for: Wall Slide Effect, Quake Numb Effect, Elec Effect, Fire Jump Smoke Effect, and quite possibly more
    EffectObj                       mSlipSmokeEffect;
    EffectObj                       _22fc;
    EffectObj                       mFootEffect;
    EffectObj                       mHipAttackDropEffect;
    Effect                          mHipdropEffect;
    sead::Vector3f                  mHipdropPos;
    HipdropExEffect                 mHipdropExEffect;
    EffectObj                       _2498;
    EffectObj                       _2500;
    Effect                          mTurnBrakeEffect;
    Effect                          mTurnBrakeSmokeEffect;
    BgAttr                          mTurnBrakeBgAttr;
    bool                            mIsTurnBrakeEffectEnable;
    bool                            mIsTurnBrakeSmokeEffectEnable;
    u32                             _25f0;
    EffectObj                       _25f4;
    u32                             _265c;
    u32                             _2660;
    sead::SafeArray<Effect, 3>      mWaterEffect;           // [0] = waterSplash, [2] = waterSplashS
    FStateMgr<PlayerBase>           mChallengeStateMgr;     // Maybe?
    u32                             _2748;
    bool                            _274c;
};
static_assert(sizeof(PlayerBase) == 0x2750);
