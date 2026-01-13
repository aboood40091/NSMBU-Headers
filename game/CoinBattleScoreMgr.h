#pragma once

#include <heap/seadDisposer.h>

class CoinBattleScoreMgr
{
    // createInstance()                             Address: 0x024BBE40
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D15D8
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024BBF94
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D15DC
    // SingletonDisposer_::vtbl                     Address: 0x100B6FE8
    SEAD_SINGLETON_DISPOSER(CoinBattleScoreMgr)

public:
    // Address: 0x024BBF18
    void incCoin(s32 num, s32 player_no);

    // Address: 0x024BBF50
    s32 calcGoalBonusCoinNum(f32 height_from_goal_pos);
};
