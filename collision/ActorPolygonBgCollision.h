#pragma once

#include <collision/LoopRideLineBgCollision.h>

template <s32 N>
class ActorPolygonBgCollision : public LoopRideLineBgCollision
{
    SEAD_RTTI_OVERRIDE(ActorPolygonBgCollision, LoopRideLineBgCollision)

private:
    static_assert(N >= 3);

    // Deleted
    void set(Actor* p_owner, const InitArg& arg, s32 point_num, sead::Heap* heap = nullptr);

public:
    ActorPolygonBgCollision()
        : LoopRideLineBgCollision(N, mPointArray, mRideLineArray, mRideLinePrevArray)
    {
        for (int i = 0; i < N; i++)
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
        LoopRideLineBgCollision::set(p_owner, base_arg);
    }

protected:
    sead::Vector2f  mPointArray[N];
    BasicRideLine   mRideLineArray[N];
    BasicRideLine   mRideLinePrevArray[N];
};
