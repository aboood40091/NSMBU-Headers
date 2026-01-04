#pragma once

#include <actor/Actor.h>
#include <actor/AttentionLookat.h>
#include <audio/GameAudio.h>
#include <collision/ActorBgCollisionPlayerCheck.h>
#include <effect/EffectObj.h>
#include <game/Quake.h>
#include <map/NextGotoType.h>
#include <player/PlayerDrcTouchCB.h>
#include <player/PlayerEnum.h>
#include <player/PlayerKey.h>
#include <player/util/HipdropExEffect.h>
#include <state/FStateMgr.h>
#include <state/FStateVirtualID.h>

#include <container/seadRingBuffer.h>

struct PlayerBgPointHIO
{
    ActorBgCollisionCheck::Sensor   sensor_foot;
    ActorBgCollisionCheck::Sensor   sensor_head;
    ActorBgCollisionCheck::Sensor   sensor_wall;
};
static_assert(sizeof(PlayerBgPointHIO) == 0x24);

class   ActorBoxBgCollision;
struct  PlayerGravityHIO;
class   PlayerModelBase;
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
        cStatus_3,                          // NSMBW: Bit 0x02

        cStatus_DemoMode            =   5,  // NSMBW: Boolean

        cStatus_DispOut             =   7,  // NSMBW: Bit 0xB9
        cStatus_DispOutDanger,              // NSMBW: Bit 0xBA
        cStatus_FaderPosSet,
        cStatus_10,                         // Force-disable jump (accelY = 0)
        cStatus_11,

        cStatus_14                  =  14,  // NSMBW: Bit 0x04

        cStatus_17                  =  17,  // NSMBW: Bit 0x06

        cStatus_25                  =  25,  // NSMBW: Bit 0x0A

        cStatus_36                  =  36,  // NSMBW: Bit 0x13
        cStatus_37,

        cStatus_40                  =  40,  // NSMBW: Bit 0x15
        cStatus_41,                         // NSMBW: Bit 0x16

        cStatus_46                  =  46,
        cStatus_47,
        cStatus_48,                         // NSMBW: Bit 0x1C

        cStatus_52                  =  52,  // NSMBW: Bit 0x1F

        cStatus_56                  =  56,  // NSMBW: Bit 0xC4

        cStatus_58                  =  58,

        cStatus_60                  =  60,  // Disable block-hit bounce

        cStatus_62                  =  62,
        cStatus_63,

        cStatus_69                  =  69,  // NSMBW: Bit 0x2B

        cStatus_71                  =  71,  // NSMBW: Bit 0x2D

        cStatus_73                  =  73,  // NSMBW: Bit 0x30

        cStatus_78                  =  78,  // NSMBW: Bit 0x35
        cStatus_79,                         // NSMBW: Bit 0x36

        cStatus_82                  =  82,

        cStatus_84                  =  84,  // NSMBW: Bit 0x3A

        cStatus_93                  =  93,

        cStatus_97                  =  97,
        cStatus_98,                         // NSMBW: Bit 0x3B
        cStatus_99,                         // NSMBW: Bit 0x3C

        cStatus_105                 = 105,
        cStatus_106,
        cStatus_107,                        // NSMBW: Bit 0x45 (Is carried maybe?)

        cStatus_113                 = 113,  // NSMBW: Bit 0x4A

        cStatus_117                 = 117,
        cStatus_118,
        cStatus_119,                        // NSMBW: Bit 0x4E

        cStatus_122                 = 122,  // NSMBW: Bit 0x53
        cStatus_123,                        // Make visible next frame

        cStatus_RideNatDone         = 127,  // NSMBW: Bit 0x58 (Ride Nat target reached)
        cStatus_RideNat,                    // NSMBW: Bit 0x59
        cStatus_129,                        // NSMBW: Bit 0x5A
        cStatus_130,                        // NSMBW: Bit 0x5C
        cStatus_131,                        // NSMBW: Bit 0x5D

        cStatus_133                 = 133,  // NSMBW: Bit 0x5E
        cStatus_134,                        // NSMBW: Bit 0x61

        cStatus_136                 = 136,  // NSMBW: Bit 0x62
        cStatus_137,
        cStatus_138,

        cStatus_141                 = 141,

        cStatus_145                 = 145,  // NSMBW: Bit 0x86
        cStatus_146,                        // NSMBW: Bit 0x87
        cStatus_147,                        // NSMBW: Bit 0x88
        cStatus_148,                        // NSMBW: Bit 0x89

        cStatus_150                 = 150,  // NSMBW: Bit 0x2C
        cStatus_151,                        // NSMBW: Bit 0x8B
        cStatus_152,                        // NSMBW: Bit 0x8C
        cStatus_153,                        // NSMBW: Bit 0x8D

        cStatus_155                 = 155,
        cStatus_156,                        // NSMBW: Bit 0x95

        cStatus_EnableDokanIn       = 171,

        cStatus_FollowMameKuribo    = 174,  // NSMBW: Bit 0xAC
        cStatus_Invisible,                  // NSMBW: Bit 0xBB
        cStatus_HideTemporarily,            // NSMBW: Bit 0xBC

        cStatus_178                 = 178,  // NSMBW: Bit 0xBE
        cStatus_179,                        // NSMBW: Bit 0xBF

        cStatus_191                 = 191,

        cStatus_193                 = 193,

        cStatus_208                 = 208,
        cStatus_SceneChangeNext,            // NSMBW: Bit 0x64
        cStatus_210,

        cStatus_227                 = 227,  // NSMBW: Bit 0x6F

        cStatus_235                 = 235,  // NSMBW: Bit 0x71
        cStatus_NoSlipSaka          = 236,

        cStatus_DemoControl         = 238,  // NSMBW: Bit 0x72

        cStatus_242                 = 242,  // NSMBW: Bit 0x76
        cStatus_243,
        cStatus_244,                        // NSMBW: Bit 0x5F

        cStatus_247                 = 247,  // NSMBW: Bit 0x7E
        cStatus_248,                        // NSMBW: Bit 0x7F
        cStatus_CheckBg,                    // NSMBW: Bit 0x80
        cStatus_250,
        cStatus_ShadowkunCatch,
        cStatus_252,                        // NSMBW: Bit 0x81
        cStatus_253,                        // NSMBW: Bit 0xB8
        cStatus_254,
        cStatus_255,                        // NSMBW: Bit 0x82
        cStatus_256,                        // NSMBW: Bit 0x83

        cStatus_258                 = 258,

        cStatus_DispOutPosYAdj      = 260,

        cStatus_RDash_DispPinch     = 262,
        cStatus_263,                        // NSMBW: Bit 0x77
        cStatus_264,                        // NSMBW: Bit 0x78
        cStatus_265,                        // NSMBW: Bit 0x79
        cStatus_266,                        // NSMBW: Bit 0x7A
        cStatus_267,

        cStatus_270                 = 270,  // NSMBW: Bit 0x84

        cStatus_280                 = 280,  // NSMBW: Bit 0xCA

        cStatus_282                 = 282,

        cStatus_LastBit             = 286,  // Not sure if bit 287 is used
        cStatus_BitNum,
        cStatus_MaxBitNum = (cStatus_BitNum + 31) / 32 * 32
    };

    enum BgCross
    {
        cBgCross_IsFoot = 0,                        // NSMBW Bit: 0x00
        cBgCross_IsHead,                            // NSMBW Bit: 0x01
        cBgCross_IsWall,                            // NSMBW Bit: 0x02
        cBgCross_IsWallPressL,                      // NSMBW Bit: 0x03
        cBgCross_IsWallPressR,                      // NSMBW Bit: 0x04
        cBgCross_IsWallTouchL,                      // NSMBW Bit: 0x05
        cBgCross_IsWallTouchR,                      // NSMBW Bit: 0x06
        cBgCross_CarryRelatedL,                     // NSMBW Bit: 0x07
        cBgCross_CarryRelatedR,                     // NSMBW Bit: 0x08
        cBgCross_CarryObjBgCarriedL,                // NSMBW Bit: 0x09
        cBgCross_CarryObjBgCarriedR,                // NSMBW Bit: 0x0A
        cBgCross_WallWalkEnableL,
        cBgCross_WallWalkEnableR,
        cBgCross_IsWaterPillarL,                    // Maybe?
        cBgCross_IsWaterPillarR,                    // ^^^
        cBgCross_15,                                // NSMBW Bit: 0x0B (MAYBE)
        cBgCross_16,                                // NSMBW Bit: 0x0C
        cBgCross_17,                                // NSMBW Bit: 0x0D
        cBgCross_IsUnderwater,                      // NSMBW Bit: 0x0E
        cBgCross_IsWater,                           // NSMBW Bit: 0x0F (All liquids)
        cBgCross_IsCompletelyUnderwater,            // NSMBW Bit: 0x10

        cBgCross_RDash_IsNonWaterLiquid = 22,       // i.e. Lava, Lava Wave, Poison & Quicksand
        cBgCross_IsAirWater,                        // NSMBW Bit: 0x12
        cBgCross_DispSideLimitL,
        cBgCross_DispSideLimitR,
        cBgCross_IsSnow,                            // NSMBW Bit: 0x16
        cBgCross_IsIce,                             // NSMBW Bit: 0x17
        cBgCross_IsIceLowSlip,                      // NSMBW Bit: 0x18
        cBgCross_SlipAttr6,
        cBgCross_OnSakaUnderRoof,                   // NSMBW Bit: 0x19
        cBgCross_IsWaterAttr,
        cBgCross_32,
        cBgCross_IsSand,                            // NSMBW Bit: 0x1A
        cBgCross_IsSinkSand,
        cBgCross_IsSlightlyInsideSinkSand,          // NSMBW Bit: 0x1B
        cBgCross_IsPartiallySubmergedInSinkSand,    // NSMBW Bit: 0x1C
        cBgCross_IsCompletelySubmergedInSinkSand,   // NSMBW Bit: 0x1D
        cBgCross_IsBeltConveyorL,                   // NSMBW Bit: 0x1E
        cBgCross_IsBeltConveyorR,                   // NSMBW Bit: 0x1F
        cBgCross_IsChikuwa,
        cBgCross_IsChikuwaActor,
        cBgCross_OnHalf,                            // NSMBW Bit: 0x20
        cBgCross_OnRide,                            // NSMBW Bit: 0x21
        cBgCross_IsHold,                            // NSMBW Bit: 0x22 (i.e., Head is touching a horizontal rope)
        cBgCross_Slip,                              // NSMBW Bit: 0x23 (MAYBE)
        cBgCross_IsOnHDokan,
        cBgCross_47,                                // NSMBW Bit: 0x26
        cBgCross_IsSaka,                            // NSMBW: daPlBase_c::isSaka()

        cBgCross_IsLineSpinLift = 50,
        cBgCross_IsBlockDRC,
        cBgCross_IsLiftZenStar,
        cBgCross_IsFloorGyration,
        cBgCross_IsFunsui,
        cBgCross_IsKani,                            // NSMBW Bit: 0x28
        cBgCross_IsKani2,                           // NSMBW Bit: 0x29
        cBgCross_IsKani3,                           // NSMBW Bit: 0x2A (Never actually set at runtime)
        cBgCross_IsPole,

        cBgCross_66 = 66,                           // NSMBW Bit: 0x35
        cBgCross_67,                                // NSMBW Bit: 0x36
        cBgCross_68,                                // NSMBW Bit: 0x37 (MAYBE)
        cBgCross_69,                                // NSMBW Bit: 0x38 (MAYBE)

        cBgCross_HitBgActorYuka = 73,               // NSMBW Bit: 0x3B (MAYBE)
        cBgCross_74,                                // NSMBW Bit: 0x3D
        cBgCross_75,                                // NSMBW Bit: 0x3E
        cBgCross_76,                                // NSMBW Bit: 0x3F

        cBgCross_LastBit = cBgCross_76,             // Explicitly checked in function 0x029586DC
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
        cBgAttr_Water1,
        cBgAttr_Cloud,
        cBgAttr_SandFunsui, // i.e., sand pillar
        cBgAttr_Manta,      // Used for beanstalk
        cBgAttr_Beach,
        cBgAttr_Carpet,
        cBgAttr_Leaf,
        cBgAttr_Wood,
        cBgAttr_Water2,     // Water pillar?
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

    enum JumpSe
    {
        cJumpSe_None = 0,
        cJumpSe_Normal,
        cJumpSe_High
    };
    static_assert(sizeof(JumpSe) == 4);

    struct JumpInf
    {
        f32     speed_y;
        JumpSe  jump_se_type;
        u8      _8;
    };
    static_assert(sizeof(JumpInf) == 0xC);

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
        cDemoType_1 = 1,

        cDemoType_3 = 3,
        cDemoType_4,
        cDemoType_5,    // CourseOut?
        cDemoType_ShadowkunCatch
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

    enum ReductionMode
    {
        cReductionMode_None = 0,
        cReductionMode_JumpDai,
        cReductionMode_2,
        cReductionMode_Boyon
    };
    static_assert(sizeof(ReductionMode) == 4);

    enum NextGotoBlockDelay
    {
        cNextGotoBlockDelay_None = 0,
        cNextGotoBlockDelay_Normal,
        cNextGotoBlockDelay_Short
    };
    static_assert(sizeof(NextGotoBlockDelay) == 4);

    // Address: 0x10166E60
    static const f32 cDirSpeed[cDirType_NumX];
    // Address: 0x10166E68
    static const f32 cJumpSpeed;                    // 3.628f
    // Address: 0x10166E6C
    static const f32 cUnkZero;                      // 0.0f
    // Address: 0x10166E70
    static const f32 cWaterNumaJumpSpeed;           // 0.75f
    // Address: 0x10166E74
    static const f32 cMaxFallSpeed;                 // -4.0f
    // Address: 0x10166E78
    static const f32 cMaxFallSpeed_Foot;            // -2.0f
    // Address: 0x10166E7C
    static const f32 cTurnPowerUpRate;              // 3.0f
    // Address: 0x10166E80
    static const f32 cWaterCancelCrouchAnmSpeed;    // 0.1f

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

    // Address: 0x028F376C
    void setDrawTypeInDistantView();
    // Address: 0x028F3778
    void resetDrawType();

    // Address: 0x028F3784
    bool isKinopio() const;
    // Address: 0x028F37A8
    bool isTotten() const;

    // Address: 0x028F37BC
    bool isMameAction();

    // Address: 0x028F3820
    sead::Vector3f* getHeadTopPosP();
    // Address: 0x028F3844
    sead::Vector3f* getHeadPosP();

    const sead::Vector3f& getLookatPos() const
    {
        return *const_cast<PlayerBase*>(this)->getHeadPosP();
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

    // Address: 0x028F389C
    void setMaskPosInterpType(s32 src_type);

    // Address: 0x028F31C0
    void calcMaskPos();

    // Address: 0x028F38AC
    void dokanAdjustMaskPos(sead::Vector3f& mask_pos);

    // Address: 0x028F3948
    bool checkRideActor(PlayerBase* p_player_other);
    // Address: 0x028F3978
    void setRideNat(f32 value);
    // Address: 0x028F398C
    void updateRideNat();

    // Address: 0x028F39E4
    void onFollowMameKuribo();
    // Address: 0x028F31A0
    void clearFollowMameKuribo();
    // Address: 0x028F3A00
    s32 getFollowMameKuribo();
    // Address: 0x028F3A08
    s32 getFollowMameKuriboSpeedType();
    // Address: 0x028F3A44
    f32 getFollowMameKuriboSpeedScaleX();
    // Address: 0x028F3A94
    f32 getFollowMameKuriboSpeedScaleY();

    // Address: 0x028F6274
    BgAttr getFootBgAttr(BgUnitCode::Attr attr);

protected:
    // Address: 0x028F684C
    void postBgCrossImpl_();
    // Address: 0x028F6298
    bool checkLedge_();
    // Address: 0x028F658C
    bool vsPlayerCarryPush_();

    // Address: 0x028F6B04
    void setBcSensorFlagsImpl_();

public:
    // Address: 0x028F77B4
    void bgCheck(bool side_view_check);

    // Address: 0x028F86AC
    void clearBgAndSakaAngle();
    // Address: 0x028F6CD4
    void clearBgCheckInfo();
    // Address: 0x028F6CAC
    void clearBgSpeed();

    // Address: 0x028F71C0
    bool checkOnHDokan(const u64& bc_data); // See BgUnitCode

    // Address: 0x028F7204
    bool checkSinkSand();

    // Address: 0x028F730C
    bool checkBgWall(u8 dir);

    // Address: 0x028F73F4
    f32 getWaterCheckPosY();
    // Address: 0x028F73B4
    f32 getWaterOffsetY();

    // Address: 0x028F7428
    void checkWater();

    virtual PlayerBgPointHIO* getBgPointData() = 0;

    ActorBgCollisionCheck::Sensor* getHeadBgPointData()
    {
        return &getBgPointData()->sensor_head;
    }

    ActorBgCollisionCheck::Sensor* getWallBgPointData()
    {
        return &getBgPointData()->sensor_wall;
    }

    ActorBgCollisionCheck::Sensor* getFootBgPointData()
    {
        return &getBgPointData()->sensor_foot;
    }

    virtual f32 getStandHeadBgPointY() = 0;

    bool isSaka()
    {
        return isNowBgCross(cBgCross_IsSaka);
    }

    // Address: 0x028F86EC
    bool isSlipSaka();

private:
    inline void checkBgCross_();
    inline void checkCarryObjBgCarried_(const ActorBgCollisionCheck::Output& output, u8 dir);

public:
    virtual void checkBgCrossSub() = 0;
    virtual void postBgCross() = 0;

    // Address: 0x028F872C
    bool checkBGCrossWall(s32 dir);

    // Address: 0x028F8760
    bool checkOldBgCrossFoot(s32 frame_cnt);

    virtual void clearJumpActionInfo() = 0;

    // Address: 0x028F87B8
    void setJumpSandSinkRate();

    // Address: 0x028F87C8
    Angle getSakaAngle(s32 dir);
    // Address: 0x028F716C
    Angle getSakaAngleBySpeed(f32 speed_F);
    // Address: 0x028F8804
    bool getSakaUpDown(s32 dir);    // true => moving "up"hill, false => moving "down"hill

    // Address: 0x028F76A0
    void checkDamageBg();
    // Address: 0x028F8850
    bool setBgDamage();

    // Address: 0x028F8900
    void calcNoHitObjBgTimer();

    // Address: 0x028F6EEC
    void checkSideViewLemit();
    // Address: 0x028F6D20
    void revSideLimitCommon(f32 x);
    // Address: 0x028F6E64
    void calcSideLimitMultL(f32 x);
    // Address: 0x028F6EA8
    void calcSideLimitMultR(f32 x);

private:
    inline bool checkDispSideLemit_();

public:
    // Address: 0x028F8944
    void setLandSakaJumpSpeedF();

    // Address: 0x028F8A1C
    bool isRideMove();

    // Address: 0x028F8A4C
    void setNoHitObjBg(Actor* p_no_hit_obj, s32 time);

    // Address: 0x028F8A58
    void setJumpAddSpeedF(f32 f);
    // Address: 0x028F8ABC
    void setAddLiftSpeedF();

    // Address: 0x028F9858
    virtual void initCollision(const ActorCollisionCheck::CollisionData& cc_data_react, const ActorCollisionCheck::CollisionData& cc_data_attack);
    // Address: 0x028F98FC
    virtual void releaseCcData();
    // Address: 0x028F9A78
    virtual void clearCcData();

    // Address: 0x028F9AC8
    bool entryCollision();

    virtual bool vf19C() = 0;

    // Address: 0x028F9CC8
    void setCcAt(const ActorCollisionCheck::Vec2& center_offset, const ActorCollisionCheck::Vec2& half_size, const ActorCollisionCheck::Attack& attack);

    // Address: 0x028F9D1C
    void setCcAtBody(const ActorCollisionCheck::Attack& attack);
    // Address: 0x028F9D2C
    void setCcAtSlip();
    // Address: 0x028F9D58
    void setCcAtPenguinSlip();
    // Address: 0x028F9D9C
    void setCcAtHipAttack();
    // Address: 0x028F9DD4
    void setCcAtCannon();
    // Address: 0x028F9E0C
    void setCcAtStar();

    // Address: 0x028F9E48
    bool isActionRevisionY();
    // Address: 0x028F9E6C
    void setCcPlayerRevY(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other, f32 scale, ActorCollisionCheck::Kind kind);
    // Address: 0x028FA0DC
    void setCcPlayerRevParam(f32 param);
    // Address: 0x028FA108
    void clearCcPlayerRev();
    // Address: 0x028FA130
    bool calcCcPlayerRev(f32*);

    // Address: 0x028FA280
    void setNoHitPlayer(const PlayerBase* p_player_other, s32 time);
    // Address: 0x028FA290
    void updateNoHitPlayer();
    // Address: 0x028FA2B4
    const PlayerBase* getNoHitPlayer();

    // Address: 0x028FA350
    bool isEnableStamp(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x028FA3E0
    bool isEnableStampPlayerJump(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x028FA590
    void setStampReduction(PlayerBase* p_player_other);
    // Address: 0x028FA544
    void setReductionScale();

    // Address: 0x028FA62C
    void setStampPlayerJump(bool allow_high_jump, f32 rev_y);

    // Address: 0x028FA8D8
    virtual void initStampReduction();
    // Address: 0x028FA910
    virtual void calcJumpDaiReductionScale(s32, s32);
    // Address: 0x028FA97C
    virtual void setReductionBoyon();

    // Address: 0x028FA830
    void setStomped();

    // Address: 0x028FA990
    virtual bool getHeadTopPos(sead::Vector3f& pos);

    // Address: 0x028FAA20
    void calcReductionScale();
    // Address: 0x028FAB14
    void getReductionModelScale(sead::Vector3f* p_scale);

    // Address: 0x028F8B18
    void dispPinchRequestRDash();

    // Address: 0x028F8B3C
    void initDispSideLemit();

    // Address: 0x028F92B0
    void checkDispOver();
    // Address: 0x028F9164
    void checkDisplayOutDead();

    // Address: 0x028F93F8
    virtual void upperOverCheck();

    // Address: 0x028F8BAC
    bool isLenientOutCheck();

    // Address: 0x028F8C50
    void setFallDownDemo();

    virtual void setFallDownDemoImpl() = 0;

    // Address: 0x028F8FA8
    bool checkDispOutLR();
    // Address: 0x028F9010
    bool checkBalloonInDispOutLR();

    virtual bool setBalloonInDispOut(s32) = 0;
    virtual bool setBalloonDispOut() = 0;

    // Address: 0x028F9560
    bool checkStandUpRoof();

    // Address: 0x028f9694
    bool isBgPress(Actor* p_actor);
    // Address: 0x028f9710
    bool setPressBgDamageImpl(DamageType type);
    // Address: 0x028F8F18
    bool checkPressBg();

private:
    inline void underOverCheck_();

    // Address: 0x028F8CD8
    bool checkPressBgUD_();
    // Address: 0x028F8D88
    bool checkPressBgLR_();
    // Address: 0x028F8C80
    void setPressBgCollision_(const BgCollision* p_bg_collision);

public:
    // Address: 0x028FD318
    virtual void setCreate(const sead::Vector3f& pos, NextGotoType next_goto_type, s32 dir);
    // Address: 0x028FD394
    virtual void reset();

    // Address: 0x028FD684
    virtual void initialNormal(NextGotoType next_goto_type);
    // Address: 0x028FDD4C
    virtual void initialDoor(NextGotoType next_goto_type);
    // Address: 0x028FD6D0
    virtual void initialDokan(NextGotoType next_goto_type);
    // Address: 0x028FD7B4
    virtual void initialFall(NextGotoType next_goto_type);
    // Address: 0x028FD800
    virtual void initialHipAttack(NextGotoType next_goto_type);
    // Address: 0x028FD84C
    virtual void initialSlip(NextGotoType next_goto_type);
    // Address: 0x028FDD50
    virtual void initialJump(NextGotoType next_goto_type);
    // Address: 0x028FDD54
    virtual void initialVine(NextGotoType next_goto_type);
    // Address: 0x028FDD58
    virtual void initialShiroBoss(NextGotoType next_goto_type);
    // Address: 0x028FDD5C
    virtual void initialFinalBoss(NextGotoType next_goto_type);
    // Address: 0x028FDD60
    virtual void initialUnk10(NextGotoType next_goto_type);
    // Address: 0x028FD8A4
    virtual void initialUnk27(NextGotoType next_goto_type);
    // Address: 0x028FDD64
    virtual void initialBoxingKoopaJr(NextGotoType next_goto_type);
    // Address: 0x028FDD68
    virtual void initialTitle(NextGotoType next_goto_type);

    // StateID_DemoCreate           Address: 0x1022A008
    // initializeState_DemoCreate   Address: 0x028FD8B4
    // executeState_DemoCreate      Address: 0x028FD8B8
    // finalizeState_DemoCreate     Address: 0x028FDD6C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoCreate)
    // StateID_DemoNone         Address: 0x1022A02C
    // initializeState_DemoNone Address: 0x028FAC40
    // executeState_DemoNone    Address: 0x028FACDC
    // finalizeState_DemoNone   Address: 0x028FD244
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoNone)
    // StateID_DemoReset            Address: 0x1022A050
    // initializeState_DemoReset    Address: 0x028FD248
    // executeState_DemoReset       Address: 0x028FD24C
    // finalizeState_DemoReset      Address: 0x028FD250
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoReset)
    // StateID_DemoStartCoinBattle          Address: 0x1022A074
    // initializeState_DemoStartCoinBattle  Address: 0x028FAEB0
    // executeState_DemoStartCoinBattle     Address: 0x028FAFB4
    // finalizeState_DemoStartCoinBattle    Address: 0x028FB05C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoStartCoinBattle)
    // StateID_DemoGoal         Address: 0x1022A098
    // initializeState_DemoGoal Address: 0x02901D7C
    // executeState_DemoGoal    Address: 0x02902988
    // finalizeState_DemoGoal   Address: 0x02902AE0
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoGoal)
    // StateID_DemoStartWait            Address: 0x1022A0BC
    // initializeState_DemoStartWait    Address: 0x028FD938
    // executeState_DemoStartWait       Address: 0x028FD9E0
    // finalizeState_DemoStartWait      Address: 0x028FDD70
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoStartWait)
    // StateID_DemoWait         Address: 0x1022A0E0
    // initializeState_DemoWait Address: 0x028FDAAC
    // executeState_DemoWait    Address: 0x028FDB30
    // finalizeState_DemoWait   Address: 0x028FDD18
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoWait)
    // StateID_DemoOutDokanU            Address: 0x1022A104
    // initializeState_DemoOutDokanU    Address: 0x028FDFB4
    // executeState_DemoOutDokanU       Address: 0x028FE1E4
    // finalizeState_DemoOutDokanU      Address: 0x028FE21C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDokanU)
    // StateID_DemoOutDokanD            Address: 0x1022A128
    // initializeState_DemoOutDokanD    Address: 0x028FE220
    // executeState_DemoOutDokanD       Address: 0x028FE228
    // finalizeState_DemoOutDokanD      Address: 0x028FE22C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDokanD)
    // StateID_DemoOutDokanR            Address: 0x1022A14C
    // initializeState_DemoOutDokanR    Address: 0x028FE3B4
    // executeState_DemoOutDokanR       Address: 0x028FE67C
    // finalizeState_DemoOutDokanR      Address: 0x028FE680
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDokanR)
    // StateID_DemoOutDokanL            Address: 0x1022A170
    // initializeState_DemoOutDokanL    Address: 0x028FE684
    // executeState_DemoOutDokanL       Address: 0x028FE68C
    // finalizeState_DemoOutDokanL      Address: 0x028FE690
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDokanL)
    // StateID_DemoOutDokanRollUD           Address: 0x1022A194
    // initializeState_DemoOutDokanRollUD   Address: 0x028FE7E4
    // executeState_DemoOutDokanRollUD      Address: 0x028FE824
    // finalizeState_DemoOutDokanRollUD     Address: 0x028FEBD0
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDokanRollUD)
    // StateID_DemoOutDokanRollLR           Address: 0x1022A1B8
    // initializeState_DemoOutDokanRollLR   Address: 0x028FEBD4
    // executeState_DemoOutDokanRollLR      Address: 0x028FEC34
    // finalizeState_DemoOutDokanRollLR     Address: 0x028FEDC4
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDokanRollLR)
    // StateID_DemoInDokanU         Address: 0x1022A1DC
    // initializeState_DemoInDokanU Address: 0x028FEDC8
    // executeState_DemoInDokanU    Address: 0x028FF344
    // finalizeState_DemoInDokanU   Address: 0x028FF3A8
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoInDokanU)
    // StateID_DemoInDokanD         Address: 0x1022A200
    // initializeState_DemoInDokanD Address: 0x028FF3AC
    // executeState_DemoInDokanD    Address: 0x028FF4B8
    // finalizeState_DemoInDokanD   Address: 0x028FF4BC
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoInDokanD)
    // StateID_DemoInDokanR         Address: 0x1022A224
    // initializeState_DemoInDokanR Address: 0x028FF54C
    // executeState_DemoInDokanR    Address: 0x028FF554
    // finalizeState_DemoInDokanR   Address: 0x028FF558
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoInDokanR)
    // StateID_DemoInDokanL         Address: 0x1022A248
    // initializeState_DemoInDokanL Address: 0x028FF55C
    // executeState_DemoInDokanL    Address: 0x028FF564
    // finalizeState_DemoInDokanL   Address: 0x028FF568
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoInDokanL)
    // StateID_DemoOutDoor          Address: 0x1022A26C
    // initializeState_DemoOutDoor  Address: 0x028FD254
    // executeState_DemoOutDoor     Address: 0x028FD258
    // finalizeState_DemoOutDoor    Address: 0x028FD25C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDoor)
    // StateID_DemoInDoor           Address: 0x1022A290
    // initializeState_DemoInDoor   Address: 0x028FD260
    // executeState_DemoInDoor      Address: 0x028FD264
    // finalizeState_DemoInDoor     Address: 0x028FD268
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoInDoor)
    // StateID_DemoNextGotoBlock            Address: 0x1022A2B4
    // initializeState_DemoNextGotoBlock    Address: 0x028FB068
    // executeState_DemoNextGotoBlock       Address: 0x028FB404
    // finalizeState_DemoNextGotoBlock      Address: 0x028FB51C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoNextGotoBlock)
    // StateID_DemoDown         Address: 0x1022A2D8
    // initializeState_DemoDown Address: 0x02901CF8
    // executeState_DemoDown    Address: 0x02901CFC
    // finalizeState_DemoDown   Address: 0x02901D00
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoDown)
    // StateID_DemoControl          Address: 0x1022A2FC
    // initializeState_DemoControl  Address: 0x02900350
    // executeState_DemoControl     Address: 0x02900420
    // finalizeState_DemoControl    Address: 0x02900644
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoControl)
    // StateID_DemoState23          Address: 0x1022A320
    // initializeState_DemoState23  Address: 0x029031E8
    // executeState_DemoState23     Address: 0x02903288
    // finalizeState_DemoState23    Address: 0x0290338C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoState23)
    // StateID_DemoState24          Address: 0x1022A344
    // initializeState_DemoState24  Address: 0x0290339C
    // executeState_DemoState24     Address: 0x029033BC
    // finalizeState_DemoState24    Address: 0x0290340C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoState24)
    // StateID_DemoState25          Address: 0x1022A368
    // initializeState_DemoState25  Address: 0x02903F24
    // executeState_DemoState25     Address: 0x02903F28
    // finalizeState_DemoState25    Address: 0x02903F2C
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoState25)

    // Address: 0x028FAF1C
    void changeDemoState(const StateID& state_id, s32 param);
    // Address: 0x028FB568
    bool executeDemoState();

    virtual void initializeDemoControl(bool carry_chibi_yoshi = true) = 0;

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
    // Address: 0x028FB754
    bool isDemoAll();
    // Address: 0x028FB764
    bool isDemo();
    // Address: 0x028FAEBC
    void onDemo();
    // Address: 0x028FABD4
    void offDemo();

    // Address: 0x028FB7E0
    void setShadowkunCatchDemo();

    // Address: 0x028FB828
    bool isDisableDokanInDemo();
    // Address: 0x028FB948
    bool isDisableGoalDemo();

