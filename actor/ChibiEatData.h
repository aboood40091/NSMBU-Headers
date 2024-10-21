#pragma once

#include <actor/ActorUniqueID.h>

#include <math/seadVector.h>

class ChibiEatData  // vtbl Address: 0x1000145C
{
public:
    // Address: 0x0200CF1C
    ChibiEatData(ActorUniqueID owner_id);

    // Address: 0x0200D308
    virtual u32 vf0C();
    // Address: 0x0200D034
    virtual void* vf14(void*);
    // Address: 0x0200D094
    virtual void* vf1C(void*);
    // Address: 0x0200D310
    virtual void vf24();
    // Address: 0x0200D314
    virtual void vf2C();
    // Address: 0x0200D1B4
    virtual bool handleEaten(void*);
    // Address: 0x0200D318
    virtual void vf3C();

protected:
    ActorUniqueID   mOwnerID;
    u32             mYoshiChibiID;
    sead::Vector3f  mScale;
    u32             _14;
    u32             _18;
    u32             mScore;
};
static_assert(sizeof(ChibiEatData) == 0x24);
