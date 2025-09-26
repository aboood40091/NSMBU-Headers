#pragma once

#include <actor/Actor.h>
#include <collision/PoleRopeBgCollision.h>

class TarzanIvyBase : public Actor  // vtbl Address: 0x1015682C
{
    static const s32 cNodeMax = 16;

    struct Unk1
    {
        u32     _0;
        Angle   _4;
        u32     _8;
        u32     _c;
        u32     _10;
        u32     _14;
        u32     _18;
        u32     _1c;

        Unk1()
            : _0(0)
          //, _4(0)
            , _8(0x20)
            , _c(0x20000)
            , _10(0x8000000)
            , _14(0x80000)
            , _18(0x800000)
            , _1c(0x400000)
        {
        }
    };
    static_assert(sizeof(Unk1) == 0x20);

    struct Unk2 : Unk1
    {
        u8  _20;

        Unk2()
            : _20(0)
        {
        }
    };
    static_assert(sizeof(Unk2) == 0x24);

    struct Unk3
    {
        Unk2    _0;
        f32     _24;
        f32     _28;
        u8      _2c;
        u8      player_no;
    };
    static_assert(sizeof(Unk3) == 0x30);

public:
    noinline TarzanIvyBase(const ActorCreateParam& param)
        : Actor(param)
    {
        _2c4 = 0;
    }

protected:
    virtual bool isKusari_() const
    {
        return false;
    }

    // Address: 0x0288F748
    virtual void createMdl_();

    // Address: 0x028907C8
    Result create_() override;
    // Address: 0x02890A74
    bool execute_() override;
    // Address: 0x02890C50
    bool draw_() override;

protected:
    u32                                 _27c[(0x2C4 - 0x27C) / sizeof(u32)];
    u32                                 _2c4;
    u32                                 _2c8[(0x2D8 - 0x2C8) / sizeof(u32)];
    PoleRopeBgCollision                 mRopeBgCollision;
    Unk2                                _490;
    u32                                 _4b4[(0x4F4 - 0x4B4) / sizeof(u32)];
    sead::UnsafeArray<Unk3,  cNodeMax>  _4f4;
    sead::UnsafeArray<Unk3*, cNodeMax>  _7f4;
    sead::Vector2f                      _834[17];                               // Unused
    f32                                 _8bc;
    sead::UnsafeArray<Angle, cNodeMax>  mNodeAngle;
    sead::UnsafeArray<Angle, 64>        _900;
    u32                                 _a00[(0xA08 - 0xA00) / sizeof(u32)];
};
static_assert(sizeof(TarzanIvyBase) == 0xA08);

class TarzanIvy : public TarzanIvyBase  // vtbl Address: 0x101565E8
{
public:
    TarzanIvy(const ActorCreateParam& param)
        : TarzanIvyBase(param)
    {
        _2c4 = 0;
    }
};
static_assert(sizeof(TarzanIvy) == sizeof(TarzanIvyBase));
