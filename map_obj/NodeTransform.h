#pragma once

#include <math/seadMatrix.h>

struct NodeTransform
{
    sead::Matrix34f mtx_rt;
    sead::Vector3f  scale;
    s32             index;

    NodeTransform()
        : mtx_rt(sead::Matrix34f::zero)
        , scale(0.0f, 0.0f, 0.0f)
        , index(0)
    {
    }
};
static_assert(sizeof(NodeTransform) == 0x40);
