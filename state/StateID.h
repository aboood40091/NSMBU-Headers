#pragma once

#include <basis/seadTypes.h>

class StateID
{
public:
    // Address: 0x1022D390
    static const StateID cNull;
    static const s32 cNullNumber = -1;

private:
    class NumberMemo
    {
    public:
        NumberMemo()
            : mNumber(0)
        {
        }

        s32 get()
        {
            mNumber++;
            return mNumber;
        }

    private:
        s32 mNumber;
    };
    static_assert(sizeof(NumberMemo) == 4);

public:
    StateID()
    {
        // s_number_memo initialization guard variable  Address: 0x101E9E9C
        // s_number_memo                                Address: 0x101E9F04
        static NumberMemo s_number_memo;
        mNumber = s_number_memo.get();
    }

    explicit StateID(s32 number)
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
        return mNumber == cNullNumber;
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
