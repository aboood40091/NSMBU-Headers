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

    IState* getState() const { return mpState; }
    const StateID* getNewStateID() const { return mpNewStateID; }
    // Address: 0x029C4B88
    const StateID* getStateID() const;
    const StateID* getOldStateID() const { return mpOldStateID; }

protected:
    IStateFactory*  mpFactory;
    const StateID*  mpNewStateID;
    IState*         mpState;
    const StateID*  mpOldStateID;
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

    bool isSubStateMethod() const
    {
        return mMain.isSet();
    }

    void returnToMainStateMethod()
    {
        mpOldStateID = mpState->getStateID();
        mpFactory->dispose(mpState);
        const StateID& main_state_id = *(mMain.get());
        mMain.reset();
        mpState = mpFactory->buildNoInitializeState(main_state_id);
    }

    void replaceStateMethod(const StateID& state_id)
    {
        mpFactory->dispose(mpState);
        mpState = mpFactory->build(state_id);
    }

    const StateID* getMainStateID() const
    {
        const StateID* p_state_id = mMain.get();
        if (p_state_id == nullptr)
            p_state_id = getStateID();
        return p_state_id;
    }

protected:
    StateIDHolder   mMain;
};
static_assert(sizeof(StateMethodMulti) == 0x14);
