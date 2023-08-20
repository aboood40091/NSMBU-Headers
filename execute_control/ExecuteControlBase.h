#pragma once

#include <container/seadListImpl.h>
#include <heap/seadDisposer.h>

class ActorBase;
class ExecuteControlMgr;

class ExecuteControlBase : public sead::IDisposer
{
public:
    // Address: 0x024A4AC8
    ExecuteControlBase();
    // Address: 0x024A4B28
    virtual ~ExecuteControlBase();

    SEAD_RTTI_BASE(ExecuteControlBase)

protected:
    virtual void initializeCurrent_()
    {
    }

    virtual s32 currentState_() // 0: Pause, 1: Pause Done
    {
        return 0;
    }

    virtual void finalizeCurrent_()
    {
    }

    virtual void onDestroyQueued_()
    {
    }

    virtual void onDestroyCurrent_()
    {
    }

    virtual bool isActorPauseOff_(ActorBase* p_actor)
    {
        return false;
    }

protected:
    sead::ListNode  mListNode;

    friend class ExecuteControlMgr;
};
static_assert(sizeof(ExecuteControlBase) == 0x18);
