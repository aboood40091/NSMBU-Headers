#pragma once

#include <actor/ActorState.h>

class Ice : public ActorState
{
public:
    // Address: 0x02372800
    void breakReq(s32 direction, s32 player_no);

    void breakReq(const Actor& actor)
    {
        breakReq(mPos.x < actor.getPos().x ? DIRECTION_LEFT : DIRECTION_RIGHT, actor.getPlayerNo());
    }
};
