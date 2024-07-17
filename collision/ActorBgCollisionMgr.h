#pragma once

#include <system/LineNodeMgr.h>

#include <heap/seadDisposer.h>

class BgCollision;

class ActorBgCollisionMgr
{
    // createInstance()                             Address: 0x02192460
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101C9360
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x021931F0
    // SingletonDisposer_::sStaticDisposer          Address: 0x101C9364
    // SingletonDisposer_::vtbl                     Address: 0x100415AC
    SEAD_SINGLETON_DISPOSER(ActorBgCollisionMgr)

public:
    const LineNodeMgr<BgCollision>& getActiveList() const
    {
        return mActiveList;
    }

    // Address: 0x0219269C
    void entry(const BgCollision& bg_collision);
    // Address: 0x0219282C
    void release(const BgCollision& bg_collision);

    const LineNodeMgr<BgCollision>& getSolidList() const
    {
        return mSolidList;
    }

    const LineNodeMgr<BgCollision>& getNonSolidList() const
    {
        return mNonSolidList;
    }

    const LineNodeMgr<BgCollision>& getCoinList() const
    {
        return mCoinList;
    }

    const LineNodeMgr<BgCollision>& getPoleList() const
    {
        return mPoleList;
    }

    // Address: 0x02192A9C
    void entryPole(const BgCollision& bg_collision);
    // Address: 0x02192AE0
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
