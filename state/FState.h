#pragma once

#include <state/FStateID.h>
#include <state/IState.h>

template <typename T>
class FState : public IState
{
public:
    FState(T& obj)
        : mObject(&obj)
    {
    }

    T& getObject() const { return *mObject; }

    const StateID* getStateID() const override { return mStateID; }
    void setStateID(const FStateID<T>* state_id) { mStateID = state_id; }

    void execute() override
    {
        mStateID->executeState(getObject());
    }

protected:
    T*                  mObject;
    const FStateID<T>*  mStateID;
};
