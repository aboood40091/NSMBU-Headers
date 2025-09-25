#pragma once

#include <player/PlayerModelBase.h>

class PlayerModelBaseMgr    // vtbl Address: 0x1016BE5C
{
public:
    enum DrawType
    {
        cDrawType_Normal = 0,
        cDrawType_InBalloon,
        cDrawType_InDistantView
    };

public:
    // Address: 0x02922A38
    PlayerModelBaseMgr();

    virtual void setCapMode(PlayerModelBase::CapMode mode)
    {
    }

    PlayerModelBase* getModelBase()
    {
        return mpModelBase;
    }

    // Address: 0x02922B3C
    void setModelBase(PlayerModelBase* p_mdl_base);

    void reset()
    {
        mpModelBase->reset();
    }

    f32 getAnmRate(s32 anm_id)
    {
        return mpModelBase->getAnmRate(anm_id);
    }

    f32 getAnmBlendDuration(s32 anm_id)
    {
        return mpModelBase->getAnmBlendDuration(anm_id);
    }

    // Address: 0x02922A84
    void setAnm(s32 anm_id, f32 frame = 0.0f);
    // Address: 0x02922BA4
    void setAnm(s32 anm_id, f32 blend_duration, f32 frame);

    void setAnm(s32 anm_id, f32 rate, f32 blend_duration, f32 frame)
    {
        mpModelBase->setAnm(anm_id, rate, blend_duration, frame);
    }

    // Address: 0x02922C40
    void setBodyAnm(s32 anm_id);

    void setBodyAnm(s32 anm_id, f32 rate, f32 frame = 0.0f, f32 blend_duration = 0.0f)
    {
        mpModelBase->setBodyAnm(anm_id, rate, frame, blend_duration);
    }

    void copyLinkAnm(f32 blend_duration)
    {
        mpModelBase->copyLinkAnm(blend_duration);
    }

    void setJumpIndex(s32 rnd_type)
    {
        mpModelBase->setJumpIndex(rnd_type);
    }

    void setRate(f32 rate)
    {
        mpModelBase->setRate(rate);
    }

    f32 getRate()
    {
        return mpModelBase->getRate();
    }

    void setRateDirect(f32 rate)
    {
        mpModelBase->setRateDirect(rate);
    }

    f32 getRateDirect()
    {
        return mpModelBase->getRateDirect();
    }

    void setBodyRate(f32 rate)
    {
        mpModelBase->setBodyRate(rate);
    }

    f32 getBodyRate()
    {
        return mpModelBase->getBodyRate();
    }

    bool isAnmStop()
    {
        return mpModelBase->isAnmStop();
    }

    bool isBodyAnmStop()
    {
        return mpModelBase->isBodyAnmStop();
    }

    void setFrame(f32 frame)
    {
        mpModelBase->setFrame(frame);
    }

    f32 getFrame()
    {
        return mpModelBase->getFrame();
    }

    void setFrameDirect(f32 frame)
    {
        mpModelBase->setFrameDirect(frame);
    }

    f32 getFrameDirect()
    {
        return mpModelBase->getFrameDirect();
    }

    void setBodyFrame(f32 frame)
    {
        mpModelBase->setBodyFrame(frame);
    }

    f32 getBodyFrame()
    {
        return mpModelBase->getBodyFrame();
    }

    bool checkFrame(f32 frame)
    {
        return mpModelBase->checkFrame(frame);
    }

    bool checkBodyFrame(f32 frame)
    {
        return mpModelBase->checkBodyFrame(frame);
    }

    bool checkFrameCtrlFlagUnk2()
    {
        return mpModelBase->checkFrameCtrlFlagUnk2();
    }

    bool checkBodyFrameCtrlFlagUnk2()
    {
        return mpModelBase->checkBodyFrameCtrlFlagUnk2();
    }

    f32 getFrameEnd()
    {
        return mpModelBase->getFrameEnd();
    }

    bool isBodyAnmOn()
    {
        return mpModelBase->isBodyAnmOn();
    }

    void getJointMtx(sead::Matrixf* p_mtx, s32 index)
    {
        mpModelBase->getJointMtx(p_mtx, index);
    }

    void getJointPos(sead::Vector3f* p_pos, s32 index)
    {
        mpModelBase->getJointPos(p_pos, index);
    }

    void getJointMtx(sead::Matrixf* p_mtx, const sead::SafeString& name)
    {
        mpModelBase->getJointMtx(p_mtx, name);
    }

    void getJointPos(sead::Vector3f* p_pos, const sead::SafeString& name)
    {
        mpModelBase->getJointPos(p_pos, name);
    }

    void play()
    {
        mpModelBase->play();
    }

    void calc(const sead::Matrixf& mtx)
    {
        mpModelBase->calc(mtx);
    }

    void calc2()
    {
        mpModelBase->calc2();
    }

    // Address: 0x02922CA0
    void draw();

    void cancelCarry()
    {
        mpModelBase->cancelCarry();
    }

    void onCarry()
    {
        mpModelBase->onCarry();
    }

    void onLiftUp()
    {
        mpModelBase->onLiftUp();
    }

    void onBalloonChibiYoshiFly()
    {
        mpModelBase->onBalloonChibiYoshiFly();
    }

    void onBubbleChibiYoshiShake()
    {
        mpModelBase->onBubbleChibiYoshiShake();
    }

    void offCarry()
    {
        mpModelBase->offCarry();
    }

    void offLiftUp()
    {
        mpModelBase->offLiftUp();
    }

    void offBalloonChibiYoshiFly()
    {
        mpModelBase->offBalloonChibiYoshiFly();
    }

    void offBubbleChibiYoshiShake()
    {
        mpModelBase->offBubbleChibiYoshiShake();
    }

    bool isCarry()
    {
        return mpModelBase->isCarry();
    }

    bool isLiftUp()
    {
        return mpModelBase->isLiftUp();
    }

    void onStarAnm()
    {
        mpModelBase->onStarAnm();
    }

    void offStarAnm()
    {
        mpModelBase->offStarAnm();
    }

    bool isFootStepTiming()
    {
        return mpModelBase->isFootStepTiming();
    }

    bool isCourseSelectScene()
    {
        return mpModelBase->isCourseSelectScene();
    }

    f32 getBaseScale()
    {
        return mpModelBase->getBaseScale();
    }

    sead::Vector3f* getHeadTopPosP()
    {
        return mpModelBase->getHeadTopPosP();
    }

    sead::Vector3f* getHeadPosP()
    {
        return mpModelBase->getHeadPosP();
    }

    u32 getAnmFlag(PlayerModelBase::AnmFlagType type) const
    {
        return mpModelBase->getAnmFlag(type);
    }

    void changeFaceAngleOverrideFlag(PlayerModelBase::FaceAngleOverrideFlag flag, bool enable)
    {
        mpModelBase->changeFaceAngleOverrideFlag(flag, enable);
    }

    const Angle3& getFaceAngleOverride() const
    {
        return mpModelBase->getFaceAngleOverride();
    }

    void setFaceAngleOverride(const Angle3& angle)
    {
        mpModelBase->setFaceAngleOverride(angle);
    }

    void resetFaceAngleOverride()
    {
        mpModelBase->resetFaceAngleOverride();
    }

    void resetFaceAngleOverrideFlag()
    {
        mpModelBase->resetFaceAngleOverrideFlag();
    }

    // Address: 0x02922D8C
    void setDrawType(DrawType type);

protected:
    PlayerModelBase*    mpModelBase;
    DrawType            mDrawType;
};
static_assert(sizeof(PlayerModelBaseMgr) == 0xC);
