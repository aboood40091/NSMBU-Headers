#pragma once

#include <prim/seadBitFlag.h>

class PlyOrchestra
{
public:
    // Address: 0x0295BD1C
    PlyOrchestra();

    // Address: 0x0295BDC4
    void init(s32 player_no);

    // Address: 0x0295BDDC
    void update();

private:
    u32             _0;
    s32             mPlayerNo;
    sead::BitFlag32 mPadHold;
    sead::BitFlag32 mPadTrig;
    sead::BitFlag32 mPadRelease;
};
static_assert(sizeof(PlyOrchestra) == 0x14);
