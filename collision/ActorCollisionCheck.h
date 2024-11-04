#pragma once

#include <system/LineNodeMgr.h>

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <math/seadBoundBox.h>
#include <math/seadVector.h>
#include <prim/seadBitFlag.h>

class Actor;
class ActorCollisionHitCallback;

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
        cType_Generic   = 0,
        cType_Player,
        cType_Yoshi,
        cType_Enemy,
        cType_Unk4,
        cType_Unk5,
        cType_Unk6,
        cType_Unk7,
        cType_Unk8,
        cType_Unk9,
        cType_Unk10,
        cType_Unk11,
        // ...
    };
    static_assert(sizeof(Type) == 4);

    enum TypeMask
    {
        cTypeMask_Generic   = 1 << cType_Generic,
        cTypeMask_Player    = 1 << cType_Player,
        cTypeMask_Yoshi     = 1 << cType_Yoshi,
        cTypeMask_Enemy     = 1 << cType_Enemy,
        cTypeMask_Unk4      = 1 << cType_Unk4,
        cTypeMask_Unk5      = 1 << cType_Unk5,
        cTypeMask_Unk6      = 1 << cType_Unk6,
        cTypeMask_Unk7      = 1 << cType_Unk7,
        cTypeMask_Unk8      = 1 << cType_Unk8,
        cTypeMask_Unk9      = 1 << cType_Unk9,
        cTypeMask_Unk10     = 1 << cType_Unk10,
        cTypeMask_Unk11     = 1 << cType_Unk11,

        cTypeMask_None      = 0,
        cTypeMask_All       = 0xFFFFFFFF
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
        cAttack_YoshiEat,
        cAttack_YoshiMouth,
        cAttack_Cannon,
        cAttack_SpinLiftUp,
        cAttack_YoshiBullet,
        cAttack_YoshiFire,
        cAttack_YoshiIce,
        cAttack_Unk22,
        cAttack_Unk23,

        cAttack_ChibiYoshiGlow  = 26,
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
        cAttackMask_YoshiEat        = 1 << cAttack_YoshiEat,
        cAttackMask_YoshiMouth      = 1 << cAttack_YoshiMouth,
        cAttackMask_Cannon          = 1 << cAttack_Cannon,
        cAttackMask_SpinLiftUp      = 1 << cAttack_SpinLiftUp,
        cAttackMask_YoshiBullet     = 1 << cAttack_YoshiBullet,
        cAttackMask_YoshiFire       = 1 << cAttack_YoshiFire,
        cAttackMask_YoshiIce        = 1 << cAttack_YoshiIce,
        cAttackMask_Unk22           = 1 << cAttack_Unk22,
        cAttackMask_Unk23           = 1 << cAttack_Unk23,

        cAttackMask_ChibiYoshiGlow  = 1 << cAttack_ChibiYoshiGlow,

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
    void set(Actor* p_owner, const Info& info, ActorCollisionHitCallback* p_actor_hit_callback = nullptr);
    // Address: 0x0219B010
    void set(Actor* p_owner, const Info& info, const sead::BitFlag8& collision_mask, ActorCollisionHitCallback* p_actor_hit_callback = nullptr);
    // Address: 0x0219B054
    void set(Actor* p_owner, const Info& info, const sead::BitFlag8& collision_mask, u8 layer, ActorCollisionHitCallback* p_actor_hit_callback = nullptr);

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

    Actor* getOwner() const
    {
        return mpOwner;
    }

    bool isInactive() const
    {
        return mFlag & 2;
    }

    bool isCollidable() const
    {
        return mCollisionMask.getDirect() != 0;
    }

    ActorCollisionHitCallback* getActorHitCallback() const
    {
        return mpActorHitCallback;
    }

    const Info& getInfo() const
    {
        return mInfo;
    }

    f32 getDaikei(s32 index) const
    {
        return mDaikei[index];
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

    List::Node                  mExecuteNode;
    List::Node                  mCreateNode;
    List::Node                  _28;
    List::Node                  _34;
    Actor*                      mpOwner;
    Actor*                      mpFriend;   // Collisions with this are ignored
    u32                         _48;
    sead::Vector2f              _4C;
    sead::Vector2f              _54;
    TypeMask                    mHit;               // Owner types of others we've collided with
    AttackMask                  mAttacksPerformed;  // Attacks performed on non-passive others
    AttackMask                  mAttacksReceived;   // Attacks received from non-passive others
    u32                         _68;
    sead::BitFlag8              mCollisionMask;
    u8                          mLayer;
    u8                          mFlag;
    ActorCollisionHitCallback*  mpActorHitCallback;
    Info                        mInfo;
    sead::SafeArray<f32, 4>     mDaikei;
    sead::UnsafeArray<f32, 15>  _b0;
    sead::UnsafeArray<f32, 15>  _ec;
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