protected:
    // Address: 0x028FB888
    bool isDemo3Any_();
    // Address: 0x028FB118
    bool isDemo5Any_();

public:
    // Address: 0x028FB1D8
    void setFaderPos(const sead::Vector3f& pos);
    // Address: 0x028FB338
    void changeNextScene(s32);
    // Address: 0x028FB9A8
    bool isSceneChangeWaitDone();

    // Address: 0x028FBA0C
    bool isDispOutCheckOn();

    // Address: 0x028FBAAC
    void changeNormalAction();

    // Address: 0x028FBB18
    bool setNextGotoBlockDemo(s32 dst_next_goto_no, s32 wait_timer, NextGotoBlockDelay delay, bool unk_rdash = false);

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

    // Address: 0x028FFA48
    bool checkDokanInKeyTrig(DokanDir dir);

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

    // Address: 0x02900D34
    void checkDemoControl();

    // Address: 0x02906B04
    void changeState(const StateID& state_id, s32 param);
    // Address: 0x02906B0C
    void changeState(const StateID& state_id, const JumpInf& jmp_inf);

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

    // Address: 0x028F3B44
    void coinJumpOnStampCB(s32 coin_num);
    // Address: 0x028F3C34
    void coinFunsuiOnDamageCB(s32 type, Actor* p_eat_die_actor);

