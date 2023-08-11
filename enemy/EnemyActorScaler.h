#pragma once

#include <math/seadVector.h>

class Actor;

class EnemyActorScaler
{
public:
    EnemyActorScaler(Actor* p_owner)
        : mScale(1.0f, 1.0f, 1.0f)
        , _c(1.0f)
        , _14(0)
        , mpOwner(p_owner)
    {
    }

    const sead::Vector3f& getScale() const
    {
        return mScale;
    }

    virtual void updateFromScale(const sead::Vector3f& scale); // Unsure if parameter is Vec3 or EnemyActorScaler ref

protected:
    sead::Vector3f  mScale;
    f32             _c;
    f32             _10;
    u32             _14;
    Actor*          mpOwner;
};
static_assert(sizeof(EnemyActorScaler) == 0x20);
