#pragma once

#include <graphics/ModelShaderArchive.h>

#include <container/seadBuffer.h>
#include <heap/seadDisposer.h>
#include <prim/seadSafeString.h>
#include <resource/seadArchiveRes.h>

#include <nw/g3d/res/g3d_ResFile.h>

class ModelResource : public sead::IDisposer    // vtbl Address: 0x100BD17C
{
public:
    // Address: 0x024F5548
    ModelResource();
    // Address: 0x024F5684
    virtual ~ModelResource();

    // Address: 0x024F55D0
    void destroy();

    // Address: 0x024F5C14
    void load(
        const sead::SafeString& filename, sead::Heap* heap
    );

    // Address: 0x024F56F8
    void load(
        sead::ArchiveRes* archive, const sead::SafeString& filename,
        const nw::g3d::res::ResFile* tex_res_file, sead::Heap* heap
    );

    // Address: 0x024F5C78
    void loadDemo(  // (This function just calls load())
        sead::ArchiveRes* archive, const sead::SafeString& filename,
        const nw::g3d::res::ResFile* tex_res_file, sead::Heap* heap
    );

    // Address: 0x024F5C7C
    agl::ShaderProgramArchive* getModelShaderProgramArchive(s32 idx_model) const;

    nw::g3d::res::ResFile* getResFile() const
    {
        return mResFile;
    }

private:
    nw::g3d::res::ResFile*              mResFile;
    sead::Buffer<ModelShaderArchive>    mModelShaderArchive;
    u32                                 _1c;
};
static_assert(sizeof(ModelResource) == 0x20);
