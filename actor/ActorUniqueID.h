#pragma once

#include <basis/seadTypes.h>

class ActorUniqueID
{
public:
    ActorUniqueID()
        : mValue(0)
    {
    }

    ActorUniqueID(u32 id)
        : mValue(id)
    {
    }

    void setValue(u32 id)
    {
        mValue = id;
    }

    u32 getValue() const
    {
        return mValue;
    }

    u32 getCreateIndex() const
    {
        return mValue & 0x3fffff;
    }

private:
    u32 mValue;
};
static_assert(sizeof(ActorUniqueID) == 4);
