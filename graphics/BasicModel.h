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

class BasicModel
{
public:
    static BasicModel* create(
        ModelResource* mdl_res,
        ModelG3d* model,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        sead::Heap* heap = nullptr,
        const sead::PtrArray<ModelResource>* anim_mdl_res_array = nullptr
    );

    static BasicModel* create(
        ModelResource* mdl_res,
        const sead::SafeString& name,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode = Model::cBoundingMode_Disable,
        sead::Heap* heap = nullptr
    );

    static BasicModel* create(
        ModelResource* mdl_res,
        const sead::SafeString& name,
        s32 view_num,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode,
        sead::Heap* heap = nullptr
    );

    static BasicModel* create(
        const sead::SafeString& resource_key,
        const sead::SafeString& name,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode = Model::cBoundingMode_Disable,
        sead::Heap* heap = nullptr
    );

    static BasicModel* create(
        const sead::SafeString& resource_key,
        const sead::SafeString& name,
        s32 view_num,
        s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
        Model::BoundingMode bounding_mode,
        sead::Heap* heap = nullptr
    );

public:
    // Address: 0x024D4798
    BasicModel(ModelG3d* model, u32 skl_anim_num, u32 tex_anim_num, u32 shu_anim_num, u32 vis_anim_num, u32 sha_anim_num);

    ModelG3d* getModel() const { return mModel; }
    ModelResource* getModelResource() const { return mModelResource; }

    SkeletalAnimation*          getSklAnim(s32 index) const { return mSklAnim[index]; }
    TexturePatternAnimation*    getTexAnim(s32 index) const { return mTexAnim[index]; }
    ShaderParamAnimation*       getShuAnim(s32 index) const { return mShuAnim[index]; }
    VisibilityAnimation*        getVisAnim(s32 index) const { return mVisAnim[index]; }
    ShapeAnimation*             getShaAnim(s32 index) const { return mShaAnim[index]; }

    // Address: 0x024D49A0
    void init(ModelResource* mdl_res, const sead::PtrArray<ModelResource>* anim_mdl_res_array = nullptr, sead::Heap* heap = nullptr);

    // Address: 0x024D4D20
    void playAnmFrameCtrl();

    // Address: 0x024D4E84
    void calcMdl();

private:
    ModelG3d*                               mModel;
    ModelResource*                          mModelResource;
    sead::Buffer<SkeletalAnimation*>        mSklAnim;
    sead::Buffer<TexturePatternAnimation*>  mTexAnim;
    sead::Buffer<ShaderParamAnimation*>     mShuAnim;
    sead::Buffer<VisibilityAnimation*>      mVisAnim;
    sead::Buffer<ShapeAnimation*>           mShaAnim;
};
static_assert(sizeof(BasicModel) == 0x30);

inline BasicModel* BasicModel::create(
    ModelResource* mdl_res,
    ModelG3d* model,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    sead::Heap* heap,
    const sead::PtrArray<ModelResource>* anim_mdl_res_array
)
{
    BasicModel* bmdl = new (heap) BasicModel(model, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num);
    bmdl->init(mdl_res, anim_mdl_res_array, heap);
    return bmdl;
}

inline BasicModel* BasicModel::create(
    ModelResource* mdl_res,
    const sead::SafeString& name,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    Model::BoundingMode bounding_mode,
    sead::Heap* heap
)
{
    ModelG3d* model = Model::createG3d(*mdl_res, name, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, bounding_mode, heap);
    return create(mdl_res, model, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, heap);
}

inline BasicModel* BasicModel::create(
    ModelResource* mdl_res,
    const sead::SafeString& name,
    s32 view_num,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    Model::BoundingMode bounding_mode,
    sead::Heap* heap
)
{
    ModelG3d* model = Model::createG3d(*mdl_res, name, view_num, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, bounding_mode, heap);
    return create(mdl_res, model, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, heap);
}

inline BasicModel* BasicModel::create(
    const sead::SafeString& resource_key,
    const sead::SafeString& name,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    Model::BoundingMode bounding_mode,
    sead::Heap* heap
)
{
    ModelResource* mdl_res = ModelResourceMgr::instance()->getResource(resource_key);
    return create(mdl_res, name, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, bounding_mode, heap);
}

inline BasicModel* BasicModel::create(
    const sead::SafeString& resource_key,
    const sead::SafeString& name,
    s32 view_num,
    s32 skl_anim_num, s32 tex_anim_num, s32 shu_anim_num, s32 vis_anim_num, s32 sha_anim_num,
    Model::BoundingMode bounding_mode,
    sead::Heap* heap
)
{
    ModelResource* mdl_res = ModelResourceMgr::instance()->getResource(resource_key);
    return create(mdl_res, name, view_num, skl_anim_num, tex_anim_num, shu_anim_num, vis_anim_num, sha_anim_num, bounding_mode, heap);
}
