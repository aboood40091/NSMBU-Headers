#pragma once

#include <input/SysController.h>

#include <controller/seadControllerWrapper.h>

class SysControllerWrapper : public sead::ControllerWrapper
{
public:
    enum PadIdx
    {
        cPadIdx_Jump = 0,
        cPadIdx_Run,
        cPadIdx_Shoot,
        cPadIdx_Shake,
        cPadIdx_Up,
        cPadIdx_Down,
        cPadIdx_Left,
        cPadIdx_Right,
        cPadIdx_Bubble,
        cPadIdx_1,
        cPadIdx_Minus,
        cPadIdx_Plus,
        cPadIdx_Touch,
        cPadIdx_Decide,
        cPadIdx_Back,
        cPadIdx_Home,
        cPadIdx_Spin,
        cPadIdx_2,
        cPadIdx_Num
    };

    enum PadFlag
    {
        cPadFlag_Jump   = 1 << cPadIdx_Jump,
        cPadFlag_Run    = 1 << cPadIdx_Run,
        cPadFlag_Shoot  = 1 << cPadIdx_Shoot,
        cPadFlag_Shake  = 1 << cPadIdx_Shake,
        cPadFlag_Up     = 1 << cPadIdx_Up,
        cPadFlag_Down   = 1 << cPadIdx_Down,
        cPadFlag_Left   = 1 << cPadIdx_Left,
        cPadFlag_Right  = 1 << cPadIdx_Right,
        cPadFlag_Bubble = 1 << cPadIdx_Bubble,
        cPadFlag_1      = 1 << cPadIdx_1,
        cPadFlag_Minus  = 1 << cPadIdx_Minus,
        cPadFlag_Plus   = 1 << cPadIdx_Plus,
        cPadFlag_Touch  = 1 << cPadIdx_Touch,
        cPadFlag_Decide = 1 << cPadIdx_Decide,
        cPadFlag_Back   = 1 << cPadIdx_Back,
        cPadFlag_Home   = 1 << cPadIdx_Home,
        cPadFlag_Spin   = 1 << cPadIdx_Spin,
        cPadFlag_2      = 1 << cPadIdx_2
    };

    static const u8 cPadConfig[cPadIdx_Num];

public:
    SysControllerWrapper();
    virtual ~SysControllerWrapper();

    virtual void calc(u32, bool);

    void registerWith(SysController::Id id);
};
static_assert(sizeof(SysControllerWrapper) == sizeof(sead::ControllerWrapper));
