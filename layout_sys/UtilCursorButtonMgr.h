#pragma once

#include <basis/seadTypes.h>

class UtilCursorButtonMgr
{
public:
    // Address: 0x02681FC4
    UtilCursorButtonMgr();

protected:
    u32         mSeBackOutputLine;  // CursorButtonBase::OutputLineFlag
    const char* mSeBack;
    u32         mExecStep;
    u32         _c[(0x34 - 0xC) / sizeof(u32)];
};
static_assert(sizeof(UtilCursorButtonMgr) == 0x34);
