#pragma once

#include <actor/ActorUniqueID.h>
#include <collision/ActorBgHitCheckCallback.h>
#include <collision/BasicBgCollisionCheck.h>
#include <collision/BgCollisionCat.h>
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
        cSakaType_None      = 0,    // Saka angle (abs): [0 deg, 7.0175 deg)
        cSakaType_Gentle,           // Saka angle (abs): [7.0175 deg, 20.3165 deg)
        cSakaType_Moderate,         // Saka angle (abs): [20.3165 deg, 35.7990 deg)
        cSakaType_Steep,            // Saka angle (abs): [35.7990 deg, 54.2010 deg)
        cSakaType_VerySteep,        // Saka angle (abs): >= 54.2010 deg
        cSakaType_Num
    };
    static_assert(sizeof(SakaType) == 4);
    static_assert(cSakaType_Num == 5);

    enum HitDirBit
    {
        cHitDirBit_Right = 0,
        cHitDirBit_Left,
        cHitDirBit_Up,
        cHitDirBit_Down,

        cHitDirBit_BoostBlock_Right,
        cHitDirBit_BoostBlock_Left,
        cHitDirBit_BoostBlock_Up,
        cHitDirBit_BoostBlock_Down
    };

public:
    class Output : public Bitfield<32>
    {
    public:
        enum Bit
        {
            cBit_OnGround       =  0,
            cBit_OnSlope        =  1,
            cBit_OnRide         =  2,   // If ActorBgCollisionCheckResult._3 is set and is standing
            cBit_OnTrampoline   =  3,
            cBit_OnHalf         =  4,   // If standing on surface with BgUnitCode::cHitType_Half
            cBit_Unk5           =  5,
            cBit_Unk6           =  6,
            cBit_OnHorzPipe     =  7,
            cBit_OnQuicksand    =  8,   // If standing on quicksand
            cBit_Unk9           =  9,
            cBit_HeadCollision  = 10,
            cBit_Unk13          = 13,   // If ActorBgCollisionCheckResult._3 is set and is hitting head
            cBit_Unk14          = 14,
            cBit_Unk15          = 15,
            cBit_InQuicksand    = 16,   // If fully submerged in quicksand (more specifically, head is hitting quicksand)
            cBit_Unk17          = 17,
            cBit_WallRCollision = 18,
            cBit_WallLCollision = 19,
            cBit_CarryRelatedR  = 20,
            cBit_CarryRelatedL  = 21,
            cBit_Unk22          = 22,   // Right Wall related
            cBit_Unk23          = 23,   // Left Wall related
            cBit_Unk24          = 24,
            cBit_Unk26          = 26,
            cBit_Unk27          = 27,
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
            case cDirType_Right:   return checkRightWall();
            case cDirType_Left:    return checkLeftWall();
            default:                return false;
            }
        }

        bool checkRide() const
        {
            return isOnBit(cBit_OnRide);
        }

        bool isOnQuicksand() const
        {
            return isOnBit(cBit_OnQuicksand);
        }

        bool isInQuicksand() const
        {
            return isOnBit(cBit_InQuicksand);
        }

        bool isQuicksand() const
        {
            return isOnQuicksand() || isInQuicksand();
        }

        bool checkHeadEx() const
        {
            return checkHead() && !isInQuicksand();
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

        void setFoot()
        {
            setBit(cBit_OnGround);
        }
    };
    static_assert(sizeof(Output) == 4);

    class SensorFlag : public Bitfield<64>
    {
    public:
        enum Bit
        {
            cBit_0  =  0,

            cBit_3  =  3,
            cBit_4,
            cBit_5,
            cBit_6,

            cBit_8  =  8,
            cBit_9,
            cBit_10,

            cBit_13 = 13,

            cBit_18 = 18,

            cBit_21 = 21,
            cBit_22,
            cBit_23,

            cBit_26 = 26,

            cBit_38 = 38,

            cBit_50 = 50,

            cBit_52 = 52
        };
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
    typedef sead::UnsafeArray<Sensor, cDirType_Num > SensorArray;
    typedef sead::UnsafeArray<bool,   cDirType_Num > SensorBoolArray;
    typedef sead::UnsafeArray<Sensor, cDirType_NumX> WallSensorArray;
    typedef sead::UnsafeArray<bool,   cDirType_NumX> WallSensorBoolArray;

    typedef sead::UnsafeArray<SensorFlag, cDirType_Num> SensorFlagArray;

    typedef sead::UnsafeArray<BgCollisionCat, cDirType_Num> SensorBgCollisionCatArray;

    typedef sead::UnsafeArray<ActorBgCollisionCheckResult, cBgCollisionCat_Num> BgCheckResultArray;
    typedef sead::UnsafeArray<BgCheckResultArray, cDirType_Num> SensorBgCheckResultArray;

    typedef sead::UnsafeArray<u64, cDirType_Num> SensorHitBgCheckDataArray; // See BgUnitCode

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

protected:
    // Address: 0x02190C14
    virtual void checkFoot_();
    // Address: 0x02191054
    virtual void checkHead_();
    // Address: 0x02191494
    virtual void checkWall_(u8 direction);

public:
    // Address: 0x0218AF6C
    void set(Actor* p_owner, const Sensor* p_foot, const Sensor* p_head, const Sensor* p_wall);

    Actor* getOwner() const
    {
        return mpOwner;
    }

    template <typename T>
    T* getOwner() const
    {
        return sead::DynamicCast<T>(mpOwner);
    }

    // Address: 0x0218AEFC
    void setSensor(const Sensor* sensor, u8 direction);
    // Address: 0x0218CE74
    const Sensor* getSensor(u8 direction) const;

    bool isSensor1Set(u8 direction) const
    {
        return mIsSensor1Set[direction];
    }

    bool isSensor1Null(u8 direction) const
    {
        return mIsSensor1Null[direction];
    }

    bool isSensor2Set(u8 direction) const
    {
        return mIsSensor2Set[direction];
    }

    const SensorArray& getSensorArray1() const
    {
        return mSensor1;
    }

    const SensorArray& getSensorArray2() const
    {
        return mSensor2;
    }

    SensorFlag& getSensorFlag(u8 direction)
    {
        return mSensorFlag[direction];
    }

    const SensorFlag& getSensorFlag(u8 direction) const
    {
        return mSensorFlag[direction];
    }

    const FollowArg& getFollowArg() const { return mFollowArg; }

    Output& getOutput() { return mOutput; }
    const Output& getOutput() const { return mOutput; }

    bool checkFoot() const
    {
        return getOutput().checkFoot();
    }

    bool checkHead() const
    {
        return getOutput().checkHeadEx();
    }

    bool checkWall(u8 direction) const
    {
        return getOutput().checkWallEx(direction);
    }

    bool checkRide() const
    {
        return getOutput().checkRide();
    }

    bool isQuicksand() const
    {
        return getOutput().isQuicksand();
    }

    const sead::Vector2f& getBgSpeed() const
    {
        return mBgSpeed;
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

    const u64& getBgCheckData(u32 direction) const
    {
        return mBgCheckData[direction];
    }

    const u64& getBgCheckDataPrev(u32 direction) const
    {
        return mBgCheckDataPrev[direction];
    }

    // Address: 0x0218B214
    Angle getSakaBaseAngle();
    // Address: 0x0218B254
    Angle getHeadSakaBaseAngle();
    // Address: 0x0218E260
    Angle getSakaAngle(s32 dir);
    // Address: 0x0218E28C
    Angle getHeadSakaAngle(s32 dir);

    BasicBgCollisionCheck& getBgCheck()
    {
        return mBgCheck;
    }

    const BasicBgCollisionCheck& getBgCheck() const
    {
        return mBgCheck;
    }

    // Address: 0x0218B90C
    void initBgCheck();

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
    List::Node                              mListNodeFoot;
    List::Node                              mListNodeHead;
    List::Node                              mListNodeWallR;
    List::Node                              mListNodeWallL;
    Actor*                                  mpOwner;
    Actor*                                  mpIgnoreActor;          // Force mBgCheck to ignore BgCollision owned by this actor
    FollowArg                               mFollowArg;
    Output                                  mOutput;
    Output                                  mOutputPrev;
    sead::BoundBox2f                        _8b4;
    sead::BoundBox2f                        _8c4;
    sead::BoundBox2f                        _8d4;
    sead::BoundBox2f                        _8e4;
    sead::BoundBox2f                        _8f4;
    sead::Vector2f                          mBgSpeed;
    f32                                     _90c;
    u32                                     _910;
    u8                                      mHitDirectionFlag;      // lower 4 bits: normal, upper 4 bits: boost block
    bool                                    mIsInitialized;
    bool                                    _916;
    bool                                    _917;
    bool                                    _918;
    SensorBoolArray                         mIsSensor1Set;
    SensorBoolArray                         mIsSensor1Null;
    SensorBoolArray                         mIsSensor2Set;
    SensorArray                             mSensor1;
    SensorArray                             mSensor2;
    SensorArray                             mSensor3;
    WallSensorArray                         mSensor4;
    WallSensorBoolArray                     mIsSensor4Set;
    WallSensorBoolArray                     mIsSensor4SetPrev;
    SensorFlagArray                         mSensorFlag;
    SensorBgCollisionCatArray               mBgCheckResultIdx;
    SensorBgCollisionCatArray               mBgCheckResultIdxPrev;
  //u32                                     _a14[4 / sizeof(u32)];  // Alignment???
    SensorBgCheckResultArray                mBgCheckResult;
    SensorBgCheckResultArray                mBgCheckResultPrev;
    SensorHitBgCheckDataArray               mBgCheckData;
    SensorHitBgCheckDataArray               mBgCheckDataPrev;
    u32                                     _14d8;
};
static_assert(sizeof(ActorBgCollisionCheck) == 0x14E0);
