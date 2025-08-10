#pragma once

#include <collision/BgUnitCode.h>
#include <collision/Ride2Point.h>

class BasicRideLine
{
public:
    // Address: 0x021A1ACC
    BasicRideLine();

    Ride2Point& getRide2Point()
    {
        return mRide2Point;
    }

    const Ride2Point& getRide2Point() const
    {
        return mRide2Point;
    }

    void setBgCheckData(const BgUnitCode& bc_data)
    {
        mBgCheckData = bc_data;
    }

private:
    u8          _0;
    u8          _1;
    u8          _2;
    u8          _3;
    Ride2Point  mRide2Point;
    u32         _14;
    BgUnitCode  mBgCheckData;
};
static_assert(sizeof(BasicRideLine) == 0x20);
