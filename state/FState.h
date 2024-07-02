#pragma once

#include <state/FStateID.h>
#include <state/IState.h>

template <typename T>
class FState : public IState
{
public:
    FState(T& obj)
        : mpObject(&obj)
        , mpStateID(nullptr)
    {
    }

    T& getObject() const { return *mpObject; }

    const StateID* getStateID() const override { return mpStateID; }
    void setStateID(const FStateID<T>* p_state_id) { mpStateID = p_state_id; }

    void initialize()
    {
        mpStateID->initializeState(getObject());
    }

    void execute() override
    {
        mpStateID->executeState(getObject());
    }

    void finalize()
    {
        mpStateID->finalizeState(getObject());
    }

protected:
    T*                  mpObject;
    const FStateID<T>*  mpStateID;
};
