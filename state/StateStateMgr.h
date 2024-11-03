#pragma once

#include <state/StateStateMethod.h>
#include <state/StateMgr.h>

template <typename T, template <typename FactoryT> class Factory>
class StateStateMgr
{
    STATE_MGR_BASE_BODY(StateStateMgr, StateStateMethod)

public:
    void changeToSubState(const StateID& state_id)
    {
        mMethod.changeToSubStateMethod(state_id);
    }

    bool isSubState() const
    {
        return mMethod.isSubStateMethod();
    }

    void returnState()
    {
        mMethod.returnStateMethod();
    }

    void replaceState(const StateID& state_id)
    {
        mMethod.replaceStateMethod(state_id);
    }

    const StateID* getMainStateID() const
    {
        return mMethod.getMainStateID();
    }
};
