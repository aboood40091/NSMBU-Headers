#pragma once

#include <system/LineNodeMgr.h>

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <math/seadBoundBox.h>
#include <math/seadVector.h>
#include <prim/seadBitFlag.h>

class Actor;
class ActorCollisionTouchDrcCallback;

class ActorCollisionCheck : public sead::IDisposer  // vtbl Address: 0x10041C18
{
public:
    enum Shape
    {
        cShape_Box      = 0,
        cShape_Circle,
        cShape_DaikeiUD,    // Vertical Trapezoid
        cShape_DaikeiLR     // Horizontal Trapezoid
    };
    static_assert(sizeof(Shape) == 4);

    enum Type
    {
        cType_PlayerReact   = 0,
        cType_PlayerAttack,
        cType_Yoshi,
        cType_Enemy,
        cType_Balloon,
        cType_Collect,      // CollectionCoin or Item
        cType_Bullet,       // Projectiles, such as Fire Ball and Ice Ball
        cType_CannonBullet, // Cannonballs, as well as Bullet Bills
        cType_GoalPole,
        cType_ChibiYoshi,
        cType_Unk10,
        cType_DrcTouch,
        cType_Unk12,
        cType_Unk13,
        cType_Unk14,
        cType_Num,
    };
    static_assert(sizeof(Type) == 4);
    static_assert(cType_Num == 15);

    enum TypeMask
    {
        cTypeMask_PlayerReact   = 1 << cType_PlayerReact,
        cTypeMask_PlayerAttack  = 1 << cType_PlayerAttack,
        cTypeMask_Yoshi         = 1 << cType_Yoshi,
        cTypeMask_Enemy         = 1 << cType_Enemy,
        cTypeMask_Balloon       = 1 << cType_Balloon,
        cTypeMask_Collect       = 1 << cType_Collect,
        cTypeMask_Bullet        = 1 << cType_Bullet,
        cTypeMask_CannonBullet  = 1 << cType_CannonBullet,
        cTypeMask_GoalPole      = 1 << cType_GoalPole,
        cTypeMask_ChibiYoshi    = 1 << cType_ChibiYoshi,
        cTypeMask_Unk10         = 1 << cType_Unk10,
        cTypeMask_DrcTouch      = 1 << cType_DrcTouch,
        cTypeMask_Unk12         = 1 << cType_Unk12,
        cTypeMask_Unk13         = 1 << cType_Unk13,
        cTypeMask_Unk14         = 1 << cType_Unk14,

        cTypeMask_None          = 0,
        cTypeMask_All           = 0xFFFFFFFF
    };
    static_assert(sizeof(TypeMask) == 4);

    enum Attack
    {
        cAttack_Generic         = 0,
        cAttack_Fire,
        cAttack_Ice,
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
        cAttack_YoshiTongue,
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

    enum AttackMask
    {
        cAttackMask_Generic         = 1 << cAttack_Generic,
        cAttackMask_Fire            = 1 << cAttack_Fire,
        cAttackMask_Ice             = 1 << cAttack_Ice,
        cAttackMask_Star            = 1 << cAttack_Star,
        cAttackMask_IceBreak        = 1 << cAttack_IceBreak,
        cAttackMask_Slip            = 1 << cAttack_Slip,
        cAttackMask_KoopaFire       = 1 << cAttack_KoopaFire,
        cAttackMask_HipAttack       = 1 << cAttack_HipAttack,
        cAttackMask_NetPunch        = 1 << cAttack_NetPunch,
        cAttackMask_Shell           = 1 << cAttack_Shell,
        cAttackMask_PenguinSlip     = 1 << cAttack_PenguinSlip,
        cAttackMask_Spin            = 1 << cAttack_Spin,

        cAttackMask_SpinFall        = 1 << cAttack_SpinFall,
        cAttackMask_Explosion       = 1 << cAttack_Explosion,
        cAttackMask_YoshiTongue     = 1 << cAttack_YoshiTongue,
        cAttackMask_YoshiMouth      = 1 << cAttack_YoshiMouth,
        cAttackMask_Cannon          = 1 << cAttack_Cannon,
        cAttackMask_SpinLiftUp      = 1 << cAttack_SpinLiftUp,
        cAttackMask_YoshiBullet     = 1 << cAttack_YoshiBullet,
        cAttackMask_YoshiFire       = 1 << cAttack_YoshiFire,
        cAttackMask_YoshiIce        = 1 << cAttack_YoshiIce,
        cAttackMask_Intermittent    = 1 << cAttack_Intermittent,
        cAttackMask_ChibiYoshiAwa   = 1 << cAttack_ChibiYoshiAwa,

        cAttackMask_Unk25           = 1 << cAttack_Unk25,
        cAttackMask_ChibiYoshiLight = 1 << cAttack_ChibiYoshiLight,
        cAttackMask_Unk27           = 1 << cAttack_Unk27,

        cAttackMask_None            = 0,
        cAttackMask_All             = 0xFFFFFFFF
    };
    static_assert(sizeof(AttackMask) == 4);

