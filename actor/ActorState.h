#pragma once

#include <actor/ActorCollision.h>
#include <state/FStateMgr.h>
#include <state/StateMethod.h>

class ActorState : public ActorCollision    // vtbl Address: 0x10000EC8
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CDC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CE0
    SEAD_RTTI_OVERRIDE(ActorState, ActorCollision)

public:
    // Address: 0x0200A9C0
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

class ActorMultiState : public ActorCollision   // vtbl Address: 0x10001048
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CE4
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CE8
    SEAD_RTTI_OVERRIDE(ActorMultiState, ActorCollision)

public:
    // Address: 0x0200AA8C
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
