#pragma once

#include <heap/seadDisposer.h>
#include <prim/seadBitFlag.h>

class CourseTimer
{
    // createInstance()                             Address: 0x024C12C4
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D15F4
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024C15C8
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D15F8
    // SingletonDisposer_::vtbl                     Address: 0x100B74B8
    SEAD_SINGLETON_DISPOSER(CourseTimer)

public:
    void onStopTimer(s32 player_no)
    {
        mStopTimerInfo.setBit(player_no);
    }

    void offStopTimer(s32 player_no)
    {
        mStopTimerInfo.resetBit(player_no);
    }

    void onFreezeFrame()
    {
        mFreezeTime++;
    }

protected:
    u32             mFreezeTime;
    u32             mTime;          // seconds << 12
    u32             mBeginTime;
    bool            mIsHurryUp;
    sead::BitFlag8  mStopTimerInfo;
    u16             _1e;
};
static_assert(sizeof(CourseTimer) == 0x20);
