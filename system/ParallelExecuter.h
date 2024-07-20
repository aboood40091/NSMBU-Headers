#pragma once

#include <thread/seadDelegateThread.h>
#include <thread/seadEvent.h>

class ParallelExecuterID // IG?
{
public:
    ParallelExecuterID(const sead::SafeString& name)
        : mName("") // Whoops! They don't actually use the "name" parameter
    {
    }

protected:
    sead::SafeString    mName;
};
static_assert(sizeof(ParallelExecuterID) == 8);

struct ParallelExecuter
{
    sead::DelegateThread*   p_thread;
    sead::Event*            p_event;
    ParallelExecuterID*     p_id;
};
static_assert(sizeof(ParallelExecuter) == 0xC);
