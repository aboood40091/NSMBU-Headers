#pragma once

#include <graphics/LightMapMgr.h>
#include <graphics/MaterialG3d.h>
#include <graphics/Model.h>
#include <graphics/ShaderParamAnimation.h>
#include <graphics/ShapeAnimation.h>
#include <graphics/SkeletalAnimation.h>
#include <graphics/TexturePatternAnimation.h>
#include <graphics/VisibilityAnimation.h>

#include <common/aglDisplayList.h>
#include <common/aglShaderProgramArchive.h>
#include <common/aglUniformBlock.h>
#include <container/seadBuffer.h>
#include <container/seadPtrArray.h>
#include <container/seadSafeArray.h>
#include <g3d/aglModelEx.h>
#include <math/seadBoundBox.h>

#include <nw/g3d/g3d_SkeletalAnimObj.h>
#include <nw/g3d/g3d_ShapeObj.h>

class CullViewFrustum;

class ModelG3d : public Model    // vtbl Address: 0x100BCF30
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9F78
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FA0
    SEAD_RTTI_OVERRIDE(ModelG3d, Model)

public:
    struct ShaderAssign
    {
        void initialize(const agl::ShaderProgram* p_shader_program)
        {
            this->p_shader_program = p_shader_program;

            env_location.setName("MdlEnvView");
            mtx_location.setName("MdlMtx");
            shp_location.setName("Shp");
            mat_location.setName("Mat");
            sdw_location.setName("cShadowMap");
            rfl_location.setName("cReflectionMap");

            updateLocation();
        }

        void updateLocation()
        {
            if (p_shader_program)
            {
                env_location.search(*p_shader_program);
                mtx_location.search(*p_shader_program);
                shp_location.search(*p_shader_program);
                mat_location.search(*p_shader_program);
                sdw_location.search(*p_shader_program);
                rfl_location.search(*p_shader_program);
            }
        }

        const agl::ShaderProgram*   p_shader_program;
        agl::UniformBlockLocation   env_location;
        agl::UniformBlockLocation   mtx_location;
        agl::UniformBlockLocation   shp_location;
        agl::UniformBlockLocation   mat_location;
        agl::SamplerLocation        sdw_location;
        agl::SamplerLocation        rfl_location;
    };
    static_assert(sizeof(ShaderAssign) == 0x64);

    struct ShapeRenderInfo
    {
        s32                         idx_shape;
        s32                         priority;
        sead::BitFlag32             flag;
        s32                         polygon_offset;
        mutable agl::DisplayList    attrib_dl;
        mutable agl::DisplayList    mat_dl;
    };
    static_assert(sizeof(ShapeRenderInfo) == 0x30);

    struct LightMap
    {
        void clear()
        {
            sead::MemUtil::fill(idx_lghtmap, u8(-1), sizeof(idx_lghtmap));
            sead::MemUtil::fill(idx_sampler, u8(-1), sizeof(idx_sampler));
        }

        s32 idx_lghtmap[LightMapMgr::cLightMapNum];
        s32 idx_sampler[LightMapMgr::cLightMapNum];
    };
    static_assert(sizeof(LightMap) == 0x10);

    struct Shape
    {
        agl::UniformBlock                       uniform_block; // Shp
        LightMap                                light_map;
        sead::Buffer<nw::g3d::fnd::GfxBuffer>   vtx_buffer;
    };
    static_assert(sizeof(Shape) == 0x2C);

    struct DrawInfo
    {
        s32                         view_index;
        const sead::Matrix34f*      p_view_mtx;
        const sead::Matrix44f*      p_proj_mtx;
        const agl::ShaderProgram*   p_shader_program;
        ShaderAssign*               p_shader_assign;
        s32                         material_index;
        bool                        draw_shape;
        bool                        draw_reflection;
        agl::ShaderMode             shader_mode;
        s32                         polygon_offset;
        const CullViewFrustum*      p_cull;
    };
    static_assert(sizeof(DrawInfo) == 0x28);

    enum SamplerSlot
    {
        cSamplerSlot_LightMap_0 = 12,
        cSamplerSlot_ReflectionMap = cSamplerSlot_LightMap_0 + LightMapMgr::cLightMapNum,
        cSamplerSlot_ShadowMap
    };
    static_assert(cSamplerSlot_ReflectionMap == 14);

