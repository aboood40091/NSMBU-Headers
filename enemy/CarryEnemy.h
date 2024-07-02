#pragma once

#include <enemy/Enemy.h>

class CarryEnemy : public Enemy // vtbl Address: 0x100625BC
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9F7C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FC0
    SEAD_RTTI_OVERRIDE(CarryEnemy, Enemy)

public:
    // Address: 0x022EB09C
    CarryEnemy(const ActorCreateParam& param);
    virtual ~CarryEnemy() { }

protected:
    // Address: 0x022EB18C
    s32 preExecute_() override;
    // Address: 0x022EB218
    s32 doDelete_() override;

    bool isSpinLiftUpEnable() override
    {
        return mStateMgr.getStateID()->isEqual(StateID_Sleep);
    }

    // Address: 0x022EB368
    void setSpinLiftUpActor(Actor*) override;

    // Address: 0x022EBC60
    void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022EC18C
    bool hitCallback_Shell(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x022EC130
    bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022EC59C
    bool vf2B4(bool*, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    // Address: 0x022EBD7C
    virtual void reactFumiProc(Actor*);
    // Address: 0x022EBD80
    virtual void reactMameFumiProc(Actor*);
    // Address: 0x022EBD84
    virtual void reactSpinFumiProc(Actor*);

    // Address: 0x022EBE7C
    virtual void playerHitCheck_Awake(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x022EBFEC
    virtual void playerHitCheck_Sleep(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x022EC06C
    virtual void playerHitCheck_Carry(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    // Address: 0x022ED6FC
    virtual void playerHitCheck_Unknown(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);

    virtual void setDropChangeState(Actor*) = 0;
    virtual void setThrowChangeState(Actor*) = 0;

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
    // StateID_Kick         Address: 0x101FF834
    // initializeState_Kick Address: 0x022ED02C
    // executeState_Kick    Address: 0x022ED70C
    // finalizeState_Kick   Address: 0x022ED07C
    DECLARE_STATE_VIRTUAL_ID_BASE(CarryEnemy, Kick)

    // Address: 0x22EB1CC
    void forceDrop();

protected:
    sead::Vector3f  _1880;
    f32             _188c[2];
    f32             _1894[2];
    f32             _189c;
    u32             _18a0;
    u32             _18a4;
    s8              mCarryPlayerNo;
    u32             _18ac;
    u8              _18b0;
    u8              _18b1;
    u32             _18b4;
};
static_assert(sizeof(CarryEnemy) == 0x18B8);
