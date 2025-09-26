#pragma once

#include <actor/ActorCollision.h>

class PentaroIce : public ActorCollision
{
public:
    // Address: 0x02414760
    void breakReq(const Actor* p_actor);
};
