#pragma once

#include <framework/seadCalculateTask.h>
#include <framework/seadTaskMgr.h>
#include <lighting/aglLightMapMgr.h>

class ModelNW;

class LightMapMgr : public sead::CalculateTask  // vtbl Address: 0x100BBA94
{
    // setInstance_()                               Address: 0x024E3A78
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2C60
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024E3990
    SEAD_TASK_SINGLETON_DISPOSER(LightMapMgr)

public:
    static const u32 cLightMapNum = 2;

public:
    // Address: 0x024E3A98
    LightMapMgr(const sead::TaskConstructArg& arg);
    // Address: 0x024E39BC
    virtual ~LightMapMgr();

    agl::lght::LightMapMgr& getLightMapMgr() { return mLightMapMgr; }
    const agl::lght::LightMapMgr& getLightMapMgr() const { return mLightMapMgr; }

    // Address: 0x024E5040
    void setModelLightMap(ModelNW* p_model, bool set_mdl_dl_dirty) const;

    // Address: 0x024E51C8
    void initializeForCourseSelect(sead::Heap* heap);

private:
    u32                     _cc[(0x2070 - 0xCC) / sizeof(u32)];
    agl::lght::LightMapMgr  mLightMapMgr;
    u32                     _4ddc[(0x52C8 - 0x4DDC) / sizeof(u32)];
    bool                    mIsInitialized;
};
static_assert(sizeof(LightMapMgr) == 0x52CC);
