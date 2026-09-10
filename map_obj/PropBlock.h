#pragma once

#include <map_obj/CarryBlockBase.h>

class PropBlock : public CarryBlockBase // vtbl Address: 0x1014CF64
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EB87C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EB880
    SEAD_RTTI_OVERRIDE(PropBlock, CarryBlockBase)

public:
    // Address: 0x02868440
    PropBlock(const ActorCreateParam& param);

private:
    u32 _1800[(0x1C4C - 0x1800) / sizeof(u32)];
};
static_assert(sizeof(PropBlock) == 0x1C50);
