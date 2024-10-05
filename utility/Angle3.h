#pragma once

#include <utility/Angle.h>

#include <math/seadVector.h>

class Angle3
{
public:
    Angle3()
    {
    }

    Angle3(const Angle& x, const Angle& y, const Angle& z)
        : mX(x)
        , mY(y)
        , mZ(z)
    {
    }

    explicit Angle3(const Angle* p)
        : mX(p[0])
        , mY(p[1])
        , mZ(p[2])
    {
    }

    explicit Angle3(const sead::Vector3i& v)
        : mX(v.x)
        , mY(v.y)
        , mZ(v.z)
    {
    }

    explicit Angle3(const sead::Vector3u& v)
        : mX(v.x)
        , mY(v.y)
        , mZ(v.z)
    {
    }

    Angle& x()
    {
        return mX;
    }

    const Angle& x() const
    {
        return mX;
    }

    Angle& y()
    {
        return mY;
    }

    const Angle& y() const
    {
        return mY;
    }

    Angle& z()
    {
        return mZ;
    }

    const Angle& z() const
    {
        return mZ;
    }

    operator Angle*()
    {
        return &mX;
    }

    operator const Angle*() const
    {
        return &mX;
    }

    operator sead::Vector3i() const
    {
        return sead::Vector3i(s32(mX), s32(mY), s32(mZ));
    }

    operator sead::Vector3u() const
    {
        return sead::Vector3u(s32(mX), s32(mY), s32(mZ));
    }

    Angle3& operator=(const Angle3& rhs)
    {
        mX = rhs.mX;
        mY = rhs.mY;
        mZ = rhs.mZ;
        return *this;
    }

    Angle3& operator+=(const Angle3& rhs)
    {
        mX += rhs.mX;
        mY += rhs.mY;
        mZ += rhs.mZ;
        return *this;
    }

    Angle3& operator-=(const Angle3& rhs)
    {
        mX -= rhs.mX;
        mY -= rhs.mY;
        mZ -= rhs.mZ;
        return *this;
    }

    Angle3 operator+() const
    {
        return *this;
    }

    Angle3 operator-() const
    {
        return Angle3(-mX, -mY, -mZ);
    }

    Angle3 operator+(const Angle3& rhs)
    {
        return Angle3(mX + rhs.mX, mY + rhs.mY, mZ + rhs.mZ);
    }

    Angle3 operator-(const Angle3& rhs)
    {
        return Angle3(mX - rhs.mX, mY - rhs.mY, mZ - rhs.mZ);
    }

    bool operator==(const Angle3& rhs) const
    {
        return mX == rhs.mX && mY == rhs.mY && mZ == rhs.mZ;
    }

    bool operator!=(const Angle3& rhs) const
    {
        return mX != rhs.mX || mY != rhs.mY || mZ != rhs.mZ;
    }

protected:
    Angle mX;
    Angle mY;
    Angle mZ;
};
static_assert(sizeof(Angle3) == 0xC);
