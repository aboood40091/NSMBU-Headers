#pragma once

#include <state/FStateID.h>
#include <state/IState.h>

template <typename T>
class FState : public IState
{
public:
    FState(T& obj)
        : mpObject(&obj)
        , mStateID(nullptr)
    {
    }

    T& getObject() const { return *mpObject; }

    const StateID* getStateID() const override { return mStateID; }
    void setStateID(const FStateID<T>* p_state_id) { mStateID = p_state_id; }

    void execute() override
    {
        mStateID->executeState(getObject());
    }

protected:
    T*                  mpObject;
    const FStateID<T>*  mStateID;
};
