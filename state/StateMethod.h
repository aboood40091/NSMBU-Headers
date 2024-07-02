#pragma once

#include <state/IState.h>
#include <state/IStateFactory.h>
#include <state/StateID.h>

class StateMethod
{
public:
    // Address: 0x029C4A08
    StateMethod(IStateFactory& factory, const StateID& state_id);

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
    void initializeStateLocalMethod_();
    void executeStateLocalMethod_();
    void finalizeStateLocalMethod_();
    void changeStateLocalMethod_();

protected:
    IStateFactory&  mFactory;
    const StateID*  mpNewStateID;
    IState*         mpState;
    const StateID*  mpOldStateID;
};
static_assert(sizeof(StateMethod) == 0x10);

inline void StateMethod::initializeStateLocalMethod_()
{
    if (mpNewStateID != nullptr)
    {
        mpState = mFactory.buildWithInitialize(*mpNewStateID);
        mpNewStateID = nullptr;
    }
}

inline void StateMethod::executeStateLocalMethod_()
{
    initializeStateLocalMethod_();

    if (mpState != nullptr)
        mpState->execute();
}

inline void StateMethod::finalizeStateLocalMethod_()
{
    if (mpState != nullptr && mpNewStateID != nullptr)
    {
        mpOldStateID = mpState->getStateID();
        mFactory.disposeWithFinalize(mpState);
    }
}

inline void StateMethod::changeStateLocalMethod_()
{
    finalizeStateLocalMethod_();
    initializeStateLocalMethod_();
}
