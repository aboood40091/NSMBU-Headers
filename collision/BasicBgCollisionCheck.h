#pragma once

#include <collision/BgCollisionCheckType.h>

#include <math/seadVector.h>
#include <prim/seadBitFlag.h>

class Actor;
struct BgCollisionCheckParam;
struct BgCollisionCheckResult;
class BgHitCheckCallback;

class BasicBgCollisionCheck
{
public:
    // Address: 0x021A0B8C
    BasicBgCollisionCheck();
    // Address: 0x021A0C44
    BasicBgCollisionCheck(const BgCollisionCheckParam& param);

    // Address: 0x021A1184
    bool checkGround(BgCollisionCheckResult* p_res, const sead::Vector2f& p0, const sead::Vector2f& p1, u32);
    // Address: 0x021A13F0
    bool checkGroundAngle(BgCollisionCheckResult* p_res, const sead::Vector2f& p0, const sead::Vector2f& p1, u32);

private:
    u8                      _0;
    bool                    mIgnoreQuicksand;
    u8                      mLayer;
    sead::BitFlag8          mCollisionMask;
    BgCollisionCheckType    mType;
    Actor*                  mpActor;
    BgHitCheckCallback*     mpCallback;
    u32                     mIgnoreActor[(0x48 - 0x10) / sizeof(u32)]; // sead::FixedRingBuffer<Actor*, 10> mIgnoreActor; // Actors to ignore their BgCollision
    u32                     _48;
};
static_assert(sizeof(BasicBgCollisionCheck) == 0x4C);
