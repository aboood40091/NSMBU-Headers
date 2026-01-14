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
    enum Mode
    {
        cMode_None = 0,
        cMode_Active,
        cMode_Clear,
        cMode_Fail,
        cMode_Num
    };
    static_assert(cMode_Num == 4);

    enum FinishType
    {
        cFinishType_Invalid = 6
    };

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
    // Address: 0x024CED80
    void onPlFumiCntClr();
    // Address: 0x024CEEE0
    void onAcComboCntClr();

    // Address: 0x024CF4A0
    FinishType getFinishType() const;

    // Address: 0x024CF74C
    void onComboCntInc(s32 cnt, ComboType type);

    // Address: 0x024CFB00
    void onAcBlockHit();

    // Address: 0x024D03C0
    void setFinishSubjectCoin(s32 coin_num);

    bool isDisableAreaExit() const
    {
        return mIsDisableAreaExit;
    }

    bool isSubjectCoin() const
    {
        return mIsSubjectCoin;
    }

    bool isSkipClearWait() const
    {
        return mSkipClearWait;
    }

    Mode getMode() const
    {
        return static_cast<Mode>(mMode);
    }

protected:
    u32     _10[(0x1E54 - 0x10) / sizeof(u32)];
    bool    mIsDisableAreaExit;
    u8      _1e55[0x1E57 - 0x1E55];
    bool    mIsSubjectCoin;
    u8      _1e58[0x1E5E - 0x1E58];
    bool    mSkipClearWait;
    u8      _1e5f[0x1E7F - 0x1E5F];
    u8      mMode;
    u8      _1e80[0x1E84 - 0x1E80];
};
static_assert(sizeof(SubjectMgr) == 0x1E84);
