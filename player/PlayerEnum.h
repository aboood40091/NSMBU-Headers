#pragma once

#include <basis/seadTypes.h>

enum PlayerMode
{
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
