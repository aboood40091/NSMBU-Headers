#pragma once

#include <effect/EffectID.h>
#include <utility/Angle3.h>

#include <gfx/seadColor.h>
#include <ptcl/seadPtclSystem.h>

struct PtclParam;

class Effect
{
    // NSMBW: mEf::effect_c

protected:
    // Address: 0x022AA5DC
    void reset_();

    // Address: 0x022AA618
    nw::eft::EmitterSet* getEmitterSet_();

    // Address: 0x022AA64C
    bool createEffect_(EffectID id);    // Assumes effect is not alive and has been resetted

public:
    Effect()
    {
        reset_();
    }

    // Address: 0x022AA780
    bool createEffect(EffectID id); // Will abort and return false if
                                    // - isAlive() returns true, or
                                    // - PtclMgr singleton has not been created, or
                                    // - PtclMgr is unable to create the effect

    // Address: 0x022AA738
    bool isAlive() const;

    // Address: 0x022AA7F0
    void followFade();
    // Address: 0x022AA824
    void fade();
    // Address: 0x022AA84C
    void kill();

    // Address: 0x022AA8A8
    s32 getGroupID() const;

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

    // Address: 0x022AAB48
    bool follow(const sead::Vector3f* p_trans = nullptr, const Angle3* p_angle = nullptr, const sead::Vector3f* p_scale = nullptr);
    // Address: 0x022AAD70
    bool follow(const sead::Matrixf& mtx, bool mtx_has_scale);

    const sead::Matrixf& getMtx() const
    {
        return mMtx;
    }

    bool getMtxHasScale() const
    {
        return mMtxHasScale;
    }

protected:
    // Address: 0x022AAA68
    void update_();

public:
    // Address: 0x022AAE5C
    void setStopCalc(bool stop_calc);
    // Address: 0x022AAE8C
    void setVisible(bool visible, s32 emitter_controller_index);

    const PtclParam* getParam() const { return mpParam; }

protected:
    sead::Matrixf       mMtx;
    bool                mMtxHasScale;
    nw::eft::Handle     mHandle;
    const PtclParam*    mpParam;
};
static_assert(sizeof(Effect) == 0x40);
