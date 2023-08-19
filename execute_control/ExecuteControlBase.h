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
    virtual void initialize_()
    {
    }

    virtual bool isPauseDone_()
    {
        return false;
    }

    virtual void finalize_()
    {
    }

    virtual void onDetach_()
    {
    }

    virtual void onDetachCurrent_()
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
