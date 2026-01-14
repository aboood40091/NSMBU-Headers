#pragma once

#include <framework/seadCalculateTask.h>
#include <framework/seadTaskMgr.h>
#include <layer/aglRenderInfo.h>
#include <math/seadBoundBox.h>

class AreaTask : public sead::CalculateTask // vtbl Address: 0x100B6984
{
    // setInstance_()                               Address: 0x024B5378
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D1598
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024B5228
    SEAD_TASK_SINGLETON_DISPOSER(AreaTask)

public:
    // Address: 0x024B5398
    AreaTask(const sead::TaskConstructArg& arg);
    // Address: 0x024B5254
    virtual ~AreaTask();

    sead::BoundBox2f& getBound() { return mBound; }
    const sead::BoundBox2f& getBound() const { return mBound; }

    u32 getLoopType() const { return mLoopType; }
    // Address: 0x024B5B20
    void setLoopType();

    // Address: 0x024B814C
    void setCourseOut();

    // Address: 0x024B7808
    void requestCourseOut_Down();
    // Address: 0x024B77DC
    void requestCourseOut_Normal();
    // Address: 0x024B8158
    void requestCourseOut_Secret();
    // Address: 0x024B8184
    void requestCourseOut_TreasureChest();
    // Address: 0x024B81AC
    void requestCourseOut_TreasureChestFail();
    // Address: 0x024B81D4
    void requestCourseOut_Subject();

    // Address: 0x024B84A8
    void drawLayer3D(const agl::lyr::RenderInfo& render_info);
    // Address: 0x024B8B98
    void debugDraw(const agl::lyr::RenderInfo& render_info);

    // Address: 0x024B8034
    f32 getLoopPosX(f32 x);

private:
    u8                  _c9;
    bool                mIsPrepareDone;
    bool                mIsDrawMethodReady;
    u32                 mControllerWrapper[4][0x194 / sizeof(u32)]; // ControllerWrapper[4]
    sead::BoundBox2f    mBound;
    u32                 mLoopType;
    u32                 _730[(0xBE4 - 0x730) / sizeof(u32)];
};
static_assert(sizeof(AreaTask) == 0xBE4);
