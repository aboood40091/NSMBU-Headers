#pragma once

#include <basis/seadTypes.h>

enum PlayerMode
{
    cPlayerMode_Invalid = -1,
    cPlayerMode_Small = 0,
    cPlayerMode_Normal,
    cPlayerMode_Fire,
    cPlayerMode_Mini,
    cPlayerMode_Propeller,
    cPlayerMode_Penguin,
    cPlayerMode_Ice,
    cPlayerMode_Squirrel,
    cPlayerMode_PSquirrel,
    cPlayerMode_Num
};
static_assert(cPlayerMode_Num == 9);
static_assert(sizeof(PlayerMode) == 4);

enum PlayerModeModel
{
    cPlayerModeModel_Normal = 0,
    cPlayerModeModel_Small,
    cPlayerModeModel_Propeller,
    cPlayerModeModel_Penguin,
    cPlayerModeModel_Squirrel,
    cPlayerModeModel_Num
};
static_assert(cPlayerModeModel_Num == 5);
static_assert(sizeof(PlayerModeModel) == 4);

enum PlayerCharacter
{
    cPlayerCharacter_Mario = 0,
    cPlayerCharacter_Luigi,
    cPlayerCharacter_YellowToad,
    cPlayerCharacter_BlueToad,
    cPlayerCharacter_Nabbit,
    cPlayerCharacter_Mii,
    cPlayerCharacter_Unused,    // No idea why this exists
    cPlayerCharacter_Num
};
static_assert(cPlayerCharacter_Num == 7);
static_assert(sizeof(PlayerCharacter) == 4);

enum PlayerCharacterVoice
{
    cVoice_Mario = 0,
    cVoice_Luigi,
    cVoice_YellowToad,
    cVoice_BlueToad,
    cVoice_Nabbit,
    cVoice_MiiMale1,
    cVoice_MiiMale2,
    cVoice_MiiMale3,
    cVoice_MiiMale4,
    cVoice_MiiFemale1,
    cVoice_MiiFemale2,
    cVoice_MiiFemale3,
    cVoice_MiiFemale4,
    cVoice_Yoshi,
    cVoice_Blank,   // ...?
    cVoice_Num
};
static_assert(cVoice_Num == 15);
static_assert(sizeof(PlayerCharacterVoice) == 4);

enum PlayerVoiceID
{
    PLAYER_JOIN = 0,
    PJ_JUMP,
    PJ_SPIN_JUMP,
    PLAYER_DECIDE,
    CS_FALL_INTO_MAP,
    CS_COURSE_IN,
    CS_COURSE_IN_MULTI,
    CS_COURSE_IN_HARD,
    CS_COURSE_MISS,
    CS_JUMP,
    CS_DECIDE_JOIN,
    CS_ENCOUNT,
    CS_SHOVED,
    CS_CHASE_SHIP,
    CS_NOTICE_JR,
    GAME_OVER,
    CONTINUE,
    CONTINUE_COURSE,
    MOTIAGE,
    NAGERU,
    MOTIAGE_PLAYER,
    JUMP_2ND,
    JUMP_3RD,
    YOSHI_JUMP,
    JR_A_BATTLE_APP,
    WALL_KICK,
    PRPL_JUMP,
    PNGN_SLIDE,
    ROPE_CATCH,
    ROPE_RELEASE,
    ROPE_FALL,
    GOAL_POLE_CATCH,
    CLIFF_DIVE,
    CLIFF_UP,
    CLIFF_DOWN,
    CANNON_SHOT_S,
    CANNON_SHOT,
    BALLOON_HELP__TV,
    BALLOON_HELP__RC,
    HUKKATSU,
    DAMAGE_LAST__1,
    DAMAGE_LAST__2,
    TIMEUP,
    TIMEUP_MULTI,
    SCROLL_OUT,
    DAMAGE_FIRE,
    DAMAGE_FREEZE,
    DAMAGE_POISON,
    DAMAGE_ELEC,
    DAMAGE_EATEN,
    INTO_SANDPILLAR,
    QUAKE,
    STOMPED,
    HIP_ATTACKED,
    TYUKAN,
    GET_STAR,
    ITEM_COMPLETE,
    CLEAR_NORMAL,
    CLEAR_ANOTHER,
    CLEAR_MULTI,
    CLEAR_HELPED,
    CLEAR_BOSS,
    CLEAR_LAST_BOSS,
    SAVE_PRINCESS,
    CS_COMPLETE_DEMO,
    GET_PRIZE,
    FLOOR_FALL,
    NOTICE,
    MISS_PRINCESS,
    MG_IH_ACTIVE_TV,
    MG_IH_ACTIVE_RC,

    // NSMBU-unique voice lines start from here
    CS_CMN_COURSE_CLEAR,
    CS_CMN_SHIP_ATTACK,
    CS_SHIP_SURPRISE,
    CS_CAPTURED,
    CS_SHIP_CLEAR,
    CS_CANNON_SHOT,
    CS_CMN_ITEM_MOTIAGE,
    KISSED_PEACH,
    SURPRISED_PEACH,

    cPlayerVoiceID_Num
};
static_assert(cPlayerVoiceID_Num == 80);
