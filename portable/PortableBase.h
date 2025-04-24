#pragma once

#include <actor/ActorState.h>
#include <portable/PortableBase_InitStruct.h>
#include <os_types.h>

struct PortableBase_InitStruct;

class PortableBase : public ActorState // vtbl Address: 0x10106424
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x02AFA5E8
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x02AFA5F0
    SEAD_RTTI_OVERRIDE(DoorBase, Enemy);

public:

    // Address: 0x02721B68
    PortableBase(ActorCreateParam& param);
    // Address: 0x02722AE4
    virtual ~PortableBase(){}

protected:

    // Address: 0x02721D48
    s32 preExecute_()override;
    // Address: 0x02721E7C
    s32 postExecute_()override;
    // Address: 0x02721F04
    s32 doDelete_()override;

public:

    // Address: 0x027224AC
    virtual void damageFromUnder();
    // Address: 0x02721CDC
    void FUN_02721CDC();
    // Address: 0x02721DF4
    void FUN_02721DF4(const PortableBase_InitStruct& initStruct);
    // Address: 0x02721E38
    void FUN_02721E38(const PortableBase_InitStruct& struct, s32 param_3);
    // Address: 0x02722AD0
    virtual bool isSpinLiftUpEnable();
    // Address: 0x0272218C
    virtual void setSpinLiftUpActor(Actor* param_1);
    // Address: 0x02722ADC
    virtual void vf13C();
    // Address: 0x027224DC
    virtual void vf144();
    // Address: 0x0272243C
    virtual void vfAC(Actor* param_1, u32 param_2);

private:
    PortableBase_InitStruct          mInitStruct; 
    u32                              _17D8;
    f32                              _17DC;
    u32                              _17E0;
    u16[4]                           _17E4;
    f32[2]                           _17EC;
    u8                               _17F4; 
    u8                               _17F5;
    u8                               _17F6;
    u8                               _17F7;
    u32                              _17F8; 
};
static_assert(sizeof(PortableBase) == 0x17FC);