#pragma once

#include <enemy/KuriboBase.h>
#include <graphics/BlendModel.h>
#include <graphics/SkeletalAnimation.h>

class Kuribo : public KuriboBase    // vtbl Address: 0x10090E2C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA150
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA14C
    SEAD_RTTI_OVERRIDE(Kuribo, KuriboBase)

public:
    // Address: 0x023D60C8
    Kuribo(const ActorCreateParam& param);

protected:
    // Address: 0x023D6F74
    s32 doDelete_() override;

public:
    void vf11C() override
    {
        mpBlendModel->getCurSklAnim()->getFrameCtrl().setRate(3.0f);
        _1ab4 = mSpeed.x;
        mSpeed.set(0.0f, 0.0f, 0.0f);
        _1ab0 = true;
    }

    void vf124(f32) override
    {
        mpBlendModel->getCurSklAnim()->getFrameCtrl().setRate(2.0f);
        mSpeed.x = _1ab4;
        _1ab0 = false;
    }

    bool vf12C() override
    {
        return _1ab0;
    }

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
    // Address: 0x023D7B58
    void vsEnemyHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023D7C80
    bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x023D7BD8
    bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x023D66F0
    void initialize() override;
    // Address: 0x023D6F18
    void calcModel() override;
    // Address: 0x023D6F64
    void drawModel() override;
    // Address: 0x023D6FDC
    void setTurnByEnemyHit() override;
    // Address: 0x023D7310
    void setWalkSpeed() override;
    // Address: 0x023D806C
    void vf53C(const ActorCollisionCheck&) override;

    bool vf544() override
    {
        return *mStateMgr.getStateID() == StateID_KuriboState10;
    }

    bool vf54C() override
    {
        return mKuriboType == 4 || mKuriboType == 5;
    }

    bool vf554() override
    {
        return *mStateMgr.getOldStateID() == StateID_Touch;
    }

    // StateID_Touch            Address: 0x102047D4
    // initializeState_Touch    Address: 0x023D88C4
    // executeState_Touch       Address: 0x023D8910
    // finalizeState_Touch      Address: 0x023DAD98
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Kuribo, Touch)    // ?

    bool isWakidashi() const override
    {
        return *mStateMgr.getStateID() == StateID_Auto_Walk ||
               *mStateMgr.getStateID() == StateID_Down;
    }

    // Address: 0x023D8170
    void onDrcTouch() override;
    // Address: 0x023D82B0
    void vf5E4() override;
    // Address: 0x023D82DC
    void vf5EC() override;

    void vf5F4() override
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
    // StateID_KuriboState5         Address: 0x102046C4
    // initializeState_KuriboState5 Address: 0x023D8D84
    // executeState_KuriboState5    Address: 0x023D8DD0
    // finalizeState_KuriboState5   Address: 0x023DADA4
    DECLARE_STATE_ID(Kuribo, KuriboState5)
    // StateID_KuriboState6         Address: 0x102046E4
    // initializeState_KuriboState6 Address: 0x023D8E78
    // executeState_KuriboState6    Address: 0x023D8F0C
    // finalizeState_KuriboState6   Address: 0x023D8F48
    DECLARE_STATE_ID(Kuribo, KuriboState6)
    // StateID_KuriboState7         Address: 0x10204704
    // initializeState_KuriboState7 Address: 0x023D8FF4
    // executeState_KuriboState7    Address: 0x023D9488
    // finalizeState_KuriboState7   Address: 0x023D948C
    DECLARE_STATE_ID(Kuribo, KuriboState7)
    // StateID_KuriboState8         Address: 0x10204724
    // initializeState_KuriboState8 Address: 0x023D9498
    // executeState_KuriboState8    Address: 0x023D9224
    // finalizeState_KuriboState8   Address: 0x023D9734
    DECLARE_STATE_ID(Kuribo, KuriboState8)
    // StateID_KuriboState9         Address: 0x10204744
    // initializeState_KuriboState9 Address: 0x023D9740
    // executeState_KuriboState9    Address: 0x023D97D4
    // finalizeState_KuriboState9   Address: 0x023DADA8
    DECLARE_STATE_ID(Kuribo, KuriboState9)
    // StateID_KuriboState10            Address: 0x10204764
    // initializeState_KuriboState10    Address: 0x023D98D4
    // executeState_KuriboState10       Address: 0x023D9970
    // finalizeState_KuriboState10      Address: 0x023DADAC
    DECLARE_STATE_ID(Kuribo, KuriboState10)
    // StateID_KuriboState11            Address: 0x10204784
    // initializeState_KuriboState11    Address: 0x023D9A40
    // executeState_KuriboState11       Address: 0x023DADB0
    // finalizeState_KuriboState11      Address: 0x023D9AA0
    DECLARE_STATE_ID(Kuribo, KuriboState11)

protected:
    ActorBgCollisionCheck::Sensor   _1a88;
    u8                              mKuriboType;
    u8                              mKakiboAnmType;
    u8                              _1a96;
    u8                              _1a97;
    bool                            _1a98;          // Related to Kakibo animations
    sead::Vector3f                  _1a9c;
    u32                             _1aa8;
    u32                             _1aac;
    bool                            _1ab0;
    f32                             _1ab4;
    f32                             mGroundPosY;    // When Kuribo is set to spawn on ground
    u32                             _1abc;
    ActorUniqueID                   mBalloonID;
};
static_assert(sizeof(Kuribo) == 0x1AC8);
