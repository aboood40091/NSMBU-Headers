#pragma once

#include <state/StateMethod.h>

#define STATE_MGR_BASE_BODY(CLASS, METHOD)          \
    public:                                         \
        CLASS(T& obj, const StateID& state_id)      \
            : mFactory(obj)                         \
            , mMethod(mFactory, state_id)           \
        {                                           \
        }                                           \
                                                    \
        virtual ~CLASS()                            \
        {                                           \
        }                                           \
                                                    \
        void executeState()                         \
        {                                           \
            mMethod.executeStateMethod();           \
        }                                           \
                                                    \
        void changeState(const StateID& state_id)   \
        {                                           \
            mMethod.changeStateMethod(state_id);    \
        }                                           \
                                                    \
        IState* getState() const                    \
        {                                           \
            return mMethod.getState();              \
        }                                           \
                                                    \
        const StateID* getNewStateID() const        \
        {                                           \
            return mMethod.getNewStateID();         \
        }                                           \
                                                    \
        const StateID* getStateID() const           \
        {                                           \
            return mMethod.getStateID();            \
        }                                           \
                                                    \
        const StateID* getOldStateID() const        \
        {                                           \
            return mMethod.getOldStateID();         \
        }                                           \
                                                    \
    protected:                                      \
        Factory<T>  mFactory;                       \
        METHOD      mMethod;

template <typename T, template <typename FactoryT> class Factory>
class StateMgr
{
    STATE_MGR_BASE_BODY(StateMgr, StateMethod)
};
