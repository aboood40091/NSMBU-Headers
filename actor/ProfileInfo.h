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
        cDrawPriority_1B9                                       =   0,
        cDrawPriority_PlayerObject                              =   1,
        cDrawPriority_TottenPlayer                              =   2,
        cDrawPriority_Yoshi                                     =   3,
        cDrawPriority_1BD                                       =   4,
        cDrawPriority_1D3                                       =   5,
        cDrawPriority_1D4                                       =   6,
        cDrawPriority_1D5                                       =   7,
        cDrawPriority_1D6                                       =   8,
        cDrawPriority_1D7                                       =   9,
        cDrawPriority_1D8                                       =  10,
        cDrawPriority_1D9                                       =  11,
        cDrawPriority_IceBall                                   =  12,
        cDrawPriority_IceBallPakkun                             =  13,
        cDrawPriority_FireBallPlayer                            =  14,
        cDrawPriority_FireBallPakkun                            =  15,
        cDrawPriority_YoshiFire                                 =  16,
        cDrawPriority_1DF                                       =  17,
        cDrawPriority_1E0                                       =  18,
        cDrawPriority_1E1                                       =  19,
        cDrawPriority_1E2                                       =  20,
        cDrawPriority_305                                       =  21,
        cDrawPriority_306                                       =  22,
        cDrawPriority_307                                       =  23,
        cDrawPriority_308                                       =  24,
        cDrawPriority_309                                       =  25,
        cDrawPriority_1E3                                       =  26,
        cDrawPriority_1E4                                       =  27,
        cDrawPriority_1E5                                       =  28,
        cDrawPriority_1E6                                       =  29,
        cDrawPriority_1E7                                       =  30,
        cDrawPriority_1E8                                       =  31,
        cDrawPriority_1E9                                       =  32,
        cDrawPriority_1EA                                       =  33,
        cDrawPriority_1EB                                       =  34,
        cDrawPriority_1EC                                       =  35,
        cDrawPriority_1ED                                       =  36,
        cDrawPriority_1EE                                       =  37,
        cDrawPriority_1EF                                       =  38,
        cDrawPriority_1F0                                       =  39,
        cDrawPriority_1F1                                       =  40,
        cDrawPriority_1F2                                       =  41,
        cDrawPriority_1F3                                       =  42,
        cDrawPriority_1F4                                       =  43,
        cDrawPriority_1F5                                       =  44,
        cDrawPriority_1F6                                       =  45,
        cDrawPriority_1F7                                       =  46,
        cDrawPriority_11B                                       =  47,
        cDrawPriority_14D                                       =  48,
        cDrawPriority_14E                                       =  49,
        cDrawPriority_14F                                       =  50,
        cDrawPriority_150                                       =  51,
        cDrawPriority_151                                       =  52,
        cDrawPriority_152                                       =  53,
        cDrawPriority_153                                       =  54,
        cDrawPriority_154                                       =  55,
        cDrawPriority_082                                       =  56,
        cDrawPriority_083                                       =  57,
        cDrawPriority_084                                       =  58,
        cDrawPriority_085                                       =  59,
        cDrawPriority_155                                       =  60,
        cDrawPriority_156                                       =  61,
        cDrawPriority_157                                       =  62,
        cDrawPriority_086                                       =  63,
        cDrawPriority_087                                       =  64,
        cDrawPriority_088                                       =  65,
        cDrawPriority_089                                       =  66,
        cDrawPriority_08A                                       =  67,
        cDrawPriority_08B                                       =  68,
        cDrawPriority_08C                                       =  69,
        cDrawPriority_08D                                       =  70,
        cDrawPriority_08E                                       =  71,
        cDrawPriority_05F                                       =  72,
        cDrawPriority_060                                       =  73,
        cDrawPriority_061                                       =  74,
        cDrawPriority_102                                       =  75,
        cDrawPriority_08F                                       =  76,
        cDrawPriority_090                                       =  77,
        cDrawPriority_062                                       =  78,
        cDrawPriority_063                                       =  79,
        cDrawPriority_05C                                       =  80,
        cDrawPriority_05D                                       =  81,
        cDrawPriority_05E                                       =  82,
        cDrawPriority_064                                       =  83,
        cDrawPriority_091                                       =  84,
        cDrawPriority_092                                       =  85,
        cDrawPriority_1FF                                       =  86,
        cDrawPriority_Nokonoko                                  =  87,
        cDrawPriority_201                                       =  88,
        cDrawPriority_202                                       =  89,
        cDrawPriority_203                                       =  90,
        cDrawPriority_204                                       =  91,
        cDrawPriority_17D                                       =  92,
        cDrawPriority_17E                                       =  93,
        cDrawPriority_205                                       =  94,
        cDrawPriority_206                                       =  95,
        cDrawPriority_208                                       =  96,
        cDrawPriority_207                                       =  97,
        cDrawPriority_209                                       =  98,
        cDrawPriority_20A                                       =  99,
        cDrawPriority_20B                                       = 100,
        cDrawPriority_MechaKoopa                                = 101,
        cDrawPriority_20D                                       = 102,
        cDrawPriority_20E                                       = 103,
        cDrawPriority_PentaroIce                                = 104,
        cDrawPriority_210                                       = 105,
        cDrawPriority_211                                       = 106,
        cDrawPriority_212                                       = 107,
        cDrawPriority_213                                       = 108,
        cDrawPriority_214                                       = 109,
        cDrawPriority_215                                       = 110,
        cDrawPriority_216                                       = 111,
        cDrawPriority_217                                       = 112,
        cDrawPriority_218                                       = 113,
        cDrawPriority_219                                       = 114,
        cDrawPriority_21A                                       = 115,
        cDrawPriority_21B                                       = 116,
        cDrawPriority_21C                                       = 117,
        cDrawPriority_21D                                       = 118,
        cDrawPriority_224                                       = 119,
        cDrawPriority_17F                                       = 120,
        cDrawPriority_180                                       = 121,
        cDrawPriority_181                                       = 122,
        cDrawPriority_182                                       = 123,
        cDrawPriority_225                                       = 124,
        cDrawPriority_226                                       = 125,
        cDrawPriority_229                                       = 126,
        cDrawPriority_22A                                       = 127,
        cDrawPriority_FireBar                                   = 128,
        cDrawPriority_FireBarSync                               = 129,
        cDrawPriority_179                                       = 130,
        cDrawPriority_17A                                       = 131,
        cDrawPriority_Burner                                    = 132,
        cDrawPriority_0E1                                       = 133,
        cDrawPriority_0E2                                       = 134,
        cDrawPriority_0E3                                       = 135,
        cDrawPriority_0EB                                       = 136,
        cDrawPriority_22C                                       = 137,
        cDrawPriority_22D                                       = 138,
        cDrawPriority_FireBallKeronpa                           = 139,
        cDrawPriority_FireBallKeronpaRDash                      = 140,
        cDrawPriority_FireSnake                                 = 141,
        cDrawPriority_27D                                       = 142,
        cDrawPriority_27E                                       = 143,
        cDrawPriority_27F                                       = 144,
        cDrawPriority_GabonRock                                 = 145,
        cDrawPriority_281                                       = 146,
        cDrawPriority_282                                       = 147,
        cDrawPriority_RockGabonRock                             = 148,
        cDrawPriority_284                                       = 149,
        cDrawPriority_SeichanSnowBall                           = 150,
        cDrawPriority_286                                       = 151,
        cDrawPriority_232                                       = 152,
        cDrawPriority_233                                       = 153,
        cDrawPriority_234                                       = 154,
        cDrawPriority_236                                       = 155,
        cDrawPriority_237                                       = 156,
        cDrawPriority_238                                       = 157,
        cDrawPriority_239                                       = 158,
        cDrawPriority_23A                                       = 159,
        cDrawPriority_23B                                       = 160,
        cDrawPriority_23C                                       = 161,
        cDrawPriority_23D                                       = 162,
        cDrawPriority_Kazandan                                  = 163,
        cDrawPriority_Bun                                       = 164,
        cDrawPriority_BunW2                                     = 165,
        cDrawPriority_BunW3                                     = 166,
        cDrawPriority_BunW4                                     = 167,
        cDrawPriority_BunW5                                     = 168,
        cDrawPriority_BunW6                                     = 169,
        cDrawPriority_BunDemoKameck                             = 170,
        cDrawPriority_LemmyBomb                                 = 171,
        cDrawPriority_Lemmy                                     = 172,
        cDrawPriority_LemmyBall                                 = 173,
        cDrawPriority_Morton                                    = 174,
        cDrawPriority_MortonSanbo                               = 175,
        cDrawPriority_MortonSanboParts                          = 176,
        cDrawPriority_Wendy                                     = 177,
        cDrawPriority_WendyRing                                 = 178,
        cDrawPriority_WendyIcicle                               = 179,
        cDrawPriority_WendyFloor                                = 180,
        cDrawPriority_Larry                                     = 181,
        cDrawPriority_KokoopaSearchFire                         = 182,
        cDrawPriority_Ludwig                                    = 183,
        cDrawPriority_LudwigAlterEgo                            = 184,
        cDrawPriority_Iggy                                      = 185,
        cDrawPriority_IggyMagic                                 = 186,
        cDrawPriority_IggyRoom                                  = 187,
        cDrawPriority_Woogan                                    = 188,
        cDrawPriority_Roy                                       = 189,
        cDrawPriority_BossKK                                    = 190,
        cDrawPriority_BossKKThunder                             = 191,
        cDrawPriority_BossKKDemoKameck                          = 192,
        cDrawPriority_BossKKDemoKK                              = 193,
        cDrawPriority_Kameck                                    = 194,
        cDrawPriority_KameckIce                                 = 195,
        cDrawPriority_KameckMagic                               = 196,
        cDrawPriority_PeachFinalCastleKoopaJr                   = 197,
        cDrawPriority_PeachFinalCastleKoopaJrClown              = 198,
        cDrawPriority_PeachFinalCastleKoopaJrLift               = 199,
        cDrawPriority_PeachFinalCastleKoopaJrLiftHmove          = 200,
        cDrawPriority_PeachFinalCastleKoopaJrLiftPairObj        = 201,
        cDrawPriority_RoyLiftWakiStep                           = 202,
        cDrawPriority_Koopa                                     = 203,
        cDrawPriority_KoopaFire                                 = 204,
        cDrawPriority_KoopaShutter                              = 205,
        cDrawPriority_DemoKoopaJr                               = 206,
        cDrawPriority_DemoKoopaJrClown                          = 207,
        cDrawPriority_KoopaDemoKameck                           = 208,
        cDrawPriority_FinalKoopa                                = 209,
        cDrawPriority_FinalKoopaFire                            = 210,
        cDrawPriority_FinalKoopaJr                              = 211,
        cDrawPriority_FinalKoopaJrClown                         = 212,
        cDrawPriority_FinalKoopaJrFire                          = 213,
        cDrawPriority_FinalBomhei                               = 214,
        cDrawPriority_KinokoLift                                = 215,
        cDrawPriority_KinokoLiftColor                           = 216,
        cDrawPriority_LiftZenStar                               = 217,
        cDrawPriority_033                                       = 218,
        cDrawPriority_0AD                                       = 219,
        cDrawPriority_0AE                                       = 220,
        cDrawPriority_0AF                                       = 221,
        cDrawPriority_0B0                                       = 222,
        cDrawPriority_0B1                                       = 223,
        cDrawPriority_050                                       = 224,
        cDrawPriority_17C                                       = 225,
        cDrawPriority_051                                       = 226,
        cDrawPriority_235                                       = 227,
        cDrawPriority_16D                                       = 228,
        cDrawPriority_Block                                     = 229,
        cDrawPriority_1BE                                       = 230,
        cDrawPriority_1BF                                       = 231,
        cDrawPriority_1C4                                       = 232,
        cDrawPriority_1C3                                       = 233,
        cDrawPriority_1C0                                       = 234,
        cDrawPriority_1C1                                       = 235,
        cDrawPriority_1C2                                       = 236,
        cDrawPriority_1C7                                       = 237,
        cDrawPriority_1C8                                       = 238,
        cDrawPriority_1C9                                       = 239,
        cDrawPriority_1CA                                       = 240,
        cDrawPriority_1CB                                       = 241,
        cDrawPriority_1CC                                       = 242,
        cDrawPriority_1CD                                       = 243,
        cDrawPriority_1CE                                       = 244,
        cDrawPriority_QuestPrizeItem                            = 245,
        cDrawPriority_1D0                                       = 246,
        cDrawPriority_1D1                                       = 247,
        cDrawPriority_183                                       = 248,
        cDrawPriority_184                                       = 249,
        cDrawPriority_185                                       = 250,
        cDrawPriority_186                                       = 251,
        cDrawPriority_22B                                       = 252,
        cDrawPriority_187                                       = 253,
        cDrawPriority_Kinoko                                    = 254,
        cDrawPriority_FireFlower                                = 255,
        cDrawPriority_RealizeFeverStar                          = 256,
        cDrawPriority_Star                                      = 257,
        cDrawPriority_MameKinoko                                = 258,
        cDrawPriority_IceFlower                                 = 259,
        cDrawPriority_Propeller                                 = 260,
        cDrawPriority_Penguin                                   = 261,
        cDrawPriority_OneUpKinoko                               = 262,
        cDrawPriority_Musasabi                                  = 263,
        cDrawPriority_SuperMoon                                 = 264,
        cDrawPriority_TitleDemoItem                             = 265,
        cDrawPriority_097                                       = 266,
        cDrawPriority_036                                       = 267,
        cDrawPriority_037                                       = 268,
        cDrawPriority_038                                       = 269,
        cDrawPriority_039                                       = 270,
        cDrawPriority_03A                                       = 271,
        cDrawPriority_03B                                       = 272,
        cDrawPriority_PairObjChild                              = 273,
        cDrawPriority_03D                                       = 274,
        cDrawPriority_03E                                       = 275,
        cDrawPriority_03F                                       = 276,
        cDrawPriority_040                                       = 277,
        cDrawPriority_041                                       = 278,
        cDrawPriority_042                                       = 279,
        cDrawPriority_043                                       = 280,
        cDrawPriority_044                                       = 281,
        cDrawPriority_045                                       = 282,
        cDrawPriority_046                                       = 283,
        cDrawPriority_047                                       = 284,
        cDrawPriority_048                                       = 285,
        cDrawPriority_049                                       = 286,
        cDrawPriority_04A                                       = 287,
        cDrawPriority_04B                                       = 288,
        cDrawPriority_04C                                       = 289,
        cDrawPriority_188                                       = 290,
        cDrawPriority_113                                       = 291,
        cDrawPriority_114                                       = 292,
        cDrawPriority_115                                       = 293,
        cDrawPriority_116                                       = 294,
        cDrawPriority_2E4                                       = 295,
        cDrawPriority_2E5                                       = 296,
        cDrawPriority_2E6                                       = 297,
        cDrawPriority_2E7                                       = 298,
        cDrawPriority_2E8                                       = 299,
        cDrawPriority_2E9                                       = 300,
        cDrawPriority_2EA                                       = 301,
        cDrawPriority_259                                       = 302,
        cDrawPriority_2EE                                       = 303,
        cDrawPriority_2EF                                       = 304,
        cDrawPriority_2F0                                       = 305,
        cDrawPriority_2F1                                       = 306,
        cDrawPriority_2F2                                       = 307,
        cDrawPriority_02B                                       = 308,
        cDrawPriority_02C                                       = 309,
        cDrawPriority_25A                                       = 310,
        cDrawPriority_25B                                       = 311,
        cDrawPriority_25C                                       = 312,
        cDrawPriority_25D                                       = 313,
        cDrawPriority_25E                                       = 314,
        cDrawPriority_25F                                       = 315,
        cDrawPriority_260                                       = 316,
        cDrawPriority_261                                       = 317,
        cDrawPriority_1AA                                       = 318,
        cDrawPriority_1AB                                       = 319,
        cDrawPriority_1AC                                       = 320,
        cDrawPriority_1AD                                       = 321,
        cDrawPriority_1AE                                       = 322,
        cDrawPriority_1AF                                       = 323,
        cDrawPriority_1B0                                       = 324,
        cDrawPriority_1B1                                       = 325,
        cDrawPriority_1B2                                       = 326,
        cDrawPriority_1B3                                       = 327,
        cDrawPriority_076                                       = 328,
        cDrawPriority_077                                       = 329,
        cDrawPriority_078                                       = 330,
        cDrawPriority_1B5                                       = 331,
        cDrawPriority_1B4                                       = 332,
        cDrawPriority_262                                       = 333,
        cDrawPriority_263                                       = 334,
        cDrawPriority_2F3                                       = 335,
        cDrawPriority_0BF                                       = 336,
        cDrawPriority_0C0                                       = 337,
        cDrawPriority_0C1                                       = 338,
        cDrawPriority_Hammer                                    = 339,
        cDrawPriority_2F5                                       = 340,
        cDrawPriority_Boomerang                                 = 341,
        cDrawPriority_2F7                                       = 342,
        cDrawPriority_FireBallBros                              = 343,
        cDrawPriority_2F9                                       = 344,
        cDrawPriority_IceBallBros                               = 345,
        cDrawPriority_2FB                                       = 346,
        cDrawPriority_MegaHammer                                = 347,
        cDrawPriority_2FD                                       = 348,
        cDrawPriority_2FF                                       = 349,
        cDrawPriority_300                                       = 350,
        cDrawPriority_301                                       = 351,
        cDrawPriority_121                                       = 352,
        cDrawPriority_122                                       = 353,
        cDrawPriority_ActorBlockRenga                           = 354,
        cDrawPriority_124                                       = 355,
        cDrawPriority_125                                       = 356,
        cDrawPriority_126                                       = 357,
        cDrawPriority_127                                       = 358,
        cDrawPriority_128                                       = 359,
        cDrawPriority_129                                       = 360,
        cDrawPriority_12A                                       = 361,
        cDrawPriority_12B                                       = 362,
        cDrawPriority_12C                                       = 363,
        cDrawPriority_12D                                       = 364,
        cDrawPriority_12E                                       = 365,
        cDrawPriority_12F                                       = 366,
        cDrawPriority_130                                       = 367,
        cDrawPriority_131                                       = 368,
        cDrawPriority_132                                       = 369,
        cDrawPriority_133                                       = 370,
        cDrawPriority_134                                       = 371,
        cDrawPriority_13F                                       = 372,
        cDrawPriority_140                                       = 373,
        cDrawPriority_ActorBlockMakeDRC                         = 374,
        cDrawPriority_136                                       = 375,
        cDrawPriority_137                                       = 376,
        cDrawPriority_138                                       = 377,
        cDrawPriority_13A                                       = 378,
        cDrawPriority_13B                                       = 379,
        cDrawPriority_0E4                                       = 380,
        cDrawPriority_0F5                                       = 381,
        cDrawPriority_0F6                                       = 382,
        cDrawPriority_0F7                                       = 383,
        cDrawPriority_0F8                                       = 384,
        cDrawPriority_0F9                                       = 385,
        cDrawPriority_139                                       = 386,
        cDrawPriority_13C                                       = 387,
        cDrawPriority_13D                                       = 388,
        cDrawPriority_13E                                       = 389,
        cDrawPriority_141                                       = 390,
        cDrawPriority_142                                       = 391,
        cDrawPriority_143                                       = 392,
        cDrawPriority_14B                                       = 393,
        cDrawPriority_ActorCoin                                 = 394,
        cDrawPriority_18C                                       = 395,
        cDrawPriority_18D                                       = 396,
        cDrawPriority_18E                                       = 397,
        cDrawPriority_18F                                       = 398,
        cDrawPriority_190                                       = 399,
        cDrawPriority_191                                       = 400,
        cDrawPriority_192                                       = 401,
        cDrawPriority_193                                       = 402,
        cDrawPriority_194                                       = 403,
        cDrawPriority_195                                       = 404,
        cDrawPriority_196                                       = 405,
        cDrawPriority_197                                       = 406,
        cDrawPriority_198                                       = 407,
        cDrawPriority_199                                       = 408,
        cDrawPriority_19A                                       = 409,
        cDrawPriority_19B                                       = 410,
        cDrawPriority_19C                                       = 411,
        cDrawPriority_19D                                       = 412,
        cDrawPriority_19E                                       = 413,
        cDrawPriority_1A0                                       = 414,
        cDrawPriority_19F                                       = 415,
        cDrawPriority_032                                       = 416,
        cDrawPriority_1A1                                       = 417,
        cDrawPriority_1A2                                       = 418,
        cDrawPriority_1A3                                       = 419,
        cDrawPriority_1A4                                       = 420,
        cDrawPriority_1A5                                       = 421,
        cDrawPriority_1A6                                       = 422,
        cDrawPriority_1A7                                       = 423,
        cDrawPriority_1A8                                       = 424,
        cDrawPriority_BlueCoin                                  = 425,
        cDrawPriority_264                                       = 426,
        cDrawPriority_1F9                                       = 427,
        cDrawPriority_1FA                                       = 428,
        cDrawPriority_1FB                                       = 429,
        cDrawPriority_1FC                                       = 430,
        cDrawPriority_1FD                                       = 431,
        cDrawPriority_1FE                                       = 432,
        cDrawPriority_311                                       = 433,
        cDrawPriority_312                                       = 434,
        cDrawPriority_052                                       = 435,
        cDrawPriority_053                                       = 436,
        cDrawPriority_0C5                                       = 437,
        cDrawPriority_0C6                                       = 438,
        cDrawPriority_265                                       = 439,
        cDrawPriority_KillerHoudai                              = 440,
        cDrawPriority_StretchKillerHoudai                       = 441,
        cDrawPriority_MagnumKillerHoudai                        = 442,
        cDrawPriority_MagnumKillerHoudaiDown                    = 443,
        cDrawPriority_SearchKillerHoudai                        = 444,
        cDrawPriority_SearchMagnumKillerHoudai                  = 445,
        cDrawPriority_SearchMagnumKillerHoudaiDown              = 446,
        cDrawPriority_MagnumKillerHoudaiRDash                   = 447,
        cDrawPriority_MagnumKillerHoudaiDownRDash               = 448,
        cDrawPriority_SearchMagnumKillerHoudaiRDash             = 449,
        cDrawPriority_SearchMagnumKillerHoudaiDownRDash         = 450,
        cDrawPriority_070                                       = 451,
        cDrawPriority_071                                       = 452,
        cDrawPriority_072                                       = 453,
        cDrawPriority_073                                       = 454,
        cDrawPriority_074                                       = 455,
        cDrawPriority_273                                       = 456,
        cDrawPriority_075                                       = 457,
        cDrawPriority_274                                       = 458,
        cDrawPriority_275                                       = 459,
        cDrawPriority_SearchKiller                              = 460,
        cDrawPriority_277                                       = 461,
        cDrawPriority_278                                       = 462,
        cDrawPriority_279                                       = 463,
        cDrawPriority_27B                                       = 464,
        cDrawPriority_27C                                       = 465,
        cDrawPriority_SwitchHatenaButton                        = 466,
        cDrawPriority_SwitchPbutton                             = 467,
        cDrawPriority_SwitchPbuttonRDash                        = 468,
        cDrawPriority_SwitchPbuttonNoWallKick                   = 469,
        cDrawPriority_15C                                       = 470,
        cDrawPriority_15D                                       = 471,
        cDrawPriority_313                                       = 472,
        cDrawPriority_314                                       = 473,
        cDrawPriority_315                                       = 474,
        cDrawPriority_316                                       = 475,
        cDrawPriority_317                                       = 476,
        cDrawPriority_318                                       = 477,
        cDrawPriority_319                                       = 478,
        cDrawPriority_TarzanIvy                                 = 479,
        cDrawPriority_0EF                                       = 480,
        cDrawPriority_0F0                                       = 481,
        cDrawPriority_SnakeBlock                                = 482,
        cDrawPriority_0C3                                       = 483,
        cDrawPriority_0C4                                       = 484,
        cDrawPriority_0C8                                       = 485,
        cDrawPriority_31E                                       = 486,
        cDrawPriority_31D                                       = 487,
        cDrawPriority_0C7                                       = 488,
        cDrawPriority_0E5                                       = 489,
        cDrawPriority_117                                       = 490,
        cDrawPriority_31F                                       = 491,
        cDrawPriority_166                                       = 492,
        cDrawPriority_2F4                                       = 493,
        cDrawPriority_303                                       = 494,
        cDrawPriority_304                                       = 495,
        cDrawPriority_Intermittent                              = 496,
        cDrawPriority_IntermittentPermanent                     = 497,
        cDrawPriority_WaterIntermittent                         = 498,
        cDrawPriority_WaterIntermittentPermanent                = 499,
        cDrawPriority_WaterIntermittentPermanentRD3_3           = 500,
        cDrawPriority_07E                                       = 501,
        cDrawPriority_WaterIntermittentBossChild                = 502,
        cDrawPriority_YoganIntermittent                         = 503,
        cDrawPriority_Woochan                                   = 504,
        cDrawPriority_268                                       = 505,
        cDrawPriority_Spanner                                   = 506,
        cDrawPriority_26A                                       = 507,
        cDrawPriority_26B                                       = 508,
        cDrawPriority_26C                                       = 509,
        cDrawPriority_26D                                       = 510,
        cDrawPriority_26E                                       = 511,
        cDrawPriority_26F                                       = 512,
        cDrawPriority_270                                       = 513,
        cDrawPriority_0B2                                       = 514,
        cDrawPriority_100                                       = 515,
        cDrawPriority_101                                       = 516,
        cDrawPriority_0B3                                       = 517,
        cDrawPriority_16B                                       = 518,
        cDrawPriority_16C                                       = 519,
        cDrawPriority_0B4                                       = 520,
        cDrawPriority_0B5                                       = 521,
        cDrawPriority_0B6                                       = 522,
        cDrawPriority_0B7                                       = 523,
        cDrawPriority_LineSpinLift                              = 524,
        cDrawPriority_LineSpinLiftParentRDash                   = 525,
        cDrawPriority_LineSpinLiftChildRDash                    = 526,
        cDrawPriority_0BC                                       = 527,
        cDrawPriority_081                                       = 528,
        cDrawPriority_093                                       = 529,
        cDrawPriority_094                                       = 530,
        cDrawPriority_095                                       = 531,
        cDrawPriority_096                                       = 532,
        cDrawPriority_ElasticKinokoParent                       = 533,
        cDrawPriority_0CB                                       = 534,
        cDrawPriority_0CC                                       = 535,
        cDrawPriority_0E7                                       = 536,
        cDrawPriority_0E8                                       = 537,
        cDrawPriority_0E6                                       = 538,
        cDrawPriority_0EA                                       = 539,
        cDrawPriority_287                                       = 540,
        cDrawPriority_288                                       = 541,
        cDrawPriority_289                                       = 542,
        cDrawPriority_28B                                       = 543,
        cDrawPriority_28C                                       = 544,
        cDrawPriority_28D                                       = 545,
        cDrawPriority_098                                       = 546,
        cDrawPriority_099                                       = 547,
        cDrawPriority_09A                                       = 548,
        cDrawPriority_09B                                       = 549,
        cDrawPriority_09C                                       = 550,
        cDrawPriority_09D                                       = 551,
        cDrawPriority_09E                                       = 552,
        cDrawPriority_09F                                       = 553,
        cDrawPriority_0A1                                       = 554,
        cDrawPriority_0A2                                       = 555,
        cDrawPriority_0A3                                       = 556,
        cDrawPriority_0A4                                       = 557,
        cDrawPriority_0A5                                       = 558,
        cDrawPriority_0A6                                       = 559,
        cDrawPriority_0A0                                       = 560,
        cDrawPriority_0A7                                       = 561,
        cDrawPriority_0A8                                       = 562,
        cDrawPriority_0A9                                       = 563,
        cDrawPriority_0AA                                       = 564,
        cDrawPriority_0AB                                       = 565,
        cDrawPriority_0AC                                       = 566,
        cDrawPriority_0BE                                       = 567,
        cDrawPriority_0BD                                       = 568,
        cDrawPriority_0BB                                       = 569,
        cDrawPriority_320                                       = 570,
        cDrawPriority_0D3                                       = 571,
        cDrawPriority_0D6                                       = 572,
        cDrawPriority_0D4                                       = 573,
        cDrawPriority_0D5                                       = 574,
        cDrawPriority_0D7                                       = 575,
        cDrawPriority_0D8                                       = 576,
        cDrawPriority_0D9                                       = 577,
        cDrawPriority_0DA                                       = 578,
        cDrawPriority_0DB                                       = 579,
        cDrawPriority_103                                       = 580,
        cDrawPriority_0DC                                       = 581,
        cDrawPriority_0DD                                       = 582,
        cDrawPriority_0FA                                       = 583,
        cDrawPriority_0FB                                       = 584,
        cDrawPriority_162                                       = 585,
        cDrawPriority_29F                                       = 586,
        cDrawPriority_0E9                                       = 587,
        cDrawPriority_29E                                       = 588,
        cDrawPriority_2A1                                       = 589,
        cDrawPriority_2A2                                       = 590,
        cDrawPriority_1F8                                       = 591,
        cDrawPriority_2A3                                       = 592,
        cDrawPriority_104                                       = 593,
        cDrawPriority_16E                                       = 594,
        cDrawPriority_16F                                       = 595,
        cDrawPriority_29D                                       = 596,
        cDrawPriority_30A                                       = 597,
        cDrawPriority_IcicleBig                                 = 598,
        cDrawPriority_30B                                       = 599,
        cDrawPriority_30C                                       = 600,
        cDrawPriority_30D                                       = 601,
        cDrawPriority_30E                                       = 602,
        cDrawPriority_30F                                       = 603,
        cDrawPriority_310                                       = 604,
        cDrawPriority_163                                       = 605,
        cDrawPriority_164                                       = 606,
        cDrawPriority_165                                       = 607,
        cDrawPriority_11D                                       = 608,
        cDrawPriority_11E                                       = 609,
        cDrawPriority_0DE                                       = 610,
        cDrawPriority_0DF                                       = 611,
        cDrawPriority_0EC                                       = 612,
        cDrawPriority_FloorGyration                             = 613,
        cDrawPriority_FloorHoleDokan                            = 614,
        cDrawPriority_0D0                                       = 615,
        cDrawPriority_0D1                                       = 616,
        cDrawPriority_0C9                                       = 617,
        cDrawPriority_0CA                                       = 618,
        cDrawPriority_107                                       = 619,
        cDrawPriority_0CD                                       = 620,
        cDrawPriority_0CE                                       = 621,
        cDrawPriority_0CF                                       = 622,
        cDrawPriority_Bubble                                    = 623,
        cDrawPriority_BubbleSync                                = 624,
        cDrawPriority_BubbleRDash                               = 625,
        cDrawPriority_BubbleSyncRDash                           = 626,
        cDrawPriority_292                                       = 627,
        cDrawPriority_293                                       = 628,
        cDrawPriority_294                                       = 629,
        cDrawPriority_295                                       = 630,
        cDrawPriority_298                                       = 631,
        cDrawPriority_299                                       = 632,
        cDrawPriority_29A                                       = 633,
        cDrawPriority_29B                                       = 634,
        cDrawPriority_29C                                       = 635,
        cDrawPriority_161                                       = 636,
        cDrawPriority_168                                       = 637,
        cDrawPriority_169                                       = 638,
        cDrawPriority_0F3                                       = 639,
        cDrawPriority_0F4                                       = 640,
        cDrawPriority_322                                       = 641,
        cDrawPriority_323                                       = 642,
        cDrawPriority_324                                       = 643,
        cDrawPriority_325                                       = 644,
        cDrawPriority_PlyIce                                    = 645,
        cDrawPriority_326                                       = 646,
        cDrawPriority_144                                       = 647,
        cDrawPriority_145                                       = 648,
        cDrawPriority_146                                       = 649,
        cDrawPriority_147                                       = 650,
        cDrawPriority_0F1                                       = 651,
        cDrawPriority_0F2                                       = 652,
        cDrawPriority_327                                       = 653,
        cDrawPriority_328                                       = 654,
        cDrawPriority_BattleItem                                = 655,
        cDrawPriority_VsBattleItem                              = 656,
        cDrawPriority_2A4                                       = 657,
        cDrawPriority_2A5                                       = 658,
        cDrawPriority_321                                       = 659,
        cDrawPriority_32C                                       = 660,
        cDrawPriority_32D                                       = 661,
        cDrawPriority_32F                                       = 662,
        cDrawPriority_330                                       = 663,
        cDrawPriority_331                                       = 664,
        cDrawPriority_32A                                       = 665,
        cDrawPriority_KokoopaShipLemmy                          = 666,
        cDrawPriority_KokoopaShipMorton                         = 667,
        cDrawPriority_KokoopaShipLarry                          = 668,
        cDrawPriority_KokoopaShipWendy                          = 669,
        cDrawPriority_KokoopaShipIggy                           = 670,
        cDrawPriority_KokoopaShipRoy                            = 671,
        cDrawPriority_KokoopaShipLudwig                         = 672,
        cDrawPriority_KokoopaShipWarpCannon                     = 673,
        cDrawPriority_Peach                                     = 674,
        cDrawPriority_2E0                                       = 675,
        cDrawPriority_FinalDVPeach                              = 676,
        cDrawPriority_FinalDVShutter                            = 677,
        cDrawPriority_2E3                                       = 678,
        cDrawPriority_1D2                                       = 679,
        cDrawPriority_148                                       = 680,
        cDrawPriority_149                                       = 681,
        cDrawPriority_14A                                       = 682,
        cDrawPriority_119                                       = 683,
        cDrawPriority_11A                                       = 684,
        cDrawPriority_108                                       = 685,
        cDrawPriority_KoopaJrFire                               = 686,
        cDrawPriority_KoopaJrBall                               = 687,
        cDrawPriority_174                                       = 688,
        cDrawPriority_025                                       = 689,
        cDrawPriority_UnderwaterKoopaJr                         = 690,
        cDrawPriority_UnderwaterKoopaJrClown                    = 691,
        cDrawPriority_UnderwaterKoopaJrRetreatPos               = 692,
        cDrawPriority_BoxingKoopaJr                             = 693,
        cDrawPriority_BoxingKoopaJrClown                        = 694,
        cDrawPriority_BoxingKoopaJrPostBattleDemo               = 695,
        cDrawPriority_BoxingKoopaJrClownPostBattleDemo          = 696,
        cDrawPriority_054                                       = 697,
        cDrawPriority_055                                       = 698,
        cDrawPriority_056                                       = 699,
        cDrawPriority_057                                       = 700,
        cDrawPriority_058                                       = 701,
        cDrawPriority_059                                       = 702,
        cDrawPriority_BgActorYukaMario                          = 703,
        cDrawPriority_05B                                       = 704,
        cDrawPriority_0FC                                       = 705,
        cDrawPriority_0FD                                       = 706,
        cDrawPriority_0FE                                       = 707,
        cDrawPriority_0FF                                       = 708,
        cDrawPriority_SlotYoshiChibi                            = 709,
        cDrawPriority_MiniGamePanelItem                         = 710,
        cDrawPriority_SlotItem                                  = 711,
        cDrawPriority_ShuffleBlock                              = 712,
        cDrawPriority_CoinmakiCoin                              = 713,
        cDrawPriority_CoinmakiItem                              = 714,
        cDrawPriority_CoinmakiCannon                            = 715,
        cDrawPriority_MiniGameKinopio                           = 716,
        cDrawPriority_33F                                       = 717,
        cDrawPriority_340                                       = 718,
        cDrawPriority_341                                       = 719,
        cDrawPriority_342                                       = 720,
        cDrawPriority_10A                                       = 721,
        cDrawPriority_10B                                       = 722,
        cDrawPriority_10C                                       = 723,
        cDrawPriority_118                                       = 724,
        cDrawPriority_17B                                       = 725,
        cDrawPriority_350                                       = 726,
        cDrawPriority_StaffRollMgr                              = 727,
        cDrawPriority_StaffRollMgrRDash                         = 728,
        cDrawPriority_StaffCreditChibiYoshiABC                  = 729,
        cDrawPriority_StaffCreditChibiYoshiBalloon              = 730,
        cDrawPriority_StaffCreditChibiYoshiBalloonCheer         = 731,
        cDrawPriority_StaffCreditChibiYoshiLight                = 732,
        cDrawPriority_StaffCreditChibiYoshiLightCheer           = 733,
        cDrawPriority_StaffCreditSoapABC                        = 734,
        cDrawPriority_StaffCreditSoapCoin                       = 735,
        cDrawPriority_StaffCreditTottenKun                      = 736,
        cDrawPriority_CourseSelectPlayer                        = 737,
        cDrawPriority_CourseSelectPlayer2PSub                   = 738,
        cDrawPriority_CourseSelectChibiYoshi                    = 739,
        cDrawPriority_CourseSelectCamera                        = 740,
        cDrawPriority_CourseSelectCastle                        = 741,
        cDrawPriority_CourseSelectToride                        = 742,
        cDrawPriority_CourseSelectKinokoHouse1up                = 743,
        cDrawPriority_CourseSelectKinokoHouseShuffle            = 744,
        cDrawPriority_CourseSelectKinokoHouseSlot               = 745,
        cDrawPriority_CourseSelectPeachGates1st                 = 746,
        cDrawPriority_CourseSelectPeachGates2nd                 = 747,
        cDrawPriority_CourseSelectCoursePoint                   = 748,
        cDrawPriority_CourseSelectWorldMoveDokan                = 749,
        cDrawPriority_CourseSelectGhost                         = 750,
        cDrawPriority_CourseSelectW8Cloud                       = 751,
        cDrawPriority_CourseSelectW2Bros                        = 752,
        cDrawPriority_CourseSelectEventAssistant                = 753,
        cDrawPriority_CourseSelectShipW1                        = 754,
        cDrawPriority_CourseSelectShipW2                        = 755,
        cDrawPriority_CourseSelectShipW3                        = 756,
        cDrawPriority_CourseSelectShipW4                        = 757,
        cDrawPriority_CourseSelectShipW5                        = 758,
        cDrawPriority_CourseSelectShipW6                        = 759,
        cDrawPriority_CourseSelectShipW7                        = 760,
        cDrawPriority_CourseSelectShipW8                        = 761,
        cDrawPriority_CourseSelectShipW8Broken                  = 762,
        cDrawPriority_CourseSelectSurrender                     = 763,
        cDrawPriority_CourseSelectSwitchA                       = 764,
        cDrawPriority_CourseSelectSwitchB                       = 765,
        cDrawPriority_CourseSelectTeresa                        = 766,
        cDrawPriority_CourseSelectOpeningKameck                 = 767,
        cDrawPriority_CourseSelectTorideBoss                    = 768,
        cDrawPriority_CourseSelectPakkun                        = 769,
        cDrawPriority_CourseSelectShadowFirstDemoKinopio        = 770,
        cDrawPriority_CourseSelectTobiPuku                      = 771,
        cDrawPriority_CourseSelectChorobon                      = 772,
        cDrawPriority_CourseSelectW7Item                        = 773,
        cDrawPriority_CourseSelectW5Teresa                      = 774,
        cDrawPriority_CourseSelectFlag                          = 775,
        cDrawPriority_CourseSelectMusasabi                      = 777,
        cDrawPriority_CourseSelectWPillar                       = 778,
        cDrawPriority_CourseSelectW7Bridge                      = 779,
        cDrawPriority_CourseSelectMiiBalloon                    = 780,
        cDrawPriority_CourseSelectPenguin                       = 781,
        cDrawPriority_CourseSelectW4Item                        = 782,
        cDrawPriority_CourseSelectW2Kuribo                      = 783,
        cDrawPriority_CourseSelectPakkunBig                     = 784,
        cDrawPriority_CourseSelectShadowKunIcon                 = 785,
        cDrawPriority_CourseSelectDekaUnira                     = 786,
        cDrawPriority_CourseSelectTomb                          = 787,
        cDrawPriority_CourseSelectShadowFirstDemoShadowKun      = 788,
        cDrawPriority_CourseSelectKotsuCoaster                  = 789,
        cDrawPriority_CourseSelectKoopaJr                       = 790,
        cDrawPriority_CourseSelectPeach                         = 791,
        cDrawPriority_CourseSelectW1Item                        = 792,
        cDrawPriority_CourseSelectStarGate                      = 793,
        cDrawPriority_38E                                       = 794,
        cDrawPriority_38F                                       = 795,

        // No Draw
        cDrawPriority_390                                       =   0 - 0x3ff,
        cDrawPriority_120                                       =   1 - 0x3ff,
        cDrawPriority_23F                                       =   2 - 0x3ff,
        cDrawPriority_240                                       =   3 - 0x3ff,
        cDrawPriority_241                                       =   4 - 0x3ff,
        cDrawPriority_242                                       =   5 - 0x3ff,
        cDrawPriority_243                                       =   6 - 0x3ff,
        cDrawPriority_244                                       =   7 - 0x3ff,
        cDrawPriority_245                                       =   8 - 0x3ff,
        cDrawPriority_246                                       =   9 - 0x3ff,
        cDrawPriority_247                                       =  10 - 0x3ff,
        cDrawPriority_248                                       =  11 - 0x3ff,
        cDrawPriority_249                                       =  12 - 0x3ff,
        cDrawPriority_24A                                       =  13 - 0x3ff,
        cDrawPriority_BgCenter                                  =  14 - 0x3ff,
        cDrawPriority_24C                                       =  15 - 0x3ff,
        cDrawPriority_24E                                       =  16 - 0x3ff,
        cDrawPriority_000                                       =  17 - 0x3ff,
        cDrawPriority_001                                       =  18 - 0x3ff,
        cDrawPriority_002                                       =  19 - 0x3ff,
        cDrawPriority_003                                       =  20 - 0x3ff,
        cDrawPriority_004                                       =  21 - 0x3ff,
        cDrawPriority_005                                       =  22 - 0x3ff,
        cDrawPriority_006                                       =  23 - 0x3ff,
        cDrawPriority_007                                       =  24 - 0x3ff,
        cDrawPriority_008                                       =  25 - 0x3ff,
        cDrawPriority_009                                       =  26 - 0x3ff,
        cDrawPriority_00B                                       =  27 - 0x3ff,
        cDrawPriority_00C                                       =  28 - 0x3ff,
        cDrawPriority_00D                                       =  29 - 0x3ff,
        cDrawPriority_027                                       =  30 - 0x3ff,
        cDrawPriority_028                                       =  31 - 0x3ff,
        cDrawPriority_029                                       =  32 - 0x3ff,
        cDrawPriority_02A                                       =  33 - 0x3ff,
        cDrawPriority_189                                       =  34 - 0x3ff,
        cDrawPriority_18A                                       =  35 - 0x3ff,
        cDrawPriority_267                                       =  36 - 0x3ff,
        cDrawPriority_266                                       =  37 - 0x3ff,
        cDrawPriority_21E                                       =  38 - 0x3ff,
        cDrawPriority_21F                                       =  39 - 0x3ff,
        cDrawPriority_220                                       =  40 - 0x3ff,
        cDrawPriority_026                                       =  41 - 0x3ff,
        cDrawPriority_223                                       =  42 - 0x3ff,
        cDrawPriority_2EB                                       =  43 - 0x3ff,
        cDrawPriority_271                                       =  44 - 0x3ff,
        cDrawPriority_272                                       =  45 - 0x3ff,
        cDrawPriority_221                                       =  46 - 0x3ff,
        cDrawPriority_222                                       =  47 - 0x3ff,
        cDrawPriority_20F                                       =  48 - 0x3ff,
        cDrawPriority_02D                                       =  49 - 0x3ff,
        cDrawPriority_02E                                       =  50 - 0x3ff,
        cDrawPriority_00E                                       =  51 - 0x3ff,
        cDrawPriority_00F                                       =  52 - 0x3ff,
        cDrawPriority_010                                       =  53 - 0x3ff,
        cDrawPriority_BunDemo                                   =  54 - 0x3ff,
        cDrawPriority_KokoopaDemo                               =  55 - 0x3ff,
        cDrawPriority_KoopaJrDemo                               =  56 - 0x3ff,
        cDrawPriority_KameckDemo                                =  57 - 0x3ff,
        cDrawPriority_BossKKDemo                                =  58 - 0x3ff,
        cDrawPriority_PeachFinalCastleKoopaJrDemo               =  59 - 0x3ff,
        cDrawPriority_KoopaDemo                                 =  60 - 0x3ff,
        cDrawPriority_FinalKoopaDemo                            =  61 - 0x3ff,
        cDrawPriority_PeachDemo                                 =  62 - 0x3ff,
        cDrawPriority_KameckIceConfig                           =  63 - 0x3ff,
        cDrawPriority_KameckWarpPos                             =  64 - 0x3ff,
        cDrawPriority_011                                       =  65 - 0x3ff,
        cDrawPriority_012                                       =  66 - 0x3ff,
        cDrawPriority_02F                                       =  67 - 0x3ff,
        cDrawPriority_030                                       =  68 - 0x3ff,
        cDrawPriority_2EC                                       =  69 - 0x3ff,
        cDrawPriority_2ED                                       =  70 - 0x3ff,
        cDrawPriority_00A                                       =  71 - 0x3ff,
        cDrawPriority_014                                       =  72 - 0x3ff,
        cDrawPriority_031                                       =  73 - 0x3ff,
        cDrawPriority_167                                       =  74 - 0x3ff,
        cDrawPriority_015                                       =  75 - 0x3ff,
        cDrawPriority_016                                       =  76 - 0x3ff,
        cDrawPriority_017                                       =  77 - 0x3ff,
        cDrawPriority_MiniGameMgr                               =  78 - 0x3ff,
        cDrawPriority_MiniGameMgrRDash                          =  79 - 0x3ff,
        cDrawPriority_ShuffleBlockMgr                           =  80 - 0x3ff,
        cDrawPriority_SlotMgr                                   =  81 - 0x3ff,
        cDrawPriority_CoinmakiMgr                               =  82 - 0x3ff,
        cDrawPriority_1C6                                       =  83 - 0x3ff,
        cDrawPriority_WakiSearchMagKiller                       =  84 - 0x3ff,
        cDrawPriority_32E                                       =  85 - 0x3ff,
        cDrawPriority_01D                                       =  86 - 0x3ff,
        cDrawPriority_01E                                       =  87 - 0x3ff,
        cDrawPriority_01F                                       =  88 - 0x3ff,
        cDrawPriority_KoopaFireWaki                             =  89 - 0x3ff,
        cDrawPriority_31A                                       =  90 - 0x3ff,
        cDrawPriority_020                                       =  91 - 0x3ff,
        cDrawPriority_013                                       =  92 - 0x3ff,
        cDrawPriority_31B                                       =  93 - 0x3ff,
        cDrawPriority_31C                                       =  94 - 0x3ff,
        cDrawPriority_ShootingStar                              =  95 - 0x3ff,
        cDrawPriority_302                                       =  96 - 0x3ff,
        cDrawPriority_227                                       =  97 - 0x3ff,
        cDrawPriority_228                                       =  98 - 0x3ff,
        cDrawPriority_343                                       =  99 - 0x3ff,
        cDrawPriority_344                                       = 100 - 0x3ff,
        cDrawPriority_345                                       = 101 - 0x3ff,
        cDrawPriority_RoyLiftWaki                               = 102 - 0x3ff,
        cDrawPriority_2A0                                       = 103 - 0x3ff,
        cDrawPriority_346                                       = 104 - 0x3ff,
        cDrawPriority_024                                       = 105 - 0x3ff,
        cDrawPriority_24D                                       = 106 - 0x3ff,
        cDrawPriority_230                                       = 107 - 0x3ff,
        cDrawPriority_296                                       = 108 - 0x3ff,
        cDrawPriority_297                                       = 109 - 0x3ff,
        cDrawPriority_351                                       = 110 - 0x3ff,
        cDrawPriority_11C                                       = 111 - 0x3ff,
        cDrawPriority_1B8                                       = 112 - 0x3ff,
        cDrawPriority_352                                       = 113 - 0x3ff,
        cDrawPriority_353                                       = 114 - 0x3ff,
        cDrawPriority_14C                                       = 115 - 0x3ff,
        cDrawPriority_347                                       = 116 - 0x3ff,
        cDrawPriority_1B7                                       = 117 - 0x3ff
    };

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
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_086;                                       // 134
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
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_0DE;                                       // 222
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
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_150;                                       // 336
    // Address: 0x10004298
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_151;                                       // 337
    // Address: 0x1000429C
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_152;                                       // 338
    // Address: 0x100042A0
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_153;                                       // 339
    // Address: 0x100042A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_154;                                       // 340
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
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1D3;                                       // 467
    // Address: 0x100044A4
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1D4;                                       // 468
    // Address: 0x100044A8
    PROFILE_INFO_STORAGE_STATIC const s32 cProfileID_1D5;                                       // 469
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
