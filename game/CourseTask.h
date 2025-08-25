#pragma once

#include <game/FieldGame.h>

#include <framework/seadCalculateTask.h>
#include <framework/seadTaskMgr.h>

class GamesceneBase;

class CourseTask : public sead::CalculateTask   // vtbl Address: 0x100B734C
{
    // setInstance_()                               Address: 0x024BCA80
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D15F0
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024BC924
    SEAD_TASK_SINGLETON_DISPOSER(CourseTask)

public:
    // Address: 0x024BCAA0
    CourseTask(const sead::TaskConstructArg& arg);
    // Address: 0x024BC950
    virtual ~CourseTask();

    GamesceneBase* getGamescene()
    {
        return mpGamescene;
    }

    const FieldGameData& getGameData() const
    {
        return mGameData;
    }

private:
    bool            mCourseRestart;
    GamesceneBase*  mpGamescene;
    u32             _d0[(0x124 - 0xD0) / sizeof(u32)];
    FieldGameData   mGameData;
    u32             _308[(0x5A4 - 0x308) / sizeof(u32)];
};
static_assert(sizeof(CourseTask) == 0x5A4);
