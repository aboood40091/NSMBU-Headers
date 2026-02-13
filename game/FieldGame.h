#pragma once

#include <game/FieldGameMode.h>
#include <game/FieldPlayerData.h>

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>

class FieldGameData
{
public:
    // Address: 0x024C1B04
    FieldGameData();

    FieldPlayerData& getPlayerData(s32 index)
    {
        return mPlayerData[index];
    }

    const FieldPlayerData& getPlayerData(s32 index) const
    {
        return mPlayerData[index];
    }

    s32 getPlayerCoinNum(s32 index) const
    {
        return mPlayerData[index].coin_cnt;
    }

    void setPlayerCoinNum(s32 index, s32 num)
    {
        mPlayerData[index].coin_cnt = num;
    }

    s32 getCoinNum() const
    {
        return mCoinNum;
    }

    const FieldGameMode& getGameMode() const
    {
        return mGameMode;
    }

private:
    u32                 mCheckPoint[0x14 / sizeof(u32)];    // TODO: CheckPoint
    sead::SafeArray<
        FieldPlayerData,
        4
    >                   mPlayerData;
    s32                 mCoinNum;
    u32                 _138[(0x15C - 0x138) / sizeof(u32)];
    FieldGameMode       mGameMode;
    u32                 _160[(0x1E4 - 0x160) / sizeof(u32)];
};
static_assert(sizeof(FieldGameData) == 0x1E4);

class FieldGame
{
    // createInstance()                             Address: 0x024C2660
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D1604
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024C26F4
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D1608
    // SingletonDisposer_::vtbl                     Address: 0x100B7610
    SEAD_SINGLETON_DISPOSER(FieldGame)

public:
    FieldGameData& getGameData()
    {
        return mGameData;
    }

private:
    FieldGameData   mGameData;
};
static_assert(sizeof(FieldGame) == 0x1F4);
