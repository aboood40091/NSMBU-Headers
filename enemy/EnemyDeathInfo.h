#pragma once

#include <math/seadVector.h>

class StateID;

class EnemyDeathInfo
{
public:
    struct Arg
    {
        sead::Vector2f  speed;
        f32             max_fall_speed;
        f32             gravity;
        const StateID*  p_state_id;
        s8              score_type;
        u8              direction;
        s8              player_no;
    };
    static_assert(sizeof(Arg) == 0x18);

public:
    // Address: 0x101CE360
    static Arg sDefaultArg; // { { 1.5f, 3.9f }, -4.0f, -0.24375f, nullptr, -1, 0, -1 }

public:
    EnemyDeathInfo()
        : mArg(sDefaultArg)
        , mIsDead(false)
    {
    }

    bool isDead() const
    {
        return mIsDead;
    }

    // Address: 0x0232EFA0
    void kill(const Arg& arg);

private:
    Arg     mArg;
    bool    mIsDead;
};
static_assert(sizeof(EnemyDeathInfo) == 0x1C);
