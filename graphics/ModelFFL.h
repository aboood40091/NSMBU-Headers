#pragma once

#include <graphics/Mii_DataSource.h>
#include <graphics/Mii_WmModeDB.h>
#include <graphics/RenderObj.h>

#include <common/aglTextureData.h>
#include <gfx/seadColor.h>
#include <heap/seadDisposer.h>

#include <nn/ffl.h>

class ModelFFL : public RenderObj, sead::IDisposer    // vtbl Address: 0x100BCCF8
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9E80
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EAE5C
    SEAD_RTTI_OVERRIDE(ModelFFL, RenderObj)

public:
    enum Lightmap02pType
    {
        cLightmap02pType_LightMapMgr = 0,
        cLightmap02pType_0,
        cLightmap02pType_1
    };
    static_assert(sizeof(Lightmap02pType) == 4);

    enum LightMapType
    {
        cLightmapType_LightMapMgr_Index_4 = 0,
        cLightmapType_LightMapMgr_Index_0
    };
    static_assert(sizeof(LightMapType) == 4);

    enum InitializeStep
    {
        cInitializeStep_NeedInitializeCpu = 0,
        cInitializeStep_NeedInitializeGpu,
        cInitializeStep_Done
    };
    static_assert(sizeof(InitializeStep) == 4);

    enum DrawType
    {
        cDrawType_Normal = 0,
        cDrawType_Special
    };
    static_assert(sizeof(DrawType) == 4);

    template <typename T>
    struct InitArg
    {
        FFLCharModelDesc    desc;
        const T*            data;
        u16                 index;
    };

    typedef InitArg<FFLStoreData>   InitArgStoreData;
    typedef InitArg<FFLMiddleDB>    InitArgMiddleDB;

    static_assert(sizeof(InitArgStoreData) == 0x1C);
    static_assert(sizeof(InitArgMiddleDB) == 0x1C);

