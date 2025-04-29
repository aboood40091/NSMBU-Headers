#pragma once

#include <actor/ActorState.h>
#include <player/PlayerEnum.h>
#include <state/FStateStateMgr.h>
#include <state/FStateVirtualID.h>
#include <enemy/EnemyEatData.h>
#include <enemy/EnemyActorScaler.h>

class Yoshi;
class AnimModel;
class TexturePatternAnimation;
class ActorCollisionCheck;
class EffectDisposable;

class ItemBase : public ActorMultiState //vtabl Address: 0x100A0A1C 
{
    SEAD_RTTI_OVERRIDE(ItemBase, ActorMultiState);

public:
    // Address: 0x02518C70
    void CollisionCallback(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other)override;
public:
    // Address: 0x02517448
    ItemBase(const ActorCreateParam& param);
private:
    // Address: 0x025176EC
    s32 draw_()override;

public:
    // Address: 0x02517A84
    virtual void addActiveCollider();
    // Address: 0x0251AB48
    void checkParentIsFlyingQBlockSpawner();
    // Address: 0x0251A69C
    bool checkTilesUnder();
    // Address: 0x02519b14
    bool collideWithLavaOrPoison();
    // Address: 0x02519920
    bool collideWithWaterMaybe();
    // Address: 0x0251AD6C
    void deleteIfhasParent();
    // Address: 0x0251DA88
    virtual void doStateChange();
    // Address: 0x0251A990
    Yoshi* getEatenbyYoshi()const;
    // Address: 0x025183BC
    f64 getZPosToUse();
    // Address: 0x0251784C
    virtual void initActiveColliders();
    // Address: 0x0251A964
    bool isNotCollectedByPlayer();
    // Address: 02517BD0
    virtual bool killAtGoal();
    // Address: 0x02517C7C
    void makeItemGoPoof();
    // Address: 0x0251A22C
    bool makeItemGoPoofIfNeeded();
    // Address: 0x02519580
    bool onItemCollectedTwice(u32, u32);
    // Address: 0x02518290
    void posMove();
    // Address: 0x02517908
    virtual void setAboveSensor();
    // Address: 0x02517A40
    virtual void setAboveSensor2();
    // Address: 0x02517950
    virtual void setAdjacentSensors();
    // Address: 0x02519494
    void setAnimSpeedDependingOnDirection();
    // Address: 0x025178C0
    virtual void setBelowSensor();
    // Address: 0x025196E8
    bool setPowerupState(void*, PlayerMode , u32);
    // Address: 0x025183F8
    void setRegularMovementState();
    // Address: 0x02517D5C
    virtual void splashLava();
    // Address: 0x02517E18
    virtual void splashlavaWave();
    // Address: 0x02517ED4
    virtual void splashPoison();
    // Address: 0x02517C20
    virtual void splashWater();
    // Address: 0x02518A4C
    void updateModel();
    // Address: 0x0251ABF4
    void updatePosForParentBlock(u32);
    // Address: 0x0251771C
    virtual void vf144();

    // StateID_DropMove             Address: 0x1020AA1C
    // initializeState_DropMove     Address: 0x0251B060
    // executeState_DropMove        Address: 0x0251A2D4
    // finalizeState_DropMove       Address: 0x0251DC94
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(ItemBase, DropMove);
    // StateID_EggCreateUp          Address: Unk
    // initializeState_EggCreateUp  Address: 0x0251C424
    // executeState_EggCreateUp     Address: 0x0251C530
    // finalizeState_EggCreateUp    Address: 0x0251DCA4
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(ItemBase, EggCreateUp);
    // StateID_DownMove             Address: 0x1020A9FC
    // initializeState_DownMove     Address: 0x0251AFA8
    // executeState_DownMove        Address: 0x0251B060
    // finalizeState_DownMove       Address: 0x0251DC54
    DECLARE_STATE_ID(ItemBase, DownMove);
    // StateID_RedCoinFlash         Address: 0x1020AA3C
    // initializeState_RedCoinFlash Address: 0x0251B168
    // executeState_RedCoinFlash    Address: 0x0251B1D8
    // finalizeState_RedCoinFlash   Address: 0x0251DC64
    DECLARE_STATE_ID(ItemBase, RedCoinFlash);
    // StateID_UpMove               Address: 0x1020A9DC
    // initializeState_UpMove       Address: 0x0251AD90
    // executeState_UpMove          Address: 0x0251AE48
    // finalizeState_UpMove         Address: 0x0251DC50
    DECLARE_STATE_ID(ItemBase, UpMove);
    // StateID_Wait                 Address: 0x1020AA7C
    // initializeState_Wait         Address: 0x0251B2E8
    // executeState_Wait            Address: 0x0251B368
    // finalizeState_Wait           Address: 0x0251DC70
    DECLARE_STATE_ID(ItemBase, WaitMove);
protected:
    sead::Vector2f                      _17C8;
    sead::Vector3f                      mPosition2;
    sead::Vector3f                      mEffPosition;
    u32                                 _17E8[(24 / sizeof(u32))]; // 0x17E8-0x17FF
    AnimModel*                          mAnimModel;
    TexturePatternAnimation*            mTexturePatternAnimation;
    u8[4]                               PowerUpType;
    u32                                 _180C; 
    u32                                 mAnimIDX;
    u32                                 _1814;
    u32                                 mUnkPlayerID;
    u32[2]                              _181C; // 0x181C-0x1820
    u8[3]                               _1824; // 0x1824-0x1826
    bool                                mOnCreateCalled;
    bool                                mCollidedWithLog;
    u8[3]                               _1829; // 0x1829-0x182B
    u32                                 _182C;
    s32                                  mCollidingPlayerID;
    u32[9]                              _1834; // 0x1834-0x1854
    u16                                 _1858;
    s8                                  mYoshiEatenPlayerId;
    u8                                  _185B;
    u16                                 _185C;
    u8                                  _185E;
    bool                                mCollidedWithGiantWiggler;
    u8[4]                               _1861; // 0x1860-0x1863
    EnemyEatData                        mEatData;
    u8[4]                               _1888; // 0x1888-0x188B
    EnemyActorScaler                    mScaler;
    ActorCollisionCheck*                mACollider2;
    u8[4]                               _19D4; // 0x19D4-0x19D7
    f32[2]                              _19D8;
    u32                                 _19E8;
    f32[3]                              _19E4; //0x19E4-0x19EC
    u32                                 _19F0;
    u8[4]                               _19F4; //0x19F4-0x19F7
    u32[4]                              _19F8; //0x19F8-0x1A00
    EffectDisposable                    mEffect; // Ig
    u32                                 _1A6C;
    u8[4]                               _1A70; // 0x1A70-0x1A73
    u32                                 mSetTo0IfNoParent;
    u8[2]                               _1A7C; // 0x1A7C-0x1A7D
    bool                                mParentIsFlyingQBlockSpawner;
    u8                                  _1A7F;
    sead::Vector3f                      _1A80;
    u32                                 mFuncPointer; // Placeholder cause I dont know the Datatype
};
static_assert(sizeof(ItemBase) == 0x1A90);
