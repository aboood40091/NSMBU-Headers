#pragma once

#include <actor/ActorUniqueID.h>

#include <math/seadVector.h>

class Actor;

class EatData   // vtbl Address: 0x10001594
{
public:
    enum EatType
    {
        cEatType_None = 0,
        cEatType_HoldAndSpit,
        cEatType_HoldPermanent,
        cEatType_Swallow,
        cEatType_SwallowBig,
        cEatType_SpitFireball,
        cEatType_SpitIceball,
    };
    static_assert(sizeof(EatType) == 4);

    enum ScoreType
    {
        cScoreType_Point_200 = 0,
        cScoreType_Point_1000,
        cScoreType_None,
    };
    static_assert(sizeof(ScoreType) == 4);

    // Address: 0x0200D6C4
    EatData(ActorUniqueID owner_id);

    // Address: 0x0200D4B8
    virtual void* vf0C();
    // Address: 0x0200D504
    virtual void vf14(Actor* p_yoshi);
    // Address: 0x0200D5F0
    virtual f32 vf1C(void*);
    // Address: 0x0200D76C
    virtual void eatMove(Actor* p_yoshi);
    // Address: 0x0200DA8C
    virtual void vf2C();
    // Address: 0x0200D830
    virtual bool handleEaten(Actor*);
    // Address: 0x0200DA90
    virtual void vf3C();
    // Address: 0x0200DA94
    virtual void vf44();
    // Address: 0x0200DA98
    virtual bool vf4C(Actor* p_yoshi);
    // Address: 0x0200D880
    virtual bool vf54(void*);
    // Address: 0x0200D9AC
    virtual void vf5C(void*);

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
    u32             mYoshiID;
    u32             mState;
    EatType         mEatType;
    sead::Vector3f  mScale;
    ScoreType       mScoreType;
};
static_assert(sizeof(EatData) == 0x24);
