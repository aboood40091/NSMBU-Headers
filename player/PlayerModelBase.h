#pragma once

#include <graphics/FrameCtrl.h>
#include <utility/Angle.h>

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <math/seadMatrix.h>
#include <prim/seadRuntimeTypeInfo.h>
#include <prim/seadSafeString.h>

class AnimModel;
class ModelResource;

class PlayerModelBase : public sead::IDisposer  // vtbl Address: 0x1016BCE4
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9D24
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EBA78
    SEAD_RTTI_BASE(PlayerModelBase)

public:
    enum Type
    {
        cType_Mario = 0,
        cType_Luigi,
        cType_BlueToad,
        cType_YellowToad,
        cType_NpcToad,      // i.e., Red Toad
        cType_Nabbit,
        cType_Unused,       // No idea why this exists
        cType_Mii,
        cType_Num
    };
    static_assert(cType_Num == 8);
    static_assert(sizeof(Type) == 4);

    enum SceneType
    {
        cSceneType_Course = 0,
        cSceneType_CourseSelect,
        cSceneType_Unknown,
        cSceneType_2D               // i.e., for menus
    };
    static_assert(sizeof(SceneType) == 4);
    
    enum TexAnmType
    {
        cTexAnmType_WaitStatic = 0,
        cTexAnmType_Wait,
        cTexAnmType_GoalPutOnCap,
        cTexAnmType_PropellerGoalPutOnCap,
        cTexAnmType_PenguinGoalPutOnCap,
        cTexAnmType_MusaGoalPutOnCap,
        cTexAnmType_PenguinRideGoalPutOnCap,
        cTexAnmType_MusaRideGoalPutOnCap,
        cTexAnmType_GoalPutOnCap_2,
        cTexAnmType_Dam,
        cTexAnmType_Jump,
        cTexAnmType_Jumped,
        cTexAnmType_Throw,
        cTexAnmType_CourseIn,
        cTexAnmType_CoinComp,
        cTexAnmType_DmGlad,
        cTexAnmType_DmGlad2,
        cTexAnmType_DmGlad2Wait,
        cTexAnmType_DmGlad3,
        cTexAnmType_DmGlad3Wait,
        cTexAnmType_DmGlad4Wait,
        cTexAnmType_DmSad,
        cTexAnmType_BalloonWaitDisconnect,
        cTexAnmType_KinopioMGGlad,
        cTexAnmType_KinopioMGSad,
        cTexAnmType_DmCourseIn,
        cTexAnmType_DmSad2,
        cTexAnmType_KinopioDmThanksGift,
        cTexAnmType_KinopioDmHail,
        cTexAnmType_KinopioDmDamage,
        cTexAnmType_KinopioDmAwawa,
        cTexAnmType_KinopioDmShoot,
        cTexAnmType_DmEscort,
        cTexAnmType_DmEscortWait,
        cTexAnmType_DmEnding1,
        cTexAnmType_DmEnding1Wait,
        cTexAnmType_DmEnding2,
        cTexAnmType_Num
    };
    static_assert(cTexAnmType_Num == 37);
    static_assert(sizeof(cTexAnmType_Num) == 4);

    enum TevColorOverrideType
    {
        cTevColorOverrideType_InvTevColor0 = 0,
        cTevColorOverrideType_TevKColor3
    };
    static_assert(sizeof(TevColorOverrideType) == 4);

    enum Flag
    {
        cFlag_IsCarry                   = 1 <<  0,
        cFlag_IsLiftUp                  = 1 <<  1,
        cFlag_IsBalloonChibiYoshiFly    = 1 <<  2,
        cFlag_IsBubbleChibiYoshiShake   = 1 <<  3,
        // ...
        cFlag_IsStarAnm                 = 1 << 10,

        cFlag_None                      = 0
    };

    enum AnmFlag
    {
        cAnmFlag_0              = 1 << 0,
        // ...
        cAnmFlag_IsSlopeBodyAnm = 1 << 12,

        cAnmFlag_None           = 0
    };
    static_assert(sizeof(AnmFlag) == 4);

    enum AnmFlagType
    {
        cAnmFlagType_Main = 0,
        cAnmFlagType_Body,
        cAnmFlagType_Unknown,
        cAnmFlagType_Num
    };
    static_assert(cAnmFlagType_Num == 3);

    enum FaceAngleOverrideFlag
    {
        cFaceAngleOverrideFlag_X = 1 << 0,  // Never used
        cFaceAngleOverrideFlag_Y = 1 << 1,
        cFaceAngleOverrideFlag_Z = 1 << 2
    };

    enum CapMode
    {
        cCapMode_Normal = 0,
        cCapMode_Bonus
    };
    static_assert(sizeof(CapMode) == 4);
    
