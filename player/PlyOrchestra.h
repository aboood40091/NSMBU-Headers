#pragma once

#include <prim/seadBitFlag.h>

class PlyOrchestra
{
public:
    // Address: 0x0295BD1C
    PlyOrchestra();

private:
    u32             _0;
    s32             mPlayerNo;
    sead::BitFlag32 mPadHold;
    sead::BitFlag32 mPadTrig;
    sead::BitFlag32 mPadRelease;
};
static_assert(sizeof(PlyOrchestra) == 0x14);
