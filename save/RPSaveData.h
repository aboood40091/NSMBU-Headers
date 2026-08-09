#pragma once
#include <types.h>

struct RPSaveData
{
public:
    struct Header
    {
        u32     mMagic;
        u8      mVersionMajor;
        u8      mVersionMinor;
        u8      mVersionPatch;
        u8      mLastSlot;
        u8      mRDashState;
        u8      mButtonLayout;
        u32     mCrc32;
    };
    static_assert(sizeof(Header) == 0x10);

    struct SaveSlot
    {
        bool    mIsValid;
        u8      mLastPlayerNum;
        u8      mCoinCount;
        u8      mW6SwitchState;
        u8      mCSLocation[3];
        u8      mCSLocation2[3];
        u8      _a[2];
        u8      mPlayerLives[4];
        u8      mPlayerCharacter[4];
        u8      mPlayerPowerUp[4];
        u8      mPlayerGameOverNum[4];
        u16     mFinishedWorldFlag;   
        u8      mGameCompletionFlag;
        u8      _1F[0x11];
        u32     mScore;
        u8      _34[0x10];
        u16     mCreditsHighScore;
        u8      mAirshipCSLocation[3];
        u8      mNabbit1;
        u8      mNabbit2;
        u8      _4B[10];
        u8      mCSBabyYoshiFlag;
        u8      mCurrentBabyYoshi;
        u8      _57[3];
        u8      mBalloonBabyYoshiHiddenCounter;
        u8      mBubbleBabyYoshiHiddenCounter;
        u32     _5C;
        u32     _60; // something Ambush related
        bool    mIsNabbitInW[7];
        u8      mLevelStatData[0xB9];
        u8      mStarCoin[41];
        u8      mCSInventoryItems[10];
        u8      _157[0x204-0x157];
    };
    static_assert(sizeof(SaveSlot) == 0x204);

    struct SaveSlots
    {
        SaveSlot    mNSBUSlots[3];
        SaveSlot    mNSLUSlots[3];
    };
    static_assert(sizeof(SaveSlots) == 0xC18);

    struct Statistics
    {
        u32     mTotalPlayTime;
        u32     mStoryPlayTime;
        u32     mStoryCourseCount;
        u32     mStoryCourseCount1P;
        u32     mStoryCourseCount2P;
        u32     mStoryCourseCount3P;
        u32     mStoryCourseCount4P;
        u32     mStoryCourseCountSpecial;
        u32     mQuestPlayCount;
        u32     mOtehonPlayCount;
        u32     mBoostCourseCount;
        u32     mBoostCourseCount1P;
        u32     mBoostCourseCount2P;
        u32     mBoostCourseCount3P;
        u32     mBoostCourseCount4P;
        u32     mBoostCourseCountSpecial;
        u32     mBoostCourseCountMii;
        u32     mCoinBattlePlayCourseCount;
        u32     mCoinBattlePlayCourseCountP1;
        u32     mCoinBattlePlayCourseCountP2;
        u32     mCoinBattlePlayCourseCountP3;
        u32     mCoinBattlePlayCourseCountP4;
        u32     mCoinBattlePlayCourseCountSpecial;
        u32     mCoinBattlePlayCourseCountMii;
        u32     mCoinBattlePlayEditCourseCount;
        u32     mChallengePlayCount;  
        u32     mChallengePlayAndRetryCount;
        u32     mChallengeReplayPlayCount;
        u32     mChallengeBoostPlayCount;
        u32     mLuigiStoryCourseCount;
        u32     mWiiMoteRelatedCourseCount1;
        u32     mWiiMoteRelatedCourseCount2;
        u32     mWorldItemUseCount;
        u8      mMarioStoryReachedWorld;
        u8      mMarioStoryStarCoinNum;
        bool    mStoryRelatedBool1;
        bool    mStoryRelatedBool2;
        u8      mLuigiStoryStarCoinNum;
        u8      mLuigiStoryReachedWorld;
        u8      mChallengeGoldCount;
        u8      mChallengeSilverCount;
        u8      mChallengeBronzeCount;
        u8      mChallengeBoostCount;
        u8      mPadding[0x2];
        u32     mCrc32;
    };
    static_assert(sizeof(Statistics) == 0x94);

private:
    Header      mHeader;
    SaveSlots   mMainSlots;
    SaveSlots   mQuickSaveSlots;
    u8          mChallenges[0x360C];
    u8          mBoostRush[0xA8];
    u8          mCoinEdit[0x5F38];
    Statistics  mStatistics;
    u8          mMiiData[0x274];
};
static_assert(sizeof(RPSaveData) == 0xB134);