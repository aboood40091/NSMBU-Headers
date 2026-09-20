#pragma once

#include <graphics/AnimExpDecayCalcRatio.h>
#include <player/PlayerEnum.h>
#include <player/PlayerModelBase.h>

struct PlayerObjectResHIO;

class PlayerModel : public PlayerModelBase // vtbl Address: 0x1016BA2C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9D28
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EBA74
    SEAD_RTTI_OVERRIDE(PlayerModel, PlayerModelBase)

public:
    enum BodyType
    {
        cBodyType_Normal = 0,
        cBodyType_Small,
        cBodyType_Propeller,
        cBodyType_Penguin,
        cBodyType_Squirrel,
        cBodyType_Num
    };
    static_assert(cBodyType_Num == 5);
    static_assert(sizeof(BodyType) == 4);

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
        cJointID_Num,

        cJointID_NumWing = cJointID_WingTail2 - cJointID_WingLegL + 1
    };
    static_assert(cJointID_Num == 24);
    static_assert(cJointID_NumWing == 7);

    enum EnvType
    {
        cEnvType_Normal = 0,
        cEnvType_Star,
        cEnvType_P,
        cEnvType_Num
    };
    static_assert(cEnvType_Num == 3);

    enum EnvTypeFlag
    {
        cEnvTypeFlag_Star   = 1 << cEnvType_Star,
        cEnvTypeFlag_P      = 1 << cEnvType_P
    };

    struct TexAnmData
    {
        sead::SafeString    name;
        FrameCtrl::PlayMode play_mode;
        f32                 rate;
        f32                 frame;      // No longer used
    };
    static_assert(sizeof(TexAnmData) == 0x14);

    enum
    {
        cSklAnm_Tail = cSklAnm_BaseNum,
        cSklAnm_Num
    };
    static_assert(cSklAnm_Num == 3);

    enum
    {
        cTexAnm_Color = 0,
        cTexAnm_Head,
        cTexAnm_Num
    };
    static_assert(cTexAnm_Num == 2);

    enum
    {
        cShuAnm_Color_Star = 0,
        cShuAnm_1,
        cShuAnm_2,
        cShuAnm_Num
    };
    static_assert(cShuAnm_Num == 3);

