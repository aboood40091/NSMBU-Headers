#pragma once

#include <geom/seadLine.h>

class Ride2Point
{
public:
    // Address: 0x021AF714
    Ride2Point();
    // Address: 0x021AF794
    Ride2Point(const sead::Vector2f& p0, const sead::Vector2f& p1);

    const sead::Segment2f& getSegment() const
    {
        return mSegment;
    }

private:
    sead::Segment2f mSegment;
};
static_assert(sizeof(Ride2Point) == 0x10);
