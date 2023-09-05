#pragma once

#include <framework/cafe/seadGameFrameworkCafe.h>

#include <cafe/procui.h>

class ApplicationFramework : public sead::GameFrameworkCafe
{
    SEAD_RTTI_OVERRIDE(ApplicationFramework, sead::GameFrameworkCafe)

public:
    ApplicationFramework(const CreateArg& arg);

    virtual void run(sead::Heap*, const sead::TaskBase::CreateArg&, const RunArg&);
    virtual void createProcessMeter(sead::TaskBase*);

protected:
    virtual void waitStartDisplayLoop_();
    virtual void procDraw_();
    virtual void procCalc_();
    virtual void swapBuffer_();

protected:
    sead::ProcessMeterBarBase   _378;   // sead::MultiProcessMeterBar<???>
    sead::ProcessMeterBarBase   _380;   // sead::MultiProcessMeterBar<???>
    u8                          _388;
    u32                         _38C;
    u32                         _390;
    ProcUIStatus                mProcUIStatus;
};
static_assert(sizeof(ApplicationFramework) == 0x398);
