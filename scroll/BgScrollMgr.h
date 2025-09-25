#pragma once

#include <utility/Direction.h>

#include <heap/seadDisposer.h>
#include <math/seadBoundBox.h>

class BgScrollMgr;

// This is actually in a different file
class ScrollEffectMgr
{
public:
    ScrollEffectMgr(BgScrollMgr* scroll_mgr);

public:
    u32 _0[0x3c / sizeof(u32)];
    struct // This should be a separate class
    {
        u32 _0;
        f32 _4;
        f32 _8;
        u32 _c;
        f32 _10;
        f32 _14;
    } _3c;
};
static_assert(sizeof(ScrollEffectMgr) == 0x54);

class Zoom
{
public:
    f32 getMultiplier(bool) const;
};

class TrackingMgr
{
public:
    Zoom* getActiveZoom() const;
    f32 zoomMultiplerClampMax(f32 multiplier) const;

    f32 getCurrentZoomMultiplier(bool param_1 = false) const
    {
        return zoomMultiplerClampMax(getActiveZoom()->getMultiplier(param_1));
    }
};

class BgScrollMgr
{
    SEAD_SINGLETON_DISPOSER(BgScrollMgr)

public:
    BgScrollMgr();

    f32 getZoom() const { return mZoom; }

    const sead::BoundBox2f& getScrollBound() const { return mScroll; }
    const sead::BoundBox2f& getScreenRect() const { return mScreen; }
    const sead::BoundBox2f& getScreenRectDefault() const { return mScreenDefault; }

    f32 getScreenWidth() const { return mScreenWidth; }
    f32 getScreenHeight() const { return mScreenHeight; }
    f32 getScreenLeft() const { return mScreenLeft; }
    f32 getScreenCenterX() const { return mScreenCenterX; }
    f32 getScreenRight() const { return mScreenRight; }
    f32 getScreenTop() const { return mScreenTop; }
    f32 getScreenCenterY() const { return mScreenCenterY; }
    f32 getScreenBottom() const { return mScreenBottom; }

    ScrollEffectMgr& getScrollEffectMgr() { return mScrollEffectMgr; }
    const ScrollEffectMgr& getScrollEffectMgr() const { return mScrollEffectMgr; }

    // Address: 0x029A6400
    DirType getAreaScrollDir() const;

    // Address: 0x029A6D40
    f32 getBgCenterYPos() const;

    // Address: 0x029A6DC4
    bool isScrollMeterEnable() const;

    // Address: 0x029A6E24
    DirType getAreaScrollDirSub() const;

private:
    f32                 mZoom;
    f32                 mZoomPrev;
    sead::BoundBox2f    mScroll;
    sead::BoundBox2f    mScreen;
    sead::BoundBox2f    mScreenPrev;
    sead::BoundBox2f    mScreenZoom;        // Same center as mScreen, but size is determined by mZoom
    sead::BoundBox2f    mScreenDefault;     // Same center as mScreen, but size is (796.44, 448)
    f32                 mScreenWidth;       // In world space
    f32                 mScreenHeight;      // ^^^
    f32                 mScreenLeft;        // ^^^
    f32                 mScreenCenterX;     // ^^^
    f32                 mScreenRight;       // ^^^
    f32                 mScreenTop;         // ^^^
    f32                 mScreenCenterY;     // ^^^
    f32                 mScreenBottom;      // ^^^
    sead::BoundBox2f    mScreenBg;          // Same as mScreen, but Y is inverted
    sead::BoundBox2f    mScreenBgPrev;
    void*               mScrollInfo;
    void*               mMaxStopMgr;
    void*               mZoomAreaMgr;
    void*               mKyokaiVelMgr;
    TrackingMgr*        mTrackingMgr;
    void*               _bc;
    void*               _c0;
    void*               mAutoScrollMgr;
    void*               mConfigMgr;
    u32                 mScrollLimitInfo[0x2c / sizeof(u32)];
    ScrollEffectMgr     mScrollEffectMgr;
};
static_assert(sizeof(BgScrollMgr) == 0x14C);
