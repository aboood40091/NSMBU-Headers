#pragma once

#include <heap/seadDisposer.h>

class SysControllerMgr
{
    SEAD_SINGLETON_DISPOSER(SysControllerMgr)

public:
    SysControllerMgr();

    void enterHBM();
    void exitHBM();
};
