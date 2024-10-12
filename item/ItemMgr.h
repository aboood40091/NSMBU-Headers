#pragma once

#include <heap/seadDisposer.h>

class ItemMgr
{
    // createInstance()                             Address: 0x0251DE24
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2F80
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0251EACC
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D2F84
    // SingletonDisposer_::vtbl                     Address: 0x100C0E50
    SEAD_SINGLETON_DISPOSER(ItemMgr)

public:
    // Address: 0x0251DDF8
    ItemMgr();

    // Address: 0x0251DEA4
    s32 playerNumber();
};
