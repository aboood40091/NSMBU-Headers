#pragma once

#include <item/ItemObj.h>

class Propeller : public ItemObj
{
    SEAD_RTTI_OVERRIDE(Propeller, ItemObj)

protected:
    u32 _1a98[(0x1AC0 - 0x1A98) / sizeof(u32)];
};
static_assert(sizeof(Propeller) == 0x1AC0);
