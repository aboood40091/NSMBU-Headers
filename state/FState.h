#pragma once

#include <state/FStateID.h>
#include <state/IState.h>

template <typename T>
class FState : public IState
{
public:
    FState(T& obj)
        : mObject(obj)
        , mpStateID(nullptr)
    {
    }

    T& getObject() const { return mObject; }

    const StateID* getStateID() const override { return mpStateID; }
    void setStateID(const FStateID<T>* p_state_id) { mpStateID = p_state_id; }

    void initialize()
    {
        mpStateID->initializeState(mObject);
    }

    void execute() override
    {
        mpStateID->executeState(mObject);
    }

    void finalize()
    {
        mpStateID->finalizeState(mObject);
    }

protected:
    T&                  mObject;
    const FStateID<T>*  mpStateID;
};
