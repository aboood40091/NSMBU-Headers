#pragma once

#include <prim/seadMemUtil.h>

// TODO: Investigate if this is a sead type

template <u32 BitNum>
class Bitfield
{
public:
    Bitfield()
    {
        reset();
    }

    Bitfield<BitNum>& operator=(const Bitfield<BitNum>& rhs)
    {
        set(rhs)
    }

    void set(const Bitfield<BitNum>& rhs)
    {
        sead::MemUtil::copy(mBitArray, rhs.mBitArray, BitNum / 8);
    }

    void reset()
    {
        sead::MemUtil::fillZero(mBitArray, BitNum / 8);
    }

    u32 getMask(u32 index, u32 mask) const
    {
        return mBitArray[index] & mask;
    }

    bool isOn(u32 index, u32 mask) const
    {
        return getMask(index, mask) != 0;
    }

    bool isOnAll(u32 index, u32 mask) const
    {
        return getMask(index, mask) == mask;
    }

    void set(u32 index, u32 mask)
    {
        mBitArray[index] |= mask;
    }

    void reset(u32 index, u32 mask)
    {
        mBitArray[index] &= ~mask;
    }

    void toggle(u32 index, u32 mask)
    {
        mBitArray[index] ^= mask;
    }

    void change(u32 index, u32 mask, bool b)
    {
        if (b)
            set(index, mask);
        else
            reset(index, mask);
    }

    static u32 bitToIndex(u32 bit)
    {
        return bit / 32;
    }

    static u32 makeMask(u32 bit)
    {
        return 1u << (bit % 32);
    }

    bool isOnBit(u32 bit) const
    {
        return isOn(bitToIndex(bit), makeMask(bit));
    }

    void setBit(u32 bit)
    {
        set(bitToIndex(bit), makeMask(bit));
    }

    void resetBit(u32 bit)
    {
        reset(bitToIndex(bit), makeMask(bit));
    }

    void changeBit(u32 bit, bool b)
    {
        change(bitToIndex(bit), makeMask(bit), b);
    }

    void toggleBit(u32 bit)
    {
        toggle(bitToIndex(bit), makeMask(bit));
    }

private:
    static_assert(BitNum % 32 == 0);
    u32 mBitArray[BitNum / 32];
};
static_assert(sizeof(Bitfield<32>) == 4);
