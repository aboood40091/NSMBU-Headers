#pragma once

#include <input/PadCommon.h>

class PlayerKey
{
public:
    enum Status
    {
        cStatus_NoInput     =  1,   // NSMBW: Bit 0
        cStatus_NoCross,            // NSMBW: Bit 1

        cStatus_ForceJump   =  5,   // NSMBW: Bit 3
        cStatus_NoJump,             // NSMBW: Bit 4

        cStatus_Demo        = 10    // NSMBW: Bit 7
    };

    enum Key
    {
        cKey_Jump   = cPadIdxCommon_Jump,
        cKey_Left   = cPadIdxCommon_Left,
        cKey_Right  = cPadIdxCommon_Right
    };

public:
    PlayerKey();

    void update();
    void updateEnd();

    bool triggerJump() const;

    bool buttonUp() const;
    bool buttonDown() const;
    bool buttonLeft() const;
    bool buttonRight() const;

    bool triggerUp() const;
    bool triggerDown() const;

    bool buttonDush() const;
    bool buttonWalk(s32* p_dir = nullptr) const;

    bool buttonJump() const;

    bool triggerShakeJump() const;
    bool triggerAttack() const;

    bool buttonHipAttack() const;

    void onStatus(s32 bit);
    void offStatus(s32 bit);

    void onDemoTrigger(s32 key);
    void offDemoTrigger(s32 key);

private:
    u8  _0[0x94];
};
static_assert(sizeof(PlayerKey) == 0x94);
