#pragma once

#include <actor/ActorUniqueID.h>

#include <math/seadVector.h>

class Actor;

class ChibiYoshiAwaData // vtbl Address: 0x10108190
{
public:
    enum AwaType
    {
        cAwaType_Break = 0,
        cAwaType_1,
        cAwaType_2,
        cAwaType_Num
    };
    static_assert(sizeof(AwaType) == 4);

public:
    // Address: 0x0272D5EC
    ChibiYoshiAwaData(ActorUniqueID owner_id);

    // Address: 0x0272D730
    virtual void vf0C(Actor*);
    // Address: 0x0272D734
    virtual void vf14(Actor*);
    // Address: 0x0272D700
    virtual void vf1C(Actor*);
    // Address: 0x0272D738
    virtual void vf24(Actor*);

    u32 getState() const
    {
        return mState;
    }

    void setState(u32 state)
    {
        mState = state;
    }

protected:
    ActorUniqueID   mOwnerID;
    ActorUniqueID   mChibiYoshiAwaID;
    AwaType         mAwaType;
    u32             mState;
    u32             _10;
    sead::Vector2f  _14;
};
static_assert(sizeof(ChibiYoshiAwaData) == 0x20);
