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
    {
        setValue(0);
    }

    ActorUniqueID(u32 id)
    {
        setValue(id);
    }

    ActorUniqueID(u32 i_array_index, u32 i_create_index)
    {
        setValue(i_array_index, i_create_index);
    }

    void setValue(u32 id)
    {
        mValue = id;
    }

    void setValue(u32 i_array_index, u32 i_create_index)
    {
        // SEAD_ASSERT(i_array_index <= cArrayIndexMax);
        // SEAD_ASSERT(i_create_index <= cCreateIndexMax);
        mValue = i_array_index << /* log2(cCreateIndexMax + 1) */ 22 | i_create_index;
    }

    u32 getValue() const
    {
        return mValue;
    }

    u32 getArrayIndex() const
    {
        return mValue >> /* log2(cCreateIndexMax + 1) */ 22;
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
