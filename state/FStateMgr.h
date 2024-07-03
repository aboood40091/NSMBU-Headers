#pragma once

#include <state/FStateFactory.h>
#include <state/StateMgr.h>

template <typename T>
class FStateMgr : public StateMgr<T, FStateFactory>
{
public:
    FStateMgr(T& obj, const StateID& state_id = StateID::cNull)
        : StateMgr<T, FStateFactory>(obj, state_id)
    {
    }

    virtual ~FStateMgr()
    {
    }
};
