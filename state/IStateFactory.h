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

    virtual IState* buildWithInitialize(const StateID& state_id) = 0;
    virtual void disposeWithFinalize(IState*& p_state) = 0;
    virtual IState* build(const StateID& state_id) = 0;
    virtual void dispose(IState*& p_state) = 0;
    virtual void initializeState(IState* p_state) = 0;
};
static_assert(sizeof(IStateFactory) == 4);

