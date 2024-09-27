#pragma once

#include <layout_sys/LayoutAllocator.h>
#include <layout_sys/TagProcessor.h>

#include <container/seadBuffer.h>
#include <container/seadStrTreeMap.h>
#include <heap/seadDisposer.h>
#include <math/seadMatrix.h>

#include <nw/lyt/lyt_Animator.h>
#include <nw/lyt/lyt_DrawInfo.h>

namespace nw { namespace lyt {

class Bounding;
class GroupArrayAnimator;
class Pane;
class Parts;
class Picture;
class Window;

} }

class LayoutObj;
class PartsLayoutObj;
class TextBox;

class Multi2D : public sead::IDisposer  // vtbl Address: 0x100E2A1C
{
public:
    // Address: 0x026711C8
    void createLayoutObj(sead::Heap* heap);

    // Address: 0x0267122C
    void animResRegister(const sead::SafeString& anim_res_name);

    // Address: 0x02671680
    nw::lyt::Animator* animStartSetup(s32 anim_index, const sead::SafeString& anim_res_name, nw::lyt::Animator::PlayType type);
    // Address: 0x02671730
    nw::lyt::Animator* reverseAnimeStartSetup(s32 anim_index, const sead::SafeString& anim_res_name, nw::lyt::Animator::PlayType type);

    // Address: 0x026717E0
    nw::lyt::Animator* groupAnimeStartSetup(s32 anim_index, const sead::SafeString& anim_res_name, s32 group, nw::lyt::Animator::PlayType type);
    // Address: 0x026718A8
    nw::lyt::Animator* groupReverseAnimeStartSetup(s32 anim_index, const sead::SafeString& anim_res_name, s32 group, nw::lyt::Animator::PlayType type);

    // Address: 0x02671970
    s32 getAnimGroupIndex(const sead::SafeString& anim_res_name, const sead::SafeString& group_name) const;

    // Address: 0x02671AD4
    const sead::SafeString& getAnimResName(s32 anim_index) const;

    // Address: 0x02671AF4
    nw::lyt::Animator* getAnimatorObj(s32 anim_index);

    // Address: 0x02671B14
    void setAnimFrame(s32 anim_index, f32 frame);
    // Address: 0x02671B38
    f32 getAnimFrame(s32 anim_index) const;

    // Address: 0x02671B5C
    void animEndSetup(s32 anim_index);

    // Address: 0x02671BEC
    f32 getAnimFrameSize(s32 anim_index) const;

    // Address: 0x02671C48
    nw::lyt::Pane* getRootPane();

    // Address: 0x02671C54
    void animResRegister(const sead::SafeString* p_anim_res_names, const s32& anim_res_num);

    // Address: 0x02671D3C
    void NPaneRegister(nw::lyt::Pane** pp_panes, const sead::SafeString* p_names, const s32& num);
    // Address: 0x02671E90
    void PPaneRegister(nw::lyt::Picture** pp_panes, const sead::SafeString* p_names, const s32& num);
    // Address: 0x02672010
    void TPaneRegister(TextBox** pp_panes, const sead::SafeString* p_names, const s32& num);
    // Address: 0x02672164
    void BPaneRegister(nw::lyt::Bounding** pp_panes, const sead::SafeString* p_names, const s32& num);
    // Address: 0x026722B8
    void WPaneRegister(nw::lyt::Window** pp_panes, const sead::SafeString* p_names, const s32 num); // Whoops, somebody forgot the `&`

    // Address: 0x026724D8
    void PaRootPaneRegister(nw::lyt::Pane** pp_panes, const sead::SafeString* p_parts_pane_names, const s32& num);
    // Address: 0x02672544
    void PaTPaneRegister(TextBox** pp_panes, const sead::SafeString& parts_pane_name, const sead::SafeString* p_names, const s32& num);
    // Address: 0x026725B8
    void PaBPaneRegister(nw::lyt::Bounding** pp_panes, const sead::SafeString& parts_pane_name, const sead::SafeString* p_names, const s32& num);
    // Address: 0x0267262C
    void PaPPaneRegister(nw::lyt::Picture** pp_panes, const sead::SafeString& parts_pane_name, const sead::SafeString* p_names, const s32& num);
    // Address: 0x026726A0
    void PaNPaneRegister(nw::lyt::Pane** pp_panes, const sead::SafeString& parts_pane_name, const sead::SafeString* p_names, const s32& num);

    // Address: 0x02672828
    void PaPaneRegister(nw::lyt::Parts** pp_panes, const sead::SafeString* p_names, const s32& num);

