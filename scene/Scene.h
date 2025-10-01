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
    // Address: 0x02993D68
    Scene();

    // Address: 0x02994164
    bool createScene(sead::TaskBase* p_src_task, const sead::TaskClassID& next_scene, u32 param_0, u32 param_1);

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

protected:
    sead::DelegateEvent<sead::TaskBase*>::Slot  mCreateCallback;
    sead::TaskClassID                           mOldScene;
    sead::TaskClassID                           mNowScene;
    sead::TaskClassID                           mNextScene;
    sead::TaskMgr*                              mpTaskMgr;
    Fader*                                      mpFader;
    u32                                         _6c;
    u8                                          _70;
    sead::Vector3f                              mFadeCenter;    // I think
    u32                                         _80;
};
static_assert(sizeof(Scene) == 0x84);
