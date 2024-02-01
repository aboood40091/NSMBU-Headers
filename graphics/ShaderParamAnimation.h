#pragma once

#include <graphics/Animation.h>

#include <container/seadPtrArray.h>
#include <heap/seadHeap.h>
#include <prim/seadSafeString.h>

#include <nw/g3d/g3d_ShaderParamAnimObj.h>

class ModelG3d;
class ModelResource;

class ShaderParamAnimation : public Animation
{
public:
    ShaderParamAnimation();

    bool init(const ModelG3d* model, const ModelResource* mdl_res, const sead::PtrArray<ModelResource>* anim_mdl_res_array, sead::Heap* heap);

    bool isValid() const { return mRes && mModel; }

    void bindModel(const ModelG3d* model, s32 index);
    void unbindModel();

private:
    void bindAnimObj_();

public:
    void playColorAnim(const ModelResource* mdl_res, const sead::SafeString& name);
    void playTexSrtAnim(const ModelResource* mdl_res, const sead::SafeString& name);

    void calc() override;

    nw::g3d::ShaderParamAnimObj& getAnimObj() { return mAnimObj; }
    const nw::g3d::ShaderParamAnimObj& getAnimObj() const { return mAnimObj; }

    nw::g3d::res::ResShaderParamAnim* getResource() const { return mRes; }

    const ModelG3d* getModel() const { return mModel; }
    s32 getIndex() const { return mIndex; }

private:
    static void updateInitArg_(nw::g3d::ShaderParamAnimObj::InitArg* arg, const ModelResource* mdl_res);

private:
    nw::g3d::ShaderParamAnimObj         mAnimObj;
    nw::g3d::res::ResShaderParamAnim*   mRes;
    const ModelG3d*                     mModel;
    s32                                 mIndex;
    void*                               mBuffer;
};
static_assert(sizeof(ShaderParamAnimation) == 0x88);
