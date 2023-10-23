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
    // Address: 0x024EA2A4
    Shader();
    // Address: 0x024EA33C
    ~Shader();

    // Address: 0x024EA39C
    static void initializeShader(agl::ShaderProgramArchive* p_archive, sead::Heap* heap);

    // Address: 0x024EB448
    void initialize(sead::Heap* heap = nullptr);

    void setModel(ModelFFL* p_model)
    {
        mpModel = p_model;
    }

    // Address: 0x024EB8AC
    void setCallback() const;

    // Address: 0x024EB8B4
    void activate() const;

    // Address: 0x024EB8F4
    void setViewUniform(const sead::Matrix34f& model_mtx, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx) const;
    // Address: 0x024EBA4C
    void setExRegColorUniform(const sead::Color4f* p_color) const;
    // Address: 0x024EBB20
    void setLightmapEnableUniform(bool enable) const;
    // Address: 0x024EBB98
    void setFogUniform(RenderMgr* p_render_mgr) const;

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
        f32         specularPower;
        f32         specularMode;
    };
    static_assert(sizeof(Material) == 0x38);

    struct RimParam
    {
        FFLColor    color;
        f32         power;
    };
    static_assert(sizeof(RimParam) == 0x14);

    struct SpecularParam
    {
        FFLColor    hairSpecular;
        f32         mask;
    };
    static_assert(sizeof(SpecularParam) == 0x14);

    agl::ShaderProgramArchive*      mpShaderArchive;
    agl::ShaderProgram*             mpShaderProgram;
    sead::Buffer<GX2AttribStream>   mAttribute;
    GX2FetchShader                  mFetchShader;
    FFLShaderCallback               mCallback;
    GX2Sampler                      mSampler;
    ModelFFL*                       mpModel;
    agl::TextureSampler             mLightmap02p_0;
    agl::TextureSampler             mLightmap02p_1;
    LightParam                      mLightParam;
    Material                        mMaterial[FFL_MODULATE_TYPE_SHAPE_MAX];
    RimParam                        mRimParam;
    SpecularParam                   mSpecularParam;
};
static_assert(sizeof(Shader) == 0x5F0);

}
