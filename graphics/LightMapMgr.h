#pragma once

#include <framework/seadCalculateTask.h>
#include <framework/seadTaskMgr.h>
#include <lighting/aglLightMapMgr.h>

class ModelG3d;

class LightMapMgr : public sead::CalculateTask  // vtbl Address: 0x100BBA94
{
    // setInstance_()                               Address: 0x024E3A78
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2C60
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024E3990
    SEAD_TASK_SINGLETON_DISPOSER(LightMapMgr)

public:
    static const u32 cLightMapNum = 2;

    enum EnvTypeCourse
    {
        cEnvTypeCourse_Enemy = 0,
        cEnvTypeCourse_Boss,
        cEnvTypeCourse_MapObj,
        cEnvTypeCourse_Item,
        cEnvTypeCourse_Player,
        cEnvTypeCourse_DistantView,
        cEnvTypeCourse_Effect,
        cEnvTypeCourse_Num
    };
    static_assert(cEnvTypeCourse_Num == 7);

public:
    // Address: 0x024E3A98
    LightMapMgr(const sead::TaskConstructArg& arg);
    // Address: 0x024E39BC
    virtual ~LightMapMgr();

    agl::lght::LightMapMgr& getLightMapMgr() { return mLightMapMgr; }
    const agl::lght::LightMapMgr& getLightMapMgr() const { return mLightMapMgr; }

    bool enable() const { return mEnable; }
    void setEnable(bool enable) { mEnable = enable; }

    // Address: 0x024E5040
    void setModelLightMap(ModelG3d* p_model, bool set_mdl_dl_dirty) const;

    // Address: 0x024E51C8
    void initializeForCourseSelect(sead::Heap* heap);

    // Address: 0x024E54E4
    const agl::TextureSampler& getLightmap1(EnvTypeCourse index) const;
    // Address: 0x024E5534
    const agl::TextureSampler& getLightmap2(EnvTypeCourse index) const;

private:
    u32                     _cc[(0x2070 - 0xCC) / sizeof(u32)];
    agl::lght::LightMapMgr  mLightMapMgr;
    u32                     _4ddc[(0x52C8 - 0x4DDC) / sizeof(u32)];
    bool                    mEnable;
};
static_assert(sizeof(LightMapMgr) == 0x52CC);
