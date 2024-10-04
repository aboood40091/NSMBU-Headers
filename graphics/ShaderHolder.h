#pragma once

#include <common/aglShaderProgramArchive.h>
#include <container/seadStrTreeMap.h>
#include <heap/seadDisposer.h>

class ShaderHolder
{
    // createInstance()                             Address: 0x024FDEC0
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2D9C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024FE67C
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D2DA0
    // SingletonDisposer_::vtbl                     Address: 0x100BE150
    SEAD_SINGLETON_DISPOSER(ShaderHolder)

public:
    // Address: 0x024FDE24
    ShaderHolder();

    // Address: 0x024FE274
    void initialize(sead::Heap* heap);

private:
    // Address: 0x024FDF40
    agl::ShaderProgramArchive* createShaderArchive_(const sead::SafeString& filename, sead::Heap* heap) const;
    // Address: 0x024FE030
    void pushBackShaderArchive_(const sead::SafeString& filename, agl::ShaderProgramArchive* p_archive, sead::Heap* heap);

    // Address: 0x024FE21C
    void createAndPushBackShaderArchive_(const sead::SafeString& filename, sead::Heap* heap);

public:
    // Address: 0x024FE57C
    const agl::ShaderProgramArchive* getShaderArchive(const sead::SafeString& filename) const;
    // Address: 0x024FE5CC
    const agl::ShaderProgramArchive* getNw4fShaderArchive() const;
    // Address: 0x024FE608
    const agl::ShaderProgram* getNw4fBasicShaderProgram() const;

private:
    sead::FixedStrTreeMap<64, agl::ShaderProgramArchive*, 32> mShaderArchiveTreeMap;
};
static_assert(sizeof(ShaderHolder) == 0xCA4);
