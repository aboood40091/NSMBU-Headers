#pragma once

#include <graphics/RenderObj.h>

#include <container/seadSafeArray.h>
#include <framework/seadCalculateTask.h>
#include <framework/seadTaskMgr.h>
#include <gfx/seadCamera.h>
#include <gfx/seadProjection.h>
#include <layer/aglDrawMethod.h>
#include <lighting/aglLightMapMgr.h>

#include <nw/g3d/res/g3d_ResTexture.h>

class ModelG3d;

class LightMapMgr : public sead::CalculateTask  // vtbl Address: 0x100BBA94
{
    // setInstance_()                               Address: 0x024E3A78
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2C60
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024E3990
    SEAD_TASK_SINGLETON_DISPOSER(LightMapMgr)

public:
    static const s32 cLightMapNum = 2;

    enum EnvTypeCourse
    {
        cEnvTypeCourse_Enemy = 0,
        cEnvTypeCourse_Boss,
        cEnvTypeCourse_MapObj,
        cEnvTypeCourse_Item,
        cEnvTypeCourse_Player,
        cEnvTypeCourse_DistantView,
        cEnvTypeCourse_Effect,
        cEnvTypeCourse_Num
    };
    static_assert(cEnvTypeCourse_Num == 7);

    enum EnvTypeCourseSelect
    {
        cEnvTypeCourseSelect_W1a = 0,
        cEnvTypeCourseSelect_W2a,
        cEnvTypeCourseSelect_W2b,
        cEnvTypeCourseSelect_W3a,
        cEnvTypeCourseSelect_W4a,
        cEnvTypeCourseSelect_W5a,
        cEnvTypeCourseSelect_W5b,
        cEnvTypeCourseSelect_W6a,
        cEnvTypeCourseSelect_W6b,
        cEnvTypeCourseSelect_W7a,
        cEnvTypeCourseSelect_W8a,
        cEnvTypeCourseSelect_W8b,
        cEnvTypeCourseSelect_W9a,
        cEnvTypeCourseSelect_Num
    };
    static_assert(cEnvTypeCourseSelect_Num == 13);

    static const s32 cLightMapNumAll = (cEnvTypeCourse_Num + cEnvTypeCourseSelect_Num) * cLightMapNum;

    static const s32 cLightMapHemisphereLightNum = 2;
    static const s32 cHemisphereLightNum = cLightMapHemisphereLightNum;

    static const s32 cLightMapDirectionalLightNumMain = 2;
    static const s32 cLightMapDirectionalLightNumCourse = 4;
    static const s32 cLightMapDirectionalLightNumCourseSelect = 2;
    static const s32 cLightMapDirectionalLightNum = 4; // max(cLightMapDirectionalLightNumMain, cLightMapDirectionalLightNumCourse, cLightMapDirectionalLightNumCourseSelect)

    static const s32 cDirectionalLightNumMain = cLightMapDirectionalLightNumMain;
    static const s32 cDirectionalLightNumCourse = cEnvTypeCourse_Num * cLightMapDirectionalLightNumCourse;
    static const s32 cDirectionalLightNumCourseSelect = cEnvTypeCourseSelect_Num * cLightMapDirectionalLightNumCourseSelect;
    static const s32 cDirectionalLightNumAll = cDirectionalLightNumMain + cDirectionalLightNumCourse + cDirectionalLightNumCourseSelect;

    enum AmbColorType
    {
        cAmbColorType_EffectColor13_0 = 0,
        cAmbColorType_EffectColor13_1,
        cAmbColorType_EffectColor14_0,
        cAmbColorType_EffectColor14_1,
        cAmbColorType_EffectColor15_0,
        cAmbColorType_EffectColor15_1,
        cAmbColorType_WaterHalfFrontColor0,
        cAmbColorType_WaterHalfFrontKonst0,
        cAmbColorType_WaterHalfFrontKonst1,
        cAmbColorType_WaterHalfBehindColor0,
        cAmbColorType_WaterHalfBehindColor1,
        cAmbColorType_Num
    };
    static_assert(cAmbColorType_Num == 11);

    enum RenderStep
    {
        cRenderStep_CalcView = 0,
        cRenderStep_UpdateGPUBuffer,
        cRenderStep_LightDraw,
        cRenderStep_Num
    };
    static_assert(cRenderStep_Num == 3);

private:
    class CalcObj : public RenderObjBase
    {
    public:
        void calc() override;

    private:
        agl::lght::LightMapMgr* mpLightMapMgr;

        friend class LightMapMgr;
    };
    static_assert(sizeof(CalcObj) == 8);

    enum View
    {
        cView_Main = 0,
        cView_MainDRC,
        cView_Reflection,
        cView_ReflectionDRC,
        cView_Num
    };
    static_assert(cView_Num == 4);

public:
    // Address: 0x024E3A98
    LightMapMgr(const sead::TaskConstructArg& arg);
    // Address: 0x024E39BC
    virtual ~LightMapMgr();

    agl::lght::LightMapMgr& getLightMapMgr() { return mLightMapMgr; }
    const agl::lght::LightMapMgr& getLightMapMgr() const { return mLightMapMgr; }

