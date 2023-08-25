#pragma once

#include <collision/BasicRideLineBgCollision.h>

#include <container/seadSafeArray.h>

class ActorLineBgCollision : public BasicRideLineBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA0FC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA100
    SEAD_RTTI_OVERRIDE(ActorLineBgCollision, BasicRideLineBgCollision)

private:
    // Deleted
    void set(Actor* p_owner, const InitArg& arg, s32 point_num, sead::Heap* heap = nullptr);

public:
    ActorLineBgCollision()
        : BasicRideLineBgCollision(1, mPointArray.getBufferPtr(), mRideLineArray.getBufferPtr(), mRideLinePrevArray.getBufferPtr())
    {
        for (int i = 0; i < 2; i++)
        {
            mPointArray[i].x = 0.0f;
            mPointArray[i].y = 0.0f;
        }

        for (int i = 0; i < 1; i++)
        {
            mRideLineArray[i].setBgCheckData(mBgCheckData);
            mRideLinePrevArray[i].setBgCheckData(mBgCheckData);
        }
    }

    void set(Actor* p_owner, const InitArg& base_arg)
    {
        BasicRideLineBgCollision::set(p_owner, base_arg);
    }

    void set(Actor* p_owner, const sead::Vector2f& p0, const sead::Vector2f& p1, s32 angle = 0)
    {
        const sead::Vector2f points[2] = { p0, p1 };
        InitArg base_arg = { sead::Vector2f(0.0f, 0.0f), sead::Vector2f(0.0f, 0.0f), points, angle };
        set(p_owner, base_arg);
    }

    void set(Actor* p_owner, const LineInitArg& arg)
    {
        InitArg base_arg = { arg.pos_offset, arg.rot_pivot_offset, arg.points, arg.angle };
        set(p_owner, base_arg);
    }

protected:
    sead::UnsafeArray<sead::Vector2f,   2>  mPointArray;
    sead::UnsafeArray<BasicRideLine,    1>  mRideLineArray;
    sead::UnsafeArray<BasicRideLine,    1>  mRideLinePrevArray;
};
static_assert(sizeof(ActorLineBgCollision) == 0x1C8);
