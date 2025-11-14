#pragma once

#include <math/seadVector.h>

class Actor;

class EnemyBoyoMgr  // vtbl Address: 0x10072588
{
    // Used to make the Enemy's scale fluctuate when breaking out of ice, and when touched using the Wii U gamepad.

public:
    static const s32 cBoyonTime = 24;
    // Address: 0x10200DF0
    static const f32 cDeltaScale;       // 0.0625

public:
    EnemyBoyoMgr(Actor* p_owner)
        : mScale(1.0f, 1.0f, 1.0f)
        , mScaleFactor(1.0f)
        , mTime(0)
        , mpOwner(p_owner)
    {
    }

    void initialize()
    {
        mScale.set(getBaseScale());
    }

    // Address: 0x0232A940
    void begin(s32 time = cBoyonTime, f32 delta_scale = cDeltaScale);

    // Address: 0x0232A958
    void execute();             // Decrements `mTime` each time it's called. Scale is increased by `mDeltaScale` if `(mTime & 4) != 0`, otherwise decreased. i.e., it's increased for 4 frames, then decreased for 4 frames, and so on.
    // Address: 0x0232AA54
    void execute(s32 period);   // Decrements `mTime` each time it's called. Scale is increased by `mDeltaScale` if `(mTime & period) != 0`, otherwise decreased. i.e., if `period` is a power of 2, it's increased for `period` frames, then decreased for `period` frames, and so on.

    const sead::Vector3f& getScale() const
    {
        return mScale;
    }

    // Address: 0x0232AB5C
    virtual sead::Vector3f getBaseScale() const;    // Returns owner's scale

protected:
    sead::Vector3f  mScale;
    f32             mScaleFactor;
    f32             mDeltaScale;
    s32             mTime;
    Actor*          mpOwner;
};
static_assert(sizeof(EnemyBoyoMgr) == 0x20);
