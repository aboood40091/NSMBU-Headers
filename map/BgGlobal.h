#pragma once

#include <heap/seadDisposer.h>

class BgUnit;

class BgGlobal
{
    SEAD_SINGLETON_DISPOSER(BgGlobal)

public:
    BgGlobal();

    BgUnit* getBgUnit(s32 file, s32 layer);
};
