#pragma once

#include <heap/seadDisposer.h>
#include <resource/seadSharcArchiveRes.h>
#include <utility/aglParameterIO.h>

class GfxParameter  // vtbl Address: 0x100BAD04
{
    // createInstance()                             Address: 0x024DF350
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2B90
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024DF7C8
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D2B94
    // SingletonDisposer_::vtbl                     Address: 0x100BACF4
    SEAD_SINGLETON_DISPOSER(GfxParameter)

public:
    // Address: 0x024DF254
    GfxParameter();
    // Address: 0x024DF3D0
    virtual ~GfxParameter();

    // Address: 0x024DF5A8
    void setDelegateForParameter(agl::utl::IParameterIO* param);

    // Address: 0x024DF5CC
    void* getAglEnvBinary(const sead::SafeString& name, sead::Heap* heap = nullptr) const;
    // Address: 0x024DF6C4
    void* getAglLmapBinary(const sead::SafeString& name, sead::Heap* heap = nullptr) const;

private:
    // Address: 0x024DF5B4
    void* getFileFromPack_(const sead::SafeString& filename, sead::Heap* heap) const;

private:
    sead::SharcArchiveRes*  mPackArc;
    u32                     mDelegateData[8]; // Same idea as agl::lyr::DrawMethod
    u32                     _34;
};
static_assert(sizeof(GfxParameter) == 0x3C);
