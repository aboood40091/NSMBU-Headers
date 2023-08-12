#pragma once

#include <actor/GenericEatData.h>

class Enemy;

class EnemyEatData : public GenericEatData
{
public:
    EnemyEatData(ActorUniqueID owner_id);

    bool handleEaten() override;
    void vf3C() override;
    u32 vf4C() override;

protected:
    Enemy* getOwner_() const;
};
static_assert(sizeof(EnemyEatData) == sizeof(GenericEatData));
