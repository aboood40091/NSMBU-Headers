#pragma once

#include <input/PadCommon.h>

class PlayerKey
{
public:
    enum Status
    {
        cStatus_NoInput     =  1,   // NSMBW: Bit 0
        cStatus_NoCross,            // NSMBW: Bit 1
        cStatus_NoShakeJump,

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

    void setPlayerNo(s32 player_no);

    void update();
    void updateEnd();

    bool triggerJump() const;

    bool buttonUp() const;
    bool buttonDown() const;
    bool buttonLeft() const;
    bool buttonRight() const;
    bool buttonCross() const;

    bool triggerUp() const;
    bool triggerDown() const;
    bool triggerLeft() const;
    bool triggerRight() const;
    bool triggerCross() const;

    bool buttonDush() const;
    bool buttonWalk(s32* p_dir = nullptr) const;

    bool buttonJump() const;

    bool buttonCrouch() const;

    bool triggerShakeJump() const;
    bool triggerA() const;
    bool triggerAttack() const;
    bool triggerSwim() const;
    bool triggerJumpBuf(s32 buf_frame) const;
    bool triggerEat() const;

    bool buttonHipAttack() const;

    void onStatus(s32 bit);
    void offStatus(s32 bit);

    void onDemoTrigger(s32 key);
    void offDemoTrigger(s32 key);

private:
    u8  _0[0x94];
};
static_assert(sizeof(PlayerKey) == 0x94);
