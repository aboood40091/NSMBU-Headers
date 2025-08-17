#pragma once

#include <system/LineNodeMgr.h>

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <math/seadBoundBox.h>
#include <math/seadVector.h>
#include <prim/seadBitFlag.h>

enum CcLineKind
{
    cCcLineKind_0 = 1 << 0,
    cCcLineKind_1 = 1 << 1,
    cCcLineKind_2 = 1 << 2
};

class Actor;
class ActorCollisionTouchDrcCallback;

class ActorCollisionCheck : public sead::IDisposer  // vtbl Address: 0x10041C18
{
public:
    enum ShapeType
    {
        cShapeType_Box      = 0,
        cShapeType_Circle,
        cShapeType_DaikeiUD,    // Vertical Trapezoid
        cShapeType_DaikeiLR     // Horizontal Trapezoid
    };
    static_assert(sizeof(ShapeType) == 4);

    enum Kind
    {
        cKind_PlayerBody    = 0,
        cKind_PlayerAttack,
        cKind_Yoshi,
        cKind_Enemy,
        cKind_Balloon,
        cKind_Item,         // CollectionCoin or Item
        cKind_Tama,         // Projectiles, such as Fire Ball and Ice Ball
        cKind_Killer,       // Cannonballs, as well as Bullet Bills
        cKind_GoalPole,
        cKind_ChibiYoshi,
        cKind_Unk10,
        cKind_DrcTouch,
        cKind_Unk12,
        cKind_Unk13,
        cKind_Unk14,
        cKind_Num
    };
    static_assert(sizeof(Kind) == 4);
    static_assert(cKind_Num == 15);

    enum TargetKind
    {
        cTargetKind_PlayerBody      = 1 << cKind_PlayerBody,
        cTargetKind_PlayerAttack    = 1 << cKind_PlayerAttack,
        cTargetKind_Yoshi           = 1 << cKind_Yoshi,
        cTargetKind_Enemy           = 1 << cKind_Enemy,
        cTargetKind_Balloon         = 1 << cKind_Balloon,
        cTargetKind_Item            = 1 << cKind_Item,
        cTargetKind_Tama            = 1 << cKind_Tama,
        cTargetKind_Killer          = 1 << cKind_Killer,
        cTargetKind_GoalPole        = 1 << cKind_GoalPole,
        cTargetKind_ChibiYoshi      = 1 << cKind_ChibiYoshi,
        cTargetKind_Unk10           = 1 << cKind_Unk10,
        cTargetKind_DrcTouch        = 1 << cKind_DrcTouch,
        cTargetKind_Unk12           = 1 << cKind_Unk12,
        cTargetKind_Unk13           = 1 << cKind_Unk13,
        cTargetKind_Unk14           = 1 << cKind_Unk14,

        cTargetKind_Player          = cTargetKind_PlayerBody | cTargetKind_PlayerAttack | cTargetKind_Yoshi,

        cTargetKind_None            = 0,
        cTargetKind_All             = 0xFFFFFFFF
    };
    static_assert(sizeof(TargetKind) == 4);

    enum Attack
    {
        cAttack_Generic            = 0,
        cAttack_FireBall,
        cAttack_IceBall,
        cAttack_Star,
        cAttack_IceBreak,
        cAttack_Slip,
        cAttack_KoopaFire,
        cAttack_HipAttack,
        cAttack_NetPunch,
        cAttack_Shell,
        cAttack_PenguinSlip,
        cAttack_Spin,

        cAttack_SpinFall        = 13,
        cAttack_Explosion,
        cAttack_YoshiEat,
        cAttack_YoshiMouth,
        cAttack_Cannon,
        cAttack_SpinLiftUp,
        cAttack_YoshiBullet,
        cAttack_YoshiFire,
        cAttack_YoshiIce,
        cAttack_Intermittent,
        cAttack_ChibiYoshiAwa,

