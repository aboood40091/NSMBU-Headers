#pragma once

#include <basis/seadTypes.h>

class StateID;

class IState
{
public:
    IState()
    {
    }

    virtual ~IState()
    {
    }

    virtual const StateID* getStateID() const = 0;
    virtual void execute() = 0;
};
static_assert(sizeof(IState) == 4);
