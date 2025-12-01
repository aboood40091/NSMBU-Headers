#pragma once

#include <collision/UnitBgCollision.h>

class UnitTriangleBgCollision : public UnitBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA390
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA3BC
    SEAD_RTTI_OVERRIDE(UnitTriangleBgCollision, UnitBgCollision)

public:
    UnitTriangleBgCollision()
        : UnitBgCollision(3, mPointArray, mRideLineArray, mRideLinePrevArray)
    {
        for (int i = 0; i < 3; i++)
        {
            mPointArray[i].x = 0.0f;
            mPointArray[i].y = 0.0f;
        }

        for (int i = 0; i < 3; i++)
        {
            mRideLineArray[i].setBgCheckData(mBgCheckData);
            mRideLinePrevArray[i].setBgCheckData(mBgCheckData);
        }
    }

protected:
    sead::Vector2f  mPointArray[3];
    BasicRideLine   mRideLineArray[3];
    BasicRideLine   mRideLinePrevArray[3];
};
static_assert(sizeof(UnitTriangleBgCollision) == 0x248);
