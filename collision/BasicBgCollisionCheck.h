#pragma once

#include <collision/BgCollisionCheckType.h>
#include <system/LineNodeMgr.h>

#include <math/seadVector.h>
#include <prim/seadBitFlag.h>

class   Actor;
class   BgCollision;
struct  BgCollisionCheckParam;
struct  BgCollisionCheckResultArea;
struct  BgCollisionCheckResultPoint;
class   BgHitCheckCallback;
struct  BgUnitCode;

class BasicBgCollisionCheck
{
protected:
    // Address: 0x021A09A4
    const LineNodeMgr<BgCollision>& getActorBgCollisionList_() const;

    // Address: 0x021A09D8
    bool isMatching_(const BgUnitCode& bc_data) const;

    // Address: 0x021A0A44
    bool isConsider_(const BgCollision& bg_collision) const;

public:
    // Address: 0x021A0B8C
    BasicBgCollisionCheck();
    // Address: 0x021A0C44
    BasicBgCollisionCheck(const BgCollisionCheckParam& param);

    // Address: 0x021A0D04
    void initialize(const BgCollisionCheckParam& param);

    // Address: 0x021A0D40
    bool checkAreaUnit(BgCollisionCheckResultArea* p_res, const sead::Vector2f& p0, const sead::Vector2f& p1, u8 hit_dir_mask) const;
    // Address: 0x021A1184
    bool checkAreaActor(BgCollisionCheckResultArea* p_res, const sead::Vector2f& p0, const sead::Vector2f& p1, u8 hit_dir_mask) const;
    // Address: 0x021A13F0
    bool checkArea(BgCollisionCheckResultArea* p_res, const sead::Vector2f& p0, const sead::Vector2f& p1, u8 hit_dir_mask) const;

    // Address: 0x021A1610
    bool checkPointUnit(BgCollisionCheckResultPoint* p_res, const sead::Vector2f& p) const;
    // Address: 0x021A1828
    bool checkPointActor(BgCollisionCheckResultPoint* p_res, const sead::Vector2f& p) const;
    // Address: 0x021A1988
    bool checkPoint(BgCollisionCheckResultPoint* p_res, const sead::Vector2f& p) const;

    void setLayer(u8 layer)
    {
        mLayer = layer;
    }

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
