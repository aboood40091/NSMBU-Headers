#pragma once

#include <collision/ActorCollisionTouchDrcCallback.h>
#include <map/UnitID.h>
#include <map_obj/BlockCoinBase.h>
#include <map_obj/ObjBgCollisionCullCheck.h>
#include <map_obj/ParentMovementMgr.h>

class ChangeBlockCoinBaseTouchDrcCB : public ActorCollisionTouchDrcCallback
{
public:
    bool bcSetTouchNormal(BgCollision* p_bg_collision, const sead::Vector2f& pos) override;
};
static_assert(sizeof(ChangeBlockCoinBaseTouchDrcCB) == 4);

class ChangeBlockCoinBase : public BlockCoinBase
{
    SEAD_RTTI_OVERRIDE(ChangeBlockCoinBase, BlockCoinBase)

public:
    ChangeBlockCoinBase(const ActorCreateParam& param);
    virtual ~ChangeBlockCoinBase() { }

    void spawnItemUp() override;
    void spawnItemDown() override;
    u32 vf1DC() override;

    virtual void vf29C()
    {
    }

    virtual void setTileFlag();

    virtual u32 vf2AC()
    {
        return 0;
    }

    virtual void vf2B4()
    {
    }

    virtual void vf2BC()
    {
    }

    // TODO: inline
    virtual bool vf2C4(); // Checks if current state is StateID_Wait or equivalent
    virtual void vf2CC();

    bool registerColliderActiveInfo();

protected:
    ActorBgCollisionCheck::Sensor   mFootSensor;
    sead::Vector3f                  mPosForState;
    ParentMovementMgr               mParentMovementMgr;
    ObjBgCollisionCullCheck         mColliderActiveInfo;
    sead::Vector2f                  mColliderActiveAreaSize;
    u32                             _1c68;
    u8                              _1c6c[4];
    UnitID                          mUnitID;
    ParentMovementType              mParentMovementType;
    u32                             mParentMovementID;
    u8                              _1c7c[0x1CA0 - 0x1C7C];
    ChangeBlockCoinBaseTouchDrcCB   mTouchDrcCallback;
    u8                              _1ca4[4];
};
static_assert(sizeof(ChangeBlockCoinBase) == 0x1CA8);
