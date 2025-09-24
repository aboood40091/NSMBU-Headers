#pragma once

#include <heap/seadHeap.h>

class ActorResLoader
{
public:
    // Address: 0x0200A738
    static void load(s32 prof_res_type, sead::Heap* heap);
    // Address: 0x0200A930
    static void unload(s32 prof_res_type);
};
