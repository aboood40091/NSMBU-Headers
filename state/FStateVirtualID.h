#pragma once

#include <state/FStateID.h>
#include <state/StateMethod.h>

template <typename T>
class FStateVirtualID : public FStateID<T>
{
public:
    typedef typename FStateID<T>::FunctionPtr FunctionPtr;

public:
    FStateVirtualID(FunctionPtr initialize, FunctionPtr execute, FunctionPtr finalize, const StateID& super_id = StateMethod::cNullStateID)
        : FStateID<T>(initialize, execute, finalize)
        , mSuperID(&super_id)
    {
    }

    virtual ~FStateVirtualID()
    {
    }

    s32 number() const override
    {
        if (!mSuperID->isNull())
            return mSuperID->number();

        return mNumber;
    }

    const StateID* superID() const
    {
        return mSuperID;
    }

protected:
    const StateID* mSuperID;
};

#define DECLARE_STATE_VIRTUAL_ID_BASE(CLASS, NAME)          \
    static FStateVirtualID<CLASS> StateID_##NAME;           \
    virtual void initializeState_##NAME();                  \
    virtual void executeState_##NAME();                     \
    virtual void finalizeState_##NAME();

#define DECLARE_STATE_VIRTUAL_ID_OVERRIDE(CLASS, NAME)      \
    static FStateVirtualID<CLASS> StateID_##NAME;           \
    void initializeState_##NAME() override;                 \
    void executeState_##NAME() override;                    \
    void finalizeState_##NAME() override;

#define CREATE_STATE_VIRTUAL_ID_BASE(CLASS, NAME)           \
    FStateVirtualID<CLASS> CLASS::StateID_##NAME            \
        (&CLASS::initializeState_##NAME,                    \
         &CLASS::executeState_##NAME,                       \
         &CLASS::finalizeState_##NAME);

#define CREATE_STATE_VIRTUAL_ID_OVERRIDE(CLASS, BASE, NAME) \
    FStateVirtualID<CLASS> CLASS::StateID_##NAME            \
        (&CLASS::initializeState_##NAME,                    \
         &CLASS::executeState_##NAME,                       \
         &CLASS::finalizeState_##NAME,                      \
         BASE::StateID_##NAME);
