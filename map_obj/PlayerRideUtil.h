#pragma once

#include <basis/seadTypes.h>

class ActorUniqueID;
class BgCollision;

class PlayerRideUtil
{
public:
    static const u32 cIceActorIDArraySize = 16;

public:
    // Address: 0x02857AF8
    static u32 getRideFlag(ActorUniqueID* p_ice_actor_id_array, u32* p_ice_actor_id_num, const BgCollision& bg_collision);

    static u32 getRideFlag(const BgCollision& bg_collision)
    {
        ActorUniqueID ice_actor_id_array[cIceActorIDArraySize];
        u32 ice_actor_id_num = 0;
        return getRideFlag(ice_actor_id_array, &ice_actor_id_num, bg_collision);
    }
};
