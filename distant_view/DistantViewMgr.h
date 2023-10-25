#pragma once

#include <distant_view/DVEnvTagMgr.h>
#include <graphics/CullViewFrustum.h>

#include <common/aglTextureData.h>
#include <gfx/seadCamera.h>
#include <gfx/seadProjection.h>
#include <heap/seadDisposer.h>
#include <layer/aglDrawMethod.h>
#include <layer/aglLayer.h>
#include <math/seadBoundBox.h>
#include <math/seadVector.h>
#include <postfx/aglDepthOfField.h>

class BasicModel;

//class DistantViewCreditActorMgr;
class DistantViewEffectMgr;
class DistantViewFFLMgr;
class DVCameraParam;

class ShaderParamAnimation;
class SkeletalAnimation;
class TexturePatternAnimation;

class DistantViewMgr
{
    // createInstance()                             Address: 0x022A76E0
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101CD394
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x022A94E0
    // SingletonDisposer_::sStaticDisposer          Address: 0x101CD398
    // SingletonDisposer_::vtbl                     Address: 0x10058464
    SEAD_SINGLETON_DISPOSER(DistantViewMgr)

public:
    // Address: 0x022A72E8
    DistantViewMgr();

private:
    // Address: 0x022A7760
    void calcView_();
    // Address: 0x022A7AC0
    void calcModelMtx_();

    // Address: 0x022A7B10
    void drawParticle_(const agl::lyr::RenderInfo& render_info) const;
    // Address: 0x022A7B24
    void applyDepthOfField_(const agl::lyr::RenderInfo& render_info) const;

public:
    // Address: 0x022A7C00
    void initialize(u8 course_file, u8 area, const sead::BoundBox2f& area_bound);

    // Address: 0x022A8E2C
    void resetAnim();

    // Address: 0x022A8EF8
    SkeletalAnimation* getSklAnim() const;
    // Address: Deleted
    TexturePatternAnimation* getTexAnim() const;
    // Address: Deleted
    ShaderParamAnimation* getShuTexSrtAnim() const;
    // Address: 0x022A8F08
    ShaderParamAnimation* getShuColorAnim() const;

    // Address: 0x022A8F28
    void pushBackDrawMethod();

    // Address: 0x022A9070
    void update();
    // Address: 0x022A9334
    void draw(agl::lyr::Layer* p_layer) const;

    // Address: 0x022A93A8
    void performMiiCheer(bool);

    // Address: 0x022A93C4
    void worldPosToScreenPos(sead::Vector3f* out_screen_pos, const sead::Vector3f& in_world_pos) const;
    // Address: 0x022A9414
    void worldPosToBgScrollPos(sead::Vector3f* out_pos, const sead::Vector3f& in_world_pos) const;

    // Address: 0x022A9488
    s32 searchBoneIndex(const sead::SafeString& name) const;
    // Address: 0x022A94B8
    void getBoneWorldMatrix(s32 index, sead::Matrix34f* mtx) const;

private:
    f32                         mNear;
    f32                         mFar;
    f32                         mFovyDeg;
    f32                         mScale;
    sead::Vector3f              mCameraBasePos;
    sead::Vector3f              mCameraPosOffset;
    sead::Vector3f              mCameraPos;
    sead::Vector3f              mCameraAtOffset;
    sead::LookAtCamera          mCamera;
    sead::PerspectiveProjection mProjection;
    CullViewFrustum             mCull;
    BasicModel*                 mpBasicModel;
    DVEnvTagMgr                 mEnvTagMgr;
    DVCameraParam*              mpCameraParam;
    DistantViewEffectMgr*       mpEffectMgr;
    DistantViewFFLMgr*          mpFFLMgr;
    sead::Vector3f              mBgPos; // Position relative to the Bg / level camera
    f32                         mAreaMinY;
    agl::pfx::DepthOfField      mDof;
    agl::TextureData            mDofIndTexture;
    sead::Vector2f              mDofIndScroll;
    agl::lyr::DrawMethod        mEffDrawMethod;
    agl::lyr::DrawMethod        mDofDrawMethod;
    bool                        mIsDrawParticle;
    u8                          _1455; // Unused
    bool                        mIsFlickerEnable;
    u8                          mFlickerCounter;
    sead::Vector2f              mFlickerOffset;
};
static_assert(sizeof(DistantViewMgr) == 0x1460);
