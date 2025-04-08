#pragma once

#include <actor/ActorState.h>
#include <actor/Profile.h>
#include <collision/ActorBoxBgCollision.h>

class AnimModel;

class KillerHoudai : public ActorState  // vtbl Address: 0x1008C448
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EAAE8
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EAAEC
    SEAD_RTTI_OVERRIDE(KillerHoudai, ActorState)

public:
    // Address: 0x1008C03C
    static const ActorCreateInfo cActorCreateInfo;
    // Address: 0x1008C060
    static const ActorCreateInfo cActorCreateInfoMagnum;

public:
    // Address: 0x023BCC74
    KillerHoudai(const ActorCreateParam& param);
    virtual ~KillerHoudai() { }

protected:
    // Address: 0x023BE448
    s32 create_() override;
    // Address: 0x023BEEAc
    s32 execute_() override;
    // Address: 0x023BF214
    s32 draw_() override;
    // Address: 0x023BF2C4
    s32 doDelete_() override;

    // Address: 0x023BFBF8
    virtual void createMdlMag_();

    // Address: 0x023BF418
    bool tryShoot_() const;

protected:
    AnimModel*                          mpAnimModelA;
    AnimModel*                          mpAnimModelB;
    sead::SafeArray<AnimModel*, 16>     mpAnimModelC;
    ActorBoxBgCollision                 mBoxBgCollision;
    u32                                 _1aa0[0x50 / sizeof(u32)];
    sead::Vector3f                      _1af0;
    sead::Vector3f                      _1afc;
    sead::Vector3f                      _1b08;
    u32                                 _1b14[0xC0 / sizeof(u32)];
    sead::Vector3f                      _1bd4;
    sead::Vector3f                      _1be0;
    u32                                 _1bec[0xC0 / sizeof(u32)];
    u32                                 _1cac;
    u32                                 _1cb0;
    u32                                 _1cb4;
    u32                                 _1cb8;
    u32                                 _1cbc;
    u32                                 _1cc0;
    u32                                 _1cc4[0xC0 / sizeof(u32)];
    sead::Vector3f                      _1d84;
    sead::Vector3f                      _1d90;
    sead::Vector3f                      _1d9c;
    sead::Vector3f                      _1da8;
    f32                                 _1db4;
    f32                                 _1db8;
    f32                                 _1dbc;
    f32                                 _1dc0;
    f32                                 _1dc4;
    u32                                 _1dc8;
    u32                                 _1dcc;
    u32                                 _1dd0;
    u32                                 _1dd4;
    u32                                 _1dd8;
    u32                                 mShotCountDown;
    u32                                 _1de0;
    u32                                 _1de4;
    u32                                 _1de8;
    u32                                 _1dec;
    u8                                  _1df0;
    u8                                  _1df1;
    u8                                  _1df2;
    u8                                  _1df3;
    u32                                 _1df4;
};
static_assert(sizeof(KillerHoudai) == 0x1DF8);
