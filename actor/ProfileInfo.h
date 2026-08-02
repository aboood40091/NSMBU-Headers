#pragma once

#include <prim/seadSafeString.h>

#ifdef PROFILE_INFO_AS_NAMESPACE
#define PROFILE_INFO_TYPE namespace
#define PROFILE_INFO_ACCESS_SPEC_PUBLIC
#define PROFILE_INFO_ACCESS_SPEC_PRIVATE
#define PROFILE_INFO_STORAGE_STATIC extern
#else
#define PROFILE_INFO_TYPE class
#define PROFILE_INFO_ACCESS_SPEC_PUBLIC public:
#define PROFILE_INFO_ACCESS_SPEC_PRIVATE private:
#define PROFILE_INFO_STORAGE_STATIC static
#endif

#define PROFILE_INFO_DRAW_PRIO_NO_DRAW_MAX  (0x3ff)

#define PROFILE_INFO_DRAW_PRIO_DRAW(ID)     (ProfileInfo::cDrawPriority_Draw_##ID)
#define PROFILE_INFO_DRAW_PRIO_NO_DRAW(ID)  (ProfileInfo::cDrawPriority_NoDraw_##ID - PROFILE_INFO_DRAW_PRIO_NO_DRAW_MAX)

PROFILE_INFO_TYPE ProfileInfo
{
PROFILE_INFO_ACCESS_SPEC_PUBLIC
    enum
    {
        cProfileID_Max = 913    // Profiles 910, 911 and 912 are extra
    };

    enum ResType
    {
        cResType_Boot = 0,
        cResType_Course,
        cResType_CourseSelect,
        cResType_Num
    };

PROFILE_INFO_ACCESS_SPEC_PUBLIC
    // Address: 0x02019988
    PROFILE_INFO_STORAGE_STATIC s16 getDrawPriority(s32 id);
    // Address: 0x020199A8
    PROFILE_INFO_STORAGE_STATIC ResType getResType(s32 id);
    // Address: 0x020199CC
    PROFILE_INFO_STORAGE_STATIC u32 getResNum(s32 id);
    // Address: 0x020199EC
    PROFILE_INFO_STORAGE_STATIC const sead::SafeString* getResList(s32 id);

PROFILE_INFO_ACCESS_SPEC_PRIVATE
    enum DrawPriority
    {
        cDrawPriority_Draw_Prof_1B9                             =   0,
        cDrawPriority_Draw_PlayerObject,
        cDrawPriority_Draw_TottenPlayer,
        cDrawPriority_Draw_Yoshi,
        cDrawPriority_Draw_Prof_1BD,
        cDrawPriority_Draw_Kuribo,
        cDrawPriority_Draw_Kakibo,
        cDrawPriority_Draw_PataKuribo,
        cDrawPriority_Draw_Prof_1D6,
        cDrawPriority_Draw_Prof_1D7,
        cDrawPriority_Draw_Prof_1D8,
        cDrawPriority_Draw_Prof_1D9,
        cDrawPriority_Draw_IceBall,
        cDrawPriority_Draw_IceBallPakkun,
        cDrawPriority_Draw_FireBallPlayer,
        cDrawPriority_Draw_FireBallPakkun,
        cDrawPriority_Draw_YoshiFire,
        cDrawPriority_Draw_Prof_1DF,
        cDrawPriority_Draw_Prof_1E0,
        cDrawPriority_Draw_Prof_1E1,
        cDrawPriority_Draw_Prof_1E2,
        cDrawPriority_Draw_Prof_305,
        cDrawPriority_Draw_Prof_306,
        cDrawPriority_Draw_Prof_307,
        cDrawPriority_Draw_Prof_308,
        cDrawPriority_Draw_Prof_309,
        cDrawPriority_Draw_Prof_1E3,
        cDrawPriority_Draw_Prof_1E4,
        cDrawPriority_Draw_Prof_1E5,
        cDrawPriority_Draw_Prof_1E6,
        cDrawPriority_Draw_Prof_1E7,
        cDrawPriority_Draw_Prof_1E8,
        cDrawPriority_Draw_Prof_1E9,
        cDrawPriority_Draw_Prof_1EA,
        cDrawPriority_Draw_Prof_1EB,
        cDrawPriority_Draw_Prof_1EC,
        cDrawPriority_Draw_Prof_1ED,
        cDrawPriority_Draw_Prof_1EE,
        cDrawPriority_Draw_Prof_1EF,
        cDrawPriority_Draw_Prof_1F0,
        cDrawPriority_Draw_Prof_1F1,
        cDrawPriority_Draw_Prof_1F2,
        cDrawPriority_Draw_Prof_1F3,
        cDrawPriority_Draw_Prof_1F4,
        cDrawPriority_Draw_Prof_1F5,
        cDrawPriority_Draw_Prof_1F6,
        cDrawPriority_Draw_Prof_1F7,
        cDrawPriority_Draw_Prof_11B,
        cDrawPriority_Draw_Prof_14D,
        cDrawPriority_Draw_Prof_14E,
        cDrawPriority_Draw_Prof_14F,
        cDrawPriority_Draw_ObjPipeDown,
        cDrawPriority_Draw_Prof_151,
        cDrawPriority_Draw_Prof_152,
        cDrawPriority_Draw_Prof_153,
        cDrawPriority_Draw_ObjPipeDownGroup,
        cDrawPriority_Draw_Prof_082,
        cDrawPriority_Draw_Prof_083,
        cDrawPriority_Draw_Prof_084,
        cDrawPriority_Draw_Prof_085,
        cDrawPriority_Draw_Prof_155,
        cDrawPriority_Draw_Prof_156,
        cDrawPriority_Draw_Prof_157,
        cDrawPriority_Draw_ObjPipeDownNG,
        cDrawPriority_Draw_Prof_087,
        cDrawPriority_Draw_Prof_088,
        cDrawPriority_Draw_Prof_089,
        cDrawPriority_Draw_Prof_08A,
        cDrawPriority_Draw_Prof_08B,
        cDrawPriority_Draw_Prof_08C,
        cDrawPriority_Draw_Prof_08D,
        cDrawPriority_Draw_Prof_08E,
        cDrawPriority_Draw_Prof_05F,
        cDrawPriority_Draw_Prof_060,
        cDrawPriority_Draw_Prof_061,
        cDrawPriority_Draw_Prof_102,
        cDrawPriority_Draw_Prof_08F,
        cDrawPriority_Draw_Prof_090,
        cDrawPriority_Draw_Prof_062,
        cDrawPriority_Draw_Prof_063,
        cDrawPriority_Draw_Prof_05C,
        cDrawPriority_Draw_Prof_05D,
        cDrawPriority_Draw_Prof_05E,
        cDrawPriority_Draw_Prof_064,
        cDrawPriority_Draw_Prof_091,
        cDrawPriority_Draw_Prof_092,
        cDrawPriority_Draw_Prof_1FF,
        cDrawPriority_Draw_Nokonoko,
        cDrawPriority_Draw_Prof_201,
        cDrawPriority_Draw_Prof_202,
        cDrawPriority_Draw_Prof_203,
        cDrawPriority_Draw_Prof_204,
        cDrawPriority_Draw_Prof_17D,
        cDrawPriority_Draw_Prof_17E,
        cDrawPriority_Draw_Prof_205,
        cDrawPriority_Draw_Prof_206,
        cDrawPriority_Draw_Prof_208,
        cDrawPriority_Draw_Prof_207,
        cDrawPriority_Draw_Prof_209,
        cDrawPriority_Draw_Prof_20A,
        cDrawPriority_Draw_Prof_20B,
        cDrawPriority_Draw_MechaKoopa,
        cDrawPriority_Draw_Prof_20D,
        cDrawPriority_Draw_Prof_20E,
        cDrawPriority_Draw_PentaroIce,
        cDrawPriority_Draw_Prof_210,
        cDrawPriority_Draw_Prof_211,
        cDrawPriority_Draw_Prof_212,
        cDrawPriority_Draw_Prof_213,
        cDrawPriority_Draw_Prof_214,
        cDrawPriority_Draw_Prof_215,
        cDrawPriority_Draw_Prof_216,
        cDrawPriority_Draw_Prof_217,
        cDrawPriority_Draw_Prof_218,
        cDrawPriority_Draw_Prof_219,
        cDrawPriority_Draw_Prof_21A,
        cDrawPriority_Draw_Prof_21B,
        cDrawPriority_Draw_Prof_21C,
        cDrawPriority_Draw_Prof_21D,
        cDrawPriority_Draw_Prof_224,
        cDrawPriority_Draw_Prof_17F,
        cDrawPriority_Draw_Prof_180,
        cDrawPriority_Draw_Prof_181,
        cDrawPriority_Draw_Prof_182,
        cDrawPriority_Draw_Prof_225,
        cDrawPriority_Draw_Prof_226,
        cDrawPriority_Draw_Prof_229,
        cDrawPriority_Draw_Prof_22A,
        cDrawPriority_Draw_FireBar,
        cDrawPriority_Draw_FireBarSync,
        cDrawPriority_Draw_Prof_179,
        cDrawPriority_Draw_Prof_17A,
        cDrawPriority_Draw_Burner,
        cDrawPriority_Draw_Prof_0E1,
        cDrawPriority_Draw_Prof_0E2,
        cDrawPriority_Draw_Prof_0E3,
        cDrawPriority_Draw_Prof_0EB,
        cDrawPriority_Draw_Prof_22C,
        cDrawPriority_Draw_Prof_22D,
        cDrawPriority_Draw_FireBallKeronpa,
        cDrawPriority_Draw_FireBallKeronpaRDash,
        cDrawPriority_Draw_FireSnake,
        cDrawPriority_Draw_Prof_27D,
        cDrawPriority_Draw_Prof_27E,
        cDrawPriority_Draw_Prof_27F,
        cDrawPriority_Draw_GabonRock,
        cDrawPriority_Draw_Prof_281,
        cDrawPriority_Draw_Prof_282,
        cDrawPriority_Draw_RockGabonRock,
        cDrawPriority_Draw_Prof_284,
        cDrawPriority_Draw_SeichanSnowBall,
        cDrawPriority_Draw_Prof_286,
        cDrawPriority_Draw_Prof_232,
        cDrawPriority_Draw_Prof_233,
        cDrawPriority_Draw_Prof_234,
        cDrawPriority_Draw_Prof_236,
        cDrawPriority_Draw_Prof_237,
        cDrawPriority_Draw_Prof_238,
        cDrawPriority_Draw_Prof_239,
        cDrawPriority_Draw_Prof_23A,
        cDrawPriority_Draw_Prof_23B,
        cDrawPriority_Draw_Prof_23C,
        cDrawPriority_Draw_Prof_23D,
        cDrawPriority_Draw_Kazandan,
        cDrawPriority_Draw_Prof_Bun,
        cDrawPriority_Draw_BunW2,
        cDrawPriority_Draw_BunW3,
        cDrawPriority_Draw_BunW4,
        cDrawPriority_Draw_BunW5,
        cDrawPriority_Draw_BunW6,
        cDrawPriority_Draw_BunDemoKameck,
        cDrawPriority_Draw_LemmyBomb,
        cDrawPriority_Draw_Lemmy,
        cDrawPriority_Draw_LemmyBall,
        cDrawPriority_Draw_Morton,
        cDrawPriority_Draw_MortonSanbo,
        cDrawPriority_Draw_MortonSanboParts,
        cDrawPriority_Draw_Wendy,
        cDrawPriority_Draw_WendyRing,
        cDrawPriority_Draw_WendyIcicle,
        cDrawPriority_Draw_WendyFloor,
        cDrawPriority_Draw_Larry,
        cDrawPriority_Draw_KokoopaSearchFire,
        cDrawPriority_Draw_Ludwig,
        cDrawPriority_Draw_LudwigAlterEgo,
        cDrawPriority_Draw_Iggy,
        cDrawPriority_Draw_IggyMagic,
        cDrawPriority_Draw_IggyRoom,
        cDrawPriority_Draw_Woogan,
        cDrawPriority_Draw_Prof_Roy,
        cDrawPriority_Draw_BossKK,
        cDrawPriority_Draw_BossKKThunder,
        cDrawPriority_Draw_BossKKDemoKameck,
        cDrawPriority_Draw_BossKKDemoKK,
        cDrawPriority_Draw_Kameck,
        cDrawPriority_Draw_KameckIce,
        cDrawPriority_Draw_KameckMagic,
        cDrawPriority_Draw_PeachFinalCastleKoopaJr,
        cDrawPriority_Draw_PeachFinalCastleKoopaJrClown,
        cDrawPriority_Draw_PeachFinalCastleKoopaJrLift,
        cDrawPriority_Draw_PeachFinalCastleKoopaJrLiftHmove,
        cDrawPriority_Draw_PeachFinalCastleKoopaJrLiftPairObj,
        cDrawPriority_Draw_RoyLiftWakiStep,
        cDrawPriority_Draw_Koopa,
        cDrawPriority_Draw_KoopaFire,
        cDrawPriority_Draw_KoopaShutter,
        cDrawPriority_Draw_DemoKoopaJr,
        cDrawPriority_Draw_DemoKoopaJrClown,
        cDrawPriority_Draw_KoopaDemoKameck,
        cDrawPriority_Draw_FinalKoopa,
        cDrawPriority_Draw_FinalKoopaFire,
        cDrawPriority_Draw_FinalKoopaJr,
        cDrawPriority_Draw_FinalKoopaJrClown,
        cDrawPriority_Draw_FinalKoopaJrFire,
        cDrawPriority_Draw_FinalBomhei,
        cDrawPriority_Draw_KinokoLift,
        cDrawPriority_Draw_KinokoLiftColor,
        cDrawPriority_Draw_LiftZenStar,
        cDrawPriority_Draw_Prof_033,
        cDrawPriority_Draw_Prof_0AD,
        cDrawPriority_Draw_Prof_0AE,
        cDrawPriority_Draw_Prof_0AF,
        cDrawPriority_Draw_Prof_0B0,
        cDrawPriority_Draw_Prof_0B1,
        cDrawPriority_Draw_Prof_050,
        cDrawPriority_Draw_Prof_17C,
        cDrawPriority_Draw_Prof_051,
        cDrawPriority_Draw_Prof_235,
        cDrawPriority_Draw_Prof_16D,
        cDrawPriority_Draw_Block,
        cDrawPriority_Draw_Prof_1BE,
        cDrawPriority_Draw_Prof_1BF,
        cDrawPriority_Draw_Prof_1C4,
        cDrawPriority_Draw_Prof_1C3,
        cDrawPriority_Draw_Prof_1C0,
        cDrawPriority_Draw_Prof_1C1,
        cDrawPriority_Draw_Prof_1C2,
        cDrawPriority_Draw_Prof_1C7,
        cDrawPriority_Draw_Prof_1C8,
        cDrawPriority_Draw_Prof_1C9,
        cDrawPriority_Draw_Prof_1CA,
        cDrawPriority_Draw_Prof_1CB,
        cDrawPriority_Draw_Prof_1CC,
        cDrawPriority_Draw_Prof_1CD,
        cDrawPriority_Draw_Prof_1CE,
        cDrawPriority_Draw_QuestPrizeItem,
        cDrawPriority_Draw_Prof_1D0,
        cDrawPriority_Draw_Prof_1D1,
        cDrawPriority_Draw_Prof_183,
        cDrawPriority_Draw_Prof_184,
        cDrawPriority_Draw_Prof_185,
        cDrawPriority_Draw_Prof_186,
        cDrawPriority_Draw_Prof_22B,
        cDrawPriority_Draw_Prof_187,
        cDrawPriority_Draw_Kinoko,
        cDrawPriority_Draw_FireFlower,
        cDrawPriority_Draw_RealizeFeverStar,
        cDrawPriority_Draw_Star,
        cDrawPriority_Draw_MameKinoko,
        cDrawPriority_Draw_IceFlower,
        cDrawPriority_Draw_Propeller,
        cDrawPriority_Draw_Penguin,
        cDrawPriority_Draw_OneUpKinoko,
        cDrawPriority_Draw_Musasabi,
        cDrawPriority_Draw_SuperMoon,
        cDrawPriority_Draw_TitleDemoItem,
        cDrawPriority_Draw_Prof_097,
        cDrawPriority_Draw_Prof_036,
        cDrawPriority_Draw_Prof_037,
        cDrawPriority_Draw_Prof_038,
        cDrawPriority_Draw_Prof_039,
        cDrawPriority_Draw_Prof_03A,
        cDrawPriority_Draw_Prof_03B,
        cDrawPriority_Draw_PairObjChild,
        cDrawPriority_Draw_Prof_03D,
        cDrawPriority_Draw_Prof_03E,
        cDrawPriority_Draw_Prof_03F,
        cDrawPriority_Draw_Prof_040,
        cDrawPriority_Draw_Prof_041,
        cDrawPriority_Draw_Prof_042,
        cDrawPriority_Draw_Prof_043,
        cDrawPriority_Draw_Prof_044,
        cDrawPriority_Draw_Prof_045,
        cDrawPriority_Draw_Prof_046,
        cDrawPriority_Draw_Prof_047,
        cDrawPriority_Draw_Prof_048,
        cDrawPriority_Draw_Prof_049,
        cDrawPriority_Draw_Prof_04A,
        cDrawPriority_Draw_Prof_04B,
        cDrawPriority_Draw_Prof_04C,
        cDrawPriority_Draw_Prof_188,
        cDrawPriority_Draw_Prof_113,
        cDrawPriority_Draw_Prof_114,
        cDrawPriority_Draw_Prof_115,
        cDrawPriority_Draw_Prof_116,
        cDrawPriority_Draw_Prof_2E4,
        cDrawPriority_Draw_Prof_2E5,
        cDrawPriority_Draw_Prof_2E6,
        cDrawPriority_Draw_Prof_2E7,
        cDrawPriority_Draw_Prof_2E8,
        cDrawPriority_Draw_Prof_2E9,
        cDrawPriority_Draw_Prof_2EA,
        cDrawPriority_Draw_Prof_259,
        cDrawPriority_Draw_Prof_2EE,
        cDrawPriority_Draw_Prof_2EF,
        cDrawPriority_Draw_Prof_2F0,
        cDrawPriority_Draw_Prof_2F1,
        cDrawPriority_Draw_Prof_2F2,
        cDrawPriority_Draw_Prof_02B,
        cDrawPriority_Draw_Prof_02C,
        cDrawPriority_Draw_Prof_25A,
        cDrawPriority_Draw_Prof_25B,
        cDrawPriority_Draw_Prof_25C,
        cDrawPriority_Draw_Prof_25D,
        cDrawPriority_Draw_Prof_25E,
        cDrawPriority_Draw_Prof_25F,
        cDrawPriority_Draw_Prof_260,
        cDrawPriority_Draw_Prof_261,
        cDrawPriority_Draw_Prof_1AA,
        cDrawPriority_Draw_Prof_1AB,
        cDrawPriority_Draw_Prof_1AC,
        cDrawPriority_Draw_Prof_1AD,
        cDrawPriority_Draw_Prof_1AE,
        cDrawPriority_Draw_Prof_1AF,
        cDrawPriority_Draw_Prof_1B0,
        cDrawPriority_Draw_Prof_1B1,
        cDrawPriority_Draw_Prof_1B2,
        cDrawPriority_Draw_Prof_1B3,
        cDrawPriority_Draw_Prof_076,
        cDrawPriority_Draw_Prof_077,
        cDrawPriority_Draw_Prof_078,
        cDrawPriority_Draw_Prof_1B5,
        cDrawPriority_Draw_Prof_1B4,
        cDrawPriority_Draw_Prof_262,
        cDrawPriority_Draw_Prof_263,
        cDrawPriority_Draw_Prof_2F3,
        cDrawPriority_Draw_Prof_0BF,
        cDrawPriority_Draw_Prof_0C0,
        cDrawPriority_Draw_Prof_0C1,
        cDrawPriority_Draw_Hammer,
        cDrawPriority_Draw_Prof_2F5,
        cDrawPriority_Draw_Boomerang,
        cDrawPriority_Draw_Prof_2F7,
        cDrawPriority_Draw_FireBallBros,
        cDrawPriority_Draw_Prof_2F9,
        cDrawPriority_Draw_IceBallBros,
        cDrawPriority_Draw_Prof_2FB,
        cDrawPriority_Draw_MegaHammer,
        cDrawPriority_Draw_Prof_2FD,
        cDrawPriority_Draw_Prof_2FF,
        cDrawPriority_Draw_Prof_300,
        cDrawPriority_Draw_Prof_301,
        cDrawPriority_Draw_Prof_121,
        cDrawPriority_Draw_Prof_122,
        cDrawPriority_Draw_ActorBlockRenga,
        cDrawPriority_Draw_Prof_124,
        cDrawPriority_Draw_Prof_125,
        cDrawPriority_Draw_Prof_126,
        cDrawPriority_Draw_Prof_127,
        cDrawPriority_Draw_Prof_128,
        cDrawPriority_Draw_Prof_129,
        cDrawPriority_Draw_Prof_12A,
        cDrawPriority_Draw_Prof_12B,
        cDrawPriority_Draw_Prof_12C,
        cDrawPriority_Draw_Prof_12D,
        cDrawPriority_Draw_Prof_12E,
        cDrawPriority_Draw_Prof_12F,
        cDrawPriority_Draw_Prof_130,
        cDrawPriority_Draw_Prof_131,
        cDrawPriority_Draw_Prof_132,
        cDrawPriority_Draw_Prof_133,
        cDrawPriority_Draw_Prof_134,
        cDrawPriority_Draw_Prof_13F,
        cDrawPriority_Draw_Prof_140,
        cDrawPriority_Draw_ActorBlockMakeDRC,
        cDrawPriority_Draw_Prof_136,
        cDrawPriority_Draw_Prof_137,
        cDrawPriority_Draw_Prof_138,
        cDrawPriority_Draw_Prof_13A,
        cDrawPriority_Draw_Prof_13B,
        cDrawPriority_Draw_Prof_0E4,
        cDrawPriority_Draw_Prof_0F5,
        cDrawPriority_Draw_Prof_0F6,
        cDrawPriority_Draw_Prof_0F7,
        cDrawPriority_Draw_Prof_0F8,
        cDrawPriority_Draw_Prof_0F9,
        cDrawPriority_Draw_Prof_139,
        cDrawPriority_Draw_Prof_13C,
        cDrawPriority_Draw_Prof_13D,
        cDrawPriority_Draw_Prof_13E,
        cDrawPriority_Draw_Prof_141,
        cDrawPriority_Draw_Prof_142,
        cDrawPriority_Draw_Prof_143,
        cDrawPriority_Draw_Prof_14B,
        cDrawPriority_Draw_ActorCoin,
        cDrawPriority_Draw_Prof_18C,
        cDrawPriority_Draw_Prof_18D,
        cDrawPriority_Draw_Prof_18E,
        cDrawPriority_Draw_Prof_18F,
        cDrawPriority_Draw_Prof_190,
        cDrawPriority_Draw_Prof_191,
        cDrawPriority_Draw_Prof_192,
        cDrawPriority_Draw_Prof_193,
        cDrawPriority_Draw_Prof_194,
        cDrawPriority_Draw_Prof_195,
        cDrawPriority_Draw_Prof_196,
        cDrawPriority_Draw_Prof_197,
        cDrawPriority_Draw_Prof_198,
        cDrawPriority_Draw_Prof_199,
        cDrawPriority_Draw_Prof_19A,
        cDrawPriority_Draw_Prof_19B,
        cDrawPriority_Draw_Prof_19C,
        cDrawPriority_Draw_Prof_19D,
        cDrawPriority_Draw_Prof_19E,
        cDrawPriority_Draw_Prof_1A0,
        cDrawPriority_Draw_Prof_19F,
        cDrawPriority_Draw_Prof_032,
        cDrawPriority_Draw_Prof_1A1,
        cDrawPriority_Draw_Prof_1A2,
        cDrawPriority_Draw_Prof_1A3,
        cDrawPriority_Draw_Prof_1A4,
        cDrawPriority_Draw_Prof_1A5,
        cDrawPriority_Draw_Prof_1A6,
        cDrawPriority_Draw_Prof_1A7,
        cDrawPriority_Draw_Prof_1A8,
        cDrawPriority_Draw_BlueCoin,
        cDrawPriority_Draw_Prof_264,
        cDrawPriority_Draw_Prof_1F9,
        cDrawPriority_Draw_Prof_1FA,
        cDrawPriority_Draw_Prof_1FB,
        cDrawPriority_Draw_Prof_1FC,
        cDrawPriority_Draw_Prof_1FD,
        cDrawPriority_Draw_Prof_1FE,
        cDrawPriority_Draw_Prof_311,
        cDrawPriority_Draw_Prof_312,
        cDrawPriority_Draw_Prof_052,
        cDrawPriority_Draw_Prof_053,
        cDrawPriority_Draw_Prof_0C5,
        cDrawPriority_Draw_Prof_0C6,
        cDrawPriority_Draw_Prof_265,
        cDrawPriority_Draw_KillerHoudai,
        cDrawPriority_Draw_StretchKillerHoudai,
        cDrawPriority_Draw_MagnumKillerHoudai,
        cDrawPriority_Draw_MagnumKillerHoudaiDown,
        cDrawPriority_Draw_SearchKillerHoudai,
        cDrawPriority_Draw_SearchMagnumKillerHoudai,
        cDrawPriority_Draw_SearchMagnumKillerHoudaiDown,
        cDrawPriority_Draw_MagnumKillerHoudaiRDash,
        cDrawPriority_Draw_MagnumKillerHoudaiDownRDash,
        cDrawPriority_Draw_SearchMagnumKillerHoudaiRDash,
        cDrawPriority_Draw_SearchMagnumKillerHoudaiDownRDash,
        cDrawPriority_Draw_Prof_070,
        cDrawPriority_Draw_Prof_071,
        cDrawPriority_Draw_Prof_072,
        cDrawPriority_Draw_Prof_073,
        cDrawPriority_Draw_Prof_074,
        cDrawPriority_Draw_Prof_273,
        cDrawPriority_Draw_Prof_075,
        cDrawPriority_Draw_Prof_274,
        cDrawPriority_Draw_Prof_275,
        cDrawPriority_Draw_SearchKiller,
        cDrawPriority_Draw_Prof_277,
        cDrawPriority_Draw_Prof_278,
        cDrawPriority_Draw_Prof_279,
        cDrawPriority_Draw_Prof_27B,
        cDrawPriority_Draw_Prof_27C,
        cDrawPriority_Draw_SwitchHatenaButton,
        cDrawPriority_Draw_SwitchPbutton,
        cDrawPriority_Draw_SwitchPbuttonRDash,
        cDrawPriority_Draw_SwitchPbuttonNoWallKick,
        cDrawPriority_Draw_Prof_15C,
        cDrawPriority_Draw_Prof_15D,
        cDrawPriority_Draw_Prof_313,
        cDrawPriority_Draw_Prof_314,
        cDrawPriority_Draw_Prof_315,
        cDrawPriority_Draw_Prof_316,
        cDrawPriority_Draw_Prof_317,
        cDrawPriority_Draw_Prof_318,
        cDrawPriority_Draw_Prof_319,
        cDrawPriority_Draw_TarzanIvy,
        cDrawPriority_Draw_Prof_0EF,
        cDrawPriority_Draw_Prof_0F0,
        cDrawPriority_Draw_SnakeBlock,
        cDrawPriority_Draw_Prof_0C3,
        cDrawPriority_Draw_Prof_0C4,
        cDrawPriority_Draw_Prof_0C8,
        cDrawPriority_Draw_Prof_31E,
        cDrawPriority_Draw_Prof_31D,
        cDrawPriority_Draw_Prof_0C7,
        cDrawPriority_Draw_Prof_0E5,
        cDrawPriority_Draw_Prof_117,
        cDrawPriority_Draw_Prof_31F,
        cDrawPriority_Draw_Prof_166,
        cDrawPriority_Draw_Prof_2F4,
        cDrawPriority_Draw_Prof_303,
        cDrawPriority_Draw_Prof_304,
        cDrawPriority_Draw_Intermittent,
        cDrawPriority_Draw_IntermittentPermanent,
        cDrawPriority_Draw_WaterIntermittent,
        cDrawPriority_Draw_WaterIntermittentPermanent,
        cDrawPriority_Draw_WaterIntermittentPermanentRD3_3,
        cDrawPriority_Draw_Prof_07E,
        cDrawPriority_Draw_WaterIntermittentBossChild,
        cDrawPriority_Draw_YoganIntermittent,
        cDrawPriority_Draw_Woochan,
        cDrawPriority_Draw_Prof_268,
        cDrawPriority_Draw_Spanner,
        cDrawPriority_Draw_Prof_26A,
        cDrawPriority_Draw_Prof_26B,
        cDrawPriority_Draw_Prof_26C,
        cDrawPriority_Draw_Prof_26D,
        cDrawPriority_Draw_Prof_26E,
        cDrawPriority_Draw_Prof_26F,
        cDrawPriority_Draw_Prof_270,
        cDrawPriority_Draw_Prof_0B2,
        cDrawPriority_Draw_Prof_100,
        cDrawPriority_Draw_Prof_101,
        cDrawPriority_Draw_Prof_0B3,
        cDrawPriority_Draw_Prof_16B,
        cDrawPriority_Draw_Prof_16C,
        cDrawPriority_Draw_Prof_0B4,
        cDrawPriority_Draw_Prof_0B5,
        cDrawPriority_Draw_Prof_0B6,
        cDrawPriority_Draw_Prof_0B7,
        cDrawPriority_Draw_LineSpinLift,
        cDrawPriority_Draw_LineSpinLiftParentRDash,
        cDrawPriority_Draw_LineSpinLiftChildRDash,
        cDrawPriority_Draw_Prof_0BC,
        cDrawPriority_Draw_Prof_081,
        cDrawPriority_Draw_Prof_093,
        cDrawPriority_Draw_Prof_094,
        cDrawPriority_Draw_Prof_095,
        cDrawPriority_Draw_Prof_096,
        cDrawPriority_Draw_ElasticKinokoParent,
        cDrawPriority_Draw_Prof_0CB,
        cDrawPriority_Draw_Prof_0CC,
        cDrawPriority_Draw_Prof_0E7,
        cDrawPriority_Draw_Prof_0E8,
        cDrawPriority_Draw_Prof_0E6,
        cDrawPriority_Draw_Prof_0EA,
        cDrawPriority_Draw_Prof_287,
        cDrawPriority_Draw_Prof_288,
        cDrawPriority_Draw_Prof_289,
        cDrawPriority_Draw_Prof_28B,
        cDrawPriority_Draw_Prof_28C,
        cDrawPriority_Draw_Prof_28D,
        cDrawPriority_Draw_Prof_098,
        cDrawPriority_Draw_Prof_099,
        cDrawPriority_Draw_Prof_09A,
        cDrawPriority_Draw_Prof_09B,
        cDrawPriority_Draw_Prof_09C,
        cDrawPriority_Draw_Prof_09D,
        cDrawPriority_Draw_Prof_09E,
        cDrawPriority_Draw_Prof_09F,
        cDrawPriority_Draw_Prof_0A1,
        cDrawPriority_Draw_Prof_0A2,
        cDrawPriority_Draw_Prof_0A3,
        cDrawPriority_Draw_Prof_0A4,
        cDrawPriority_Draw_Prof_0A5,
        cDrawPriority_Draw_Prof_0A6,
        cDrawPriority_Draw_Prof_0A0,
        cDrawPriority_Draw_Prof_0A7,
        cDrawPriority_Draw_Prof_0A8,
        cDrawPriority_Draw_Prof_0A9,
        cDrawPriority_Draw_Prof_0AA,
        cDrawPriority_Draw_Prof_0AB,
        cDrawPriority_Draw_Prof_0AC,
        cDrawPriority_Draw_Prof_0BE,
        cDrawPriority_Draw_Prof_0BD,
        cDrawPriority_Draw_Prof_0BB,
        cDrawPriority_Draw_Prof_320,
        cDrawPriority_Draw_Prof_0D3,
        cDrawPriority_Draw_Prof_0D6,
        cDrawPriority_Draw_Prof_0D4,
        cDrawPriority_Draw_Prof_0D5,
        cDrawPriority_Draw_Prof_0D7,
        cDrawPriority_Draw_Prof_0D8,
        cDrawPriority_Draw_Prof_0D9,
        cDrawPriority_Draw_Prof_0DA,
        cDrawPriority_Draw_Prof_0DB,
        cDrawPriority_Draw_Prof_103,
        cDrawPriority_Draw_Prof_0DC,
        cDrawPriority_Draw_Prof_0DD,
        cDrawPriority_Draw_Prof_0FA,
        cDrawPriority_Draw_Prof_0FB,
        cDrawPriority_Draw_Prof_162,
        cDrawPriority_Draw_Prof_29F,
        cDrawPriority_Draw_Prof_0E9,
        cDrawPriority_Draw_Prof_29E,
        cDrawPriority_Draw_Prof_2A1,
        cDrawPriority_Draw_Prof_2A2,
        cDrawPriority_Draw_Prof_1F8,
        cDrawPriority_Draw_Prof_2A3,
        cDrawPriority_Draw_Prof_104,
        cDrawPriority_Draw_Prof_16E,
        cDrawPriority_Draw_Prof_16F,
        cDrawPriority_Draw_Prof_29D,
        cDrawPriority_Draw_Prof_30A,
        cDrawPriority_Draw_IcicleBig,
        cDrawPriority_Draw_Prof_30B,
        cDrawPriority_Draw_Prof_30C,
        cDrawPriority_Draw_Prof_30D,
        cDrawPriority_Draw_Prof_30E,
        cDrawPriority_Draw_Prof_30F,
        cDrawPriority_Draw_Prof_310,
        cDrawPriority_Draw_Prof_163,
        cDrawPriority_Draw_Prof_164,
        cDrawPriority_Draw_Prof_165,
        cDrawPriority_Draw_Prof_11D,
        cDrawPriority_Draw_Prof_11E,
        cDrawPriority_Draw_Maruta,
        cDrawPriority_Draw_Prof_0DF,
        cDrawPriority_Draw_Prof_0EC,
        cDrawPriority_Draw_FloorGyration,
        cDrawPriority_Draw_FloorHoleDokan,
        cDrawPriority_Draw_Prof_0D0,
        cDrawPriority_Draw_Prof_0D1,
        cDrawPriority_Draw_Prof_0C9,
        cDrawPriority_Draw_Prof_0CA,
        cDrawPriority_Draw_Prof_107,
        cDrawPriority_Draw_Prof_0CD,
        cDrawPriority_Draw_Prof_0CE,
        cDrawPriority_Draw_Prof_0CF,
        cDrawPriority_Draw_Bubble,
        cDrawPriority_Draw_BubbleSync,
        cDrawPriority_Draw_BubbleRDash,
        cDrawPriority_Draw_BubbleSyncRDash,
        cDrawPriority_Draw_Prof_292,
        cDrawPriority_Draw_Prof_293,
        cDrawPriority_Draw_Prof_294,
        cDrawPriority_Draw_Prof_295,
        cDrawPriority_Draw_Prof_298,
        cDrawPriority_Draw_Prof_299,
        cDrawPriority_Draw_Prof_29A,
        cDrawPriority_Draw_Prof_29B,
        cDrawPriority_Draw_Prof_29C,
        cDrawPriority_Draw_Prof_161,
        cDrawPriority_Draw_Prof_168,
        cDrawPriority_Draw_Prof_169,
        cDrawPriority_Draw_Prof_0F3,
        cDrawPriority_Draw_Prof_0F4,
        cDrawPriority_Draw_Prof_322,
        cDrawPriority_Draw_Prof_323,
        cDrawPriority_Draw_Prof_324,
        cDrawPriority_Draw_Prof_325,
        cDrawPriority_Draw_PlyIce,
        cDrawPriority_Draw_Prof_326,
        cDrawPriority_Draw_Prof_144,
        cDrawPriority_Draw_Prof_145,
        cDrawPriority_Draw_Prof_146,
        cDrawPriority_Draw_Prof_147,
        cDrawPriority_Draw_Prof_0F1,
        cDrawPriority_Draw_Prof_0F2,
        cDrawPriority_Draw_Prof_327,
        cDrawPriority_Draw_Prof_328,
        cDrawPriority_Draw_BattleItem,
        cDrawPriority_Draw_VsBattleItem,
        cDrawPriority_Draw_Prof_2A4,
        cDrawPriority_Draw_Prof_2A5,
        cDrawPriority_Draw_Prof_321,
        cDrawPriority_Draw_Prof_32C,
        cDrawPriority_Draw_Prof_32D,
        cDrawPriority_Draw_Prof_32F,
        cDrawPriority_Draw_Prof_330,
        cDrawPriority_Draw_Prof_331,
        cDrawPriority_Draw_Prof_32A,
        cDrawPriority_Draw_KokoopaShipLemmy,
        cDrawPriority_Draw_KokoopaShipMorton,
        cDrawPriority_Draw_KokoopaShipLarry,
        cDrawPriority_Draw_KokoopaShipWendy,
        cDrawPriority_Draw_KokoopaShipIggy,
        cDrawPriority_Draw_KokoopaShipRoy,
        cDrawPriority_Draw_KokoopaShipLudwig,
        cDrawPriority_Draw_KokoopaShipWarpCannon,
        cDrawPriority_Draw_Peach,
        cDrawPriority_Draw_Prof_2E0,
        cDrawPriority_Draw_FinalDVPeach,
        cDrawPriority_Draw_FinalDVShutter,
        cDrawPriority_Draw_Prof_2E3,
        cDrawPriority_Draw_Prof_1D2,
        cDrawPriority_Draw_Prof_148,
        cDrawPriority_Draw_Prof_149,
        cDrawPriority_Draw_Prof_14A,
        cDrawPriority_Draw_Prof_119,
        cDrawPriority_Draw_Prof_11A,
        cDrawPriority_Draw_Prof_108,
        cDrawPriority_Draw_KoopaJrFire,
        cDrawPriority_Draw_KoopaJrBall,
        cDrawPriority_Draw_Prof_174,
        cDrawPriority_Draw_Prof_025,
        cDrawPriority_Draw_UnderwaterKoopaJr,
        cDrawPriority_Draw_UnderwaterKoopaJrClown,
        cDrawPriority_Draw_UnderwaterKoopaJrRetreatPos,
        cDrawPriority_Draw_BoxingKoopaJr,
        cDrawPriority_Draw_BoxingKoopaJrClown,
        cDrawPriority_Draw_BoxingKoopaJrPostBattleDemo,
        cDrawPriority_Draw_BoxingKoopaJrClownPostBattleDemo,
        cDrawPriority_Draw_Prof_054,
        cDrawPriority_Draw_Prof_055,
        cDrawPriority_Draw_Prof_056,
        cDrawPriority_Draw_Prof_057,
        cDrawPriority_Draw_Prof_058,
        cDrawPriority_Draw_Prof_059,
        cDrawPriority_Draw_BgActorYukaMario,
        cDrawPriority_Draw_Prof_05B,
        cDrawPriority_Draw_Prof_0FC,
        cDrawPriority_Draw_Prof_0FD,
        cDrawPriority_Draw_Prof_0FE,
        cDrawPriority_Draw_Prof_0FF,
        cDrawPriority_Draw_SlotYoshiChibi,
        cDrawPriority_Draw_MiniGamePanelItem,
        cDrawPriority_Draw_SlotItem,
        cDrawPriority_Draw_ShuffleBlock,
        cDrawPriority_Draw_CoinmakiCoin,
        cDrawPriority_Draw_CoinmakiItem,
        cDrawPriority_Draw_CoinmakiCannon,
        cDrawPriority_Draw_MiniGameKinopio,
        cDrawPriority_Draw_Prof_33F,
        cDrawPriority_Draw_Prof_340,
        cDrawPriority_Draw_Prof_341,
        cDrawPriority_Draw_Prof_342,
        cDrawPriority_Draw_Prof_10A,
        cDrawPriority_Draw_Prof_10B,
        cDrawPriority_Draw_Prof_10C,
        cDrawPriority_Draw_Prof_118,
        cDrawPriority_Draw_Prof_17B,
        cDrawPriority_Draw_Prof_350,
        cDrawPriority_Draw_StaffRollMgr,
        cDrawPriority_Draw_StaffRollMgrRDash,
        cDrawPriority_Draw_StaffCreditChibiYoshiABC,
        cDrawPriority_Draw_StaffCreditChibiYoshiBalloon,
        cDrawPriority_Draw_StaffCreditChibiYoshiBalloonCheer,
        cDrawPriority_Draw_StaffCreditChibiYoshiLight,
        cDrawPriority_Draw_StaffCreditChibiYoshiLightCheer,
        cDrawPriority_Draw_StaffCreditSoapABC,
        cDrawPriority_Draw_StaffCreditSoapCoin,
        cDrawPriority_Draw_StaffCreditTottenKun,
        cDrawPriority_Draw_CourseSelectPlayer,
        cDrawPriority_Draw_CourseSelectPlayer2PSub,
        cDrawPriority_Draw_CourseSelectChibiYoshi,
        cDrawPriority_Draw_CourseSelectCamera,
        cDrawPriority_Draw_CourseSelectCastle,
        cDrawPriority_Draw_CourseSelectToride,
        cDrawPriority_Draw_CourseSelectKinokoHouse1up,
        cDrawPriority_Draw_CourseSelectKinokoHouseShuffle,
        cDrawPriority_Draw_CourseSelectKinokoHouseSlot,
        cDrawPriority_Draw_CourseSelectPeachGates1st,
        cDrawPriority_Draw_CourseSelectPeachGates2nd,
        cDrawPriority_Draw_CourseSelectCoursePoint,
        cDrawPriority_Draw_CourseSelectWorldMoveDokan,
        cDrawPriority_Draw_CourseSelectGhost,
        cDrawPriority_Draw_CourseSelectW8Cloud,
        cDrawPriority_Draw_CourseSelectW2Bros,
        cDrawPriority_Draw_CourseSelectEventAssistant,
        cDrawPriority_Draw_CourseSelectShipW1,
        cDrawPriority_Draw_CourseSelectShipW2,
        cDrawPriority_Draw_CourseSelectShipW3,
        cDrawPriority_Draw_CourseSelectShipW4,
        cDrawPriority_Draw_CourseSelectShipW5,
        cDrawPriority_Draw_CourseSelectShipW6,
        cDrawPriority_Draw_CourseSelectShipW7,
        cDrawPriority_Draw_CourseSelectShipW8,
        cDrawPriority_Draw_CourseSelectShipW8Broken,
        cDrawPriority_Draw_CourseSelectSurrender,
        cDrawPriority_Draw_CourseSelectSwitchA,
        cDrawPriority_Draw_CourseSelectSwitchB,
        cDrawPriority_Draw_CourseSelectTeresa,
        cDrawPriority_Draw_CourseSelectOpeningKameck,
        cDrawPriority_Draw_CourseSelectTorideBoss,
        cDrawPriority_Draw_CourseSelectPakkun,
        cDrawPriority_Draw_CourseSelectShadowFirstDemoKinopio,
        cDrawPriority_Draw_CourseSelectTobiPuku,
        cDrawPriority_Draw_CourseSelectChorobon,
        cDrawPriority_Draw_CourseSelectW7Item,
        cDrawPriority_Draw_CourseSelectW5Teresa,
        cDrawPriority_Draw_CourseSelectFlag,
        cDrawPriority_Draw_Unused_776,
        cDrawPriority_Draw_CourseSelectMusasabi,
        cDrawPriority_Draw_CourseSelectWPillar,
        cDrawPriority_Draw_CourseSelectW7Bridge,
        cDrawPriority_Draw_CourseSelectMiiBalloon,
        cDrawPriority_Draw_CourseSelectPenguin,
        cDrawPriority_Draw_CourseSelectW4Item,
        cDrawPriority_Draw_CourseSelectW2Kuribo,
        cDrawPriority_Draw_CourseSelectPakkunBig,
        cDrawPriority_Draw_CourseSelectShadowKunIcon,
        cDrawPriority_Draw_CourseSelectDekaUnira,
        cDrawPriority_Draw_CourseSelectTomb,
        cDrawPriority_Draw_CourseSelectShadowFirstDemoShadowKun,
        cDrawPriority_Draw_CourseSelectKotsuCoaster,
        cDrawPriority_Draw_CourseSelectKoopaJr,
        cDrawPriority_Draw_CourseSelectPeach,
        cDrawPriority_Draw_CourseSelectW1Item,
        cDrawPriority_Draw_CourseSelectStarGate,
        cDrawPriority_Draw_Prof_38E,
        cDrawPriority_Draw_Prof_38F,

        cDrawPriority_Draw_Num,

        // No Draw
        cDrawPriority_NoDraw_Prof_390                           = 0,
        cDrawPriority_NoDraw_Prof_120,
        cDrawPriority_NoDraw_Prof_23F,
        cDrawPriority_NoDraw_Prof_240,
        cDrawPriority_NoDraw_Prof_241,
        cDrawPriority_NoDraw_Prof_242,
        cDrawPriority_NoDraw_Prof_243,
        cDrawPriority_NoDraw_Prof_244,
        cDrawPriority_NoDraw_Prof_245,
        cDrawPriority_NoDraw_Prof_246,
        cDrawPriority_NoDraw_Prof_247,
        cDrawPriority_NoDraw_Prof_248,
        cDrawPriority_NoDraw_Prof_249,
        cDrawPriority_NoDraw_Prof_24A,
        cDrawPriority_NoDraw_BgCenter,
        cDrawPriority_NoDraw_Prof_24C,
        cDrawPriority_NoDraw_Prof_24E,
        cDrawPriority_NoDraw_Prof_000,
        cDrawPriority_NoDraw_Prof_001,
        cDrawPriority_NoDraw_Prof_002,
        cDrawPriority_NoDraw_Prof_003,
        cDrawPriority_NoDraw_Prof_004,
        cDrawPriority_NoDraw_Prof_005,
        cDrawPriority_NoDraw_Prof_006,
        cDrawPriority_NoDraw_Prof_007,
        cDrawPriority_NoDraw_Prof_008,
        cDrawPriority_NoDraw_Prof_009,
        cDrawPriority_NoDraw_Prof_00B,
        cDrawPriority_NoDraw_Prof_00C,
        cDrawPriority_NoDraw_Prof_00D,
        cDrawPriority_NoDraw_Prof_027,
        cDrawPriority_NoDraw_Prof_028,
        cDrawPriority_NoDraw_Prof_029,
        cDrawPriority_NoDraw_Prof_02A,
        cDrawPriority_NoDraw_Prof_189,
        cDrawPriority_NoDraw_Prof_18A,
        cDrawPriority_NoDraw_Prof_267,
        cDrawPriority_NoDraw_Prof_266,
        cDrawPriority_NoDraw_Prof_21E,
        cDrawPriority_NoDraw_Prof_21F,
        cDrawPriority_NoDraw_Prof_220,
        cDrawPriority_NoDraw_Prof_026,
        cDrawPriority_NoDraw_Prof_223,
        cDrawPriority_NoDraw_Prof_2EB,
        cDrawPriority_NoDraw_Prof_271,
        cDrawPriority_NoDraw_Prof_272,
        cDrawPriority_NoDraw_Prof_221,
        cDrawPriority_NoDraw_Prof_222,
        cDrawPriority_NoDraw_Prof_20F,
        cDrawPriority_NoDraw_Prof_02D,
        cDrawPriority_NoDraw_Prof_02E,
        cDrawPriority_NoDraw_Prof_00E,
        cDrawPriority_NoDraw_Prof_00F,
        cDrawPriority_NoDraw_Prof_010,
        cDrawPriority_NoDraw_BunDemo,
        cDrawPriority_NoDraw_KokoopaDemo,
        cDrawPriority_NoDraw_KoopaJrDemo,
        cDrawPriority_NoDraw_KameckDemo,
        cDrawPriority_NoDraw_BossKKDemo,
        cDrawPriority_NoDraw_PeachFinalCastleKoopaJrDemo,
        cDrawPriority_NoDraw_KoopaDemo,
        cDrawPriority_NoDraw_FinalKoopaDemo,
        cDrawPriority_NoDraw_PeachDemo,
        cDrawPriority_NoDraw_KameckIceConfig,
        cDrawPriority_NoDraw_KameckWarpPos,
        cDrawPriority_NoDraw_Prof_011,
        cDrawPriority_NoDraw_Prof_012,
        cDrawPriority_NoDraw_Prof_02F,
        cDrawPriority_NoDraw_Prof_030,
        cDrawPriority_NoDraw_Prof_2EC,
        cDrawPriority_NoDraw_Prof_2ED,
        cDrawPriority_NoDraw_Prof_00A,
        cDrawPriority_NoDraw_Prof_014,
        cDrawPriority_NoDraw_Prof_031,
        cDrawPriority_NoDraw_Prof_167,
        cDrawPriority_NoDraw_Prof_015,
        cDrawPriority_NoDraw_Prof_016,
        cDrawPriority_NoDraw_Prof_017,
        cDrawPriority_NoDraw_MiniGameMgr,
        cDrawPriority_NoDraw_MiniGameMgrRDash,
        cDrawPriority_NoDraw_ShuffleBlockMgr,
        cDrawPriority_NoDraw_SlotMgr,
        cDrawPriority_NoDraw_CoinmakiMgr,
        cDrawPriority_NoDraw_Prof_1C6,
        cDrawPriority_NoDraw_WakiSearchMagKiller,
        cDrawPriority_NoDraw_Prof_32E,
        cDrawPriority_NoDraw_Prof_01D,
        cDrawPriority_NoDraw_Prof_01E,
        cDrawPriority_NoDraw_Prof_01F,
        cDrawPriority_NoDraw_KoopaFireWaki,
        cDrawPriority_NoDraw_Prof_31A,
        cDrawPriority_NoDraw_Prof_020,
        cDrawPriority_NoDraw_Prof_013,
        cDrawPriority_NoDraw_Prof_31B,
        cDrawPriority_NoDraw_Prof_31C,
        cDrawPriority_NoDraw_ShootingStar,
        cDrawPriority_NoDraw_Prof_302,
        cDrawPriority_NoDraw_Prof_227,
        cDrawPriority_NoDraw_Prof_228,
        cDrawPriority_NoDraw_Prof_343,
        cDrawPriority_NoDraw_Prof_344,
        cDrawPriority_NoDraw_Prof_345,
        cDrawPriority_NoDraw_RoyLiftWaki,
        cDrawPriority_NoDraw_Prof_2A0,
        cDrawPriority_NoDraw_Prof_346,
        cDrawPriority_NoDraw_Prof_024,
        cDrawPriority_NoDraw_Prof_24D,
        cDrawPriority_NoDraw_Prof_230,
        cDrawPriority_NoDraw_Prof_296,
        cDrawPriority_NoDraw_Prof_297,
        cDrawPriority_NoDraw_Prof_351,
        cDrawPriority_NoDraw_Prof_11C,
        cDrawPriority_NoDraw_Prof_1B8,
        cDrawPriority_NoDraw_Prof_352,
        cDrawPriority_NoDraw_Prof_353,
        cDrawPriority_NoDraw_Prof_14C,
        cDrawPriority_NoDraw_Prof_347,
        cDrawPriority_NoDraw_Prof_1B7,

        cDrawPriority_NoDraw_Num
    };

    static_assert(cDrawPriority_NoDraw_Num <= PROFILE_INFO_DRAW_PRIO_NO_DRAW_MAX, "No Draw priority exceeds maximum limit.");

    // Address: 0x10001940
    PROFILE_INFO_STORAGE_STATIC const s16               cDrawPriority[cProfileID_Max];
    // Address: 0x10002064
    PROFILE_INFO_STORAGE_STATIC const s8                cResType[cProfileID_Max];
    // Address: 0x100023F8
    PROFILE_INFO_STORAGE_STATIC const u8                cResNum[cProfileID_Max];
    // Address: 0x101C321C
    PROFILE_INFO_STORAGE_STATIC const sead::SafeString* cResList[cProfileID_Max];

PROFILE_INFO_ACCESS_SPEC_PUBLIC
    // Address: 0x10003D54
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_000;                                       //   0
    // Address: 0x10003D58
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_001;                                       //   1
    // Address: 0x10003D5C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_002;                                       //   2
    // Address: 0x10003D60
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_003;                                       //   3
    // Address: 0x10003D64
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_004;                                       //   4
    // Address: 0x10003D68
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_005;                                       //   5
    // Address: 0x10003D6C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_006;                                       //   6
    // Address: 0x10003D70
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_007;                                       //   7
    // Address: 0x10003D74
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_008;                                       //   8
    // Address: 0x10003D78
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_009;                                       //   9
    // Address: 0x10003D7C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_00A;                                       //  10
    // Address: 0x10003D80
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_00B;                                       //  11
    // Address: 0x10003D84
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_00C;                                       //  12
    // Address: 0x10003D88
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_00D;                                       //  13
    // Address: 0x10003D8C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_00E;                                       //  14
    // Address: 0x10003D90
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_00F;                                       //  15
    // Address: 0x10003D94
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_010;                                       //  16
    // Address: 0x10003D98
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_011;                                       //  17
    // Address: 0x10003D9C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_012;                                       //  18
    // Address: 0x10003DA0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_013;                                       //  19
    // Address: 0x10003DA4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_014;                                       //  20
    // Address: 0x10003DA8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_015;                                       //  21
    // Address: 0x10003DAC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_016;                                       //  22
    // Address: 0x10003DB0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_017;                                       //  23
    // Address: 0x10003DB4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MiniGameMgr;                               //  24
    // Address: 0x10003DB8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MiniGameMgrRDash;                          //  25
    // Address: 0x10003DBC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_ShuffleBlockMgr;                           //  26
    // Address: 0x10003DC0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SlotMgr;                                   //  27
    // Address: 0x10003DC4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CoinmakiMgr;                               //  28
    // Address: 0x10003DC8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_01D;                                       //  29
    // Address: 0x10003DCC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_01E;                                       //  30
    // Address: 0x10003DD0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_01F;                                       //  31
    // Address: 0x10003DD4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_020;                                       //  32
    // Address: 0x10003DD8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_ShootingStar;                              //  33
    // Address: 0x10003DDC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StaffRollMgr;                              //  34
    // Address: 0x10003DE0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StaffRollMgrRDash;                         //  35
    // Address: 0x10003DE4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_024;                                       //  36
    // Address: 0x10003DE8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_025;                                       //  37
    // Address: 0x10003DEC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_026;                                       //  38
    // Address: 0x10003DF0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_027;                                       //  39
    // Address: 0x10003DF4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_028;                                       //  40
    // Address: 0x10003DF8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_029;                                       //  41
    // Address: 0x10003DFC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_02A;                                       //  42
    // Address: 0x10003E00
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_02B;                                       //  43
    // Address: 0x10003E04
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_02C;                                       //  44
    // Address: 0x10003E08
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_02D;                                       //  45
    // Address: 0x10003E0C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_02E;                                       //  46
    // Address: 0x10003E10
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_02F;                                       //  47
    // Address: 0x10003E14
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_030;                                       //  48
    // Address: 0x10003E18
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_031;                                       //  49
    // Address: 0x10003E1C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_032;                                       //  50
    // Address: 0x10003E20
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_033;                                       //  51
    // Address: 0x10003E24
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_ElasticKinokoParent;                       //  52
    // Address: 0x10003E28
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FloorGyration;                             //  53
    // Address: 0x10003E2C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_036;                                       //  54
    // Address: 0x10003E30
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_037;                                       //  55
    // Address: 0x10003E34
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_038;                                       //  56
    // Address: 0x10003E38
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_039;                                       //  57
    // Address: 0x10003E3C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_03A;                                       //  58
    // Address: 0x10003E40
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_03B;                                       //  59
    // Address: 0x10003E44
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PairObjChild;                              //  60
    // Address: 0x10003E48
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_03D;                                       //  61
    // Address: 0x10003E4C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_03E;                                       //  62
    // Address: 0x10003E50
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_03F;                                       //  63
    // Address: 0x10003E54
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_040;                                       //  64
    // Address: 0x10003E58
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_041;                                       //  65
    // Address: 0x10003E5C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_042;                                       //  66
    // Address: 0x10003E60
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_043;                                       //  67
    // Address: 0x10003E64
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_044;                                       //  68
    // Address: 0x10003E68
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_045;                                       //  69
    // Address: 0x10003E6C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_046;                                       //  70
    // Address: 0x10003E70
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_047;                                       //  71
    // Address: 0x10003E74
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_048;                                       //  72
    // Address: 0x10003E78
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_049;                                       //  73
    // Address: 0x10003E7C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_04A;                                       //  74
    // Address: 0x10003E80
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_04B;                                       //  75
    // Address: 0x10003E84
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_04C;                                       //  76
    // Address: 0x10003E88
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KinokoLift;                                //  77
    // Address: 0x10003E8C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KinokoLiftColor;                           //  78
    // Address: 0x10003E90
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_LiftZenStar;                               //  79
    // Address: 0x10003E94
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_050;                                       //  80
    // Address: 0x10003E98
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_051;                                       //  81
    // Address: 0x10003E9C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_052;                                       //  82
    // Address: 0x10003EA0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_053;                                       //  83
    // Address: 0x10003EA4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_054;                                       //  84
    // Address: 0x10003EA8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_055;                                       //  85
    // Address: 0x10003EAC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_056;                                       //  86
    // Address: 0x10003EB0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_057;                                       //  87
    // Address: 0x10003EB4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_058;                                       //  88
    // Address: 0x10003EB8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_059;                                       //  89
    // Address: 0x10003EBC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BgActorYukaMario;                          //  90
    // Address: 0x10003EC0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_05B;                                       //  91
    // Address: 0x10003EC4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_05C;                                       //  92
    // Address: 0x10003EC8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_05D;                                       //  93
    // Address: 0x10003ECC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_05E;                                       //  94
    // Address: 0x10003ED0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_05F;                                       //  95
    // Address: 0x10003ED4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_060;                                       //  96
    // Address: 0x10003ED8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_061;                                       //  97
    // Address: 0x10003EDC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_062;                                       //  98
    // Address: 0x10003EE0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_063;                                       //  99
    // Address: 0x10003EE4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_064;                                       // 100
    // Address: 0x10003EE8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KillerHoudai;                              // 101
    // Address: 0x10003EEC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StretchKillerHoudai;                       // 102
    // Address: 0x10003EF0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MagnumKillerHoudai;                        // 103
    // Address: 0x10003EF4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MagnumKillerHoudaiDown;                    // 104
    // Address: 0x10003EF8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SearchKillerHoudai;                        // 105
    // Address: 0x10003EFC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SearchMagnumKillerHoudai;                  // 106
    // Address: 0x10003F00
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SearchMagnumKillerHoudaiDown;              // 107
    // Address: 0x10003F04
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MagnumKillerHoudaiRDash;                   // 108
    // Address: 0x10003F08
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MagnumKillerHoudaiDownRDash;               // 109
    // Address: 0x10003F0C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SearchMagnumKillerHoudaiRDash;             // 110
    // Address: 0x10003F10
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SearchMagnumKillerHoudaiDownRDash;         // 111
    // Address: 0x10003F14
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_070;                                       // 112
    // Address: 0x10003F18
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_071;                                       // 113
    // Address: 0x10003F1C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_072;                                       // 114
    // Address: 0x10003F20
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_073;                                       // 115
    // Address: 0x10003F24
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_074;                                       // 116
    // Address: 0x10003F28
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_075;                                       // 117
    // Address: 0x10003F2C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_076;                                       // 118
    // Address: 0x10003F30
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_077;                                       // 119
    // Address: 0x10003F34
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_078;                                       // 120
    // Address: 0x10003F38
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Intermittent;                              // 121
    // Address: 0x10003F3C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_IntermittentPermanent;                     // 122
    // Address: 0x10003F40
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_WaterIntermittent;                         // 123
    // Address: 0x10003F44
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_WaterIntermittentPermanent;                // 124
    // Address: 0x10003F48
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_WaterIntermittentPermanentRD3_3;           // 125
    // Address: 0x10003F4C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_07E;                                       // 126
    // Address: 0x10003F50
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_WaterIntermittentBossChild;                // 127
    // Address: 0x10003F54
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_YoganIntermittent;                         // 128
    // Address: 0x10003F58
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_081;                                       // 129
    // Address: 0x10003F5C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_082;                                       // 130
    // Address: 0x10003F60
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_083;                                       // 131
    // Address: 0x10003F64
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_084;                                       // 132
    // Address: 0x10003F68
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_085;                                       // 133
    // Address: 0x10003F6C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_ObjPipeDownNG;                             // 134
    // Address: 0x10003F70
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_087;                                       // 135
    // Address: 0x10003F74
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_088;                                       // 136
    // Address: 0x10003F78
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_089;                                       // 137
    // Address: 0x10003F7C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_08A;                                       // 138
    // Address: 0x10003F80
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_08B;                                       // 139
    // Address: 0x10003F84
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_08C;                                       // 140
    // Address: 0x10003F88
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_08D;                                       // 141
    // Address: 0x10003F8C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_08E;                                       // 142
    // Address: 0x10003F90
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_08F;                                       // 143
    // Address: 0x10003F94
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_090;                                       // 144
    // Address: 0x10003F98
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_091;                                       // 145
    // Address: 0x10003F9C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_092;                                       // 146
    // Address: 0x10003FA0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_093;                                       // 147
    // Address: 0x10003FA4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_094;                                       // 148
    // Address: 0x10003FA8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_095;                                       // 149
    // Address: 0x10003FAC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_096;                                       // 150
    // Address: 0x10003FB0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_097;                                       // 151
    // Address: 0x10003FB4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_098;                                       // 152
    // Address: 0x10003FB8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_099;                                       // 153
    // Address: 0x10003FBC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_09A;                                       // 154
    // Address: 0x10003FC0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_09B;                                       // 155
    // Address: 0x10003FC4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_09C;                                       // 156
    // Address: 0x10003FC8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_09D;                                       // 157
    // Address: 0x10003FCC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_09E;                                       // 158
    // Address: 0x10003FD0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_09F;                                       // 159
    // Address: 0x10003FD4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0A0;                                       // 160
    // Address: 0x10003FD8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0A1;                                       // 161
    // Address: 0x10003FDC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0A2;                                       // 162
    // Address: 0x10003FE0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0A3;                                       // 163
    // Address: 0x10003FE4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0A4;                                       // 164
    // Address: 0x10003FE8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0A5;                                       // 165
    // Address: 0x10003FEC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0A6;                                       // 166
    // Address: 0x10003FF0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0A7;                                       // 167
    // Address: 0x10003FF4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0A8;                                       // 168
    // Address: 0x10003FF8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0A9;                                       // 169
    // Address: 0x10003FFC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0AA;                                       // 170
    // Address: 0x10004000
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0AB;                                       // 171
    // Address: 0x10004004
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0AC;                                       // 172
    // Address: 0x10004008
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0AD;                                       // 173
    // Address: 0x1000400C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0AE;                                       // 174
    // Address: 0x10004010
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0AF;                                       // 175
    // Address: 0x10004014
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0B0;                                       // 176
    // Address: 0x10004018
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0B1;                                       // 177
    // Address: 0x1000401C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0B2;                                       // 178
    // Address: 0x10004020
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0B3;                                       // 179
    // Address: 0x10004024
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0B4;                                       // 180
    // Address: 0x10004028
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0B5;                                       // 181
    // Address: 0x1000402C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0B6;                                       // 182
    // Address: 0x10004030
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0B7;                                       // 183
    // Address: 0x10004034
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_LineSpinLift;                              // 184
    // Address: 0x10004038
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_LineSpinLiftParentRDash;                   // 185
    // Address: 0x1000403C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_LineSpinLiftChildRDash;                    // 186
    // Address: 0x10004040
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0BB;                                       // 187
    // Address: 0x10004044
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0BC;                                       // 188
    // Address: 0x10004048
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0BD;                                       // 189
    // Address: 0x1000404C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0BE;                                       // 190
    // Address: 0x10004050
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0BF;                                       // 191
    // Address: 0x10004054
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0C0;                                       // 192
    // Address: 0x10004058
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0C1;                                       // 193
    // Address: 0x1000405C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SnakeBlock;                                // 194
    // Address: 0x10004060
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0C3;                                       // 195
    // Address: 0x10004064
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0C4;                                       // 196
    // Address: 0x10004068
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0C5;                                       // 197
    // Address: 0x1000406C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0C6;                                       // 198
    // Address: 0x10004070
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0C7;                                       // 199
    // Address: 0x10004074
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0C8;                                       // 200
    // Address: 0x10004078
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0C9;                                       // 201
    // Address: 0x1000407C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0CA;                                       // 202
    // Address: 0x10004080
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0CB;                                       // 203
    // Address: 0x10004084
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0CC;                                       // 204
    // Address: 0x10004088
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0CD;                                       // 205
    // Address: 0x1000408C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0CE;                                       // 206
    // Address: 0x10004090
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0CF;                                       // 207
    // Address: 0x10004094
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0D0;                                       // 208
    // Address: 0x10004098
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0D1;                                       // 209
    // Address: 0x1000409C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FloorHoleDokan;                            // 210
    // Address: 0x100040A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0D3;                                       // 211
    // Address: 0x100040A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0D4;                                       // 212
    // Address: 0x100040A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0D5;                                       // 213
    // Address: 0x100040AC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0D6;                                       // 214
    // Address: 0x100040B0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0D7;                                       // 215
    // Address: 0x100040B4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0D8;                                       // 216
    // Address: 0x100040B8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0D9;                                       // 217
    // Address: 0x100040BC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0DA;                                       // 218
    // Address: 0x100040C0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0DB;                                       // 219
    // Address: 0x100040C4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0DC;                                       // 220
    // Address: 0x100040C8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0DD;                                       // 221
    // Address: 0x100040CC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Maruta;                                    // 222
    // Address: 0x100040D0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0DF;                                       // 223
    // Address: 0x100040D4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Burner;                                    // 224
    // Address: 0x100040D8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0E1;                                       // 225
    // Address: 0x100040DC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0E2;                                       // 226
    // Address: 0x100040E0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0E3;                                       // 227
    // Address: 0x100040E4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0E4;                                       // 228
    // Address: 0x100040E8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0E5;                                       // 229
    // Address: 0x100040EC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0E6;                                       // 230
    // Address: 0x100040F0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0E7;                                       // 231
    // Address: 0x100040F4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0E8;                                       // 232
    // Address: 0x100040F8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0E9;                                       // 233
    // Address: 0x100040FC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0EA;                                       // 234
    // Address: 0x10004100
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0EB;                                       // 235
    // Address: 0x10004104
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0EC;                                       // 236
    // Address: 0x10004108
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PlyIce;                                    // 237
    // Address: 0x1000410C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_TarzanIvy;                                 // 238
    // Address: 0x10004110
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0EF;                                       // 239
    // Address: 0x10004114
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0F0;                                       // 240
    // Address: 0x10004118
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0F1;                                       // 241
    // Address: 0x1000411C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0F2;                                       // 242
    // Address: 0x10004120
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0F3;                                       // 243
    // Address: 0x10004124
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0F4;                                       // 244
    // Address: 0x10004128
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0F5;                                       // 245
    // Address: 0x1000412C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0F6;                                       // 246
    // Address: 0x10004130
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0F7;                                       // 247
    // Address: 0x10004134
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0F8;                                       // 248
    // Address: 0x10004138
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0F9;                                       // 249
    // Address: 0x1000413C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0FA;                                       // 250
    // Address: 0x10004140
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0FB;                                       // 251
    // Address: 0x10004144
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0FC;                                       // 252
    // Address: 0x10004148
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0FD;                                       // 253
    // Address: 0x1000414C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0FE;                                       // 254
    // Address: 0x10004150
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0FF;                                       // 255
    // Address: 0x10004154
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_100;                                       // 256
    // Address: 0x10004158
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_101;                                       // 257
    // Address: 0x1000415C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_102;                                       // 258
    // Address: 0x10004160
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_103;                                       // 259
    // Address: 0x10004164
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_104;                                       // 260
    // Address: 0x10004168
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_ShuffleBlock;                              // 261
    // Address: 0x1000416C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KokoopaShipWarpCannon;                     // 262
    // Address: 0x10004170
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_107;                                       // 263
    // Address: 0x10004174
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_108;                                       // 264
    // Address: 0x10004178
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KoopaShutter;                              // 265
    // Address: 0x1000417C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_10A;                                       // 266
    // Address: 0x10004180
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_10B;                                       // 267
    // Address: 0x10004184
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_10C;                                       // 268
    // Address: 0x10004188
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PeachFinalCastleKoopaJrLift;               // 269
    // Address: 0x1000418C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PeachFinalCastleKoopaJrLiftHmove;          // 270
    // Address: 0x10004190
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PeachFinalCastleKoopaJrLiftPairObj;        // 271
    // Address: 0x10004194
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_RoyLiftWakiStep;                           // 272
    // Address: 0x10004198
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_WendyFloor;                                // 273
    // Address: 0x1000419C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_IggyRoom;                                  // 274
    // Address: 0x100041A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_113;                                       // 275
    // Address: 0x100041A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_114;                                       // 276
    // Address: 0x100041A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_115;                                       // 277
    // Address: 0x100041AC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_116;                                       // 278
    // Address: 0x100041B0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_117;                                       // 279
    // Address: 0x100041B4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_118;                                       // 280
    // Address: 0x100041B8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_119;                                       // 281
    // Address: 0x100041BC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_11A;                                       // 282
    // Address: 0x100041C0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_11B;                                       // 283
    // Address: 0x100041C4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_11C;                                       // 284
    // Address: 0x100041C8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_11D;                                       // 285
    // Address: 0x100041CC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_11E;                                       // 286
    // Address: 0x100041D0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Block;                                     // 287
    // Address: 0x100041D4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_120;                                       // 288
    // Address: 0x100041D8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_121;                                       // 289
    // Address: 0x100041DC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_122;                                       // 290
    // Address: 0x100041E0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_ActorBlockRenga;                           // 291
    // Address: 0x100041E4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_124;                                       // 292
    // Address: 0x100041E8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_125;                                       // 293
    // Address: 0x100041EC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_126;                                       // 294
    // Address: 0x100041F0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_127;                                       // 295
    // Address: 0x100041F4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_128;                                       // 296
    // Address: 0x100041F8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_129;                                       // 297
    // Address: 0x100041FC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_12A;                                       // 298
    // Address: 0x10004200
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_12B;                                       // 299
    // Address: 0x10004204
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_12C;                                       // 300
    // Address: 0x10004208
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_12D;                                       // 301
    // Address: 0x1000420C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_12E;                                       // 302
    // Address: 0x10004210
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_12F;                                       // 303
    // Address: 0x10004214
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_130;                                       // 304
    // Address: 0x10004218
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_131;                                       // 305
    // Address: 0x1000421C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_132;                                       // 306
    // Address: 0x10004220
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_133;                                       // 307
    // Address: 0x10004224
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_134;                                       // 308
    // Address: 0x10004228
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_ActorBlockMakeDRC;                         // 309
    // Address: 0x1000422C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_136;                                       // 310
    // Address: 0x10004230
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_137;                                       // 311
    // Address: 0x10004234
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_138;                                       // 312
    // Address: 0x10004238
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_139;                                       // 313
    // Address: 0x1000423C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_13A;                                       // 314
    // Address: 0x10004240
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_13B;                                       // 315
    // Address: 0x10004244
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_13C;                                       // 316
    // Address: 0x10004248
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_13D;                                       // 317
    // Address: 0x1000424C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_13E;                                       // 318
    // Address: 0x10004250
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_13F;                                       // 319
    // Address: 0x10004254
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_140;                                       // 320
    // Address: 0x10004258
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_141;                                       // 321
    // Address: 0x1000425C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_142;                                       // 322
    // Address: 0x10004260
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_143;                                       // 323
    // Address: 0x10004264
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_144;                                       // 324
    // Address: 0x10004268
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_145;                                       // 325
    // Address: 0x1000426C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_146;                                       // 326
    // Address: 0x10004270
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_147;                                       // 327
    // Address: 0x10004274
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_148;                                       // 328
    // Address: 0x10004278
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_149;                                       // 329
    // Address: 0x1000427C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_14A;                                       // 330
    // Address: 0x10004280
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_14B;                                       // 331
    // Address: 0x10004284
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_14C;                                       // 332
    // Address: 0x10004288
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_14D;                                       // 333
    // Address: 0x1000428C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_14E;                                       // 334
    // Address: 0x10004290
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_14F;                                       // 335
    // Address: 0x10004294
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_ObjPipeDown;                               // 336
    // Address: 0x10004298
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_151;                                       // 337
    // Address: 0x1000429C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_152;                                       // 338
    // Address: 0x100042A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_153;                                       // 339
    // Address: 0x100042A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_ObjPipeDownGroup;                          // 340
    // Address: 0x100042A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_155;                                       // 341
    // Address: 0x100042AC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_156;                                       // 342
    // Address: 0x100042B0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_157;                                       // 343
    // Address: 0x100042B4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SwitchHatenaButton;                        // 344
    // Address: 0x100042B8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SwitchPbutton;                             // 345
    // Address: 0x100042BC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SwitchPbuttonRDash;                        // 346
    // Address: 0x100042C0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SwitchPbuttonNoWallKick;                   // 347
    // Address: 0x100042C4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_15C;                                       // 348
    // Address: 0x100042C8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_15D;                                       // 349
    // Address: 0x100042CC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_IcicleBig;                                 // 350
    // Address: 0x100042D0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_LemmyBall;                                 // 351
    // Address: 0x100042D4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_LemmyBomb;                                 // 352
    // Address: 0x100042D8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_161;                                       // 353
    // Address: 0x100042DC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_162;                                       // 354
    // Address: 0x100042E0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_163;                                       // 355
    // Address: 0x100042E4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_164;                                       // 356
    // Address: 0x100042E8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_165;                                       // 357
    // Address: 0x100042EC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_166;                                       // 358
    // Address: 0x100042F0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_167;                                       // 359
    // Address: 0x100042F4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_168;                                       // 360
    // Address: 0x100042F8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_169;                                       // 361
    // Address: 0x100042FC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PentaroIce;                                // 362
    // Address: 0x10004300
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_16B;                                       // 363
    // Address: 0x10004304
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_16C;                                       // 364
    // Address: 0x10004308
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_16D;                                       // 365
    // Address: 0x1000430C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_16E;                                       // 366
    // Address: 0x10004310
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_16F;                                       // 367
    // Address: 0x10004314
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KameckIce;                                 // 368
    // Address: 0x10004318
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_WendyIcicle;                               // 369
    // Address: 0x1000431C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PeachFinalCastleKoopaJrClown;              // 370
    // Address: 0x10004320
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BoxingKoopaJrClown;                        // 371
    // Address: 0x10004324
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_174;                                       // 372
    // Address: 0x10004328
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FinalKoopaJrClown;                         // 373
    // Address: 0x1000432C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FinalKoopa;                                // 374
    // Address: 0x10004330
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FireBar;                                   // 375
    // Address: 0x10004334
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FireBarSync;                               // 376
    // Address: 0x10004338
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_179;                                       // 377
    // Address: 0x1000433C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_17A;                                       // 378
    // Address: 0x10004340
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_17B;                                       // 379
    // Address: 0x10004344
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_17C;                                       // 380
    // Address: 0x10004348
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_17D;                                       // 381
    // Address: 0x1000434C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_17E;                                       // 382
    // Address: 0x10004350
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_17F;                                       // 383
    // Address: 0x10004354
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_180;                                       // 384
    // Address: 0x10004358
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_181;                                       // 385
    // Address: 0x1000435C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_182;                                       // 386
    // Address: 0x10004360
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_183;                                       // 387
    // Address: 0x10004364
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_184;                                       // 388
    // Address: 0x10004368
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_185;                                       // 389
    // Address: 0x1000436C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_186;                                       // 390
    // Address: 0x10004370
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_187;                                       // 391
    // Address: 0x10004374
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_188;                                       // 392
    // Address: 0x10004378
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_189;                                       // 393
    // Address: 0x1000437C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_18A;                                       // 394
    // Address: 0x10004380
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_ActorCoin;                                 // 395
    // Address: 0x10004384
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_18C;                                       // 396
    // Address: 0x10004388
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_18D;                                       // 397
    // Address: 0x1000438C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_18E;                                       // 398
    // Address: 0x10004390
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_18F;                                       // 399
    // Address: 0x10004394
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_190;                                       // 400
    // Address: 0x10004398
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_191;                                       // 401
    // Address: 0x1000439C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_192;                                       // 402
    // Address: 0x100043A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_193;                                       // 403
    // Address: 0x100043A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_194;                                       // 404
    // Address: 0x100043A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_195;                                       // 405
    // Address: 0x100043AC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_196;                                       // 406
    // Address: 0x100043B0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_197;                                       // 407
    // Address: 0x100043B4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_198;                                       // 408
    // Address: 0x100043B8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_199;                                       // 409
    // Address: 0x100043BC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_19A;                                       // 410
    // Address: 0x100043C0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_19B;                                       // 411
    // Address: 0x100043C4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_19C;                                       // 412
    // Address: 0x100043C8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_19D;                                       // 413
    // Address: 0x100043CC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_19E;                                       // 414
    // Address: 0x100043D0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_19F;                                       // 415
    // Address: 0x100043D4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1A0;                                       // 416
    // Address: 0x100043D8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1A1;                                       // 417
    // Address: 0x100043DC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1A2;                                       // 418
    // Address: 0x100043E0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1A3;                                       // 419
    // Address: 0x100043E4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1A4;                                       // 420
    // Address: 0x100043E8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1A5;                                       // 421
    // Address: 0x100043EC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1A6;                                       // 422
    // Address: 0x100043F0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1A7;                                       // 423
    // Address: 0x100043F4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1A8;                                       // 424
    // Address: 0x100043F8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BlueCoin;                                  // 425
    // Address: 0x100043FC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1AA;                                       // 426
    // Address: 0x10004400
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1AB;                                       // 427
    // Address: 0x10004404
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1AC;                                       // 428
    // Address: 0x10004408
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1AD;                                       // 429
    // Address: 0x1000440C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1AE;                                       // 430
    // Address: 0x10004410
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1AF;                                       // 431
    // Address: 0x10004414
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1B0;                                       // 432
    // Address: 0x10004418
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1B1;                                       // 433
    // Address: 0x1000441C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1B2;                                       // 434
    // Address: 0x10004420
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1B3;                                       // 435
    // Address: 0x10004424
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1B4;                                       // 436
    // Address: 0x10004428
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1B5;                                       // 437
    // Address: 0x1000442C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CoinmakiCoin;                              // 438
    // Address: 0x10004430
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1B7;                                       // 439
    // Address: 0x10004434
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1B8;                                       // 440
    // Address: 0x10004438
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1B9;                                       // 441
    // Address: 0x1000443C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Yoshi;                                     // 442
    // Address: 0x10004440
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_TottenPlayer;                              // 443
    // Address: 0x10004444
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PlayerObject;                              // 444
    // Address: 0x10004448
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1BD;                                       // 445
    // Address: 0x1000444C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1BE;                                       // 446
    // Address: 0x10004450
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1BF;                                       // 447
    // Address: 0x10004454
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1C0;                                       // 448
    // Address: 0x10004458
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1C1;                                       // 449
    // Address: 0x1000445C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1C2;                                       // 450
    // Address: 0x10004460
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1C3;                                       // 451
    // Address: 0x10004464
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1C4;                                       // 452
    // Address: 0x10004468
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SlotYoshiChibi;                            // 453
    // Address: 0x1000446C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1C6;                                       // 454
    // Address: 0x10004470
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1C7;                                       // 455
    // Address: 0x10004474
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1C8;                                       // 456
    // Address: 0x10004478
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1C9;                                       // 457
    // Address: 0x1000447C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1CA;                                       // 458
    // Address: 0x10004480
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1CB;                                       // 459
    // Address: 0x10004484
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1CC;                                       // 460
    // Address: 0x10004488
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1CD;                                       // 461
    // Address: 0x1000448C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1CE;                                       // 462
    // Address: 0x10004490
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_QuestPrizeItem;                            // 463
    // Address: 0x10004494
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1D0;                                       // 464
    // Address: 0x10004498
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1D1;                                       // 465
    // Address: 0x1000449C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1D2;                                       // 466
    // Address: 0x100044A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Kuribo;                                    // 467
    // Address: 0x100044A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Kakibo;                                    // 468
    // Address: 0x100044A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PataKuribo;                                // 469
    // Address: 0x100044AC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1D6;                                       // 470
    // Address: 0x100044B0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1D7;                                       // 471
    // Address: 0x100044B4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1D8;                                       // 472
    // Address: 0x100044B8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1D9;                                       // 473
    // Address: 0x100044BC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_IceBall;                                   // 474
    // Address: 0x100044C0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_IceBallPakkun;                             // 475
    // Address: 0x100044C4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FireBallPlayer;                            // 476
    // Address: 0x100044C8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FireBallPakkun;                            // 477
    // Address: 0x100044CC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_YoshiFire;                                 // 478
    // Address: 0x100044D0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1DF;                                       // 479
    // Address: 0x100044D4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1E0;                                       // 480
    // Address: 0x100044D8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1E1;                                       // 481
    // Address: 0x100044DC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1E2;                                       // 482
    // Address: 0x100044E0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1E3;                                       // 483
    // Address: 0x100044E4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1E4;                                       // 484
    // Address: 0x100044E8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1E5;                                       // 485
    // Address: 0x100044EC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1E6;                                       // 486
    // Address: 0x100044F0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1E7;                                       // 487
    // Address: 0x100044F4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1E8;                                       // 488
    // Address: 0x100044F8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1E9;                                       // 489
    // Address: 0x100044FC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1EA;                                       // 490
    // Address: 0x10004500
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1EB;                                       // 491
    // Address: 0x10004504
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1EC;                                       // 492
    // Address: 0x10004508
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1ED;                                       // 493
    // Address: 0x1000450C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1EE;                                       // 494
    // Address: 0x10004510
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1EF;                                       // 495
    // Address: 0x10004514
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1F0;                                       // 496
    // Address: 0x10004518
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1F1;                                       // 497
    // Address: 0x1000451C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1F2;                                       // 498
    // Address: 0x10004520
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1F3;                                       // 499
    // Address: 0x10004524
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1F4;                                       // 500
    // Address: 0x10004528
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1F5;                                       // 501
    // Address: 0x1000452C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1F6;                                       // 502
    // Address: 0x10004530
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1F7;                                       // 503
    // Address: 0x10004534
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1F8;                                       // 504
    // Address: 0x10004538
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1F9;                                       // 505
    // Address: 0x1000453C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1FA;                                       // 506
    // Address: 0x10004540
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1FB;                                       // 507
    // Address: 0x10004544
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1FC;                                       // 508
    // Address: 0x10004548
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1FD;                                       // 509
    // Address: 0x1000454C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1FE;                                       // 510
    // Address: 0x10004550
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1FF;                                       // 511
    // Address: 0x10004554
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Nokonoko;                                  // 512
    // Address: 0x10004558
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_201;                                       // 513
    // Address: 0x1000455C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_202;                                       // 514
    // Address: 0x10004560
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_203;                                       // 515
    // Address: 0x10004564
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_204;                                       // 516
    // Address: 0x10004568
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_205;                                       // 517
    // Address: 0x1000456C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_206;                                       // 518
    // Address: 0x10004570
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_207;                                       // 519
    // Address: 0x10004574
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_208;                                       // 520
    // Address: 0x10004578
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_209;                                       // 521
    // Address: 0x1000457C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_20A;                                       // 522
    // Address: 0x10004580
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_20B;                                       // 523
    // Address: 0x10004584
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MechaKoopa;                                // 524
    // Address: 0x10004588
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_20D;                                       // 525
    // Address: 0x1000458C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_20E;                                       // 526
    // Address: 0x10004590
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_20F;                                       // 527
    // Address: 0x10004594
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_210;                                       // 528
    // Address: 0x10004598
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_211;                                       // 529
    // Address: 0x1000459C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_212;                                       // 530
    // Address: 0x100045A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_213;                                       // 531
    // Address: 0x100045A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_214;                                       // 532
    // Address: 0x100045A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_215;                                       // 533
    // Address: 0x100045AC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_216;                                       // 534
    // Address: 0x100045B0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_217;                                       // 535
    // Address: 0x100045B4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_218;                                       // 536
    // Address: 0x100045B8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_219;                                       // 537
    // Address: 0x100045BC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_21A;                                       // 538
    // Address: 0x100045C0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_21B;                                       // 539
    // Address: 0x100045C4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_21C;                                       // 540
    // Address: 0x100045C8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_21D;                                       // 541
    // Address: 0x100045CC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_21E;                                       // 542
    // Address: 0x100045D0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_21F;                                       // 543
    // Address: 0x100045D4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_220;                                       // 544
    // Address: 0x100045D8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_221;                                       // 545
    // Address: 0x100045DC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_222;                                       // 546
    // Address: 0x100045E0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_223;                                       // 547
    // Address: 0x100045E4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_224;                                       // 548
    // Address: 0x100045E8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_225;                                       // 549
    // Address: 0x100045EC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_226;                                       // 550
    // Address: 0x100045F0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_227;                                       // 551
    // Address: 0x100045F4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_228;                                       // 552
    // Address: 0x100045F8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_229;                                       // 553
    // Address: 0x100045FC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_22A;                                       // 554
    // Address: 0x10004600
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_22B;                                       // 555
    // Address: 0x10004604
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_22C;                                       // 556
    // Address: 0x10004608
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_22D;                                       // 557
    // Address: 0x1000460C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FireBallKeronpa;                           // 558
    // Address: 0x10004610
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FireBallKeronpaRDash;                      // 559
    // Address: 0x10004614
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_230;                                       // 560
    // Address: 0x10004618
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FireSnake;                                 // 561
    // Address: 0x1000461C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_232;                                       // 562
    // Address: 0x10004620
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_233;                                       // 563
    // Address: 0x10004624
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_234;                                       // 564
    // Address: 0x10004628
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_235;                                       // 565
    // Address: 0x1000462C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_236;                                       // 566
    // Address: 0x10004630
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_237;                                       // 567
    // Address: 0x10004634
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_238;                                       // 568
    // Address: 0x10004638
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_239;                                       // 569
    // Address: 0x1000463C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_23A;                                       // 570
    // Address: 0x10004640
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_23B;                                       // 571
    // Address: 0x10004644
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_23C;                                       // 572
    // Address: 0x10004648
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_23D;                                       // 573
    // Address: 0x1000464C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Kazandan;                                  // 574
    // Address: 0x10004650
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_23F;                                       // 575
    // Address: 0x10004654
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_240;                                       // 576
    // Address: 0x10004658
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_241;                                       // 577
    // Address: 0x1000465C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_242;                                       // 578
    // Address: 0x10004660
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_243;                                       // 579
    // Address: 0x10004664
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_244;                                       // 580
    // Address: 0x10004668
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_245;                                       // 581
    // Address: 0x1000466C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_246;                                       // 582
    // Address: 0x10004670
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_247;                                       // 583
    // Address: 0x10004674
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_248;                                       // 584
    // Address: 0x10004678
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_249;                                       // 585
    // Address: 0x1000467C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_24A;                                       // 586
    // Address: 0x10004680
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BgCenter;                                  // 587
    // Address: 0x10004684
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_24C;                                       // 588
    // Address: 0x10004688
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_24D;                                       // 589
    // Address: 0x1000468C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_24E;                                       // 590
    // Address: 0x10004690
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Kinoko;                                    // 591
    // Address: 0x10004694
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FireFlower;                                // 592
    // Address: 0x10004698
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MameKinoko;                                // 593
    // Address: 0x1000469C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_IceFlower;                                 // 594
    // Address: 0x100046A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Propeller;                                 // 595
    // Address: 0x100046A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Penguin;                                   // 596
    // Address: 0x100046A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_OneUpKinoko;                               // 597
    // Address: 0x100046AC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Musasabi;                                  // 598
    // Address: 0x100046B0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SuperMoon;                                 // 599
    // Address: 0x100046B4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_TitleDemoItem;                             // 600
    // Address: 0x100046B8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_259;                                       // 601
    // Address: 0x100046BC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_25A;                                       // 602
    // Address: 0x100046C0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_25B;                                       // 603
    // Address: 0x100046C4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_25C;                                       // 604
    // Address: 0x100046C8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_25D;                                       // 605
    // Address: 0x100046CC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_25E;                                       // 606
    // Address: 0x100046D0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_25F;                                       // 607
    // Address: 0x100046D4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_260;                                       // 608
    // Address: 0x100046D8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_261;                                       // 609
    // Address: 0x100046DC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_262;                                       // 610
    // Address: 0x100046E0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_263;                                       // 611
    // Address: 0x100046E4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_264;                                       // 612
    // Address: 0x100046E8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_265;                                       // 613
    // Address: 0x100046EC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_266;                                       // 614
    // Address: 0x100046F0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_267;                                       // 615
    // Address: 0x100046F4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_268;                                       // 616
    // Address: 0x100046F8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Spanner;                                   // 617
    // Address: 0x100046FC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_26A;                                       // 618
    // Address: 0x10004700
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_26B;                                       // 619
    // Address: 0x10004704
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_26C;                                       // 620
    // Address: 0x10004708
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_26D;                                       // 621
    // Address: 0x1000470C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_26E;                                       // 622
    // Address: 0x10004710
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_26F;                                       // 623
    // Address: 0x10004714
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_270;                                       // 624
    // Address: 0x10004718
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_271;                                       // 625
    // Address: 0x1000471C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_272;                                       // 626
    // Address: 0x10004720
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_273;                                       // 627
    // Address: 0x10004724
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_274;                                       // 628
    // Address: 0x10004728
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_275;                                       // 629
    // Address: 0x1000472C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SearchKiller;                              // 630
    // Address: 0x10004730
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_277;                                       // 631
    // Address: 0x10004734
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_278;                                       // 632
    // Address: 0x10004738
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_279;                                       // 633
    // Address: 0x1000473C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_WakiSearchMagKiller;                       // 634
    // Address: 0x10004740
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_27B;                                       // 635
    // Address: 0x10004744
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_27C;                                       // 636
    // Address: 0x10004748
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_27D;                                       // 637
    // Address: 0x1000474C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_27E;                                       // 638
    // Address: 0x10004750
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_27F;                                       // 639
    // Address: 0x10004754
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_GabonRock;                                 // 640
    // Address: 0x10004758
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_281;                                       // 641
    // Address: 0x1000475C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_282;                                       // 642
    // Address: 0x10004760
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_RockGabonRock;                             // 643
    // Address: 0x10004764
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_284;                                       // 644
    // Address: 0x10004768
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SeichanSnowBall;                           // 645
    // Address: 0x1000476C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_286;                                       // 646
    // Address: 0x10004770
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_287;                                       // 647
    // Address: 0x10004774
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_288;                                       // 648
    // Address: 0x10004778
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_289;                                       // 649
    // Address: 0x1000477C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Woochan;                                   // 650
    // Address: 0x10004780
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_28B;                                       // 651
    // Address: 0x10004784
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_28C;                                       // 652
    // Address: 0x10004788
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_28D;                                       // 653
    // Address: 0x1000478C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Bubble;                                    // 654
    // Address: 0x10004790
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BubbleSync;                                // 655
    // Address: 0x10004794
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BubbleRDash;                               // 656
    // Address: 0x10004798
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BubbleSyncRDash;                           // 657
    // Address: 0x1000479C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_292;                                       // 658
    // Address: 0x100047A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_293;                                       // 659
    // Address: 0x100047A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_294;                                       // 660
    // Address: 0x100047A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_295;                                       // 661
    // Address: 0x100047AC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_296;                                       // 662
    // Address: 0x100047B0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_297;                                       // 663
    // Address: 0x100047B4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_298;                                       // 664
    // Address: 0x100047B8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_299;                                       // 665
    // Address: 0x100047BC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_29A;                                       // 666
    // Address: 0x100047C0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_29B;                                       // 667
    // Address: 0x100047C4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_29C;                                       // 668
    // Address: 0x100047C8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_29D;                                       // 669
    // Address: 0x100047CC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_29E;                                       // 670
    // Address: 0x100047D0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_29F;                                       // 671
    // Address: 0x100047D4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2A0;                                       // 672
    // Address: 0x100047D8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2A1;                                       // 673
    // Address: 0x100047DC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2A2;                                       // 674
    // Address: 0x100047E0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2A3;                                       // 675
    // Address: 0x100047E4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2A4;                                       // 676
    // Address: 0x100047E8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2A5;                                       // 677
    // Address: 0x100047EC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Bun;                                       // 678
    // Address: 0x100047F0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BunW2;                                     // 679
    // Address: 0x100047F4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BunW3;                                     // 680
    // Address: 0x100047F8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BunW4;                                     // 681
    // Address: 0x100047FC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BunW5;                                     // 682
    // Address: 0x10004800
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BunW6;                                     // 683
    // Address: 0x10004804
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BunDemo;                                   // 684
    // Address: 0x10004808
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KokoopaDemo;                               // 685
    // Address: 0x1000480C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KoopaJrDemo;                               // 686
    // Address: 0x10004810
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KameckDemo;                                // 687
    // Address: 0x10004814
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BossKKDemo;                                // 688
    // Address: 0x10004818
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PeachFinalCastleKoopaJrDemo;               // 689
    // Address: 0x1000481C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KoopaDemo;                                 // 690
    // Address: 0x10004820
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FinalKoopaDemo;                            // 691
    // Address: 0x10004824
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PeachDemo;                                 // 692
    // Address: 0x10004828
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Larry;                                     // 693
    // Address: 0x1000482C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KokoopaSearchFire;                         // 694
    // Address: 0x10004830
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Lemmy;                                     // 695
    // Address: 0x10004834
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Morton;                                    // 696
    // Address: 0x10004838
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MortonSanbo;                               // 697
    // Address: 0x1000483C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MortonSanboParts;                          // 698
    // Address: 0x10004840
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Wendy;                                     // 699
    // Address: 0x10004844
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_WendyRing;                                 // 700
    // Address: 0x10004848
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Ludwig;                                    // 701
    // Address: 0x1000484C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_LudwigAlterEgo;                            // 702
    // Address: 0x10004850
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Iggy;                                      // 703
    // Address: 0x10004854
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_IggyMagic;                                 // 704
    // Address: 0x10004858
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Woogan;                                    // 705
    // Address: 0x1000485C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Roy;                                       // 706
    // Address: 0x10004860
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_RoyLiftWaki;                               // 707
    // Address: 0x10004864
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BossKK;                                    // 708
    // Address: 0x10004868
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BossKKThunder;                             // 709
    // Address: 0x1000486C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Kameck;                                    // 710
    // Address: 0x10004870
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KameckIceConfig;                           // 711
    // Address: 0x10004874
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KameckWarpPos;                             // 712
    // Address: 0x10004878
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KameckMagic;                               // 713
    // Address: 0x1000487C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_PeachFinalCastleKoopaJr;                   // 714
    // Address: 0x10004880
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Koopa;                                     // 715
    // Address: 0x10004884
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KoopaFireWaki;                             // 716
    // Address: 0x10004888
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KoopaFire;                                 // 717
    // Address: 0x1000488C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_DemoKoopaJrClown;                          // 718
    // Address: 0x10004890
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_DemoKoopaJr;                               // 719
    // Address: 0x10004894
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BunDemoKameck;                             // 720
    // Address: 0x10004898
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KoopaDemoKameck;                           // 721
    // Address: 0x1000489C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BossKKDemoKameck;                          // 722
    // Address: 0x100048A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BossKKDemoKK;                              // 723
    // Address: 0x100048A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FinalKoopaFire;                            // 724
    // Address: 0x100048A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FinalKoopaJr;                              // 725
    // Address: 0x100048AC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FinalKoopaJrFire;                          // 726
    // Address: 0x100048B0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FinalBomhei;                               // 727
    // Address: 0x100048B4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KokoopaShipLemmy;                          // 728
    // Address: 0x100048B8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KokoopaShipMorton;                         // 729
    // Address: 0x100048BC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KokoopaShipLarry;                          // 730
    // Address: 0x100048C0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KokoopaShipWendy;                          // 731
    // Address: 0x100048C4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KokoopaShipIggy;                           // 732
    // Address: 0x100048C8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KokoopaShipRoy;                            // 733
    // Address: 0x100048CC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KokoopaShipLudwig;                         // 734
    // Address: 0x100048D0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Peach;                                     // 735
    // Address: 0x100048D4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2E0;                                       // 736
    // Address: 0x100048D8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FinalDVPeach;                              // 737
    // Address: 0x100048DC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FinalDVShutter;                            // 738
    // Address: 0x100048E0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2E3;                                       // 739
    // Address: 0x100048E4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2E4;                                       // 740
    // Address: 0x100048E8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2E5;                                       // 741
    // Address: 0x100048EC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2E6;                                       // 742
    // Address: 0x100048F0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2E7;                                       // 743
    // Address: 0x100048F4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2E8;                                       // 744
    // Address: 0x100048F8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2E9;                                       // 745
    // Address: 0x100048FC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2EA;                                       // 746
    // Address: 0x10004900
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2EB;                                       // 747
    // Address: 0x10004904
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2EC;                                       // 748
    // Address: 0x10004908
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2ED;                                       // 749
    // Address: 0x1000490C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2EE;                                       // 750
    // Address: 0x10004910
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2EF;                                       // 751
    // Address: 0x10004914
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2F0;                                       // 752
    // Address: 0x10004918
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2F1;                                       // 753
    // Address: 0x1000491C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2F2;                                       // 754
    // Address: 0x10004920
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2F3;                                       // 755
    // Address: 0x10004924
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2F4;                                       // 756
    // Address: 0x10004928
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2F5;                                       // 757
    // Address: 0x1000492C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Hammer;                                    // 758
    // Address: 0x10004930
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2F7;                                       // 759
    // Address: 0x10004934
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Boomerang;                                 // 760
    // Address: 0x10004938
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2F9;                                       // 761
    // Address: 0x1000493C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_FireBallBros;                              // 762
    // Address: 0x10004940
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2FB;                                       // 763
    // Address: 0x10004944
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_IceBallBros;                               // 764
    // Address: 0x10004948
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2FD;                                       // 765
    // Address: 0x1000494C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MegaHammer;                                // 766
    // Address: 0x10004950
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_2FF;                                       // 767
    // Address: 0x10004954
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_300;                                       // 768
    // Address: 0x10004958
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_301;                                       // 769
    // Address: 0x1000495C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_302;                                       // 770
    // Address: 0x10004960
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_303;                                       // 771
    // Address: 0x10004964
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_304;                                       // 772
    // Address: 0x10004968
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_305;                                       // 773
    // Address: 0x1000496C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_306;                                       // 774
    // Address: 0x10004970
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_307;                                       // 775
    // Address: 0x10004974
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_308;                                       // 776
    // Address: 0x10004978
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_309;                                       // 777
    // Address: 0x1000497C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_30A;                                       // 778
    // Address: 0x10004980
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_30B;                                       // 779
    // Address: 0x10004984
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_30C;                                       // 780
    // Address: 0x10004988
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_30D;                                       // 781
    // Address: 0x1000498C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_30E;                                       // 782
    // Address: 0x10004990
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_30F;                                       // 783
    // Address: 0x10004994
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_310;                                       // 784
    // Address: 0x10004998
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_311;                                       // 785
    // Address: 0x1000499C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_312;                                       // 786
    // Address: 0x100049A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_313;                                       // 787
    // Address: 0x100049A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_314;                                       // 788
    // Address: 0x100049A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_315;                                       // 789
    // Address: 0x100049AC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_316;                                       // 790
    // Address: 0x100049B0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_317;                                       // 791
    // Address: 0x100049B4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_318;                                       // 792
    // Address: 0x100049B8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_319;                                       // 793
    // Address: 0x100049BC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_31A;                                       // 794
    // Address: 0x100049C0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_31B;                                       // 795
    // Address: 0x100049C4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_31C;                                       // 796
    // Address: 0x100049C8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_31D;                                       // 797
    // Address: 0x100049CC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_31E;                                       // 798
    // Address: 0x100049D0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_31F;                                       // 799
    // Address: 0x100049D4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_320;                                       // 800
    // Address: 0x100049D8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_321;                                       // 801
    // Address: 0x100049DC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_322;                                       // 802
    // Address: 0x100049E0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_323;                                       // 803
    // Address: 0x100049E4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_324;                                       // 804
    // Address: 0x100049E8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_325;                                       // 805
    // Address: 0x100049EC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_326;                                       // 806
    // Address: 0x100049F0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_327;                                       // 807
    // Address: 0x100049F4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_328;                                       // 808
    // Address: 0x100049F8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BattleItem;                                // 809
    // Address: 0x100049FC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_32A;                                       // 810
    // Address: 0x10004A00
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_VsBattleItem;                              // 811
    // Address: 0x10004A04
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_32C;                                       // 812
    // Address: 0x10004A08
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_32D;                                       // 813
    // Address: 0x10004A0C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_32E;                                       // 814
    // Address: 0x10004A10
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_32F;                                       // 815
    // Address: 0x10004A14
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_330;                                       // 816
    // Address: 0x10004A18
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_331;                                       // 817
    // Address: 0x10004A1C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KoopaJrFire;                               // 818
    // Address: 0x10004A20
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_KoopaJrBall;                               // 819
    // Address: 0x10004A24
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_UnderwaterKoopaJr;                         // 820
    // Address: 0x10004A28
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_UnderwaterKoopaJrClown;                    // 821
    // Address: 0x10004A2C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_UnderwaterKoopaJrRetreatPos;               // 822
    // Address: 0x10004A30
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BoxingKoopaJr;                             // 823
    // Address: 0x10004A34
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BoxingKoopaJrPostBattleDemo;               // 824
    // Address: 0x10004A38
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_BoxingKoopaJrClownPostBattleDemo;          // 825
    // Address: 0x10004A3C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MiniGamePanelItem;                         // 826
    // Address: 0x10004A40
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_SlotItem;                                  // 827
    // Address: 0x10004A44
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CoinmakiCannon;                            // 828
    // Address: 0x10004A48
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CoinmakiItem;                              // 829
    // Address: 0x10004A4C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_MiniGameKinopio;                           // 830
    // Address: 0x10004A50
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_33F;                                       // 831
    // Address: 0x10004A54
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_340;                                       // 832
    // Address: 0x10004A58
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_341;                                       // 833
    // Address: 0x10004A5C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_342;                                       // 834
    // Address: 0x10004A60
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_343;                                       // 835
    // Address: 0x10004A64
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_344;                                       // 836
    // Address: 0x10004A68
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_345;                                       // 837
    // Address: 0x10004A6C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_346;                                       // 838
    // Address: 0x10004A70
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_347;                                       // 839
    // Address: 0x10004A74
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StaffCreditChibiYoshiABC;                  // 840
    // Address: 0x10004A78
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StaffCreditChibiYoshiBalloon;              // 841
    // Address: 0x10004A7C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StaffCreditChibiYoshiBalloonCheer;         // 842
    // Address: 0x10004A80
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StaffCreditChibiYoshiLight;                // 843
    // Address: 0x10004A84
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StaffCreditChibiYoshiLightCheer;           // 844
    // Address: 0x10004A88
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StaffCreditSoapABC;                        // 845
    // Address: 0x10004A8C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StaffCreditSoapCoin;                       // 846
    // Address: 0x10004A90
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_StaffCreditTottenKun;                      // 847
    // Address: 0x10004A94
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_350;                                       // 848
    // Address: 0x10004A98
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_351;                                       // 849
    // Address: 0x10004A9C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_352;                                       // 850
    // Address: 0x10004AA0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_353;                                       // 851
    // Address: 0x10004AA4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_RealizeFeverStar;                          // 852
    // Address: 0x10004AA8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_Star;                                      // 853
    // Address: 0x10004AAC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectPlayer;                        // 854
    // Address: 0x10004AB0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectPlayer2PSub;                   // 855 (CS Player 2, 3 or 4)
    // Address: 0x10004AB4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectChibiYoshi;                    // 856
    // Address: 0x10004AB8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectCamera;                        // 857
    // Address: 0x10004ABC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectCastle;                        // 858
    // Address: 0x10004AC0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectToride;                        // 859
    // Address: 0x10004AC4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectKinokoHouse1up;                // 860
    // Address: 0x10004AC8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectKinokoHouseShuffle;            // 861
    // Address: 0x10004ACC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectKinokoHouseSlot;               // 862
    // Address: 0x10004AD0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectPeachGates1st;                 // 863
    // Address: 0x10004AD4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectPeachGates2nd;                 // 864
    // Address: 0x10004AD8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectCoursePoint;                   // 865
    // Address: 0x10004ADC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectWorldMoveDokan;                // 866
    // Address: 0x10004AE0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectW8Cloud;                       // 867
    // Address: 0x10004AE4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectGhost;                         // 868
    // Address: 0x10004AE8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectW2Bros;                        // 869 (The Japanese Profile name says "Hammer Bros" LOL)
    // Address: 0x10004AEC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShipW1;                        // 870
    // Address: 0x10004AF0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShipW2;                        // 871
    // Address: 0x10004AF4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShipW3;                        // 872
    // Address: 0x10004AF8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShipW4;                        // 873
    // Address: 0x10004AFC
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShipW5;                        // 874
    // Address: 0x10004B00
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShipW6;                        // 875
    // Address: 0x10004B04
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShipW7;                        // 876
    // Address: 0x10004B08
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShipW8;                        // 877
    // Address: 0x10004B0C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShipW8Broken;                  // 878
    // Address: 0x10004B10
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectSurrender;                     // 879
    // Address: 0x10004B14
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectSwitchA;                       // 880
    // Address: 0x10004B18
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectSwitchB;                       // 881
    // Address: 0x10004B1C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectTeresa;                        // 882
    // Address: 0x10004B20
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectOpeningKameck;                 // 883
    // Address: 0x10004B24
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectTorideBoss;                    // 884
    // Address: 0x10004B28
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectPakkun;                        // 885
    // Address: 0x10004B2C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShadowFirstDemoKinopio;        // 886
    // Address: 0x10004B30
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectTobiPuku;                      // 887
    // Address: 0x10004B34
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectChorobon;                      // 888
    // Address: 0x10004B38
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectW7Item;                        // 889
    // Address: 0x10004B3C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectW5Teresa;                      // 890
    // Address: 0x10004B40
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectFlag;                          // 891
    // Address: 0x10004B44
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectMusasabi;                      // 892
    // Address: 0x10004B48
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectWPillar;                       // 893
    // Address: 0x10004B4C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectW7Bridge;                      // 894
    // Address: 0x10004B50
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectMiiBalloon;                    // 895
    // Address: 0x10004B54
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectPenguin;                       // 896
    // Address: 0x10004B58
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectW4Item;                        // 897
    // Address: 0x10004B5C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectW2Kuribo;                      // 898
    // Address: 0x10004B60
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectPakkunBig;                     // 899
    // Address: 0x10004B64
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShadowKunIcon;                 // 900
    // Address: 0x10004B68
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectDekaUnira;                     // 901
    // Address: 0x10004B6C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectTomb;                          // 902
    // Address: 0x10004B70
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectShadowFirstDemoShadowKun;      // 903
    // Address: 0x10004B74
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectKotsuCoaster;                  // 904
    // Address: 0x10004B78
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectKoopaJr;                       // 905
    // Address: 0x10004B7C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectPeach;                         // 906
    // Address: 0x10004B80
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectW1Item;                        // 907
    // Address: 0x10004B84
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectStarGate;                      // 908
    // Address: 0x10004B88
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_CourseSelectEventAssistant;                // 909
};
