#pragma once

#include <math/seadVector.h>

class Actor;

class EnemyActorScaler  // vtbl Address: 0x10072588
{
public:
    EnemyActorScaler(Actor* owner)
        : mScale(1.0f, 1.0f, 1.0f)
        , _c(1.0f)
        , _14(0)
        , mOwner(owner)
    {
    }

    const sead::Vector3f& getScale() const
    {
        return mScale;
    }

    // Address: 0x0232AB5C
    virtual void updateFromScale(const sead::Vector3f& scale); // Unsure if parameter is Vec3 or EnemyActorScaler ref

protected:
    sead::Vector3f  mScale;
    f32             _c;
    f32             _10;
    u32             _14;
    Actor*          mOwner;
};
static_assert(sizeof(EnemyActorScaler) == 0x20);
