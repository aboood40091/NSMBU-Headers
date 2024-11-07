#pragma once

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

class Actor;

class ScoreMgr
{
    // createInstance()                             Address: 0x02027A0C
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101C63C4
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x02028418
    // SingletonDisposer_::sStaticDisposer          Address: 0x101C63C8
    // SingletonDisposer_::vtbl                     Address: 0x10004E28
    SEAD_SINGLETON_DISPOSER(ScoreMgr)

public:
    enum ScoreType
    {
        cScoreType_Point_100,
        cScoreType_Point_200,
        cScoreType_Point_400,
        cScoreType_Point_800,
        cScoreType_Point_1000,
        cScoreType_Point_2000,
        cScoreType_Point_4000,
        cScoreType_Point_8000,
        cScoreType_Rest_1,
        cScoreType_Rest_3,
        cScoreType_Unk,
        cScoreType_Max
    };

    enum ScoreTypeAll
    {
        cScoreTypeAll_Point_100,
        cScoreTypeAll_Point_200,
        cScoreTypeAll_Point_400,
        cScoreTypeAll_Point_800,
        cScoreTypeAll_Point_1000,
        cScoreTypeAll_Point_2000,
        cScoreTypeAll_Point_4000,
        cScoreTypeAll_Point_8000,
        cScoreTypeAll_Rest_All,
        cScoreTypeAll_Point_10,
        cScoreTypeAll_Max
    };

public:
    // Address: 0x020279E0
    ScoreMgr();

    // Address: 0x02027BD8
    void incRestAll(bool sound);
    // Address: 0x02027C80
    void addScore(const sead::Vector3f& small_score_pos, ScoreType type, s32 player_no, bool rest_sound = true);
    // Address: 0x02027F04
    void addScoreAll(const sead::Vector3f& small_score_pos, ScoreTypeAll type);
    // Address: 0x02027FCC
    void addScoreAll(const Actor& actor_for_small_score_pos, f32 small_score_offset_x, f32 small_score_offset_y, ScoreTypeAll type);
    // Address: 0x0202821C
    void incRestAllWithSmallScore(bool sound);
};
