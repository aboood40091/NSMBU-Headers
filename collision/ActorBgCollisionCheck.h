#pragma once

#include <actor/ActorUniqueID.h>
#include <collision/ActorBgHitCheckCallback.h>
#include <collision/BasicBgCollisionCheck.h>
#include <collision/BgCheckUnitInfo.h>
#include <collision/FollowArg.h>
#include <map/WaterType.h>
#include <system/LineNodeMgr.h>
#include <utility/Angle.h>
#include <utility/Direction.h>

#include <container/seadPtrArray.h>
#include <container/seadSafeArray.h>
#include <math/seadBoundBox.h>
#include <prim/seadMemUtil.h>
#include <prim/seadRuntimeTypeInfo.h>

class BgCollision;

class ActorBgCollisionCheckResult
{
public:
    // Address: 0x0218A4D0
    ActorBgCollisionCheckResult();

    // Address: 0x0218A5B4
    void initialize();

    // Address: 0x0218A608
    BgCollision* getOwner() const;
    // Address: 0x0218A658
    void setOwner(BgCollision*);

private:
    u8              _0;
    u8              _1;
    u8              _2;
    u8              _3;
    u32             _4;
    Angle           mAngle;
    sead::Vector2f  _c;
    sead::Vector2f  _14;
    ActorUniqueID   mActorUniqueID;
    BgCollision*    mpOwner;
  //u32             _24[4 / sizeof(u32)];   // Alignment???
    BgCheckUnitInfo mBgCheckData;
    f32             _30;
    u32             _34;
};
static_assert(sizeof(ActorBgCollisionCheckResult) == 0x38);

class Actor;

class ActorBgCollisionCheck // vtbl Address: 0x10041364
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: Deleted
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: Deleted
    SEAD_RTTI_BASE(ActorBgCollisionCheck)

public:
    class Output
    {
    public:
        enum Flag
        {
            cFlag_OnGround          = 1 <<  0,
            cFlag_OnSlope           = 1 <<  1,
            cFlag_OnRide            = 1 <<  4,
            cFlag_HeadCollision     = 1 << 10,
            cFlag_Unk16             = 1 << 16,
            cFlag_WallRCollision    = 1 << 18,
            cFlag_WallLCollision    = 1 << 19,
            cFlag_Unk22             = 1 << 22,  // Right Wall related
            cFlag_Unk23             = 1 << 23,  // Left Wall related
            cFlag_Unk28             = 1 << 28,  // Right Wall related
            cFlag_Unk29             = 1 << 29   // Left Wall related
        };

    public:
        Output()
        {
            sead::MemUtil::fillZero(&mFlag, sizeof(mFlag));
        }

        u32 get() const { return mFlag; }

        bool checkFoot()        const { return mFlag & cFlag_OnGround; }
        bool checkHead()        const { return mFlag & cFlag_HeadCollision; }
        bool checkRightWall()   const { return mFlag & cFlag_WallRCollision; }
        bool checkLeftWall()    const { return mFlag & cFlag_WallLCollision; }

        bool checkWall(u8 direction) const
        {
            switch (direction)
            {
            case DIRECTION_RIGHT:   return checkRightWall();
            case DIRECTION_LEFT:    return checkLeftWall();
            default:                return false;
            }
        }

        bool checkHeadEx() const
        {
            return checkHead() && !(mFlag & cFlag_Unk16);
        }

        bool checkRightWallEx() const
        {
            return (checkRightWall() || (mFlag & cFlag_Unk22)) && !(mFlag & cFlag_Unk28);
        }

        bool checkLeftWallEx() const
        {
            return (checkLeftWall() || (mFlag & cFlag_Unk23)) && !(mFlag & cFlag_Unk29);
        }

        bool checkWallEx(u8 direction) const
        {
            return ((mFlag & (1 << (18 + direction))) || (mFlag & (1 << (22 + direction)))) && !(mFlag & (1 << (28 + direction)));
        }

    private:
        u32 mFlag;

        friend class ActorBgCollisionCheck;
    };
    static_assert(sizeof(Output) == 4);

    struct SensorFlag
    {
        SensorFlag()
        {
            sead::MemUtil::fillZero(_0, sizeof(_0));
        }

        u8 _0[8];
    };
    static_assert(sizeof(SensorFlag) == 8);

