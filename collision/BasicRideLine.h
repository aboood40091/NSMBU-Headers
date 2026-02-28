#pragma once

#include <collision/BgUnitCode.h>
#include <collision/Segment.h>

class BasicRideLine
{
public:
    // Address: 0x021A1ACC
    BasicRideLine();

    Segment& getSegment()
    {
        return mSegment;
    }

    const Segment& getSegment() const
    {
        return mSegment;
    }

    void setBgCheckData(const u64& bc_data)
    {
        mBgCheckData = bc_data;
    }

private:
    u8      _0;
    u8      _1;
    u8      _2;
    u8      _3;
    Segment mSegment;
    u32     _14;
    u64     mBgCheckData;   // See BgUnitCode
};
static_assert(sizeof(BasicRideLine) == 0x20);
