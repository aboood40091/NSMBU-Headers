#pragma once

#include <basis/seadTypes.h>

struct BgUnitCode
{
    u64 mData;  // HitType == 1: Ignore active camera

    enum Type
    {
        // ---------- Common ---------- //

        cType_None                  = 0,
        cType_SenLift               = 1,
        cType_WakuCoin              = 2,
        cType_Coin                  = 3,
        cType_ClearCoin             = 4,
        cType_Block                 = 5,
        cType_BreakBlock            = 6,
        cType_Q_Block               = 7,
        cType_TensenBlock           = 8,
        cType_QuarterBlock          = 9,
        Clear_Q_Block               = 10,
        cType_Saka                  = 11,
        cType_Tenjou                = 12,
        cType_Water                 = 13,
        cType_Vine                  = 14,   // Vine, Fence and Climbable wall with ledge
        cType_Damage                = 15,
        cType_Dokan                 = 16,
        cType_BeltConveyor          = 17,
        cType_Chikuwa               = 18,
        cType_CaveEnter             = 19,
        cType_Kani                  = 20,
        cType_Hold                  = 21,
        cType_Pole                  = 22,

        // ------ Game--specific ------ //

        cType_PoleRope              = 23,   // Swinging chain/vine and Rope ladder
        cType_BreakIce              = 24,
        cType_MouseHole             = 25,
        cType_WaterStream           = 26,
        cType_Manta                 = 27,
        cType_PalmTree              = 28,
        cType_WoodBarrel            = 29,
        cType_TrplnCloud            = 30,
        cType_DrcBlock              = 31,
        cType_AirshipHand           = 32,
        cType_WaterGeyser           = 33,
        cType_BigBreakBlock         = 34,
        cType_Big_Q_Block           = 35,
        cType_BigBlock              = 36,
        cType_RemoconBalanceRideOff = 37,
        cType_LineTrain             = 38,
        cType_Unira                 = 39
    };

    enum HitType
    {
        cHitType_None           = 0,    // Collision is not solid
        cHitType_Full           = 1,    // Collision is completely solid                        (filled)
        cHitType_Half           = 2,    // Collision is solid on the outer surface              (line)
        cHitType_HalfCeiling    = 3,    // Collision is solid on the inner surface              (line)
        cHitType_HalfBoth       = 4     // Collision is solid on the outer and inner surfaces   (line, TODO: verify that this is valid)
    };

    Type getType() const
    {
        return Type(mData & 0xFFFF);
    }

    u8 getTypeInfo() const
    {
        return (mData >> 16) & 0xFF;
    }

    u8 getTypeOption() const
    {
        return (mData >> 24) & 0xFF;
    }

    HitType getHitType() const
    {
        return HitType((mData >> 32) & 0xF);
    }

    // -------------------------------------

    enum SlipAttr
    {
        cSlipAttr_Normal    = 0,    // Player can slide while colliding when crouching
        cSlipAttr_Slip      = 1,    // Player instantly enters sliding state when colliding
        cSlipAttr_NoSlip    = 2     // Player cannot slide while colliding
    };

    enum Attr
    {
        cNone       = 0,
        cIce        = 1,
        cSnow       = 2,
        cNuma       = 3,
        cSand       = 4,
        cGrass      = 5,
        cCloud      = 6,
        cBeachSand  = 7,    // Unused
        cCarpet     = 8,    // Unused
        cPalmTree   = 9,
        cWood       = 10,
        cWater      = 11,
        cManta      = 12    // Now used for Beanstalk Leaf
    };

    SlipAttr getSlipAttr() const
    {
        return SlipAttr((mData >> 36) & 0xF);
    }

    Attr getAttr() const
    {
        return Attr((mData >> 40) & 0xFF);
    }

    // -------------------------------------

    enum TypeInfo
    {
        cTypeInfo_None,
        cTypeInfo_VineStop,
        cTypeInfo_Num
    };

    enum TypeInfo_WakuCoin
    {
        cTypeInfo_WakuCoin_Normal,
        TypeInfo_WakuCoin_Multi,
        cTypeInfo_WakuCoin_Num
    };

    enum TypeInfo_Coin
    {
        cTypeInfo_Coin_Yellow,
        cTypeInfo_Coin_Red,
        cTypeInfo_Coin_Blue,
        cTypeInfo_CoinNum
    };

    enum TypeInfo_ClearCoin
    {
        cTypeInfo_ClearCoin_Blue,
        cTypeInfo_ClearCoin_Num,
    };

    enum TypeInfo_Block
    {
        cTypeInfo_Block_Brown,
        cTypeInfo_Block_Stone,
        cTypeInfo_Block_Wood,
        cTypeInfo_Block_Red,
        cTypeInfo_Block_Num
    };

    enum TypeInfo_TensenBlock
    {
        cTypeInfo_TensenBlock_0,
        cTypeInfo_TensenBlock_1,
        cTypeInfo_TensenBlock_Num
    };

    enum TypeInfo_Saka
    {
        cTypeInfo_Saka_00,
        cTypeInfo_Saka_01,
        cTypeInfo_Saka_02,
        cTypeInfo_Saka_03,
        cTypeInfo_Saka_04,
        cTypeInfo_Saka_05,
        cTypeInfo_Saka_06,
        cTypeInfo_Saka_07,
        cTypeInfo_Saka_08,
        cTypeInfo_Saka_09,
        cTypeInfo_Saka_0A,
        cTypeInfo_Saka_0B,
        cTypeInfo_Saka_0C,
        cTypeInfo_Saka_0D,
        cTypeInfo_Saka_0E,
        cTypeInfo_Saka_0F,
        cTypeInfo_Saka_10,
        cTypeInfo_Saka_11,
        cTypeInfo_Saka_12,
        cTypeInfo_Saka_Num
    };

