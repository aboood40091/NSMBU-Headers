#pragma once

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

class ActorCoinMgr
{
    // createInstance()                             Address: 0x026CA474
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101DB43C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x026CDF00
    // SingletonDisposer_::sStaticDisposer          Address: 0x101DB440
    // SingletonDisposer_::vtbl                     Address: 0x100F4EAC
    SEAD_SINGLETON_DISPOSER(ActorCoinMgr)

public:
    // Address: 0x026CA34C
    ActorCoinMgr();

    // Address: 0x026CABB4
    void spawnItemCoin(const sead::Vector3f& pos, s32 dir, s32 player_no) const;
};
