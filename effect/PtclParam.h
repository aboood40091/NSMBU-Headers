#pragma once

#include <basis/seadTypes.h>

struct PtclParam
{
    s32 emitter_set_id;
    f32 scale;
    f32 transX;
    f32 transY;
    f32 transZ;

    bool isDefault() const
    {
        return scale == 1.0f &&
               transX == 0.0f &&
               transY == 0.0f &&
               transZ == 0.0f;
    }
};
static_assert(sizeof(PtclParam) == 0x14);
