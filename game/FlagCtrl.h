#pragma once

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>

class FlagCtrl
{
    // createInstance()                             Address: 0x024C2938
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D160C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024C2CA8
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D1610
    // SingletonDisposer_::vtbl                     Address: 0x100B7620
    SEAD_SINGLETON_DISPOSER(FlagCtrl)

private:
    struct Flag
    {
        union
        {
            struct
            {
                u16 cd_file_no;
                u16 x;
                u16 y;
                u16 flag;
            };
            u64 value;
        };
    };
    static_assert(sizeof(Flag) == 8);

    typedef sead::SafeArray<Flag, 256> FlagArray;
    typedef FlagArray::iterator iterator;

public:
    // Address: 0x024C29D4
    void initialize();

    // Address: 0x024C2B10
    u16 getFlagData(u16 cd_file_no, f32 x, f32 y);

    // Address: 0x024C2B78
    bool setFlagData(u16 cd_file_no, f32 x, f32 y, u16 flag);

private:
    // Address: 0x024C2A10
    static u8 flagToIndex_(Flag flag);

    // Address: 0x024C2A30
    iterator find_(u16 cd_file_no, u16 x, u16 y);

private:
    FlagArray   mFlag;
};
static_assert(sizeof(FlagCtrl) == 0x810);
