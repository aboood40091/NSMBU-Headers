#pragma once

#include <effect/Effect.h>

class FollowEffect : public Effect
{
    // NSMBW: mEf::effect_c + dEf::followEffect_c

public:
    // Address: 0x022AB980
    bool createEffect(EffectID id, const sead::Vector3f* p_trans = nullptr, const Angle3* p_angle = nullptr, const sead::Vector3f* p_scale = nullptr);
    // Address: 0x022AB9F0
    bool createEffect(EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale);
};
static_assert(sizeof(FollowEffect) == sizeof(Effect));
