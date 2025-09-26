#pragma once

#include <container/seadRingBuffer.h>
#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <prim/seadBitFlag.h>

class PlayerObject;
class Yoshi;

class PlayerMgr
{
    SEAD_SINGLETON_DISPOSER(PlayerMgr)

public:
    PlayerObject* getPlayerObject(s32 player_no)
    {
        return mPlayerObject[player_no];
    }

    PlayerObject* getPlayerObject2(s32 player_no)
    {
        return mPlayerObject2[player_no];
    }

    bool isPlayerActive(s32 player_no)
    {
        return mPlayerFlag.isOnBit(player_no);
    }

    s32 getNum()
    {
        return mPlayerFlag.countOnBit();
    }

    bool isAcceptQuake(s32 player_no);

    s32 getNumInGame();

    s32 getCoinNumMin();

private:
    u32                                 _10[(0x20 - 0x10) / sizeof(u32)];
    sead::SafeArray<PlayerObject*, 4>   mPlayerObject;
    sead::SafeArray<PlayerObject*, 4>   mPlayerObject2; // Idk why
    sead::BitFlag8                      _40;
    sead::BitFlag16                     mPlayerFlag;
    sead::FixedRingBuffer<Yoshi*, 4>    mYoshi;
    sead::FixedRingBuffer<Yoshi*, 4>    mYoshi2;
    u32                                 _84[(0xD0 - 0x84) / sizeof(u32)];
};
static_assert(sizeof(PlayerMgr) == 0xD0);
