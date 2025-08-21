#pragma once

#include <map_obj/ChangeBlockCoinBase.h>

class ActorBlockBase : public ChangeBlockCoinBase
{
    SEAD_RTTI_OVERRIDE(ActorBlockBase, ChangeBlockCoinBase)

public:
    enum Type
    {
        cType_Hatena = 0,
        cType_Renga,
        cType_Hit,
        cType_Clear
    };

public:
    ActorBlockBase(const ActorCreateParam& param);
    virtual ~ActorBlockBase() { }

    bool init(bool register_collider, bool);
    void initMover();

    Type getBlockType() const
    {
        return mType;
    }

    void forceSpawnItemUp(u8 player_no_2, s32 hit_player_no)
    {
        mPlayerNo2 = player_no_2;
        mHitPlayerNo = hit_player_no;
        mSpawnDirection = DIRECTION_UP;

        preSpawnItem();
        spawnItemUp();
    }

protected:
    bool execute_() override;
    bool draw_() override;

public:
    void onDownMove_DiffStart() override;
    void spawnItemUp() override;
    void spawnItemDown() override;
    void onDownMove_DiffEnd() override;
    void onMove_Diff() override;

    bool vf2C4() override;

    virtual bool isBlockActive();

    virtual void vf2DC()
    {
    }

    virtual u8 getContentIndex() const
    {
        return (mParam1 >> 28 & 1) << 4 | (mParam1 & 0xF);
    }

    virtual void preSpawnItem();

    virtual sead::Vector3f getItemCreatePos() const
    {
        return mPos;
    }

    virtual void executeBlock();
    virtual void destroy();
    virtual void destroy2();

    virtual void vf314()
    {
    }

    virtual void vf31C()
    {
    }

    virtual void vf324()
    {
    }

    virtual u32 vf32C()
    {
        return 0;
    }

    DECLARE_STATE_VIRTUAL_ID_BASE(ActorBlockBase, Wait)
    DECLARE_STATE_VIRTUAL_ID_BASE(ActorBlockBase, HitWait)

protected:
    void preSpawnItem_PropellerOrCoin_();

protected:
    f32     mItemCreateZPos;
    f32     mItemCreateAddYPosUp1;
    f32     mItemCreateAddYPosDown1;
    f32     mItemCreateAddYPosUp2;
    f32     mItemCreateAddYPosDown2;
    Type    mType;
    u32     _1cc0;
    u8      _1cc4;
    u8      _1cc5;
    u8      _1cc6;
    u32     _1cc8;
    bool    mScreenOutCheckEnable;      // Initialized to true
    u8      _1ccd;
};
static_assert(sizeof(ActorBlockBase) == 0x1CD0);
