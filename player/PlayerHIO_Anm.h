#pragma once

#include <player/PlayerAnmData.h>
#include <player/PlayerEnum.h>

class PlayerMgr;

class PlayerHIO_Anm
{
public:
    // Address: 0x101E2290
    static const PlayerAnmData cData[PlayerAnmID::cNum];

public:
    // Address: 0x0291211C
    PlayerHIO_Anm(PlayerMgr& mgr);

    // Address: 0x029121C8
    static f32 getCarryMiniPlayerAddYOffs(PlayerCharacter character, PlayerMode mode);
    // Address: 0x029121D8
    static f32 getCarrySmallPlayerAddYOffs(PlayerCharacter character, PlayerMode mode);
};
static_assert(sizeof(PlayerHIO_Anm) == 1);
