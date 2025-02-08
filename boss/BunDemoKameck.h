#pragma once

#include <enemy/Enemy.h>

class BunDemoKameck : public Enemy  // vtbl Address: 0x1000D274                                                             
{         
    SEAD_RTTI_OVERRIDE(BunDemoKameck, Enemy);

public:
    // StateID_BunDemoKameckState1          Address: 0x101F1BAC
    // initializeState_BunDemoKameckState1  Address: 0x02065A70
    // executeState_BunDemoKameckState1     Address: 0x02065A74
    // finalizeState_BunDemoKameckState1    Address: 0x02065A78
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState1);
    // StateID_BunDemoKameckState2          Address: 0x0101F1BCC
    // initializeState_BunDemoKameckState2  Address: 0x02064D60
    // executeState_BunDemoKameckState2     Address: 0x02064E30
    // finalizeState_BunDemoKameckState2    Address: 0x02064CF8
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState2);
    // StateID_BunDemoKameckState3          Address: 0x101F1BEC
    // initializeState_BunDemoKameckState3  Address: 0x02064FCC
    // executeState_BunDemoKameckState3     Address: 0x02065124
    // finalizeState_BunDemoKameckState3    Address: 0x02065A7C
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState3);
    // StateID_BunDemoKameckState4          Address: 0x101F1C0C
    // initializeState_BunDemoKameckState4  Address: 0x02065A80
    // executeState_BunDemoKameckState4     Address: 0x02065A84
    // finalizeState_BunDemoKameckState4    Address: 0x02065A88
    DECLARE_STATE_ID(BunDemoKameck, BunDemoKameckState4);
};
