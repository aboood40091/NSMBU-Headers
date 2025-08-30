#pragma once

#include <math/seadMathCalcCommon.h>

class MathUtil
{
    // NSMBW: sLib

public:
    template <typename T>
    static T calcTimer(T* p_value);

    static u32 absAngle(s32 value);

    // Address: 0x029E11FC
    static f32 addCalc(f32*, f32, f32, f32, f32);
};

template <typename T>
T MathUtil::calcTimer(T* p_value)
{
    if (*p_value != 0)
        (*p_value)--;
    return *p_value;
}

inline u32 MathUtil::absAngle(s32 value)
{
    if (value >= 0)
        return value;
    else if (value == -sead::Mathi::cHalfRoundIdx)
        return sead::Mathu::cHalfRoundIdx;
    else
        return -value;
}
