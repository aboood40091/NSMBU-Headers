#pragma once

#include <effect/Effect.h>

#include <container/seadTList.h>
#include <heap/seadDisposer.h>

class EffectLevelBase : public sead::IDisposer, public Effect, public sead::TListNode<EffectLevelBase*> // vtbl Address: 0x10058734
{
    // NSMBW: mEf::levelEffect_c

public:
    // Address: 0x022AB52C
    bool createEffect(EffectID id, const sead::Vector3f& trans, const sead::Vector3u& rotat, const sead::Vector3f& scale);
    // Address: 0x022AB6EC
    bool createEffect(EffectID id, const sead::Matrixf& mtx, bool mtx_has_scale);

    // Address: 0x022AB448
    bool follow(const sead::Vector3f& trans, const sead::Vector3u& rotat, const sead::Vector3f& scale);
    // Address: 0x022AB608
    bool follow(const sead::Matrixf& mtx, bool mtx_has_scale);

    // Address: 0x022AB7DC
    void cleanup();

public:
    // Address: 0x022AB868
    EffectLevelBase();

    virtual ~EffectLevelBase()
    {
        cleanup();
    }

    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: Deleted
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: Deleted
    SEAD_RTTI_BASE(EffectLevelBase)

public:
    EffectID getEffectID() const
    {
        return mEffectID;
    }

    bool isActive() const
    {
        return mIsActive;
    }

protected:
    EffectID    mEffectID;
    bool        mIsActive;
};
static_assert(sizeof(EffectLevelBase) == 0x68);
