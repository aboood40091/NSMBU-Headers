#pragma once

#include <graphics/Material.h>

#include <container/seadSafeArray.h>
#include <math/seadMatrix.h>

#include <nw/g3d/g3d_MaterialObj.h>

class MaterialG3d : public Material  // vtbl Address: 0x100BBC1C
{
public:
    MaterialG3d(nw::g3d::MaterialObj* material)
        : mMaterialObj(material)
    {
    }

    // Address: 0x024E6CA4
    void setTexSrtMtx(s32 index, const sead::Vector2f& scale, const u32& rotate, const sead::Vector2f& translate) override;
    // Address: 0x024E7064
    void setTexSrt(s32 index, const sead::Vector2f& scale, const u32& rotate, const sead::Vector2f& translate) override;
    // Address: 0x024E71F0
    void getTexSrt(s32 index, sead::Vector2f* p_scale = nullptr, u32* p_rotate = nullptr, sead::Vector2f* p_translate = nullptr) const override;
    // Address: 0x024E737C
    void setTevColor(s32 index, const sead::Color4f& color) override;
    // Address: 0x024E74AC
    void getTevColor(s32 index, sead::Color4f& color) const override;
    // Address: 0x024E7598
    void setTevKColor(s32 index, const sead::Color4f& color) override;
    // Address: 0x024E76C8
    void getTevKColor(s32 index, sead::Color4f& color) const override;

    sead::Matrix34f& getTexSrtMtx(s32 index) { return mTexSrtMtx[index]; }
    const sead::Matrix34f& getTexSrtMtx(s32 index) const { return mTexSrtMtx[index]; }

private:
    nw::g3d::MaterialObj*               mMaterialObj;
    sead::SafeArray<sead::Matrix34f, 8> mTexSrtMtx;
};
static_assert(sizeof(MaterialG3d) == 0x188);
