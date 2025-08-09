#pragma once

#include <map_obj/ChibiYoshiAwaData.h>

class EnemyChibiYoshiAwaData : public ChibiYoshiAwaData // vtbl Address: 0x1007262C
{
public:
    // Address: 0x0232AB90
    EnemyChibiYoshiAwaData(ActorUniqueID owner_id);

    // Address: 0x0232ABFC
    void vf0C(Actor*) override;
    // Address: 0x0232AC3C
    void vf14(Actor*) override;
    // Address: 0x0232AC7C
    void vf1C(Actor*) override;
    // Address: 0x0232ACBC
    void vf24(Actor*) override;
};
static_assert(sizeof(EnemyChibiYoshiAwaData) == sizeof(ChibiYoshiAwaData));
