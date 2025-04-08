#pragma once

#include <effect/EffectID.h>
#include <utility/Angle3.h>

#include <math/seadMatrix.h>

class EffectObj;
class FollowEffect;

class EffectCreateUtil
{
    // NSMBW: mEf + dEf

public:
    // Address: 0x022AB080
    static bool createEffect(EffectID id, const sead::Vector3f* p_trans = nullptr, const Angle3* p_angle = nullptr, const sead::Vector3f* p_scale = nullptr);
    // Address: 0x022AB0F4
    static bool createEffect(EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale);

    // Address: 0x022AB158
    static bool createPlayerEffect(s32 player_no, EffectID id, const sead::Vector3f* p_trans = nullptr, const Angle3* p_angle = nullptr, const sead::Vector3f* p_scale = nullptr);
    // Address: Deleted
    static bool createPlayerEffect(s32 player_no, EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale);

    // Address: 0x022AB1BC
    static bool createPlayerEffect(s32 player_no, EffectObj* p_effect, EffectID id, const sead::Vector3f* p_trans = nullptr, const Angle3* p_angle = nullptr, const sead::Vector3f* p_scale = nullptr);
    // Address: 0x022AB224
    static bool createPlayerEffect(s32 player_no, EffectObj* p_effect, EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale);

    // Address: 0x022AB288
    static bool createPlayerEffect(s32 player_no, FollowEffect* p_effect, EffectID id, const sead::Vector3f* p_trans = nullptr, const Angle3* p_angle = nullptr, const sead::Vector3f* p_scale = nullptr);
    // Address: Deleted
    static bool createPlayerEffect(s32 player_no, FollowEffect* p_effect, EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale);

    // Address: 0x022AB2F0
    static bool isCreateAboveLayer0(const sead::Vector3f& effect_pos);
};
