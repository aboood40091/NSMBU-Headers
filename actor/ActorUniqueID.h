#pragma once

#include <basis/seadTypes.h>

class ActorUniqueID
{
public:
    static const u32 cInvalidID         = 0;
    static const u32 cArrayIndexMax     = 0x3ff;
    static const u32 cCreateIndexMax    = 0x3fffff;

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
        return mValue & cCreateIndexMax;
    }

    bool isValid() const
    {
        return mValue != cInvalidID;
    }

private:
    u32 mValue;
};
static_assert(sizeof(ActorUniqueID) == 4);
