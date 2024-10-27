#pragma once

#include <actor/ActorUniqueID.h>

#include <container/seadSafeArray.h>

struct IceInfo
{
    u32             ice_param_0;
    sead::Vector3f  position;
    sead::Vector3f  scale;
    u32             _1c;        // Angle? (Seems to be unused)
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

    // Address: 0x0237CB94
    void setIceStatus(const IceStatus& status);

    // Address: 0x0237D63C
    bool createIce(IceInfo* p_info, s32 num);

protected:
    u8                                          mIceNum;
    sead::SafeArray<ActorUniqueID, cIceMaxNum>  mIceID;
    IceStatus                                   mIceStatus;
    TimeInfo*                                   mpTimeInfo;
    Enemy*                                      mpOwner;
    s16                                         mTimer1;
    s16                                         mTimer2;
    bool                                        mDisabled;  // Maybe?
    bool                                        mPermanent; // Maybe??
    u8                                          _46;
    u8                                          _47;
    u8                                          _48;
    u8                                          _49;
    u8                                          _4a;
    u8                                          mPlayerNo;
    u8                                          _4c;
};
static_assert(sizeof(IceMgr) == 0x50);
