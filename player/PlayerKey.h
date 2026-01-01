#pragma once

#include <basis/seadTypes.h>

class PlayerKey
{
public:
    enum Status
    {
        cStatus_NoInput     =  1,   // NSMBW: Bit 0
        cStatus_NoCross,            // NSMBW: Bit 1

        cStatus_Demo        = 10    // NSMBW: Bit 7
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

    bool buttonJump() const;

    bool triggerShakeJump() const;
    bool triggerAttack() const;

    bool buttonHipAttack() const;

    void onStatus(s32 bit);
    void offStatus(s32 bit);

private:
    u8  _0[0x94];
};
static_assert(sizeof(PlayerKey) == 0x94);
