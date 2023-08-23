#pragma once

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

class Quake
{
    // createInstance()                             Address: 0x024C47B4
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D1660
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024C4F14
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D1664
    // SingletonDisposer_::vtbl                     Address: 0x100B7CF0
    SEAD_SINGLETON_DISPOSER(Quake)

public:
    // Address: 0x024C46CC
    Quake();

    const sead::Vector2f& getOffset() const { return mOffset; }

private:
    u32             _10[(0x4C - 0x10) / sizeof(u32)];
    sead::Vector2f  mOffset;
    u32             _54;
};
static_assert(sizeof(Quake) == 0x58);
