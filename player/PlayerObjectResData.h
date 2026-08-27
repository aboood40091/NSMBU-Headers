#pragma once

#include <player/PlayerModel.h>

struct PlayerObjectResHIO
{
    sead::SafeString    model_res_key;
    sead::SafeString    anm_res_key;
    sead::SafeString    body_mdl_name[PlayerModel::cBodyType_Num];
    sead::SafeString    head_mdl_name[PlayerModel::cBodyType_Num];
    f32                 head_top_offs[PlayerModel::cBodyType_Num];
};
static_assert(sizeof(PlayerObjectResHIO) == 0x74);
