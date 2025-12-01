#pragma once

#include <collision/SimpleShapeBgCollision.h>

class SimpleBoxBgCollision : public SimpleShapeBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9EA0
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FCC
    SEAD_RTTI_OVERRIDE(SimpleBoxBgCollision, SimpleShapeBgCollision)

public:
    SimpleBoxBgCollision()
        : SimpleShapeBgCollision(4, mPointArray, mRideLineArray, mRideLinePrevArray)
    {
        for (int i = 0; i < 4; i++)
        {
            mPointArray[i].x = 0.0f;
            mPointArray[i].y = 0.0f;
        }

        for (int i = 0; i < 4; i++)
        {
            mRideLineArray[i].setBgCheckData(mBgCheckData);
            mRideLinePrevArray[i].setBgCheckData(mBgCheckData);
        }
    }

protected:
    sead::Vector2f  mPointArray[4];
    BasicRideLine   mRideLineArray[4];
    BasicRideLine   mRideLinePrevArray[4];
};
static_assert(sizeof(SimpleBoxBgCollision) == 0x290);
