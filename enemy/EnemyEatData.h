#pragma once

#include <actor/GenericEatData.h>

class Enemy;

class EnemyEatData : public GenericEatData  // vtbl Address: 0x10072F9C
{
public:
    // Address: 0x0232F00C
    EnemyEatData(ActorUniqueID owner_id);

    // Address: 0x0232F124
    bool handleEaten() override;
    // Address: 0x0232F208
    void vf3C() override;
    // Address: 0x0232F28C
    u32 vf4C() override;

protected:
    // Address: 0x0232F074
    Enemy* getOwner_() const;
};
static_assert(sizeof(EnemyEatData) == sizeof(GenericEatData));
