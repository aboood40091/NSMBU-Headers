#pragma once

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>

class SwitchFlagMgr
{
    // Combination of NSMBW's dSwitchFlagMng_c & dPSwManager_c

    SEAD_SINGLETON_DISPOSER(SwitchFlagMgr)

public:
    static const s32 cFlag_Num = 64;

    enum PSwitchType
    {
        cPSwitchType_Num = 3
    };

    enum FlagType
    {
        cFlagType_Normal = 0,
        cFlagType_GreenCoin,
        cFlagType_Switch,
        cFlagType_SwitchMultiUse
    };

private:
    struct FlagStruct1
    {
        u32 duration;   // In seconds
        u32 _4;
        u8  flag;
    };
    static_assert(sizeof(FlagStruct1) == 0xC);

    struct FlagStruct2
    {
        u64 _0;
        f32 _8;
        f32 _c;
        u8  _10;
        u8  _11;
    };
    static_assert(sizeof(FlagStruct2) == 0x18);

public:
    // duration: 0 = permanent, N = 10 * N sec
    void set(u8 flag_bit, u8 duration, bool activate, bool timed_reverse = false, bool = false, u32 = 0, FlagType type = cFlagType_Normal);

    bool isActivated(u8 flag_bit) const
    {
        return mSwitchFlag & (1ULL << flag_bit);
    }

    u32 checkPSwitch(PSwitchType type);

    bool isPSwitch()
    {
        return checkPSwitch(PSwitchType(0)) != 0;
    }

private:
    u64                                     mSwitchFlag;
    sead::SafeArray<FlagStruct1, cFlag_Num> _18;
    sead::SafeArray<FlagStruct2, cFlag_Num> _318;
    u32                                     _918[(0x91C - 0x918) / sizeof(u32)];
    u32                                     mPSwitchFlag;
    sead::SafeArray<u32, cPSwitchType_Num>  _920;
    sead::SafeArray<s32, cPSwitchType_Num>  mPSwitchTimer;
    u32                                     _938[(0x940 - 0x938) / sizeof(u32)];
};
static_assert(sizeof(SwitchFlagMgr) == 0x940);
