#pragma once

#include <basis/seadTypes.h>

class PlayerMgr;

class PlayerHIO_General
{
public:
    // Address: 0x10169648
    static const s32 cMaxAngleZ_1;    // 30 degrees
    // Address: 0x1016964C
    static const s32 cMinAngleZ_1;    // -45 degrees

    // Address: 0x10169650
    static const s32 cMaxAngleZ_2;    // 17 degrees
    // Address: 0x10169654
    static const s32 cMinAngleZ_2;    // -17 degrees

    // Address: 0x10169658
    static const s32 cMaxAngleY;      // 113 degrees

    // Address: 0x1016965C
    static const f32 cSandSinkRate;   // -1.26f

public:
    // Address: 0x02911F74
    PlayerHIO_General(PlayerMgr& mgr);
};
static_assert(sizeof(PlayerHIO_General) == 1);
