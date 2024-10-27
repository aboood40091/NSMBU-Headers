#pragma once

#include <item/ItemBase.h>

class ItemObject : public ItemBase
{
    SEAD_RTTI_OVERRIDE(ItemObject, ItemBase)

protected:
    u32 _1a90[(0x1A98 - 0x1A90) / sizeof(u32)];
};
static_assert(sizeof(ItemObject) == 0x1A98);
