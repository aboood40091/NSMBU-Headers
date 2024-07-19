#pragma once

#include <container/seadPtrArray.h>
#include <container/seadTList.h>
#include <heap/seadDisposer.h>
#include <math/seadMatrix.h>

namespace sead { namespace ptcl {

class PtclSystem;

} } // namespace sead::ptcl

namespace nw { namespace eft {

struct  EmitterInstance;
class   EmitterSet;
class   Handle;

} } // namespace nw::eft

namespace agl {

class TextureSampler;

namespace lyr {

class RenderInfo;

} } // namespace agl::lyr

enum    EffectID;
class   EffectDisposable;
class   EffectDisposableBase;
class   PtclEmitterColorMgr;
class   PtclParallelExecuter;
struct  PtclParam;
class   PtclParamMgr;

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
    class PlayerNoSetter
    {
    public:
        PlayerNoSetter(s32 player_no)
            : mPrevPlayerNo(PtclMgr::instance()->mPlayerNo)
        {
            if (0 <= player_no && player_no < 4)
                PtclMgr::instance()->mPlayerNo = player_no;
        }

        ~PlayerNoSetter()
        {
            PtclMgr::instance()->mPlayerNo = mPrevPlayerNo;
        }

    private:
        s32 mPrevPlayerNo;
    };
    static_assert(sizeof(PlayerNoSetter) == 4);

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

    // Address: 0x022AC984
    void updateAmbientLight(bool update_emitter = true);

    // Address: 0x022ACA14
    static s32 compare(const nw::eft::EmitterInstance* a, const nw::eft::EmitterInstance* b);

    // Address: 0x022ACA44
    void draw(const agl::lyr::RenderInfo& render_info, u32 type, const sead::PtrArray<nw::eft::EmitterInstance>* p_emitters = nullptr);

    // Address: 0x022ACE58
    s32 getEmitterSetGroupID(s32 set_id, u32 res_id = 0) const;

    // Address: 0x022ACF0C
    void enterScene(sead::Heap* heap);

    // Address: 0x022AD370
    void enableDisplayList();

    void enableDraw()
    {
        mIsDrawDisable = false;
    }

    // Address: 0x022AD37C
    void pushBackDrawMethod();

    // Address: 0x022AD434
    void exitScene();

    // Address: 0x022ACE84
    void setUserDataCallbacks();
    // Address: 0x022AD468
    void resetUserDataCallbacks();

    // Address: 0x022AD4E0
    void execute();

    // Address: 0x022AD8BC
    void drawMulti(const agl::lyr::RenderInfo& render_info, u32 typeMin, u32 typeMax);

    // Address: 0x022AD948
    bool createEmitterSet(nw::eft::Handle* p_handle, const sead::Matrix34f& mtxRT, EffectID id);

    // Address: 0x022AD930
    const PtclParam* getParam(EffectID id) const;

    // Address: 0x022ADA08
    void setFrameBufferTexture(const agl::TextureSampler& texture, f32 x_offset = 0.0f, f32 y_offset = 0.0f, f32 x_scale = 1.0f, f32 y_scale = 1.0f);

private:
    // Address: 0x022AC8F8
    void setEmitterColor_(nw::eft::EmitterSet* p_emitter_set);

private:
    sead::ptcl::PtclSystem*                             mpPtclSystem;
    PtclParallelExecuter*                               mpParallelExecuter;
    PtclEmitterColorMgr*                                mpEmitterColorMgr;
    PtclParamMgr*                                       mpParamMgr;
    sead::TList<EffectDisposableBase*>                  mEffects;
    sead::FixedPtrArray<nw::eft::EmitterInstance, 256>  mpEmitter1;
    sead::FixedPtrArray<nw::eft::EmitterInstance, 256>  mpEmitter2;
    s32                                                 mPlayerNo;
    bool                                                mIsUseDisplayList;
    bool                                                mIsDrawDisable;
    bool                                                mIsUseParallel;

    friend class EffectDisposable;
};
static_assert(sizeof(PtclMgr) == 0x84C);
