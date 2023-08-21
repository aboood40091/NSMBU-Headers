#pragma once

#include <collision/UnitBgCollision.h>

#include <container/seadSafeArray.h>

class UnitTriangleBgCollision : public UnitBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA390
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA3BC
    SEAD_RTTI_OVERRIDE(UnitTriangleBgCollision, UnitBgCollision)

public:
    UnitTriangleBgCollision()
        : UnitBgCollision(3, mPointArray.getBufferPtr(), mRideLineArray.getBufferPtr(), mRideLinePrevArray.getBufferPtr())
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
    sead::UnsafeArray<sead::Vector2f,   3>  mPointArray;
    sead::UnsafeArray<BasicRideLine,    3>  mRideLineArray;
    sead::UnsafeArray<BasicRideLine,    3>  mRideLinePrevArray;
};
static_assert(sizeof(UnitTriangleBgCollision) == 0x248);
