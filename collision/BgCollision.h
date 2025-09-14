#pragma once

#include <actor/Actor.h>
#include <collision/BgCollisionCat.h>
#include <collision/BgUnitCode.h>
#include <collision/FollowArg.h>
#include <system/LineNodeMgr.h>
#include <utility/Angle.h>

#include <math/seadMatrix.h>

class   ActorBgCollisionCheck;
class   ActorBgCollisionCheckResult;
class   BasicBgCollisionCheck;
struct  BgCollisionCheckResultArea;
class   ActorCollisionDrcTouchCallback;

class BgCollision : public sead::IDisposer  // vtbl Address: 0x10042528
{
public:
    typedef LineNodeMgr<ActorBgCollisionCheck> BcList;

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
    virtual bool checkAreaBasic(BgCollisionCheckResultArea* p_res, const BasicBgCollisionCheck& bc, const sead::Vector2f& p0, const sead::Vector2f& p1, u8 hit_dir_mask) = 0;
    virtual bool checkAreaActor(ActorBgCollisionCheckResult*, sead::Vector2f*, sead::Vector2f*, u8 direction, ActorBgCollisionCheck*) = 0;
    virtual bool checkPointInside(bool* p_on_edge, const sead::Vector2f& p) const = 0;
    virtual bool vf5C(u32*) = 0;
    // Address: 0x021A680C
    virtual void vf64();
    virtual void vf6C() = 0;
    virtual void onBgCheckDataChange(const u64& bc_data) = 0;
    virtual bool checkPointInsideOrWithinDistance(const sead::Vector2f& p, f32 distance) const = 0;

    const sead::BoundBox2f getAffectedArea() const
    {
        return mAffectedArea;
    }

    Actor* getOwner() const
    {
        return mpOwner;
    }

    template <typename T>
    T* getOwner() const
    {
        return sead::DynamicCast<T>(mpOwner);
    }

    Actor* getIgnoreActor() const
    {
        return mpIgnoreActor;
    }

    const FollowArg& getFollowArg() const
    {
        return mFollowArg;
    }

    sead::Vector2f& getPosOffset()
    {
        return mPosOffset;
    }

    const sead::Vector2f& getPosOffset() const
    {
        return mPosOffset;
    }

    const sead::Vector2f& getPosOffset2() const
    {
        return mPosOffset2;
    }

    sead::Vector2f& getTypeOffset()
    {
        return mTypeOffset;
    }

    const sead::Vector2f& getTypeOffset() const
    {
        return mTypeOffset;
    }

    f32 getPosX() const
    {
        return mFollowArg.p_position->x + mPosOffset.x;
    }

    f32 getPosY() const
    {
        return mFollowArg.p_position->y + mPosOffset.y;
    }

    sead::Vector2f getPos() const
    {
        // Not inline in NSMB2
        return *reinterpret_cast<sead::Vector2f*>(mFollowArg.p_position) + mPosOffset;
    }

    f32 getPosPrevX() const
    {
        return mFollowArg.p_position_prev->x + mPosOffsetPrev.x;
    }

    f32 getPosPrevY() const
    {
        return mFollowArg.p_position_prev->y + mPosOffsetPrev.y;
    }

    sead::Vector2f getPosPrev() const
    {
        // Not inline in NSMB2
        return *reinterpret_cast<sead::Vector2f*>(mFollowArg.p_position_prev) + mPosOffsetPrev;
    }

    f32 getTypePosX() const
    {
        return getPosX() + mTypeOffset.x;
    }

    f32 getTypePosY() const
    {
        return getPosY() + mTypeOffset.y;
    }

    sead::Vector2f getTypePos() const
    {
        return getPos() + mTypeOffset;
    }

    f32 getTypePosPrevX() const
    {
        return getPosPrevX() + mTypeOffsetPrev.x;
    }

    f32 getTypePosPrevY() const
    {
        return getPosPrevY() + mTypeOffsetPrev.y;
    }

    sead::Vector2f getTypePosPrev() const
    {
        return getPosPrev() + mTypeOffsetPrev;
    }

    bool isInactive() const
    {
        return mIsInactive;
    }

    Angle getAngle() const
    {
        return mAngle;
    }

    void setAngle(Angle angle)
    {
        mAngle = angle;
    }

    const BcList& getBcListFoot() const
    {
        return mBcListFoot;
    }

    const BcList& getBcListHead() const
    {
        return mBcListHead;
    }

    const BcList& getBcListWallR() const
    {
        return mBcListWallR;
    }

    const BcList& getBcListWallL() const
    {
        return mBcListWallL;
    }

    // Address: 0x021A59F4
    void reset();
    // Address: 0x021A5598
    void clearBcList();