private:
    inline void reduceCoinNum_(s32 coin_num);
    // Address: 0x028F3AE4
    s32 adjustCoinReductionNumCB_(s32 coin_num);

public:
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

    // Address: 0x028F3814
    PlayerModelBase* getModel();
    // Address: 0x028F3FFC
    const PlayerModelBase* getModel() const;

    // Address: 0x028F4008
    void getAnkleCenterPos(sead::Vector3f* p_pos);

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

    // Address: 0x028F40D8
    f32 getThrowSpeed();
    // Address: 0x028F40F0
    f32 getThrowLoopPosX(f32 x);

    // Address: 0x028F4898
    void calcPlayerSpeedXY();
    // Address: 0x028F45E4
    void posMoveAnglePlayer(const sead::Vector3f& speed);
    // Address: 0x028F4178
    void posMoveAnglePenguin(const sead::Vector3f& speed);
    // Address: 0x028F4CD8
    void initAirDriftSpeedF(f32 start_val, f32 len_frames);
    // Address: 0x028F4148
    void calcAirDriftSpeedF();

    // Address: 0x028F4D48
    bool setJump(u8, JumpSe jump_se_type);
    // Address: 0x028F4E50
    bool setDelayHelpJump();
    // Address: 0x028F4EE8
    bool checkJumpTrigger();

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

    // Address: 0x028F4F48
    void clearTreadCount();
    s8 getTreadCount() const { return mTreadCnt; }
    // Address: 0x028F4F84
    s8 calcTreadCount(s32 max);

    void clearComboCount() { mComboCnt = 0; }
    s8 getComboCount() const { return mComboCnt; }
    // Address: 0x028F4FA8
    s8 calcComboCount(s32 max);

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

    // Address: 0x029049F8
    void setSandEffect();

    // Address: 0x0290345C
    void changeChallengeState(const StateID& state_id);

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

    // Address: 0x028F5E90
    void calcHeadAttentionAngle();

