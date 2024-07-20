#pragma once

#include <ptcl/seadPtclSystem.h>

class PtclUserShaderCallback
{
protected:
    enum AreaLoopShaderParam
    {
        cAreaLoopShaderParam_RepeatNum      = 0,
        cAreaLoopShaderParam_BoxScaleX,
        cAreaLoopShaderParam_BoxScaleY,
        cAreaLoopShaderParam_BoxScaleZ,
        cAreaLoopShaderParam_BoxAlphaRatioX,
        cAreaLoopShaderParam_BoxAlphaRatioY,
        cAreaLoopShaderParam_BoxAlphaRatioZ
    };

    struct AreaLoopShaderVtxUniform
    {
        sead::Vector4f  vec0;
        sead::Vector4f  vec1;
        sead::Vector4f  vec2;
        sead::Vector4f  vec3;
        sead::Vector4f  vec4;
    };
    static_assert(sizeof(AreaLoopShaderVtxUniform) == 0x50);

    // Address: 0x022AF678
    static void setAreaLoopRepeatNum_(s32 data_idx, s32 rep_num);
    // Address: 0x022AF68C
    static s32 getAreaLoopRepeatNum_(s32 data_idx);

    // Address: 0x022AF6A0
    static f32 getRand_(u32& seed);

public:
    // Address: 0x022AF710
    static void areaLoopDrawOverrideCallback(nw::eft::ShaderDrawOverrideArg& arg);
    // Address: 0x022AF7F0
    static void areaLoopRenderStateSetCallback(nw::eft::RenderStateSetArg& arg);
};
