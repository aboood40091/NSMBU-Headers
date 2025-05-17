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

    bool isOnBit(u32 bit) const
    {
        return mBitArray[bit / 32] >> (bit % 32) & 1;
    }

    bool isOffBit(u32 bit) const
    {
        return !isOnBit(bit);
    }

    void setBit(u32 bit)
    {
        mBitArray[bit / 32] |= 1 << (bit % 32);
    }

    void resetBit(u32 bit)
    {
        mBitArray[bit / 32] &= ~(1 << (bit % 32));
    }

private:
    static_assert(BitNum % 32 == 0);
    u32 mBitArray[BitNum / 32];
};
static_assert(sizeof(Bitfield<32>) == 4);
