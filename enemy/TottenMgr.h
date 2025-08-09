#pragma once

#include <heap/seadDisposer.h>

class Actor;

class TottenMgr
{
    // createInstance()                             Address: 0x02422BA0
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D0264
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x02423DB8
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D0268
    // SingletonDisposer_::vtbl                     Address: 0x1009DB94
    SEAD_SINGLETON_DISPOSER(TottenMgr)

public:
    Actor* getTottenActor()
    {
        return mpTottenActor;
    }

protected:
    u32     _10[(0x68 - 0x10) / sizeof(u32)];
    Actor*  mpTottenActor;
    u32     _6c[(0x198 - 0x6C) / sizeof(u32)];
};
static_assert(sizeof(TottenMgr) == 0x198);
