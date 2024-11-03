#pragma once

#include <heap/seadDisposer.h>

class ScoreMgr
{
    // createInstance()                             Address: 0x02027A0C
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101C63C4
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x02028418
    // SingletonDisposer_::sStaticDisposer          Address: 0x101C63C8
    // SingletonDisposer_::vtbl                     Address: 0x10004E28
    SEAD_SINGLETON_DISPOSER(ScoreMgr)

public:
    // Address: 0x020279E0
    ScoreMgr();

    // Address: 0x02027BD8
    void incRestAll(bool sound);
    // Address: 0x0202821C
    void incRestAllWithSmallScore(bool sound);
};
