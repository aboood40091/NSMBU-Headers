#pragma once

#include <basis/seadTypes.h>

class PtclEmitterUserDataUtil
{
public:
    // Address: 0x022AC3A0
    static bool isCalcGroup(s32 group_id);

    // Address: 0x022AC4C0
    static bool isForceCalcEmitterSet(u16 user_data_bit);
    // Address: 0x022AC4C8
    static u8 getEmitterSetGroupID(u16 user_data_bit);

    // Address: 0x022AC508
    static u32 getEmitterUserType(u16 user_data_bit);
    // Address: 0x022AC604
    static u32 getEmitterColorType(u16 user_data_bit);
};
