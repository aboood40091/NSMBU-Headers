#pragma once

#include <basis/seadTypes.h>

class StateID
{
public:
    StateID()
    {
        // s_number_memo initialization guard variable  Address: 0x101E9E9C
        // s_number_memo                                Address: 0x101E9F04
        static s32 s_number_memo = 0;
        mNumber = ++s_number_memo;
    }

    StateID(s32 number)
        : mNumber(number)
    {
    }

    virtual ~StateID()
    {
    }

    virtual s32 number() const
    {
        return mNumber;
    }

    bool isNull() const
    {
        return mNumber == -1;
    }

    bool isEqual(const StateID& rhs) const
    {
        return number() == rhs.number();
    }

    bool operator==(const StateID& rhs) const
    {
        return isEqual(rhs);
    }

    bool operator!=(const StateID& rhs) const
    {
        return !isEqual(rhs);
    }

protected:
    s32 mNumber;
};
static_assert(sizeof(StateID) == 8);

class StateIDHolder
{
public:
    StateIDHolder()
    {
        reset();
    }

    void set(const StateID& state_id)
    {
        mpStateID = &state_id;
    }

    void reset()
    {
        mpStateID = nullptr;
    }

    bool isSet() const
    {
        return mpStateID != nullptr;
    }

    const StateID* get() const
    {
        return mpStateID;
    }

protected:
    const StateID*  mpStateID;
};
static_assert(sizeof(StateIDHolder) == 4);
