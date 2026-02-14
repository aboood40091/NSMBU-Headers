#pragma once

#include <event/EventBase.h>

class EventDown : public EventBase  // vtbl Address: 0x100B4754
{
public:
    enum DieType
    {
        cDieType_Normal = 0,
        cDieType_Fall,
        cDieType_Yogan,
        cDieType_Poison,
        cDieType_DeathCloud,
        cDieType_None
    };
    static_assert(sizeof(DieType) == 4);

public:
    // Address: 0x024A50EC
    EventDown(s32 player_no);

    virtual ~EventDown()
    {
    }

    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9EBC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA81C
    SEAD_RTTI_OVERRIDE(EventDown, EventBase)

public:
    // Address: 0x024A5168
    void enter() override;
    // Address: 0x024A52A8
    ExecuteState execute() override;
    // Address: 0x024A52F0
    bool isJoin(const ActorBase* p_actor) const override;

private:
    s32     mPlayerNo;
    u8      _1c;
    bool    mIsDone;
    u8      _1e;
    DieType mDieType;
};
static_assert(sizeof(EventDown) == 0x24);
