#pragma once

#include <layout_sys/AnimLayout.h>
#include <state/FStateMgr.h>

class AttentionScreen   // vtbl Address: 0x100C52A0
{
public:
    enum Type
    {
        cType_DRC = 0,  // Appears on DRC, attention towards TV
        cType_TV        // Appears on TV, attention towards DRC
    };
    static_assert(sizeof(Type) == 4);

public:
    // Address: 0x02532B04
    AttentionScreen();
    // Address: 0x02532C74
    virtual ~AttentionScreen();

    // Address: 0x02532D14
    void create();

    // Address: 0x02532FB0
    void execute();

    // Address: 0x02532FFC
    void draw(const agl::lyr::RenderInfo& render_info) const;

    // Address: 0x02533050
    void drawDRC(const agl::lyr::RenderInfo& render_info) const;

    // Address: 0x025330A4
    void open(Type type);

    void forceOpen(Type type)
    {
        open(type);
        mIsVisible = true;
    }

    bool isVisible() const
    {
        return mIsVisible;
    }

    void requestClose()
    {
        mRequestClose = true;
    }

    // Address: 0x02533104
    void requestCloseNow(); // Skips "In" animation

    // Address: 0x025331A0
    void forceClose();

    // StateID_In           Address: 0x1020B588
    // initializeState_In   Address: 0x02533228
    // executeState_In      Address: 0x025332D4
    // finalizeState_In     Address: 0x02533A34
    DECLARE_STATE_ID(AttentionScreen, In)

    bool isFadein() const
    {
        return *mStateMgr.getStateID() == StateID_In;
    }

protected:
    FStateMgr<AttentionScreen>              mStateMgr;
    AnimLayout<2>                           mLayout;
    sead::SafeArray<nw::lyt::Pane*, 2>      mNPane;
    sead::SafeArray<nw::lyt::Picture*, 3>   mPPane;
    bool                                    mIsOpen;
    bool                                    mRequestClose;
    bool                                    mIsVisible;
    Type                                    mType;
};
static_assert(sizeof(AttentionScreen) == 0xEF8);
