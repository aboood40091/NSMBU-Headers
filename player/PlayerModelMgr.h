#pragma once

#include <player/PlayerModelBaseMgr.h>

class PlayerModel;

class PlayerModelMgr : public PlayerModelBaseMgr    // vtbl Address: 0x
{
public:
    // Address: 0x02922A84
    void setAnm(s32 id, f32 frame);

    // TODO: Virtual functions

private:
    PlayerModel*    mpModel;
};
static_assert(sizeof(PlayerModelMgr) == 0x10);
