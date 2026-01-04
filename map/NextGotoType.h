#pragma once

#include <basis/seadTypes.h>

enum NextGotoType
{
    cNextGotoType_Normal = 0,
    cNextGotoType_CheckPoint,
    cNextGotoType_Door,
    cNextGotoType_DokanD,
    cNextGotoType_DokanU,
    cNextGotoType_DokanR,
    cNextGotoType_DokanL,
    cNextGotoType_Fall,
    cNextGotoType_HipAttack,
    cNextGotoType_Slip,
    cNextGotoType_10,
    cNextGotoType_Normal_11,
    cNextGotoType_Normal_12,
    cNextGotoType_Normal_13,
    cNextGotoType_Door_14,
    cNextGotoType_DoorBoss,
    cNextGotoType_DokanD_Mame,
    cNextGotoType_DokanU_Mame,
    cNextGotoType_DokanR_Mame,
    cNextGotoType_DokanL_Mame,
    cNextGotoType_JumpL,
    cNextGotoType_Vine,
    cNextGotoType_JumpR,
    cNextGotoType_ShiroBoss,
    cNextGotoType_FinalBoss,
    cNextGotoType_Ambush,
    cNextGotoType_Normal_26,
    cNextGotoType_27,
    cNextGotoType_BoxingKoopaJr,
    cNextGotoType_Credits_P1,
    cNextGotoType_Credits_P2,
    cNextGotoType_Credits_P3,
    cNextGotoType_Credits_P4,
    cNextGotoType_Title,
    cNextGotoType_Ambush_ChibiYoshi,
    cNextGotoType_Num
};
static_assert(sizeof(NextGotoType) == 0x4);
static_assert(cNextGotoType_Num == 35);
