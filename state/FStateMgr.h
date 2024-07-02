#pragma once

#include <state/FStateFactory.h>
#include <state/StateMgr.h>

template <typename T, typename Method>
class FStateMgr : public StateMgr<T, Method, FStateFactory>
{
public:
    FStateMgr(T& obj, const StateID& state_id = StateID::cNull)
        : StateMgr<T, Method, FStateFactory>(obj, state_id)
    {
    }

    virtual ~FStateMgr()
    {
    }
};
