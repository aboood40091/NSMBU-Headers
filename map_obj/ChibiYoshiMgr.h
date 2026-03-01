#pragma once

#include <utility/Direction.h>

#include <math/seadVector.h>

class ChibiYoshiMgr
{
public:
    // Address: 0x02743BB0
    static void spawnEgg(const sead::Vector3f& pos, u8 type, DirType dir_type);
};
