#pragma once

#include <framework/seadTaskID.h>
#include <heap/seadDisposer.h>
#include <math/seadVector.h>
#include <prim/seadDelegateEventSlot.h>

class Fader;

class Scene
{
    // createInstance()                             Address: 0x02993E68
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101E7B28
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x029945C0
    // SingletonDisposer_::sStaticDisposer          Address: 0x101E7B2C
    // SingletonDisposer_::vtbl                     Address: 0x10178FE4
    SEAD_SINGLETON_DISPOSER(Scene)

public:
    class WipeInfo
    {
    public:
        enum Mask
        {
            cMask_FadeinWipeType  = 0x0000FFFF,
            cMask_FadeoutWipeType = 0xFFFF0000
        };

        enum Shift
        {
            cShift_FadeinWipeType = 0,
            cShift_FadeoutWipeType = 16
        };
    
        static u32 make(u16 fadeout_wipe_type, u16 fadein_wipe_type)
        {
            u32 data = 0;
            setFadeoutWipeType(data, fadeout_wipe_type);
            setFadeinWipeType(data, fadein_wipe_type);
            return data;
        }

        static u16 getFadeoutWipeType(u32 data)
        {
            return (data & cMask_FadeoutWipeType) >> cShift_FadeoutWipeType;
        }

        static void setFadeoutWipeType(u32& data, u16 type)
        {
            data &= ~cMask_FadeoutWipeType;
            data |= (u32(type) << cShift_FadeoutWipeType) & cMask_FadeoutWipeType;
        }

        static u16 getFadeinWipeType(u32 data)
        {
            return (data & cMask_FadeinWipeType) >> cShift_FadeinWipeType;
        }

        static void setFadeinWipeType(u32& data, u16 type)
        {
            data &= ~cMask_FadeinWipeType;
            data |= (u32(type) << cShift_FadeinWipeType) & cMask_FadeinWipeType;
        }
    };

public:
    // Address: 0x02993D68
    Scene();

    // Address: 0x02994164
    bool createScene(sead::TaskBase* p_src_task, const sead::TaskClassID& next_scene, u32 wipe_info = WipeInfo::make(0, 0), u32 snd_param_unused = 0);

    // Address: 0x029941D0
    bool setCourse_Story(sead::TaskBase* p_src_task, s32 world_no, s32 course_no);

    // Address: 0x029945B8
    bool isFadein() const;

    const sead::TaskClassID& getNextScene() const
    {
        return mNextScene;
    }

    sead::TaskMgr* getTaskMgr()
    {
        return mpTaskMgr;
    }

    u32& getWipeInfo()
    {
        return mWipeInfo;
    }

    const u32& getWipeInfo() const
    {
        return mWipeInfo;
    }

    sead::Vector3f& getFadeCenter()
    {
        return mFadeCenter;
    }

    const sead::Vector3f& getFadeCenter() const
    {
        return mFadeCenter;
    }

protected:
    sead::DelegateEvent<sead::TaskBase*>::Slot  mCreateCallback;
    sead::TaskClassID                           mOldScene;
    sead::TaskClassID                           mNowScene;
    sead::TaskClassID                           mNextScene;
    sead::TaskMgr*                              mpTaskMgr;
    Fader*                                      mpFader;
    u32                                         mWipeInfo;
    u8                                          _70;
    sead::Vector3f                              mFadeCenter;
    u32                                         _80;
};
static_assert(sizeof(Scene) == 0x84);
