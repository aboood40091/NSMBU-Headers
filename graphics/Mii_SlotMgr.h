#pragma once

#include <heap/seadDisposer.h>

struct FFLStoreData;

namespace Mii {

class SlotID;

class SlotMgr : public sead::IDisposer  // vtbl Address: 0x100BBE24
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
    // Address: 0x024ECF98
    static bool getStoreData(FFLStoreData* p_store_data, const SlotID& slot_id);

private:
    u32 mSlotNum;
    u32 mSlot[0x5E8 / sizeof(u32)]; // sead::FixedObjList<Mii::Slot, 62>
};
static_assert(sizeof(SlotMgr) == 0x5FC);

}
