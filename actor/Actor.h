#pragma once

#include <actor/ActorBase.h>
#include <collision/ActorCollisionCheck.h>
#include <utility/Angle3.h>
#include <utility/Direction.h>

#include <math/seadVector.h>

class ActorBgCollisionCheck;
class GenericChibiEatData;
class GenericEatData;
class PropelParts;

class Actor : public ActorBase  // vtbl Address: 0x10000268
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CBC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CC0
    SEAD_RTTI_OVERRIDE(Actor, ActorBase)

public:
    enum ActorType
    {
        cType_Actor = 0,
        cType_Player,
        cType_Yoshi,
        cType_Enemy,
        cType_ChibiYoshi
    };

public:
    // Address: 0x02000AC8
    Actor(const ActorCreateParam& param);
    // Address: 0x02000F18
    virtual ~Actor();

protected:
    // Address: 0x02000FB8
    void postCreate_(MainState state) override;

    // Address: 0x02000FE8
    s32 preExecute_() override;
    // Address: 0x020010BC
    void postExecute_(MainState state) override;

    // Address: 0x020011A0
    s32 preDraw_() override;

public:
    virtual void setPlayerNo(s8 id)
    {
        mPlayerNo = id;
    }

    s8 getPlayerNo() const
    {
        return mPlayerNo;
    }

    // Address: 0x020002CC
    virtual void removeCollisionCheck();
    // Address: 0x02000328
    virtual void reviveCollisionCheck();

    virtual ActorBgCollisionCheck* getBgCheck()
    {
        return nullptr;
    }

    virtual void vfAC()
    {
    }

    virtual bool isSpinLiftUpEnable()
    {
        return true;
    }

    virtual void setSpinLiftUpActor(Actor*)
    {
    }

    virtual void vfC4()
    {
    }

    virtual void vfCC()
    {
    }

    // Address: 0x02002AD8
    virtual void killAtGoal();
    // Address: 0x02002ADC
    virtual void splashWater(sead::Vector3f*);
    // Address: 0x02002AE0
    virtual void splashLava(sead::Vector3f*);
    // Address: 0x02000960
    virtual void splashLavaWave(sead::Vector3f*);
    // Address: 0x02002AE4
    virtual void splashPoison(sead::Vector3f*);
    // Address: 0x02001254
    virtual bool drawCullCheck();

    virtual void blockHitInit()
    {
    }

    ActorCollisionCheck& getCollisionCheck()
    {
        return mCollisionCheck;
    }

    const ActorCollisionCheck& getCollisionCheck() const
    {
        return mCollisionCheck;
    }

    u8 isVisible() const
    {
        return mIsVisible;
    }

    // Address: 0x020005A4
    s32 searchNearPlayer(sead::Vector2f& out); // Returns -1 if no player found
    // Address: 0x020005EC
    u8 directionToPlayerH(const sead::Vector3f& position);
    // Address: 0x020006B4
    u8 directionToPlayerV(const sead::Vector3f& position);
    // Address: 0x0200C7E4
    u8 directionToActorH(const Actor& other);
    // Address: 0x020007A0
    bool screenOutCheck(u16);

    const sead::Vector3f& getPos() const
    {
        return mPos;
    }

    const sead::Vector2f& getPos2D() const
    {
        return reinterpret_cast<const sead::Vector2f&>(mPos.x);
    }

protected:
    u32                     mDirection;
    u8                      mPlayerNo;
    u8                      mControllerLytPlayerNo;
    u8                      mLayer;                     // Inited to ActorCreateParam::layer
    sead::BitFlag8          mCollisionMask;
    f32                     mSpeedF;                    // Horizontal speed
    f32                     mSpeedFMax;                 // Maximum horizontal speed
    f32                     mAccelY;                    // Vertical acceleration
    f32                     mFallSpeedMax;              // Maximum fall speed
    f32                     mAccelF;                    // Horizontal acceleration
    sead::Vector3f          mPos;
    sead::Vector3f          mSpeed;
    sead::Vector3f          mSpeedMax;
    sead::Vector3f          mScale;
    Angle3                  mAngle;
    Angle3                  mAnglePrev;
    sead::Vector2f          mPosDelta;
    ActorCollisionCheck     mCollisionCheck;
    struct
    {
        sead::Vector2f  offset;
        sead::Vector2f  size;
    }                       mVisibleArea;               // Inited to ActorCreateInfo::spawn_range
    sead::Vector2f          mSize;
    f32                     _rectQ_0;                   // Inited to 256.0 + ActorCreateInfo::_18
    f32                     _rectQ_1;                   // Inited to 256.0 + ActorCreateInfo::_1A
    f32                     _destroyBoundDistanceLeft;  // Inited to  80.0 + ActorCreateInfo::_1C
    f32                     _destroyBoundDistanceRight; // Inited to  80.0 + ActorCreateInfo::_1E
    u8                      mAreaNo;
    u8                      mType;                      // ActorType
    u8                      mIsActive;
    u8                      mIsVisible;
    bool                    mIsNoRespawn;
    u8                      _211;
    u8                      _212;
    u8                      mEventID[2];
    u16                     mCreateFlag;                // Inited to ActorCreateInfo::flag
    u32                     mBumpDamageTimer;
    u32                     _21c;
    u32                     _220;
    u32                     _224;
    u32                     _228;
    u32                     mKillStreak;
    u32                     mProfFlag;                  // Inited to Profile::mFlag
    sead::Vector3f          mCenterPos;
    sead::Vector3f          mPosPrev;
    sead::Vector3f          _24c;
    sead::Vector3f          _258;
    GenericEatData*         mpEatData;
    GenericChibiEatData*    mpChibiEatData;
    PropelParts*            mpPropelParts;
    u8*                     _270;                       // Inited to ActorCreateParam::_28
    f32                     mJumpAddSpeed;
    void*                   mpChibiBubbleData;
};
static_assert(sizeof(Actor) == 0x27C);
