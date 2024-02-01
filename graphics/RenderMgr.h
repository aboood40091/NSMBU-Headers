#pragma once

#include <graphics/ModelEnvView.h>

#include <common/aglTextureSampler.h>
#include <container/seadBuffer.h>
#include <container/seadListImpl.h>
#include <container/seadPtrArray.h>
#include <environment/aglEnvObjMgr.h>
#include <gfx/seadCamera.h>
#include <gfx/seadProjection.h>
#include <heap/seadDisposer.h>
#include <layer/aglRenderInfo.h>
#include <math/seadMatrix.h>
#include <prim/seadNamable.h>
#include <shadow/aglDepthShadow.h>

class CullViewFrustum;
class RenderObj;
class RenderObjLayerBase;

class RenderMgr : public sead::IDisposer, public sead::INamable
{
public:
    struct ViewInfo
    {
        RenderObjLayerBase*     layer;
        sead::Matrix34f         view_mtx;
        sead::Matrix44f         proj_mtx;
        const sead::Matrix44f*  _74;
        const CullViewFrustum*  cull;
        void*                   _7c; // pointer to struct of two f32 and one sead::Color4f for fog color
    };
    static_assert(sizeof(ViewInfo) == 0x80);

    class CallbackBase
    {
    public:
        virtual void preDrawOpa(s32 view_index, s32 buffer_index, const agl::lyr::RenderInfo& render_info) = 0;
        virtual void preDrawXlu(s32 view_index, s32 buffer_index, const agl::lyr::RenderInfo& render_info) = 0;
        virtual void postDrawOpa(s32 view_index, s32 buffer_index, const agl::lyr::RenderInfo& render_info) = 0;
        virtual void postDrawXlu(s32 view_index, s32 buffer_index, const agl::lyr::RenderInfo& render_info) = 0;
    };

public:
    RenderMgr(const sead::SafeString& name);
    virtual ~RenderMgr();

    void initialize(s32 view_max_num, s32 render_obj_max_num, s32 opa_buffer_max_num, s32 xlu_buffer_max_num, sead::Heap* heap);
    void initialize(s32 view_max_num, s32 render_obj_max_num, s32 opa_buffer_alloc_num, s32 opa_buffer_max_num, s32 xlu_buffer_max_num, sead::Heap* heap);

    bool isFull() const;

    void updateEnvObjMgr();

    void clear();

    void calcView(s32 view_index, const sead::Camera& camera, const sead::Projection& projection, const sead::Matrix44f* param_4, const CullViewFrustum* cull, void* param_6);
    void calcGPU(s32 view_index);
    void drawOpa(s32 view_index, const agl::lyr::RenderInfo& render_info);
    void drawXlu(s32 view_index, const agl::lyr::RenderInfo& render_info);
    void drawShadowOpa(s32 view_index, const agl::lyr::RenderInfo& render_info);
    void drawReflectionOpa(s32 view_index, const agl::lyr::RenderInfo& render_info);
    void drawReflectionXlu(s32 view_index, const agl::lyr::RenderInfo& render_info);

    void pushBackRenderObj(RenderObj* obj, s32 opa_buffer_index, s32 xlu_buffer_index);
    void pushBackRenderObj(RenderObj* obj, s32 opa_buffer_index, s32 xlu_buffer_index, const sead::Vector3f& order_pos);

    s32 createView(RenderObjLayerBase* layer);

    void loadEnvRes(const void* file);

    void calcViewShapeShadowFlags(agl::sdw::DepthShadow* depth_shadow, RenderObjLayerBase* shadow_layer);

    ModelEnvView& getModelEnvView() { return mModelEnvView; }
    const ModelEnvView& getModelEnvView() const { return mModelEnvView; }

    CallbackBase* getDrawCallback() const { return mCallback; }
    void setDrawCallback(CallbackBase* callback) { mCallback = callback; }

    agl::TextureSampler* getShadowMap() const { return mShadowMap; }
    agl::TextureSampler* getReflectionMap() const { return mReflectionMap; }

    void setShadowMap(agl::TextureSampler* sampler) { mShadowMap = sampler; }
    void setReflectionMap(agl::TextureSampler* sampler) { mReflectionMap = sampler; }

    agl::env::EnvObjMgr& getEnvObjMgr() { return mEnvObjMgr; }
    const agl::env::EnvObjMgr& getEnvObjMgr() const { return mEnvObjMgr; }

    ViewInfo& getViewInfo(s32 view_index) { return mViewInfo[view_index]; }
    const ViewInfo& getViewInfo(s32 view_index) const { return mViewInfo[view_index]; }

private:
    void enable_18_();

    static int compare_(const RenderObj* a, const RenderObj* b);

private:
    bool                                        _18;
    sead::PtrArray<RenderObj>                   mRenderObj;
    sead::Buffer< sead::PtrArray<RenderObj> >   mRenderObjOpa;
    sead::Buffer< sead::PtrArray<RenderObj> >   mRenderObjXlu;
    sead::PtrArray<RenderObj>                   mRenderObjShadow;
    agl::env::EnvObjMgr                         mEnvObjMgr;
    ModelEnvView                                mModelEnvView;
    CallbackBase*                               mCallback;
    bool                                        mDrawShadow;        // I think
    agl::TextureSampler*                        mShadowMap;
    agl::TextureSampler*                        mReflectionMap;
    sead::Buffer<ViewInfo>                      mViewInfo;
    sead::ListNode                              mListNode;          // For sead::OffsetList in LayerMgr
};
static_assert(sizeof(RenderMgr) == 0x4D4);
