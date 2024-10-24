#pragma once

#include <effect/EffectDisposableBase.h>

class EffectDisposable : public EffectDisposableBase
{
    // NSMBW: Other part of mEf::levelEffect_c & dEf::dLevelEffect_c

public:
    EffectDisposable()
        : EffectDisposableBase()
    {
    }

    virtual ~EffectDisposable()
    {
    }

    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: Deleted
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: Deleted
    SEAD_RTTI_OVERRIDE(EffectDisposable, EffectDisposableBase)

public:
    // Address: 0x022AB52C
    bool createEffect(EffectID id, const sead::Vector3f* p_trans = nullptr, const Angle3* p_angle = nullptr, const sead::Vector3f* p_scale = nullptr);
    // Address: 0x022AB6EC
    bool createEffect(EffectID id, const sead::Matrixf* p_mtx = nullptr, bool mtx_has_scale = false);

    bool createEffect(EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale)
    {
        return createEffect(id, &mtx, mtx_has_scale);
    }

    // Address: 0x022AB448
    bool follow(const sead::Vector3f* p_trans = nullptr, const Angle3* p_angle = nullptr, const sead::Vector3f* p_scale = nullptr);
    // Address: 0x022AB608
    bool follow(const sead::Matrixf& mtx, bool mtx_has_scale);

    bool follow(const sead::Matrixf* p_mtx, bool mtx_has_scale)
    {
        if (p_mtx == nullptr)
            p_mtx = &sead::Matrixf::ident;

        return follow(*p_mtx, mtx_has_scale);
    }
};
static_assert(sizeof(EffectDisposable) == sizeof(EffectDisposableBase));
