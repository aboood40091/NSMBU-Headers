#pragma once

#include <graphics/CalcRatioSRT.h>
#include <player/PlayerEnum.h>
#include <player/PlayerModelBase.h>

struct PlayerObjectResHIO
{
    sead::SafeString    model_res_key;
    sead::SafeString    anm_res_key;
    sead::SafeString    body_mdl_name[cPlayerModeModel_Num];
    sead::SafeString    head_mdl_name[cPlayerModeModel_Num];
    f32                 _60;
    f32                 _64;
    f32                 _68;    // Always same value as _60
    f32                 _6c;    // ^^^
    f32                 _70;    // ^^^
};
static_assert(sizeof(PlayerObjectResHIO) == 0x74);

class PlayerModel : public PlayerModelBase // vtbl Address: 0x1016BA2C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9D28
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EBA74
    SEAD_RTTI_OVERRIDE(PlayerModel, PlayerModelBase)

public:
    enum ColorType
    {
        cColorType_Invalid = 0,
        cColorType_Normal,
        cColorType_Fire,
        cColorType_Ice
    };
    static_assert(sizeof(ColorType) == 4);

    enum JointID
    {
        cJointID_AllRoot = 0,
        cJointID_SklRoot,
        cJointID_LegL1,
        cJointID_LegL2,
        cJointID_AnkleL1,
        cJointID_LegR1,
        cJointID_LegR2,
        cJointID_AnkleR1,
        cJointID_Spin,
        cJointID_ArmL1,
        cJointID_ArmL2,
        cJointID_WristL1,
        cJointID_ArmR1,
        cJointID_ArmR2,
        cJointID_WristR1,
        cJointID_CapPosition,
        cJointID_Face1,
        cJointID_WingLegL,
        cJointID_WingLegR,
        cJointID_WingArmL,
        cJointID_WingArmR,
        cJointID_Wing,
        cJointID_WingTail1,
        cJointID_WingTail2,
        cJointID_Num
    };
    static_assert(cJointID_Num == 24);

    enum EnvType
    {
        cEnvType_Normal = 0,
        cEnvType_Star,
        cEnvType_P
    };

    enum EnvTypeFlag
    {
        cEnvTypeFlag_Star   = 1 << cEnvType_Star,
        cEnvTypeFlag_P      = 1 << cEnvType_P
    };

