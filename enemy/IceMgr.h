#pragma once

#include <actor/ActorUniqueID.h>

#include <container/seadSafeArray.h>

struct IceEfScale;

enum IceType
{
    cIceType_Square = 0,
    cIceType_Tate,
    cIceType_Yoko,
    cIceType_BigSquare,
    cIceType_BigTate,
    cIceType_BigYoko,
    cIceType_Num
};
static_assert(cIceType_Num == 6);

struct IceInfo
{
    u32                 ice_param_0;
    sead::Vector3f      position;
    sead::Vector3f      scale;
    const IceEfScale*   p_ef_scale;     // Was actually applied in NSMBW, but no longer does anything in NSMBU

    static u32 makeParam(IceType type, bool unk_1 = false, u32 unk_2 = 0, bool unk_3 = false)
    {
        return (
            ((u32)type & 7) |
            ((u32)unk_1 << 12) |
            ((unk_2 & 0xF) << 24) |
            ((u32)unk_3 << 28)
        );
    }
};

class Enemy;

class IceMgr
{
public:
    static const s32 cIceMaxNum = 12;

public:
    struct IceStatus
    {
        union
        {
            struct
            {
                u8  melt_time_type;
                u8  ice_act_1;
                u8  ice_act_2;
            };
            u32 _0;
        };

        IceStatus()
            : melt_time_type(0)
            , ice_act_1(0)
            , ice_act_2(4)
        {
        }

        IceStatus(s32 melt_time_type_, s32 ice_act_1_, s32 ice_act_2_)
            : melt_time_type(melt_time_type_)
            , ice_act_1(ice_act_1_)
            , ice_act_2(ice_act_2_)
        {
        }
    };
    static_assert(sizeof(IceStatus) == 4);

    struct TimeInfo
    {
        s16 melt;
        s16 melt_shake;
    };
    static_assert(sizeof(TimeInfo) == 4);

public:
    // Address: 0x0237CBBC
    IceMgr(Enemy* p_owner);
    // Address: 0x0237CD54
    ~IceMgr();

    // Address: 0x0237CB94
    void setIceStatus(const IceStatus& status);

    // Address: 0x0237D63C
    bool createIce(IceInfo* p_info, s32 num);
    // Address: 0x0237CCC8
    void removeIce();

    bool hasIce() const
    {
        return mHasIce;
    }

protected:
    u8                                          mIceNum;
    sead::SafeArray<ActorUniqueID, cIceMaxNum>  mIceID;
    IceStatus                                   mIceStatus;
    TimeInfo*                                   mpTimeInfo;
    Enemy*                                      mpOwner;
    s16                                         mTimer1;
    s16                                         mTimer2;
    bool                                        mHasIce;  // Maybe?
    bool                                        mPermanent; // Maybe??
    u8                                          _46;
    u8                                          _47;
    u8                                          _48;
    u8                                          _49;
    u8                                          _4a;
    s8                                          mPlayerNo;
    u8                                          _4c;
};
static_assert(sizeof(IceMgr) == 0x50);
