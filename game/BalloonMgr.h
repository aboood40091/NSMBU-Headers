#pragma once

#include <actor/ActorUniqueID.h>

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <math/seadVector.h>

class BalloonMgr
{
    // createInstance()                             Address: 0x024B8E64
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D159C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024B9824
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D15A0
    // SingletonDisposer_::vtbl                     Address: 0x100B6B08
    SEAD_SINGLETON_DISPOSER(BalloonMgr)

public:
    void onDemo()
    {
        mIsActive = false;
    }

    void offDemo()
    {
        mIsActive = true;
    }

    // Address: 0x024B953C
    void createRevivalBallon(const sead::Vector3f& pos, s32 type, s32 player_no);

protected:
    u32     _10;
    u32     _14;
    u32     _18;
    u8      _1c;
    u8      _1d;
    bool    mIsShadowkunCaught;
    bool    mIsActive;
    u32     _20;
    u32     _24;
    sead::SafeArray<
        ActorUniqueID,
        5
    >       mBalloonItemID;
};
static_assert(sizeof(BalloonMgr) == 0x3C);
