#pragma once

#include <collision/BgCheckUnitInfo.h>
#include <collision/FollowArg.h>
#include <system/LineNodeMgr.h>
#include <utility/Angle.h>

#include <heap/seadDisposer.h>
#include <math/seadBoundBox.h>
#include <math/seadMatrix.h>
#include <prim/seadRuntimeTypeInfo.h>

class Actor;
class ActorBgCollisionCheck;
class ActorBgCollisionCheckResult;
struct BgCollisionCheckResult;
class CollisionCallback;

class BgCollision : public sead::IDisposer  // vtbl Address: 0x10042528
{
public:
    typedef void (*Callback)(BgCollision*, ActorBgCollisionCheck*);
    typedef void (*CallbackWall)(BgCollision*, ActorBgCollisionCheck*, u8 direction);

    typedef bool (*CheckRev)(Actor*, Actor*);
    typedef bool (*CheckRevWall)(Actor*, Actor*, u8 direction);

    struct InitArg
    {
        sead::Vector2f          pos_offset;
        sead::Vector2f          rot_pivot_offset;
        const sead::Vector2f*   points;
        Angle                   angle;
    };
    static_assert(sizeof(InitArg) == 0x18);

    struct BoxInitArg
    {
        sead::Vector2f          pos_offset;
        sead::Vector2f          rot_pivot_offset;
        sead::Vector2f          left_top_offset;
        sead::Vector2f          right_under_offset;
        Angle                   angle;
    };
    static_assert(sizeof(BoxInitArg) == 0x24);

    struct CircleInitArg
    {
        sead::Vector2f          pos_offset;
        sead::Vector2f          rot_pivot_offset;
        sead::Vector2f          center_offset;
        f32                     radius;
        Angle                   angle;
    };
    static_assert(sizeof(CircleInitArg) == 0x20);

    struct EllipseInitArg
    {
        sead::Vector2f          pos_offset;
        sead::Vector2f          rot_pivot_offset;
        sead::Vector2f          center_offset;
        sead::Vector2f          half_size;          // Radii
        Angle                   angle;
    };
    static_assert(sizeof(EllipseInitArg) == 0x24);

    struct LineInitArg
    {
        sead::Vector2f          pos_offset;
        sead::Vector2f          rot_pivot_offset;
        sead::Vector2f          points[2];
        Angle                   angle;
    };
    static_assert(sizeof(LineInitArg) == 0x24);

    struct PoleRopeInitArg
    {
        sead::Vector2f          pos_offset;
        sead::Vector2f          rot_pivot_offset;
        sead::Vector2f          start_point;
        f32                     line_length;
        f32                     range;
        Angle*                  line_angles;
        Angle                   angle;
    };
    static_assert(sizeof(PoleRopeInitArg) == 0x28);

    enum Type
    {
        cType_Normal            = 0,
        cType_Coin              = 1,
        cType_GreenCoin         = 2,
        cType_BlueCoin          = 3,
        cType_CoinOutline       = 4,
        cType_Fence             = 5,
        cType_Vine              = 6,
        cType_QuestionBlock     = 7,
        cType_BrickBlock        = 8,
        cType_QuestionBlockBig  = 9,
        cType_BrickBlockBig     = 10,
        cType_BlockUsedBig      = 11,
        cType_BlockUsed         = 12,
        cType_WoodBlock         = 13,
        cType_StoneBlock        = 14,
        cType_RedBlock          = 15,
        cType_DonutBlock        = 16,
        cType_BoostBlock        = 17,
        cType_UnknownLiquid     = 18,
        cType_Water             = 19,
        cType_Lava              = 20,
        cType_Poison            = 21,
        cType_Quicksand         = 22,
        cType_Carpet            = 23,   // Unused
        cType_Leaves            = 24,   // Used by Palm Tree
        cType_Wood              = 25,   // Used by Floating Barrel
        cType_Cloud             = 26,   // Used by Bouncy Cloud
        cType_SwingingVine      = 27,
        cType_SwingingChain     = 28,
        cType_RopeLadder        = 29,
        cType_Ice               = 30,
        cType_BreakableIce      = 31,   // Used by frozen actors
        cType_BreakableIce2     = 32,   // Used by Portable Ice Block
        cType_GrrrolPassage     = 33,   // Used by Grrrol Passage and Grrrol Spawner
        cType_SpikesUp          = 34,
        cType_StreamCurrent     = 35,   // Used by Pipe Bubbles,    Bg Check Info Unit Kind = 26
        cType_AirshipHand       = 36,   // Used by Airship Hand,    Bg Check Info Unit Kind = 32
        cType_WaterGeyser       = 37,   // Used by Water Geyser,    Bg Check Info Unit Kind = 33
        cType_Unknown10         = 38,   // Used by Pipes,           Bg Check Info Unit Kind = Pipe, Bg Check Info Unit Param 0 = 36
        cType_SpineCoaster      = 39,   // Used by Spine Coaster,   Bg Check Info Unit Kind = 38
        cType_Urchin            = 40,   // Used by Urchin,          Bg Check Info Unit Kind = 39
        cType_InvisibleBlock    = 41
    };

public:
    // Address: 0x021A5184
    BgCollision();
    // Address: 0x021A5610
    virtual ~BgCollision();

    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9D2C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FA4
    SEAD_RTTI_BASE(BgCollision)

