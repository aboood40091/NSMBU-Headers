#pragma once

#include <heap/seadDisposer.h>

class SeadControllerMgr
{
    SEAD_SINGLETON_DISPOSER(SeadControllerMgr)

public:
    SeadControllerMgr();

    void enterHBM();
    void exitHBM();
};
