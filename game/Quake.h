#pragma once

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

class Quake
{
    // createInstance()                             Address: 0x024C47B4
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D1660
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024C4F14
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D1664
    // SingletonDisposer_::vtbl                     Address: 0x100B7CF0
    SEAD_SINGLETON_DISPOSER(Quake)

public:
    enum ShockType
    {
        cShockType_4 = 4,
        cShockType_PlayerImpact = 8,
        cShockType_PlayerRepeat,
        cShockType_Pow = 12,
        cShockType_Max = 26
    };

    enum ShockFlag
    {
        cShockFlag_ShockCamera  = 1 << 0,
        cShockFlag_ShockMotor   = 1 << 1
    };

public:
    // Address: 0x024C46CC
    Quake();

    // Address: 0x024C4AEC
    void shockMotor(s8 player_no, ShockType type, s32 unk_flag = 0, bool motor_related = false);

    // Address: 0x024C4BD8
    void startShock(s8 player_no, ShockType type, s32 shock_flag, s32 unk_flag, bool motor_related);

    u32 getFlag() const { return mFlag; }
    const sead::Vector2f& getOffset() const { return mOffset; }

private:
    u32             _10[(0x38 - 0x10) / sizeof(u32)];
    u32             mFlag;
    u32             _3c[(0x4C - 0x3C) / sizeof(u32)];
    sead::Vector2f  mOffset;
    u32             _54;
};
static_assert(sizeof(Quake) == 0x58);
