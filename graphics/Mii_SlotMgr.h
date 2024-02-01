#pragma once

#include <heap/seadDisposer.h>

struct FFLStoreData;

namespace Mii {

class DataSource;

class SlotMgr : public sead::IDisposer
{
public:
    // Address: 0x024ECA98
    SlotMgr();

    virtual ~SlotMgr()
    {
        destroy();
    }

    // Address: 0x024ECDDC
    bool initialize();
    // Address: 0x024ECF34
    void destroy();

public:
    static bool getStoreData(FFLStoreData* store_data, const DataSource& source);

private:
    u32 mSlotNum;
    u32 mSlot[0x5E8 / sizeof(u32)]; // sead::FixedObjList<Mii::Slot, 62>
};
static_assert(sizeof(SlotMgr) == 0x5FC);

}