    // Address: 0x02672890
    void animPlay(const sead::Matrix34f& view_mtx, const sead::Matrix34f* p_model_mtx = nullptr);
    // Address: 0x02672A4C
    void animPlay(s32 view_layer_id, const sead::Matrix34f* p_model_mtx = nullptr); // See: LayerMgr::Layer

    // Address: 0x02672A78
    void setPlayerColor(const sead::SafeString& color_anim_res_name, s32 player_no, s32 view_layer_id, bool force_5th_color);

    // Address: 0x02672C90
    void setTextBoxMessageFromTextID(TextBox& text_box, bool is_urcc);

    // Address: 0x02672CE8
    void initializeLayoutObj_();

    // Address: 0x02672D14
    void draw(const sead::Matrix44f& proj_mtx);

protected:
    struct AnimRes
    {
        nw::lyt::GroupArrayAnimator*    p_group_array_animator;
        u32                             group_num;
        nw::lyt::Animator**             p_animators;
    };
    static_assert(sizeof(AnimRes) == 0xC);

    struct Animation
    {
        nw::lyt::Animator*  p_animator;
        sead::SafeString    anim_res_name;
        u32                 _c;
        bool                oneshot_playback_done;
    };
    static_assert(sizeof(Animation) == 0x14);

protected:
    // Address: 0x02672D5C
    Multi2D(Animation* p_anim_buf, s32 anim_buf_size);
    // Address: 0x02672E98
    virtual ~Multi2D();

    // Address: 0x0267153C
    void animStartBaseSetup_(s32 anim_index, const sead::SafeString& anim_res_name, nw::lyt::Animator::PlayType type, f32 speed, nw::lyt::Animator* p_animator);

    // Address: 0x02671CCC
    nw::lyt::Pane* findPaneByName_(const sead::SafeString& name);
    // Address: 0x02671DA4
    nw::lyt::Picture* findPictureByName_(const sead::SafeString& name);
    // Address: 0x02671EF8
    TextBox* findTextBoxByName_(const sead::SafeString& name);
    // Address: 0x02672078
    nw::lyt::Bounding* findBoundingByName_(const sead::SafeString& name);
    // Address: 0x026721CC
    nw::lyt::Window* findWindowByName_(const sead::SafeString& name);
    // Address: 0x0267273C
    nw::lyt::Parts* findPartsByName_(const sead::SafeString& name);

    // Address: 0x02672410
    PartsLayoutObj* findPartsLayoutByPaneName_(const sead::SafeString& name);

    // Address: 0x02672324
    LayoutObj* getPartsLayoutObj_(const sead::SafeString& parts_pane_name);

protected:
    LayoutObj*              mpObj;
    LayoutAllocator         mAllocator;
    nw::lyt::DrawInfo       mDrawInfo;
    sead::FixedStrTreeMap<
        64,
        AnimRes,
        32
    >                       mAnimResMap;
    sead::Buffer<Animation> mAnimBuffer;
    TagProcessor            mTagProcessor;
};
static_assert(sizeof(Multi2D) == 0xE88);

class ArcResAccMulti;
class UtilCursorButtonMgr;

class AnimLayoutBase : public Multi2D   // vtbl Address: 0x100E2A2C
{
public:
    // Address: 0x02672F04
    AnimLayoutBase(Animation* p_anim_buf, s32 anim_buf_size);
    // Address: 0x02672F80
    virtual ~AnimLayoutBase();

    // Address: 0x02673008
    void readResource(const sead::SafeString& res_name);

    // Address: 0x02673050
    void build(const sead::SafeString& lyt_filename, UtilCursorButtonMgr* p_cursor_btn_mgr = nullptr, void* = nullptr, void* = nullptr);

protected:
    ArcResAccMulti* mpResAcc;
};
static_assert(sizeof(AnimLayoutBase) == 0xE8C);

class PartsAnimLayoutBase : public Multi2D  // vtbl Address: 0x100E29D0
{
public:
    // Address: 0x02673124
    PartsAnimLayoutBase(Animation* p_anim_buf, s32 anim_buf_size);

    // Address: 0x026731A0
    void createLayoutObj(const Multi2D& p_parent, const sead::SafeString& parts_name);

protected:
    // Address: 0x02673198
    void setLayoutObj_(LayoutObj* p_obj);
};
static_assert(sizeof(PartsAnimLayoutBase) == 0xE88);

template <s32 N>
class AnimLayout : public AnimLayoutBase
{
public:
    AnimLayout()
        : AnimLayoutBase(mAnimation, N)
    {
    }

protected:
    Animation   mAnimation[N];
};

template <s32 N>
class PartsAnimLayout : public PartsAnimLayoutBase
{
public:
    PartsAnimLayout()
        : PartsAnimLayoutBase(mAnimation, N)
    {
    }

protected:
    Animation   mAnimation[N];
};