private:
    // Address: 0x028F5554
    PlayerBase* searchPlayerAttention_(const sead::Vector2f& src_pos);
    // Address: 0x028F566C
    bool calcHeadAttentionAngle_(const sead::Vector2f& target_pos, sead::BitFlag32 flag, Angle max_angle_y);

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

    // Address: 0x029050C8
    s32 getPowerChangeType(bool);

    // Address: 0x029063AC
    void setJumpAirDrift();

    // Address: 0x029065F0
    Angle getMukiAngle(u32 dir);

    // Address: 0x0290B89C
    void forceSlipToStoop();

    // Address: 0x0290B9A4
    void startSound(const char* label, u32 = 0);
    // Address: 0x0290BBBC
    void startVoiceSound(PlayerVoiceID voice_id, u32 = 0);

    // Address: 0x0290BC6C
    void setHitBlockSE();

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
    f32                             mCenterOffsetY;         // Or height?
    u32                             _4b8;
    sead::Vector3f                  mFrameEndPosDelta;
    sead::Vector3f                  _4c8;
    PlayerSpeedHIO*                 mpSpeedData_Normal;
    PlayerSpeedHIO*                 mpSpeedData_Star;
    PlayerGravityHIO*               mpGravityData;
    s32                             mNoGravityTimer;
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
    f32                             mKaniPosY;
    ActorBgCollisionCheck::SakaType mSakaType;
    Angle                           mSpeedSakaAngle;
    Angle                           mSpeedSakaAnglePrev;
    Angle                           mBaseSakaAngle;
    Angle                           mBaseSakaAnglePrev;
    sead::Vector3f                  _1b28;
    BgAttr                          mBgAttr;
    Angle                           mWallAngle;
    f32                             mWaterSurfacePosY;
    f32                             mWaterSurfacePosYPrev;
    WaterType                       mWaterType;
    s32                             mWaterDepthType;        // TODO: enum
    sead::Vector3f                  mAirWaterHitPos;        // "AirWater" = Floating Water Bubble
    Angle                           mAirWaterHitAngle;
    f32                             mSinkSandSurfacePosY;
    sead::Vector2f                  mBgSpeed;
    sead::Vector2f                  mBgSpeedPrev;
    f32                             mSandSinkRate;
    f32                             mDispSideLimitPad;
    bool                            mIsBgDamageEnable;
    BgUnitCode::TypeInfo_Damage     mDamageBgTypeInfo;
    sead::FixedRingBuffer<
        ActorUniqueID,
        2
    >                               mBgPressIDBuffer;
    ActorUniqueID                   mLineSpinLiftID;
    u32                             _1b9c;
    s32                             mNoHitObjBgTimer;
    f32                             mAirDriftSpeedFStart;
    f32                             mAirDriftSpeedF;
    f32                             mAirDriftSpeedFDecelStep;
    f32                             mAddBgSpeedF;
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
    f32                             mCcPlayerRevSpeedFScale;
    f32                             mCcPlayerRevSpeedFStart;
    f32                             mCcPlayerRevSpeedF;
    f32                             _2080;
    bool                            _2084;
    bool                            _2085;
    s32                             mNoHitPlayerTimer;
    ActorUniqueID                   mNoHitPlayerID;
    ReductionMode                   mReductionMode;
    u32                             mReductionStep;
    f32                             mReductionScale;
    s32                             _209c;
    s32                             _20a0;
    sead::SafeArray<
        u32,
        cDirType_NumX
    >                               _20a4;
    sead::SafeArray<
        f32,
        cDirType_NumX
    >                               _20ac;
    FStateMgr<PlayerBase>           mDemoStateMgr;
    s32                             mChangeDemoStateParam;
    sead::BitFlag32                 mDemoTypeFlag;
    s32                             mDemoMode;              // TODO: Union
    s32                             mDemoAction;            // ^^^
    s32                             mDemoWaitTimer;
    s32                             _20ec;
    ActorUniqueID                   mPlayerJumpDaiID;
    s32                             mDstNextGotoID;
    NextGotoType                    mNextGotoType;          // i.e., "Create Action"
    NextGotoBlockDelay              mNextGotoDelay;
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
    u32                             mDokanInTimerL;
    u32                             mDokanInTimerR;
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
    f32                             mRideNatPosY;
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
