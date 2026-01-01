#pragma once

#include <heap/seadDisposer.h>

class Next
{
    SEAD_SINGLETON_DISPOSER(Next)

public:
    // Address: 0x0269B87C
    void setChangeSceneNextDat(u8 file_no, u8 next_goto_no);
    // Address: 0x0269B8C4
    bool isDifferentChangeSceneNextDat(u8 file_no, u8 next_goto_no) const;

    void requestChangeScene()
    {
        mRequestChangeScene = true;
    }

protected:
    u32     _10[(0x30 - 0x10) / sizeof(u32)];
    bool    mNextGotoSet;
    bool    mRequestChangeScene;
    u32     mFaderType; // Maybe?
};
static_assert(sizeof(Next) == 0x38);
