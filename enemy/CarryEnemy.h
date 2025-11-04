#pragma once

#include <enemy/Enemy.h>
#include <map/CarryType.h>

class PlayerBase;
class PlayerObject;

class CarryEnemy : public Enemy // vtbl Address: 0x100625BC
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9F7C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FC0
    SEAD_RTTI_OVERRIDE(CarryEnemy, Enemy)

public:
    static const s32 cShellSlideNoHitTimer = 10;

public:
    // Address: 0x022EB09C
    CarryEnemy(const ActorCreateParam& param);

protected:
    // Address: 0x022EB18C
    bool preExecute_() override;
    // Address: 0x022EB218
    Result doDelete_() override;

public:
    bool isSpinLiftUpEnable() override
    {
        return *mStateMgr.getStateID() == StateID_Sleep;
    }

    // Address: 0x022EB368
    void setSpinLiftUpActor(Actor* p_player) override;

    // Address: 0x022EB370
    bool carryCheckBg(Actor* p_player);
    // Address: 0x022EB724
    void setDeathInfo_CarryBgIn(Actor* p_player, bool eff_set);

    // Address: 0x022EB808
    PlayerObject* getCarryPlayerObject() const;
    // Address: 0x022EB844
    PlayerObject* getCarryPlayerObject2() const;

    // Address: 0x022EB888
    bool carryCheck(Actor* p_player);

    // Address: 0x022EB1CC
    void cancelCarry();

    // Address: 0x022EB988
    bool checkSleepEnd() const;

    // Address: 0x022EBB2C
    void startSlide();
    // Address: 0x022EBBFC
    void endSlide();

    // Address: 0x022EBA94
    void setSlideCc();
    // Address: 0x022EBB64
    void resetSlideCc();

    // Address: 0x022EBADC
    void setSlideBc();
    // Address: 0x022EBBAC
    void resetSlideBc();

    // Address: 0x022EBC34
    DirType getRevisionDir(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x022EBC60
    void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022EBD7C
    virtual void reactFumiProc(Actor* p_player);
    // Address: 0x022EBD80
    virtual void reactMameFumiProc(Actor* p_player);
    // Address: 0x022EBD84
    virtual void reactSpinFumiProc(Actor* p_player);

    // Address: 0x022EBD88
    bool fumiProcCheck(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x022EBE7C
    virtual void playerHitCheck_Awake(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x022EBFEC
    virtual void playerHitCheck_Sleep(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x022EC06C
    virtual void playerHitCheck_Carry(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    // Address: 0x022ED6FC
    virtual void playerHitCheck_Sleep_Base(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x022EC068
    void playerHitCheck_Carry_Base(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    virtual void setPutOnChangeState(Actor* p_player) = 0;
    virtual void setThrowChangeState(Actor* p_player, bool hard) = 0;

    // Address: 0x022EC130
    bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022EC18C
    bool hitCallback_Shell(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022EC59C
    bool hitCallback_AttackUnk27(bool* p_dead, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022EC648
    void setSlidePlayerParam(Actor* p_player);

    // Address: 0x022EC6B8
    void calcCarryPos(sead::Vector3f* p_pos, PlayerObject* p_player_obj);
    // Address: 0x022ECA60
    void calcCarryCcPos(ActorCollisionCheck* p_cc, PlayerObject* p_player_obj);

    // StateID_Carry            Address: 0x101FF7EC
    // initializeState_Carry    Address: 0x022ECD00
    // executeState_Carry       Address: 0x022ECD8C
    // finalizeState_Carry      Address: 0x022ECF84
    DECLARE_STATE_VIRTUAL_ID_BASE(CarryEnemy, Carry)
    // StateID_Sleep            Address: 0x101FF810
    // initializeState_Sleep    Address: 0x022ED700
    // executeState_Sleep       Address: 0x022ED704
    // finalizeState_Sleep      Address: 0x022ED708
    DECLARE_STATE_VIRTUAL_ID_BASE(CarryEnemy, Sleep)
    // StateID_Slide            Address: 0x101FF834
    // initializeState_Slide    Address: 0x022ED02C
    // executeState_Slide       Address: 0x022ED70C
    // finalizeState_Slide      Address: 0x022ED07C
    DECLARE_STATE_VIRTUAL_ID_BASE(CarryEnemy, Slide)

private:
    // Address: 0x022EB880
    void setCarryActor_(Actor* p_player);

    // Address: 0x022EB190
    PlayerObject* getCarryPlayerObject_() const;

    // Address: 0x022EB23C
    void setCarryImpl_(Actor* p_player, CarryType type);

    // Address: 0x022EBED8
    bool sleepSpinFumiProcCheck_(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    inline void reviseCarryBgPosX_(ActorBgCollisionCheck& bc, const sead::Vector3f& player_pos);
    inline void reviseCarryBgPosY_(ActorBgCollisionCheck& bc);

protected:
    sead::Vector3f              mCarryBaseOffset;
    ActorCollisionCheck::Vec2   mPreCarryCcCenterOffset;
    ActorCollisionCheck::Vec2   mPreCarryCcHalfSize;
    f32                         mCarryChangePosZ;
    u32                         _18a0;                      // Unused
    u32                         _18a4;                      // ^^^
    s8                          mCarryPlayerNo;
    ActorUniqueID               mCarryPlayerID;
    bool                        mIsCarryEnemy;
    bool                        mIsLiftUp;
};
static_assert(sizeof(CarryEnemy) == 0x18B8);
