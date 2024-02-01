#pragma once

#include <state/StateID.h>

template <typename T>
class FStateID : public StateID
{
public:
    typedef void (T::*FunctionPtr)();

public:
    FStateID(FunctionPtr initialize, FunctionPtr execute, FunctionPtr finalize)
        : mInitialize(initialize)
        , mExecute(execute)
        , mFinalize(finalize)
    {
    }

    virtual ~FStateID()
    {
    }

    void initializeState(T& obj) const
    {
        (obj.*mInitialize)();
    }

    void executeState(T& obj) const
    {
        (obj.*mExecute)();
    }

    void finalizeState(T& obj) const
    {
        (obj.*mFinalize)();
    }

protected:
    FunctionPtr mInitialize;
    FunctionPtr mExecute;
    FunctionPtr mFinalize;
};

#define DECLARE_STATE_ID(CLASS, NAME)       \
    static FStateID<CLASS> StateID_##NAME;  \
    void initializeState_##NAME();          \
    void executeState_##NAME();             \
    void finalizeState_##NAME();

#define CREATE_STATE_ID(CLASS, NAME)        \
    FStateID<CLASS> CLASS::StateID_##NAME   \
        (&CLASS::initializeState_##NAME,    \
         &CLASS::executeState_##NAME,       \
         &CLASS::finalizeState_##NAME);
