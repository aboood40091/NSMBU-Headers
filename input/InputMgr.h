#pragma once

#include <heap/seadDisposer.h>
#include <random/seadRandom.h>

class InputMgr
{
    // createInstance()                             Address: 0x0250C348
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2DF8
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0250E978
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D2DFC
    // SingletonDisposer_::vtbl                     Address: 0x100BED44
    SEAD_SINGLETON_DISPOSER(InputMgr)

public:
    // Address: 0x0250C1A0
    InputMgr();

    sead::Random& getRandom()
    {
        return mRandom;
    }

    u8 getBgmBeatTrg() const
    {
        return mBgmBeatTrg;
    }

    bool isBgmBeatTrg(u8 trg) const
    {
        return trg == mBgmBeatTrg;
    }

    u8 getBgmAccentSign() const
    {
        return mBgmAccentSign;
    }

    bool isBgmAccentSign(u8 mask) const
    {
        return mBgmAccentSign & mask;
    }

    u8 getBgmAccentSignCredit() const
    {
        return mBgmAccentSignCredit;
    }

    u16 getBgmTempo() const
    {
        return mBgmTempo;
    }

    bool isPlayerControllerConnected(s32 player_no) const
    {
        return (mControllerConnectionInfo & (1 << player_no)) != 0;
    }

    bool isFadein() const
    {
        return (mControllerConnectionInfo & (1 << 7)) != 0;
    }

    bool isAreaSceneSwitch() const
    {
        return mIsAreaSceneSwitch;
    }

    bool isInputEnabled() const
    {
        return !isFadein() && !isAreaSceneSwitch();
    }

protected:
    u32             _10[(0x52C - 0x10) / sizeof(u32)];
    sead::Random    mRandom;
    bool            mControllersRegistered;
    u16             mBgmTempo;
    u8              mBgmBeatTrg;
    u8              mBgmAccentSign;
    u8              mBgmAccentSignCredit;
    u32             _544[(0x56C - 0x544) / sizeof(u32)];
    u8              mControllerConnectionInfo;
    bool            mIsAreaSceneSwitch;
    u32             _570[(0x57C - 0x570) / sizeof(u32)];
};
static_assert(sizeof(InputMgr) == 0x57C);

#define GAME_RANDOM (InputMgr::instance()->getRandom())
