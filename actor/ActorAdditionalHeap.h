#pragma once

#include <heap/seadDisposer.h>

class ActorAdditionalHeap : public sead::IDisposer
{
public:
    ActorAdditionalHeap()
        : sead::IDisposer()
        , mpHeap(nullptr)
    {
    }

    virtual ~ActorAdditionalHeap()
    {
        destroy();
    }

    // Address: 0x02002C70
    void create();
    // Address: 0x02002C54
    void destroy();

    sead::Heap* getHeap() const
    {
        return mpHeap;
    }

protected:
    sead::Heap* mpHeap;
};
static_assert(sizeof(ActorAdditionalHeap) == 0x14);
