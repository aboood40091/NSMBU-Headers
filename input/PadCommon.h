#pragma once

#include <basis/seadTypes.h>

enum PadIdxCommon
{
    cPadIdxCommon_Jump = 0,
    cPadIdxCommon_Run,
    cPadIdxCommon_Shoot,
    cPadIdxCommon_Shake,
    cPadIdxCommon_Up,
    cPadIdxCommon_Down,
    cPadIdxCommon_Left,
    cPadIdxCommon_Right,
    cPadIdxCommon_Bubble,
    cPadIdxCommon_1,
    cPadIdxCommon_Minus,
    cPadIdxCommon_Plus,
    cPadIdxCommon_Touch,
    cPadIdxCommon_Decide,
    cPadIdxCommon_Back,
    cPadIdxCommon_Home,
    cPadIdxCommon_Spin,
    cPadIdxCommon_2,
    cPadIdxCommon_Num
};

enum PadFlagCommon
{
    cPadFlagCommon_Jump     = 1 << cPadIdxCommon_Jump,
    cPadFlagCommon_Run      = 1 << cPadIdxCommon_Run,
    cPadFlagCommon_Shoot    = 1 << cPadIdxCommon_Shoot,
    cPadFlagCommon_Shake    = 1 << cPadIdxCommon_Shake,
    cPadFlagCommon_Up       = 1 << cPadIdxCommon_Up,
    cPadFlagCommon_Down     = 1 << cPadIdxCommon_Down,
    cPadFlagCommon_Left     = 1 << cPadIdxCommon_Left,
    cPadFlagCommon_Right    = 1 << cPadIdxCommon_Right,
    cPadFlagCommon_Bubble   = 1 << cPadIdxCommon_Bubble,
    cPadFlagCommon_1        = 1 << cPadIdxCommon_1,
    cPadFlagCommon_Minus    = 1 << cPadIdxCommon_Minus,
    cPadFlagCommon_Plus     = 1 << cPadIdxCommon_Plus,
    cPadFlagCommon_Touch    = 1 << cPadIdxCommon_Touch,
    cPadFlagCommon_Decide   = 1 << cPadIdxCommon_Decide,
    cPadFlagCommon_Back     = 1 << cPadIdxCommon_Back,
    cPadFlagCommon_Home     = 1 << cPadIdxCommon_Home,
    cPadFlagCommon_Spin     = 1 << cPadIdxCommon_Spin,
    cPadFlagCommon_2        = 1 << cPadIdxCommon_2
};
