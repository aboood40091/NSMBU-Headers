#pragma once

#include <basis/seadTypes.h>

template <typename T, typename Method, template <typename FactoryT> class Factory>
class StateMgr
{
public:
    StateMgr(T& obj, const StateID& state_id)
        : mFactory(obj)
        , mMethod(mFactory, state_id)
    {
    }

    virtual ~StateMgr()
    {
    }

    Method& getStateMethod()
    {
        return mMethod;
    }

    const Method& getStateMethod() const
    {
        return mMethod;
    }

    void executeState()
    {
        mMethod.executeStateMethod();
    }

    void changeState(const StateID& state_id)
    {
        mMethod.changeStateMethod(state_id);
    }

    IState* getState() const
    {
        return mMethod.getState();
    }

    const StateID* getNewStateID() const
    {
        return mMethod.getNewStateID();
    }

    const StateID* getStateID() const
    {
        return mMethod.getStateID();
    }

    const StateID* getOldStateID() const
    {
        return mMethod.getOldStateID();
    }

protected:
    Factory<T>  mFactory;
    Method      mMethod;
};
