#pragma once

#include <event/EventBase.h>

class EventPlayerChange : public EventBase  // vtbl Address: 0x100B4B3C
{
public:
    // Address: 0x024A6194
    EventPlayerChange(s32 player_no);

    virtual ~EventPlayerChange()
    {
    }

    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA820
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA824
    SEAD_RTTI_OVERRIDE(EventPlayerChange, EventBase)

public:
    // Address: 0x024A6200
    void enter() override;
    // Address: 0x024A6260
    ExecuteState execute() override;
    // Address: 0x024A6300
    bool isJoin(const ActorBase* p_actor) const override;

private:
    s32     mPlayerNo;
};
static_assert(sizeof(EventPlayerChange) == 0x1C);
