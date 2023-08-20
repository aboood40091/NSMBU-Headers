#pragma once

#include <heap/seadDisposer.h>

class ExecuteControlBase;

class ExecuteControlMgr
{
    // createInstance()                             Address: 0x024A5B2C
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D136C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024A6080
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D1370
    SEAD_SINGLETON_DISPOSER(ExecuteControlMgr)

public:
    // Address: 0x024A5AA8
    ExecuteControlMgr();

    ExecuteControlBase* getCurrentControl() const
    {
        return mpCurrentControl;
    }

    // Address: 0x024A5BAC
    bool isCurrentControlNotSpecial() const;

    // Address: 0x024A5E48
    bool isActorPauseOff(ActorBase* p_actor) const;

    // Address: 0x024A5EA4
    bool addControl(ExecuteControlBase* p_control);

    // Address: 0x024A5F24
    void execute();

    void destroy()
    {
        mControlQueue.clear();
    }

protected:
    // Address: 0x024A5FDC
    void removeControl_(ExecuteControlBase* p_control);

protected:
    sead::OffsetList<ExecuteControlBase>    mControlQueue;
    ExecuteControlBase*                     mpCurrentControl;

    friend class ExecuteControlBase;
};
