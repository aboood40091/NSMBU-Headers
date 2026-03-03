#pragma once

#include <enemy/KuriboBase.h>
#include <graphics/BlendModel.h>
#include <graphics/SkeletalAnimation.h>

class BalloonHangActor;

class Kuribo : public KuriboBase    // vtbl Address: 0x10090E2C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA150
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA14C
    SEAD_RTTI_OVERRIDE(Kuribo, KuriboBase)

protected:
    enum KakiboAnmID
    {
        cKakiboAnmID_Walk = 0,
        cKakiboAnmID_Walk0,
        cKakiboAnmID_Walk1
    };

    enum WakiDir
    {
        cWakiDir_Up = 0,
        cWakiDir_Down,
        cWakiDir_Left,
        cWakiDir_Right,
        cWakiDir_Num
    };
    static_assert(sizeof(WakiDir) == 4);
    static_assert(cWakiDir_Num == 4);

public:
    // Address: 0x102045F0
    static const sead::SafeString cModelName[cModelType_Num];

public:
    // Address: 0x023D60C8
    Kuribo(const ActorCreateParam& param);

    // Address: 0x023D66F0
    void initialize() override;
    // Address: 0x023D6F18
    void calcModel() override;
    // Address: 0x023D6F64
    void drawModel() override;

protected:
    // Address: 0x023D6F74
    Result doDelete_() override;

    void beginFunsui_() override
    {
        mpBlendModel->getCurSklAnim()->getFrameCtrl().setRate(3.0f);
        mPreFunsuiSpeedX = mSpeed.x;
        mSpeed.set(0.0f, 0.0f, 0.0f);
        mIsFunsui = true;
    }

    void endFunsui_(f32 speed_y) override
    {
        mpBlendModel->getCurSklAnim()->getFrameCtrl().setRate(2.0f);
        mSpeed.x = mPreFunsuiSpeedX;
        mIsFunsui = false;
    }

    bool isFunsui_() const override
    {
        return mIsFunsui;
    }

public:
    // Address: 0x023D6FDC
    void setTurnByEnemyHit(Actor* actor_self, Actor* actor_other) override;

    // Address: 0x023D7310
    void setWalkSpeed() override;

    // Address: 0x023D732C
    void setFrozenAnm();

    // Address: 0x023D7798
    bool checkGroundKakiboTurn();

    // Address: 0x023D7A00
    void down();

    // Address: 0x023D7B58
    void vsEnemyHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x023D7BD8
    bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023D7C80
    bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x023D7D18
    bool createIceActor() override;

    void setIceAnm() override
    {
    }

    void returnAnm_Ice() override
    {
    }

    // Address: 0x023D7DAC
    void returnState_Ice() override;

    // Address: 0x023D806C
    void balloonCollCheck(ActorCollisionCheck* cc_other) override;

    bool disallowDrcTouchOnGround() override
    {
        return isState(StateID_BalloonHang);
    }

    bool vf54C() override
    {
        return mKuriboType == 4 || mKuriboType == 5;
    }

    bool vf554() override
    {
        return isOldState(StateID_Touch);
    }

    bool isWakidashi() const override
    {
        return isState(StateID_Auto_Walk) ||
               isState(StateID_Down);
    }

    // Address: 0x023D8170
    void onDrcTouch() override;
    // Address: 0x023D82B0
    void resetCcDrcTouch() override;
    // Address: 0x023D82DC
    void calcDrcTouch() override;

    void setWalkState() override
    {
        if (!mIsKakibo)
            changeState(StateID_Walk);
        else
            changeState(StateID_KakiboWalk);
    }

