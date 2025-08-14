#pragma once

#include <heap/seadDisposer.h>

class FukidashiMgr
{
    // createInstance()                             Address: 0x024B2CF8
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D157C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024B3B50
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D1580
    // SingletonDisposer_::vtbl                     Address: 0x100B6428
    SEAD_SINGLETON_DISPOSER(FukidashiMgr)

public:
    // Address: 0x024B2D7C
    void show(s32 player_no, s32 action);
    // Address: 0x024B2FC8
    void hide(s32 player_no, s32 action, u32 = 0);
    // Address: 0x024B32FC
    bool isVisible(s32 player_no);
};
