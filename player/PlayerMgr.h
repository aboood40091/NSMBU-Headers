#pragma once

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>

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
        return mPlayerFlag & (1 << player_no);
    }

    s32 getNumInGame();

private:
    u32                                 _10;
    u32                                 _14;
    u32                                 _18;
    u32                                 _1c;
    sead::SafeArray<PlayerObject*, 4>   mPlayerObject;
    sead::SafeArray<PlayerObject*, 4>   mPlayerObject2; // Idk why
    u16                                 _40;
    u16                                 mPlayerFlag;
    Yoshi**                             mppYoshi;
    u32                                 mYoshiRelated1;
    u32                                 mYoshiRelated2;
    s32                                 mActiveYoshiNumMaybe;
    u32                                 _54[(0xD0 - 0x54) / sizeof(u32)];
};
static_assert(sizeof(PlayerMgr) == 0xD0);
