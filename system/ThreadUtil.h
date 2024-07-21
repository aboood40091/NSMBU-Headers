#pragma once

#include <thread/seadThread.h>
#include <thread/seadThreadUtil.h>

class ThreadUtil
{
public:
    enum SeadPriority
    {
        cSeadPriority_ParallelExecuter = sead::Thread::cDefaultSeadPriority + 1,
        cSeadPriority_CourseSelectParallelExecuter,
        cSeadPriority_SaveMgr,
        cSeadPriority_Prepare,
        cSeadPriority_CourseCacheMgr,
        cSeadPriority_BackgroundLoadMgr,
        cSeadPriority_Unused,
        cSeadPriority_Olive,
        cSeadPriority_CommentMgr
    };

public:
    static s32 getPriority(SeadPriority prio)
    {
        return sead::ThreadUtil::ConvertPrioritySeadToPlatform(prio);
    }
};

#define THREAD_PRIORITY(NAME) ThreadUtil::getPriority(ThreadUtil::cSeadPriority_##NAME)
