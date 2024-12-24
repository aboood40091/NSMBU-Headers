#pragma once

#include <actor/ActorState.h>
#include <sound/SndSceneMgr.h>
#include <state/FStateVirtualID.h>

class BossDemo : public ActorState  // vtbl Address: 0x10005FC0
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9F28
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9F2C
    SEAD_RTTI_OVERRIDE(BossDemo, ActorState)

public:
    // Address: 0x0202E448
    BossDemo(const ActorCreateParam& param);
    virtual ~BossDemo() { }

protected:
    // Address: 0x0202E4DC
    s32 create_() override;
    // Address: 0x0202E578
    s32 execute_() override;
    // Address: 0x0202E5A0
    s32 doDelete_() override;

public:
    // StateID_Ready            Address: 0x101F0AA0
    // initializeState_Ready    Address: 0x0202E6D4
    // executeState_Ready       Address: 0x0202E754
    // finalizeState_Ready      Address: 0x0202F780
    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, Ready)
    // StateID_BattleStDemo         Address: 0x101F0AC4
    // initializeState_BattleStDemo Address: 0x0202E758
    // executeState_BattleStDemo    Address: 0x0202E7D8
    // finalizeState_BattleStDemo   Address: 0x0202E948
    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, BattleStDemo)
    // StateID_BattleIn         Address: 0x101F0AE8
    // initializeState_BattleIn Address: 0x0202E9B8
    // executeState_BattleIn    Address: 0x0202EAD8
    // finalizeState_BattleIn   Address: 0x0202F784
    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, BattleIn)
    // StateID_BattleEdDemo         Address: 0x101F0B0C
    // initializeState_BattleEdDemo Address: 0x0202EB50
    // executeState_BattleEdDemo    Address: 0x0202EE6C
    // finalizeState_BattleEdDemo   Address: 0x0202F788
    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, BattleEdDemo)

    // Address: 0x0202F110
    virtual void vf1E4();   // Starts music?
    // Address: 0x0202F158
    virtual void vf1EC();   // Stops music?

    virtual bool checkBattleStDemo()
    {
        return false;
    }

    virtual bool checkBattleEdDemo()
    {
        return mIsBattleEdDemo;
    }

    virtual bool demoScroll()
    {
        return true;
    }

    virtual Actor* bossSearch()
    {
        return nullptr;
    }

    virtual void initialize()
    {
    }

    virtual void startClearFanfare() const
    {
        SndSceneMgr::instance()->startBossClearFanfare(SndSceneMgr::cBossClear_Toride);
    }

    void setBattleEdDemo()
    {
        mIsBattleEdDemo = true;
    }

    void setClear()
    {
        mIsClear = true;
    }

protected:
    // Address: 0x0202ED24
    void setCourseOutFaderPos_() const;

protected:
    u8              _17c8;
    u8              _17c9;
    bool            mIsBattleEdDemo;
    u8              mIsClear;
    u32             _17cc;
    u32             mBattleEdDemoState;
    ActorUniqueID   mBossID;
    u32             _17d8;
    bool            _17dc;
    u8              _17dd;
};
static_assert(sizeof(BossDemo) == 0x17E0);
