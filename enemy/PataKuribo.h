#pragma once

#include <enemy/KuriboBase.h>

class PataKuribo : public KuriboBase    // vtbl Address: 0x10098FC0
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EAB10
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EAB84
    SEAD_RTTI_OVERRIDE(PataKuribo, KuriboBase)

public:
    // Address: 0x0240A0B4
    PataKuribo(const ActorCreateParam& param);

    // Address: 0x0240AD78
    bool createIceActor() override;
    // Address: 0x0240AF2C
    void returnState_Ice() override;
    // Address: 0x0240A264
    bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x0240A1F8
    bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x0240A2D0
    bool hitCallback_YoshiHipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x0240A17C
    bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x0240ABEC
    void initialize() override;
    // Address: 0x0240AD74
    void calcModel() override;
    // Address: 0x0240B0F8
    void drawModel() override;
    // Address: 0x0240A33C
    void setTurnByEnemyHit() override;
    // Address: 0x0240A798
    void setTurnByPlayerHit(Actor*) override;
    // Address: 0x0240AD50
    void setWalkSpeed() override;
    // Address: 0x0240A8D8
    void reactFumiProc(Actor*) override;
    // Address: 0x0240A968
    void reactSpinFumiProc(Actor* p_player) override;
    // Address: 0x0240A9C4
    void reactYoshiFumiProc(Actor* p_yoshi) override;
    // Address: 0x0240B150
    void onDrcTouch() override;

    virtual void vf5F4()
    {
        changeState(StateID_Walk);
    }

    // StateID_Pata_Walk            Address: 0x1020592C
    // initializeState_Pata_Walk    Address: 0x0240B2D0
    // executeState_Pata_Walk       Address: 0x0240B404
    // finalizeState_Pata_Walk      Address: 0x0240BCAC
    DECLARE_STATE_ID(PataKuribo, Pata_Walk)
    // StateID_Pata_Turn            Address: 0x1020594C
    // initializeState_Pata_Turn    Address: 0x0240B5DC
    // executeState_Pata_Turn       Address: 0x0240B61C
    // finalizeState_Pata_Turn      Address: 0x0240BCB0
    DECLARE_STATE_ID(PataKuribo, Pata_Turn)

protected:
    BlendModel*     mpBlendModelWing;
    sead::Vector3f  mWingRootPos;
    u8              _1a98;
    u8              _1a99;
    u8              _1a9a;
    bool            mHasWing;
    bool            mIsNotStartInWalkAnm;
};
static_assert(sizeof(PataKuribo) == 0x1AA0);
