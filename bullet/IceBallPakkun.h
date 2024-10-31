#pragma once

#include <actor/ActorState.h>

class IceBallPakkun : /* IceBallBase */ public ActorState
{
public:
    void setExludeActor(const ActorUniqueID& id)
    {
        mExcludeActor = id;
    }

    const ActorUniqueID& getExcludeActor() const
    {
        return mExcludeActor;
    }

protected:
    u32             _17c8[(0x1A44 - 0x17C8) / sizeof(u32)];
    ActorUniqueID   mExcludeActor;
    u32             _1a48[(0x1A50 - 0x1A48) / sizeof(u32)];
};
static_assert(sizeof(IceBallPakkun) == 0x1A50);
