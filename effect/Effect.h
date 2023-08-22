#pragma once

#include <effect/EffectID.h>

#include <gfx/seadColor.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <ptcl/seadPtclSystem.h>

class Effect
{
    // NSMBW: mEf::effect_c

public:
    Effect()
    {
        clear();
    }

    // Address: 0x022AA5DC
    void clear();

    // Address: 0x022AA780
    bool createEffect(EffectID id); // Will abort and return false if
                                    // - isAlive() returns true, or
                                    // - PtclMgr singleton has not been created, or
                                    // - PtclMgr is unable to create the effect

    // Address: 0x022AA738
    bool isAlive() const;

    // Address: 0x022AA7F0
    void fade();
    // Address: 0x022AA824
    void fadeAndKill();
    // Address: 0x022AA84C
    void kill();

    // Address: 0x022AA8A8
    u32 getUserData() const;

    // Address: 0x022AA8D4
    void setColor(const sead::Color4f& color);
    // Address: 0x022AA91C
    void setAlpha(f32 alpha);
    // Address: 0x022AA948
    void setDirectionalVel(f32 vel);
    // Address: 0x022AA974
    void setEmitterScale(const sead::Vector3f& scale);
    // Address: 0x022AA9B4
    void setParticleScale(const sead::Vector2f& scale);
    // Address: 0x022AAA04
    void setEmissionParticleScale(const sead::Vector2f& scale);
    // Address: 0x022AAA3C
    void setRandomSeed(u32 seed);

    // Address: 0x022AAA68
    void update();

    // Address: 0x022AAB48
    void follow(const sead::Vector3f& trans, const sead::Vector3u& rotat, const sead::Vector3f& scale);
    // Address: 0x022AAD70
    void follow(const sead::Matrixf& mtx, bool mtx_has_scale);

    // Address: 0x022AAE5C
    void setStopCalc(bool stop_calc);
    // Address: 0x022AAE8C
    void setVisible(bool visible, s32 emitter_controller_index);

public:
    // Address: 0x022AA64C
    bool createEffect_(EffectID id);    // Assumes effect is not alive and has been cleared

    // Address: 0x022AA618
    nw::eft::EmitterSet* getEmitterSet();

    void* getShaderParam() const { return mpShaderParam; }

protected:
    sead::Matrixf   mMtx;
    bool            mMtxHasScale;
    nw::eft::Handle mHandle;
    void*           mpShaderParam;
};
static_assert(sizeof(Effect) == 0x40);
