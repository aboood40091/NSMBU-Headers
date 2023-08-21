#pragma once

#include <collision/LoopRideLineBgCollisionUtil.h>
#include <collision/SimpleShapeBgCollision.h>

#include <container/seadSafeArray.h>

class SimpleBoxBgCollision : public SimpleShapeBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9EA0
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FCC
    SEAD_RTTI_OVERRIDE(SimpleBoxBgCollision, SimpleShapeBgCollision)

public:
    SimpleBoxBgCollision()
        : SimpleShapeBgCollision(4, mPointArray.getBufferPtr(), mRideLineArray.getBufferPtr(), mRideLinePrevArray.getBufferPtr())
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
static_assert(sizeof(SimpleBoxBgCollision) == 0x290);

class BoxBgCollision : public SimpleBoxBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9D38
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FBC
    SEAD_RTTI_OVERRIDE(BoxBgCollision, SimpleBoxBgCollision)

public:
    void setCommon(const FollowArg& follow_arg, const BoxInitArg& init_arg)
    {
        LoopRideLineBgCollisionUtil::setCommon(this, follow_arg, init_arg);
    }

    void set(Actor* p_owner, const BoxInitArg& arg)
    {
        LoopRideLineBgCollisionUtil::set(this, p_owner, arg);
    }

    void setOfs(const sead::Vector2f& p0, const sead::Vector2f& p1) // left top and right bottom
    {
        LoopRideLineBgCollisionUtil::setOfs(this, p0, p1);
    }
};
static_assert(sizeof(BoxBgCollision) == sizeof(SimpleBoxBgCollision));
