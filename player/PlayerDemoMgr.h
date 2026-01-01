#pragma once

#include <container/seadRingBuffer.h>
#include <heap/seadDisposer.h>

class PlayerDemoMgr
{
    SEAD_SINGLETON_DISPOSER(PlayerDemoMgr)

public:
    bool isPlayerGameStop();

    void playOther();

    void setCourseOutList(s32 player_no);

    s32 getCourseOutList(s32 index) const
    {
        return mCourseOutList[index];
    }

    void setCourseOutPlayerNo(s32 player_no)
    {
        mCourseOutPlayerNo = player_no;
    }

    void clearDemoNo(s8 player_no);

protected:
    u32                             _10[(0x158 - 0x10) / sizeof(u32)];
    sead::FixedRingBuffer<s32, 4>   mCourseOutList;
    u32                             _178[(0x1B8 - 0x178) / sizeof(u32)];
    s32                             mCourseOutPlayerNo;
    u32                             _1BC[(0x1F4 - 0x1BC) / sizeof(u32)];
};
static_assert(sizeof(PlayerDemoMgr) == 0x1F4);
