#pragma once

#include <actor/EatData.h>

class Enemy;

class EnemyEatData : public EatData // vtbl Address: 0x10072F9C
{
public:
    // Address: 0x0232F00C
    EnemyEatData(ActorUniqueID owner_id);

    // Address: 0x0232F124
    bool setEatTongue(Actor* p_yoshi) override;
    // Address: 0x0232F208
    void setEatTongueOff(Actor* p_yoshi) override;
    // Address: 0x0232F28C
    bool setEatSpitOut(Actor* p_yoshi) override;

protected:
    // Address: 0x0232F074
    Enemy* getOwner_() const;
};
static_assert(sizeof(EnemyEatData) == sizeof(EatData));
