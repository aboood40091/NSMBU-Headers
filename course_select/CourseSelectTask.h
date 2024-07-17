#pragma once

#include <framework/seadCalculateTask.h>
#include <framework/seadTaskMgr.h>

class CourseSelectTask : public sead::CalculateTask // vtbl Address: 0x1005345C
{
    // setInstance_()                               Address: 0x022656C0
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101CC96C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0226551C
    SEAD_TASK_SINGLETON_DISPOSER(CourseSelectTask)

public:
    // Address: 0x022656E0
    CourseSelectTask(const sead::TaskConstructArg& arg);
    // Address: 0x02265548
    virtual ~CourseSelectTask();

//private:
    u32     _cc[(0xDC9 - 0xCC) / sizeof(u32)];
    bool    _dc9;
    u8      _dca[0xDD0 - 0xDCA];
};
static_assert(sizeof(CourseSelectTask) == 0xDD0);
