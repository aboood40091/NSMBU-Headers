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
    class FaderInfo
    {
    public:
        enum Mask
        {
            cMask_InFaderType  = 0x0000FFFF,
            cMask_OutFaderType = 0xFFFF0000
        };

        enum Shift
        {
            cShift_InFaderType = 0,
            cShift_OutFaderType = 16
        };
    
        static u32 make(u16 out_fader_type, u16 in_fader_type)
        {
            u32 data = 0;
            setOutFaderType(data, out_fader_type);
            setInFaderType(data, in_fader_type);
            return data;
        }

        static u16 getOutFaderType(u32 data)
        {
            return (data & cMask_OutFaderType) >> cShift_OutFaderType;
        }

        static void setOutFaderType(u32& data, u16 type)
        {
            data &= ~cMask_OutFaderType;
            data |= (u32(type) << cShift_OutFaderType) & cMask_OutFaderType;
        }

        static u16 getInFaderType(u32 data)
        {
            return (data & cMask_InFaderType) >> cShift_InFaderType;
        }

        static void setInFaderType(u32& data, u16 type)
        {
            data &= ~cMask_InFaderType;
            data |= (u32(type) << cShift_InFaderType) & cMask_InFaderType;
        }
    };

public:
    // Address: 0x02993D68
    Scene();

    // Address: 0x02994164
    bool setNextScene(sead::TaskBase* p_src_task, const sead::TaskClassID& next_scene, u32 fader_info = FaderInfo::make(0, 0), u32 snd_param_unused = 0);

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

    u32& getFaderInfo()
    {
        return mFaderInfo;
    }

    const u32& getFaderInfo() const
    {
        return mFaderInfo;
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
    u32                                         mFaderInfo;
    u8                                          _70;
    sead::Vector3f                              mFadeCenter;
    u32                                         _80;
};
static_assert(sizeof(Scene) == 0x84);
