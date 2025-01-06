#pragma once

#include <actor/ActorUniqueID.h>

#include <math/seadVector.h>

class ChibiEatData  // vtbl Address: 0x1000145C
{
public:
    enum EatType
    {
        cEatType_None = 0,
        cEatType_Drink,
    };
    static_assert(sizeof(EatType) == 4);

    enum ScoreType
    {
        cScoreType_Point_200 = 0,
        cScoreType_Point_1000,
        cScoreType_None,
    };
    static_assert(sizeof(ScoreType) == 4);

    // Address: 0x0200CF1C
    ChibiEatData(ActorUniqueID owner_id);

    // Address: 0x0200D308
    virtual u32 vf0C();
    // Address: 0x0200D034
    virtual void* vf14(void*);
    // Address: 0x0200D094
    virtual void* vf1C(void*);
    // Address: 0x0200D310
    virtual void vf24();
    // Address: 0x0200D314
    virtual void setEatSpitOut(Actor* p_chibi_yoshi);
    // Address: 0x0200D1B4
    virtual bool handleEaten(void*);
    // Address: 0x0200D318
    virtual void vf3C();

    u32 getState() const
    {
        return mState;
    }

    void setState(u32 state)
    {
        mState = state;
    }

    EatType getEatType() const
    {
        return mEatType;
    }

    void setEatType(EatType eat_type)
    {
        mEatType = eat_type;
    }

    sead::Vector3f& getScale()
    {
        return mScale;
    }

    const sead::Vector3f& getScale() const
    {
        return mScale;
    }

    ScoreType getScoreType() const
    {
        return mScoreType;
    }

    void setScoreType(ScoreType score_type)
    {
        mScoreType = score_type;
    }

protected:
    ActorUniqueID   mOwnerID;
    u32             mYoshiChibiID;
    sead::Vector3f  mScale;
    u32             mState;
    EatType         mEatType;
    ScoreType       mScoreType;
};
static_assert(sizeof(ChibiEatData) == 0x24);
