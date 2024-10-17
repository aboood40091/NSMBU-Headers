#pragma once

#include <heap/seadDisposer.h>
#include <random/seadRandom.h>

class InputMgr
{
    // createInstance()                             Address: 0x0250C348
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2DF8
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0250E978
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D2DFC
    // SingletonDisposer_::vtbl                     Address: 0x100BED44
    SEAD_SINGLETON_DISPOSER(InputMgr)

public:
    // Address: 0x0250C1A0
    InputMgr();

    sead::Random& getRandom()
    {
        return mRandom;
    }

protected:
    u32             _10[(0x52C - 0x10) / sizeof(u32)];
    sead::Random    mRandom;
    u32             _53c[(0x57C - 0x53C) / sizeof(u32)];
};
static_assert(sizeof(InputMgr) == 0x57C);

#define GAME_RANDOM (InputMgr::instance()->getRandom())
