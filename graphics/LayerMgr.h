#pragma once

#include <framework/seadTaskMgr.h>
#include <gfx/seadCamera.h>
#include <gfx/seadProjection.h>
#include <gfx/seadViewport.h>
#include <layer/aglDrawMethod.h>

class RenderMgr;

class LayerMgr : public sead::TaskBase  // vtbl Address: 0x100BB268
{
    // setInstance_()                               Address: 0x024E013C
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2BE4
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024DFFE4
    SEAD_TASK_SINGLETON_DISPOSER(LayerMgr)

public:
    enum Layer
    {
        cLayer_Gather = 0,
        cLayer_Capture,
        cLayer_ReflectionLightMap,
        cLayer_Reflection_User,
        cLayer_LightMap,
        cLayer_User_0,
        cLayer_User_1,
        cLayer_User_2,
        cLayer_User_3,
        cLayer_User_4,
        cLayer_User_5,
        cLayer_User_6,
        cLayer_User_7,
        cLayer_User_8,
        cLayer_System,
        cLayer_15,                      // Unknown
        cLayer_16,                      // Unknown
        cLayer_Fader,
        cLayer_DRCMode,
        cLayer_DebugDraw,
        cLayer_ReflectionLightMap_DRC,
        cLayer_Reflection_User_DRC,
        cLayer_LightMap_DRC,
        cLayer_DRC_User_0,
        cLayer_DRC_User_1,
        cLayer_DRC_User_2,
        cLayer_DRC_User_3,
        cLayer_DRC_User_4,
        cLayer_System_DRC,
        cLayer_Fader_DRC,
        cLayer_DebugDraw_DRC,
        cLayer_Num
    };
    static_assert(cLayer_Num == 31);

public:
    // Address: 0x024E015C
    LayerMgr(const sead::TaskConstructArg& arg);

    // TODO
    // virtual ...

    // Address: 0x024E0E50
    void clearRenderMgr();

    // Address: 0x024E0F84
    void calcDL();

    // Address: 0x024E0FEC
    void calcParallelExec();

    // Address: 0x024E1260
    void removeRenderMgr(RenderMgr* p_render_mgr);

    void setDRCUniqueView(bool enable)
    {
        mIsDRCUniqueView = enable;
    }

protected:
    agl::lyr::DrawMethod        mDrawMethod;
    sead::MethodTreeNode        _b8;
    sead::MethodTreeNode        _10c;
    sead::MethodTreeNode        _160;
    sead::Viewport              mViewport;
    sead::OrthoProjection       mProjection;
    sead::OrthoCamera           mCamera;
    bool                        mIsDRCUniqueView;                                   // false = TV framebuffer is duplicated to the DRC
    sead::OffsetList<RenderMgr> mRenderMgr;
    sead::CriticalSection       mCriticalSection;
    u32                         _320[4 / sizeof(u32)];
    u32                         mRenderObjParallelExecuter[0x4024 / sizeof(u32)];   // TODO: RenderObjParallelExecuter
    u32                         gpuCalcObjTV[8 / sizeof(u32)];                      // TODO: GpuCalcObj
    u32                         gpuCalcObjDRC[8 / sizeof(u32)];                     // ^^^
};
static_assert(sizeof(LayerMgr) == 0x4358);