    bool overrideModelLightMap() const { return mOverrideModelLightMap; }
    void setOverrideModelLightMap(bool enable) { mOverrideModelLightMap = enable; }

    // Address: 0x024E4398
    void prepare() override;
    // Address: 0x024E4E30
    void enter() override;
    // Address: 0x024E5008
    void calc() override;

    // Address: 0x024E3DC0
    void loadAglEnvBinary(void* p_data, s32 = -1);
    // Address: 0x024E3EC0
    void loadAglEnvBinary(const sead::SafeString& name, s32 = -1, sead::Heap* heap = nullptr);
    // Address: 0x024E3F14
    void loadAglEnvBinary(const sead::SafeString& name, sead::Heap* heap = nullptr);

    // Address: 0x024E3FB0
    void initializeViewDependent(
        const sead::Camera* p_camera, const sead::Projection* p_projection,
        const sead::Camera* p_camera_drc = nullptr, const sead::Projection* p_projection_drc = nullptr
    );
    // Address: 0x024E3FFC
    void initializeViewIndependent();

    // Address: 0x024E4094
    void loadAglLmapBinary(void* p_data);
    // Address: 0x024E42D8
    void loadAglLmapBinary(const sead::SafeString& name, sead::Heap* heap = nullptr);

    // Address: 0x024E4318
    void initialize(sead::Heap* heap = nullptr);

    // Address: 0x024E5040
    void setModelLightMap(ModelG3d* p_model, bool set_mdl_dl_dirty) const;

    // Address: 0x024E51C0
    void loadAglEnvBinaryWithType(const sead::SafeString& name, const sead::SafeString& type, sead::Heap* heap = nullptr);

    // Address: 0x024E51C8
    void initializeForCourseSelect(sead::Heap* heap = nullptr);
    // Address: 0x024E53B4
    void loadAglEnvBinaryWithLerpForCourseSelect(f32 t);

    // Address: 0x024E54E4
    const agl::TextureSampler& getLightmap1(EnvTypeCourse type) const;
    // Address: 0x024E5534
    const agl::TextureSampler& getLightmap2(EnvTypeCourse type) const;

    // Address: 0x024E5584
    void getAmbColor(sead::Color4f* p_color, AmbColorType type) const;

    // Address: 0x024E5900
    void setCobModelLightMapForCourseSelect(ModelG3d* p_model, u8 world, u8 world_sub_letter) const;
    // Address: 0x024E5A14
    void setModelLightMapForCourseSelect(ModelG3d* p_model) const;

    // Address: 0x024E5AF8
    const sead::SafeString& getEnvTypeCourseStr(EnvTypeCourse type) const;

private:
    // Address: 0x024E3F20
    void initializeViewDependent_();

    // Address: 0x024E5734
    void setModelLightMapWithName_(ModelG3d* p_model, const sead::SafeString& name, s32 idx_lghtmap, s32 model_light_map_index) const;

    // Address: 0x024E5B0C
    void draw_(const agl::lyr::RenderInfo& render_info, View view, bool view_dependent, const sead::Matrix34f* p_view_mtx, const sead::Projection* p_projection);

    // Address: 0x024E5DB0
    void drawMain_(const agl::lyr::RenderInfo& render_info);
    // Address: 0x024E5DC4
    void drawMainDRC_(const agl::lyr::RenderInfo& render_info);
    // Address: 0x024E5DD8
    void drawReflection_(const agl::lyr::RenderInfo& render_info);
    // Address: 0x024E5F60
    void drawReflectionDRC_(const agl::lyr::RenderInfo& render_info);

private:
    u32                             _cc[4 / sizeof(u32)];
    nw::g3d::res::ResTexture*       mpResTexture[cLightMapNumAll];
    nw::g3d::res::ResTextureData    mResTextureData[cLightMapNumAll];
    agl::lyr::DrawMethod            mDrawMethodMain;
    agl::lyr::DrawMethod            mDrawMethodMainDRC;
    agl::lyr::DrawMethod            mDrawMethodReflection;
    agl::lyr::DrawMethod            mDrawMethodReflectionDRC;
    agl::lght::LightMapMgr          mLightMapMgr;
    CalcObj                         mCalcObj;
    agl::env::EnvObjMgr             mEnvObjMgr;
    bool                            mIsViewDependent;
    const sead::Camera*             mpCamera;
    const sead::Projection*         mpProjection;
    const sead::Camera*             mpCameraDRC;
    const sead::Projection*         mpProjectionDRC;
    sead::SafeArray<
        sead::SafeArray<
            s32,
            cEnvTypeCourse_Num
        >,
        cLightMapNum
    >                               mLightMapIndexCourse;
    sead::SafeArray<
        s32,
        cAmbColorType_Num
    >                               mAmbientLightTypeIndex;
    const void*                     mpAglEnvBinary1;
    const void*                     mpAglEnvBinary2;
    bool                            mOverrideModelLightMap;
};
static_assert(sizeof(LightMapMgr) == 0x52CC);
