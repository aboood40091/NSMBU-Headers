#pragma once

#include <collision/UnitBgCollision.h>

class UnitQuadBgCollision : public UnitBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA394
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA3C4
    SEAD_RTTI_OVERRIDE(UnitQuadBgCollision, UnitBgCollision)

public:
    UnitQuadBgCollision()
        : UnitBgCollision(4, mPointArray, mRideLineArray, mRideLinePrevArray)
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
static_assert(sizeof(UnitQuadBgCollision) == 0x290);
