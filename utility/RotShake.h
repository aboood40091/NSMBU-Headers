#pragma once

#include <utility/Angle.h>

class RotShake
{
public:
    struct Arg
    {
        Angle   _0;
        Angle   _4;
        s32     _8;
        Angle   _c;
        Angle   _10;
        Angle   _14;
        Angle   _18;
        Angle   _1c;

        Arg(
            const Angle& field_0 = 0,
            const Angle& field_4 = 0,
            s32 field_8 = 32,
            const Angle& field_c = 0x00020000,
            const Angle& field_10 = 0x08000000,
            const Angle& field_14 = 0x00080000,
            const Angle& field_18 = 0x00800000,
            const Angle& field_1c = 0x00400000
        )
            : _0(field_0)
            , _4(field_4)
            , _8(field_8)
            , _c(field_c)
            , _10(field_10)
            , _14(field_14)
            , _18(field_18)
            , _1c(field_1c)
        {
        }
    };
    static_assert(sizeof(Arg) == 0x20);

public:
    RotShake()
        : mArg()
        , _20(false)
    {
    }

    // Address: 0x029E2CE8
    void init(const Arg& arg);

    Arg& getArg()
    {
        return mArg;
    }

    const Arg& getArg() const
    {
        return mArg;
    }

protected:
    Arg     mArg;
    bool    _20;
};
static_assert(sizeof(RotShake) == 0x24);
