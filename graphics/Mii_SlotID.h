#pragma once

#include <basis/seadTypes.h>

namespace Mii {

class SlotID
{
public:
    SlotID()
    {
        setValue(5, 0);
    }

    SlotID(u32 value)
    {
        setValue(value);
    }

    void setValue(u32 value)
    {
        mValue = value;
    }

    void setValue(u32 type, u32 slotNo)
    {
        mValue = type << 24 | (slotNo & 0xffffff);
    }

    u32 getValue() const
    {
        return mValue;
    }

    u32 getType() const
    {
        return mValue >> 24;
    }

    u32 getSlotNo() const
    {
        return mValue & 0xffffff;
    }

private:
    u32 mValue;
};
static_assert(sizeof(SlotID) == 4);

}
