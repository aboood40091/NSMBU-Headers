#pragma once

#include <effect/EffectObj.h>
#include <utility/Angle.h>

#include <container/seadSafeArray.h>

class Actor;

class PropelParts
{
public:
    class Part
    {
    public:
        // Address: 0x020271B8
        Part();

    private:
        s32         mIndex;
        u32         _4;
        EffectObj   mEffectObj;
        s32         mPlayerNo;
        bool        mIsForPlayer;
        u8          _75;
    };
    static_assert(sizeof(Part) == 0x78);

    enum Mode
    {
        cMode_Num = 7
    };
    static_assert(sizeof(Mode) == 4);

public:
    // Address: 0x0202722C
    PropelParts();

    virtual ~PropelParts()
    {
    }

    // Address: 0x020272DC
    void create(Actor* p_owner);

    // Address: 0x02027790
    void setSpinEffect(const sead::Matrixf& mtx);

private:
    Actor*                      mpOwner;
    Mode                        mMode;
    Angle                       mRollSpeed;
    f32                         mScale;
    sead::SafeArray<Part, 3>    mParts;
};
static_assert(sizeof(PropelParts) == 0x17C);
