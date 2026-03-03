#pragma once

#include <heap/seadDisposer.h>

class ActorStatus
{
    // createInstance()                             Address: 0x0200C154
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101C30D0
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0200C1D4
    // SingletonDisposer_::sStaticDisposer          Address: 0x101C30D4
    // SingletonDisposer_::vtbl                     Address: 0x100012F4
    SEAD_SINGLETON_DISPOSER(ActorStatus)

public:
    void incKuribo()
    {
        mKuriboNum++;
    }

    void decKuribo()
    {
        mKuriboNum--;
    }

    void validateKuriboNum()
    {
        if (mKuriboNum < 0)
            mKuriboNum = 0;
    }

    void incKakibo()
    {
        mKakiboNum++;
    }

    void decKakibo()
    {
        mKakiboNum--;
    }

    void validateKakiboNum()
    {
        if (mKakiboNum < 0)
            mKakiboNum = 0;
    }

protected:
    u32 _10[(0xAC - 0x10) / sizeof(u32)];
    s32 mKuriboNum;
    s32 mKakiboNum;
    u32 _b4[(0x9F4 - 0xB4) / sizeof(u32)];
};
static_assert(sizeof(ActorStatus) == 0x9F4);
