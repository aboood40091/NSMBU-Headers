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

    IState* buildWithInitialize(const StateID& state_id) override
    {
        mState.setStateID(static_cast<const FStateID<T>*>(&state_id));
        mState.initialize();
        return &mState;
    }

    void disposeWithFinalize(IState*& p_state) override
    {
        mState.finalize();
        mState.setStateID(nullptr);
        p_state = nullptr;
    }

    IState* build(const StateID& state_id) override
    {
        mState.setStateID(static_cast<const FStateID<T>*>(&state_id));
        return &mState;
    }

    void dispose(IState*& p_state) override
    {
        mState.setStateID(nullptr);
        p_state = nullptr;
    }

    void initializeState(IState* p_state) override
    {
        static_cast<FState<T>*>(p_state)->initialize();
    }

protected:
    FState<T>   mState;
};
