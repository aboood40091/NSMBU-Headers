#pragma once

#include <enemy/Enemy.h>

class DemoKamek : public Enemy {
    SEAD_RTTI_OVERRIDE(DemoKamek, Enemy);

public:
    DECLARE_STATE_ID(DemoKamek, DemoKamekState1);
    DECLARE_STATE_ID(DemoKamek, DemoKamekState2);
    DECLARE_STATE_ID(DemoKamek, DemoKamekState3);
    DECLARE_STATE_ID(DemoKamek, DemoKamekState4);
};
