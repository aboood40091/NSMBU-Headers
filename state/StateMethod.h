#pragma once

#include <state/StateID.h>

class IState;
class IStateFactory;

class StateMethod
{
public:
    // Address: 0x1022D390
    static const StateID cNullStateID;

public:
    // Address: 0x029C4A08
    StateMethod(IStateFactory& factory, const StateID& state_id = cNullStateID);

    // Address: 0x029C4A80
    void executeStateMethod();

    // Address: 0x029C4AF0
    void changeStateMethod(const StateID& state_id);

    IState* getState() const { return mState; }
    StateID* getNewStateID() const { return mNewStateID; }
    // Address: 0x029C4B88
    StateID* getStateID() const;
    StateID* getOldStateID() const { return mOldStateID; }

protected:
    IStateFactory*  mFactory;
    StateID*        mNewStateID;
    IState*         mState;
    StateID*        mOldStateID;
};
static_assert(sizeof(StateMethod) == 0x10);

class StateMethodMulti : public StateMethod
{
public:
    StateMethodMulti(IStateFactory& factory, const StateID& state_id = cNullStateID)
        : StateMethod(factory, state_id)
    {
    }

    // Address: 0x029C4BC4
    void changeToSubStateMethod(const StateID& state_id);

protected:
    StateID*    mReturnStateID;
};
static_assert(sizeof(StateMethodMulti) == 0x14);
