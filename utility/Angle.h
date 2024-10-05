#pragma once

#include <basis/seadTypes.h>

class Angle
{
public:
    Angle()
        : mValue(0)
    {
    }

    Angle(s32 value)
        : mValue(value)
    {
    }

    operator s32() const
    {
        return mValue;
    }

    Angle& operator=(const Angle& rhs)
    {
        mValue = rhs.mValue;
        return *this;
    }

    Angle& operator+=(const Angle& rhs)
    {
        mValue += rhs.mValue;
        return *this;
    }

    Angle& operator-=(const Angle& rhs)
    {
        mValue -= rhs.mValue;
        return *this;
    }

    Angle operator+() const
    {
        return *this;
    }

    Angle operator-() const
    {
        return Angle(-mValue);
    }

    Angle operator+(const Angle& rhs)
    {
        return mValue + rhs.mValue;
    }

    Angle operator+(s32 rhs)
    {
        return mValue + rhs;
    }

    Angle operator-(const Angle& rhs)
    {
        return mValue - rhs.mValue;
    }

    Angle operator-(s32 rhs)
    {
        return mValue - rhs;
    }

    bool operator==(const Angle& rhs) const
    {
        return mValue == rhs.mValue;
    }

    bool operator==(s32 rhs) const
    {
        return mValue == rhs;
    }

    bool operator!=(const Angle& rhs) const
    {
        return mValue != rhs.mValue;
    }

    bool operator!=(s32 rhs) const
    {
        return mValue != rhs;
    }

public:
    // Address: 0x029E0EA8
    bool chaseAngle(const Angle& target, f32 ratio, const Angle& max);
    // Address: 0x029E0EE8
    bool chaseAngle(const Angle& target, f32 ratio, const Angle& max, const Angle& min);
    // Address: 0x029E116C
    bool chaseDecrease(const Angle& target, f32 ratio, const Angle& max, const Angle& min);
    // Address: 0x029E117C
    bool chaseRest(const Angle& target, const Angle& step);
    // Address: 0x029E1188
    bool chaseConstant(const Angle& target, const Angle& step);

protected:
    // Address: 0x029E0E34
    bool chaseAngle_(s32 target, s32 distance, f32 ratio, s32 max, s32 min);
    // Address: 0x029E0F8C
    bool chaseDecrease_(s32 target, f32 ratio, s32 max, s32 min);
    // Address: 0x029E0DE8
    bool chaseRest_(s32 target, s32 step);
    // Address: 0x029E0F2C
    bool chaseConstant_(s32 target, s32 step);

protected:
    s32 mValue;
};
static_assert(sizeof(Angle) == 4);
