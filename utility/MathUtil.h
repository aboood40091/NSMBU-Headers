#pragma once

#include <basis/seadTypes.h>

class MathUtil
{
public:
    template <typename T>
    static T calcTimer(T* p_value);

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
