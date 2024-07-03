#include <state/StateIDHolder.h>
#include <state/StateMethod.h>

class StateStateMethod : public StateMethod
{
public:
    StateStateMethod(IStateFactory& factory, const StateID& state_id)
        : StateMethod(factory, state_id)
    {
    }

    // Address: 0x029C4BC4
    void changeToSubStateMethod(const StateID& state_id);

    bool isSubStateMethod() const
    {
        return mMain.isSet();
    }

    void returnStateMethod()
    {
        mpOldStateID = mpState->getStateID();
        mFactory.disposeWithFinalize(mpState);
        const StateID& main_state_id = *(mMain.get());
        mMain.reset();
        mpState = mFactory.build(main_state_id);
    }

    void replaceStateMethod(const StateID& state_id)
    {
        mFactory.disposeWithFinalize(mpState);
        mpState = mFactory.buildWithInitialize(state_id);
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
static_assert(sizeof(StateStateMethod) == 0x14);
