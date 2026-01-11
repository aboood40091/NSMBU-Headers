#pragma once

#include <container/seadRingBuffer.h>
#include <heap/seadDisposer.h>
#include <prim/seadBitFlag.h>

class PlayerDemoMgr
{
    SEAD_SINGLETON_DISPOSER(PlayerDemoMgr)

public:
    enum Mode
    {
        cMode_None,
        cMode_Wait,
        cMode_Goal,
        cMode_Num
    };
    static_assert(cMode_Num == 3);

public:
    void setDemoMode(Mode mode);

    bool isPlayerGameStop();

    bool isGoalDemoKimeWait();

    void stopOther();
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

    bool checkDemoNo(s8* p_player_no)
    {
        return isEnableCheckDemoNo() && getNextDemoNo() == *p_player_no;
    }

    s32 getNextDemoNo();
    s32 getNumDemoNo();
    void turnNextDemoNo();
    void clearDemoNo(s32 player_no);
    s32 searchDemoNo(s32 player_no);

    bool isUnderwaterKoopaJrDemo() const
    {
        return mFlag.isOnBit(0);
    }

protected:
    u32                             _10[(0x158 - 0x10) / sizeof(u32)];
    sead::FixedRingBuffer<s32, 4>   mCourseOutList;
    u32                             _178[(0x1B8 - 0x178) / sizeof(u32)];
    s32                             mCourseOutPlayerNo;
    u32                             _1bc;
    bool                            mIsEnableCheckDemoNo;
    sead::BitFlag32                 mFlag;
    u32                             _1c8[(0x1F4 - 0x1C8) / sizeof(u32)];
};
static_assert(sizeof(PlayerDemoMgr) == 0x1F4);
