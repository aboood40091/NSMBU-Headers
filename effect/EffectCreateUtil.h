#pragma once

#include <effect/EffectID.h>

#include <math/seadMatrix.h>
#include <math/seadVector.h>

class FollowEffect;
class LevelEffect;

class EffectCreateUtil
{
    // NSMBW: mEf + dEf

public:
    // Address: 0x022AB080
    static bool createEffect(EffectID id, const sead::Vector3f& trans, const sead::Vector3u& rotat, const sead::Vector3f& scale);
    // Address: 0x022AB0F4
    static bool createEffect(EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale);

    // Address: 0x022AB158
    static bool createPlayerEffect(s32 player_no, EffectID id, const sead::Vector3f& trans, const sead::Vector3u& rotat, const sead::Vector3f& scale);
    // Address: Deleted
    static bool createPlayerEffect(s32 player_no, EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale);

    // Address: 0x022AB1BC
    static bool createPlayerEffect(s32 player_no, LevelEffect* p_effect, EffectID id, const sead::Vector3f& trans, const sead::Vector3u& rotat, const sead::Vector3f& scale);
    // Address: 0x022AB224
    static bool createPlayerEffect(s32 player_no, LevelEffect* p_effect, EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale);

    // Address: 0x022AB288
    static bool createPlayerEffect(s32 player_no, FollowEffect* p_effect, EffectID id, const sead::Vector3f& trans, const sead::Vector3u& rotat, const sead::Vector3f& scale);
    // Address: Deleted
    static bool createPlayerEffect(s32 player_no, FollowEffect* p_effect, EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale);
};
