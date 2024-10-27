#pragma once

#include <item/ItemObject.h>

class Propeller : public ItemObject
{
    SEAD_RTTI_OVERRIDE(Propeller, ItemObject)

protected:
    u32 _1a98[(0x1AC0 - 0x1A98) / sizeof(u32)];
};
static_assert(sizeof(Propeller) == 0x1AC0);
