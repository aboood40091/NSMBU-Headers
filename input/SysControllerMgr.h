#pragma once

#include <heap/seadDisposer.h>

class SysControllerMgr
{
    SEAD_SINGLETON_DISPOSER(SysControllerMgr)

public:
    enum SetUpType
    {
        cSetUp_AB_XY = 0,
        cSetUp_AX_BY
    };
    static_assert(sizeof(SetUpType) == 4);

public:
    SysControllerMgr();

    bool isURCC(s32 controller_index) const;

    void enterHBM();
    void exitHBM();

    void setRemoteEnable(bool enable)
    {
        mIsRemoteEnable = enable;
    }

protected:
    s32         mDRCTouchPanelIndex;
    SetUpType   mSetUpType;
    bool        mIsRemoteEnable;
    u32         _1c[(0xB0 - 0x1C) / sizeof(u32)];

};
static_assert(sizeof(SysControllerMgr) == 0xB0);
