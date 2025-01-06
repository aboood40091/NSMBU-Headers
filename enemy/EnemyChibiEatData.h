#pragma once

#include <actor/ChibiEatData.h>

class Enemy;

class EnemyChibiEatData : public ChibiEatData   // vtbl Address: 0x10072738
{
public:
    // Address: 0x0232ADAC
    EnemyChibiEatData(ActorUniqueID owner_id);

    // Address: 0x0232AEAC
    u32 vf0C() override;
    // Address: 0x0232AFB0
    void* vf14(void*) override;
    // Address: 0x0232B01C
    void setEatSpitOut(Actor* p_chibi_yoshi) override;

protected:
    // Address: 0x0232AE14
    Enemy* getOwner_() const;
};
static_assert(sizeof(EnemyChibiEatData) == sizeof(ChibiEatData));
