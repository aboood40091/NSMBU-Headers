#pragma once

#include <state/FStateFactory.h>
#include <state/StateMgr.h>

template <typename T, typename Method>
class FStateMgr : public StateMgr<T, Method, FStateFactory>
{
public:
    FStateMgr(T& obj)
        : StateMgr<T, Method, FStateFactory>(obj)
    {
    }

    virtual ~FStateMgr()
    {
    }
};
