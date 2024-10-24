#pragma once

#include <basis/seadTypes.h>

class Snd2DCalc
{
public:
    struct Param
    {
        f32 volume;
        s32 priority;
        f32 pitch;
        f32 pan;

        Param()
            : volume(1.0f)
            , priority(0)
            , pitch(1.0f)
            , pan(0.0f)
        {
        }
    };
    static_assert(sizeof(Param) == 0x10);

public:
    // TODO
};
