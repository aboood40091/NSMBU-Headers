#pragma once

#include <actor/Actor.h>
#include <actor/AttentionLookat.h>
#include <audio/GameAudio.h>
#include <collision/ActorBgCollisionPlayerCheck.h>
#include <collision/ActorCollisionHitCallback.h>
#include <effect/EffectObj.h>
#include <player/PlayerEnum.h>
#include <player/PlayerKey.h>
#include <player/util/HipdropExEffect.h>
#include <state/FStateMgr.h>

#include <container/seadRingBuffer.h>

class PlayerBaseCB : public ActorCollisionHitCallback   // vtbl Address: 0x101693FC
{
public:
    // Address: 0x029117C0
    bool ccCallback1(ActorCollisionCheck*, const sead::Vector2f&) override;
    void ccCallback2(ActorCollisionCheck*, const sead::Vector2f&) override { }

    bool bcCallback1(BgCollision*, const sead::Vector2f&) override { return false; }
};
static_assert(sizeof(PlayerBaseCB) == sizeof(ActorCollisionHitCallback));

class   ActorBoxBgCollision;
struct  PlayerGravityHIO;
class   PlayerModelBaseMgr;
struct  PlayerSpeedHIO;

class PlayerBase : public Actor // vtbl Address: 0x10166E84
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CCC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CD0
    SEAD_RTTI_OVERRIDE(PlayerBase, Actor)

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
        cDamageType_Hit4,
        cDamageType_Lava,
        cDamageType_Ice,
        cDamageType_Ice2,
        cDamageType_Spark,
        cDamageType_Poison,
        cDamageType_Kill,
        cDamageType_Kill2,
        cDamageType_RunInPlace,
        cDamageType_RunInPlace2,
        cDamageType_SteppedOn,
        cDamageType_Num
    };

    enum Status
    {
        cStatus_113 = 113,

        cStatus_LastBit = 286,  // Not sure if bit 287 is used
        cStatus_BitNum,
        cStatus_MaxBitNum = (cStatus_BitNum + 31) / 32 * 32
    };

    enum BgCross
    {
        cBgCross_IsFoot = 0,

        cBgCross_IsWallPressL = 3,
        cBgCross_IsWallPressR,
        cBgCross_IsWallTouchL,
        cBgCross_IsWallTouchR,

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

        cBgCross_IsPole = 58,

        cBgCross_LastBit = 76,  // Explicitly checked in function 0x029586DC
        cBgCross_BitNum,
        cBgCross_MaxBitNum = (cBgCross_BitNum + 31) / 32 * 32
    };

    static const s32 cOldBgCrossFootNum = 10;

    enum SurfaceType
    {
        cSurfaceType_Rock = 0,
        cSurfaceType_Snow,
        cSurfaceType_Sand,
        cSurfaceType_Ice,
        cSurfaceType_Dirt,
        cSurfaceType_Water,
        cSurfaceType_Cloud,
        cSurfaceType_SandFunsui,    // i.e., sand pillar
        cSurfaceType_Manta,         // Used for beanstalk
        cSurfaceType_Beach,
        cSurfaceType_Carpet,
        cSurfaceType_Leaf,
        cSurfaceType_Wood,
        cSurfaceType_WaterPillar,
        cSurfaceType_Num
    };
    static_assert(cSurfaceType_Num == 14);
    static_assert(sizeof(SurfaceType) == 4);

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
        cJumpAction_Start = 0,
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
        cTarzanRopeAction_4,
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

    // Address: 0x10166E60
    static const f32 cDirSpeed[DIRECTION_NUM_X];
    // Address: 0x10166E68
    static const f32 cJumpSpeed;                    // 3.628f
    // Address: 0x10166E74
    static const f32 cMaxFallSpeed;                 // -4.0f
    // Address: 0x10166E78
    static const f32 cMaxFallSpeed_Foot;            // -2.0f
    // Address: 0x10166E7C
    static const f32 cTurnPowerUpRate;              // 3.0f

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

    // Address: 0x028F37A8
    bool isTotten() const;

    // Address: 0x028F4D48
    bool setJump(u8, u32);

    // Address: 0x029065F0
    Angle getMukiAngle(u32 dir);

    // Address: 0x0290B9A4
    void startSound(const char* label, u32 = 0);

protected:
    s32                             mExecuteFreezeTimer;
    PlayerModelBaseMgr*             mpModelBaseMgr;
    sead::Vector3f                  _284;
    s32                             _290;                   // Interpolation source for the below; 1 = ankle joints center pos, everything else = player pos
    s32                             _294;                   // Time value for the below
    sead::Vector3f                  _298;                   // Some position that gets linearly interpolated towards from either player pos or ankle joints center pos
    s32                             _2A4;
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
    s8                              mUnkPlayerNo;
    s8                              mTreadCnt;
    u8                              mSlipComboCnt;
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
    SurfaceType                     mSurfaceType;
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
    s32                             _1ba0;
    f32                             _1ba4;
    f32                             _1ba8;
    f32                             _1bac;
    f32                             _1bb0;
    s32                             _1bb4;
    ActorCollisionCheck             mCollisionCheck2_React; // First collision check is also for react
    ActorCollisionCheck             mCollisionCheck3_React;
    ActorCollisionCheck             mCollisionCheck4_Attack;
    ActorCollisionCheck             mCollisionCheck5_Attack;
    PlayerBaseCB                    mCollisionHitCallback;
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
    u32                             _20a4[2];               // TODO: Figure out if this is a SafeArray
    f32                             _20ac[2];               // ^^^
    FStateMgr<PlayerBase>           mDemoStateMgr;
    u32                             mChangeDemoStateParam;
    sead::BitFlag32                 mDemoTypeFlag;
    s32                             mDemoMode;              // TODO: Union
    s32                             mDemoAction;            // ^^^
    u32                             _20e8;
    u32                             _20ec;
    ActorUniqueID                   mPlayerJumpDaiID;
    s32                             mDstNextGotoID;
    s32                             mCreateAction;          // i.e., NextGoto types, TODO: enum
    u32                             _20fc;
    sead::Vector2f                  _2100;                  // Target for movement in a specific direction
    sead::Vector2f                  _2108;                  // Speed ^^^
    sead::Vector3f                  mFaderPos;
    bool                            mIsLastPlayer;          // Maybe?
    f32                             _2120;
    f32                             _2124;
    u32                             _2128;
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
    u32                             mChangeStateParam;
    ActionType                      mAction;
    s32                             mActionTimer;
    u32                             mStunMode;
    ActorUniqueID                   mRideActorID;
    s32                             _21d8;
    u32                             _21dc;
    s32                             _21e0;
    s32                             _21e4;
    s32                             _21e8;
    u32                             _21ec;
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
    SurfaceType                     mTurnBrakeSurfaceType;
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
