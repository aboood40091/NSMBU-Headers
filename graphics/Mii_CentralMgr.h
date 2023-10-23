#pragma once

#include <graphics/Mii_CafeResInitializer.h>
#include <graphics/Mii_ModelGpuInitializer.h>
#include <graphics/Mii_Shader.h>
#include <graphics/Mii_IconFacelineShader.h>
#include <graphics/Mii_SlotMgr.h>

namespace Mii {

class CentralMgr
{
    // createInstance()                             Address: 0x024E80D4
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2CC4
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024E81EC
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D2CC8
    // SingletonDisposer_::vtbl                     Address: 0x100BBE34
    SEAD_SINGLETON_DISPOSER(CentralMgr)

public:
    // Address: 0x024E8068
    CentralMgr();

    ~CentralMgr()
    {
        destroy();
    }

    // Address: 0x024E8154
    void destroy();

    ModelGpuInitializer& getModelGpuInitializer()
    {
        return mModelGpuInitializer;
    }

    Shader& getShader()
    {
        return mShader;
    }

private:
    CafeResInitializer  mResInitializer;
    ModelGpuInitializer mModelGpuInitializer;
    Shader              mShader;
    IconFacelineShader  mIconFacelineShader;
    SlotMgr             mSlotMgr;
};
static_assert(sizeof(CentralMgr) == 0x1300);

}