public:
    // Address: 0x024EF694
    ModelFFL(s32 opa_buffer_idx, s32 xlu_buffer_idx);

    // Address: 0x024F04CC
    virtual ~ModelFFL()
    {
        destroy();
    }

    // Address: 0x024EF900
    bool initialize(const FFLCharModelDesc* p_desc, const sead::Vector3f& scale, sead::Heap* heap, sead::Heap* heap_tmp);
    // Address: 0x024EFAC0
    bool initialize(Mii::DataSource source, const FFLCharModelDesc* p_desc, const sead::Vector3f& scale, sead::Heap* heap, sead::Heap* heap_tmp);

    template <typename T>
    bool initialize(const InitArg<T>& arg, const sead::Vector3f& scale, sead::Heap* heap, sead::Heap* heap_tmp);

    // Address: 0x024EF62C
    void destroy();

    // Address: 0x024EF680
    void initExRegColor();
    // Address: 0x024EF63C
    void setExRegColor(const sead::Color4f& light, const sead::Color4f& dark);

    // Address: 0x024EFB88
    void updateMtxSRT();

    // Address: 0x024EFBE8
    void setSpecialDrawType();

    // Address: 0x024F0708
    void calc() override;
    // Address: 0x024EFBF4
    void updateView(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;
    // Address: 0x024EFBF8
    void calcGPU(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;
    // Address: 0x024EFE58
    void drawOpa(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;
    // Address: 0x024F009C
    void drawXlu(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;

    // Address: 0x024F0134
    bool getAdditionalInfo(FFLAdditionalInfo* p_additional_info, BOOL checkFontRegion) const;
    // Address: 0x024F01E0
    sead::Color4f getFavoriteColor() const;

    // Address: 0x024EF9F4
    bool initializeCpu(const FFLCharModelSource* p_source, const FFLCharModelDesc* p_desc);
    // Address: 0x024F03C8
    void initializeGpu();

    void setMtxRT(const sead::Matrix34f& mtx)
    {
        mMtxRT = mtx;
        updateMtxSRT();
    }

    void setScale(const sead::Vector3f& scale)
    {
        mScale.set(scale);
        updateMtxSRT();
    }

    agl::TextureData* getLightmap02p_0() const
    {
        return mLightmap02p_0;
    }

    agl::TextureData* getLightmap02p_1() const
    {
        return mLightmap02p_1;
    }

    Lightmap02pType getLightmap02pType() const
    {
        return mLightmap02pType;
    }

    LightMapType getLightMapType() const
    {
        return mLightMapType;
    }

private:
    // Address: 0x024EF840
    bool allocBuffer_();

    // Address: 0x024EFBFC
    void setEnvUniform_(RenderMgr* p_render_mgr);
    // Address: 0x024EFC70
    void setEnvViewUniform_(const sead::Matrix34f& model_mtx, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr);
    // Address: 0x024EFCD4
    void setEnvViewUniformWithLightmapEnable_(const sead::Matrix34f& model_mtx, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr);

    // Addres: 0x024EFD74
    void drawOpaNormal_();
    // Addres: 0x024EFD08
    void drawOpaSpecial_();

    // Addres: 0x024EFFB8
    void drawXluNormal_();
    // Addres: 0x024EFEC4
    void drawXluSpecial_();

    // Address: 0x024EF9C4
    bool initializeCpu_(const FFLCharModelSource* p_source, const FFLCharModelDesc* p_desc);
    // Address: 0x024F0358
    void initializeGpu_();

    // Address: 0x024EFA44
    bool setCharModelSource_(const FFLStoreData* p_store_data);
    // Address: 0x024F041C
    bool setCharModelSource_(const FFLMiddleDB* p_middle_db, u16 index);

    // Address: 0x024EFAAC
    void pushBackModelGpuInitializer_();

private:
    sead::Heap*             mpHeap;
    sead::Heap*             mpHeapTmp;
    FFLCharModel            mCharModel;
    FFLCharModelBuffer      mCharModelBuffer;
    u32                     _814;
    FFLCharModelDesc        mCharModelDesc;
    FFLCharModelSource      mCharModelSource;
    sead::Matrix34f         mMtxRT;
    sead::Vector3f          mScale;
    sead::Matrix34f         mMtxSRT;
    sead::Color4f           mExLightRegColor;
    sead::Color4f           mExDarkRegColor;
    agl::TextureData*       mLightmap02p_0;
    agl::TextureData*       mLightmap02p_1;
    Lightmap02pType         mLightmap02pType;
    LightMapType            mLightMapType;
    bool                    mDrawOpaWithXlu;
    InitializeStep          mInitializeStep;
    DrawType                mDrawType;
    Mii::WmModeDB::Model*   mpWmModeDBModel;
    Mii::DataSource         mDataSource;
    s32                     mOpaBufferIdx;
    s32                     mXluBufferIdx;
};
static_assert(sizeof(ModelFFL) == 0x8F0);

// Address: 0x024F070C
template <>
bool ModelFFL::initialize<FFLStoreData>(const InitArgStoreData& arg, const sead::Vector3f& scale, sead::Heap* heap, sead::Heap* heap_tmp)
{
    if (!initialize(&mCharModelDesc, scale, heap, heap_tmp))
        return false;

    if (!setCharModelSource_(arg.data))
        return false;

    pushBackModelGpuInitializer_();
    return true;
}

// Address: 0x024EE1B0
template <>
bool ModelFFL::initialize<FFLMiddleDB>(const InitArgMiddleDB& arg, const sead::Vector3f& scale, sead::Heap* heap, sead::Heap* heap_tmp)
{
    if (!initialize(&mCharModelDesc, scale, heap, heap_tmp))
        return false;

    if (!setCharModelSource_(arg.data, arg.index))
        return false;

    pushBackModelGpuInitializer_();
    return true;
}
