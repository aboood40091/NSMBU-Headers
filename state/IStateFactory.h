#pragma once

#include <basis/seadTypes.h>

class IState;
class StateID;

class IStateFactory
{
public:
    IStateFactory()
    {
    }

    virtual ~IStateFactory()
    {
    }

    virtual IState* build(const StateID& state_id) = 0;
    virtual void dispose(IState*& state) = 0;
    virtual IState* buildNoInitializeState(const StateID& state_id) = 0;
    virtual void disposeNoFinalizeState(IState*& state) = 0;
    virtual void initializeState(IState* state) = 0;
};
static_assert(sizeof(IStateFactory) == 4);

