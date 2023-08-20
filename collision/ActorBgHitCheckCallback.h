#pragma once

#include <collision/BgHitCheckCallback.h>

class ActorBgCollisionCheck;

class ActorBgHitCheckCallback : public BgHitCheckCallback   // vtbl Address: 0x10041A30
{
public:
    ActorBgHitCheckCallback(ActorBgCollisionCheck* p_bc)
        : mpBgCollisionCheck(p_bc)
    {
    }

    // Address: 0x02197C14
    bool vf0C() override /* { return true; } */ ;
    // Address: 0x02197B4C
    bool hit(const BgCollisionCheckResult& hit_res) override;

protected:
    ActorBgCollisionCheck*  mpBgCollisionCheck;
};
static_assert(sizeof(ActorBgHitCheckCallback) == 8);
