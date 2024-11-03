#pragma once

#include <basis/seadTypes.h>

class StateID;

class StateIDHolder
{
public:
    StateIDHolder()
    {
        reset();
    }

    void set(const StateID* p_state_id)
    {
        mpStateID = p_state_id;
    }

    void reset()
    {
        mpStateID = nullptr;
    }

    bool isSet() const
    {
        return mpStateID != nullptr;
    }

    const StateID* get() const
    {
        return mpStateID;
    }

protected:
    const StateID*  mpStateID;
};
static_assert(sizeof(StateIDHolder) == 4);
