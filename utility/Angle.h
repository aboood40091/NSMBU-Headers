#pragma once

#include <basis/seadTypes.h>

class Angle
{
public:
    Angle(u32 angle)
        : value(angle)
    {
    }

    operator u32() const
    {
        return value;
    }

private:
    u32 value;
};