private:
    class BoundingFlagArray
    {
    public:
        BoundingFlagArray()
        {
            resetAll();
        }

        void set(s32 index, bool enable)
        {
            if (index >= 32*10)
                return;

            if (enable)
                mBuffer[index >> 5] |= 1 << (index & 0x1f);
            else
                mBuffer[index >> 5] &= ~(1 << (index & 0x1f));
        }

        bool get(s32 index) const
        {
            return mBuffer[index >> 5] & 1 << (index & 0x1f);
        }

        bool any() const
        {
            for (s32 i = 0; i < 10; i++)
                if (mBuffer[i] != 0)
                    return true;

            return false;
        }

        void setAll()
        {
            // ???
            sead::MemUtil::fill(mBuffer.getBufferPtr(), u8(-1), sizeof(sead::BitFlag32) * 9);
            // ??????
            mBuffer[9] = u32(-1);
        }

        void resetAll()
        {
            sead::MemUtil::fillZero(mBuffer.getBufferPtr(), sizeof(mBuffer));
        }

    private:
        sead::UnsafeArray<u32, 10>  mBuffer;
    };
    static_assert(sizeof(BoundingFlagArray) == 0x28);

public:
    // Address: 0x024F301C
    // Calculates the drawing resources for skeleton matrices, shapes and materials
    void calc() override;

    // Address: 0x024F30DC
    // Updates buffers for the GPU
    void calcGPU(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;

    // (Does nothing)
    void updateView(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override
    {
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Notes:
    // 1. Shadow-only shapes and reflection-only shapes are always invisible
    // 2. Shadow casting for a shape is automatically enabled if "shadow_cast" is not present in its material's render info

    // Address: 0x024F3884
    void drawOpa(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;
    // Address: 0x024F398C
    void drawXlu(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;

    // Address: 0x024F3A94
    // This draws the shadow of shadow-casting shapes
    void drawShadowOpa(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;

    // These draws the reflection on shapes
    // Address: 0x024F3D64
    void drawReflectionOpa(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;
    // Address: 0x024F3E6C
    void drawReflectionXlu(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool hasShadow() const override
    {
        return mShapeFlag.isOn(4);
    }

public:
    // Address: 0x024F0800
    ModelG3d();
    // Address: 0x024F078C
    virtual ~ModelG3d();

    // Address: 0x024F4094
    void calcAnm() override;
    // Address: 0x024F4518
    void calcMdl() override;

    // Rotation + Translation matrix
    void setMtxRT(const sead::Matrix34f& rt) override
    {
        mMtxRT = rt;
        mBoundingEnableFlag.set(1 << 1);
    }

    const sead::Matrix34f& getMtxRT() const override
    {
        return mMtxRT;
    }

    void setScale(const sead::Vector3f& scale) override
    {
        mScale = scale;
        mBoundingEnableFlag.set(1 << 1);
    }

    const sead::Vector3f& getScale() const override
    {
        return mScale;
    }

    // Address: 0x024F3F74
    // Determines if there are any shapes that can be drawn by draw*Opa()
    bool hasOpa() const override;
    // Address: 0x024F3FD0
    // Determines if there are any shapes that can be drawn by draw*Xlu()
    bool hasXlu() const override;

    // Address: 0x024F476C
    s32 searchBoneIndex(const sead::SafeString& name) const override;
    // Address: 0x024F47D8
    const char* getBoneName(s32 index) const override;
    // Address: 0x024F4820
    u32 getBoneNum() const override;

    // Address: 0x024F4628
    void setBoneLocalMatrix(s32 index, const sead::Matrix34f& rt, const sead::Vector3f& scale) override;
    // Address: 0x024F46A4
    void getBoneLocalMatrix(s32 index, sead::Matrix34f* rt = nullptr, sead::Vector3f* scale = nullptr) const override;

    // Address: 0x024F4724
    void setBoneWorldMatrix(s32 index, const sead::Matrix34f& mtx) override;
    // Address: 0x024F4748
    void getBoneWorldMatrix(s32 index, sead::Matrix34f* mtx) const override;

    // Address: 0x024F4B3C
    void setBoneVisible(s32 index, bool visible) override;
    // Address: Deleted
    bool isBoneVisible(s32 index) const override;

    // Address: 0x024F4A54
    u32 getMaterialNum() const override;
    // Address: 0x024F4A5C
    s32 searchMaterialIndex(const sead::SafeString& name) const override;
    // Address: 0x024F4AC8
    const char* getMaterialName(s32 index) const override;

    Material* getMaterial(s32 index) const override
    {
        return mpMaterial[index];
    }

    // Address: 0x024F4B0C
    void setMaterialVisible(s32 index, bool visible) override;
    // Address: Deleted
    bool isMaterialVisible(s32 index) const override;

    void setBoundingEnable(bool enable) override // deleted
    {
        mBoundingEnableFlag.change(1 << 0, enable);
    }

    bool isBoundingEnable() const override
    {
        return mBoundingEnableFlag.isOn(1 << 0);
    }

    const sead::Sphere3f& getBounding() const override
    {
        return mBounding;
    }

    // Address: 0x024F4B6C
    void calcViewShapeShadowFlags(agl::sdw::DepthShadow* p_depth_shadow, RenderObjLayerBase* p_shadow_layer, RenderMgr* p_render_mgr) override;

    sead::SafeString getName() const override
    {
        return mModelEx.GetResource()->GetName();
    }

    void setSklAnimBlendWeight(s32 index, f32 weight) override
    {
        mSklAnimBlendWeight[index] = weight;
    }

    f32 getSklAnimBlendWeight(s32 index) const override // deleted
    {
        return mSklAnimBlendWeight[index];
    }

    // Address: 0x024F4830
    void setSklAnim(s32 index, Animation* anim) override;
    // Address: 0x024F489C
    void setTexAnim(s32 index, Animation* anim) override;
    // Address: 0x024F4910
    void setShuAnim(s32 index, Animation* anim) override;
    // Address: 0x024F497C
    void setVisAnim(s32 index, Animation* anim) override;
    // Address: 0x024F49E8
    void setShaAnim(s32 index, Animation* anim) override;

private:
    Animation* const* getSklAnims() const override
    {
        return reinterpret_cast<Animation* const*>(mpSklAnim.getBufferPtr());
    }

    Animation* const* getTexAnims() const override
    {
        return reinterpret_cast<Animation* const*>(mpTexAnim.getBufferPtr());
    }

    Animation* const* getShuAnims() const override
    {
        return reinterpret_cast<Animation* const*>(mpShuAnim.getBufferPtr());
    }

    Animation* const* getVisAnims() const override
    {
        return reinterpret_cast<Animation* const*>(mpVisAnim.getBufferPtr());
    }

    Animation* const* getShaAnims() const override
    {
        return reinterpret_cast<Animation* const*>(mpShaAnim.getBufferPtr());
    }

public:
    SkeletalAnimation** getSklAnimBuffer()
    {
        return const_cast<SkeletalAnimation**>(reinterpret_cast<SkeletalAnimation* const*>(getSklAnims()));
    }

    TexturePatternAnimation** getTexAnimBuffer()
    {
        return const_cast<TexturePatternAnimation**>(reinterpret_cast<TexturePatternAnimation* const*>(getTexAnims()));
    }

    ShaderParamAnimation** getShuAnimBuffer()
    {
        return const_cast<ShaderParamAnimation**>(reinterpret_cast<ShaderParamAnimation* const*>(getShuAnims()));
    }

    VisibilityAnimation** getVisAnimBuffer()
    {
        return const_cast<VisibilityAnimation**>(reinterpret_cast<VisibilityAnimation* const*>(getVisAnims()));
    }

    ShapeAnimation** getShaAnimBuffer()
    {
        return const_cast<ShapeAnimation**>(reinterpret_cast<ShapeAnimation* const*>(getShaAnims()));
    }

public:
    // Address: 0x024F1860
    void initialize(nw::g3d::res::ResModel* res_model, const agl::ShaderProgramArchive* shader_archive, s32 num_view, s32 num_skl_anim, s32 num_tex_anim, s32 num_shu_anim, s32 num_vis_anim, s32 num_sha_anim, BoundingMode bounding_mode, sead::Heap* heap);

    agl::g3d::ModelEx& getModelEx() { return mModelEx; }
    const agl::g3d::ModelEx& getModelEx() const { return mModelEx; }

    Shape& getShape(s32 index) { return mShape[index]; }
    const Shape& getShape(s32 index) const { return mShape[index]; }

    sead::BitFlag32& getRenderFlag() { return mRenderFlag; }
    const sead::BitFlag32& getRenderFlag() const { return mRenderFlag; }

    // Address: 0x024F0FE0
    void activateMaterial(const agl::g3d::ModelShaderAssign& shader_assign, const nw::g3d::MaterialObj* p_material, const LightMap& light_map) const;

    // Address: 0x024F50D8
    void setDisplayListDirty();

private:
    // Address: 0x024F0B70
    void createViewShapeShadowFlagBuffer_(s32 num_view, sead::Heap* heap);
    // Address: 0x024F1098
    void initializeShapeRenderInfo_(ShapeRenderInfo& render_info, const nw::g3d::MaterialObj* p_material, const nw::g3d::ShapeObj* p_shape);
    // Address: 0x024F1850
    static s32 sortShapeRenderInfoCmp(const ShapeRenderInfo* a, const ShapeRenderInfo* b);
    // Address: 0x024F0C9C
    void calcBounding_();
    // Address: 0x024F2CEC
    void applyBlendWeight_(s32 shape_index);
    // Address: 0x024F402C
    static void setBoundingFlagArray_(BoundingFlagArray& flag_array, const SkeletalAnimation& anim);

    // Address: 0x024F37B4
    void drawOpa_(DrawInfo& draw_info, const RenderMgr* p_render_mgr) const;
    // Address: 0x024F381C
    void drawXlu_(DrawInfo& draw_info, const RenderMgr* p_render_mgr) const;

    // Address: 0x024F30E8
    void drawShape_(DrawInfo& draw_info, const ShapeRenderInfo& render_info, const RenderMgr* p_render_mgr) const;

private:
    agl::g3d::ModelEx                               mModelEx;
    nw::g3d::SkeletalAnimBlender                    mSklAnimBlender;
    sead::Buffer<SkeletalAnimation*>                mpSklAnim;
    sead::Buffer<TexturePatternAnimation*>          mpTexAnim;
    sead::Buffer<ShaderParamAnimation*>             mpShuAnim;
    sead::Buffer<VisibilityAnimation*>              mpVisAnim;
    sead::Buffer<ShapeAnimation*>                   mpShaAnim;
    void*                                           mpBuffer;
    void*                                           mpBlockBuffer;
    size_t                                          mBlockBufferSize;
    void*                                           mpSklAnimBlenderBuffer;
    sead::Buffer<f32>                               mSklAnimBlendWeight;
    sead::PtrArray<ShapeRenderInfo>                 mOpaShapeInfo;
    sead::PtrArray<ShapeRenderInfo>                 mXluShapeInfo;
    sead::Buffer<ShaderAssign>                      mShaderAssign;
    sead::Buffer<MaterialG3d*>                      mpMaterial;
    sead::Buffer<Shape>                             mShape;
    sead::Matrix34f                                 mMtxRT;
    sead::Vector3f                                  mScale;
    u8                                              _128;
    sead::BitFlag32                                 mRenderFlag;
    sead::BitFlag32                                 mBoundingEnableFlag;
    sead::Buffer< sead::Buffer<sead::BitFlag32> >   mViewShapeShadowFlagBuffer;
    sead::Sphere3f                                  mBounding;
    sead::BoundBox3f*                               mpSubBounding;
    sead::BitFlag32                                 mShapeFlag;                 // & 4: a shape has shadow cast, & 2: a shape has reflection, & 1: a shape is visible
    BoundingFlagArray                               mBoundingFlagArray;
    BoundingFlagArray                               mSubBoundingFlagArray;
    sead::BitFlag32                                 mViewDepthShadowEnableFlag;
    bool                                            mDisplayListDirty;
};
static_assert(sizeof(ModelG3d) == 0x1AC);
