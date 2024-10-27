#pragma once

#include <item/ItemBase.h>

class ItemObj : public ItemBase
{
    SEAD_RTTI_OVERRIDE(ItemObj, ItemBase)

protected:
    u32 _1a90[(0x1A98 - 0x1A90) / sizeof(u32)];
};
static_assert(sizeof(ItemObj) == 0x1A98);