    // Address: 0x021A5A70
    void setType(Type type);    // Sets all parameters of mBgCheckData (see BgUnitCode)
    Type getType() const { return mType; }

    // Address: 0x021A5A04
    void setBgCheckData(const u64& bc_data);
    const u64& getBgCheckData() const { return mBgCheckData; }

    // Address: 0x021A5A90
    void setHitType(BgUnitCode::HitType hit_type);
    // Address: 0x021A5AD0
    void setAttr(BgUnitCode::Attr attr);
    // Address: 0x021A5B14
    void setSlipAttr(BgUnitCode::SlipAttr slip_attr);

    // Address: 0x021A5EB4
    void update();

    void setFlag(u32 flag)
    {
        mFlag.setDirect(flag);
    }

    void resetFlag(u32 mask)
    {
        mFlag.reset(mask);
    }

    void clearFlag()
    {
        mFlag.makeAllZero();
    }

    bool isFlag(s32 bit) const
    {
        return mFlag.isOnBit(bit);
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

    void setDrcTouchCallback(ActorCollisionDrcTouchCallback* p_drc_touch_callback)
    {
        mpDrcTouchCallback = p_drc_touch_callback;
    }

public:
    // Use this as default for mCheckRevFoot
    static bool CheckRevUpperSpeed(Actor* p_actor_self, Actor* p_actor_other)
    {
        return p_actor_self->getSpeedVec().y > 0.0f;
    }

    // Use this as default for mCheckRevHead
    static bool CheckRevUnderSpeed(Actor* p_actor_self, Actor* p_actor_other)
    {
        return p_actor_self->getSpeedVec().y < 0.0f;
    }

    // Use this as default for mCheckRevWall
    static bool CheckRevSideSpeed(Actor* p_actor_self, Actor* p_actor_other, u8 direction)
    {
        if (direction == cDirType_Right)
        {
            if (p_actor_self->getSpeedVec().x > 0.0f)
                return true;
        }
        else
        {
            if (p_actor_self->getSpeedVec().x < 0.0f)
                return true;
        }
        return false;
    }

protected:
    typedef LineNodeMgr<BgCollision> List;

    List::Node                      mActiveListNode;
    List::Node                      mSolidListNode;
    List::Node                      mNonSolidListNode;
    List::Node                      _34;
    List::Node                      mCoinListNode;
    List::Node                      mPoleListNode;
    List::Node                      mTouchDrcCheckNoDamageListNode;
    List::Node                      mTouchDrcHoldListNode;
    sead::BoundBox2f                mAffectedArea;  // Current Area & Prev Area
    sead::Vector2f                  mPosOffset2;    // Additional position offset set when area loop is on, not even used by all collision types...
    sead::BitFlag32                 mFlag;
    sead::BitFlag32                 mCheckRevFlag;  // ^^^
    Actor*                          mpOwner;
    Actor*                          mpIgnoreActor;  // Force BasicBgCollisionCheck owned by this actor to ignore this BgCollision
    FollowArg                       mFollowArg;
    sead::Vector2f                  mPosOffset;
    sead::Vector2f                  mPosOffsetPrev;
    sead::Vector2f                  mRotPivotOffset;
    sead::Vector2f                  mRotPivotOffsetPrev;
    sead::Vector2f                  mTypeOffset;
    sead::Vector2f                  mTypeOffsetPrev;
    bool                            mIsInactive;    // If true, forces BasicBgCollisionCheck to ignore this BgCollision
    BgCollisionCat                  mCategory;
    sead::Matrix22f                 mRotMtx;
    Angle                           mAngle;
    Angle                           mAnglePrev;
    BcList                          mBcListFoot;    // List of ActorBgCollisionCheck with foot sensor hitting this BgCollision
    BcList                          mBcListHead;    // List of ActorBgCollisionCheck with head sensor hitting this BgCollision
    BcList                          mBcListWallR;   // List of ActorBgCollisionCheck with right wall sensor hitting this BgCollision
    BcList                          mBcListWallL;   // List of ActorBgCollisionCheck with left wall sensor hitting this BgCollision
    Type                            mType;
    u64                             mBgCheckData;   // See BgUnitCode
    Callback                        mCallbackFoot;
    Callback                        mCallbackHead;
    CallbackWall                    mCallbackWall;
    CheckRev                        mCheckRevFoot;
    CheckRev                        mCheckRevHead;
    CheckRevWall                    mCheckRevWall;
    ActorCollisionDrcTouchCallback* mpDrcTouchCallback;
    u32                             _154;
};
static_assert(sizeof(BgCollision) == 0x158);
