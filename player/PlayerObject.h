#pragma once

#include <map/CarryType.h>
#include <player/PlayerBase.h>
#include <player/PlayerModelMgr.h>

class PlayerObject : public PlayerBase
{
public:
    enum CarryStep
    {
        cCarryStep_None = 0,
        cCarryStep_Carry_NoTimer,
        cCarryStep_LiftUp,
        cCarryStep_Carry
    };

public:
    // ...
    bool setDamage(Actor* p_actor, DamageType type) override;
    bool setForcedDamage(Actor* p_actor, DamageType type) override;
    // ...
    bool isStar() const override;
    // ...

    bool setCarry(Actor* p_actor, CarryType type); // TODO: virtual (0xADC)

    bool isDrawingCarryFukidashi(); // TODO: virtual (0xAF4)

    ActorUniqueID getCarryActorID() const
    {
        return mCarryActorID;
    }

    CarryStep getCarryStep() const
    {
        return mCarryStep;
    }

    // StateID_Balloon          Address: 0x1022B18C
    // initializeState_Balloon  Address: 0x029265C0
    // executeState_Balloon     Address: 0x02926AA0
    // finalizeState_Balloon    Address: 0x02926EF4
    DECLARE_STATE_ID(PlayerObject, Balloon)

    bool isBalloon() const
    {
        return *mStateMgr.getStateID() == StateID_Balloon;
    }

    // ------------------------------------ PlayerObjectCarry.cpp ------------------------------------ //

    void cancelCarry(Actor* p_actor);

    f32 getCarryStepRatio();

    bool getCarryMtx(sead::Matrixf* p_mtx);

    // ------------------------------------ PlayerObjectCc.cpp ------------------------------------ //

    void getSpinLiftUpCcSizeInfo(sead::Vector2f* p_center_offset, sead::Vector2f* p_half_size);

    // ------------------------------------ PlayerObjectMain.cpp ------------------------------------ //

    bool setRideOffPlayerJump(f32 speed_y, f32 speed_f);

    // ------------------------------------ PlayerObjectPropel.cpp ------------------------------------ //

    void setPropelFallSpin();

    // ------------------------------------ PlayerObjectSpin.cpp ------------------------------------ //

    Angle getMissSpinAngle();

    // ------------------------------------ PlayerObjectVine.cpp ------------------------------------ //

    void VineActionNet();

    bool checkVineEnd();
    void calcVineSpeed();
    bool setVineToKaniHangAction();
    void vineWalk();

protected:
    PlayerModelMgr  mModelMgr;
    u32             _2760[(0x2784 - 0x2760) / sizeof(u32)];
    ActorUniqueID   mCarryActorID;
    CarryStep       mCarryStep;
    CarryStep       mCarryStepPrev;
    f32             mCarryStepTimer;
    f32             mCarryStepLength;
    u32             _2798[(0x2AC8 - 0x2798) / sizeof(u32)];
    u32             _2ac8;
    u32             _2acc;
    u32             _2ad0[(0x34CC - 0x2AD0) / sizeof(u32)];
    f32             mJumpTimerF;
    s32             mJumpAnmID;
    s32             _34d4;  // Some random timer
};
static_assert(sizeof(PlayerObject) == 0x34D8);
