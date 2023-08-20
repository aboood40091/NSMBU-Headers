#pragma once

#include <state/FState.h>
#include <state/IStateFactory.h>

template <typename T>
class FStateFactory : public IStateFactory
{
public:
    FStateFactory(T& obj)
        : mState(obj)
    {
    }

    virtual ~FStateFactory()
    {
    }

    IState* build(const StateID& state_id) override
    {
        const FStateID<T>& sid = static_cast<const FStateID<T>&>(state_id);
        mState.setStateID(&sid);
        sid.initializeState(mState.getObject());
        return &mState;
    }

    void dispose(IState*& p_state) override
    {
        const FStateID<T>& sid = static_cast<const FStateID<T>&>(*mState.getStateID());
        sid.finalizeState(mState.getObject());
        mState.setStateID(nullptr);
        p_state = nullptr;
    }

    IState* buildNoInitializeState(const StateID& state_id) override
    {
        const FStateID<T>& sid = static_cast<const FStateID<T>&>(state_id);
        mState.setStateID(&sid);
        return &mState;
    }

    void disposeNoFinalizeState(IState*& p_state) override
    {
        mState.setStateID(nullptr);
        p_state = nullptr;
    }

    void initializeState(IState* p_state) override
    {
        const FStateID<T>& sid = static_cast<const FStateID<T>&>(*(static_cast<FState<T>*>(p_state)->getStateID()));
        sid.initializeState(mState.getObject());
    }

protected:
    FState<T>   mState;
};
