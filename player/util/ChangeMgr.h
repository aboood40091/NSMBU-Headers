#pragma once

#include <player/PlayerEnum.h>

#include <math/seadVector.h>

class ChangeMgr
{
public:
    enum Step
    {
        cStep_None = 0,
        cStep_Change,
        cStep_ChangeEnd
    };
    static_assert(sizeof(Step) == 4);

    enum ChangeType
    {
        cChangeType_None = 0, // MiniToMini & MiniToSmall & SmallToSmall
        cChangeType_1,
        cChangeType_MiniToBig,
        cChangeType_SmallToMini,
        cChangeType_SmallToBig,
        cChangeType_BigToMini,
        cChangeType_BigToSmall,
        cChangeType_BigToBig,
        cChangeType_Num
    };
    static_assert(cChangeType_Num == 8);
    static_assert(sizeof(ChangeType) == 4);

public:
    // Address: 0x02975AE0
    ChangeMgr();

    bool isChange() const
    {
        return mStep != cStep_None;
    }

private:
    PlayerMode      mModeFrom;
    PlayerMode      mModeTo;
    PlayerMode      mModeNow;
    s32             mTimer;
    f32             _10;
    sead::Vector3f  mScale;
    Step            mStep;
    ChangeType      mChangeType;
};
static_assert(sizeof(ChangeMgr) == 0x28);
