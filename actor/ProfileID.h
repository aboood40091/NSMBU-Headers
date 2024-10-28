#pragma once

#include <basis/seadTypes.h>

enum
{
    cProfileID_Max = 913    // Profiles 910, 911 and 912 are extra
};

namespace ProfileID {

// Address: 0x10003D54
extern const s32 c000;                                      //   0
// Address: 0x10003D58
extern const s32 c001;                                      //   1
// Address: 0x10003D5C
extern const s32 c002;                                      //   2
// Address: 0x10003D60
extern const s32 c003;                                      //   3
// Address: 0x10003D64
extern const s32 c004;                                      //   4
// Address: 0x10003D68
extern const s32 c005;                                      //   5
// Address: 0x10003D6C
extern const s32 c006;                                      //   6
// Address: 0x10003D70
extern const s32 c007;                                      //   7
// Address: 0x10003D74
extern const s32 c008;                                      //   8
// Address: 0x10003D78
extern const s32 c009;                                      //   9
// Address: 0x10003D7C
extern const s32 c00A;                                      //  10
// Address: 0x10003D80
extern const s32 c00B;                                      //  11
// Address: 0x10003D84
extern const s32 c00C;                                      //  12
// Address: 0x10003D88
extern const s32 c00D;                                      //  13
// Address: 0x10003D8C
extern const s32 c00E;                                      //  14
// Address: 0x10003D90
extern const s32 c00F;                                      //  15
// Address: 0x10003D94
extern const s32 c010;                                      //  16
// Address: 0x10003D98
extern const s32 c011;                                      //  17
// Address: 0x10003D9C
extern const s32 c012;                                      //  18
// Address: 0x10003DA0
extern const s32 c013;                                      //  19
// Address: 0x10003DA4
extern const s32 c014;                                      //  20
// Address: 0x10003DA8
extern const s32 c015;                                      //  21
// Address: 0x10003DAC
extern const s32 c016;                                      //  22
// Address: 0x10003DB0
extern const s32 c017;                                      //  23
// Address: 0x10003DB4
extern const s32 cMiniGameMgr;                              //  24
// Address: 0x10003DB8
extern const s32 cMiniGameMgrRDash;                         //  25
// Address: 0x10003DBC
extern const s32 cShuffleBlockMgr;                          //  26
// Address: 0x10003DC0
extern const s32 cSlotMgr;                                  //  27
// Address: 0x10003DC4
extern const s32 cCoinmakiMgr;                              //  28
// Address: 0x10003DC8
extern const s32 c01D;                                      //  29
// Address: 0x10003DCC
extern const s32 c01E;                                      //  30
// Address: 0x10003DD0
extern const s32 c01F;                                      //  31
// Address: 0x10003DD4
extern const s32 c020;                                      //  32
// Address: 0x10003DD8
extern const s32 cShootingStar;                             //  33
// Address: 0x10003DDC
extern const s32 cStaffRollMgr;                             //  34
// Address: 0x10003DE0
extern const s32 cStaffRollMgrRDash;                        //  35
// Address: 0x10003DE4
extern const s32 c024;                                      //  36
// Address: 0x10003DE8
extern const s32 c025;                                      //  37
// Address: 0x10003DEC
extern const s32 c026;                                      //  38
// Address: 0x10003DF0
extern const s32 c027;                                      //  39
// Address: 0x10003DF4
extern const s32 c028;                                      //  40
// Address: 0x10003DF8
extern const s32 c029;                                      //  41
// Address: 0x10003DFC
extern const s32 c02A;                                      //  42
// Address: 0x10003E00
extern const s32 c02B;                                      //  43
// Address: 0x10003E04
extern const s32 c02C;                                      //  44
// Address: 0x10003E08
extern const s32 c02D;                                      //  45
// Address: 0x10003E0C
extern const s32 c02E;                                      //  46
// Address: 0x10003E10
extern const s32 c02F;                                      //  47
// Address: 0x10003E14
extern const s32 c030;                                      //  48
// Address: 0x10003E18
extern const s32 c031;                                      //  49
// Address: 0x10003E1C
extern const s32 c032;                                      //  50
// Address: 0x10003E20
extern const s32 c033;                                      //  51
// Address: 0x10003E24
extern const s32 c034;                                      //  52
// Address: 0x10003E28
extern const s32 c035;                                      //  53
// Address: 0x10003E2C
extern const s32 c036;                                      //  54
// Address: 0x10003E30
extern const s32 c037;                                      //  55
// Address: 0x10003E34
extern const s32 c038;                                      //  56
// Address: 0x10003E38
extern const s32 c039;                                      //  57
// Address: 0x10003E3C
extern const s32 c03A;                                      //  58
// Address: 0x10003E40
extern const s32 c03B;                                      //  59
// Address: 0x10003E44
extern const s32 c03C;                                      //  60
// Address: 0x10003E48
extern const s32 c03D;                                      //  61
// Address: 0x10003E4C
extern const s32 c03E;                                      //  62
// Address: 0x10003E50
extern const s32 c03F;                                      //  63
// Address: 0x10003E54
extern const s32 c040;                                      //  64
// Address: 0x10003E58
extern const s32 c041;                                      //  65
// Address: 0x10003E5C
extern const s32 c042;                                      //  66
// Address: 0x10003E60
extern const s32 c043;                                      //  67
// Address: 0x10003E64
extern const s32 c044;                                      //  68
// Address: 0x10003E68
extern const s32 c045;                                      //  69
// Address: 0x10003E6C
extern const s32 c046;                                      //  70
// Address: 0x10003E70
extern const s32 c047;                                      //  71
// Address: 0x10003E74
extern const s32 c048;                                      //  72
// Address: 0x10003E78
extern const s32 c049;                                      //  73
// Address: 0x10003E7C
extern const s32 c04A;                                      //  74
// Address: 0x10003E80
extern const s32 c04B;                                      //  75
// Address: 0x10003E84
extern const s32 c04C;                                      //  76
// Address: 0x10003E88
extern const s32 c04D;                                      //  77
// Address: 0x10003E8C
extern const s32 c04E;                                      //  78
// Address: 0x10003E90
extern const s32 c04F;                                      //  79
// Address: 0x10003E94
extern const s32 c050;                                      //  80
// Address: 0x10003E98
extern const s32 c051;                                      //  81
// Address: 0x10003E9C
extern const s32 c052;                                      //  82
// Address: 0x10003EA0
extern const s32 c053;                                      //  83
// Address: 0x10003EA4
extern const s32 c054;                                      //  84
// Address: 0x10003EA8
extern const s32 c055;                                      //  85
// Address: 0x10003EAC
extern const s32 c056;                                      //  86
// Address: 0x10003EB0
extern const s32 c057;                                      //  87
// Address: 0x10003EB4
extern const s32 c058;                                      //  88
// Address: 0x10003EB8
extern const s32 c059;                                      //  89
// Address: 0x10003EBC
extern const s32 c05A;                                      //  90
// Address: 0x10003EC0
extern const s32 c05B;                                      //  91
// Address: 0x10003EC4
extern const s32 c05C;                                      //  92
// Address: 0x10003EC8
extern const s32 c05D;                                      //  93
// Address: 0x10003ECC
extern const s32 c05E;                                      //  94
// Address: 0x10003ED0
extern const s32 c05F;                                      //  95
// Address: 0x10003ED4
extern const s32 c060;                                      //  96
// Address: 0x10003ED8
extern const s32 c061;                                      //  97
// Address: 0x10003EDC
extern const s32 c062;                                      //  98
// Address: 0x10003EE0
extern const s32 c063;                                      //  99
// Address: 0x10003EE4
extern const s32 c064;                                      // 100
// Address: 0x10003EE8
extern const s32 cKillerHoudai;                             // 101
// Address: 0x10003EEC
extern const s32 cStretchKillerHoudai;                      // 102
// Address: 0x10003EF0
extern const s32 cMagnumKillerHoudai;                       // 103
// Address: 0x10003EF4
extern const s32 cMagnumKillerHoudaiDown;                   // 104
// Address: 0x10003EF8
extern const s32 cSearchKillerHoudai;                       // 105
// Address: 0x10003EFC
extern const s32 cSearchMagnumKillerHoudai;                 // 106
// Address: 0x10003F00
extern const s32 cSearchMagnumKillerHoudaiDown;             // 107
// Address: 0x10003F04
extern const s32 cMagnumKillerHoudaiRDash;                  // 108
// Address: 0x10003F08
extern const s32 cMagnumKillerHoudaiDownRDash;              // 109
// Address: 0x10003F0C
extern const s32 cSearchMagnumKillerHoudaiRDash;            // 110
// Address: 0x10003F10
extern const s32 cSearchMagnumKillerHoudaiDownRDash;        // 111
// Address: 0x10003F14
extern const s32 c070;                                      // 112
// Address: 0x10003F18
extern const s32 c071;                                      // 113
// Address: 0x10003F1C
extern const s32 c072;                                      // 114
// Address: 0x10003F20
extern const s32 c073;                                      // 115
// Address: 0x10003F24
extern const s32 c074;                                      // 116
// Address: 0x10003F28
extern const s32 c075;                                      // 117
// Address: 0x10003F2C
extern const s32 c076;                                      // 118
// Address: 0x10003F30
extern const s32 c077;                                      // 119
// Address: 0x10003F34
extern const s32 c078;                                      // 120
// Address: 0x10003F38
extern const s32 c079;                                      // 121
// Address: 0x10003F3C
extern const s32 c07A;                                      // 122
// Address: 0x10003F40
extern const s32 c07B;                                      // 123
// Address: 0x10003F44
extern const s32 c07C;                                      // 124
// Address: 0x10003F48
extern const s32 c07D;                                      // 125
// Address: 0x10003F4C
extern const s32 c07E;                                      // 126
// Address: 0x10003F50
extern const s32 c07F;                                      // 127
// Address: 0x10003F54
extern const s32 cYoganIntermittent;                        // 128
// Address: 0x10003F58
extern const s32 c081;                                      // 129
// Address: 0x10003F5C
extern const s32 c082;                                      // 130
// Address: 0x10003F60
extern const s32 c083;                                      // 131
// Address: 0x10003F64
extern const s32 c084;                                      // 132
// Address: 0x10003F68
extern const s32 c085;                                      // 133
// Address: 0x10003F6C
extern const s32 c086;                                      // 134
// Address: 0x10003F70
extern const s32 c087;                                      // 135
// Address: 0x10003F74
extern const s32 c088;                                      // 136
// Address: 0x10003F78
extern const s32 c089;                                      // 137
// Address: 0x10003F7C
extern const s32 c08A;                                      // 138
// Address: 0x10003F80
extern const s32 c08B;                                      // 139
// Address: 0x10003F84
extern const s32 c08C;                                      // 140
// Address: 0x10003F88
extern const s32 c08D;                                      // 141
// Address: 0x10003F8C
extern const s32 c08E;                                      // 142
// Address: 0x10003F90
extern const s32 c08F;                                      // 143
// Address: 0x10003F94
extern const s32 c090;                                      // 144
// Address: 0x10003F98
extern const s32 c091;                                      // 145
// Address: 0x10003F9C
extern const s32 c092;                                      // 146
// Address: 0x10003FA0
extern const s32 c093;                                      // 147
// Address: 0x10003FA4
extern const s32 c094;                                      // 148
// Address: 0x10003FA8
extern const s32 c095;                                      // 149
// Address: 0x10003FAC
extern const s32 c096;                                      // 150
// Address: 0x10003FB0
extern const s32 c097;                                      // 151
// Address: 0x10003FB4
extern const s32 c098;                                      // 152
// Address: 0x10003FB8
extern const s32 c099;                                      // 153
// Address: 0x10003FBC
extern const s32 c09A;                                      // 154
// Address: 0x10003FC0
extern const s32 c09B;                                      // 155
// Address: 0x10003FC4
extern const s32 c09C;                                      // 156
// Address: 0x10003FC8
extern const s32 c09D;                                      // 157
// Address: 0x10003FCC
extern const s32 c09E;                                      // 158
// Address: 0x10003FD0
extern const s32 c09F;                                      // 159
// Address: 0x10003FD4
extern const s32 c0A0;                                      // 160
// Address: 0x10003FD8
extern const s32 c0A1;                                      // 161
// Address: 0x10003FDC
extern const s32 c0A2;                                      // 162
// Address: 0x10003FE0
extern const s32 c0A3;                                      // 163
// Address: 0x10003FE4
extern const s32 c0A4;                                      // 164
// Address: 0x10003FE8
extern const s32 c0A5;                                      // 165
// Address: 0x10003FEC
extern const s32 c0A6;                                      // 166
// Address: 0x10003FF0
extern const s32 c0A7;                                      // 167
// Address: 0x10003FF4
extern const s32 c0A8;                                      // 168
// Address: 0x10003FF8
extern const s32 c0A9;                                      // 169
// Address: 0x10003FFC
extern const s32 c0AA;                                      // 170
// Address: 0x10004000
extern const s32 c0AB;                                      // 171
// Address: 0x10004004
extern const s32 c0AC;                                      // 172
// Address: 0x10004008
extern const s32 c0AD;                                      // 173
// Address: 0x1000400C
extern const s32 c0AE;                                      // 174
// Address: 0x10004010
extern const s32 c0AF;                                      // 175
// Address: 0x10004014
extern const s32 c0B0;                                      // 176
// Address: 0x10004018
extern const s32 c0B1;                                      // 177
// Address: 0x1000401C
extern const s32 c0B2;                                      // 178
// Address: 0x10004020
extern const s32 c0B3;                                      // 179
// Address: 0x10004024
extern const s32 c0B4;                                      // 180
// Address: 0x10004028
extern const s32 c0B5;                                      // 181
// Address: 0x1000402C
extern const s32 c0B6;                                      // 182
// Address: 0x10004030
extern const s32 c0B7;                                      // 183
// Address: 0x10004034
extern const s32 c0B8;                                      // 184
// Address: 0x10004038
extern const s32 c0B9;                                      // 185
// Address: 0x1000403C
extern const s32 c0BA;                                      // 186
// Address: 0x10004040
extern const s32 c0BB;                                      // 187
// Address: 0x10004044
extern const s32 c0BC;                                      // 188
// Address: 0x10004048
extern const s32 c0BD;                                      // 189
// Address: 0x1000404C
extern const s32 c0BE;                                      // 190
// Address: 0x10004050
extern const s32 c0BF;                                      // 191
// Address: 0x10004054
extern const s32 c0C0;                                      // 192
// Address: 0x10004058
extern const s32 c0C1;                                      // 193
// Address: 0x1000405C
extern const s32 c0C2;                                      // 194
// Address: 0x10004060
extern const s32 c0C3;                                      // 195
// Address: 0x10004064
extern const s32 c0C4;                                      // 196
// Address: 0x10004068
extern const s32 c0C5;                                      // 197
// Address: 0x1000406C
extern const s32 c0C6;                                      // 198
// Address: 0x10004070
extern const s32 c0C7;                                      // 199
// Address: 0x10004074
extern const s32 c0C8;                                      // 200
// Address: 0x10004078
extern const s32 c0C9;                                      // 201
// Address: 0x1000407C
extern const s32 c0CA;                                      // 202
// Address: 0x10004080
extern const s32 c0CB;                                      // 203
// Address: 0x10004084
extern const s32 c0CC;                                      // 204
// Address: 0x10004088
extern const s32 c0CD;                                      // 205
// Address: 0x1000408C
extern const s32 c0CE;                                      // 206
// Address: 0x10004090
extern const s32 c0CF;                                      // 207
// Address: 0x10004094
extern const s32 c0D0;                                      // 208
// Address: 0x10004098
extern const s32 c0D1;                                      // 209
// Address: 0x1000409C
extern const s32 cFloorHoleDokan;                           // 210
// Address: 0x100040A0
extern const s32 c0D3;                                      // 211
// Address: 0x100040A4
extern const s32 c0D4;                                      // 212
// Address: 0x100040A8
extern const s32 c0D5;                                      // 213
// Address: 0x100040AC
extern const s32 c0D6;                                      // 214
// Address: 0x100040B0
extern const s32 c0D7;                                      // 215
// Address: 0x100040B4
extern const s32 c0D8;                                      // 216
// Address: 0x100040B8
extern const s32 c0D9;                                      // 217
// Address: 0x100040BC
extern const s32 c0DA;                                      // 218
// Address: 0x100040C0
extern const s32 c0DB;                                      // 219
// Address: 0x100040C4
extern const s32 c0DC;                                      // 220
// Address: 0x100040C8
extern const s32 c0DD;                                      // 221
// Address: 0x100040CC
extern const s32 c0DE;                                      // 222
// Address: 0x100040D0
extern const s32 c0DF;                                      // 223
// Address: 0x100040D4
extern const s32 c0E0;                                      // 224
// Address: 0x100040D8
extern const s32 c0E1;                                      // 225
// Address: 0x100040DC
extern const s32 c0E2;                                      // 226
// Address: 0x100040E0
extern const s32 c0E3;                                      // 227
// Address: 0x100040E4
extern const s32 c0E4;                                      // 228
// Address: 0x100040E8
extern const s32 c0E5;                                      // 229
// Address: 0x100040EC
extern const s32 c0E6;                                      // 230
// Address: 0x100040F0
extern const s32 c0E7;                                      // 231
// Address: 0x100040F4
extern const s32 c0E8;                                      // 232
// Address: 0x100040F8
extern const s32 c0E9;                                      // 233
// Address: 0x100040FC
extern const s32 c0EA;                                      // 234
// Address: 0x10004100
extern const s32 c0EB;                                      // 235
// Address: 0x10004104
extern const s32 c0EC;                                      // 236
// Address: 0x10004108
extern const s32 c0ED;                                      // 237
// Address: 0x1000410C
extern const s32 c0EE;                                      // 238
// Address: 0x10004110
extern const s32 c0EF;                                      // 239
// Address: 0x10004114
extern const s32 c0F0;                                      // 240
// Address: 0x10004118
extern const s32 c0F1;                                      // 241
// Address: 0x1000411C
extern const s32 c0F2;                                      // 242
// Address: 0x10004120
extern const s32 c0F3;                                      // 243
// Address: 0x10004124
extern const s32 c0F4;                                      // 244
// Address: 0x10004128
extern const s32 c0F5;                                      // 245
// Address: 0x1000412C
extern const s32 c0F6;                                      // 246
// Address: 0x10004130
extern const s32 c0F7;                                      // 247
// Address: 0x10004134
extern const s32 c0F8;                                      // 248
// Address: 0x10004138
extern const s32 c0F9;                                      // 249
// Address: 0x1000413C
extern const s32 c0FA;                                      // 250
// Address: 0x10004140
extern const s32 c0FB;                                      // 251
// Address: 0x10004144
extern const s32 c0FC;                                      // 252
// Address: 0x10004148
extern const s32 c0FD;                                      // 253
// Address: 0x1000414C
extern const s32 c0FE;                                      // 254
// Address: 0x10004150
extern const s32 c0FF;                                      // 255
// Address: 0x10004154
extern const s32 c100;                                      // 256
// Address: 0x10004158
extern const s32 c101;                                      // 257
// Address: 0x1000415C
extern const s32 c102;                                      // 258
// Address: 0x10004160
extern const s32 c103;                                      // 259
// Address: 0x10004164
extern const s32 c104;                                      // 260
// Address: 0x10004168
extern const s32 cShuffleBlock;                             // 261
// Address: 0x1000416C
extern const s32 cKokoopaShipWarpCannon;                    // 262
// Address: 0x10004170
extern const s32 c107;                                      // 263
// Address: 0x10004174
extern const s32 c108;                                      // 264
// Address: 0x10004178
extern const s32 cKoopaShutter;                             // 265
// Address: 0x1000417C
extern const s32 c10A;                                      // 266
// Address: 0x10004180
extern const s32 c10B;                                      // 267
// Address: 0x10004184
extern const s32 c10C;                                      // 268
// Address: 0x10004188
extern const s32 cPeachFinalCastleKoopaJrLift;              // 269
// Address: 0x1000418C
extern const s32 cPeachFinalCastleKoopaJrLiftHmove;         // 270
// Address: 0x10004190
extern const s32 cPeachFinalCastleKoopaJrLiftPairObj;       // 271
// Address: 0x10004194
extern const s32 cRoyLiftWakiStep;                          // 272
// Address: 0x10004198
extern const s32 cWendyFloor;                               // 273
// Address: 0x1000419C
extern const s32 cIggyRoom;                                 // 274
// Address: 0x100041A0
extern const s32 c113;                                      // 275
// Address: 0x100041A4
extern const s32 c114;                                      // 276
// Address: 0x100041A8
extern const s32 c115;                                      // 277
// Address: 0x100041AC
extern const s32 c116;                                      // 278
// Address: 0x100041B0
extern const s32 c117;                                      // 279
// Address: 0x100041B4
extern const s32 c118;                                      // 280
// Address: 0x100041B8
extern const s32 c119;                                      // 281
// Address: 0x100041BC
extern const s32 c11A;                                      // 282
// Address: 0x100041C0
extern const s32 c11B;                                      // 283
// Address: 0x100041C4
extern const s32 c11C;                                      // 284
// Address: 0x100041C8
extern const s32 c11D;                                      // 285
// Address: 0x100041CC
extern const s32 c11E;                                      // 286
// Address: 0x100041D0
extern const s32 c11F;                                      // 287
// Address: 0x100041D4
extern const s32 c120;                                      // 288
// Address: 0x100041D8
extern const s32 c121;                                      // 289
// Address: 0x100041DC
extern const s32 c122;                                      // 290
// Address: 0x100041E0
extern const s32 cActorBlockRenga;                          // 291
// Address: 0x100041E4
extern const s32 c124;                                      // 292
// Address: 0x100041E8
extern const s32 c125;                                      // 293
// Address: 0x100041EC
extern const s32 c126;                                      // 294
// Address: 0x100041F0
extern const s32 c127;                                      // 295
// Address: 0x100041F4
extern const s32 c128;                                      // 296
// Address: 0x100041F8
extern const s32 c129;                                      // 297
// Address: 0x100041FC
extern const s32 c12A;                                      // 298
// Address: 0x10004200
extern const s32 c12B;                                      // 299
// Address: 0x10004204
extern const s32 c12C;                                      // 300
// Address: 0x10004208
extern const s32 c12D;                                      // 301
// Address: 0x1000420C
extern const s32 c12E;                                      // 302
// Address: 0x10004210
extern const s32 c12F;                                      // 303
// Address: 0x10004214
extern const s32 c130;                                      // 304
// Address: 0x10004218
extern const s32 c131;                                      // 305
// Address: 0x1000421C
extern const s32 c132;                                      // 306
// Address: 0x10004220
extern const s32 c133;                                      // 307
// Address: 0x10004224
extern const s32 c134;                                      // 308
// Address: 0x10004228
extern const s32 c135;                                      // 309
// Address: 0x1000422C
extern const s32 c136;                                      // 310
// Address: 0x10004230
extern const s32 c137;                                      // 311
// Address: 0x10004234
extern const s32 c138;                                      // 312
// Address: 0x10004238
extern const s32 c139;                                      // 313
// Address: 0x1000423C
extern const s32 c13A;                                      // 314
// Address: 0x10004240
extern const s32 c13B;                                      // 315
// Address: 0x10004244
extern const s32 c13C;                                      // 316
// Address: 0x10004248
extern const s32 c13D;                                      // 317
// Address: 0x1000424C
extern const s32 c13E;                                      // 318
// Address: 0x10004250
extern const s32 c13F;                                      // 319
// Address: 0x10004254
extern const s32 c140;                                      // 320
// Address: 0x10004258
extern const s32 c141;                                      // 321
// Address: 0x1000425C
extern const s32 c142;                                      // 322
// Address: 0x10004260
extern const s32 c143;                                      // 323
// Address: 0x10004264
extern const s32 c144;                                      // 324
// Address: 0x10004268
extern const s32 c145;                                      // 325
// Address: 0x1000426C
extern const s32 c146;                                      // 326
// Address: 0x10004270
extern const s32 c147;                                      // 327
// Address: 0x10004274
extern const s32 c148;                                      // 328
// Address: 0x10004278
extern const s32 c149;                                      // 329
// Address: 0x1000427C
extern const s32 c14A;                                      // 330
// Address: 0x10004280
extern const s32 c14B;                                      // 331
// Address: 0x10004284
extern const s32 c14C;                                      // 332
// Address: 0x10004288
extern const s32 c14D;                                      // 333
// Address: 0x1000428C
extern const s32 c14E;                                      // 334
// Address: 0x10004290
extern const s32 c14F;                                      // 335
// Address: 0x10004294
extern const s32 c150;                                      // 336
// Address: 0x10004298
extern const s32 c151;                                      // 337
// Address: 0x1000429C
extern const s32 c152;                                      // 338
// Address: 0x100042A0
extern const s32 c153;                                      // 339
// Address: 0x100042A4
extern const s32 c154;                                      // 340
// Address: 0x100042A8
extern const s32 c155;                                      // 341
// Address: 0x100042AC
extern const s32 c156;                                      // 342
// Address: 0x100042B0
extern const s32 c157;                                      // 343
// Address: 0x100042B4
extern const s32 cSwitchHatenaButton;                       // 344
// Address: 0x100042B8
extern const s32 cSwitchPbutton;                            // 345
// Address: 0x100042BC
extern const s32 cSwitchPbuttonRDash;                       // 346
// Address: 0x100042C0
extern const s32 cSwitchPbuttonNoWallKick;                  // 347
// Address: 0x100042C4
extern const s32 c15C;                                      // 348
// Address: 0x100042C8
extern const s32 c15D;                                      // 349
// Address: 0x100042CC
extern const s32 c15E;                                      // 350
// Address: 0x100042D0
extern const s32 cLemmyBall;                                // 351
// Address: 0x100042D4
extern const s32 cLemmyBomb;                                // 352
// Address: 0x100042D8
extern const s32 c161;                                      // 353
// Address: 0x100042DC
extern const s32 c162;                                      // 354
// Address: 0x100042E0
extern const s32 c163;                                      // 355
// Address: 0x100042E4
extern const s32 c164;                                      // 356
// Address: 0x100042E8
extern const s32 c165;                                      // 357
// Address: 0x100042EC
extern const s32 c166;                                      // 358
// Address: 0x100042F0
extern const s32 c167;                                      // 359
// Address: 0x100042F4
extern const s32 c168;                                      // 360
// Address: 0x100042F8
extern const s32 c169;                                      // 361
// Address: 0x100042FC
extern const s32 c16A;                                      // 362
// Address: 0x10004300
extern const s32 c16B;                                      // 363
// Address: 0x10004304
extern const s32 c16C;                                      // 364
// Address: 0x10004308
extern const s32 c16D;                                      // 365
// Address: 0x1000430C
extern const s32 c16E;                                      // 366
// Address: 0x10004310
extern const s32 c16F;                                      // 367
// Address: 0x10004314
extern const s32 cKameckIce;                                // 368
// Address: 0x10004318
extern const s32 cWendyIcicle;                              // 369
// Address: 0x1000431C
extern const s32 cPeachFinalCastleKoopaJrClown;             // 370
// Address: 0x10004320
extern const s32 cBoxingKoopaJrClown;                       // 371
// Address: 0x10004324
extern const s32 c174;                                      // 372
// Address: 0x10004328
extern const s32 cFinalKoopaJrClown;                        // 373
// Address: 0x1000432C
extern const s32 cFinalKoopa;                               // 374
// Address: 0x10004330
extern const s32 c177;                                      // 375
// Address: 0x10004334
extern const s32 c178;                                      // 376
// Address: 0x10004338
extern const s32 c179;                                      // 377
// Address: 0x1000433C
extern const s32 c17A;                                      // 378
// Address: 0x10004340
extern const s32 c17B;                                      // 379
// Address: 0x10004344
extern const s32 c17C;                                      // 380
// Address: 0x10004348
extern const s32 c17D;                                      // 381
// Address: 0x1000434C
extern const s32 c17E;                                      // 382
// Address: 0x10004350
extern const s32 c17F;                                      // 383
// Address: 0x10004354
extern const s32 c180;                                      // 384
// Address: 0x10004358
extern const s32 c181;                                      // 385
// Address: 0x1000435C
extern const s32 c182;                                      // 386
// Address: 0x10004360
extern const s32 c183;                                      // 387
// Address: 0x10004364
extern const s32 c184;                                      // 388
// Address: 0x10004368
extern const s32 c185;                                      // 389
// Address: 0x1000436C
extern const s32 c186;                                      // 390
// Address: 0x10004370
extern const s32 c187;                                      // 391
// Address: 0x10004374
extern const s32 c188;                                      // 392
// Address: 0x10004378
extern const s32 c189;                                      // 393
// Address: 0x1000437C
extern const s32 c18A;                                      // 394
// Address: 0x10004380
extern const s32 cActorCoin;                                // 395
// Address: 0x10004384
extern const s32 c18C;                                      // 396
// Address: 0x10004388
extern const s32 c18D;                                      // 397
// Address: 0x1000438C
extern const s32 c18E;                                      // 398
// Address: 0x10004390
extern const s32 c18F;                                      // 399
// Address: 0x10004394
extern const s32 c190;                                      // 400
// Address: 0x10004398
extern const s32 c191;                                      // 401
// Address: 0x1000439C
extern const s32 c192;                                      // 402
// Address: 0x100043A0
extern const s32 c193;                                      // 403
// Address: 0x100043A4
extern const s32 c194;                                      // 404
// Address: 0x100043A8
extern const s32 c195;                                      // 405
// Address: 0x100043AC
extern const s32 c196;                                      // 406
// Address: 0x100043B0
extern const s32 c197;                                      // 407
// Address: 0x100043B4
extern const s32 c198;                                      // 408
// Address: 0x100043B8
extern const s32 c199;                                      // 409
// Address: 0x100043BC
extern const s32 c19A;                                      // 410
// Address: 0x100043C0
extern const s32 c19B;                                      // 411
// Address: 0x100043C4
extern const s32 c19C;                                      // 412
// Address: 0x100043C8
extern const s32 c19D;                                      // 413
// Address: 0x100043CC
extern const s32 c19E;                                      // 414
// Address: 0x100043D0
extern const s32 c19F;                                      // 415
// Address: 0x100043D4
extern const s32 c1A0;                                      // 416
// Address: 0x100043D8
extern const s32 c1A1;                                      // 417
// Address: 0x100043DC
extern const s32 c1A2;                                      // 418
// Address: 0x100043E0
extern const s32 c1A3;                                      // 419
// Address: 0x100043E4
extern const s32 c1A4;                                      // 420
// Address: 0x100043E8
extern const s32 c1A5;                                      // 421
// Address: 0x100043EC
extern const s32 c1A6;                                      // 422
// Address: 0x100043F0
extern const s32 c1A7;                                      // 423
// Address: 0x100043F4
extern const s32 c1A8;                                      // 424
// Address: 0x100043F8
extern const s32 cBlueCoin;                                 // 425
// Address: 0x100043FC
extern const s32 c1AA;                                      // 426
// Address: 0x10004400
extern const s32 c1AB;                                      // 427
// Address: 0x10004404
extern const s32 c1AC;                                      // 428
// Address: 0x10004408
extern const s32 c1AD;                                      // 429
// Address: 0x1000440C
extern const s32 c1AE;                                      // 430
// Address: 0x10004410
extern const s32 c1AF;                                      // 431
// Address: 0x10004414
extern const s32 c1B0;                                      // 432
// Address: 0x10004418
extern const s32 c1B1;                                      // 433
// Address: 0x1000441C
extern const s32 c1B2;                                      // 434
// Address: 0x10004420
extern const s32 c1B3;                                      // 435
// Address: 0x10004424
extern const s32 c1B4;                                      // 436
// Address: 0x10004428
extern const s32 c1B5;                                      // 437
// Address: 0x1000442C
extern const s32 cCoinmakiCoin;                             // 438
// Address: 0x10004430
extern const s32 c1B7;                                      // 439
// Address: 0x10004434
extern const s32 c1B8;                                      // 440
// Address: 0x10004438
extern const s32 c1B9;                                      // 441
// Address: 0x1000443C
extern const s32 cYoshi;                                    // 442
// Address: 0x10004440
extern const s32 cTottenPlayer;                             // 443
// Address: 0x10004444
extern const s32 cPlayerObject;                             // 444
// Address: 0x10004448
extern const s32 c1BD;                                      // 445
// Address: 0x1000444C
extern const s32 c1BE;                                      // 446
// Address: 0x10004450
extern const s32 c1BF;                                      // 447
// Address: 0x10004454
extern const s32 c1C0;                                      // 448
// Address: 0x10004458
extern const s32 c1C1;                                      // 449
// Address: 0x1000445C
extern const s32 c1C2;                                      // 450
// Address: 0x10004460
extern const s32 c1C3;                                      // 451
// Address: 0x10004464
extern const s32 c1C4;                                      // 452
// Address: 0x10004468
extern const s32 cSlotYoshiChibi;                           // 453
// Address: 0x1000446C
extern const s32 c1C6;                                      // 454
// Address: 0x10004470
extern const s32 c1C7;                                      // 455
// Address: 0x10004474
extern const s32 c1C8;                                      // 456
// Address: 0x10004478
extern const s32 c1C9;                                      // 457
// Address: 0x1000447C
extern const s32 c1CA;                                      // 458
// Address: 0x10004480
extern const s32 c1CB;                                      // 459
// Address: 0x10004484
extern const s32 c1CC;                                      // 460
// Address: 0x10004488
extern const s32 c1CD;                                      // 461
// Address: 0x1000448C
extern const s32 c1CE;                                      // 462
// Address: 0x10004490
extern const s32 cQuestPrizeItem;                           // 463
// Address: 0x10004494
extern const s32 c1D0;                                      // 464
// Address: 0x10004498
extern const s32 c1D1;                                      // 465
// Address: 0x1000449C
extern const s32 c1D2;                                      // 466
// Address: 0x100044A0
extern const s32 c1D3;                                      // 467
// Address: 0x100044A4
extern const s32 c1D4;                                      // 468
// Address: 0x100044A8
extern const s32 c1D5;                                      // 469
// Address: 0x100044AC
extern const s32 c1D6;                                      // 470
// Address: 0x100044B0
extern const s32 c1D7;                                      // 471
// Address: 0x100044B4
extern const s32 c1D8;                                      // 472
// Address: 0x100044B8
extern const s32 c1D9;                                      // 473
// Address: 0x100044BC
extern const s32 cIceBall;                                  // 474
// Address: 0x100044C0
extern const s32 cIceBallPakkun;                            // 475
// Address: 0x100044C4
extern const s32 cFireBallPlayer;                           // 476
// Address: 0x100044C8
extern const s32 cFireBallPakkun;                           // 477
// Address: 0x100044CC
extern const s32 c1DE;                                      // 478
// Address: 0x100044D0
extern const s32 c1DF;                                      // 479
// Address: 0x100044D4
extern const s32 c1E0;                                      // 480
// Address: 0x100044D8
extern const s32 c1E1;                                      // 481
// Address: 0x100044DC
extern const s32 c1E2;                                      // 482
// Address: 0x100044E0
extern const s32 c1E3;                                      // 483
// Address: 0x100044E4
extern const s32 c1E4;                                      // 484
// Address: 0x100044E8
extern const s32 c1E5;                                      // 485
// Address: 0x100044EC
extern const s32 c1E6;                                      // 486
// Address: 0x100044F0
extern const s32 c1E7;                                      // 487
// Address: 0x100044F4
extern const s32 c1E8;                                      // 488
// Address: 0x100044F8
extern const s32 c1E9;                                      // 489
// Address: 0x100044FC
extern const s32 c1EA;                                      // 490
// Address: 0x10004500
extern const s32 c1EB;                                      // 491
// Address: 0x10004504
extern const s32 c1EC;                                      // 492
// Address: 0x10004508
extern const s32 c1ED;                                      // 493
// Address: 0x1000450C
extern const s32 c1EE;                                      // 494
// Address: 0x10004510
extern const s32 c1EF;                                      // 495
// Address: 0x10004514
extern const s32 c1F0;                                      // 496
// Address: 0x10004518
extern const s32 c1F1;                                      // 497
// Address: 0x1000451C
extern const s32 c1F2;                                      // 498
// Address: 0x10004520
extern const s32 c1F3;                                      // 499
// Address: 0x10004524
extern const s32 c1F4;                                      // 500
// Address: 0x10004528
extern const s32 c1F5;                                      // 501
// Address: 0x1000452C
extern const s32 c1F6;                                      // 502
// Address: 0x10004530
extern const s32 c1F7;                                      // 503
// Address: 0x10004534
extern const s32 c1F8;                                      // 504
// Address: 0x10004538
extern const s32 c1F9;                                      // 505
// Address: 0x1000453C
extern const s32 c1FA;                                      // 506
// Address: 0x10004540
extern const s32 c1FB;                                      // 507
// Address: 0x10004544
extern const s32 c1FC;                                      // 508
// Address: 0x10004548
extern const s32 c1FD;                                      // 509
// Address: 0x1000454C
extern const s32 c1FE;                                      // 510
// Address: 0x10004550
extern const s32 c1FF;                                      // 511
// Address: 0x10004554
extern const s32 cNokonoko;                                 // 512
// Address: 0x10004558
extern const s32 c201;                                      // 513
// Address: 0x1000455C
extern const s32 c202;                                      // 514
// Address: 0x10004560
extern const s32 c203;                                      // 515
// Address: 0x10004564
extern const s32 c204;                                      // 516
// Address: 0x10004568
extern const s32 c205;                                      // 517
// Address: 0x1000456C
extern const s32 c206;                                      // 518
// Address: 0x10004570
extern const s32 c207;                                      // 519
// Address: 0x10004574
extern const s32 c208;                                      // 520
// Address: 0x10004578
extern const s32 c209;                                      // 521
// Address: 0x1000457C
extern const s32 c20A;                                      // 522
// Address: 0x10004580
extern const s32 c20B;                                      // 523
// Address: 0x10004584
extern const s32 c20C;                                      // 524
// Address: 0x10004588
extern const s32 c20D;                                      // 525
// Address: 0x1000458C
extern const s32 c20E;                                      // 526
// Address: 0x10004590
extern const s32 c20F;                                      // 527
// Address: 0x10004594
extern const s32 c210;                                      // 528
// Address: 0x10004598
extern const s32 c211;                                      // 529
// Address: 0x1000459C
extern const s32 c212;                                      // 530
// Address: 0x100045A0
extern const s32 c213;                                      // 531
// Address: 0x100045A4
extern const s32 c214;                                      // 532
// Address: 0x100045A8
extern const s32 c215;                                      // 533
// Address: 0x100045AC
extern const s32 c216;                                      // 534
// Address: 0x100045B0
extern const s32 c217;                                      // 535
// Address: 0x100045B4
extern const s32 c218;                                      // 536
// Address: 0x100045B8
extern const s32 c219;                                      // 537
// Address: 0x100045BC
extern const s32 c21A;                                      // 538
// Address: 0x100045C0
extern const s32 c21B;                                      // 539
// Address: 0x100045C4
extern const s32 c21C;                                      // 540
// Address: 0x100045C8
extern const s32 c21D;                                      // 541
// Address: 0x100045CC
extern const s32 c21E;                                      // 542
// Address: 0x100045D0
extern const s32 c21F;                                      // 543
// Address: 0x100045D4
extern const s32 c220;                                      // 544
// Address: 0x100045D8
extern const s32 c221;                                      // 545
// Address: 0x100045DC
extern const s32 c222;                                      // 546
// Address: 0x100045E0
extern const s32 c223;                                      // 547
// Address: 0x100045E4
extern const s32 c224;                                      // 548
// Address: 0x100045E8
extern const s32 c225;                                      // 549
// Address: 0x100045EC
extern const s32 c226;                                      // 550
// Address: 0x100045F0
extern const s32 c227;                                      // 551
// Address: 0x100045F4
extern const s32 c228;                                      // 552
// Address: 0x100045F8
extern const s32 c229;                                      // 553
// Address: 0x100045FC
extern const s32 c22A;                                      // 554
// Address: 0x10004600
extern const s32 c22B;                                      // 555
// Address: 0x10004604
extern const s32 c22C;                                      // 556
// Address: 0x10004608
extern const s32 c22D;                                      // 557
// Address: 0x1000460C
extern const s32 cFireBallKeronpa;                          // 558
// Address: 0x10004610
extern const s32 cFireBallKeronpaRDash;                     // 559
// Address: 0x10004614
extern const s32 c230;                                      // 560
// Address: 0x10004618
extern const s32 cFireSnake;                                // 561
// Address: 0x1000461C
extern const s32 c232;                                      // 562
// Address: 0x10004620
extern const s32 c233;                                      // 563
// Address: 0x10004624
extern const s32 c234;                                      // 564
// Address: 0x10004628
extern const s32 c235;                                      // 565
// Address: 0x1000462C
extern const s32 c236;                                      // 566
// Address: 0x10004630
extern const s32 c237;                                      // 567
// Address: 0x10004634
extern const s32 c238;                                      // 568
// Address: 0x10004638
extern const s32 c239;                                      // 569
// Address: 0x1000463C
extern const s32 c23A;                                      // 570
// Address: 0x10004640
extern const s32 c23B;                                      // 571
// Address: 0x10004644
extern const s32 c23C;                                      // 572
// Address: 0x10004648
extern const s32 c23D;                                      // 573
// Address: 0x1000464C
extern const s32 cKazandan;                                 // 574
// Address: 0x10004650
extern const s32 c23F;                                      // 575
// Address: 0x10004654
extern const s32 c240;                                      // 576
// Address: 0x10004658
extern const s32 c241;                                      // 577
// Address: 0x1000465C
extern const s32 c242;                                      // 578
// Address: 0x10004660
extern const s32 c243;                                      // 579
// Address: 0x10004664
extern const s32 c244;                                      // 580
// Address: 0x10004668
extern const s32 c245;                                      // 581
// Address: 0x1000466C
extern const s32 c246;                                      // 582
// Address: 0x10004670
extern const s32 c247;                                      // 583
// Address: 0x10004674
extern const s32 c248;                                      // 584
// Address: 0x10004678
extern const s32 c249;                                      // 585
// Address: 0x1000467C
extern const s32 c24A;                                      // 586
// Address: 0x10004680
extern const s32 cBgCenter;                                 // 587
// Address: 0x10004684
extern const s32 c24C;                                      // 588
// Address: 0x10004688
extern const s32 c24D;                                      // 589
// Address: 0x1000468C
extern const s32 c24E;                                      // 590
// Address: 0x10004690
extern const s32 cKinoko;                                   // 591
// Address: 0x10004694
extern const s32 cFireFlower;                               // 592
// Address: 0x10004698
extern const s32 cMameKinoko;                               // 593
// Address: 0x1000469C
extern const s32 cIceFlower;                                // 594
// Address: 0x100046A0
extern const s32 cPropeller;                                // 595
// Address: 0x100046A4
extern const s32 cPenguin;                                  // 596
// Address: 0x100046A8
extern const s32 cOneUpKinoko;                              // 597
// Address: 0x100046AC
extern const s32 cMusasabi;                                 // 598
// Address: 0x100046B0
extern const s32 cSuperMoon;                                // 599
// Address: 0x100046B4
extern const s32 cTitleDemoItem;                            // 600
// Address: 0x100046B8
extern const s32 c259;                                      // 601
// Address: 0x100046BC
extern const s32 c25A;                                      // 602
// Address: 0x100046C0
extern const s32 c25B;                                      // 603
// Address: 0x100046C4
extern const s32 c25C;                                      // 604
// Address: 0x100046C8
extern const s32 c25D;                                      // 605
// Address: 0x100046CC
extern const s32 c25E;                                      // 606
// Address: 0x100046D0
extern const s32 c25F;                                      // 607
// Address: 0x100046D4
extern const s32 c260;                                      // 608
// Address: 0x100046D8
extern const s32 c261;                                      // 609
// Address: 0x100046DC
extern const s32 c262;                                      // 610
// Address: 0x100046E0
extern const s32 c263;                                      // 611
// Address: 0x100046E4
extern const s32 c264;                                      // 612
// Address: 0x100046E8
extern const s32 c265;                                      // 613
// Address: 0x100046EC
extern const s32 c266;                                      // 614
// Address: 0x100046F0
extern const s32 c267;                                      // 615
// Address: 0x100046F4
extern const s32 c268;                                      // 616
// Address: 0x100046F8
extern const s32 cSpanner;                                  // 617
// Address: 0x100046FC
extern const s32 c26A;                                      // 618
// Address: 0x10004700
extern const s32 c26B;                                      // 619
// Address: 0x10004704
extern const s32 c26C;                                      // 620
// Address: 0x10004708
extern const s32 c26D;                                      // 621
// Address: 0x1000470C
extern const s32 c26E;                                      // 622
// Address: 0x10004710
extern const s32 c26F;                                      // 623
// Address: 0x10004714
extern const s32 c270;                                      // 624
// Address: 0x10004718
extern const s32 c271;                                      // 625
// Address: 0x1000471C
extern const s32 c272;                                      // 626
// Address: 0x10004720
extern const s32 c273;                                      // 627
// Address: 0x10004724
extern const s32 c274;                                      // 628
// Address: 0x10004728
extern const s32 c275;                                      // 629
// Address: 0x1000472C
extern const s32 c276;                                      // 630
// Address: 0x10004730
extern const s32 c277;                                      // 631
// Address: 0x10004734
extern const s32 c278;                                      // 632
// Address: 0x10004738
extern const s32 c279;                                      // 633
// Address: 0x1000473C
extern const s32 cWakiSearchMagKiller;                      // 634
// Address: 0x10004740
extern const s32 c27B;                                      // 635
// Address: 0x10004744
extern const s32 c27C;                                      // 636
// Address: 0x10004748
extern const s32 c27D;                                      // 637
// Address: 0x1000474C
extern const s32 c27E;                                      // 638
// Address: 0x10004750
extern const s32 c27F;                                      // 639
// Address: 0x10004754
extern const s32 cGabonRock;                                // 640
// Address: 0x10004758
extern const s32 c281;                                      // 641
// Address: 0x1000475C
extern const s32 c282;                                      // 642
// Address: 0x10004760
extern const s32 cRockGabonRock;                            // 643
// Address: 0x10004764
extern const s32 c284;                                      // 644
// Address: 0x10004768
extern const s32 cSeichanSnowBall;                          // 645
// Address: 0x1000476C
extern const s32 c286;                                      // 646
// Address: 0x10004770
extern const s32 c287;                                      // 647
// Address: 0x10004774
extern const s32 c288;                                      // 648
// Address: 0x10004778
extern const s32 c289;                                      // 649
// Address: 0x1000477C
extern const s32 cWoochan;                                  // 650
// Address: 0x10004780
extern const s32 c28B;                                      // 651
// Address: 0x10004784
extern const s32 c28C;                                      // 652
// Address: 0x10004788
extern const s32 c28D;                                      // 653
// Address: 0x1000478C
extern const s32 cBubble;                                   // 654
// Address: 0x10004790
extern const s32 cBubbleSync;                               // 655
// Address: 0x10004794
extern const s32 cBubbleRDash;                              // 656
// Address: 0x10004798
extern const s32 cBubbleSyncRDash;                          // 657
// Address: 0x1000479C
extern const s32 c292;                                      // 658
// Address: 0x100047A0
extern const s32 c293;                                      // 659
// Address: 0x100047A4
extern const s32 c294;                                      // 660
// Address: 0x100047A8
extern const s32 c295;                                      // 661
// Address: 0x100047AC
extern const s32 c296;                                      // 662
// Address: 0x100047B0
extern const s32 c297;                                      // 663
// Address: 0x100047B4
extern const s32 c298;                                      // 664
// Address: 0x100047B8
extern const s32 c299;                                      // 665
// Address: 0x100047BC
extern const s32 c29A;                                      // 666
// Address: 0x100047C0
extern const s32 c29B;                                      // 667
// Address: 0x100047C4
extern const s32 c29C;                                      // 668
// Address: 0x100047C8
extern const s32 c29D;                                      // 669
// Address: 0x100047CC
extern const s32 c29E;                                      // 670
// Address: 0x100047D0
extern const s32 c29F;                                      // 671
// Address: 0x100047D4
extern const s32 c2A0;                                      // 672
// Address: 0x100047D8
extern const s32 c2A1;                                      // 673
// Address: 0x100047DC
extern const s32 c2A2;                                      // 674
// Address: 0x100047E0
extern const s32 c2A3;                                      // 675
// Address: 0x100047E4
extern const s32 c2A4;                                      // 676
// Address: 0x100047E8
extern const s32 c2A5;                                      // 677
// Address: 0x100047EC
extern const s32 cBun;                                      // 678
// Address: 0x100047F0
extern const s32 cBunW2;                                    // 679
// Address: 0x100047F4
extern const s32 cBunW3;                                    // 680
// Address: 0x100047F8
extern const s32 cBunW4;                                    // 681
// Address: 0x100047FC
extern const s32 cBunW5;                                    // 682
// Address: 0x10004800
extern const s32 cBunW6;                                    // 683
// Address: 0x10004804
extern const s32 cBunDemo;                                  // 684
// Address: 0x10004808
extern const s32 cKokoopaDemo;                              // 685
// Address: 0x1000480C
extern const s32 cKoopaJrDemo;                              // 686
// Address: 0x10004810
extern const s32 cKameckDemo;                               // 687
// Address: 0x10004814
extern const s32 cBossKKDemo;                               // 688
// Address: 0x10004818
extern const s32 cPeachFinalCastleKoopaJrDemo;              // 689
// Address: 0x1000481C
extern const s32 cKoopaDemo;                                // 690
// Address: 0x10004820
extern const s32 cFinalKoopaDemo;                           // 691
// Address: 0x10004824
extern const s32 cPeachDemo;                                // 692
// Address: 0x10004828
extern const s32 cLarry;                                    // 693
// Address: 0x1000482C
extern const s32 cKokoopaSearchFire;                        // 694
// Address: 0x10004830
extern const s32 cLemmy;                                    // 695
// Address: 0x10004834
extern const s32 cMorton;                                   // 696
// Address: 0x10004838
extern const s32 cMortonSanbo;                              // 697
// Address: 0x1000483C
extern const s32 cMortonSanboParts;                         // 698
// Address: 0x10004840
extern const s32 cWendy;                                    // 699
// Address: 0x10004844
extern const s32 cWendyRing;                                // 700
// Address: 0x10004848
extern const s32 cLudwig;                                   // 701
// Address: 0x1000484C
extern const s32 cLudwigAlterEgo;                           // 702
// Address: 0x10004850
extern const s32 cIggy;                                     // 703
// Address: 0x10004854
extern const s32 cIggyMagic;                                // 704
// Address: 0x10004858
extern const s32 cWoogan;                                   // 705
// Address: 0x1000485C
extern const s32 cRoy;                                      // 706
// Address: 0x10004860
extern const s32 cRoyLiftWaki;                              // 707
// Address: 0x10004864
extern const s32 cBossKK;                                   // 708
// Address: 0x10004868
extern const s32 cBossKKThunder;                            // 709
// Address: 0x1000486C
extern const s32 cKameck;                                   // 710
// Address: 0x10004870
extern const s32 cKameckIceConfig;                          // 711
// Address: 0x10004874
extern const s32 cKameckWarpPos;                            // 712
// Address: 0x10004878
extern const s32 cKameckMagic;                              // 713
// Address: 0x1000487C
extern const s32 cPeachFinalCastleKoopaJr;                  // 714
// Address: 0x10004880
extern const s32 cKoopa;                                    // 715
// Address: 0x10004884
extern const s32 cKoopaFireWaki;                            // 716
// Address: 0x10004888
extern const s32 cKoopaFire;                                // 717
// Address: 0x1000488C
extern const s32 cDemoKoopaJrClown;                         // 718
// Address: 0x10004890
extern const s32 cDemoKoopaJr;                              // 719
// Address: 0x10004894
extern const s32 cBunDemoKameck;                            // 720
// Address: 0x10004898
extern const s32 cKoopaDemoKameck;                          // 721
// Address: 0x1000489C
extern const s32 cBossKKDemoKameck;                         // 722
// Address: 0x100048A0
extern const s32 cBossKKDemoKK;                             // 723
// Address: 0x100048A4
extern const s32 cFinalKoopaFire;                           // 724
// Address: 0x100048A8
extern const s32 cFinalKoopaJr;                             // 725
// Address: 0x100048AC
extern const s32 cFinalKoopaJrFire;                         // 726
// Address: 0x100048B0
extern const s32 cFinalBomhei;                              // 727
// Address: 0x100048B4
extern const s32 cKokoopaShipLemmy;                         // 728
// Address: 0x100048B8
extern const s32 cKokoopaShipMorton;                        // 729
// Address: 0x100048BC
extern const s32 cKokoopaShipLarry;                         // 730
// Address: 0x100048C0
extern const s32 cKokoopaShipWendy;                         // 731
// Address: 0x100048C4
extern const s32 cKokoopaShipIggy;                          // 732
// Address: 0x100048C8
extern const s32 cKokoopaShipRoy;                           // 733
// Address: 0x100048CC
extern const s32 cKokoopaShipLudwig;                        // 734
// Address: 0x100048D0
extern const s32 cPeach;                                    // 735
// Address: 0x100048D4
extern const s32 c2E0;                                      // 736
// Address: 0x100048D8
extern const s32 cFinalDVPeach;                             // 737
// Address: 0x100048DC
extern const s32 cFinalDVShutter;                           // 738
// Address: 0x100048E0
extern const s32 c2E3;                                      // 739
// Address: 0x100048E4
extern const s32 c2E4;                                      // 740
// Address: 0x100048E8
extern const s32 c2E5;                                      // 741
// Address: 0x100048EC
extern const s32 c2E6;                                      // 742
// Address: 0x100048F0
extern const s32 c2E7;                                      // 743
// Address: 0x100048F4
extern const s32 c2E8;                                      // 744
// Address: 0x100048F8
extern const s32 c2E9;                                      // 745
// Address: 0x100048FC
extern const s32 c2EA;                                      // 746
// Address: 0x10004900
extern const s32 c2EB;                                      // 747
// Address: 0x10004904
extern const s32 c2EC;                                      // 748
// Address: 0x10004908
extern const s32 c2ED;                                      // 749
// Address: 0x1000490C
extern const s32 c2EE;                                      // 750
// Address: 0x10004910
extern const s32 c2EF;                                      // 751
// Address: 0x10004914
extern const s32 c2F0;                                      // 752
// Address: 0x10004918
extern const s32 c2F1;                                      // 753
// Address: 0x1000491C
extern const s32 c2F2;                                      // 754
// Address: 0x10004920
extern const s32 c2F3;                                      // 755
// Address: 0x10004924
extern const s32 c2F4;                                      // 756
// Address: 0x10004928
extern const s32 c2F5;                                      // 757
// Address: 0x1000492C
extern const s32 cHammer;                                   // 758
// Address: 0x10004930
extern const s32 c2F7;                                      // 759
// Address: 0x10004934
extern const s32 cBoomerang;                                // 760
// Address: 0x10004938
extern const s32 c2F9;                                      // 761
// Address: 0x1000493C
extern const s32 cFireBallBros;                             // 762
// Address: 0x10004940
extern const s32 c2FB;                                      // 763
// Address: 0x10004944
extern const s32 cIceBallBros;                              // 764
// Address: 0x10004948
extern const s32 c2FD;                                      // 765
// Address: 0x1000494C
extern const s32 cMegaHammer;                               // 766
// Address: 0x10004950
extern const s32 c2FF;                                      // 767
// Address: 0x10004954
extern const s32 c300;                                      // 768
// Address: 0x10004958
extern const s32 c301;                                      // 769
// Address: 0x1000495C
extern const s32 c302;                                      // 770
// Address: 0x10004960
extern const s32 c303;                                      // 771
// Address: 0x10004964
extern const s32 c304;                                      // 772
// Address: 0x10004968
extern const s32 c305;                                      // 773
// Address: 0x1000496C
extern const s32 c306;                                      // 774
// Address: 0x10004970
extern const s32 c307;                                      // 775
// Address: 0x10004974
extern const s32 c308;                                      // 776
// Address: 0x10004978
extern const s32 c309;                                      // 777
// Address: 0x1000497C
extern const s32 c30A;                                      // 778
// Address: 0x10004980
extern const s32 c30B;                                      // 779
// Address: 0x10004984
extern const s32 c30C;                                      // 780
// Address: 0x10004988
extern const s32 c30D;                                      // 781
// Address: 0x1000498C
extern const s32 c30E;                                      // 782
// Address: 0x10004990
extern const s32 c30F;                                      // 783
// Address: 0x10004994
extern const s32 c310;                                      // 784
// Address: 0x10004998
extern const s32 c311;                                      // 785
// Address: 0x1000499C
extern const s32 c312;                                      // 786
// Address: 0x100049A0
extern const s32 c313;                                      // 787
// Address: 0x100049A4
extern const s32 c314;                                      // 788
// Address: 0x100049A8
extern const s32 c315;                                      // 789
// Address: 0x100049AC
extern const s32 c316;                                      // 790
// Address: 0x100049B0
extern const s32 c317;                                      // 791
// Address: 0x100049B4
extern const s32 c318;                                      // 792
// Address: 0x100049B8
extern const s32 c319;                                      // 793
// Address: 0x100049BC
extern const s32 c31A;                                      // 794
// Address: 0x100049C0
extern const s32 c31B;                                      // 795
// Address: 0x100049C4
extern const s32 c31C;                                      // 796
// Address: 0x100049C8
extern const s32 c31D;                                      // 797
// Address: 0x100049CC
extern const s32 c31E;                                      // 798
// Address: 0x100049D0
extern const s32 c31F;                                      // 799
// Address: 0x100049D4
extern const s32 c320;                                      // 800
// Address: 0x100049D8
extern const s32 c321;                                      // 801
// Address: 0x100049DC
extern const s32 c322;                                      // 802
// Address: 0x100049E0
extern const s32 c323;                                      // 803
// Address: 0x100049E4
extern const s32 c324;                                      // 804
// Address: 0x100049E8
extern const s32 c325;                                      // 805
// Address: 0x100049EC
extern const s32 c326;                                      // 806
// Address: 0x100049F0
extern const s32 c327;                                      // 807
// Address: 0x100049F4
extern const s32 c328;                                      // 808
// Address: 0x100049F8
extern const s32 cBattleItem;                               // 809
// Address: 0x100049FC
extern const s32 c32A;                                      // 810
// Address: 0x10004A00
extern const s32 cVsBattleItem;                             // 811
// Address: 0x10004A04
extern const s32 c32C;                                      // 812
// Address: 0x10004A08
extern const s32 c32D;                                      // 813
// Address: 0x10004A0C
extern const s32 c32E;                                      // 814
// Address: 0x10004A10
extern const s32 c32F;                                      // 815
// Address: 0x10004A14
extern const s32 c330;                                      // 816
// Address: 0x10004A18
extern const s32 c331;                                      // 817
// Address: 0x10004A1C
extern const s32 cKoopaJrFire;                              // 818
// Address: 0x10004A20
extern const s32 cKoopaJrBall;                              // 819
// Address: 0x10004A24
extern const s32 cUnderwaterKoopaJr;                        // 820
// Address: 0x10004A28
extern const s32 cUnderwaterKoopaJrClown;                   // 821
// Address: 0x10004A2C
extern const s32 cUnderwaterKoopaJrRetreatPos;              // 822
// Address: 0x10004A30
extern const s32 cBoxingKoopaJr;                            // 823
// Address: 0x10004A34
extern const s32 cBoxingKoopaJrPostBattleDemo;              // 824
// Address: 0x10004A38
extern const s32 cBoxingKoopaJrClownPostBattleDemo;         // 825
// Address: 0x10004A3C
extern const s32 cMiniGamePanelItem;                        // 826
// Address: 0x10004A40
extern const s32 cSlotItem;                                 // 827
// Address: 0x10004A44
extern const s32 cCoinmakiCannon;                           // 828
// Address: 0x10004A48
extern const s32 cCoinmakiItem;                             // 829
// Address: 0x10004A4C
extern const s32 cMiniGameKinopio;                          // 830
// Address: 0x10004A50
extern const s32 c33F;                                      // 831
// Address: 0x10004A54
extern const s32 c340;                                      // 832
// Address: 0x10004A58
extern const s32 c341;                                      // 833
// Address: 0x10004A5C
extern const s32 c342;                                      // 834
// Address: 0x10004A60
extern const s32 c343;                                      // 835
// Address: 0x10004A64
extern const s32 c344;                                      // 836
// Address: 0x10004A68
extern const s32 c345;                                      // 837
// Address: 0x10004A6C
extern const s32 c346;                                      // 838
// Address: 0x10004A70
extern const s32 c347;                                      // 839
// Address: 0x10004A74
extern const s32 cStaffCreditChibiYoshiABC;                 // 840
// Address: 0x10004A78
extern const s32 cStaffCreditChibiYoshiBalloon;             // 841
// Address: 0x10004A7C
extern const s32 cStaffCreditChibiYoshiBalloonCheer;        // 842
// Address: 0x10004A80
extern const s32 cStaffCreditChibiYoshiLight;               // 843
// Address: 0x10004A84
extern const s32 cStaffCreditChibiYoshiLightCheer;          // 844
// Address: 0x10004A88
extern const s32 cStaffCreditSoapABC;                       // 845
// Address: 0x10004A8C
extern const s32 cStaffCreditSoapCoin;                      // 846
// Address: 0x10004A90
extern const s32 cStaffCreditTottenKun;                     // 847
// Address: 0x10004A94
extern const s32 c350;                                      // 848
// Address: 0x10004A98
extern const s32 c351;                                      // 849
// Address: 0x10004A9C
extern const s32 c352;                                      // 850
// Address: 0x10004AA0
extern const s32 c353;                                      // 851
// Address: 0x10004AA4
extern const s32 cRealizeFeverStar;                         // 852
// Address: 0x10004AA8
extern const s32 cStar;                                     // 853
// Address: 0x10004AAC
extern const s32 cCourseSelectPlayer;                       // 854
// Address: 0x10004AB0
extern const s32 cCourseSelectPlayer2PSub;                  // 855 (CS Player 2, 3 or 4)
// Address: 0x10004AB4
extern const s32 cCourseSelectChibiYoshi;                   // 856
// Address: 0x10004AB8
extern const s32 cCourseSelectCamera;                       // 857
// Address: 0x10004ABC
extern const s32 cCourseSelectCastle;                       // 858
// Address: 0x10004AC0
extern const s32 cCourseSelectToride;                       // 859
// Address: 0x10004AC4
extern const s32 cCourseSelectKinokoHouse1up;               // 860
// Address: 0x10004AC8
extern const s32 cCourseSelectKinokoHouseShuffle;           // 861
// Address: 0x10004ACC
extern const s32 cCourseSelectKinokoHouseSlot;              // 862
// Address: 0x10004AD0
extern const s32 cCourseSelectPeachGates1st;                // 863
// Address: 0x10004AD4
extern const s32 cCourseSelectPeachGates2nd;                // 864
// Address: 0x10004AD8
extern const s32 cCourseSelectCoursePoint;                  // 865
// Address: 0x10004ADC
extern const s32 cCourseSelectWorldMoveDokan;               // 866
// Address: 0x10004AE0
extern const s32 cCourseSelectW8Cloud;                      // 867
// Address: 0x10004AE4
extern const s32 cCourseSelectGhost;                        // 868
// Address: 0x10004AE8
extern const s32 cCourseSelectW2Bros;                       // 869 (The Japanese Profile name says "Hammer Bros" LOL)
// Address: 0x10004AEC
extern const s32 cCourseSelectShipW1;                       // 870
// Address: 0x10004AF0
extern const s32 cCourseSelectShipW2;                       // 871
// Address: 0x10004AF4
extern const s32 cCourseSelectShipW3;                       // 872
// Address: 0x10004AF8
extern const s32 cCourseSelectShipW4;                       // 873
// Address: 0x10004AFC
extern const s32 cCourseSelectShipW5;                       // 874
// Address: 0x10004B00
extern const s32 cCourseSelectShipW6;                       // 875
// Address: 0x10004B04
extern const s32 cCourseSelectShipW7;                       // 876
// Address: 0x10004B08
extern const s32 cCourseSelectShipW8;                       // 877
// Address: 0x10004B0C
extern const s32 cCourseSelectShipW8Broken;                 // 878
// Address: 0x10004B10
extern const s32 cCourseSelectSurrender;                    // 879
// Address: 0x10004B14
extern const s32 cCourseSelectSwitchA;                      // 880
// Address: 0x10004B18
extern const s32 cCourseSelectSwitchB;                      // 881
// Address: 0x10004B1C
extern const s32 cCourseSelectTeresa;                       // 882
// Address: 0x10004B20
extern const s32 cCourseSelectOpeningKameck;                // 883
// Address: 0x10004B24
extern const s32 cCourseSelectTorideBoss;                   // 884
// Address: 0x10004B28
extern const s32 cCourseSelectPakkun;                       // 885
// Address: 0x10004B2C
extern const s32 cCourseSelectShadowFirstDemoKinopio;       // 886
// Address: 0x10004B30
extern const s32 cCourseSelectTobiPuku;                     // 887
// Address: 0x10004B34
extern const s32 cCourseSelectChorobon;                     // 888
// Address: 0x10004B38
extern const s32 cCourseSelectW7Item;                       // 889
// Address: 0x10004B3C
extern const s32 cCourseSelectW5Teresa;                     // 890
// Address: 0x10004B40
extern const s32 cCourseSelectFlag;                         // 891
// Address: 0x10004B44
extern const s32 cCourseSelectMusasabi;                     // 892
// Address: 0x10004B48
extern const s32 cCourseSelectWPillar;                      // 893
// Address: 0x10004B4C
extern const s32 cCourseSelectW7Bridge;                     // 894
// Address: 0x10004B50
extern const s32 cCourseSelectMiiBalloon;                   // 895
// Address: 0x10004B54
extern const s32 cCourseSelectPenguin;                      // 896
// Address: 0x10004B58
extern const s32 cCourseSelectW4Item;                       // 897
// Address: 0x10004B5C
extern const s32 cCourseSelectW2Kuribo;                     // 898
// Address: 0x10004B60
extern const s32 cCourseSelectPakkunBig;                    // 899
// Address: 0x10004B64
extern const s32 cCourseSelectShadowKunIcon;                // 900
// Address: 0x10004B68
extern const s32 cCourseSelectDekaUnira;                    // 901
// Address: 0x10004B6C
extern const s32 cCourseSelectTomb;                         // 902
// Address: 0x10004B70
extern const s32 cCourseSelectShadowFirstDemoShadowKun;     // 903
// Address: 0x10004B74
extern const s32 cCourseSelectKotsuCoaster;                 // 904
// Address: 0x10004B78
extern const s32 cCourseSelectKoopaJr;                      // 905
// Address: 0x10004B7C
extern const s32 cCourseSelectPeach;                        // 906
// Address: 0x10004B80
extern const s32 cCourseSelectW1Item;                       // 907
// Address: 0x10004B84
extern const s32 cCourseSelectStarGate;                     // 908
// Address: 0x10004B88
extern const s32 cCourseSelectEventAssistant;               // 909

}
