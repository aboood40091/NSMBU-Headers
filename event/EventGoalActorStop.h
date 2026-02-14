#pragma once

#include <event/EventBase.h>

class EventGoalActorStop : public EventBase // vtbl Address: 0x100B47C4
{
public:
    // Address: 0x024A5624
    EventGoalActorStop();

    virtual ~EventGoalActorStop()
    {
    }

    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA828
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA8B0
    SEAD_RTTI_OVERRIDE(EventGoalActorStop, EventBase)

public:
    // Address: 0x024A5680
    void enter() override;
    // Address: 0x024A5694
    Result execute() override;

    void setDone()
    {
        mIsDone = true;
    }

private:
    bool    mIsDone;
};
static_assert(sizeof(EventGoalActorStop) == 0x1C);
