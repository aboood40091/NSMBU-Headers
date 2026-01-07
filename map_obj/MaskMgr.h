#pragma once

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>

class PlayerMask
{
public:
    f32 getCaveMaskDiameter() const
    {
        return mCaveMaskDiameter;
    }

protected:
    u32 _0[0x11C / sizeof(u32)];
    f32 mCaveMaskDiameter;
    u32 _120[(0x140 - 0x120) / sizeof(u32)];
};
static_assert(sizeof(PlayerMask) == 0x140);

class MaskMgr
{
    SEAD_SINGLETON_DISPOSER(MaskMgr)

public:
    PlayerMask& getPlayerMask(s32 player_no)
    {
        return mPlayerMask[player_no];
    }

protected:
    u32 _0[(0x1C - 0x10) / sizeof(u32)];
    sead::SafeArray<
        PlayerMask,
        4
    > mPlayerMask;
    sead::SafeArray<
        PlayerMask,
        4
    > mPlayerMask2;
};
static_assert(sizeof(MaskMgr) == 0xA1C);
