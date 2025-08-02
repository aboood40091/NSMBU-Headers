#pragma once

#include <actor/ScoreMgr.h>

class Actor;

class Combo
{
public:
    enum Type
    {
        cType_Null = 0,
        cType_1 = 1,
        cType_2 = 2
    };
    static_assert(sizeof(Type) == 4);

public:
    // Address: 0x02302F88
    Combo();

    bool getType() const
    {
        return mType;
    }

    bool isComboType2() const
    {
        return mType == cType_2;
    }

    // Address: 0x02302FC4
    ScoreMgr::ScoreType getComboScore(s32 combo_cnt);

    // Address: 0x02303024
    void setScore(Actor* p_actor, ScoreMgr::ScoreType score_type, s32 player_no);

    // Address: 0x02303070
    ScoreMgr::ScoreType getDamageScore();

    // Address: 0x02303088
    ScoreMgr::ScoreType getQuakeScore(s32 quake_cnt);

    // Address: 0x0230309C
    s32 calcPlFumiCnt(Actor* p_player);
    // Address: 0x02303154
    static s32 calcPlStarCnt(Actor* p_player);
    // Address: 0x02303234
    static s32 calcPlComboCnt(Actor* p_player);

protected:
    Type mType;
};
static_assert(sizeof(Combo) == 4);
