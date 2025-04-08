#pragma once

#include <effect/Effect.h>

#include <container/seadTList.h>
#include <heap/seadDisposer.h>

class EffectObjBase : public sead::IDisposer, public Effect  // vtbl Address: 0x10058734
{
    // NSMBW: Part of mEf::levelEffect_c

public:
    // Address: 0x022AB7DC
    void cleanup();

public:
    // Address: 0x022AB868
    EffectObjBase();

    virtual ~EffectObjBase()
    {
        cleanup();
    }

    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: Deleted
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: Deleted
    SEAD_RTTI_BASE(EffectObjBase)

public:
    EffectID getEffectID() const
    {
        return mEffectID;
    }

    bool isActive() const
    {
        return mIsActive;
    }

    void setActive(bool active)
    {
        mIsActive = active;
    }

protected:
    sead::TListNode<EffectObjBase*> mNode;
    EffectID                        mEffectID;
    bool                            mIsActive;
};
static_assert(sizeof(EffectObjBase) == 0x68);
