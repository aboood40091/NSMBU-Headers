#pragma once

#include <enemy/Enemy.h>

class BunDemoKameck : public Enemy {
    SEAD_RTTI_OVERRIDE(BunDemoKameck, Enemy);

public:
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState1);
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState2);
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState3);
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState4);
};
