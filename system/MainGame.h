#pragma once

#include <heap/seadDisposer.h>

class MainGame
{
    // createInstance()                             Address: 0x029CDCAC
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101E7D7C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x029CEBF0
    // SingletonDisposer_::sStaticDisposer          Address: 0x101E7D80
    // SingletonDisposer_::vtbl                     Address: 0x1018A110
    SEAD_SINGLETON_DISPOSER(MainGame)

public:
    // Address: 0x029CD2E8
    MainGame();

    // Address: 0x029CEAD4
    void initMiiIconRenderBuffer(sead::Heap* heap = nullptr);
};
