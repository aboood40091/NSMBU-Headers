#pragma once

#include <enemy/Enemy.h>

class CarryEnemy : public Enemy
{
    SEAD_RTTI_OVERRIDE(CarryEnemy, Enemy)

public:
    CarryEnemy(const ActorCreateParam& param);
    virtual ~CarryEnemy() { }

protected:
    s32 preExecute_() override;
    s32 doDelete_() override;

    bool isSpinLiftUpEnable() override
    {
        return mStateMgr.getStateMethod().getStateID()->isEqual(StateID_Sleep);
    }

    void setSpinLiftUpActor(Actor*) override;

    void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    bool hitCallback_Shell(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    bool vf2B4(bool*, ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    virtual void reactFumiProc(Actor*);
    virtual void reactMameFumiProc(Actor*);
    virtual void reactSpinFumiProc(Actor*);
    virtual void playerHitCheck_Awake(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual void playerHitCheck_Sleep(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual bool playerHitCheck_Carry(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual void playerHitCheck_Unknown(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other);
    virtual void setDropChangeState(Actor*) = 0;
    virtual void setThrowChangeState(Actor*) = 0;

    DECLARE_STATE_VIRTUAL_ID_BASE(CarryEnemy, Carry)
    DECLARE_STATE_VIRTUAL_ID_BASE(CarryEnemy, Sleep)
    DECLARE_STATE_VIRTUAL_ID_BASE(CarryEnemy, Kick)

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
