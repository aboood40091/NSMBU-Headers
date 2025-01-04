#pragma once

#include <math/seadVector.h>

class Actor;

class EnemyActorScaler  // vtbl Address: 0x10072588
{
    // Used to make the Enemy's scale fluctuate when touched using the Wii U gamepad.

public:
    // Address: 0x10200DF0
    static f32 sDefaultStep;    // 0.0625

public:
    EnemyActorScaler(Actor* p_owner)
        : mScale(1.0f, 1.0f, 1.0f)
        , mScaleFactor(1.0f)
        , mDuration(0)
        , mpOwner(p_owner)
    {
    }

    // Address: 0x0232A940
    void set(f32 step = sDefaultStep, u32 duration = 24);

    // Address: 0x0232A958
    void calc();            // Decrements `mDuration` each time it's called. Scale is increased by `mStep` if `(mDuration & 4) != 0`, otherwise decreased. i.e., it's increased for 4 frames, then decreased for 4 frames, and so on.
    // Address: 0x0232AA54
    void calc(u32 period);  // Decrements `mDuration` each time it's called. Scale is increased by `mStep` if `(mDuration & period) != 0`, otherwise decreased. i.e., if `period` is a power of 2, it's increased for `period` frames, then decreased for `period` frames, and so on.

    const sead::Vector3f& getScale() const
    {
        return mScale;
    }

    // Address: 0x0232AB5C
    virtual sead::Vector3f getBaseScale() const;    // Returns owner's scale

protected:
    sead::Vector3f  mScale;
    f32             mScaleFactor;
    f32             mStep;
    u32             mDuration;
    Actor*          mpOwner;
};
static_assert(sizeof(EnemyActorScaler) == 0x20);
