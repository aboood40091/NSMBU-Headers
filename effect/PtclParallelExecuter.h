#pragma once

#include <container/seadPtrArray.h>
#include <heap/seadDisposer.h>
#include <ptcl/seadPtclSystem.h>
#include <thread/seadAtomic.h>
#include <thread/seadMessageQueue.h>

class ParallelExecuter;
class PtclMgr;

class PtclParallelExecuter : public sead::IDisposer // vtable Address: 0x10058B74
{
public:
    static const s32 cExecuterNum = 2;
    static const s32 cEmitterMaxNum = 256;

protected:
    enum Step
    {
        cStep_Ptcl = 1,
        cStep_ChildPtcl
    };

    // Address: 0x022AECD0
    static s32 comparePtcl_(const nw::eft::EmitterInstance* a, const nw::eft::EmitterInstance* b);
    // Address: 0x022AECE0
    static s32 compareChildPtcl_(const nw::eft::EmitterInstance* a, const nw::eft::EmitterInstance* b);

    // Address: 0x022AECF0
    void run_(Step step);

    // Address: 0x022AEE94
    void runCallback_(sead::Thread*, sead::MessageQueue::Element step);

public:
    // Address: 0x022AF060
    PtclParallelExecuter(sead::Heap* heap, PtclMgr* p_mgr, sead::ptcl::PtclSystem* p_system);

    // Address: 0x022AF420
    void execute();

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
