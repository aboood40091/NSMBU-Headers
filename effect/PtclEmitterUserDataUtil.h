#pragma once

#include <basis/seadTypes.h>

class PtclEmitterUserDataUtil
{
public:
    static bool isCalcGroup(s32 group_id);

    static bool isForceCalcEmitterSet(u16 user_data_bit);
    static u8 getEmitterSetGroupID(u16 user_data_bit);

    static u32 getEmitterUserType(u16 user_data_bit);
    static u32 getEmitterColorType(u16 user_data_bit);
};
