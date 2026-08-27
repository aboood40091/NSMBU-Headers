#pragma once

#include <prim/seadBitFlag.h>

class PlayerInstrument
{
public:
    // Address: 0x0295BD1C
    PlayerInstrument();

    // Address: 0x0295BDC4
    void init(s32 player_no);

    // Address: 0x0295BDDC
    void update();

private:
    u32             mDirection; // 0 = U, 1 = D, 2 = L, 3 = R
    s32             mPlayerNo;
    sead::BitFlag32 mPadHold;
    sead::BitFlag32 mPadTrig;
    sead::BitFlag32 mPadRelease;
};
static_assert(sizeof(PlayerInstrument) == 0x14);