public:
    // StateID_KakiboWalk           Address: 0x10204644
    // initializeState_KakiboWalk   Address: 0x023D839C
    // executeState_KakiboWalk      Address: 0x023D8428
    // finalizeState_KakiboWalk     Address: 0x023DAD90
    DECLARE_STATE_ID(Kuribo, KakiboWalk)
    // StateID_KakiboTurn           Address: 0x10204664
    // initializeState_KakiboTurn   Address: 0x023D86BC
    // executeState_KakiboTurn      Address: 0x023D86D8
    // finalizeState_KakiboTurn     Address: 0x023DAD94
    DECLARE_STATE_ID(Kuribo, KakiboTurn)

    // StateID_Touch            Address: 0x102047D4
    // initializeState_Touch    Address: 0x023D88C4
    // executeState_Touch       Address: 0x023D8910
    // finalizeState_Touch      Address: 0x023DAD98
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Kuribo, Touch)

    // StateID_Down         Address: 0x10204684
    // initializeState_Down Address: 0x023D8914
    // executeState_Down    Address: 0x023D8948
    // finalizeState_Down   Address: 0x023DAD9C
    DECLARE_STATE_ID(Kuribo, Down)
    // StateID_Auto_Walk            Address: 0x102046A4
    // initializeState_Auto_Walk    Address: 0x023D89B0
    // executeState_Auto_Walk       Address: 0x023D8B14
    // finalizeState_Auto_Walk      Address: 0x023DADA0
    DECLARE_STATE_ID(Kuribo, Auto_Walk)
    // StateID_Dokan_Down           Address: 0x102046C4
    // initializeState_Dokan_Down   Address: 0x023D8D84
    // executeState_Dokan_Down      Address: 0x023D8DD0
    // finalizeState_Dokan_Down     Address: 0x023DADA4
    DECLARE_STATE_ID(Kuribo, Dokan_Down)
    // StateID_BlockAppear          Address: 0x102046E4
    // initializeState_BlockAppear  Address: 0x023D8E78
    // executeState_BlockAppear     Address: 0x023D8F0C
    // finalizeState_BlockAppear    Address: 0x023D8F48
    DECLARE_STATE_ID(Kuribo, BlockAppear)
    // StateID_Born_Split1          Address: 0x10204704
    // initializeState_Born_Split1  Address: 0x023D8FF4
    // executeState_Born_Split1     Address: 0x023D9488
    // finalizeState_Born_Split1    Address: 0x023D948C
    DECLARE_STATE_ID(Kuribo, Born_Split1)
    // StateID_Born_Split2          Address: 0x10204724
    // initializeState_Born_Split2  Address: 0x023D9498
    // executeState_Born_Split2     Address: 0x023D9224
    // finalizeState_Born_Split2    Address: 0x023D9734
    DECLARE_STATE_ID(Kuribo, Born_Split2)
    // StateID_EatOut_Ready         Address: 0x10204744
    // initializeState_EatOut_Ready Address: 0x023D9740
    // executeState_EatOut_Ready    Address: 0x023D97D4
    // finalizeState_EatOut_Ready   Address: 0x023DADA8
    DECLARE_STATE_ID(Kuribo, EatOut_Ready)
    // StateID_BalloonHang          Address: 0x10204764
    // initializeState_BalloonHang  Address: 0x023D98D4
    // executeState_BalloonHang     Address: 0x023D9970
    // finalizeState_BalloonHang    Address: 0x023DADAC
    DECLARE_STATE_ID(Kuribo, BalloonHang)
    // StateID_KameckIce            Address: 0x10204784
    // initializeState_KameckIce    Address: 0x023D9A40
    // executeState_KameckIce       Address: 0x023DADB0
    // finalizeState_KameckIce      Address: 0x023D9AA0
    DECLARE_STATE_ID(Kuribo, KameckIce)

protected:
    // Address: 0x023D6580
    void createBodyModel_();

    // Address: 0x023D61A4
    void setKakiboAnm(KakiboAnmID anm_id);

    // Address: 0x023D6634
    bool checkGroundCreate_();

    // Address: 0x023D7434
    bool checkGroundKakibo_(f32 check_dist);

    // Address: 0x023D7584
    bool checkKakiboTurnSaka_();

    void calcKakiboHa_()
    {
        if (mKakiboBgmHoldTimer != 0)
        {
            mKakiboBgmHoldTimer--;
            mKakiboHaAngleZ = 0x15555555; // 30 degrees
            mKakiboHaScale = 1.2f;
        }
        else
        {
            Angle angle = mKakiboHaAngleZ;
            angle.chaseRest(0, 0x2222222); // 3 degrees per frame
            mKakiboHaAngleZ = angle;
            sead::Mathf::chase(&mKakiboHaScale, 1.0f, 0.02f);
        }
    }

protected:
    ActorBgCollisionCheck::Sensor   mBcSensorFootDown;
    u8                              mKuriboType;
    u8                              mKakiboAnm;
    u8                              _1a96;
    u8                              _1a97;
    bool                            mIsKakiboWalk1;
    sead::Vector3f                  mWakiTargetPos;
    WakiDir                         mWakiDir;
    s32                             mKakiboBgmHoldTimer;
    bool                            mIsFunsui;
    f32                             mPreFunsuiSpeedX;
    f32                             mGroundDistance;    // When Kuribo is set to spawn on ground
    BalloonHangActor*               mpBalloon;
    ActorUniqueID                   mBalloonID;

    // Address: 0x102047A4
    static const f32 cWalkSpeed[cDirType_NumX]; // 0.5f, -0.5f

    static f32 getWalkSpeed()
    {
        return 0.5f;
    }
};
static_assert(sizeof(Kuribo) == 0x1AC8);
