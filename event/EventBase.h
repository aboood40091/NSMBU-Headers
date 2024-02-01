#pragma once

#include <container/seadListImpl.h>
#include <heap/seadDisposer.h>
#include <prim/seadRuntimeTypeInfo.h>

class ActorBase;
class EventMgr;

class EventBase : public sead::IDisposer    // vtbl Address: 0x100B4480
{
public:
    enum ExecuteState
    {
        cState_Waiting      = 0,
        cState_RequestExit
    };

public:
    // Address: 0x024A4AC8
    EventBase();
    // Address: 0x024A4B28
    virtual ~EventBase();

    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9E8C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA7C8
    SEAD_RTTI_BASE(EventBase)

public:
    virtual void enter()
    {
    }

    virtual ExecuteState execute()
    {
        return cState_Waiting;
    }

    virtual void exit()
    {
    }

    virtual void cancel()
    {
    }

    virtual void terminate()
    {
    }

    virtual bool isJoin(const ActorBase* actor) const
    {
        return false;
    }

protected:
    sead::ListNode  mListNode;

    friend class EventMgr;
};
static_assert(sizeof(EventBase) == 0x18);