    typedef void (*HitCallback)(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    struct Info
    {
        enum Flag
        {
            cFlag_Unk0      = 1 << 0,
            cFlag_Passive   = 1 << 2,   // If set, this instance does not trigger other instances
            cFlag_Unk9      = 1 << 9,
            cFlag_Unk12     = 1 << 12,

            cFlag_None      = 0
        };
        static_assert(sizeof(Flag) == 4);

        f32         center_offset_x;
        f32         center_offset_y;
        f32         half_size_x;
        f32         half_size_y;
        Shape       shape;
        Type        type;               // Type of the owner of this instance
        Attack      attack;             // Type of attack this instance performs
        TypeMask    type_mask;          // Mask of owner types to interact with
        AttackMask  attack_mask;        // Mask of attack types to receive
        Flag        flag;               // Sets allowed interactions, such as being pick-able
        HitCallback callback;

        // Address: 0x10041BC0
        static const Info cDefault;
    };
    static_assert(sizeof(Info) == 0x2C);

public:
    // Address: 0x0219A960
    ActorCollisionCheck();
    // Address: 0x0219AB90
    virtual ~ActorCollisionCheck();

    // Address: 0x0219AF1C
    void set(Actor* p_owner, const Info& info, ActorCollisionTouchDrcCallback* p_touch_drc_callback = nullptr);
    // Address: 0x0219B010
    void set(Actor* p_owner, const Info& info, const sead::BitFlag8& collision_mask, ActorCollisionTouchDrcCallback* p_touch_drc_callback = nullptr);
    // Address: 0x0219B054
    void set(Actor* p_owner, const Info& info, const sead::BitFlag8& collision_mask, u8 layer, ActorCollisionTouchDrcCallback* p_touch_drc_callback = nullptr);

    void setCenterOffsetX(f32 center_offset_x)
    {
        mInfo.center_offset_x = center_offset_x;
    }

    void setCenterOffsetY(f32 center_offset_y)
    {
        mInfo.center_offset_y = center_offset_y;
    }

    void setCenterOffset(f32 center_offset_x, f32 center_offset_y)
    {
        mInfo.center_offset_x = center_offset_x;
        mInfo.center_offset_y = center_offset_y;
    }

    void setCenterOffset(const sead::Vector2f& center_offset)
    {
        setCenterOffset(center_offset.x, center_offset.y);
    }

    void setHalfSizeX(f32 half_size_x)
    {
        mInfo.half_size_x = half_size_x;
    }

    void setHalfSizeY(f32 half_size_y)
    {
        mInfo.half_size_y = half_size_y;
    }

    void setHalfSize(f32 half_size_x, f32 half_size_y)
    {
        mInfo.half_size_x = half_size_x;
        mInfo.half_size_y = half_size_y;
    }

    void setHalfSize(const sead::Vector2f& half_size)
    {
        setHalfSize(half_size.x, half_size.y);
    }

    void setIndex(u32 index)
    {
        mIndex = index;
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

    s32 getIndex() const
    {
        return mIndex;
    }

    bool isInactive() const
    {
        return mFlag & 2;
    }

    void setInactive()
    {
        mFlag |= 2;
    }

    bool isCollidable() const
    {
        return mCollisionMask.getDirect() != 0;
    }

    ActorCollisionTouchDrcCallback* getTouchDrcCallback() const
    {
        return mpTouchDrcCallback;
    }

    const Info& getInfo() const
    {
        return mInfo;
    }

    f32 getDaikei(s32 index) const
    {
        return mDaikei[index];
    }

    f32 getIntersectionX(Type type) const
    {
        return mIntersectionX[type];
    }

    f32 getIntersectionY(Type type) const
    {
        return mIntersectionY[type];
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
    sead::Vector2f                  _4C;
    sead::Vector2f                  _54;
    TypeMask                        mHit;               // Owner types of others we've collided with
    AttackMask                      mAttacksPerformed;  // Attacks performed on non-passive others
    AttackMask                      mAttacksReceived;   // Attacks received from non-passive others
    u32                             mIndex;
    sead::BitFlag8                  mCollisionMask;
    u8                              mLayer;
    u8                              mFlag;
    ActorCollisionTouchDrcCallback* mpTouchDrcCallback;
    Info                            mInfo;
    sead::SafeArray<f32, 4>         mDaikei;
    sead::SafeArray<f32, cType_Num> mIntersectionX;
    sead::SafeArray<f32, cType_Num> mIntersectionY;
};
static_assert(sizeof(ActorCollisionCheck) == 0x128);

inline ActorCollisionCheck::TypeMask operator|(const ActorCollisionCheck::TypeMask& lhs, const ActorCollisionCheck::TypeMask& rhs)
{
    return (ActorCollisionCheck::TypeMask)((u32)lhs | (u32)rhs);
}

inline ActorCollisionCheck::TypeMask& operator|=(ActorCollisionCheck::TypeMask& lhs, const ActorCollisionCheck::TypeMask& rhs)
{
    lhs = lhs | rhs;
    return lhs;
}

inline ActorCollisionCheck::TypeMask operator~(const ActorCollisionCheck::TypeMask& val)
{
    return (ActorCollisionCheck::TypeMask)(~(u32)val);
}

inline ActorCollisionCheck::AttackMask operator|(const ActorCollisionCheck::AttackMask& lhs, const ActorCollisionCheck::AttackMask& rhs)
{
    return (ActorCollisionCheck::AttackMask)((u32)lhs | (u32)rhs);
}

inline ActorCollisionCheck::AttackMask& operator|=(ActorCollisionCheck::AttackMask& lhs, const ActorCollisionCheck::AttackMask& rhs)
{
    lhs = lhs | rhs;
    return lhs;
}

inline ActorCollisionCheck::AttackMask operator~(const ActorCollisionCheck::AttackMask& val)
{
    return (ActorCollisionCheck::AttackMask)(~(u32)val);
}

inline ActorCollisionCheck::Info::Flag operator|(const ActorCollisionCheck::Info::Flag& lhs, const ActorCollisionCheck::Info::Flag& rhs)
{
    return (ActorCollisionCheck::Info::Flag)((u32)lhs | (u32)rhs);
}

inline ActorCollisionCheck::Info::Flag& operator|=(ActorCollisionCheck::Info::Flag& lhs, const ActorCollisionCheck::Info::Flag& rhs)
{
    lhs = lhs | rhs;
    return lhs;
}
