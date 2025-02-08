#pragma once

#include <enemy/Enemy.h>

class BunDemoKamek : public Enemy  // vtbl Address: 0x1000D274                                                             
{         
    SEAD_RTTI_OVERRIDE(BunDemoKamek, Enemy);

public:
    // BunDemoKamekState1                  Address: 0x101F1BAC
    // initializeState_BunDemoKamekState1  Address: 0x02065A70
    // executeState_BunDemoKamekState1     Address: 0x02065A74
    // finalizeState_BunDemoKamekState1    Address: 0x02065A78
    DECLARE_STATE_ID(BunDemoKamek, BunDemoKamekState1);
    // BunDemoKamekState2                  Address: 0x0101F1BCC
    // initializeState_BunDemoKamekState2  Address: 0x02064D60
    // executeState_BunDemoKamekState2     Address: 0x02064E30
    // finalizeState_BunDemoKamekState2    Address: 0x02064CF8
    DECLARE_STATE_ID(BunDemoKamek, BunDemoKamekState2);
    // BunDemoKamekState3                  Address: 0x101F1BEC
    // initializeState_BunDemoKamekState3  Address: 0x02064FCC
    // executeState_BunDemoKamekState3     Address: 0x02065124
    // finalizeState_BunDemoKamekState3    Address: 0x02065A7C
    DECLARE_STATE_ID(BunDemoKamek, BunDemoKamekState3);
    // BunDemoKamekState4                  Address: 0x101F1C0C
    // initializeState_BunDemoKamekState4  Address: 0x02065A80
    // executeState_BunDemoKamekState4     Address: 0x02065A84
    // finalizeState_BunDemoKamekState4    Address: 0x02065A88
    DECLARE_STATE_ID(BunDemoKamek, BunDemoKamekState4);
};
