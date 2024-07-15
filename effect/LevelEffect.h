#pragma once

#include <effect/EffectDisposable.h>

class LevelEffect : public EffectDisposable
{
    // NSMBW: dEf::dLevelEffect_c

public:
    LevelEffect()
        : EffectDisposable()
    {
    }

    virtual ~LevelEffect()
    {
    }

    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: Deleted
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: Deleted
    SEAD_RTTI_OVERRIDE(LevelEffect, EffectDisposable)
};
static_assert(sizeof(LevelEffect) == sizeof(EffectDisposable));
