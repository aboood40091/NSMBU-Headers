#pragma once

#include <graphics/RenderMgr.h>

#include <common/aglRenderBuffer.h>
#include <common/aglRenderTarget.h>
#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <utility/aglDebugTexturePage.h>

class BgTexMgr
{
    // createInstance()                             Address: 0x0269383C
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101DB014
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x02694EE4
    // SingletonDisposer_::sStaticDisposer          Address: 0x101DB018
    // SingletonDisposer_::vtbl                     Address: 0x100E5BFC
    SEAD_SINGLETON_DISPOSER(BgTexMgr)

private:
    class RenderCallback : public RenderMgr::CallbackBase
    {
    public:
        void preDrawOpa(s32 view_index, s32 buffer_index, const agl::lyr::RenderInfo& render_info) override;
        void preDrawXlu(s32 view_index, s32 buffer_index, const agl::lyr::RenderInfo& render_info) override;
        void postDrawOpa(s32 view_index, s32 buffer_index, const agl::lyr::RenderInfo& render_info) override;
        void postDrawXlu(s32 view_index, s32 buffer_index, const agl::lyr::RenderInfo& render_info) override;
    };
    static_assert(sizeof(RenderCallback) == 4);

    struct AnimeParam
    {
        bool    playing;
        bool    reverse;
        u32*    p_frame_delays;
        u32     frame_max;
        u32     frame;
        u32     delay_timer;
    };
    static_assert(sizeof(AnimeParam) == 0x14);

    enum PaType
    {
        cPaType_Sub = 0,
        cPaType_Main
    };
    static_assert(sizeof(PaType) == 4);

public:
    // Address: 0x02693668
    BgTexMgr();
    // Address: 0x026938BC
    ~BgTexMgr();

    const agl::RenderBuffer& getTexRenderBuffer() const
    {
        return mTexRenderBuffer;
    }

private:
    RenderCallback                          mRenderCallback;
    sead::SafeArray<agl::TextureData, 4>    mTex;
    sead::BitFlag32                         mFlag;
    u32                                     _288[4 / sizeof(u32)];
    sead::SafeArray<agl::TextureData, 4>    mNml;
    agl::RenderTargetColor                  mTexColorTarget;
    agl::RenderBuffer                       mTexRenderBuffer;
    agl::RenderTargetColor                  mNmlColorTarget;
    agl::RenderBuffer                       mNmlRenderBuffer;
    sead::OrthoProjection                   mProjection;
    sead::OrthoCamera                       mCamera;
    sead::SafeArray<agl::TextureData, 6>    mAnimeTex;
    sead::SafeArray<AnimeParam, 9>          mAnimeParam;
    PaType                                  mPaType;
    agl::utl::DebugTexturePage              mDebugTexturePage;
    bool                                    _f84;
};
static_assert(sizeof(BgTexMgr) == 0xF88);
