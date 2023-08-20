#pragma once

#include <actor/ActorCollision.h>
#include <state/FStateMgr.h>
#include <state/StateMethod.h>

class ActorState : public ActorCollision
{
    SEAD_RTTI_OVERRIDE(ActorState, ActorCollision)

public:
    ActorState(const ActorCreateParam& param);
    virtual ~ActorState() { }

    void changeState(const StateID& state_id)
    {
        mStateMgr.getStateMethod().changeStateMethod(state_id);
    }

protected:
    FStateMgr<ActorState, StateMethod>  mStateMgr;
    u32                                 _17c4[4 / sizeof(u32)];
};
static_assert(sizeof(ActorState) == 0x17C8);

class ActorMultiState : public ActorCollision
{
    SEAD_RTTI_OVERRIDE(ActorMultiState, ActorCollision)

public:
    ActorMultiState(const ActorCreateParam& param);
    virtual ~ActorMultiState() { }

    virtual void changeState(const StateID& state_id)
    {
        mStateMgr.getStateMethod().changeStateMethod(state_id);
    }

protected:
    FStateMgr<ActorMultiState, StateMethodMulti>    mStateMgr;
};
static_assert(sizeof(ActorMultiState) == 0x17C8);
