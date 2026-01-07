#pragma once

#include <utility/Angle3.h>

#include <math/seadMatrix.h>

class Mtxf : public sead::Matrixf
{
public:
    // Address: 0x029E136C
    void XrotS(Angle angle);    // S: Set
    // Address: 0x029E1594
    void XrotM(Angle angle);    // M: Mult (i.e., Apply)

    // Address: 0x029E12C0
    void YrotS(Angle angle);    // S: Set
    // Address: 0x029E14C4
    void YrotM(Angle angle);    // M: Mult (i.e., Apply)

    // Address: 0x029E1418
    void ZrotS(Angle angle);    // S: Set
    // Address: 0x029E152C
    void ZrotM(Angle angle);    // M: Mult (i.e., Apply)

    // Address: 0x029E15FC
    void ZXYrotM(const Angle3& angle);
    // Address: Deleted
    void XYZrotM(const Angle3& angle);

    void multVecZero(sead::Vector3f& vec) const
    {
        getTranslation(vec);
    }

    // Address: 0x029E1650
    void copy(const sead::Matrixf& mtx);
    // Address: 0x029E16B4
    void copy(const Mtxf& mtx);
};
static_assert(sizeof(Mtxf) == sizeof(sead::Matrixf));
