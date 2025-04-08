#pragma once

#include <graphics/Model.h>
#include <graphics/ModelResourceMgr.h>

#include <container/seadBuffer.h>
#include <container/seadPtrArray.h>
#include <heap/seadHeap.h>

class ModelG3d;
class ModelResource;
class ShaderParamAnimation;
class ShapeAnimation;
class SkeletalAnimation;
class TexturePatternAnimation;
class VisibilityAnimation;

class AnimModel
{
public:
    static AnimModel* create(
        ModelResource* p_mdl_res,
        ModelG3d* p_model,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        sead::Heap* heap = nullptr,
        const sead::PtrArray<ModelResource>* p_anim_mdl_res_array = nullptr
    );

    static AnimModel* create(
        ModelResource* p_mdl_res,
        const sead::SafeString& name,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode = Model::cBoundingMode_Disable,
        sead::Heap* heap = nullptr
    );

    static AnimModel* create(
        ModelResource* p_mdl_res,
        const sead::SafeString& name,
        s32 view_num,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode,
        sead::Heap* heap = nullptr
    );

    static AnimModel* create(
        const sead::SafeString& resource_key,
        const sead::SafeString& name,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode = Model::cBoundingMode_Disable,
        sead::Heap* heap = nullptr
    );

    static AnimModel* create(
        const sead::SafeString& resource_key,
        const sead::SafeString& name,
        s32 view_num,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode,
        sead::Heap* heap = nullptr
    );

public:
    // Address: 0x024D4798
    AnimModel(ModelG3d* p_model, u32 skl_anim_num, u32 tex_anim_num, u32 shu_anim_num, u32 vis_anim_num, u32 sha_anim_num);

    ModelG3d* getModel() const { return mpModel; }
    ModelResource* getModelResource() const { return mpModelResource; }

    SkeletalAnimation*          getSklAnim(s32 index) const { return mpSklAnim[index]; }
    TexturePatternAnimation*    getTexAnim(s32 index) const { return mpTexAnim[index]; }
    ShaderParamAnimation*       getShuAnim(s32 index) const { return mpShuAnim[index]; }
    VisibilityAnimation*        getVisAnim(s32 index) const { return mpVisAnim[index]; }
    ShapeAnimation*             getShaAnim(s32 index) const { return mpShaAnim[index]; }

    // Address: 0x024D49A0
    void init(ModelResource* p_mdl_res, const sead::PtrArray<ModelResource>* p_anim_mdl_res_array = nullptr, sead::Heap* heap = nullptr);

    // Address: 0x024D4D20
    void playAnmFrameCtrl();

    // Address: 0x024D4E84
    void calcMdl();

private:
    ModelG3d*                               mpModel;
    ModelResource*                          mpModelResource;
    sead::Buffer<SkeletalAnimation*>        mpSklAnim;
    sead::Buffer<TexturePatternAnimation*>  mpTexAnim;
    sead::Buffer<ShaderParamAnimation*>     mpShuAnim;
    sead::Buffer<VisibilityAnimation*>      mpVisAnim;
    sead::Buffer<ShapeAnimation*>           mpShaAnim;
};
static_assert(sizeof(AnimModel) == 0x30);

inline AnimModel* AnimModel::create(
    ModelResource* p_mdl_res,
    ModelG3d* p_model,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    sead::Heap* heap,
    const sead::PtrArray<ModelResource>* p_anim_mdl_res_array
)
{
    AnimModel* p_anim_model = new (heap) AnimModel(p_model, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num);
    p_anim_model->init(p_mdl_res, p_anim_mdl_res_array, heap);
    return p_anim_model;
}

inline AnimModel* AnimModel::create(
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

inline AnimModel* AnimModel::create(
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

inline AnimModel* AnimModel::create(
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

inline AnimModel* AnimModel::create(
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
