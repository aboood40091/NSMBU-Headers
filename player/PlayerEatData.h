#pragma once

#include <actor/EatData.h>

class PlayerEatData : public EatData    // vtbl Address: 0x10169524
{
public:
    // Address: 0x02911918
    PlayerEatData(ActorUniqueID owner_id);

    // Address: 0x02911980
    void eatMove(Actor* p_yoshi) override;
    // Address: 0x02911A8C
    bool setEatTongue(Actor* p_yoshi) override;
    // Address: 0x02911B9C
    void setEatTongueOff(Actor* p_yoshi) override;
    // Address: 0x02911CA8
    void setEatMouth(Actor* p_yoshi) override;
    // Address: 0x02911DB4
    bool setEatSpitOut(Actor* p_yoshi) override;
};
static_assert(sizeof(PlayerEatData) == sizeof(EatData));
