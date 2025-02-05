#pragma once

#include <enemy/Enemy.h>

class BunDemoKameck : public Enemy {
    SEAD_RTTI_OVERRIDE(BunDemoKameck, Enemy);

public:
    // Address: 0x0101F1bAC
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState1);
    // Address: 0x0101F1BCC
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState2);
    // Address: 0x0101F1bEC
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState3);
    // Address: 0x0101F1C0C
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState4);
};
