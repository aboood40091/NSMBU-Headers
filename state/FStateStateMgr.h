#pragma once

#include <state/FStateFactory.h>
#include <state/StateStateMgr.h>

template <typename T>
class FStateStateMgr : public StateStateMgr<T, FStateFactory>
{
public:
    FStateStateMgr(T& obj, const StateID& state_id = StateID::cNull)
        : StateStateMgr<T, FStateFactory>(obj, state_id)
    {
    }

    virtual ~FStateStateMgr()
    {
    }
};
