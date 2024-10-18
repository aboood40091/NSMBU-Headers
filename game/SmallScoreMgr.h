#pragma once

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

class SmallScoreMgr
{
    // createInstance()                             Address: 0x024CC864
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D1860
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024CD354
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D1864
    // SingletonDisposer_::vtbl                     Address: 0x100B9168
    SEAD_SINGLETON_DISPOSER(SmallScoreMgr)

public:
    // Address: 0x024CC774
    SmallScoreMgr();

    // Address: 0x024CCA84
    void createSmallScore(const sead::Vector3f& pos, s32 action, s32 player_no, bool goal_score = false, u32 = 0);

private:
    u32 _10[(0x3B5F8 - 0x10) / sizeof(u32)];
};
static_assert(sizeof(SmallScoreMgr) == 0x3B5F8);
