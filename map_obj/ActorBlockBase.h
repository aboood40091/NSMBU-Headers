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

protected:
    s32 execute_() override;
    s32 draw_() override;

public:
    void setFootSensor() override;
    void spawnItemUp() override;
    void spawnItemDown() override;
    void vf1CC() override;
    void vf1EC() override;

    bool vf2C4() override;

    virtual bool isActive();
    virtual void vf2DC();
    virtual u8 getContent();
    virtual void vf2EC();
    virtual sead::Vector3f getPosForSomething() const;
    virtual void executeBlock();
    virtual void destroy();
    virtual void destroy2();
    virtual void vf314();
    virtual void vf31C();
    virtual void vf324();
    virtual u32 vf32C();

    DECLARE_STATE_VIRTUAL_ID_BASE(ActorBlockBase, Wait)
    DECLARE_STATE_VIRTUAL_ID_BASE(ActorBlockBase, HitWait)

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
    u8      _1ccc;
    u8      _1ccd;
};
static_assert(sizeof(ActorBlockBase) == 0x1CD0);
