#pragma once

#include <math/seadVector.h>

class StateID;

class EnemyDeathInfo
{
public:
    struct KillArg
    {
        KillArg(u32 arg_ = 0)
            : arg(arg_)
        {
        }

        KillArg(s8 score_lyt_type_, u8 kill_direction_, s8 kill_player_no_)
            : score_lyt_type(score_lyt_type_)
            , kill_direction(kill_direction_)
            , kill_player_no(kill_player_no_)
        {
        }

        union
        {
            struct
            {
                s8  score_lyt_type;
                u8  kill_direction;
                s8  kill_player_no;
            };
            u32 arg;
        };
    };
    static_assert(sizeof(KillArg) == 4);

public:
    // Address: 0x101CE360
    static sead::Vector2f sDefaultSpeed;    // 1.5f, 3.9f
    // Address: 0x101CE368
    static f32 sDefaultFallSpeedMax;        // -4.0f
    // Address: 0x101CE36C
    static f32 sDefaultAccelY;              // -0.24375f
    // Address: 0x101CE370
    static const StateID* spDefaultStateID; // nullptr
    // Address: 0x101CE374
    static KillArg sDefaultKillArg;         // { -1, 0, -1 }

public:
    EnemyDeathInfo()
        : mSpeed(sDefaultSpeed)
        , mFallSpeedMax(sDefaultFallSpeedMax)
        , mAccelY(sDefaultAccelY)
        , mStateID(spDefaultStateID)
        , mKillArg(sDefaultKillArg)
        , mIsNoRespawn(false)
    {
    }

    EnemyDeathInfo(const sead::Vector2f& speed,
                   f32 fall_speed_max,
                   f32 accel_y,
                   const StateID* state_id)
        : mSpeed(speed)
        , mFallSpeedMax(fall_speed_max)
        , mAccelY(accel_y)
        , mStateID(state_id)
    {
    }

    void setKillArg(s8 score_lyt_type, u8 kill_direction, s8 kill_player_no)
    {
        mKillArg.score_lyt_type = score_lyt_type;
        mKillArg.kill_direction = kill_direction;
        mKillArg.kill_player_no = kill_player_no;
    }

    // Address: 0x0232EFA0
    void setNoRespawn(const EnemyDeathInfo& info);

private:
    sead::Vector2f  mSpeed;
    f32             mFallSpeedMax;
    f32             mAccelY;
    const StateID*  mStateID;
    KillArg         mKillArg;
    bool            mIsNoRespawn;
};
static_assert(sizeof(EnemyDeathInfo) == 0x1C);