public:
    // Address: 0x0291A230
    PlayerModel(const PlayerObjectResHIO& res_hio, Type type, PlayerMode mode, SceneType scene_type, bool override_lightmap);

    // Address: 0x0291A3D8
    void draw() override;

    // Address: 0x0291A420
    f32 getBaseScale() override;

    // Address: 0x0291A444
    void setModelRenderPass(s32 idx_opa, s32 idx_xlu) override;
    // Address: 0x0291A530
    void setModelG3dRenderFlag(u32 flag) override;

    // Address: 0x0291A720
    void setDark(DarkTargetType type, f32 value) override;
    // Address: 0x0291A664
    void applyDark(DarkTargetType type, f32 value);

    // Address: 0x0291A744
    void onStarAnm() override;
    // Address: 0x0291A768
    void offStarAnm() override;

    // Address: 0x0291A78C
    void getFaceMtx(sead::Matrixf* p_mtx);

    PlayerMode getPlayerMode()
    {
        return mPlayerMode;
    }

    // Address: 0x0291A980
    void setPlayerModel(PlayerMode mode);

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

    // Address: 0x0291B010
    void createPlayerModel(const sead::PtrArray<ModelResource>* p_anim_mdl_res_array);

    // Address: 0x0291B348
    void playBody();
    // Address: 0x0291B448
    void playHead();

    // Address: 0x0291BD40
    void calcBody();
    // Address: 0x0291BDF0
    void calcHead();

    // Address: 0x0291A1CC
    void setModelLoadFlag();

    // Address: 0x0291B384
    void calcBlinkFrame();

    // Address: 0x0291B494
    void calcFaceAngle();

    // Address: 0x0291AB0C
    void calcBlendRate();

    // Address: 0x0291B73C
    void calcMusaWing();

    // Address: 0x0291B8F8
    void calcFaceAngleOverride();

    // Address: 0x0291BA00
    void calcJointLocalMtxPostAnm();

    // Address: 0x0291BC70
    void calcHeadPos();

    // Address: 0x0291AA1C
    void copyAnm();

    // Address: 0x0291AB50
    void resetTexAnmType();

    virtual void setColorType(ColorType color_type, bool keep_head_konst3) = 0;

    virtual void setMiiColor(PlayerCharacter mii_color)
    {
    }

    virtual void setHeadID(HeadType id)
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

    BodyType getBodyID()
    {
        return mNowBodyID;
    }

    // Address: 0x0291BEEC
    virtual void setBodyID(BodyType id);

    // Address: 0x0291BF10
    void setHeadTexAnm(TexAnmType type);

    // Address: 0x0291BF94
    void setTexAnmType(TexAnmType type) override;

    virtual void setTexAnmTypeImpl(TexAnmType type) = 0;

    // Address: 0x0291BEFC
    const TexAnmData& getTexAnmData(TexAnmType type) const;

    // Address: 0x02920A18
    void calc2Impl() override;

    // Address: 0x0291C4D8
    bool setPersonalAnm(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id, bool body) override;
    // Address: 0x0291DDE4
    bool setPersonalRideAnm(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id) override;

    // Address: 0x0291BFF4
    bool getLowWalkAnmName(sead::BufferedSafeString* p_anm_name, s32 anm_id, bool body);

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

    // Address: 0x0291E8EC
    void setTailAnm(const ModelResource* p_anm_res, const sead::SafeString& anm_name, FrameCtrl::PlayMode mode, f32 rate, f32 frame);

    // Address: 0x0291EC24
    bool releaseMusaGlideCarryAnm(f32 blend_duration);

    // Address: 0x0291F180
    void setAnmBind() override;

    virtual f32 getAimMotionShareScale() = 0;
    virtual f32 getStoopOffsetTarget() = 0;

    // Address: 0x0291F6B8
    virtual void onPMusaChange();

    // Address: 0x0291F430
    void changeLightTexture(AnimModel& anim_model);

    // Address: 0x0291F408
    EnvType getEnvType() const;

    // Address: 0x0291F734
    void setStarAnm(AnimModel* p_anim_model, const ModelResource* p_mdl_res, const sead::SafeString& name, f32 frame);
    // Address: 0x0291F7B0
    void removeStarAnm(AnimModel* p_anim_model);

    // Address: 0x0291F8F8
    virtual void setStarAnm();
    // Address: 0x0291FB58
    virtual void removeStarAnm_NowBodyID();
    // Address: 0x0291FB64
    virtual void removeStarAnm_OldBodyID();

    // Address: 0x0291FAB0
    void removeStarAnm(AnimModel* p_head_anim_model, AnimModel* p_body_anim_model);

    // Address: 0x0291F9C0
    void resetTevKColor3Alpha(Model* p_model);

    virtual f32 getTevColor0Alpha(s32 idx_material) = 0;
    virtual void setTevColor0Alpha(s32 idx_material, f32 value) = 0;
    // Address: 0x0291AB74
    void resetTevColor0Alpha();

    // Address: 0x0291FB9C
    virtual void setInvTevColor0(f32 value);
    // Address: 0x0291FD90
    virtual void setTevKColor3(f32 value);

    // Address: 0x0291FF7C
    virtual void setJointMap();

    // Address: 0x02920024
    JointID getJointID(const sead::SafeString& name) const;

    void getJointMtx(sead::Matrixf* p_mtx, JointID id)
    {
        PlayerModelBase::getJointMtx(p_mtx, mJointMap[id]);
    }

    void getJointPos(sead::Vector3f* p_pos, JointID id)
    {
        PlayerModelBase::getJointPos(p_pos, mJointMap[id]);
    }

    // Address: 0x02920118
    void getJointMtx(sead::Matrixf* p_mtx, const sead::SafeString& name) override;

    void getJointPos(sead::Vector3f* p_pos, const sead::SafeString& name)
    {
        PlayerModelBase::getJointPos(p_pos, name);
    }

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

    AnimModel* getBodyModel(BodyType type)
    {
        return mModelArray[type];
    }

    AnimModel* getHeadModel(BodyType type)
    {
        return mModelArray[type];
    }

private:
    inline void setHeadTexAnm_(AnimModel& head_anim_model, const TexAnmData& tex_anm_data);

protected:
    sead::SafeArray<AnimModel*, cBodyType_Num>  mModelArray;
    sead::SafeArray<AnimModel*, cBodyType_Num>  mHeadModelArray;
    const PlayerObjectResHIO&                   mResHio;
    AnimModel*                                  mpHeadModel;
    BodyType                                    mOldBodyID;
    BodyType                                    mNowBodyID;
    sead::BitFlag16                             mModelLoadFlag;
    sead::SafeArray<s32, cJointID_Num>          mJointMap;
    s32                                         mPlayerNo;
    AnimExpDecayCalcRatio                       mCalcRatio;
    PlayerMode                                  mPlayerMode;
    PlayerMode                                  mPlayerModeOverride;
    ColorType                                   mColorType;
    Angle                                       mFaceAngle;
    Angle                                       mFaceAngleTarget;
    s32                                         mFaceRotTimer;
    s32                                         mFaceRotFrameCnt;
    bool                                        mClampFaceRotTimer;
    Angle                                       mPropelRollAngle;
    Angle                                       mPropelRollSpeed;
    f32                                         mPropelScale;
    f32                                         mAimMotionScale;        // lerp of mAimMotionScaleBase and mAimMotionScaleTarget
    f32                                         mAimMotionScaleTarget;
    f32                                         mAimMotionScaleBase;
    DarkTargetType                              mDarkTargetType;
    f32                                         mDarkColorValue;
    sead::BitFlag32                             mEnvTypeFlag;
    bool                                        mOverrideLightMap;

    // Address: 0x1022AA9C
    static const Angle cPropelRollBaseSpeed;

    // Address: 0x101E699C
    static const TexAnmData cTexAnmData[];
};
static_assert(sizeof(PlayerModel) == 0x218);
