#pragma once

#include <player/PlayerModel.h>

class ShadowModel : public PlayerModel   // vtbl Address: 0x101748B8
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EBA84
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EBA90
    SEAD_RTTI_OVERRIDE(ShadowModel, PlayerModel)

public:
    static const s32 cMaterialMaxNum = 4;

public:
    // Address: 0x02971880
    ShadowModel(Type type, PlayerMode mode, SceneType scene_type, bool override_lightmap);

    // Address: 0x02971B34
    // void func(); // Sets _22C and _230

    // Address: 0x02971B4C
    void getBottomJointPos(sead::Vector3f* p_pos);

    // Address: 0x02971BC4
    void play() override;

    // Address: 0x02971BFC
    void draw() override;

    // Address: 0x02971C10
    void setModelDrawBufferIndex(s32 idx_opa, s32 idx_xlu) override;
    // Address: 0x02971C2C
    void setModelDrawFlagDirect(u32 flag) override;

    f32 getBaseScale() override
    {
        return 1.0f;
    }

    // Address: 0x02971CC0
    void setColorType(ColorType color_type, bool keep_head_konst3) override;

    // Address: 0x02971CCC
    void setStarAnm() override;
    // Address: 0x02971D84
    void cancelStarAnm_NowModeModel() override;
    // Address: 0x02971D88
    void cancelStarAnm_OldModeModel() override;

    // Address: 0x02971F3C
    void calcImpl() override;

    // Address: 0x02971FD4
    void setModeModel(PlayerModeModel mode_mdl) override;

    // Address: 0x02971FE4
    void setTexAnmTypeImpl(TexAnmType type) override;
    // Address: 0x02971FE8
    void setTexAnmType(TexAnmType type) override;

    bool getPlayerModeAnmResInfo(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id, bool body) override
    {
        return false;
    }

    // Address: 0x02971FEC
    bool getPlayerModeRideAnmResInfo(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id) override;

    f32 vf13C() override
    {
        return 1.0f;
    }

    // Address: 0x02971FF4
    f32 getAnmRate(s32 anm_id) override;
    // Address: 0x02972008
    f32 getAnmBlendDuration(s32 anm_id) override;

    // Address: 0x029720E4
    void setAnm(s32 anm_id, f32 rate, f32 blend_duration = 0.0f, f32 frame = 0.0f) override;
    // Address: 0x029724C4
    void setAnmImpl(const ModelResource* p_anm_res, const sead::SafeString& anm_name, FrameCtrl::PlayMode mode, f32 rate, f32 frame, f32 blend_duration) override;
    // Address: 0x029725A0
    void setBodyAnmImpl(const ModelResource* p_anm_res, const sead::SafeString& anm_name, FrameCtrl::PlayMode mode, f32 rate, f32 frame, f32 blend_duration) override;

    void releaseBodyAnm(f32 blend_duration) override
    {
    }

    // Address: 0x029725A4
    void setCarryBodyAnm(f32 blend_duration, bool bubble_reset_frame) override;

    // Address: 0x029725A8
    void setAnmBind() override;

    void setBodyRate(f32 rate) override
    {
    }

    void setBodyFrame(f32 frame) override
    {
    }

    // Address: 0x02972654
    void onPMusaChange() override;

    f32 vf144() override
    {
        return 0.0f;
    }

    // Address: 0x0297265C
    f32 getTevColor0Alpha(s32 idx_material) override;
    // Address: 0x02972678
    void setTevColor0Alpha(s32 idx_material, f32 value) override;

    // Address: 0x02972694
    void setInvTevColor0(f32 value) override;
    // Address: 0x0297275C
    void setTevKColor3(f32 value) override;

    // Address: 0x0297289C
    void setJointMap() override;

protected:
    ModelResource*                          mpShadowAnmRes;
    sead::SafeArray<f32, cMaterialMaxNum>   mTevColor0Alpha;
    s32                                     _22C;
    f32                                     _230;
};
static_assert(sizeof(ShadowModel) == 0x234);
