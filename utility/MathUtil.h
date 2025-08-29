#pragma once

#include <basis/seadTypes.h>

class MathUtil
{
public:
    template <typename T>
    static T calcTimer(T* p_value);
};

template <typename T>
T MathUtil::calcTimer(T* p_value)
{
    if (*p_value != 0)
        (*p_value)--;
    return *p_value;
}
