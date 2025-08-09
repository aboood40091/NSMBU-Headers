#pragma once

#include <basis/seadTypes.h>

struct ActorCullRange
{
    f32 up;
    f32 down;
    f32 left;
    f32 right;
};
static_assert(sizeof(ActorCullRange) == 0x10);
