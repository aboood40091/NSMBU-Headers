#pragma once

#include <player/PlayerModelBase.h>

#include <prim/seadSafeString.h>

struct PlayerAnmData
{
    sead::SafeString            normal;
    sead::SafeString            ride;
    sead::SafeString            yoshi_body;
    sead::SafeString            penguin;
    FrameCtrl::PlayMode         play_mode;
    f32                         rate;
    f32                         blend_duration;
    PlayerModelBase::TexAnmType tex_anm_type;
    u32                         flag;   // See PlayerModelBase::AnmFlagBit
};
static_assert(sizeof(PlayerAnmData) == 0x34);