    // Address: 0x021A7688 (TODO: This should be inline)
    virtual bool vf24(u32*, u32);
    // Address: Deleted
    virtual u32 vf2C(u32*);
    virtual void vf34() = 0;
    virtual void execute() = 0;
    virtual bool vf44(BgCollisionCheckResult*, u8*, sead::Vector2f*, sead::Vector2f*, u8) = 0;
    virtual bool vf4C(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) = 0;
    virtual bool vf54(u8*, sead::Vector2f*) = 0;
    virtual bool vf5C(u32*) = 0;
    // Address: 0x021A680C
    virtual void vf64();
    virtual void vf6C() = 0;
    virtual void vf74(u32*) = 0;
    virtual bool vf7C(sead::Vector2f*, f32) = 0;

    const sead::BoundBox2f getAffectedArea() const
    {
        return mAffectedArea;
    }

    Actor* getOwner() const
    {
        return mOwner;
    }

    const FollowArg& getFollowArg() const
    {
        return mFollowArg;
    }

    f32 getPosX() const
    {
        return mFollowArg.position->x + mPosOffset.x;
    }

    f32 getPosY() const
    {
        return mFollowArg.position->y + mPosOffset.y;
    }

    Angle getAngle() const
    {
        return mAngle;
    }

    void setAngle(Angle angle)
    {
        mAngle = angle;
    }

    // Address: 0x021A5A70
    void setType(Type type);    // Sets all parameters of BgCheckUnitInfo

    // Address: 0x021A5A04
    void setBgCheckData(const BgCheckUnitInfo& bc_data);
    const BgCheckUnitInfo& getBgCheckData() const { return mBgCheckData; }

    // Address: 0x021A5A90
    void setSolidType(BgCheckUnitInfo::SolidType solid_type);
    // Address: 0x021A5AD0
    void setSurfaceType(BgCheckUnitInfo::SurfaceType surface_type);
    // Address: 0x021A5B14
    void setSlideType(BgCheckUnitInfo::SlideType slide_type);

    void setCallbackFlag(u32 flag)
    {
        mCallbackFlag.setDirect(flag);
    }

    void setCallback(Callback callback_foot, Callback callback_head, CallbackWall callback_wall)
    {
        mCallbackFoot = callback_foot;
        mCallbackHead = callback_head;
        mCallbackWall = callback_wall;
    }

    void setCheckRev(CheckRev check_rev_foot, CheckRev check_rev_head, CheckRevWall check_rev_wall)
    {
        mCheckRevFoot = check_rev_foot;
        mCheckRevHead = check_rev_head;
        mCheckRevWall = check_rev_wall;
    }

    void setCollisionCallback(CollisionCallback* callbacks)
    {
        mCallbacks = callbacks;
    }

protected:
    typedef LineNodeMgr<BgCollision> List;
    typedef LineNodeMgr<ActorBgCollisionCheck> BcList;

    List::Node          mActiveListNode;
    List::Node          mSolidListNode;
    List::Node          mNonSolidListNode;
    List::Node          _34;
    List::Node          mCoinListNode;
    List::Node          _4c;
    List::Node          _58;
    List::Node          _64;
    sead::BoundBox2f    mAffectedArea;  // Current Area & Prev Area
    sead::Vector2f      _80;
    sead::BitFlag32     mCallbackFlag;  // I assume
    sead::BitFlag32     mCheckRevFlag;  // ^^^
    Actor*              mOwner;
    Actor*              _94;
    FollowArg           mFollowArg;
    sead::Vector2f      mPosOffset;
    sead::Vector2f      mPosOffsetPrev;
    sead::Vector2f      mRotPivotOffset;
    sead::Vector2f      mRotPivotOffsetPrev;
    sead::Vector2f      mTypeOffset;
    sead::Vector2f      mTypeOffsetPrev;
    u8                  _dc;
    u32                 _e0;
    sead::Matrix22f     mRotMtx;
    Angle               mAngle;
    Angle               mAnglePrev;
    BcList              mBcListDown;
    BcList              mBcListUp;
    BcList              mBcListRight;
    BcList              mBcListLeft;
    Type                mType;
    BgCheckUnitInfo     mBgCheckData;
    Callback            mCallbackFoot;
    Callback            mCallbackHead;
    CallbackWall        mCallbackWall;
    CheckRev            mCheckRevFoot;
    CheckRev            mCheckRevHead;
    CheckRevWall        mCheckRevWall;
    CollisionCallback*  mCallbacks;
    u32                 _154;
};
static_assert(sizeof(BgCollision) == 0x158);
