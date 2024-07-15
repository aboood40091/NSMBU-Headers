#pragma once

#include <effect/Effect.h>

class FollowEffect : public Effect
{
    // NSMBW: mEf::effect_c + dEf::followEffect_c

public:
    // Address: 0x022AB980
    bool createEffect(EffectID id, const sead::Vector3f* p_trans = nullptr, const Angle3* p_angle = nullptr, const sead::Vector3f* p_scale = nullptr);
    // Address: 0x022AB9F0
    bool createEffect(EffectID id, const sead::Matrixf* p_mtx = nullptr, bool mtx_has_scale = false);

    bool createEffect(EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale)
    {
        return createEffect(id, &mtx, mtx_has_scale);
    }

    using Effect::follow;

    bool follow(const sead::Matrixf* p_mtx, bool mtx_has_scale)
    {
        if (p_mtx == nullptr)
            p_mtx = &sead::Matrixf::ident;

        return follow(*p_mtx, mtx_has_scale);
    }
};
static_assert(sizeof(FollowEffect) == sizeof(Effect));
