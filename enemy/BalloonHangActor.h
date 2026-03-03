#pragma once

#include <enemy/Enemy.h>

class BalloonHangActor : public Enemy   // vtbl Address: 0x1005A150
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA148
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA82C
    SEAD_RTTI_OVERRIDE(BalloonHangActor, Enemy)

public:
    // Address: 0x022BDAE0
    void getHangPos(sead::Vector2f& out, u32 = 0) const;

    // Address: 0x022BE744
    void detachChild();

    bool isDetach() const
    {
        return mIsDetach;
    }

protected:
    u32     _1880[(0x18A4 - 0x1880) / sizeof(u32)];
    bool    mIsDetach;
    u32     _18a8[(0x18B0 - 0x18A8) / sizeof(u32)];
};
static_assert(sizeof(BalloonHangActor) == 0x18B0);
