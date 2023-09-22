#pragma once

#include <container/seadSafeArray.h>
#include <framework/seadCalculateTask.h>
#include <framework/seadTaskMgr.h>
#include <math/seadVector.h>
#include <time/seadTickTime.h>

class CommentMgr : public sead::CalculateTask
{
    SEAD_TASK_SINGLETON_DISPOSER(CommentMgr)

public:
    CommentMgr(const sead::TaskConstructArg& arg);

//protected:
    u8                                      _c8;
    u32                                     _cc;
    u8                                      _d0;
    u8                                      _d1;
    u8                                      _d2;
    u8                                      _d3;
    sead::Vector2f                          _d4;
    u8                                      _dc;
    u8                                      _dd;
    u8                                      _de;
    u32                                     _e0[0x310 / sizeof(u32)];
    u8                                      _3f0;
    u32                                     _3f4[0x318 / sizeof(u32)];
    u8                                      _70c;
    u32                                     _710[0x10 / sizeof(u32)];
    u8                                      _720;
    u8                                      _721;
    u32                                     _724;
    u32                                     _728;
    sead::BitFlag32                         _72c;   // Maybe?
    u32                                     _730[0x1C / sizeof(u32)];
    sead::UnsafeArray<sead::TickTime, 12>   _750;
    u32                                     _7b0;
    u32                                     _7b4;
    u8                                      _7b8;
    u32                                     _7bc;
    u8                                      _7c0;
    u8                                      _7c1;
    u32                                     _7c4;
    u8                                      _7c8;
    u8                                      _7c9;
    u32                                     _7cc;
    u32                                     _7d0;
    u8                                      _7d4;
    u32                                     _7d8;
    u8                                      _7dc;
    u8                                      _7dd;
    u32                                     _7e0;
    u8                                      _7e4;
    u8                                      _7e5;
    u8                                      _7e6;
    u32                                     _7e8;
    u32                                     _7ec;
    // ...
};
static_assert(sizeof(CommentMgr) == 0x7F0);
