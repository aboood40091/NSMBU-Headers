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
    // Address: 0x02977068
    HipdropExEffect();

    // Address: 0x029770EC
    void createModel();
    // Address: 0x02977360
    void calcModel();
    // Address: 0x029774B4
    void drawModel();

    // Address: 0x02977590
    void set(const sead::Vector3f& pos);

private:
    sead::SafeArray<AnimModel*, cModelType_Num> mModel;
    sead::Vector3f                              mPosition;
    bool                                        mIsEnable;
};
static_assert(sizeof(HipdropExEffect) == 0x18);
