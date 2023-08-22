#pragma once

#include <container/seadPtrArray.h>
#include <container/seadTList.h>
#include <heap/seadDisposer.h>

namespace sead { namespace ptcl {

class PtclSystem;

} } // namespace sead::ptcl

namespace nw { namespace eft {

struct EmitterInstance;

} } // namespace nw::eft

namespace agl {

class TextureSampler;

namespace lyr {

class RenderInfo;

} } // namespace agl::lyr

class LevelEffect;
class PtclEmitterColorMgr;

class PtclMgr
{
    // createInstance()                             Address: 0x022AC738
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101CD3A8
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x022ADADC
    // SingletonDisposer_::sStaticDisposer          Address: 0x101CD3AC
    // SingletonDisposer_::vtbl                     Address: 0x10058B48
    SEAD_SINGLETON_DISPOSER(PtclMgr)

public:
    // Address: 0x022AC634
    PtclMgr();
    // Address: 0x022AC854
    ~PtclMgr();

    // Address: 0x022AC7B8
    void cleanUp();

    sead::ptcl::PtclSystem* getPtclSystem()
    {
        return mpPtclSystem;
    }

    // Address: 0x022ACA44
    void draw(const agl::lyr::RenderInfo& render_info, u32 type, const sead::PtrArray<nw::eft::EmitterInstance>* p_emitters = nullptr);

    // Address: 0x022ACE58
    u8 getEmitterSetGroupID(s32 set_id, u32 res_id = 0) const;

    // Address: 0x022ADA08
    void setFrameBufferTexture(const agl::TextureSampler& texture, f32 x_offset = 0.0f, f32 y_offset = 0.0f, f32 x_scale = 1.0f, f32 y_scale = 1.0f);

private:
    sead::ptcl::PtclSystem*                             mpPtclSystem;
    void*                                               mpPtclParallelTbl;
    PtclEmitterColorMgr*                                mpEmitterColorMgr;
    void*                                               mpUserShaderParamTbl;
    sead::TList<LevelEffect*>                           mEffects;
    sead::FixedPtrArray<nw::eft::EmitterInstance, 256>  mpEmitter1;
    sead::FixedPtrArray<nw::eft::EmitterInstance, 256>  mpEmitter2;
    s32                                                 mPlayerId;
    bool                                                mIsUseDisplayList;
    bool                                                mIsDrawDisable;
    bool                                                mIsUseParallel;
};
static_assert(sizeof(PtclMgr) == 0x84C);
