#pragma once

#include <basis/seadTypes.h>

class InfoStats
{
public:
    // Address: 0x024C4404
    void incKuriboFumi();

private:
    u32 mCoinNum;
    u32 mStarCoinNum;
    u32 mGoalNum;
    u32 mClapNum;
    u32 mBlockMakeWalkDist;     // Quantized value, to dequantize: value / 100 * 16
    u32 mBlockMakeMiniWalkDist; // ^^^
    u32 mShadowCatchNum;
    u32 mKuriboFumiNum;
    u32 mItemGetNum;
    u32 mGoalYoshiNum;
    u32 mGoalChibiYoshiNum;
    u32 mGoal1UpNum;
    u32 mGoalHanabiNum;
    u32 mMoon3UpNum;
};
static_assert(sizeof(InfoStats) == 0x38);
