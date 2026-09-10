#pragma once

#include <map_obj/CarryObjBase.h>

class ActorBoxBgCollision;

class CarryBlockBase : public CarryObjBase  // vtbl Address: 0x10105988
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA8D4
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA8D8
    SEAD_RTTI_OVERRIDE(CarryBlockBase, CarryObjBase)

public:
    CarryBlockBase(const ActorCreateParam& param, ActorBoxBgCollision& bg_collision, s32 fukidashi_type);

protected:
    ActorBoxBgCollision*    mpBoxBgCollision;
    s32                     _17fc;
};
static_assert(sizeof(CarryBlockBase) == 0x1800);