public:
    struct Sensor
    {
        f32 p1;
        f32 p2;
        f32 center_offset;
    };
    static_assert(sizeof(Sensor) == 0xC);

public:
    // Address: 0x0218A6EC
    ActorBgCollisionCheck();
    // Address: 0x0218ADFC
    virtual ~ActorBgCollisionCheck();

    // Address: 0x0218D954
    virtual void process();
    // Address: 0x0218E060
    virtual void reset();
    // Address: 0x0218E180
    virtual void vf34();
    virtual Actor* vf3C(f32) const = 0;
    virtual Actor* vf44(const BgCollision&, s32) const = 0;
    virtual u8* vf4C(f32) const = 0;
    // Address: 0x0219070C
    virtual void vf54();
    // Address: 0x02190C14
    virtual void checkFoot();
    // Address: 0x02191054
    virtual void checkHead();
    // Address: 0x02191494
    virtual void checkWall(u8 direction);

    // Address: 0x0218AF6C
    void set(Actor* p_owner, const Sensor* p_foot, const Sensor* p_head, const Sensor* p_wall);

    Actor* getOwner() const
    {
        return mpOwner;
    }

    // Address: 0x0218AEFC
    void setSensor(const Sensor* sensor, u8 direction);
    // Address: 0x0218CE74
    const Sensor* getSensor(u8 direction) const;

    const FollowArg& getFollowArg() const { return mFollowArg; }
    const Output& getOutput() const { return mOutput; }

    static WaterType checkWater(const sead::Vector3f& pos, u8 layer);

protected:
    typedef LineNodeMgr<ActorBgCollisionCheck> List;

    BasicBgCollisionCheck                   mBgCheck;
    ActorBgHitCheckCallback                 mBgHitCheckCallback;
    sead::FixedPtrArray<BgCollision, 512>   _54;
    List::Node                              _860;
    List::Node                              _86c;
    List::Node                              _878;
    List::Node                              _884;
    Actor*                                  mpOwner;
    Actor*                                  mpIgnoreActor;  // Force mBgCheck to ignore BgCollision owned by this actor
    FollowArg                               mFollowArg;
    Output                                  mOutput;
    Output                                  _8b0;
    sead::BoundBox2f                        _8b4;
    sead::BoundBox2f                        _8c4;
    sead::BoundBox2f                        _8d4;
    sead::BoundBox2f                        _8e4;
    sead::BoundBox2f                        _8f4;
    sead::Vector2f                          _904;
    f32                                     _90c;
    u32                                     _910;
    u8                                      _914;
    bool                                    mIsInitialized;
    bool                                    _916;
    bool                                    _917;
    bool                                    _918;
    sead::UnsafeArray<bool, 4>              mIsSensor1Set;
    sead::UnsafeArray<bool, 4>              mIsSensor1Null;
    sead::UnsafeArray<bool, 4>              mIsSensor2Set;
    sead::UnsafeArray<Sensor, 4>            mSensor1;
    sead::UnsafeArray<Sensor, 4>            mSensor2;
    sead::UnsafeArray<Sensor, 4>            mSensor3;
    sead::UnsafeArray<Sensor, 2>            mSensor4;
    sead::UnsafeArray<bool, 2>              mIsSensor4Set;
    sead::UnsafeArray<u8, 2>                _9d2;
    sead::UnsafeArray<SensorFlag, 4>        mSensorFlag;
    sead::UnsafeArray<u32, 4>               _9f4;
    sead::UnsafeArray<u32, 4>               _a04;
    u32                                     _a14[4 / sizeof(u32)];
    sead::UnsafeArray<
        sead::UnsafeArray<
            ActorBgCollisionCheckResult,
            6
        >,
        4
    >                                       _a18;
    sead::UnsafeArray<
        sead::UnsafeArray<
            ActorBgCollisionCheckResult,
            6
        >,
        4
    >                                       _f58;
    sead::UnsafeArray<u8, 32>               _1498;
    sead::UnsafeArray<u8, 32>               _14b8;
    u32                                     _14d8;
};
static_assert(sizeof(ActorBgCollisionCheck) == 0x14E0);
