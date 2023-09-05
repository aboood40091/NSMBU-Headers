#pragma once

#include <common/aglTextureData.h>
#include <controller/seadControllerMgr.h>
#include <filedevice/seadFileDevice.h>
#include <framework/seadCalculateTask.h>

class RootTask : public sead::CalculateTask
{
    SEAD_RTTI_OVERRIDE(RootTask, RootTask) // Good job, Nintendo

public:
    RootTask(const sead::TaskConstructArg& arg);

    virtual void prepare();
    virtual void enter();
    virtual void calc();

protected:
    sead::FileDevice*               mpCommonFileDevice;     // sead::AliasFileDevice*
    sead::FileDevice*               mpLocalFileDevice;      // sead::AliasFileDevice*
    sead::FileDevice*               mpPlatformFileDevice;   // sead::AliasFileDevice*
    sead::FileDevice*               mpAnyFileDevice;        // sead::AnyFileDevice*
    sead::ControllerMgr::Parameter  mControllerParameter;
    agl::TextureData                mLastFrame;
    agl::TextureData                mLastFrameDRC;
    bool                            mIsLastFrameValid;
    bool                            mIsLastFrameDRCValid;
};
static_assert(sizeof(RootTask) == 0x220);
