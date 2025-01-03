#pragma once

#include <graphics/BasicModel.h>
#include <graphics/CalcRatio.h>

class BlendModel : public BasicModel
{
    // Actual name of this class is unknown.

public:
    static BlendModel* create(
        ModelResource* p_mdl_res,
        ModelG3d* p_model,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        sead::Heap* heap = nullptr,
        const sead::PtrArray<ModelResource>* p_anim_mdl_res_array = nullptr
    );

    static BlendModel* create(
        ModelResource* p_mdl_res,
        const sead::SafeString& name,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode = Model::cBoundingMode_Disable,
        sead::Heap* heap = nullptr
    );

    static BlendModel* create(
        ModelResource* p_mdl_res,
        const sead::SafeString& name,
        s32 view_num,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode,
        sead::Heap* heap = nullptr
    );

    static BlendModel* create(
        const sead::SafeString& resource_key,
        const sead::SafeString& name,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode = Model::cBoundingMode_Disable,
        sead::Heap* heap = nullptr
    );

    static BlendModel* create(
        const sead::SafeString& resource_key,
        const sead::SafeString& name,
        s32 view_num,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode,
        sead::Heap* heap = nullptr
    );

public:
    // Address: 0x024DFBF0
    BlendModel(ModelG3d* p_model, u32 skl_anim_num, u32 tex_anim_num, u32 shu_anim_num, u32 vis_anim_num, u32 sha_anim_num);

    // Address: 0x024DFC78
    void init(ModelResource* p_mdl_res, const sead::PtrArray<ModelResource>* p_anim_mdl_res_array = nullptr, sead::Heap* heap = nullptr);

    // Address: 0x024dfc7c
    void playAnmFrameCtrl();

    // Address: 0x024DFD04
    void calcMdl();
    // Address: 0x024DFC80
    void calcBlend();

    SkeletalAnimation* getCurSklAnim() const { return getSklAnim(mCurAnmIdx); }

    // Address: 0x024DFF9C
    void setAnm(
        ModelResource* p_mdl_res,
        const sead::SafeString& name,
        f32 blend_duration
    );

    // Address: 0x024DFFB4
    void setAnm(
        const sead::SafeString& name,
        f32 blend_duration,

        FrameCtrl::PlayMode mode = FrameCtrl::cMode_Repeat,
        f32 rate = 1.0f,
        f32 frame = 0.0f
    );

    // Address: 0x024DFFC4
    void setAnm(
        const sead::SafeString& name,

        FrameCtrl::PlayMode mode = FrameCtrl::cMode_Repeat,
        f32 rate = 1.0f,
        f32 frame = 0.0f
    );

private:
    // Address: 0x024DFD38
    void setAnm_(
        ModelResource* p_mdl_res,
        const sead::SafeString& name,
        f32 blend_duration,

        FrameCtrl::PlayMode mode = FrameCtrl::cMode_Repeat,
        f32 rate = 1.0f,
        f32 frame = 0.0f
    );

private:
    CalcRatio   mCalcRatio;
    u32         mCurAnmIdx;
};
static_assert(sizeof(BlendModel) == 0x48);

inline BlendModel* BlendModel::create(
    ModelResource* p_mdl_res,
    ModelG3d* p_model,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    sead::Heap* heap,
    const sead::PtrArray<ModelResource>* p_anim_mdl_res_array
)
{
    BlendModel* p_bmdl = new (heap) BlendModel(p_model, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num);
    p_bmdl->init(p_mdl_res, p_anim_mdl_res_array, heap);
    return p_bmdl;
}

inline BlendModel* BlendModel::create(
    ModelResource* p_mdl_res,
    const sead::SafeString& name,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    Model::BoundingMode bounding_mode,
    sead::Heap* heap
)
{
    ModelG3d* p_model = Model::createG3d(*p_mdl_res, name, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, bounding_mode, heap);
    return create(p_mdl_res, p_model, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, heap);
}

inline BlendModel* BlendModel::create(
    ModelResource* p_mdl_res,
    const sead::SafeString& name,
    s32 view_num,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    Model::BoundingMode bounding_mode,
    sead::Heap* heap
)
{
    ModelG3d* p_model = Model::createG3d(*p_mdl_res, name, view_num, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, bounding_mode, heap);
    return create(p_mdl_res, p_model, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, heap);
}

inline BlendModel* BlendModel::create(
    const sead::SafeString& resource_key,
    const sead::SafeString& name,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    Model::BoundingMode bounding_mode,
    sead::Heap* heap
)
{
    ModelResource* p_mdl_res = ModelResourceMgr::instance()->getResource(resource_key);
    return create(p_mdl_res, name, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, bounding_mode, heap);
}

inline BlendModel* BlendModel::create(
    const sead::SafeString& resource_key,
    const sead::SafeString& name,
    s32 view_num,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    Model::BoundingMode bounding_mode,
    sead::Heap* heap
)
{
    ModelResource* p_mdl_res = ModelResourceMgr::instance()->getResource(resource_key);
    return create(p_mdl_res, name, view_num, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, bounding_mode, heap);
}
