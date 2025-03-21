#pragma once

#include <graphics/Layer.h>

class RenderMgr;

class RenderObjLayerBase : public Layer // vtbl Address: 0x100BDCE8
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9E60
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA074
    SEAD_RTTI_OVERRIDE(RenderObjLayerBase, Layer)

public:
    // Address: 0x024FC968
    RenderObjLayerBase();
    // Address: 0x024FC9D0
    virtual ~RenderObjLayerBase();

    s32 getViewIndex() const { return mViewIndex; }

    virtual void setPolygonOffset(s32 polygon_offset) const
    {
    }

    RenderMgr* getRenderMgr() const
    {
        return mpRenderMgr;
    }

    // Address: 0x024FCA24
    void setRenderMgr(RenderMgr* p_render_mgr);

    // ...

protected:
    RenderMgr*  mpRenderMgr;
    s32         mViewIndex;
    void*       _428;
};
static_assert(sizeof(RenderObjLayerBase) == 0x42C);

class RenderObjLayer : public RenderObjLayerBase    // vtbl Address: 0x100BDD50
{
public:
    enum RenderStep
    {
        cRenderStep_CalcView = 0,
        cRenderStep_UpdateGPUBuffer,
        cRenderStep_Opa,
        cRenderStep_Xlu,
        cRenderStep_Particle,
        cRenderStep_PostFx,
        cRenderStep_Num
    };
    static_assert(cRenderStep_Num == 6);

public:
    // Address: 0x024FCA6C
    RenderObjLayer();
    // Address: 0x024FCB18
    virtual ~RenderObjLayer();

    u32 getRenderStepNum() const override { return cRenderStep_Num; }
    // Address: 0x024FCB6C
    sead::SafeString getRenderStepName(s32 idx) const override;

    // Address: 0x024FCBCC
    void initialize(sead::Heap* heap) override;

    bool isRenderStepGPUCalc(s32 idx) override { return idx == cRenderStep_UpdateGPUBuffer; }

    // Address: 0x024FCCD0
    void setPolygonOffset(s32 polygon_offset) const override;

protected:
    // Address: 0x024FCCEC
    void render_(const agl::lyr::RenderInfo& render_info) const;

protected:
    sead::Matrix44f mDepthShadowMtx;
    bool            _46c;
    f32             mPolygonOffsetFactor;
    f32             mPolygonOffsetUnits;
};
static_assert(sizeof(RenderObjLayer) == 0x478);
