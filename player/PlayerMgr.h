#pragma once

#include <player/PlayerHIO_Air.h>
#include <player/PlayerHIO_Anm.h>
#include <player/PlayerHIO_ChibiYoshi.h>
#include <player/PlayerHIO_FlyMusa.h>
#include <player/PlayerHIO_General.h>
#include <player/PlayerHIO_Gravity.h>
#include <player/PlayerHIO_Speed.h>
#include <player/PlayerHIO_Turn.h>

#include <container/seadRingBuffer.h>
#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <math/seadVector.h>
#include <prim/seadBitFlag.h>

class FieldGameData;
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

    void setDemoWaitFlgDisable()
    {
        mDemoWaitFlgDisable.makeAllOne();
    }

    void resetDemoWaitFlgDisable()
    {
        mDemoWaitFlgDisable.makeAllZero();
    }

    bool isDemoWaitFlgDisable(s32 player_no)
    {
        return mDemoWaitFlgDisable.isOnBit(player_no);
    }

    void setPauseDisable(s32 player_no)
    {
        mPauseDisable.setBit(player_no);
    }

    void setPauseEnable(s32 player_no)
    {
        mPauseDisable.resetBit(player_no);
    }

    bool isPauseDisable(s32 player_no)
    {
        return mPauseDisable.isOnBit(player_no);
    }

    bool isDisablePlayerInstrument() const
    {
        return mDisablePlayerInstrument;
    }

    bool isCreateBalloon(s32 player_no)
    {
        return mCreateBalloonFlag.isOnBit(player_no);
    }

    void setAllBalloon()
    {
        mAllBalloon = true;
    }

    bool isAllBalloon() const
    {
        return mAllBalloon;
    }

    void setCannonJump(s32 player_no)
    {
        mCannonJumpFlag.setBit(player_no);
    }

    void resetCannonJump(s32 player_no)
    {
        mCannonJumpFlag.resetBit(player_no);
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

    bool isNormalCourse();

    PlayerBase* getCtrlPlayer(s32 player_no);

    void setPlayer(s32 player_no, PlayerObject* p_player_obj);
    void resetPlayer(s32 player_no);

    bool isAcceptQuake(s32 player_no);

    s32 getNumInGame();

    s32 getEntryNum();

    FieldGameData* getGameData();

    bool isEnableStopOutDokanOther(s32 player_no);

    bool isCourseInStar(s32 player_no);

    void setSubjectClear();

    void setHipAttackQuake(s32 type, s32 player_no, bool ext);

    s32 getCoinNumMin();

private:
    PlayerHIO_General       mPlayerHIO_General;
    PlayerHIO_Speed         mPlayerHIO_Speed;
    PlayerHIO_Air           mPlayerHIO_Air;
    PlayerHIO_Turn          mPlayerHIO_Turn;
    PlayerHIO_Gravity       mPlayerHIO_Gravity;
    u8                      mPlayerHIO_Jump;        // TODO
    u8                      mPlayerHIO_Swim;        // TODO
    PlayerHIO_Anm           mPlayerHIO_Anm;
    u8                      mPlayerHIO_Propel;      // TODO
    u8                      mPlayerHIO_Penguin;     // TODO
    PlayerHIO_FlyMusa       mPlayerHIO_FlyMusa;
    PlayerHIO_ChibiYoshi    mPlayerHIO_ChibiYoshi;
    u8                      mPlayerHIO_Yoshi;       // TODO
    u8                      mPlayerHIO_Totten;      // TODO
    sead::SafeArray<
        PlayerObject*,
        cPlayerNum
    >                       mPlayerObject;
    sead::SafeArray<
        PlayerObject*,
        cPlayerNum
    >                       mPlayerObject2;     // Idk why
    sead::BitFlag8          mCreateFlag;
    sead::BitFlag16         mActPlayerInfo;
    sead::FixedRingBuffer<
        Yoshi*,
        cPlayerNum
    >                       mYoshi;
    sead::FixedRingBuffer<
        Yoshi*,
        cPlayerNum
    >                       mYoshi2;
    u32                     _84;
    u8                      _88;
    sead::BitFlag32         mDemoWaitFlgDisable;
    sead::BitFlag32         mPauseDisable;
    bool                    mDisablePlayerInstrument;
    sead::BitFlag32         mCreateBalloonFlag;
    bool                    mAllBalloon;
    sead::BitFlag8          mCannonJumpFlag;
    s32                     mCannonJumpTimer;
    sead::BitFlag16         mBgmState;
    u32                     _a8;
    s32                     mPreFanfareTimer;
    bool                    mOdaiClear;
    u8                      _b1;
    s32                     mHpDpSpecialType;
    s32                     mCoinMaxNum;
    sead::Vector3f          mPlayerSetPos;
    sead::BitFlag16         mPlayerNextGotoBlockInfo;
    sead::BitFlag16         _ca;
    RDashPhysicsType        mRDashPhysics;
};
static_assert(sizeof(PlayerMgr) == 0xD0);
