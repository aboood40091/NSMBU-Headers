#pragma once

#include <graphics/Mii_SlotID.h>
#include <player/PlayerModel.h>

#include <common/aglTextureData.h>

class ModelFFL;

class MiiModel : public PlayerModel   // vtbl Address: 0x10174D6C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9E84
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EBA70
    SEAD_RTTI_OVERRIDE(MiiModel, PlayerModel)

public:
    static const s32 cMaterialMaxNum = 7;

    enum ModeHeadModel
    {
        cModeHeadModel_Normal = 0,
        cModeHeadModel_Propeller,
        cModeHeadModel_Penguin,
        cModeHeadModel_Squirrel,
        cModeHeadModel_Num
    };
    static_assert(cModeHeadModel_Num == 4);

public:
    // Address: 0x029735D8
    MiiModel(Type type, PlayerMode mode, SceneType scene_type, PlayerCharacter color, const Mii::SlotID& slot_id, sead::Heap* p_ffl_tmp_heap, bool override_lightmap);

    // Address: 0x02973800
    void play() override;

    // Address: 0x029738CC
    void draw() override;

    // Address: 0x02973908
    void setModelDrawBufferIndex(s32 idx_opa, s32 idx_xlu) override;
    // Address: 0x029739B0
    void setModelDrawFlagDirect(u32 flag) override;

    // Address: 0x02973BA0
    void setColorType(ColorType color_type, bool keep_head_konst3) override;

    // Address: 0x02973EB4
    void setMiiColor(PlayerCharacter mii_color) override;

    void setMiiCapVisible(bool visible) override
    {
        mIsCapVisible = visible;
    }

    bool isMiiCapVisible() override
    {
        return mIsCapVisible;
    }

    // Address: 0x02974354
    void calcImpl() override;

    // Address: 0x0297444C
    void setModeModel(PlayerModeModel mode_mdl) override;
    
    // Address: 0x029744EC
    void setTexAnmTypeImpl(TexAnmType type) override;

    // Address: 0x0297453C
    bool getPlayerModeAnmResInfo(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id, bool body) override;
    // Address: 0x029748B4
    bool getPlayerModeRideAnmResInfo(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id) override;

    // Address: 0x029749F0
    f32 vf13C() override;

    // Address: 0x02974ADC
    void onPMusaChange() override;

    // Address: 0x02974B68
    void setStarAnm() override;
    // Address: 0x02974CD0
    void removeStarAnm_NowModeModel() override;
    // Address: 0x02974CDC
    void removeStarAnm_OldModeModel() override;

    // Address: 0x02974D18
    f32 vf144() override;

    f32 getTevColor0Alpha(s32 idx_material) override
    {
        return mTevColor0Alpha[idx_material];
    }

    void setTevColor0Alpha(s32 idx_material, f32 value) override
    {
        mTevColor0Alpha[idx_material] = value;
    }

    // Address: 0x02974D7C
    void setInvTevColor0(f32 value) override;
    // Address: 0x02974E68
    void setTevKColor3(f32 value) override;

protected:
    ModelResource*                          mpMiiAnmRes;
    PlayerCharacter                         mColor;
    Mii::SlotID                             mSlotID;
    ModelFFL*                               mpFaceModel;
    agl::TextureData                        mEnvTexture_Star;
    agl::TextureData                        mEnvTexture_P;
    f32                                     mHeadPatAnmFrame;
    f32                                     mHeadPatAnmRate;
    FrameCtrl::PlayMode                     mHeadPatAnmPlayMode;
    sead::SafeArray<f32, cMaterialMaxNum>   mTevColor0Alpha;
    ModeHeadModel                           mNowModeHeadModel;
    ModeHeadModel                           mOldModeHeadModel;
    sead::SafeArray<
        AnimModel*,
        cModeHeadModel_Num
    >                                       mModeHeadModelArray;
    AnimModel*                              mpModeHeadModel;
    sead::BitFlag16                         mModeHeadModelLoadFlag;
    bool                                    mIsCapVisible;
};
static_assert(sizeof(MiiModel) == 0x3A8);
