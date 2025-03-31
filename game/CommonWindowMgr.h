#pragma once

#include <input/SysControllerWrapper.h>
#include <layout/CommonWindow.h>

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <layer/aglRenderInfo.h>

class CommonWindowMgr
{
    // createInstance()                             Address: 0x024BC444
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D15E8
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024BC874
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D15EC
    // SingletonDisposer_::vtbl                     Address: 0x100B7014
    SEAD_SINGLETON_DISPOSER(CommonWindowMgr)

public:
    enum PadTrigStatus
    {
        cStatus_Decide = 0,
        cStatus_Back,
        cStatus_Disabled,
        cStatus_Dpad,       // Maybe???
        cStatus_Idle
    };

public:
    // Address: 0x024BC3C4
    CommonWindowMgr();

    // Address: 0x024BC4C4
    void create();

    // Address: 0x024BC540
    void execute();

    // Address: 0x024BC590
    void draw(const agl::lyr::RenderInfo& render_info) const;

    // Address: 0x024BC5A4
    void drawDRC(const agl::lyr::RenderInfo& render_info) const;        // Only draws if mCommonWindow.mIsSystemDRC == false
    // Address: 0x024BC5C4
    void drawDRC_System(const agl::lyr::RenderInfo& render_info) const; // Only draws if mCommonWindow.mIsSystemDRC == true

    // Address: 0x024BC5E4
    PadTrigStatus processPadTrig_TwoButtons(bool enable_back_button);   // i.e., Window has two UI buttons
    // Address: 0x024BC7D4
    PadTrigStatus processPadTrig_OneButton();                           // i.e., Window has one UI button

private:
    CommonWindow                mCommonWindow;
    sead::SafeArray<
        SysControllerWrapper,
        SysController::cId_Max
    >                           mControllers;
    SysController::Id           mCurrentControllerId;
    bool                        mIsActive;
};
static_assert(sizeof(CommonWindowMgr) == 0x22B8);
