#pragma once
#include <seadDisposer.h>
#include <seadSafeString.h>
#include <layout_sys/LayoutAllocator.h>
#include <lyt/lyt_DrawInfo.h>
#include <seadBuffer.h>
#include <layout_sys/TagProcessor.h>
#include <Mtx.h>
#include <graphics/LayerMgr.h>
#include <lyt/lyt_Animator.h>
#include <layout_sys/AnimLayout.h>

class Multi2D : public sead::IDisposer
{
public:
    Multi2D(Multi2D::Animation*, u32);
    virtual ~Multi2D();

public:

    // Adress: 0x02672A4C
   void AnimePlay(LayerMgr* viewLayerId, sead::Matrix34* modelMtx);
   // Adress: 0x02671C54
   void AnimeResRegister(sead::SafeString* resName, u32 animNumber);
   // Adress: 0x026711C8
   void createLayoutObj(sead::Heap* heap);
   // Adress: 0x026712E4
   void draw(const sead::Matrix44& projection);
   // Adress: 0x2671680
   nw::lyt::Animator* AnimeStartSetup(u32 animeIndex, sead::SafeString* animResName, nw::lyt::Animator::PlayType type);
   // Adress: 0x2672D14
   void draw(sead::Matrix44* mtx);
   // Adress: 0x02671CCC
   nw::lyt::Pane* findPaneByName(const sead::SafeString& paneName);    


public:
    struct Animation
    {
        u8                  animatorObject[0x4];
        sead::SafeString    animResName;
        u8                  _c[0x4];
        bool                oneShotPlaybackDone;
        u8                 _11[3];
    };
    static_assert(sizeof(Animation) == 0x14);

private:
    u8                                  mLayoutObj[0x4];
    LayoutAllocator                     mLayoutAllocator;
    nw::lyt::DrawInfo                   mDrawInfo;
    u8                                  mAnimeResMaps[0xD94];
    sead::Buffer<Multi2D::Animation>    mAnimeBuffer;
    TagProcessor                        mTagProcessor;
};
static_assert(sizeof(Multi2D) == 0xE88);