#pragma once

#include <basis/seadTypes.h>

template <typename T, typename Method, template <typename FactoryT> class Factory>
class StateMgr
{
public:
    StateMgr(T& obj)
        : mFactory(obj)
        , mMethod(mFactory)
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

protected:
    Factory<T>  mFactory;
    Method      mMethod;
};
