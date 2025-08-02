#pragma once

#include <basis/seadTypes.h>

template <typename T>
T CalcTimer(T* p_value)
{
    if (*p_value != 0)
        (*p_value)--;
    return *p_value;
}
