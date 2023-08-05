#pragma once

#include <basis/seadTypes.h>

class ProfileID
{
public:
    enum
    {
        cNum = 913,

        cActorSpawner,
        cFlipBlock,
        cMagicPlatform,
        cEffectPlayer,

        cNumAll
    };

public:
    static const u32 cFloorHoleDokan;               // 210

    static const u32 cYoshi;                        // 442
    static const u32 cTottenPlayer;                 // 443
    static const u32 cPlayerObject;                 // 444

    static const u32 cBgCenter;                     // 587

    static const u32 cCourseSelectPlayer;           // 854
    static const u32 cCourseSelectPlayer_2P_3P_4P;  // 855 (CS Player 2, 3 or 4)
};
