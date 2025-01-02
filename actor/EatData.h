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
        cEatType_Eat,
        cEatType_EatPermanent,
        cEatType_Drink,
        cEatType_DrinkBig,
        cEatType_YoshiFire,
        cEatType_YoshiFire_Ice
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
    virtual void setAfterEatScale();
    // Address: 0x0200D504
    virtual void calcSpitOutPos(Actor* p_yoshi);
    // Address: 0x0200D5F0
    virtual f32 calcEatScaleRate(Actor* p_yoshi);
    // Address: 0x0200D76C
    virtual void eatMove(Actor* p_yoshi);
    // Address: 0x0200DA8C
    virtual void vf2C();
    // Address: 0x0200D830
    virtual bool setEatTongue(Actor* p_yoshi);
    // Address: 0x0200DA90
    virtual void setEatTongueOff(Actor* p_yoshi);
    // Address: 0x0200DA94
    virtual void setEatMouth(Actor* p_yoshi);
    // Address: 0x0200DA98
    virtual bool setEatSpitOut(Actor* p_yoshi);
    // Address: 0x0200D880
    virtual bool setEatGlupDown(Actor* p_yoshi);
    // Address: 0x0200D9AC
    virtual void calcEatInScale(Actor* p_yoshi);

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