public:
    // Address: 0x0291A230
    PlayerModel(const PlayerObjectResHIO& res_hio, Type type, PlayerMode mode, SceneType scene_type, bool override_lightmap);

    virtual ~PlayerModel()
    {
    }

    // Address: 0x02920A18
    void calc2Impl() override;

    // Address: 0x0291A3D8
    void draw() override;

    // Address: 0x0291A420
    f32 getBaseScale() override;

    // Address: 0x0291A444
    void setModelDrawBufferIndex(s32 idx_opa, s32 idx_xlu) override;
    // Address: 0x0291A530
    void setModelDrawFlagDirect(u32 flag) override;

    // Address: 0x0291A720
    void setTevColorOverride(TevColorOverrideType type, f32 value) override;

    // Address: 0x0291A744
    void onStarAnm() override;
    // Address: 0x0291A768
    void offStarAnm() override;

    PlayerMode getPlayerMode()
    {
        return mPlayerMode;
    }

    // Address: 0x0291AC9C
    void setPlayerMode(PlayerMode mode);

    // Address: 0x0291ADF0
    bool getHeadPropelJointMtx(sead::Matrixf* p_mtx);

    // Address: 0x0291AE58
    bool checkChange_MusaPtoNml();
    // Address: 0x0291AFAC
    void postChange_MusaPtoNml();

    // Address: 0x0291AFF4
    bool isFaceRot();
    // Address: 0x0291B004
    void setClampFaceRot();

    virtual void setColorType(ColorType color_type, bool keep_head_konst3) = 0;

    virtual void setMiiColor(PlayerCharacter mii_color)
    {
    }

    virtual void setCapMode(CapMode mode)
    {
    }

    virtual void updateBonusCap()
    {
    }

    virtual void setMusaPtoNmlAnm()
    {
    }

    virtual void setPlayerNo(s32 player_no)
    {
        mPlayerNo = player_no;
    }

    virtual void setMiiCapVisible(bool visible)
    {
    }

    virtual bool isMiiCapVisible()
    {
        return false;
    }

    PlayerModeModel getModeModel()
    {
        return mNowModeModel;
    }

    // Address: 0x0291BEEC
    virtual void setModeModel(PlayerModeModel mode_mdl);

    // Address: 0x0291BF94
    void setTexAnmType(TexAnmType type) override;

    virtual void setTexAnmTypeImpl(TexAnmType type) = 0;

    // Address: 0x0291C4D8
    bool getPlayerModeAnmResInfo(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id, bool body) override;
    // Address: 0x0291DDE4
    bool getPlayerModeRideAnmResInfo(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id) override;

    // Address: 0x0291E8C0
    void setAnm(s32 anm_id, f32 rate, f32 blend_duration = 0.0f, f32 frame = 0.0f) override;
    // Address: 0x0291E9A8
    void setFootAnmImpl(const ModelResource* p_anm_res, const sead::SafeString& anm_name, FrameCtrl::PlayMode mode, f32 rate, f32 frame, f32 blend_duration) override;
    // Address: 0x0291EB30
    void setBodyAnmImpl(const ModelResource* p_anm_res, const sead::SafeString& anm_name, FrameCtrl::PlayMode mode, f32 rate, f32 frame, f32 blend_duration) override;
    // Address: 0x0291ED04
    void releaseBodyAnm(f32 blend_duration) override;
    // Address: 0x0291EF78
    void setCarryBodyAnm(f32 blend_duration, bool bubble_reset_frame) override;

    // Address: 0x0291F180
    void setAnmBind() override;

    virtual f32 vf13C() = 0;
    virtual f32 vf144() = 0;

    // Address: 0x0291F6B8
    virtual void onPMusaChange();

    // Address: 0x0291F8F8
    virtual void setStarAnm();
    // Address: 0x0291FB58
    virtual void removeStarAnm_NowModeModel();
    // Address: 0x0291FB64
    virtual void removeStarAnm_OldModeModel();

    virtual f32 getTevColor0Alpha(s32 idx_material) = 0;
    virtual void setTevColor0Alpha(s32 idx_material, f32 value) = 0;

    // Address: 0x0291FB9C
    virtual void setInvTevColor0(f32 value);
    // Address: 0x0291FD90
    virtual void setTevKColor3(f32 value);

    // Address: 0x0291FF7C
    virtual void setJointMap();

    // Address: 0x02920118
    void getJointMtx(sead::Matrixf* p_mtx, const sead::SafeString& name) override;

    void setPropelRollAngle(const Angle& angle)
    {
        mPropelRollAngle = angle;
    }

    void setPropelRollSpeed(const Angle& speed)
    {
        mPropelRollSpeed = speed;
    }

    void setPropelScale(f32 scale)
    {
        mPropelScale = scale;
    }

    AnimModel* getBodyModel(PlayerModeModel mode_mdl)
    {
        return mModelArray[mode_mdl];
    }

    AnimModel* getHeadModel(PlayerModeModel mode_mdl)
    {
        return mModelArray[mode_mdl];
    }

protected:
    sead::SafeArray<AnimModel*, cPlayerModeModel_Num>   mModelArray;
    sead::SafeArray<AnimModel*, cPlayerModeModel_Num>   mHeadModelArray;
    const PlayerObjectResHIO&                           mResHio;
    AnimModel*                                          mpHeadModel;
    PlayerModeModel                                     mOldModeModel;
    PlayerModeModel                                     mNowModeModel;
    sead::BitFlag16                                     mModeModelLoadFlag;
    sead::SafeArray<s32, cJointID_Num>                  mJointMap;
    s32                                                 mPlayerNo;
    CalcRatioSRT                                        mCalcRatio;
    PlayerMode                                          mPlayerMode;
    PlayerMode                                          mPlayerModeOverride;
    ColorType                                           mColorType;
    Angle                                               mFaceAngle;
    Angle                                               mFaceAngleTarget;
    s32                                                 mFaceRotTimer;
    s32                                                 mFaceRotFrameCnt;
    bool                                                mClampFaceRotTimer;
    Angle                                               mPropelRollAngle;
    Angle                                               mPropelRollSpeed;
    f32                                                 mPropelScale;
    f32                                                 mBlendRate_v0;
    f32                                                 mBlendRate_v1;
    f32                                                 mBlendRate_v2;
    TevColorOverrideType                                mTevColorOverrideType;
    f32                                                 mTevColorOverrideValue;
    sead::BitFlag32                                     mEnvTypeFlag;
    bool                                                mOverrideLightMap;
};
static_assert(sizeof(PlayerModel) == 0x218);
