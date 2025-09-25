#pragma once

#include <basis/seadTypes.h>

class BgUnitCode
{
public:
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

    enum TypeInfo
    {
        cTypeInfo_None,
        cTypeInfo_VineStop,
        cTypeInfo_Num
    };

    enum TypeOpt
    {
        cTypeOpt_None
    };

    enum HitType
    {
        cHitType_None           = 0,    // Collision is not solid
        cHitType_Full           = 1,    // Collision is completely solid                        (filled)
        cHitType_Half           = 2,    // Collision is solid on the outer surface              (line)
        cHitType_HalfCeiling    = 3,    // Collision is solid on the inner surface              (line)
        cHitType_HalfBoth       = 4     // Collision is solid on the outer and inner surfaces   (line, TODO: verify that this is valid)
    };

    enum SlipAttr
    {
        cSlipAttr_Normal        = 0,    // Player can slide while colliding when crouching
        cSlipAttr_Slip          = 1,    // Player instantly enters sliding state when colliding
        cSlipAttr_NoSlip        = 2,    // Player cannot slide while colliding
        cSlipAttr_IceLowSlip,
        cSlipAttr_SakaLowPow,
        cSlipAttr_SlideSlope,
        cSlipAttr_Unk6,
        cSlipAttr_Num
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
        cManta      = 8,    // Unused
        cPalmTree   = 9,
        cWood       = 10,
        cWater      = 11,
        cCarpet     = 12    // Now used for Beanstalk Leaf
    };

    static const u64 cPanelTypeMask         = 0x000000000000FFFF;
    static const u64 cPanelTypeInfoMask     = 0x0000000000FF0000;
    static const u64 cPanelTypeOptionMask   = 0x00000000FF000000;
    static const u64 cPanelHitTypeMask      = 0x0000000F00000000;
    static const u64 cPanelSlipAttrMask     = 0x000000F000000000;
    static const u64 cPanelAttrMask         = 0x0000FF0000000000;

    enum Shift
    {
        cShift_Type = 0,
        cShift_TypeInfo = 16,
        cShift_TypeOption = 24,
        cShift_HitType = 32,
        cShift_SlipAttr = 36,
        cShift_Attr = 40
    };

    static u64 makeBgUnitCode(
        HitType hit_type,
        Attr attr,
        SlipAttr slip_attr,
        Type type,
        TypeInfo type_info,
        TypeOpt type_option)
    {
        u64 data = 0;
        setHitType(data, hit_type);
        setAttr(data, attr);
        setSlipAttr(data, slip_attr);
        setType(data, type);
        setTypeInfo(data, type_info);
        setTypeOption(data, type_option);
        return data;
    }

    static Type getType(u64 data)
    {
        return Type((data & cPanelTypeMask) >> cShift_Type);
    }

    static void setType(u64& data, Type type)
    {
        data &= ~cPanelTypeMask;
        data |= (u64(type) << cShift_Type) & cPanelTypeMask;
    }

    static TypeInfo getTypeInfo(u64 data)
    {
        return TypeInfo((data & cPanelTypeInfoMask) >> cShift_TypeInfo);
    }

    static void setTypeInfo(u64& data, TypeInfo type_info)
    {
        data &= ~cPanelTypeInfoMask;
        data |= (u64(type_info) << cShift_TypeInfo) & cPanelTypeInfoMask;
    }

    static TypeOpt getTypeOption(u64 data)
    {
        return TypeOpt((data & cPanelTypeOptionMask) >> cShift_TypeOption);
    }

    static void setTypeOption(u64& data, TypeOpt type_option)
    {
        data &= ~cPanelTypeOptionMask;
        data |= (u64(type_option) << cShift_TypeOption) & cPanelTypeOptionMask;
    }

    static HitType getHitType(u64 data)
    {
        return HitType((data & cPanelHitTypeMask) >> cShift_HitType);
    }

    static void setHitType(u64& data, HitType hit_type)
    {
        data &= ~cPanelHitTypeMask;
        data |= (u64(hit_type) << cShift_HitType) & cPanelHitTypeMask;
    }

    static SlipAttr getSlipAttr(u64 data)
    {
        return SlipAttr((data & cPanelSlipAttrMask) >> cShift_SlipAttr);
    }

    static void setSlipAttr(u64& data, SlipAttr slip_attr)
    {
        data &= ~cPanelSlipAttrMask;
        data |= (u64(slip_attr) << cShift_SlipAttr) & cPanelSlipAttrMask;
    }

    static Attr getAttr(u64 data)
    {
        return Attr((data & cPanelAttrMask) >> cShift_Attr);
    }

    static void setAttr(u64& data, Attr attr)
    {
        data &= ~cPanelAttrMask;
        data |= (u64(attr) << cShift_Attr) & cPanelAttrMask;
    }

    // -------------------------------------

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
        cTypeInfo_Dokan_0,          // Vert. Top Entrance Left
        cTypeInfo_Dokan_1,          // Vert. Top Entrance Right
        cTypeInfo_Dokan_2,          // Vert. Bottom Entrance Left
        cTypeInfo_Dokan_3,          // Vert. Bottom Entrance Right
        cTypeInfo_Dokan_4,          // Horiz. Left Entrance Top
        cTypeInfo_Dokan_5,          // Horiz. Left Entrance Bottom
        cTypeInfo_Dokan_6,          // Horiz. Right Entrance Top
        cTypeInfo_Dokan_7,          // Horiz. Right Entrance Bottom
        cTypeInfo_Dokan_Mame0,      // Vert. Mini Pipe Top
        cTypeInfo_Dokan_Mame1,      // Vert. Mini Pipe Bottom
        cTypeInfo_Dokan_Mame2,      // Horiz. Mini Pipe Left
        cTypeInfo_Dokan_Mame3,      // Horiz. Mini Pipe Right
        cTypeInfo_Dokan_Pipe0,      // Vert. Center Left
        cTypeInfo_Dokan_Pipe1,      // Vert. Center Right
        cTypeInfo_Dokan_Pipe2,      // Vert. Intersection Left
        cTypeInfo_Dokan_Pipe3,      // Vert. Intersection Right
        cTypeInfo_Dokan_Pipe4,      // Horiz. Center Top
        cTypeInfo_Dokan_Pipe5,      // Horiz. Center Bottom
        cTypeInfo_Dokan_Pipe6,      // Horiz. Intersection Top
        cTypeInfo_Dokan_Pipe7,      // Horiz. Intersection Bottom
        cTypeInfo_Dokan_Pipe8,
        cTypeInfo_Dokan_Pipe9,
        cTypeInfo_Dokan_PipeB,
        cTypeInfo_Dokan_MamePipe0,  // Vert. Mini Pipe Center
        cTypeInfo_Dokan_MamePipe1,  // Horiz. Mini Pipe Center
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
        cTypeInfo_Dokan_Tunagi,     // Pipe Joint
        cTypeInfo_Dokan_MamePipe2,  // Vert. Mini Pipe Intersection
        cTypeInfo_Dokan_MamePipe3,  // Horiz. Mini Pipe Intersection
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

    enum TypeOpt_DokanColor
    {
        cTypeOpt_DokanColor_Green,
        cTypeOpt_DokanColor_Red,
        cTypeOpt_DokanColor_Yellow,
        cTypeOpt_DokanColor_Blue,
        cTypeOpt_DokanColor_Num
    };
};
