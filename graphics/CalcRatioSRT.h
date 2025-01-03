#pragma once

#include <container/seadBuffer.h>
#include <math/seadMatrix.h>
#include <prim/seadBitFlag.h>

class Model;

class CalcRatioSRT
{
public:
    // Address: 0x024D4FB8
    CalcRatioSRT(s32 bone_num_max);
    // Address: 0x024D5210
    virtual ~CalcRatioSRT();

    // Address: 0x024D5248
    void set(f32 duration);
    // Address: 0x024D5224
    void reset();

    // Address: 0x024D5288
    void calc();

    // Address: 0x024D5354
    void applyTo(sead::Matrixf* p_bone_rt, sead::Vector3f* p_bone_scale, s32 bone_index);
    // Address: 0x024D5710
    void applyTo(Model* p_model);

    // Address: 0x024D56FC
    void offUpdate();

    // Address: 0x024D52FC
    bool isFramesPrepared() const;

    // Address: 0x024D532C
    bool isBlendDisable(s32 bone_index) const;
    // Address: 0x024D57DC
    void setBlendDisable(s32 bone_index);

private:
    sead::Buffer<sead::Vector3f>    mBoneTrans;
    sead::Buffer<sead::Quatf>       mBoneRot;
    sead::Buffer<sead::Vector3f>    mBoneScale;
    sead::Buffer<sead::BitFlag32>   mBoneFlag;
    s32                             mBoneNumMax;
    f32                             _24;
    f32                             mCounter;
    f32                             mInvDuration;
    f32                             mRatioA;    // Source
    f32                             mRatioB;    // Target
    bool                            mIsFramesPrepared;
    bool                            mIsActive;
};
static_assert(sizeof(CalcRatioSRT) == 0x40);
