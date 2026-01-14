#pragma once

#include <state/FStateID.h>

#include <container/seadRingBuffer.h>
#include <heap/seadDisposer.h>
#include <math/seadVector.h>
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
    bool isDemoMode(const StateID& state_id) const;

    bool isGoalDemoMode() const;

    bool isPlayerGameStop();

    bool isGoalDemoKimeWait();
    bool isGoalDemoItem();

    void setSubjectClear();

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

    s32 setGoalDemoList(s32 player_no);

    s32 getGoalDemoNum() const
    {
        return mGoalDemoNum;
    }

    s32 getPoleBelowPlayer(s32 player_no);

    void setPoleDown()
    {
        mGoalFlag.setBit(0);
    }

    void offUnkGoalFlag3()
    {
        mGoalFlag.resetBit(3);
    }

    void onHangFlag()
    {
        mGoalFlag.setBit(4);
    }

    void offHangFlag()
    {
        mGoalFlag.resetBit(4);
    }

    bool isUnkGoalFlag6() const
    {
        return mGoalFlag.isOnBit(6);
    }

    bool isUnkGoalFlag7() const
    {
        return mGoalFlag.isOnBit(7);
    }

    bool isSecretExit() const
    {
        return mIsSecretExit;
    }

    void setSecretExit(bool b)
    {
        mIsSecretExit = b;
    }

    bool isNormalExit() const
    {
        return !mIsSecretExit;
    }

    const sead::Vector2f& getGoalPos() const
    {
        return mGoalPos;
    }

    void setGoalPos(const sead::Vector2f& pos)
    {
        mGoalPos = pos;
    }

    void setGoalWalkTargetPosX(f32 x)
    {
        mGoalWalkTargetPosX = x;
    }

    void setHanabiPos(const sead::Vector3f& pos)
    {
        mHanabiPos = pos;
    }

    void stopBgmGoalDemo();

    bool isUnderwaterKoopaJrDemo() const
    {
        return mFlag.isOnBit(0);
    }

    s32 getControlDemoPlayerNum() const;

protected:
    u32                             _10[(0x3C - 0x10) / sizeof(u32)];
    sead::BitFlag32                 mGoalFlag;
    u32                             _40[(0x48 - 0x40) / sizeof(u32)];
    s32                             mGoalDemoNum;
    u32                             _4c[(0xD8 - 0x4C) / sizeof(u32)];
    bool                            mIsSecretExit;
    u32                             _dc[(0xF0 - 0xDC) / sizeof(u32)];
    sead::Vector2f                  mGoalPos;
    u32                             _f8[(0x108 - 0xF8) / sizeof(u32)];
    f32                             mGoalWalkTargetPosX;
    u32                             _10c[(0x128 - 0x10C) / sizeof(u32)];
    sead::Vector3f                  mHanabiPos;
    u32                             _134[(0x158 - 0x134) / sizeof(u32)];
    sead::FixedRingBuffer<s32, 4>   mCourseOutList;
    u32                             _178[(0x1B8 - 0x178) / sizeof(u32)];
    s32                             mCourseOutPlayerNo;
    u32                             _1bc;
    bool                            mIsEnableCheckDemoNo;
    sead::BitFlag32                 mFlag;
    u32                             _1c8[(0x1F4 - 0x1C8) / sizeof(u32)];
};
static_assert(sizeof(PlayerDemoMgr) == 0x1F4);
