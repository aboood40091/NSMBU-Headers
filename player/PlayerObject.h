#pragma once

#include <player/PlayerBase.h>
#include <player/PlayerModelMgr.h>

class PlayerObject : public PlayerBase
{
public:
    // ...
    bool setDamage(Actor* p_actor, DamageType type) override;
    bool setForcedDamage(Actor* p_actor, DamageType type) override;
    // ...
    bool isStar() const override;
    // ...

    bool isDrawingCarryFukidashi(); // TODO: virtual (0xAF4)

    ActorUniqueID getCarryActorID() const
    {
        return mCarryActorID;
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

    // ------------------------------------ PlayerObjectCc.cpp ------------------------------------ //

    void getSpinLiftUpCcSizeInfo(sead::Vector2f* p_center_offset, sead::Vector2f* p_half_size);

    // ------------------------------------ PlayerObjectMain.cpp ------------------------------------ //

    bool setRideOffPlayerJump(f32 speed_y, f32 speed_f);

    // ------------------------------------ PlayerObjectPropel.cpp ------------------------------------ //

    void setPropelFallSpin();

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
    u32             _2788[(0x2AC8 - 0x2788) / sizeof(u32)];
    u32             _2ac8;
    u32             _2acc;
    u32             _2ad0[(0x34CC - 0x2AD0) / sizeof(u32)];
    f32             mJumpTimerF;
    s32             mJumpAnmID;
    s32             _34d4;  // Some random timer
};
static_assert(sizeof(PlayerObject) == 0x34D8);
