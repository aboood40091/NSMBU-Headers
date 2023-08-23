#pragma once

#include <basis/seadTypes.h>

class CalcRatio
{
    // Actual name of this class is unknown.
    // In NSMBW, it is m3d::calcRatio_c.
    // However, "CalcRatio" is not consistent with the code order in NSMBU.

public:
    // Address: 0x024D7F1C
    CalcRatio();

    // Address: 0x024D7FE0
    void set(f32 duration);
    // Address: 0x024D7FB8
    void reset();

    // Address: 0x024D8054
    void calc();

    f32 ratioA() const
    {
        return mRatioA;
    }

    f32 ratioB() const
    {
        return mRatioB;
    }

    bool isActive() const
    {
        return mIsActive;
    }

private:
    // Address: 0x024D7F94
    void reset_();

    // Address: 0x024D7F78
    static bool isZero_(f32 v);

private:
    f32     mRatioA;    // Source
    f32     mRatioB;    // Target
    f32     mCounter;
    f32     mInvDuration;
    bool    mIsActive;
};
static_assert(sizeof(CalcRatio) == 0x14);
