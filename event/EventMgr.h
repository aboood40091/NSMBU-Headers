#pragma once

#include <container/seadOffsetList.h>
#include <heap/seadDisposer.h>

class ActorBase;
class EventBase;

class EventMgr
{
    // createInstance()                             Address: 0x024A5B2C
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D136C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024A6080
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D1370
    // SingletonDisposer_::vtbl                     Address: 0x100B49F8
    SEAD_SINGLETON_DISPOSER(EventMgr)

public:
    // Address: 0x024A5AA8
    EventMgr();

    EventBase* getCurrentEvent() const
    {
        return mCurrentEvent;
    }

    // Address: 0x024A5BAC
    bool isNormal() const;

    // Address: 0x024A5E48
    bool isJoin(const ActorBase* actor) const;

    // Address: 0x024A5EA4
    bool pushEvent(EventBase* event);

    // Address: 0x024A5F24
    void execute();

    void clearEvent()
    {
        mEventList.clear();
    }

    // Address: 0x024A5FDC
    void eraseEvent(EventBase* event);

protected:
    sead::OffsetList<EventBase> mEventList;     // This actually functions like a queue
    EventBase*                  mCurrentEvent;
};
static_assert(sizeof(EventMgr) == 0x24);
