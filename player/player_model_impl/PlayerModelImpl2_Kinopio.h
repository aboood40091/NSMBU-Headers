#pragma once

#include <player/PlayerModel.h>

class KinopioModel : public PlayerModel   // vtbl Address: 0x10174520
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EBA80
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EBA9C
    SEAD_RTTI_OVERRIDE(KinopioModel, PlayerModel)

public:
    static const s32 cMaterialMaxNum = 4;

public:
    // Address: 0x0296EBDC
    KinopioModel(Type type, PlayerMode mode, SceneType scene_type, bool override_lightmap);

    // Address: 0x0296ED84
    void draw() override;

    // Address: 0x0296ED88
    void setColorType(ColorType color_type, bool keep_head_konst3) override;

    // Address: 0x0296F138
    void play() override;

    // Address: 0x0296F16C
    void calcImpl() override;

    // Address: 0x0296F1A0
    void setTexAnmTypeImpl(TexAnmType type) override;

    // Address: 0x0296FAD4
    bool getPlayerModeAnmResInfo(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id, bool body) override;
    // Address: 0x02971078
    bool getPlayerModeRideAnmResInfo(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id) override;

    // Address: 0x029711B4
    f32 vf13C() override;

    f32 vf144() override
    {
        return 0.0f;
    }

    // Address: 0x02971234
    f32 getTevColor0Alpha(s32 idx_material) override;
    // Address: 0x02971250
    void setTevColor0Alpha(s32 idx_material, f32 value) override;

    // Address: 0x0297126C
    void setMusaPtoNmlAnm() override;

protected:
    ModelResource*                          mpKinopioAnmRes;
    sead::SafeArray<f32, cMaterialMaxNum>   mTevColor0Alpha;
};
static_assert(sizeof(KinopioModel) == 0x22C);
