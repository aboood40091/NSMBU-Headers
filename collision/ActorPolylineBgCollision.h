#pragma once

#include <collision/BasicRideLineBgCollision.h>

template <s32 N>
class ActorPolylineBgCollision : public BasicRideLineBgCollision
{
    SEAD_RTTI_OVERRIDE(ActorPolylineBgCollision, BasicRideLineBgCollision)

private:
    static_assert(N >= 1);

    // Deleted
    void set(Actor* p_owner, const InitArg& arg, s32 point_num, sead::Heap* heap = nullptr);

public:
    ActorPolylineBgCollision()
        : BasicRideLineBgCollision(N, mPointArray, mRideLineArray, mRideLinePrevArray)
    {
        for (int i = 0; i < N+1; i++)
        {
            mPointArray[i].x = 0.0f;
            mPointArray[i].y = 0.0f;
        }

        for (int i = 0; i < N; i++)
        {
            mRideLineArray[i].setBgCheckData(mBgCheckData);
            mRideLinePrevArray[i].setBgCheckData(mBgCheckData);
        }
    }

    void set(Actor* p_owner, const InitArg& base_arg)
    {
        BasicRideLineBgCollision::set(p_owner, base_arg);
    }

protected:
    sead::Vector2f  mPointArray[N+1];
    BasicRideLine   mRideLineArray[N];
    BasicRideLine   mRideLinePrevArray[N];
};
