#pragma once

#include <system/LineNodeMgr.h>

#include <heap/seadDisposer.h>

class BgCollision;

class ActorBgCollisionMgr
{
    SEAD_SINGLETON_DISPOSER(ActorBgCollisionMgr)

public:
    const LineNodeMgr<BgCollision>& getActiveList() const
    {
        return mActiveList;
    }

    void entry(const BgCollision& bg_collision);
    void release(const BgCollision& bg_collision);

    const LineNodeMgr<BgCollision>& getPoleList() const
    {
        return mPoleList;
    }

    void entryPole(const BgCollision& bg_collision);
    void releasePole(const BgCollision& bg_collision);

private:
    LineNodeMgr<BgCollision>    mActiveList;
    LineNodeMgr<BgCollision>    mSolidList;
    LineNodeMgr<BgCollision>    mNonSolidList;
    LineNodeMgr<BgCollision>    mCoinList;
    LineNodeMgr<BgCollision>    mPoleList;
    LineNodeMgr<BgCollision>    _4c;
    LineNodeMgr<BgCollision>    _58;
};
static_assert(sizeof(ActorBgCollisionMgr) == 0x64);