        cAttack_Unk25           = 25,
        cAttack_ChibiYoshiLight,
        cAttack_Unk27,
        // ... ?
    };
    static_assert(sizeof(Attack) == 4);

    enum DamageFrom
    {
        cDamageFrom_Generic         = 1 << cAttack_Generic,
        cDamageFrom_FireBall        = 1 << cAttack_FireBall,
        cDamageFrom_IceBall         = 1 << cAttack_IceBall,
        cDamageFrom_Star            = 1 << cAttack_Star,
        cDamageFrom_IceBreak        = 1 << cAttack_IceBreak,
        cDamageFrom_Slip            = 1 << cAttack_Slip,
        cDamageFrom_KoopaFire       = 1 << cAttack_KoopaFire,
        cDamageFrom_HipAttack       = 1 << cAttack_HipAttack,
        cDamageFrom_NetPunch        = 1 << cAttack_NetPunch,
        cDamageFrom_Shell           = 1 << cAttack_Shell,
        cDamageFrom_PenguinSlip     = 1 << cAttack_PenguinSlip,
        cDamageFrom_Spin            = 1 << cAttack_Spin,

        cDamageFrom_SpinFall        = 1 << cAttack_SpinFall,
        cDamageFrom_Explosion       = 1 << cAttack_Explosion,
        cDamageFrom_YoshiEat        = 1 << cAttack_YoshiEat,
        cDamageFrom_YoshiMouth      = 1 << cAttack_YoshiMouth,
        cDamageFrom_Cannon          = 1 << cAttack_Cannon,
        cDamageFrom_SpinLiftUp      = 1 << cAttack_SpinLiftUp,
        cDamageFrom_YoshiBullet     = 1 << cAttack_YoshiBullet,
        cDamageFrom_YoshiFire       = 1 << cAttack_YoshiFire,
        cDamageFrom_YoshiIce        = 1 << cAttack_YoshiIce,
        cDamageFrom_Intermittent    = 1 << cAttack_Intermittent,
        cDamageFrom_ChibiYoshiAwa   = 1 << cAttack_ChibiYoshiAwa,

        cDamageFrom_Unk25           = 1 << cAttack_Unk25,
        cDamageFrom_ChibiYoshiLight = 1 << cAttack_ChibiYoshiLight,
        cDamageFrom_Unk27           = 1 << cAttack_Unk27,

        cDamageFrom_None            = 0,
        cDamageFrom_All             = 0xFFFFFFFF
    };
    static_assert(sizeof(DamageFrom) == 4);

    enum Status
    {
        cStatus_Unk0    = 1 << 0,
        cStatus_Passive = 1 << 2,   // If set, this instance does not trigger other instances
        cStatus_Unk9    = 1 << 9,
        cStatus_Unk12   = 1 << 12,

        cStatus_None    = 0
    };
    static_assert(sizeof(Status) == 4);