    enum TypeInfo_Tenjou
    {
        cTypeInfo_Tenjou_00,
        cTypeInfo_Tenjou_01,
        cTypeInfo_Tenjou_02,
        cTypeInfo_Tenjou_03,
        cTypeInfo_Tenjou_04,
        cTypeInfo_Tenjou_05,
        cTypeInfo_Tenjou_06,
        cTypeInfo_Tenjou_07,
        cTypeInfo_Tenjou_08,
        cTypeInfo_Tenjou_09,
        cTypeInfo_Tenjou_0A,
        cTypeInfo_Tenjou_0B,
        cTypeInfo_Tenjou_0C,
        cTypeInfo_Tenjou_0D,
        cTypeInfo_Tenjou_0E,
        cTypeInfo_Tenjou_0F,
        cTypeInfo_Tenjou_10,
        cTypeInfo_Tenjou_11,
        cTypeInfo_Tenjou_12,
        cTypeInfo_Tenjou_Num
    };

    enum TypeInfo_Water
    {
        cTypeInfo_Water_Normal,
        cTypeInfo_Water_Air,
        cTypeInfo_Water_Lava,
        cTypeInfo_Water_Doku,
        cTypeInfo_Water_Numa,
        cTypeInfo_Water_Num
    };

    enum TypeInfo_Damage
    {
        cTypeInfo_Damage_Turara00,
        cTypeInfo_Damage_Turara10,
        cTypeInfo_Damage_Turara11,
        cTypeInfo_Damage_Left,
        cTypeInfo_Damage_Right,
        cTypeInfo_Damage_Top,
        cTypeInfo_Damage_Bottom,
        cTypeInfo_Damage_Die,
        cTypeInfo_Damage_Lava,
        cTypeInfo_Damage_Doku,
        cTypeInfo_Damage_Num
    };

    enum TypeInfo_Dokan
    {
        cTypeInfo_Dokan_0,
        cTypeInfo_Dokan_1,
        cTypeInfo_Dokan_2,
        cTypeInfo_Dokan_3,
        cTypeInfo_Dokan_4,
        cTypeInfo_Dokan_5,
        cTypeInfo_Dokan_6,
        cTypeInfo_Dokan_7,
        cTypeInfo_Dokan_Mame0,
        cTypeInfo_Dokan_Mame1,
        cTypeInfo_Dokan_Mame2,
        cTypeInfo_Dokan_Mame3,
        cTypeInfo_Dokan_Pipe0,
        cTypeInfo_Dokan_Pipe1,
        cTypeInfo_Dokan_Pipe2,
        cTypeInfo_Dokan_Pipe3,
        cTypeInfo_Dokan_Pipe4,
        cTypeInfo_Dokan_Pipe5,
        cTypeInfo_Dokan_Pipe6,
        cTypeInfo_Dokan_Pipe7,
        cTypeInfo_Dokan_Pipe8,
        cTypeInfo_Dokan_Pipe9,
        cTypeInfo_Dokan_PipeB,
        cTypeInfo_Dokan_MamePipe0,
        cTypeInfo_Dokan_MamePipe1,
        cTypeInfo_Dokan_Break0,
        cTypeInfo_Dokan_Break1,
        cTypeInfo_Dokan_Break2,
        cTypeInfo_Dokan_Break3,
        cTypeInfo_Dokan_Break4,
        cTypeInfo_Dokan_Break5,
        cTypeInfo_Dokan_Break6,
        cTypeInfo_Dokan_Break7,
        cTypeInfo_Dokan_MameBreak0,
        cTypeInfo_Dokan_MameBreak1,
        cTypeInfo_Dokan_Tunagi,
        cTypeInfo_Dokan_MamePipe2,
        cTypeInfo_Dokan_MamePipe3,
        cTypeInfo_Dokan_Num
    };

    enum TypeInfo_Chikuwa
    {
        cTypeInfo_Chikuwa_Normal,
        cTypeInfo_Chikuwa_Num
    };

    enum TypeInfo_BeltConveyor
    {
        cTypeInfo_BeltConveyor_Left,
        cTypeInfo_BeltConveyor_Right,
        cTypeInfo_BeltConveyor_Left_High,
        cTypeInfo_BeltConveyor_Right_High,
        cTypeInfo_BeltConveyor_Num
    };

    enum TypeInfo_SenLift
    {
        // TODO
        cTypeInfo_SenLift_Yoko = 4,
        cTypeInfo_SenLift_Tate,
        cTypeInfo_SenLift_Nuki = 32,
        cTypeInfo_SenLift_Num
    };

    enum TypeOpt
    {
        cTypeOpt_None
    };

    enum TypeOpt_DokanColor
    {
        cTypeOpt_DokanColor_Green,
        cTypeOpt_DokanColor_Red,
        cTypeOpt_DokanColor_Yellow,
        cTypeOpt_DokanColor_Blue,
        cTypeOpt_DokanColor_Num
    };
};
static_assert(sizeof(BgUnitCode) == 8);
