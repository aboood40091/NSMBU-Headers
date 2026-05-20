#pragma once

#include <utility/Direction.h>

#include <math/seadVector.h>

class ChibiYoshiMgr
{
public:
    // Address: 0x02743BB0
    // type: 0 = bubble, 1 = balloon, 2 = light
    // spawn_type: See BlockCoinBase::VSpawnType
    static void spawnEgg(const sead::Vector3f& pos, u8 type, u32 spawn_type);
};