    typedef void (*CallBack)(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    struct CollisionData
    {
        f32         center_offset_x;
        f32         center_offset_y;
        f32         half_size_x;
        f32         half_size_y;
        ShapeType   shape_type;
        Kind        kind;               // Type of the owner of this instance
        Attack      attack;             // Type of attack this instance performs
        TargetKind  vs_kind;            // Mask of owner types to interact with
        DamageFrom  vs_damage;          // Mask of attack types to receive
        Status      status;             // Sets allowed interactions, such as being pick-able
        CallBack    callback;

        // Address: 0x10041BC0
        static const CollisionData cDefault;
    };
    static_assert(sizeof(CollisionData) == 0x2C);

    enum Info
    {
        cInfo_NoHit = 2
    };
    static_assert(sizeof(Info) == 4);

public:
    // Address: 0x0219A960
    ActorCollisionCheck();
    // Address: 0x0219AB90
    virtual ~ActorCollisionCheck();

    // Address: 0x0219AF1C
    void set(Actor* p_owner, const CollisionData& collision_data, ActorCollisionTouchDrcCallback* p_touch_drc_callback = nullptr);
    // Address: 0x0219B010
    void set(Actor* p_owner, const CollisionData& collision_data, const sead::BitFlag8& collision_mask, ActorCollisionTouchDrcCallback* p_touch_drc_callback = nullptr);
    // Address: 0x0219B054
    void set(Actor* p_owner, const CollisionData& collision_data, const sead::BitFlag8& collision_mask, u8 layer, ActorCollisionTouchDrcCallback* p_touch_drc_callback = nullptr);

    void setCenterOffsetX(f32 center_offset_x)
    {
        mCollisionData.center_offset_x = center_offset_x;
    }

    void setCenterOffsetY(f32 center_offset_y)
    {
        mCollisionData.center_offset_y = center_offset_y;
    }

    void setCenterOffset(f32 center_offset_x, f32 center_offset_y)
    {
        mCollisionData.center_offset_x = center_offset_x;
        mCollisionData.center_offset_y = center_offset_y;
    }

    void setCenterOffset(const sead::Vector2f& center_offset)
    {
        setCenterOffset(center_offset.x, center_offset.y);
    }

    void setHalfSizeX(f32 half_size_x)
    {
        mCollisionData.half_size_x = half_size_x;
    }

    void setHalfSizeY(f32 half_size_y)
    {
        mCollisionData.half_size_y = half_size_y;
    }

    void setHalfSize(f32 half_size_x, f32 half_size_y)
    {
        mCollisionData.half_size_x = half_size_x;
        mCollisionData.half_size_y = half_size_y;
    }

    void setHalfSize(const sead::Vector2f& half_size)
    {
        setHalfSize(half_size.x, half_size.y);
    }

    void setDamageFrom(DamageFrom vs_damage)
    {
        mCollisionData.vs_damage = vs_damage;
    }

    void setIndex(u32 index)
    {
        mIndex = index;
    }

    void setLayer(u8 layer)
    {
        mLayer = layer;
    }

    void setTouchDrcCallback(ActorCollisionTouchDrcCallback* p_touch_drc_callback)
    {
        mpTouchDrcCallback = p_touch_drc_callback;
    }

    // Address: 0x0219B434
    f32 getTopPos() const;
    // Address: 0x0219B450
    f32 getUnderPos() const;
    // Address: 0x0219B46C
    f32 getCenterPosY() const;
    // Address: 0x0219B480
    f32 getRightPos() const;
    // Address: 0x0219B49C
    f32 getLeftPos() const;
    // Address: 0x0219B4B8
    f32 getCenterPosX() const;

    sead::Vector2f getCenterPos() const
    {
        return sead::Vector2f(getCenterPosX(), getCenterPosY());
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

    const sead::Vector2f& getDrcTouchPos() const
    {
        return mDrcTouchPos;
    }

    const sead::Vector2f& getHitPos() const
    {
        return mHitPos;
    }

    s32 getIndex() const
    {
        return mIndex;
    }

    u8 getLayer() const
    {
        return mLayer;
    }

    bool isInactive() const
    {
        return mInfo & cInfo_NoHit;
    }

    void setInactive()
    {
        mInfo |= cInfo_NoHit;
    }

    bool isCollidable() const
    {
        return mCollisionMask.getDirect() != 0;
    }

    ActorCollisionTouchDrcCallback* getTouchDrcCallback() const
    {
        return mpTouchDrcCallback;
    }

    const CollisionData& getCollisionData() const
    {
        return mCollisionData;
    }

    f32 getDaikei(s32 index) const
    {
        return mDaikei[index];
    }

    f32 getIntersectionX(Kind kind) const
    {
        return mIntersectionX[kind];
    }

    f32 getIntersectionY(Kind kind) const
    {
        return mIntersectionY[kind];
    }

    sead::BoundBox2f getBoundBox() const
    {
        return sead::BoundBox2f(
            sead::Vector2f(
                getLeftPos(),
                getUnderPos()
            ),
            sead::Vector2f(
                getRightPos(),
                getTopPos()
            )
        );
    }

    bool isOverlap(const ActorCollisionCheck& cc_other)
    {
        const sead::BoundBox2f& a = getBoundBox();
        const sead::BoundBox2f& b = cc_other.getBoundBox();

        const sead::Vector2f& min_a = a.getMin();
        const sead::Vector2f& min_b = b.getMin();

        const sead::Vector2f& max_a = a.getMax();
        const sead::Vector2f& max_b = b.getMax();

        return min_a.x < max_b.x && max_a.x > min_b.x &&
               min_a.y < max_b.y && max_a.y > min_b.y;
    }

private:
    typedef LineNodeMgr<ActorCollisionCheck> List;

    List::Node                      mExecuteNode;
    List::Node                      mCreateNode;
    List::Node                      mTouchDrcHoldNode;
    List::Node                      mTouchDrcCheckNode;
    Actor*                          mpOwner;
    Actor*                          mpFriend;   // Collisions with this are ignored
    u32                             _48;
    sead::Vector2f                  mDrcTouchPos;
    sead::Vector2f                  mHitPos;
    TargetKind                      mHit;               // Owner types of others we've collided with
    DamageFrom                      mAttacksPerformed;  // Attacks performed on non-passive others
    DamageFrom                      mAttacksReceived;   // Attacks received from non-passive others
    u32                             mIndex;
    sead::BitFlag8                  mCollisionMask;
    u8                              mLayer;
    u8                              mInfo;
    ActorCollisionTouchDrcCallback* mpTouchDrcCallback;
    CollisionData                   mCollisionData;
    sead::SafeArray<f32, 4>         mDaikei;
    sead::SafeArray<f32, cKind_Num> mIntersectionX;
    sead::SafeArray<f32, cKind_Num> mIntersectionY;
};
static_assert(sizeof(ActorCollisionCheck) == 0x128);

inline ActorCollisionCheck::TargetKind operator|(const ActorCollisionCheck::TargetKind& lhs, const ActorCollisionCheck::TargetKind& rhs)
{
    return (ActorCollisionCheck::TargetKind)((u32)lhs | (u32)rhs);
}

inline ActorCollisionCheck::TargetKind& operator|=(ActorCollisionCheck::TargetKind& lhs, const ActorCollisionCheck::TargetKind& rhs)
{
    lhs = lhs | rhs;
    return lhs;
}

inline ActorCollisionCheck::TargetKind operator~(const ActorCollisionCheck::TargetKind& val)
{
    return (ActorCollisionCheck::TargetKind)(~(u32)val);
}

inline ActorCollisionCheck::DamageFrom operator|(const ActorCollisionCheck::DamageFrom& lhs, const ActorCollisionCheck::DamageFrom& rhs)
{
    return (ActorCollisionCheck::DamageFrom)((u32)lhs | (u32)rhs);
}

inline ActorCollisionCheck::DamageFrom& operator|=(ActorCollisionCheck::DamageFrom& lhs, const ActorCollisionCheck::DamageFrom& rhs)
{
    lhs = lhs | rhs;
    return lhs;
}

inline ActorCollisionCheck::DamageFrom operator~(const ActorCollisionCheck::DamageFrom& val)
{
    return (ActorCollisionCheck::DamageFrom)(~(u32)val);
}

inline ActorCollisionCheck::Status operator|(const ActorCollisionCheck::Status& lhs, const ActorCollisionCheck::Status& rhs)
{
    return (ActorCollisionCheck::Status)((u32)lhs | (u32)rhs);
}

inline ActorCollisionCheck::Status& operator|=(ActorCollisionCheck::Status& lhs, const ActorCollisionCheck::Status& rhs)
{
    lhs = lhs | rhs;
    return lhs;
}
