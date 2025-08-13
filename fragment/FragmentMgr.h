#pragma once

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

typedef s32 EffectID;

class FragmentMgr   // vtbl Address: 0x100B6098
{
    // createInstance()                             Address: 0x024B0FBC
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D155C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024B1A70
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D1560
    // SingletonDisposer_::vtbl                     Address: 0x100b6088
    SEAD_SINGLETON_DISPOSER(FragmentMgr)

public:
    // Address: 0x024B15AC
    void createWaterSplashEff(const sead::Vector3f& pos, u8 layer, EffectID effect_id);
};
