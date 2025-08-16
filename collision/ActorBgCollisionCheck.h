#pragma once

#include <actor/ActorUniqueID.h>
#include <collision/ActorBgHitCheckCallback.h>
#include <collision/BasicBgCollisionCheck.h>
#include <collision/BgUnitCode.h>
#include <collision/FollowArg.h>
#include <map/WaterType.h>
#include <system/LineNodeMgr.h>
#include <utility/Angle.h>
#include <utility/Bitfield.h>
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
    u64             mBgCheckData;           // See BgUnitCode
    f32             _30;
    u32             _34;
};
static_assert(sizeof(ActorBgCollisionCheckResult) == 0x38);

class   Actor;
struct  BgCollisionCheckHitResult;

class ActorBgCollisionCheck // vtbl Address: 0x10041364
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: Deleted
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: Deleted
    SEAD_RTTI_BASE(ActorBgCollisionCheck)

public:
    enum SakaType
    {
        cSakaType_Num = 5
    };
    static_assert(sizeof(SakaType) == 4);

public:
    class Output : public Bitfield<32>
    {
    public:
        enum Bit
        {
            cBit_OnGround       =  0,
            cBit_OnSlope        =  1,
            cBit_OnTrampoline   =  3,
            cBit_OnRide         =  4,
            cBit_Unk5           =  5,
            cBit_Unk9           =  9,
            cBit_HeadCollision  = 10,
            cBit_Unk14          = 14,
            cBit_Unk16          = 16,
            cBit_Unk17          = 17,
            cBit_WallRCollision = 18,
            cBit_WallLCollision = 19,
            cBit_Unk22          = 22,   // Right Wall related
            cBit_Unk23          = 23,   // Left Wall related
            cBit_Unk24          = 24,
            cBit_Unk28          = 28,   // Right Wall related
            cBit_Unk29          = 29,   // Left Wall related
            cBit_Unk30          = 30,
            cBit_Unk31          = 31
        };

    public:
        bool checkFoot()        const { return isOnBit(cBit_OnGround); }
        bool checkHead()        const { return isOnBit(cBit_HeadCollision); }
        bool checkRightWall()   const { return isOnBit(cBit_WallRCollision); }
        bool checkLeftWall()    const { return isOnBit(cBit_WallLCollision); }

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
            return checkHead() && !isOnBit(cBit_Unk16);
        }

        bool checkRightWallEx() const
        {
            return (checkRightWall() || isOnBit(cBit_Unk22)) && !isOnBit(cBit_Unk28);
        }

        bool checkLeftWallEx() const
        {
            return (checkLeftWall() || isOnBit(cBit_Unk23)) && !isOnBit(cBit_Unk29);
        }

        bool checkWallEx(u8 direction) const
        {
            return (isOnBit(cBit_WallRCollision + direction) || isOnBit(cBit_Unk22 + direction)) && !isOnBit(cBit_Unk28 + direction);
        }

        bool isOnTrampoline() const
        {
            return isOnBit(cBit_OnTrampoline);
        }
    };
    static_assert(sizeof(Output) == 4);

    class SensorFlag : public Bitfield<64>
    {
    };
    static_assert(sizeof(SensorFlag) == 8);

public:
    struct Sensor
    {
        f32 p1;
        f32 p2;
        f32 center_offset;

        Sensor invert() const
        {
            Sensor inv = { p1, p2, -center_offset };
            return inv;
        }
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
    virtual void atFrameStart();
    virtual Actor* getOwnerAtRevCheck(f32 bg_collision_pos_y) const = 0;
    virtual Actor* getOwnerAtHit(const BgCollision& bg_collision, u8 direction) const = 0;  // direction: Which sensor was hit
    virtual s8* vf4C(f32) const = 0;
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

    SensorFlag& getSensorFlag(u8 direction)
    {
        return mSensorFlag[direction];
    }

    const SensorFlag& getSensorFlag(u8 direction) const
    {
        return mSensorFlag[direction];
    }

    const FollowArg& getFollowArg() const { return mFollowArg; }
    const Output& getOutput() const { return mOutput; }

    bool checkRide()
    {
        return getOutput().isOnBit(2);
    }

    bool isHit(u8 hit_dir_flag) const
    {
        return mHitDirectionFlag & hit_dir_flag;
    }

    // Address: 0x0218AC38
    BgCollision* getHitBgCollisionFoot() const;
    // Address: 0x0218ACA8
    BgCollision* getHitBgCollisionHead() const;
    // Address: 0x0218AD6C
    BgCollision* getHitBgCollisionWall(u32 direction) const;

    // Address: 0x0218F0C0
    static WaterType checkWater(f32* p_surface_pos_y, const sead::Vector3f& pos, u8 layer);
    // Address: 0x0218F72C
    static WaterType checkWater(f32* p_surface_pos_y, BgCollisionCheckHitResult* p_hit_result, const sead::Vector3f& pos, u8 layer);
    // Address: 0x0219047C
    static WaterType checkWater(const sead::Vector3f& pos, u8 layer);

    // Address: 0x021905c8
    static u32 checkWaterDepth(f32 x, f32 y, u8 layer);

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
    Actor*                                  mpIgnoreActor;      // Force mBgCheck to ignore BgCollision owned by this actor
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
    u8                                      mHitDirectionFlag;  // lower 4 bits: normal, upper 4 bits: boost block
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
