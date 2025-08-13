#pragma once

#include <heap/seadDisposer.h>

class SubjectMgr
{
    // createInstance()                             Address: 0x024CDA98
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D1874
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024D04A4
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D1878
    // SingletonDisposer_::vtbl                     Address: 0x100B927C
    SEAD_SINGLETON_DISPOSER(SubjectMgr)

public:
    enum ComboType
    {
        //
        cComoType_PlFumi = 1,
        cComoType_PlStar,
        cComoType_AcCombo,
        //
        cComoType_PlCombo = 5
    };

public:
    // Address: 0x024CEEE0
    void onAcComboCntClr();
    // Address: 0x024CF74C
    void onComboCntInc(s32 cnt, ComboType type);

    // Address: 0x024CFB00
    void onAcBlockHit();
};
