#pragma once

#include <player/PlayerModel.h>

class MarioModel : public PlayerModel   // vtbl Address: 0x10173EBC
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EBA7C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EBA98
    SEAD_RTTI_OVERRIDE(MarioModel, PlayerModel)

public:
    enum BonusCapType
    {
        cBonusCap_Normal = 0,
        cBonusCap_Small,
        cBonusCap_Num
    };
    static_assert(cBonusCap_Num == 2);

    static const s32 cMaterialMaxNum = 4;

public:
    // Address: 0x0296CEB8
    MarioModel(Type type, PlayerMode mode, SceneType scene_type, bool override_lightmap);

    // Address: 0x0296D258
    void play() override;

    // Address: 0x0296D2AC
    void draw() override;

    // Address: 0x0296D310
    void setModelDrawBufferIndex(s32 idx_opa, s32 idx_xlu) override;
    // Address: 0x0296D3CC
    void setModelDrawFlagDirect(u32 flag) override;

    // Address: 0x0296D494
    void setCapMode(CapMode mode) override;
    // Address: Deleted
    void updateBonusCap() override;

    // Address: 0x0296D4AC
    void setColorType(ColorType color_type, bool keep_head_konst3) override;

    // Address: 0x0296D6EC
    void calcImpl() override;

    // Address: 0x0296D840
    void setModeModel(PlayerModeModel mode_mdl) override;

    // Address: 0x0296D880
    void setTexAnmTypeImpl(TexAnmType type) override;

    // Address: 0x0296D884
    bool setPersonalAnm(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id, bool body) override;

    // Address: 0x0296E140
    f32 getAimMotionShareScale() override;
    // Address: 0x0296E1D8
    f32 vf144() override;

    f32 getTevColor0Alpha(s32 idx_material) override
    {
        return mTevColor0Alpha[idx_material];
    }

    void setTevColor0Alpha(s32 idx_material, f32 value) override
    {
        mTevColor0Alpha[idx_material] = value;
    }

    // Address: 0x0296E24C
    void setMusaPtoNmlAnm() override;

protected:
    ModelResource*                              mpLuigiAnmRes;
    sead::SafeArray<AnimModel*, cBonusCap_Num>  mBonusCap;
    CapMode                                     mCapMode;
    BonusCapType                                mBonusCapType;
    bool                                        mIsBonusCap;
    sead::SafeArray<f32, cMaterialMaxNum>       mTevColor0Alpha;
};
static_assert(sizeof(MarioModel) == 0x240);
