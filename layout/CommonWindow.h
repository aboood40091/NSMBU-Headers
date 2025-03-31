#pragma once

#include <layout/PaCursor.h>
#include <layout_sys/AnimLayout.h>
#include <state/FStateMgr.h>

class CommonWindowMgr;

class CommonWindow  // vtbl Address: 0x100CCD58
{
public:
    enum Type
    {
        cType_WinText_Title = 0,
        cType_WinText_Pause,
        cType_WinText_ReturnPlayerNum,
        cType_WinText_QuickSave,
        cType_WinText_QuickSaveEnd,
        cType_WinText_ChangePlayStyle,
        cType_CourseSelect_NumBtn_warning,
        cType_CourseSelect_PlayStyleBtn_warning,
        cType_CoinEditMenu_Reset_confirm,
        cType_WinText_Save,
        cType_WinText_SaveEnd,
        cType_WinText_ChallengeExit_0,
        cType_WinText_ChallengeRetry,
        cType_CoinEditMenu_Save_confirm,
        cType_WinText_EditSave,
        cType_CoinEditMenu_End_confirm,
        cType_WinText_ChallengeTitle,
        cType_WinText_VSTitle,
        cType_WinText_SCoinMovie,
        cType_Olive_UpWindow_0,
        cType_Olive_UpWindow_1,
        cType_Olive_UpWindow_2,
        cType_Olive_UpWindow_3,
        cType_Olive_UpWindow_4,
        cType_Olive_UpWindow_5,
        cType_Olive_UpWindow_6,
        cType_Olive_UpWindow_7,
        cType_27,   // Invalid
        cType_Olive_ClearUpWindow_0,
        cType_Olive_ClearUpWindow_1,
        cType_Olive_ClearUpWindow_2,
        cType_Olive_ClearUpWindow_3,
        cType_Olive_ClearUpWindow_4,
        cType_Olive_ClearUpWindow_5,
        cType_Olive_ClearUpWindow_8,
        cType_WinText_FreeExit,
        cType_WinText_FreeTitle,
        cType_WinText_VSExit,
        cType_WinText_ChallengeExit_1,
        cType_Olive_ClearUpWindow_6,
        cType_Olive_ClearUpWindow_7,
        cType_WinText_InitialSave_1,
        cType_WinText_InitialSave_2,
        cType_WinText_Boss_0,
        cType_WinText_Boss_1,
        cType_WinText_Boss_2,
        cType_WinText_Boss_3,
        cType_WinText_Boss_4,
        cType_WinText_Boss_5,
        cType_WinText_EndingSave,
        cType_WinText_Item,
        cType_WinText_ReKinoko,
        cType_SetUpOlive_Warning,
        cType_SetUpOlive_NoSelect_0,
        cType_SetUpOlive_NoSelect_1,
        cType_WinText_Boss_6,
        cType_Olive_UpWindow_8,
        cType_Olive_ClearUpWindow_9,
        cType_DL_WinText_PlayerBlock,
        cType_WinText_SetUpBtn,
        cType_Num,

        cDefaultMsgTextType = cType_Olive_UpWindow_0
    };
    static_assert(sizeof(Type) == 4);
    static_assert(cType_Num == 60);

    enum Color
    {
        cColor_Default = 0,   // Also used for time attack challenges
        cColor_Coin,
        cColor_1UP,
        cColor_Special,
        cColor_Assist,
        cColor_Num
    };
    static_assert(sizeof(Color) == 4);
    static_assert(cColor_Num == 5);

public:
    // Address: 0x02585958
    CommonWindow();
    // Address: 0x02585B90
    virtual ~CommonWindow();

    // Address: 0x02586CF4
    bool cursorIsOnLeftButton() const;

    // Address: 0x02586D28
    bool cursorIsOnRightButton() const;

    void cursorTriggerDecide()
    {
        mPaCursor.triggerDecide();
    }

    void cursorResetDecideTrig()
    {
        mPaCursor.resetDecideTrig();
    }

    bool cursorIsNoPadInput() const
    {
        return mPaCursor.isNoPadInput();
    }

protected:
    FStateMgr<CommonWindow>                 mStateMgr;
    AnimLayout<2>                           mLayout;
    PaCursor                                mPaCursor;
    sead::SafeArray<nw::lyt::Pane*, 8>      mNPane;
    sead::SafeArray<TextBox*, 23>           mTPane;
    sead::SafeArray<nw::lyt::Parts*, 15>    mPaPane;
    sead::SafeArray<nw::lyt::Window*, 1>    mWPane;
    sead::SafeArray<nw::lyt::Picture*, 1>   mPPane;
    sead::SafeArray<
        SysControllerWrapper,
        SysController::cId_Max
    >                                       mControllers;
    Type                                    mType;
    Type                                    mMsgTextType;
    s32                                     _1a98;                          // Some kind of timer
    s32                                     _1a9c;                          // ^^^
    Color                                   mColor;
    SysController::Id                       mCurrentControllerId;
    bool                                    mRequestOpen;
    bool                                    mIsVisible;
    bool                                    mIsTransitionAnime;
    bool                                    mRequestClose;
    bool                                    mKeepOpenPostDecide;
    bool                                    mHideBackButton;
    bool                                    mIsDRC;
    bool                                    mIsFadeOut;
    bool                                    mIsDoneOutQuickSaveAnime;
    bool                                    mIsBgmVolumeAlreadyAdjusted;
    bool                                    mSetSeDecideToBackForLeftBtn;
    bool                                    mSetSeDecideForPlayStyleBtn;
    bool                                    mIsSystemDRC;
    bool                                    mFreezePostDecide;              // Never set to true in the original game
    bool                                    mIsDecidedTwoButtons;           // Has the decide button already been triggered if the window has two buttons?
    bool                                    mIsURCC;

    friend class CommonWindowMgr;
};
static_assert(sizeof(CommonWindow) == 0x1ABC);
