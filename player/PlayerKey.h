#pragma once

#include <basis/seadTypes.h>

class PlayerKey
{
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

private:
    u8  _0[0x94];
};
static_assert(sizeof(PlayerKey) == 0x94);
