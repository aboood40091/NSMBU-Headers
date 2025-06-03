#pragma once

#include <basis/seadTypes.h>

namespace Mii {

class SlotID
{
public:
    enum Source
    {
        cSource_Database_Default = 0,
        cSource_Database_Official,
        cSource_StoreData_Save,
        cSource_StoreData_Custom,
        cSource_StoreData_Account,
        cSource_Num
    };

public:
    SlotID()
    {
        setValue(cSource_Num, 0);
    }

    SlotID(u32 value)
    {
        setValue(value);
    }

    void setValue(u32 value)
    {
        mValue = value;
    }

    void setValue(Source source, u32 index)
    {
        mValue = source << 24 | (index & 0xffffff);
    }

    u32 getValue() const
    {
        return mValue;
    }

    Source getSource() const
    {
        return Source(mValue >> 24);
    }

    s32 getIndex() const
    {
        return mValue & 0xffffff;
    }

private:
    u32 mValue;
};
static_assert(sizeof(SlotID) == 4);

}
