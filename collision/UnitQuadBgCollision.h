#pragma once

#include <collision/UnitBgCollision.h>

#include <container/seadSafeArray.h>

class UnitQuadBgCollision : public UnitBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA394
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA3C4
    SEAD_RTTI_OVERRIDE(UnitQuadBgCollision, UnitBgCollision)

public:
    UnitQuadBgCollision()
        : UnitBgCollision(4, mPointArray.getBufferPtr(), mRideLineArray.getBufferPtr(), mRideLinePrevArray.getBufferPtr())
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
    sead::UnsafeArray<sead::Vector2f,   4>  mPointArray;
    sead::UnsafeArray<BasicRideLine,    4>  mRideLineArray;
    sead::UnsafeArray<BasicRideLine,    4>  mRideLinePrevArray;
};
static_assert(sizeof(UnitQuadBgCollision) == 0x290);
