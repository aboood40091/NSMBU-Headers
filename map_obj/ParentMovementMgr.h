#pragma once

#include "types.h"
#include <state/FStateMgr.h>
#include <utility/Angle.h>

#include <math/seadVector.h>

enum ParentMovementType
{
    cPos_None                       = 0,
    cPos_CenterRotation             = 1,    // Pivotal Rotation
    cPos_Screw                      = 2,    // Bolt
    cPos_Rail                       = 3,    // Path
    cPos_GoAndCome                  = 4,    // Two Way
    //
    cPos_ScrewKinokoLift            = 6,    // Bolt Mushroom Lift
    cPos_ScrewKinokoLift_NoScrew    = 7,    // Bolt Mushroom Lift - No Bolt
    cPos_ShiftingPlatform           = 8,    // Shifting Rectangle Platform
    cPos_Gyration                   = 9,    // Spinning
    cPos_FloorGyration              = 10,   // Rolling Hill
    cPos_KinokoLift                 = 11,   // Mushroom Lift
};

enum BoltDirection : u32
{
    cBoltDirection_Right            = 0,
    cBoltDirection_Left             = 1,
    cBoltDirection_Up               = 2,
    cBoltDirection_Down             = 3,
};

enum RectPlatformInfo : u32
{
    cRectPlatformInfo_FollowTop     = 0,
    cRectPlatformInfo_FollowBottom  = 1,
    cRectPlatformInfo_FollowNone    = 2,
};


class ParentMovementMgr
{
public:
    struct MovementProperty
    {
        u32     _0;
        u32     _4;
        u32     _8;
        u32     _c;
        f32     hill_distance_offset;
    };
    static_assert(sizeof(MovementProperty) == 0x14);

public:
    ParentMovementMgr();

    void link(const sead::Vector3f& position, u32 type_mask, u8 movement_id);
    void execute();
    u32 getTypeMask(ParentMovementType type);

    DECLARE_STATE_ID(ParentMovementType, Search)
    DECLARE_STATE_ID(ParentMovementType, Move)

    const sead::Vector3f& getPosition() const
    {
        return mPosition;
    }

    ActorUniqueID getParentActorID() const
    {
        return mParentActorID;
    }

    Angle getAngle() const
    {
        return mAngle;
    }

    f32 getTwoWayDistanceMultiplier() const
    {
        return mTwoWayDistanceMultiplier;
    }

    Angle getFloorGyrationAngle() const
    {
        return mFloorGyrationAngle;
    }

    f32 getBoltSpeed() const
    {
        return mBoltSpeed;
    }

    BoltDirection getBoltDirection() const
    {
        return mBoltDirection;
    }

    RectPlatformInfo getRectPlatformInfo() const
    {
        return mRectPlatformInfo;
    }

    MovementProperty getMovementProperty() const
    {
        return mMovementProperties;
    }

    void setAngle(Angle settervar) 
    {
        mAngle = settervar;
    }

    void setTwoWayDistanceMultiplier(f32 settervar) 
    {
        mTwoWayDistanceMultiplier = settervar;
    }

    void setFloorGyrationAngle(Angle settervar) 
    {
        mFloorGyrationAngle = settervar;
    }

    void setBoltSpeed(f32 settervar) 
    {
        mBoltSpeed = settervar;
    }

    void setBoltDirection(BoltDirection settervar) 
    {
        mBoltDirection = settervar;
    }

    void setRectPlatformInfo(RectPlatformInfo settervar) 
    {
        mRectPlatformInfo = settervar;
    }

    void setMovementProperty(MovementProperty settervar) 
    {
        mMovementProperties = settervar;
    }

private:
    sead::Vector3f  mPosition;
    sead::Vector3f  _c;
    sead::Vector3f  _18;
    sead::Vector3f  _24;
    u32             _30;
    u32             _34;
    ActorUniqueID   mParentActorID;
    u32             _3c;
    u32             _40;
    u32             _44;
    u32             mTypeMask;
    u8              mMovementId;
    Angle           mAngle;
    u8              _54;
    f32             mTwoWayDistanceMultiplier;

private:
    u8  _5c[0x74-0x5C];

private:
    Angle               mFloorGyrationAngle;
    u32                 _78;
    u32                 _7c;
    u32                 _80;
    u8                  _84;
    u8                  _85;
    u8                  _86;
    u8                  _87;
    u8                  _88;
    u8                  _89;
    u32                 _8c;
    BoltDirection       mBoltDirection;
    f32                 mBoltSpeed;
    RectPlatformInfo    mRectPlatformInfo;

private:
    u32 _9c;
    u32 _a0;
    u32 _a4;
    u32 _a8;
    u32 _ac;
    u32 _b0;
    u32 _b4;
    u32 _b8;
    u32 _bc;

private:
    MovementProperty        mMovementProperties;

    FStateMgr<
        ParentMovementMgr
    >                       mFStateMgr;
};
static_assert(sizeof(ParentMovementMgr) == 0xF8);
