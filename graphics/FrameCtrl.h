#pragma once

#include <prim/seadBitFlag.h>

class FrameCtrl
{
public:
    enum PlayMode
    {
        cMode_NoRepeat  = 0,
        cMode_Repeat    = 1
    };

public:
    // Address: 0x024DEE24
    FrameCtrl();

    // Address: 0x024DEEAC
    void reset();

    // Address: 0x024DEED4
    void setPlayMode(PlayMode mode);

    // Address: 0x024DEF04
    void play();

    f32 getFrameStart() const { return mFrameStart; }
    void setFrameStart(f32 frame) { mFrameStart = frame; }

    f32 getFrameEnd() const { return mFrameEnd; }
    void setFrameEnd(f32 frame) { mFrameEnd = frame; }

    f32 getFrameMin() const { return mFrameMin; }
    void setFrameMin(f32 frame) { mFrameMin = frame; }

    f32 getFrameMax() const { return mFrameMax; }
    void setFrameMax(f32 frame) { mFrameMax = frame; }

    f32 getFrame() const { return mFrame; }
    void setFrame(f32 frame) { mFrame = frame; mFlag.set(cFlag_StartFrame); }

    f32 getRate() const { return mRate; }
    void setRate(f32 rate) { mRate = rate; }

    void set(PlayMode mode, f32 rate, f32 frame)
    {
        setPlayMode(mode);
        setRate(rate);
        setFrame(frame);
    }

    bool isRepeat() const
    {
        return mFlag.isOn(cFlag_Repeat);
    }

    bool isStartFrame() const
    {
        return mFlag.isOn(cFlag_StartFrame);
    }

    bool isLoopFrame() const
    {
        return mFlag.isOn(cFlag_LoopFrame);
    }

    bool hasLooped() const
    {
        return mFlag.isOn(cFlag_HasLooped);
    }

    bool isEndFrame() const
    {
        return mFlag.isOn(cFlag_EndFrame);
    }

    bool isStop() const
    {
        return mFlag.isOn(cFlag_IsStop);
    }

    void stop()
    {
        mFlag.set(cFlag_IsStop);
    }

    void setSkipFirstFrame(bool skip)
    {
        mFlag.change(cFlag_StartFrame, !skip);
    }

    // Address: 0x024DF0B8
    bool checkFrame(f32) const;

protected:
    enum Flag
    {
        cFlag_Repeat        = 1 << 0,
        cFlag_StartFrame    = 1 << 1,
        cFlag_LoopFrame     = 1 << 2,
        cFlag_HasLooped     = 1 << 3,
        cFlag_EndFrame      = 1 << 4,
        cFlag_IsStop        = 1 << 5
    };

    f32             mFrameStart;
    f32             mFrameEnd;
    f32             mFrameMin;
    f32             mFrameMax;
    f32             mFrame;
    f32             mRate;
    sead::BitFlag32 mFlag;
};
static_assert(sizeof(FrameCtrl) == 0x1C);
