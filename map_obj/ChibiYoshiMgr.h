#pragma once

#include <math/seadVector.h>

class ChibiYoshiMgr
{
public:
    // Address: 0x02743BB0
    static void spawnEgg(const sead::Vector3f& pos, u8 type, u32 dir_type);
};
