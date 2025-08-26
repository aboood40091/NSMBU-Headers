#pragma once

#include <container/seadSafeArray.h>
#include <math/seadVector.h>

class AnimModel;

class HipdropExEffect
{
public:
    enum ModelType
    {
        cModelType_FB,
        cModelType_Rainbow,
        cModelType_Num
    };
    static_assert(cModelType_Num == 2);

public:
    HipdropExEffect();
    // TODO

//protected:
    sead::SafeArray<AnimModel*, cModelType_Num> mModel;
    sead::Vector3f                              mPosition;
    bool                                        mIsEnable;
};
static_assert(sizeof(HipdropExEffect) == 0x18);
