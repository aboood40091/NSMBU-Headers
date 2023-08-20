#pragma once

#include <actor/ActorUniqueID.h>

#include <math/seadVector.h>

class GenericEatData    // vtbl Address: 0x10001594
{
public:
    // Address: 0x0200D6C4
    GenericEatData(ActorUniqueID owner_id);

    // Address: 0x0200D4B8
    virtual void* vf0C();
    // Address: 0x0200D504
    virtual void* vf14(void*);
    // Address: 0x0200D5F0
    virtual f32 vf1C(void*);
    // Address: 0x0200D76C
    virtual void* vf24(void*);
    // Address: 0x0200DA8C
    virtual void vf2C();
    // Address: 0x0200D830
    virtual bool handleEaten();
    // Address: 0x0200DA90
    virtual void vf3C();
    // Address: 0x0200DA94
    virtual void vf44();
    // Address: 0x0200DA98
    virtual u32 vf4C();
    // Address: 0x0200D880
    virtual bool vf54(void*);
    // Address: 0x0200D9AC
    virtual void vf5C(void*);

protected:
    ActorUniqueID   mOwnerID;
    u32             mYoshiID;
    u32             mState;
    u32             mSpitType;
    sead::Vector3f  mScale;
    u32             mScore;
};
static_assert(sizeof(GenericEatData) == 0x24);