public:
    // Address: 0x02920CA8
    PlayerModelBase(const sead::SafeString& model_res_key, const sead::SafeString& anm_res_key);
    // Address: 0x02920E8C
    virtual ~PlayerModelBase();

    virtual void setTexAnmType(TexAnmType type) = 0;

    virtual bool getPlayerModeAnmResInfo(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id, bool body) = 0;
    virtual bool getPlayerModeRideAnmResInfo(ModelResource** pp_anm_res, sead::BufferedSafeString* p_anm_name, s32 anm_id) = 0;

    virtual void setFootAnmImpl(const ModelResource* p_anm_res, const sead::SafeString& anm_name, FrameCtrl::PlayMode mode, f32 rate, f32 frame, f32 blend_duration) = 0;
    virtual void setBodyAnmImpl(const ModelResource* p_anm_res, const sead::SafeString& anm_name, FrameCtrl::PlayMode mode, f32 rate, f32 frame, f32 blend_duration) = 0;

    virtual void setAnmBind() = 0;

    virtual void calcImpl() = 0;
    virtual void calc2Impl() = 0;

    virtual void setModelDrawBufferIndex(s32 idx_opa, s32 idx_xlu) = 0;
    virtual void setModelDrawFlagDirect(u32 flag) = 0;

    virtual void setTevColorOverride(TevColorOverrideType type, f32 value) = 0;

    // Address: 0x02920F88
    void reset();

    // Address: 0x02920F9C
    virtual f32 getAnmRate(s32 anm_id);
    // Address: 0x02920FB0
    virtual f32 getAnmBlendDuration(s32 anm_id);

    // Address: 0x02921524
    virtual void setAnm(s32 anm_id, f32 rate, f32 blend_duration = 0.0f, f32 frame = 0.0f);
    // Address: 0x02921280
    void setBodyAnm(s32 anm_id, f32 rate, f32 frame = 0.0f, f32 blend_duration = 0.0f);
    // Address: 0x029219F8
    void copyLinkAnm(f32 blend_duration);

    // Address: 0x02921444
    void setLinkAnm(s32 anm_id, f32 rate, f32 blend_duration = 0.0f, f32 frame = 0.0f);
    // Address: 0x02921A40
    void setRideAnm(s32 anm_id, f32 rate, f32 blend_duration = 0.0f, f32 frame = 0.0f);
    // Address: 0x029214F0
    void setSlopeBodyAnm(f32 blend_duration);
    virtual void releaseBodyAnm(f32 blend_duration) = 0;
    virtual void setCarryBodyAnm(f32 blend_duration, bool bubble_reset_frame) = 0;

    // Address: 0x02921DB4
    void setJumpIndex(s32 rnd_type);
    // Address: 0x02921E50
    virtual bool getJumpAnmName(sead::BufferedSafeString* p_anm_name, s32 anm_id, bool body);

    // Address: 0x02921088
    void setRate(f32 rate);
    // Address: 0x029219F0
    f32 getRate();

    // Address: 0x02921058
    void setRateDirect(f32 rate);
    // Address: 0x029220E0
    f32 getRateDirect();

    // Address: 0x029220E8
    virtual void setBodyRate(f32 rate);
    // Address: 0x029214E0
    f32 getBodyRate();

    // Address: 0x0292211C
    bool isAnmStop();
    // Address: 0x02922124
    bool isBodyAnmStop();

    // Address: 0x02921178
    void setFrame(f32 frame);
    // Address: 0x02921210
    f32 getFrame();

    // Address: 0x02921170
    void setFrameDirect(f32 frame);
    f32 getFrameDirect() { return getFrame(); }

    // Address: 0x0292212C
    virtual void setBodyFrame(f32 frame);
    // Address: 0x029214E8
    f32 getBodyFrame();

    // Address: 0x02922158
    bool checkFrame(f32 frame);
    // Address: 0x02922160
    bool checkBodyFrame(f32 frame);

    // Address: 0x02922194
    bool checkFrameCtrlFlagUnk2();
    // Address: Deleted
    bool checkBodyFrameCtrlFlagUnk2();

    // Address: 0x0292219C
    f32 getFrameEnd();

    // Address: 0x02921060
    bool isBodyAnmOn();

    // Address: 0x029221B0
    void getJointMtx(sead::Matrixf* p_mtx, s32 index);
    // Address: 0x029221D4
    void getJointPos(sead::Vector3f* p_pos, s32 index);

    // Address: 0x02922210
    virtual void getJointMtx(sead::Matrixf* p_mtx, const sead::SafeString& name);
    // Address: 0x029222BC
    void getJointPos(sead::Vector3f* p_pos, const sead::SafeString& name);

    virtual void play() = 0;

    // Address: 0x02922304
    void calc(const sead::Matrixf& mtx);
    // Address: 0x029224E8
    void calc2();

    // Address: 0x029224F8
    virtual void draw();

    // Address: 0x02922578
    void cancelCarry();

    // Address: 0x029225AC
    void onCarry();
    // Address: 0x029225D0
    void onLiftUp();
    // Address: 0x029225f4
    void onBalloonChibiYoshiFly();

    void onBubbleChibiYoshiShake()
    {
        mFlag.set(cFlag_IsBubbleChibiYoshiShake);
    }

    // Address: 0x0292250C
    void offCarry();
    // Address: 0x02922530
    void offLiftUp();
    // Address: 0x02922554
    void offBalloonChibiYoshiFly();

    void offBubbleChibiYoshiShake()
    {
        mFlag.reset(cFlag_IsBubbleChibiYoshiShake);
    }

    // Address: 0x0292123C
    bool isCarry();
    // Address: 0x02921218
    bool isLiftUp();

    virtual void onStarAnm()
    {
        mFlag.set(cFlag_IsStarAnm);
    }

    virtual void offStarAnm()
    {
        mFlag.reset(cFlag_IsStarAnm);
    }

    // Address: 0x02922618
    bool isFootStepTiming();

    // Address: 0x029227D0
    bool isCourseSelectScene();

    virtual f32 getBaseScale() = 0;

    sead::Vector3f* getHeadTopPosP()
    {
        return &mHeadTopPos;
    }

    sead::Vector3f* getHatPosP()
    {
        return &mHatPos;
    }

    const AnmFlag& getAnmFlag(AnmFlagType type) const
    {
        return mAnmFlag[type];
    }

