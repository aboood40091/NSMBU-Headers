#pragma once

#include <geom/seadLine.h>

class Segment
{
public:
    // Address: 0x021AF714
    Segment();
    // Address: 0x021AF794
    Segment(const sead::Vector2f& p0, const sead::Vector2f& p1);

    const sead::Segment2f& getSegment() const
    {
        return mSegment;
    }

private:
    sead::Segment2f mSegment;
};
static_assert(sizeof(Segment) == 0x10);
