#pragma once

#include <actor/ActorState.h>
#include <state/FStateVirtualID.h>

class Yoshi;

class ItemBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(ItemBase, ActorMultiState)

public:
    ItemBase(const ActorCreateParam& param);
    virtual ~ItemBase();

    bool draw()override;

    void setPlayerNo(s8 ID)override;
    ActorBgCollisionCheck* getBgCheck()override;
    void setCarryFall(Actor*, s32)override;
    bool isSpinLiftUpEnable()override;
    void setSpinLiftUpActor(Actor* player)override;
    void vfC4()override;
    void vfCC()override;
    void allEnemyDeathEffSet()override;
    void waterSplashEffect(const sead::Vector3f& pos)override;
    void yoganSplashEffect(const sead::Vector3f& pos)override;
    void yoganWaveSplashEffect(const sead::Vector3f& pos)override;
    void poisonSplashEffect(const sead::Vector3f& pos)override;
    void blockHitInit_()override;

    void setWaterFunsui_(bool enable)override;
    void beginFunsui_()override;
    void endFunsui_(f32 speed_y)override;
    bool isFunsui_()const override;
    bool vf13C()override;
    void vf144(s32)override;
    
    bool setTouchDrcDamage_(const sead::Vector2f& pos)override;
    void setFunsuiPos_(sead::Vector2f dst)override;
    void setFunsuiSpeedY_(f32 speed)override;
    bool smokeDamageEnable_Yogan_(f32 surface_pos_y)override;
    bool smokeDamageEnable_Poison_(f32 surface_pos_y)override;
    void changeState(const StateID& state_id)override;

    virtual void vf18C();                       // nullsub
    virtual void playBlockReleaseUpAnim();      // nullsub
    virtual void playBlockReleaseDownAnim();    // nullsub
    virtual void playIdleAnim();                // nullsub
    virtual void playFloatAnim();               // nullsub
    virtual void vf1B4();                       // nullsub
    virtual void initHitboxes();
    virtual u32  vf1C4(); // Player collision
    virtual void vf1CC();
    virtual void vf1D4();
    virtual void vf1DC();
    virtual void vf1E4();
    virtual void vf1EC();
    virtual void vf1F4();
    virtual void vf1FC(); // nullsub
    virtual u32  vf204();

    DECLARE_STATE_VIRTUAL_ID_BASE(ItemBase, ItemBaseState12);
    DECLARE_STATE_VIRTUAL_ID_BASE(ItemBase, ItemBaseState13); // unknown state
    DECLARE_STATE_VIRTUAL_ID_BASE(ItemBase, ItemBaseState14); // unknown state
    DECLARE_STATE_VIRTUAL_ID_BASE(ItemBase, ItemBaseState15); // unknown state
    DECLARE_STATE_VIRTUAL_ID_BASE(ItemBase, ItemBaseState16); // unknown state
    DECLARE_STATE_VIRTUAL_ID_BASE(ItemBase, SpatByYoshi);

    DECLARE_STATE_ID(ItemBase, BlockReleaseUp);
    DECLARE_STATE_ID(ItemBase, BlockReleaseDown);
    DECLARE_STATE_ID(ItemBase, ItemBaseState3);          // unknown state
    DECLARE_STATE_ID(ItemBase, RingRewardRelease);
    DECLARE_STATE_ID(ItemBase, ItemBaseState5);          // unknown state
    DECLARE_STATE_ID(ItemBase, ItemBaseState6);          // unknown state
    DECLARE_STATE_ID(ItemBase, ItemBaseState7);          // unknown state
    DECLARE_STATE_ID(ItemBase, ItemBaseState8);          // unknown state
    DECLARE_STATE_ID(ItemBase, ItemBaseState9);          // unknown state
    DECLARE_STATE_ID(ItemBase, BeforeYoshiYongue);
    DECLARE_STATE_ID(ItemBase, InYoshiTongue);

    // Address: 0x02518470
    void spawnMethod();
    // Address: 0x02519130
    void spawnDustParticles();
    // Address: 0x02517F90
    void init();
    // Address: 0x02518A4C
    void updateModel();
    // Address: 0x02518F94
    void despawnRelated();
    // Address: 0x025183AC
    void setLogAndWigglerColToFalse();
    // Address: 025196E8
    void trySetPlayerPowerUp(void*, u32 PowerUp, u32);

    // Address: 0x02519580
    bool handleCollectResponse(u32, u32);

    Yoshi* getEatenByYoshi() const;

protected:
    u32 _17c8[(0x1A90 - 0x17C8) / sizeof(u32)];
};
static_assert(sizeof(ItemBase) == 0x1A90);
