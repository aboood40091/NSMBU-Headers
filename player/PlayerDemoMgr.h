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

    s32 getCourseOutPlayerNo() const
    {
        return mCourseOutPlayerNo;
    }

    void setCourseOutPlayerNo(s32 player_no)
    {
        mCourseOutPlayerNo = player_no;
    }

    bool isEnableCheckDemoNo()
    {
        return mIsEnableCheckDemoNo;
    }

    void setEnableCheckDemoNo()
    {
        mIsEnableCheckDemoNo = true;
    }

    s32 getNextDemoNo();
    s32 getNumDemoNo();
    void turnNextDemoNo();
    void clearDemoNo(s32 player_no);
    s32 searchDemoNo(s32 player_no);

protected:
    u32                             _10[(0x158 - 0x10) / sizeof(u32)];
    sead::FixedRingBuffer<s32, 4>   mCourseOutList;
    u32                             _178[(0x1B8 - 0x178) / sizeof(u32)];
    s32                             mCourseOutPlayerNo;
    u32                             _1bc;
    bool                            mIsEnableCheckDemoNo;
    u32                             _1c4[(0x1F4 - 0x1C4) / sizeof(u32)];
};
static_assert(sizeof(PlayerDemoMgr) == 0x1F4);
