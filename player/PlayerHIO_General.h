#pragma once

#include <basis/seadTypes.h>

class PlayerMgr;

class PlayerHIO_General
{
public:
    // Address: 0x10169620
    static const s32 cDefaultStarTime;              // 11 seconds

    // Address: 0x10169624
    static const s32 cFaceAngleDefaultTarget;       // 60.2628866 degrees
    // Address: 0x10169628
    static const s32 cFaceAngleDefaultTargetCloud;  // 42.37040067 degrees

    // Address: 0x1016962C
    static const f32 cFaceAngleYtoXRatio;           // -0.02f
    // Address: 0x10169630
    static const s32 cFaceAngleYtoZRatio;           // -0.12f

    // Address: 0x10169634
    static const s32 cFaceAngleMaxStep;             // 8.8492267 degrees
    // Address: 0x10169638
    static const s32 cFaceAngleRevertMaxStep;       // 16.875 degrees

    // Address: 0x1016963C
    static const u32 cFaceAngleTurnTimeDefault;     // 10 seconds
    // Address: 0x10169640
    static const u32 cFaceAngleTurnTimeShort;       // 1/3 seconds

    // Address: 0x10169644
    static const s32 cDefaultWaterFunsuiEffectTime; // 1/6 seconds

    // Address: 0x10169648
    static const s32 cMaxAngleZ_1;                  // 30 degrees
    // Address: 0x1016964C
    static const s32 cMinAngleZ_1;                  // -45 degrees

    // Address: 0x10169650
    static const s32 cMaxAngleZ_2;                  // 17 degrees
    // Address: 0x10169654
    static const s32 cMinAngleZ_2;                  // -17 degrees

    // Address: 0x10169658
    static const s32 cMaxAngleY;                    // 113 degrees

    // Address: 0x1016965C
    static const f32 cSandSinkRate;                 // -1.26f

public:
    // Address: 0x02911F74
    PlayerHIO_General(PlayerMgr& mgr);
};
static_assert(sizeof(PlayerHIO_General) == 1);
