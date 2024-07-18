#pragma once

#include <heap/seadDisposer.h>
#include <ptcl/seadPtclSystem.h>
#include <thread/seadAtomic.h>

class ParallelExecuter;
class PtclMgr;

class PtclParallelExecuter : public sead::IDisposer // vtable Address: 0x10058B74
{
protected:
    static const s32 cExecuterNum = 2;
    static const s32 cEmitterMaxNum = 256;

public:
    // Address: 0x022AF060
    PtclParallelExecuter(sead::Heap* heap, PtclMgr* p_mgr, sead::ptcl::PtclSystem* p_system);

protected:
    sead::ptcl::PtclSystem* mpPtclSystem;
    sead::FixedPtrArray<
        ParallelExecuter,
        cExecuterNum
    >                       mExecuter;
    sead::FixedPtrArray<
        nw::eft::EmitterInstance,
        cEmitterMaxNum
    >                       mEmitter;
    sead::AtomicU32         mEmitterCurrentIdx;
};
static_assert(sizeof(PtclParallelExecuter) == 0x438);
