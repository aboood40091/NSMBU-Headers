#pragma once

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

class ActorCoinMgr
{
    // createInstance()                             Address: 0x026CA474
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101DB43C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x026CDF00
    // SingletonDisposer_::sStaticDisposer          Address: 0x101DB440
    // SingletonDisposer_::vtbl                     Address: 0x100F4EAC
    SEAD_SINGLETON_DISPOSER(ActorCoinMgr)

public:
    struct CoinJumpArg
    {
        sead::Vector3f pos;
        s32 dir;
        u8 count;
        u8 layer;
        u8 spawn_height;
        u8 _13;
        u8 spacing_decrease;
        u8 _15;
        u8 curve_type;
    };
    static_assert(sizeof(CoinJumpArg) == 0x18);

public:
    // Address: 0x026CA34C
    ActorCoinMgr();

    // Address: 0x026CABB4
    void spawnItemCoin(const sead::Vector3f& pos, s32 dir, s32 player_no) const;
    // Address: 0x026CB06C
    void spawnCoinJump(const CoinJumpArg& arg, u32 flag = 3) const;
};
