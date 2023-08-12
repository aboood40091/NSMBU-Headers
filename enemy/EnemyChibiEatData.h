#pragma once

#include <actor/GenericChibiEatData.h>

class Enemy;

class EnemyChibiEatData : public GenericChibiEatData
{
public:
    EnemyChibiEatData(ActorUniqueID owner_id);

    u32 vf0C() override;
    void* vf14(void*) override;
    void vf2C() override;

protected:
    Enemy* getOwner_() const;
};
static_assert(sizeof(EnemyChibiEatData) == sizeof(GenericChibiEatData));
