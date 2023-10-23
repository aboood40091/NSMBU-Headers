#pragma once

#include <heap/seadDisposer.h>

struct FFLStoreData;

namespace Mii {

class SlotID;

class SlotMgr : public sead::IDisposer
{
public:
    // Address: 0x024ECA98
    SlotMgr();

public:
    static bool getStoreData(FFLStoreData* p_store_data, const SlotID& slotID);

private:
    u32 mSlotNum;
    u32 mSlot[0x5E8 / sizeof(u32)]; // sead::FixedObjList<Mii::Slot, 62>
};
static_assert(sizeof(SlotMgr) == 0x5FC);

}
