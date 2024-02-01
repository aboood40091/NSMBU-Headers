#pragma once

#include <common/aglShaderProgramArchive.h>
#include <common/aglTextureSampler.h>
#include <heap/seadHeap.h>
#include <math/seadMatrix.h>

#include <nn/ffl.h>

class ModelFFL;
class RenderMgr;

namespace Mii {

class Shader
{
public:
    enum Uniform
    {
        cUniform_Proj = 0,
        cUniform_MV,
        cUniform_IT,    // Inverse transpose of MV
        cUniform_Mode,
        cUniform_Const0,
        cUniform_Const1,
        cUniform_Const2,
        cUniform_LightEnable,
        cUniform_LightDir,
        cUniform_LightAmbient,
        cUniform_LightDiffuse,
        cUniform_LightSpecular,
        cUniform_MaterialAmbient,
        cUniform_MaterialDiffuse,
        cUniform_MaterialSpecular,
        cUniform_MaterialSpecularPower,
        cUniform_MaterialSpecularMode,
        cUniform_RimColor,
        cUniform_RimPower,
        cUniform_SpecularMask,
        cUniform_IsFaceMask,
        cUniform_ExLightRegColor,
        cUniform_ExDarkRegColor,
        cUniform_LightmapEnable,
        cUniform_FogColor,
        cUniform_FogStart,
        cUniform_FogStartEndInv,
        cUniform_FogDir,
        cUniform_Num
    };
    static_assert(cUniform_Num == 28);

    enum Sampler
    {
        cSampler_Texture,
        cSampler_Lightmap01p,
        cSampler_Lightmap02p,
        cSampler_Num
    };
    static_assert(cSampler_Num == 3);

public:
    // Address: 0x024EA2A4
    Shader();
    // Address: 0x024EA33C
    ~Shader();

    // Address: 0x024EA39C
    static void initializeShader(agl::ShaderProgramArchive* archive, sead::Heap* heap);

    // Address: 0x024EB448
    void initialize(sead::Heap* heap = nullptr);

    void setModel(ModelFFL* model)
    {
        mModel = model;
    }

    // Address: 0x024EB8AC
    void setCallback() const;

    // Address: 0x024EB8B4
    void activate() const;

    // Address: 0x024EB8F4
    void setViewUniform(const sead::Matrix34f& model_mtx, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx) const;
    // Address: 0x024EBA4C
    void setExRegColorUniform(const sead::Color4f* color) const;
    // Address: 0x024EBB20
    void setLightmapEnableUniform(bool enable) const;
    // Address: 0x024EBB98
    void setFogUniform(RenderMgr* render_mgr) const;

    // Address: 0x024EA654
    static void setCulling(FFLCullMode mode);

private:
    // Address: 0x024EA4D4
    void initializeParam_();

    // Address: 0x024EA9B0
    void setLightUniform_() const;
    // Address: 0x024EA6A0
    void setMaterialUniform_(const FFLDrawParam& draw_param) const;
    // Address: 0x024EAB90
    void setRimUniform_() const;

    // Address: 0x024EAC74
    void draw_(const FFLDrawParam& draw_param);
    // Address: 0x024EB304
    static void drawCallback_(void* obj, const FFLDrawParam& draw_param);

    // Address: 0x024EB308
    void setMatrix_(const Mat44& matrix);
    // Address: 0x024EB444
    static void setMatrixCallback_(void* obj, const Mat44& matrix);

private:
    struct LightParam
    {
        bool            enable;
        sead::Vector3f  dir;
        FFLColor        ambient;
        FFLColor        diffuse;
        FFLColor        specular;
    };
    static_assert(sizeof(LightParam) == 0x40);

    struct Material
    {
        FFLColor    ambient;
        FFLColor    diffuse;
        FFLColor    specular;
        f32         specular_power;
        s32         specular_mode;
    };
    static_assert(sizeof(Material) == 0x38);

    struct RimParam
    {
        union
        {
            FFLColor    color;
            struct  // IDEK man
            {
                s32 color_r;
                s32 color_g;
                s32 color_b;
                s32 color_a;
            };
        };
        f32         power;
    };
    static_assert(sizeof(RimParam) == 0x14);

    struct SpecularParam
    {
        FFLColor    hair_specular;
        f32         mask;
    };
    static_assert(sizeof(SpecularParam) == 0x14);

    const agl::ShaderProgramArchive*    mShaderArchive;
    const agl::ShaderProgram*           mShaderProgram;
    sead::Buffer<GX2AttribStream>       mAttribute;
    GX2FetchShader                      mFetchShader;
    FFLShaderCallback                   mCallback;
    GX2Sampler                          mSampler;
    ModelFFL*                           mModel;
    agl::TextureSampler                 mLightmap02p_0;
    agl::TextureSampler                 mLightmap02p_1;
    LightParam                          mLightParam;
    Material                            mMaterial[FFL_MODULATE_TYPE_SHAPE_MAX];
    RimParam                            mRimParam;
    SpecularParam                       mSpecularParam;
};
static_assert(sizeof(Shader) == 0x5F0);

}
