#pragma once

#include <heap/seadDisposer.h>

class PlayerDemoMgr
{
    SEAD_SINGLETON_DISPOSER(PlayerDemoMgr)

public:
    bool isPlayerGameStop();
};
