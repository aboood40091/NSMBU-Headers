#pragma once

#include <actor/ActorUniqueID.h>

#include <container/seadListImpl.h>
#include <heap/seadDisposer.h>
#include <math/seadVector.h>
#include <prim/seadBitFlag.h>

class AttentionMgr;

class AttentionLookat : public sead::IDisposer  // vtbl Address: 0x10001340
{
public:
    enum DistanceType
    {
        cDistance_10_blocks = 0,
        cDistance_15_blocks,
        cDistance_32_blocks,        // The maximum of all values
        cDistance_16_blocks,
        cDistance_Num
    };

public:
    // Address: 0x0200CA58
    AttentionLookat(ActorUniqueID id);
    // Address: 0x0200CB10
    virtual ~AttentionLookat();

    const ActorUniqueID& getOwnerID() const
    {
        return mOwnerID;
    }

    sead::Vector2f& getPos()
    {
        return mPos;
    }

    const sead::Vector2f& getPos() const
    {
        return mPos;
    }

    void setMaxDistanceType(DistanceType distance)
    {
        mMaxDistanceType = distance;
    }

    DistanceType getMaxDistanceType() const
    {
        return mMaxDistanceType;
    }

    // TODO: Figure out flags and do this properly
    sead::BitFlag32& getFlag()
    {
        return mFlag;
    }

    const sead::BitFlag32& getFlag() const
    {
        return mFlag;
    }

protected:
    ActorUniqueID   mOwnerID;
    sead::Vector2f  mPos;
    DistanceType    mMaxDistanceType;   // Maximum distance to catch player's attention
    sead::BitFlag32 mFlag;
    sead::ListNode  mListNode;

    friend class AttentionMgr;
};
static_assert(sizeof(AttentionLookat) == 0x2C);
