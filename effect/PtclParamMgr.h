#pragma once

#include <heap/seadHeap.h>

struct PtclParam;

class PtclParamMgr
{
public:
    // Address: 0x022AF57C
    PtclParamMgr();

    // Address: 0x022AF5BC
    void initialize(sead::Heap* heap);

    // Address: 0x022AF650
    const PtclParam* getParam(u32 index) const;

protected:
    const PtclParam*    mpParam;
    u32                 mParamNum;
};
static_assert(sizeof(PtclParamMgr) == 8);
