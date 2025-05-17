#pragma once

#include <actor/Actor.h>
#include <collision/ActorBgCollisionPlayerCheck.h>
#include <player/PlayerEnum.h>
#include <player/PlayerKey.h>
#include <state/FStateMgr.h>

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
        cStatus_MaxBitNum = (cStatus_LastBit + 31) / 32 * 32
    };

    enum VineAction
    {
        cVineAction_Ivy     = 0,
        cVineAction_Net,
        cVineAction_Attack,
        cVineAction_Roll
    };
    static_assert(sizeof(VineAction) == 4);

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

    // Address: 0x028F37A8
    bool isTotten() const;

    // Address: 0x028F4D48
    bool setJump(u8, u32);

    // Address: 0x029065F0
    Angle getMukiAngle(u32 dir);

    // Address: 0x0290B9A4
    void startSound(const char* label, u32 = 0);

protected:
    u32                         _27c[(0x2A8 - 0x27C) / sizeof(u32)];
    PlayerKey                   mPlayerKey;
    u32                         _33c[(0x490 - 0x33C) / sizeof(u32)];
    Bitfield<cStatus_MaxBitNum> mStatus;
    u32                         _4b4[(0x500 - 0x4B4) / sizeof(u32)];
    PlayerMode                  mMode;
    ActorBgCollisionPlayerCheck mBgCheckPlayer;
    u32                         _1aa8[(0x1ACC - 0x1AA8) / sizeof(u32)];
    u32                         _1acc;
    u32                         _1ad0[(0x219C - 0x1AD0) / sizeof(u32)];
    FStateMgr<PlayerBase>       mStateMgr;
    void*                       mpChangeStateJmpInf;
    u32                         mChangeStateParam;
    union
    {
        VineAction  vine;
    }                           mAction;
    s32                         mActionTimer;
    u32                         mStunMode;
    ActorUniqueID               mRideActorID;
    u32                         _21d8[(0x2750 - 0x21D8) / sizeof(u32)];
};
static_assert(sizeof(PlayerBase) == 0x2750);
