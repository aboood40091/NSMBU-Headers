#pragma once

#include <actor/ActorState.h>

class PlayerObject;

class CarryObjBase : public ActorState
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA8CC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA8D0
    SEAD_RTTI_OVERRIDE(CarryObjBase, ActorState)

public:
    // Address: 0x027221E8
    PlayerObject* getCarryPlayer() const;

    bool checkCarried()
    {
        return mFlag & (1 << 2);
    }

protected:
    u32 _17c8[(0x17E0 - 0x17C8) / sizeof(u32)];
    u32 mFlag;
    u32 _17E4[(0x17F4 - 0x17E4) / sizeof(u32)];
};
static_assert(sizeof(CarryObjBase) == 0x17F8);
