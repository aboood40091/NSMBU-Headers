#pragma once

#include <common/aglUniformBlock.h>
#include <container/seadBuffer.h>
#include <math/seadMatrix.h>

namespace agl { namespace env {

class EnvObjSet;

} }

class ModelEnvView
{
public:
    struct Member
    {
        agl::UniformBlock::Type type;
        s32                     num;
    };
    static_assert(sizeof(Member) == 8);

    enum MemberIndex
    {
        cMemberIndex_View = 0,
        cMemberIndex_ViewProj,
        cMemberIndex_LightDiffDir,
        cMemberIndex_LightDiffColor,
        cMemberIndex_AmbColor,
        cMemberIndex_FogColor,
        cMemberIndex_FogStart,
        cMemberIndex_FogStartEndInv,
        cMemberIndex_ShadowMtx,
        cMemberIndex_FogDir,
        cMemberIndex_TexProjMtx,
        cMemberNum
    };
    static_assert(cMemberNum == 11);

    // Address: 0x100BCB70
    static const Member cMember[cMemberNum];

    static const s32 cLightObjMax = 8;
    static const s32 cChannelMax = 2;
    static const s32 cFogMax = 8;

public:
    // Address: 0x024EE6C8
    ModelEnvView();
    ~ModelEnvView() {}

    // Address: 0x024EE8A0
    void setUniformData(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx,
                        const sead::Matrix44f* p_depth_shadow_mtx, const agl::env::EnvObjSet* p_env_obj_set, void* p_reflection_fog);

    s32 getViewNum() const { return mViewNum; }
    const agl::UniformBlock& getUniformBlock(s32 view_index) const { return mUniformBlock[view_index]; }

private:
    s32                             mViewNum;
    sead::Buffer<agl::UniformBlock> mUniformBlock;
};
static_assert(sizeof(ModelEnvView) == 0xC);
