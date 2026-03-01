#pragma once

#include <actor/ActorUniqueID.h>

#include <math/seadVector.h>

class Actor;

class ChibiYoshiAwaData // vtbl Address: 0x10108190
{
public:
    enum AwaType
    {
        cAwaType_Invalid = 0,   // Bubble cannot catch the actor and breaks instead
        cAwaType_Catch,
        cAwaType_CatchBig,      // Spawns more coins than cAwaType_Catch
        cAwaType_Num
    };
    static_assert(sizeof(AwaType) == 4);

    enum State
    {
        cState_None = 0,
        cState_Catch
    };
    static_assert(sizeof(State) == 4);

    enum ItemType
    {
        cItemType_Normal = 0,       // Random
        cItemType_ForceMusasabi,
        cItemType_ForceKinoko
    };
    static_assert(sizeof(ItemType) == 4);

public:
    // Address: 0x0272D5EC
    ChibiYoshiAwaData(ActorUniqueID owner_id);

    // Address: 0x0272D730
    virtual void setAwaHit(Actor* p_awa); // Called when bubble hits the actor and either catches it or breaks
    // Address: 0x0272D734
    virtual void awaCatchMove(Actor* p_awa); // Called as the bubble is swallowing the actor
    // Address: 0x0272D700
    virtual void setAwaCatchEnd(Actor* p_awa); // Called when the bubble finishes swallowing the actor, actor should die
    // Address: 0x0272D738
    virtual void setAwaInvalid(Actor* p_awa); // Called when the bubble cannot catch the actor and breaks instead

    AwaType getAwaType() const
    {
        return mAwaType;
    }

    void setAwaType(AwaType type)
    {
        mAwaType = type;
    }

    State getState() const
    {
        return mState;
    }

    void setState(State state)
    {
        mState = state;
    }

    ItemType getItemType() const
    {
        return mItemType;
    }

    void setItemType(ItemType type)
    {
        mItemType = type;
    }

    sead::Vector2f& getPosOffset()
    {
        return mPosOffset;
    }

    const sead::Vector2f& getPosOffset() const
    {
        return mPosOffset;
    }

protected:
    ActorUniqueID   mOwnerID;
    ActorUniqueID   mChibiYoshiAwaID;
    AwaType         mAwaType;
    State           mState;
    ItemType        mItemType;
    sead::Vector2f  mPosOffset;
};
static_assert(sizeof(ChibiYoshiAwaData) == 0x20);
