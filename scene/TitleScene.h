#pragma once

#include <framework/seadCalculateTask.h>
#include <framework/seadTaskMgr.h>

class TitleScene : public sead::CalculateTask   // vtbl Address: 0x10179C74
{
public:
    // Address: 0x0299AC54
    TitleScene(const sead::TaskConstructArg& arg);
    // Address: 0x0299ABEC
    virtual ~TitleScene();
};
static_assert(sizeof(TitleScene) == sizeof(sead::CalculateTask));

// Address: 0x0202B51C
extern template
sead::TaskBase* sead::TTaskFactory<TitleScene>(const sead::TaskConstructArg& arg);
