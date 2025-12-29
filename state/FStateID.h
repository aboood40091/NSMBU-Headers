#pragma once

#include <state/StateID.h>

template <typename T>
class FStateID : public StateID
{
public:
    typedef void (T::*FunctionPtr)();

public:
    FStateID(FunctionPtr p_initialize, FunctionPtr p_execute, FunctionPtr p_finalize)
        : mpInitialize(p_initialize)
        , mpExecute(p_execute)
        , mpFinalize(p_finalize)
    {
    }

    virtual ~FStateID()
    {
    }

    void initializeState(T& obj) const
    {
        (obj.*mpInitialize)();
    }

    void executeState(T& obj) const
    {
        (obj.*mpExecute)();
    }

    void finalizeState(T& obj) const
    {
        (obj.*mpFinalize)();
    }

protected:
    FunctionPtr mpInitialize;
    FunctionPtr mpExecute;
    FunctionPtr mpFinalize;
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

// The following is only ever used by PlayerObject demo states

#define DECLARE_STATE_ID_VIRTUAL_FUNC_OVERRIDE(CLASS, NAME) \
    static FStateID<CLASS> StateID_##NAME;                  \
    void initializeState_##NAME() override;                 \
    void executeState_##NAME() override;                    \
    void finalizeState_##NAME() override;
