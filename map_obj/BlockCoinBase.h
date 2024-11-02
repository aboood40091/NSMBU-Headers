#pragma once

#include <actor/ActorState.h>
#include <collision/ActorBoxBgCollision.h>
#include <state/FStateVirtualID.h>

class BlockCoinBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(BlockCoinBase, ActorMultiState)

public:
    enum Content
    {
        cContent_FireMushroom = 0,
        cContent_MiniMushroom,
        cContent_LifeMushroom,
        cContent_Mushroom,
        cContent_FireFlower,        // Always a Fire Flower, even if player is small
        cContent_IceMushroom,
        cContent_PenguinMushroom,
        cContent_PropellerMushroom,
        cContent_Star,
        cContent_ContinuousStar,
        cContent_SquirrelMushroom,
        cContent_LifeMoon,
        cContent_Coin,
        cContent_MultiCoin,

        cContent_Vine = 15,
        cContent_Yoshi,
        cContent_Spring,

        cContent_MushroomIfSmall = 19,

        cContent_Empty = 21
    };

public:
    BlockCoinBase(const ActorCreateParam& param);
    virtual ~BlockCoinBase() { }

    void spawnJumpdai();
    void spawnYoshiEgg(bool multi);
    void spawnVine(u8);
    void spawnPowerup(const sead::Vector3f& pos, u32, u32, bool spawn_as_child);
    void spawnMultiPowerup(const sead::Vector3f& pos, u32, u32, bool spawn_as_child);
    void spawnPropellerOrCoin(const sead::Vector3f& pos, u32, u32, bool spawn_as_child);

    virtual void onUpMoveStart()
    {
    }

    virtual void onDownMoveStart()
    {
    }

    virtual void onDownMove_DiffStart()
    {
    }

    virtual void onUpMove()
    {
    }

    virtual void spawnItemUp()
    {
    }

    virtual void onDownMove()
    {
    }

    virtual void onDownMoveEnd()
    {
    }

    virtual void spawnItemDown()
    {
    }

    virtual void onDownMove_DiffEnd()
    {
    }

    virtual void vf1D4(s32);

    virtual u32 vf1DC()
    {
        return 0;
    }

    virtual void spawnCoinShower();

    virtual void onMove_Diff()  // For NSLU
    {
    }

    DECLARE_STATE_VIRTUAL_ID_BASE(BlockCoinBase, UpMove)
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockCoinBase, UpMoveEnd)
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockCoinBase, DownMove)
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockCoinBase, DownMoveEnd)
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockCoinBase, UpMove_Diff)
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockCoinBase, DownMove_Diff)
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockCoinBase, DownMove_DiffEnd)

    static void callbackFoot(BgCollision* self, ActorBgCollisionCheck* other);
    static void callbackHead(BgCollision* self, ActorBgCollisionCheck* other);
    static void callBackWall(BgCollision* self, ActorBgCollisionCheck* other, u8 direction);

    static void callbackFoot_Hit(BgCollision* self, ActorBgCollisionCheck* other);
    static void callbackHead_Hit(BgCollision* self, ActorBgCollisionCheck* other);
    static void callBackWall_Hit(BgCollision* self, ActorBgCollisionCheck* other, u8 direction);

    void updateBoxBgCollisionOfs()
    {
        mBoxBgCollision.setOfs(mBoxBgCollision_Ofs.p0, mBoxBgCollision_Ofs.p1);
    }

    void setBoxBgCollisionOfs(f32 left, f32 top, f32 right, f32 bottom)
    {
        mBoxBgCollision_Ofs.p0.set(left, top);
        mBoxBgCollision_Ofs.p1.set(right, bottom);
        updateBoxBgCollisionOfs();
    }

    void setBoxBgCollisionOfs(const sead::Vector2f& p0, const sead::Vector2f& p1)
    {
        mBoxBgCollision_Ofs.p0 = p0;
        mBoxBgCollision_Ofs.p1 = p1;
        updateBoxBgCollisionOfs();
    }

    const ActorBoxBgCollision& getBoxBgCollision() const
    {
        return mBoxBgCollision;
    }

    Content getBaseContent() const
    {
        return mContent;
    }

    u32 getSpawnDirection() const
    {
        return mSpawnDirection;
    }

    void setSpawnItemUp()
    {
        _1aae = 1;
        mSpawnDirection = DIRECTION_UP;
        spawnItemUp();
    }

protected:
    ActorBgCollisionCheck::Sensor   mHeadSensor;
  //u32                             _17d4[4 / sizeof(u32)]; // Alignment???
    ActorBoxBgCollision             mBoxBgCollision;
    struct
    {
        sead::Vector2f  p0;
        sead::Vector2f  p1;
    }                               mBoxBgCollision_Ofs;
    f32                             _1a78;
    f32                             _1a7c;
    f32                             _1a80;
    f32                             _1a84;
    f32                             _1a88;
    f32                             _1a8c;
    u32                             _1a90;
    u32                             _1a94;
    s32                             _1a98;
    u32                             _1a9c;
    u16                             _1aa0;
    u16                             _1aa2;
    u16                             _1aa4;
    u8                              _1aa6;
    u8                              _1aa7;
    s8                              _1aa8;
    s8                              _1aa9;
    u8                              _1aaa;
    u8                              _1aab;
    u8                              _1aac;
    u8                              _1aad;
    u8                              _1aae;
    u8                              _1aaf;
    u8                              _1ab0;
    u8                              _1ab1;
    u8                              mPlayerNo2;
    u8                              _1ab3;
    u32                             _1ab4;
    Content                         mContent;
    s32                             mHitPlayerNo;
    u32                             mSpawnDirection;
    u8                              _1ac4;
    u32                             _1ac8;
    bool                            mBlockHitNotBoundable;
    u8                              _1acd;
    u8                              _1ace;
    bool                            mNoAddScoreOnDestroy;
    f32                             _1ad0;
    f32                             _1ad4;
    f32                             _1ad8;
    u32                             _1adc;
    u32                             _1ae0;
    u32                             _1ae4;
    u32                             _1ae8;
    u32                             _1aec;
    sead::SafeArray<s8[12], 4>      _1af0;
    u8                              _1b20;
    u32                             _1b24;
};
static_assert(sizeof(BlockCoinBase) == 0x1B28);
