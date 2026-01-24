#pragma once

#include <container/seadRingBuffer.h>
#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <math/seadVector.h>
#include <prim/seadBitFlag.h>

class PlayerBase;
class PlayerObject;
class Yoshi;

class PlayerMgr
{
    SEAD_SINGLETON_DISPOSER(PlayerMgr)

public:
    enum RDashPhysicsType
    {
        cRDashPhysics_Luigi = 0,
        cRDashPhysics_Mario
    };
    static_assert(sizeof(RDashPhysicsType) == 4);

public:
    PlayerObject* getPlayerObject(s32 player_no)
    {
        return mPlayerObject[player_no];
    }

    PlayerObject* getPlayerObject2(s32 player_no)
    {
        return mPlayerObject2[player_no];
    }

    bool isPlayerActive(s32 player_no)
    {
        return mActPlayerInfo.isOnBit(player_no);
    }

    s32 getNum()
    {
        return mActPlayerInfo.countOnBit();
    }

    void addNum(s32 player_no)
    {
        mActPlayerInfo.setBit(player_no);
    }

    void decNum(s32 player_no)
    {
        mActPlayerInfo.resetBit(player_no);
    }

    void onDemo(s32 player_no)
    {
        mDemoInfo.setBit(player_no);
    }

    void offDemo(s32 player_no)
    {
        mDemoInfo.resetBit(player_no);
    }

    s32 getCannonJumpTimer() const
    {
        return mCannonJumpTimer;
    }

    void onNextGotoBlock(s32 player_no)
    {
        mPlayerNextGotoBlockInfo.setBit(player_no);
    }

    s32 getNumNextGotoBlock()
    {
        return mPlayerNextGotoBlockInfo.countOnBit();
    }

    PlayerBase* getCtrlPlayer(s32 player_no);

    bool isAcceptQuake(s32 player_no);

    s32 getNumInGame();

    bool isEnableStopOutDokanOther(s32 player_no);

    void setSubjectClear();

    void setHipAttackQuake(s32 type, s32 player_no, bool ext);

    s32 getCoinNumMin();

private:
    u32                                 _10[(0x20 - 0x10) / sizeof(u32)];
    sead::SafeArray<PlayerObject*, 4>   mPlayerObject;
    sead::SafeArray<PlayerObject*, 4>   mPlayerObject2;     // Idk why
    sead::BitFlag8                      mCreateFlag;
    sead::BitFlag16                     mActPlayerInfo;
    sead::FixedRingBuffer<Yoshi*, 4>    mYoshi;
    sead::FixedRingBuffer<Yoshi*, 4>    mYoshi2;
    u32                                 _84;
    u8                                  _88;
    sead::BitFlag32                     mPauseDisable;      // Maybe?
    sead::BitFlag32                     mDemoInfo;
    bool                                mDisableOrchestra;
    sead::BitFlag32                     mCreateBalloonFlag;
    bool                                mAllBalloon;
    sead::BitFlag8                      mCannonJumpFlag;
    s32                                 mCannonJumpTimer;
    sead::BitFlag16                     mBgmState;
    u32                                 _a8;
    s32                                 mPreFanfareTimer;
    bool                                mOdaiClear;
    u8                                  _b1;
    s32                                 mHpDpSpecialType;
    s32                                 mCoinMaxNum;
    sead::Vector3f                      mPlayerSetPos;
    sead::BitFlag16                     mPlayerNextGotoBlockInfo;
    sead::BitFlag16                     _ca;
    RDashPhysicsType                    mRDashPhysics;
};
static_assert(sizeof(PlayerMgr) == 0xD0);