protected:
    ModelResource*          mpModelRes;
    ModelResource*          mpAnmRes;
    AnimModel*              mpModel;
    s32                     mAnm;
    s32                     mBodyAnm;
    s32                     mRideAnm;
    PlayerModelBase*        mpLinkPlayer;
    sead::Matrixf           mMtxSrt;
    sead::Matrixf           mMtxSr;
    sead::Vector3f          mHeadTopPos;
    sead::Vector3f          mHatPos;
    Type                    mType;
    SceneType               mSceneType;
    TexAnmType              mTexAnmType;
    s32                     mDefaultExpressionTimer;
    f32                     mOffsetY;
    f32                     mStoopOffsetCurrent;
    f32                     mStoopOffsetTarget;
    f32                     mStoopOffsetBlendFramesRemaining;
    sead::SafeArray<
        AnmFlag,
        cAnmFlagType_Num
    >                       mAnmFlag;
    sead::BitFlag32         mFlag;
    s32                     mJumpIndex;
    s32                     mJumpIndexPrev;         // Maybe?
    Angle                   mFaceAngleXOverride;    // Always set to 0 and never actually used
    Angle                   mFaceAngleYOverride;
    Angle                   mFaceAngleZOverride;
    sead::BitFlag32         mFaceAngleOverrideFlag;
    bool                    mCarryStateChanged;
};
static_assert(sizeof(PlayerModelBase) == 0xF0);
