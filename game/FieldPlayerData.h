#pragma once

#include <player/PlayerEnum.h>
#include <utility/Bitfield.h>

struct FieldPlayerData
{
    bool            is_active;
    s32             life_cnt;
    PlayerMode      player_mode;
    PlayerCharacter character;
    PlayerCharacter character_color;
    s32             _14;
    s32             mii_slot;
    bool            mii_cap_visible;
    bool            is_spawned;
    bool            has_star;
    u8              _1f;
    Bitfield<64>    fukidashi_flag; // I believe only 48 bits are used
    u32             _28[(0x48 - 0x28) / sizeof(u32)];
};
static_assert(sizeof(FieldPlayerData) == 0x48);
