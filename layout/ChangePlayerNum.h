#pragma once

#include <layout_sys/AnimLayout.h>
#include <state/FStateMgr.h>

#include <layer/aglRenderInfo.h>

class ChangePlayerNum   // vtbl Address: 0x100C8CE0
{
public:
    // Address: 0x02553AB8
    ChangePlayerNum();
    // Address: 0x02553D24
    virtual ~ChangePlayerNum();

    // Address: 0x02553E28
    void create();

    // Address: 0x025546B8
    void execute();

    // Address: 0x025548D0
    void draw(const agl::lyr::RenderInfo& render_info) const;
    // Address: 0x0255491C
    void drawBtn(const agl::lyr::RenderInfo& render_info) const;

    // Address: 0x025549A8
    void gather();

    // Address: 0x02554A24
    void setPlayerCharacter(s32 character, s32 player_no);
    // Address: 0x02554A70
    void resetPlayerCharacter(s32 character, s32 player_no);

    void open()
    {
        mIsOpen = true;
    }

    bool isVisible() const
    {
        return mIsVisible;
    }

    // StateID_CloseRequest         Address: 0x1020D434
    // initializeState_CloseRequest Address: 0x02555998
    // executeState_CloseRequest    Address: 0x02555A28
    // finalizeState_CloseRequest   Address: 0x02556C04
    DECLARE_STATE_ID(ChangePlayerNum, CloseRequest)

    bool isCloseRequest() const
    {
        return *mStateMgr.getStateID() == StateID_CloseRequest;
    }

protected:
    FStateMgr<ChangePlayerNum>  mStateMgr;
    AnimLayout<1>               mLayout;
    u32                         _ec4[(0xB798 - 0xEC4) / sizeof(u32)];
    bool                        mIsOpen;
    u8                          _b799;
    bool                        mIsVisible;
    u32                         _b79c[(0xB7A0 - 0xB79C) / sizeof(u32)];
};
static_assert(sizeof(ChangePlayerNum) == 0xB7A4);
