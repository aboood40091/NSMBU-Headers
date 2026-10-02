#pragma once

#include <graphics/Animation.h>

#include <container/seadPtrArray.h>
#include <heap/seadHeap.h>
#include <prim/seadSafeString.h>

#include <nw/g3d/g3d_SkeletalAnimObj.h>

class ModelG3d;
class ModelResource;

class SkeletalAnimation : public Animation  // vtbl Address: 0x100BDF44
{
public:
    // Address: 0x024FD7E8
    SkeletalAnimation();

    // Address: 0x024FD948
    bool init(const ModelG3d* p_model, const ModelResource* p_mdl_res, const sead::PtrArray<ModelResource>* p_anim_mdl_res_array, sead::Heap* heap);

    bool isValid() const { return mpRes && mpModel; }

    // Address: 0x024FDA98
    void bindModel(const ModelG3d* p_model, s32 index);
    // Address: 0x024FDA64
    void unbindModel();

private:
    // Address: 0x024FDA78
    void bindAnimObj_();

public:
    // Address: 0x024FDADC
    void play(const ModelResource* p_mdl_res, const sead::SafeString& name);

    // Address: 0x024FDC64
    void unbindTarget(s32 idx_target);

    // Address: 0x024FDCB4
    void disableBindFlag();
    // Address: 0x024FDCF8
    void enableBindFlag(s32 idx_bone);

    // Address: 0x024FDD1C
    void calc() override;

    nw::g3d::SkeletalAnimObj& getAnimObj() { return mAnimObj; }
    const nw::g3d::SkeletalAnimObj& getAnimObj() const { return mAnimObj; }

    nw::g3d::res::ResSkeletalAnim* getResource() const { return mpRes; }

    const ModelG3d* getModel() const { return mpModel; }
    s32 getIndex() const { return mIndex; }

private:
    // Address: 0x024FD86C
    static void updateInitArg_(nw::g3d::SkeletalAnimObj::InitArg* p_arg, const ModelResource* p_mdl_res);

private:
    nw::g3d::SkeletalAnimObj        mAnimObj;
    void*                           mpBuffer;
    const ModelG3d*                 mpModel;
    s32                             mIndex;
    nw::g3d::res::ResSkeletalAnim*  mpRes;
};
static_assert(sizeof(SkeletalAnimation) == 0x98);
