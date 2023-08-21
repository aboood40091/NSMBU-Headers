#pragma once

#include <collision/ActorLineBgCollision.h>
#include <collision/UnitTriangleBgCollision.h>
#include <collision/UnitQuadBgCollision.h>

#include <heap/seadDisposer.h>

class UnitBgCollisionHolder
{
    // createInstance()                             Address: 0x021B1014
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101C9650
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x021B1878
    // SingletonDisposer_::sStaticDisposer          Address: 0x101C9654
    // SingletonDisposer_::vtbl                     Address: 0x10042BB8
    SEAD_SINGLETON_DISPOSER(UnitBgCollisionHolder)

public:
    // Address: 0x021B0BD8
    UnitBgCollisionHolder();

    // Address: 0x021B1094
    void setFromBgUnit(const sead::Vector2f& pos, u8 layer, const sead::BitFlag8& collision_mask);
    // Address: 0x021B1438
    void setFromSlopeBottomBgUnit(const sead::Vector2f& pos, u8 layer, const sead::BitFlag8& collision_mask);
    // Address: 0x021B1690
    void setFromReverseSlopeTopBgUnit(const sead::Vector2f& pos, u8 layer, const sead::BitFlag8& collision_mask);

    BgCollision* getBgCollision() const
    {
        return mpBgCollision;
    }

protected:
    u8                      mLayer;
    sead::BitFlag8          mCollisionMask;
    s8                      _12;
    sead::Vector3f          mPos;
    BgCollision::InitArg    mInitArgLine;
    BgCollision::InitArg    mInitArgTriangle;
    BgCollision::InitArg    mInitArgQuad;
    ActorLineBgCollision    mLineBgCollision;
    UnitTriangleBgCollision mTriangleBgCollision;
    UnitQuadBgCollision     mQuadBgCollision;
    BgCollision*            mpBgCollision;
    u32                     _70C[4 / sizeof(u32)];
};
static_assert(sizeof(UnitBgCollisionHolder) == 0x710);
