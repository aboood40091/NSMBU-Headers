#pragma once

#include <enemy/Enemy.h>

class AnimModel;

class DoorBase : public Enemy  // vtbl Address: 0x1010E7D0
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x02AFA5E8
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x02AFA5F0
    SEAD_RTTI_OVERRIDE(DoorBase, Enemy);
public:
    // Address:0x027583F0
    DoorBase(const ActorCreateParam& param);
    // Address:0x02759534
    virtual ~DoorBase() { }

protected:
    // Address: 0x02758540
    s32 create_() override;
    // Address: 0x027587C4
    s32 draw_() override;
    // Address: 0x02758778
    s32 execute_() override;

public:
/*
    // Address: 0x02758804
    virtual void FUN_02758804();
    // Address: 02758814
    virtual void FUN_02758814();
    // Address: 0x02758860
    virtual void FUN_02758860();
    // Address: 0x0275893C
    virtual void FUN_0275893C();
    // Address: 0x02758948
    virtual void FUN_02758948();
    // Address: 0x02758988
    virtual void FUN_02758988();
    // Address: 0x02758A2C
    virtual void FUN_02758A2C();
    // Address: 0x02758A48
    virtual void FUN_02758A48();
    // Address: 0x02758AC8
    virtual void FUN_02758AC8();
    // Address: 0x02758B90
    virtual void FUN_02758B90();
    // Address: 0x027595AC
    virtual bool FUN_027595AC();
    // Address: 0x02759638
    virtual void FUN_02759638();
    // Address: 0x0275969C
    virtual void FUN_0275969C();*/
    
    // Address: 0x02758470
    void updateModel();
    // Address: 0x027586D0
    void updateModel2();

protected:
    AnimModel*  mAnimModel; 
    u8          _1884;
    u8          _1885;
    u8          _1886;
    u8          _1887;
    u32         _1888;
    u8          _188C;
    u8          _188D;
    u8          _188E;
    u8          _188F;
    u32         _1890;
    u32         _1894;
    bool        mDrawModel;
    u8          _1899;
    u8          _189A;
    u8          _189B;      
    u8          _189C;
    u8          _189D;
    u8          _189E;
    u8          _189F;
    u32         _18A0;
    u32         _18A4;
};
static_assert(sizeof(DoorBase) == 0x18A8);
