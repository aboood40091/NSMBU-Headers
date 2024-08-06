#pragma once

#include <controller/seadController.h>

class SysController : public sead::Controller  // vtbl Address: 0x100BF504
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9D40
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EAE78
    SEAD_RTTI_OVERRIDE(SysController, sead::Controller)

public:
    enum Id
    {
        // Single player mode
        cId_CafeDRC_SinglePlayer    = 0,

        // Multiplayer mode
        cId_CafeRemote_1            = cId_CafeDRC_SinglePlayer,
        cId_CafeRemote_2,
        cId_CafeRemote_3,
        cId_CafeRemote_4,
        cId_CafeDRC_Multiplayer,
    };

public:
    // Address: 0x02511C40
    SysController(sead::ControllerMgr* mgr, Id id);

protected:
    // Address: 0x025124D8
    void calcRemote_Core_(const sead::Controller* controller);
    // Address: 0x025127F8
    void calcRemote_Nunchuk_(const sead::Controller* controller);
    // Address: 0x02512088
    void calcRemote_URCC_(const sead::Controller* controller);
    // Address: 0x025121F4
    void calcRemote_URCC_Acc_(const sead::Controller* controller);

protected:
    u32 _15c[(0x1D4 - 0x15C) / sizeof(u32)];
};
static_assert(sizeof(SysController) == 0x1D4);
