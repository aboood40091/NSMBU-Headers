#pragma once

#include <actor/AttentionMgr.h>
#include <collision/ActorCollisionCheckMgr.h>
#include <collision/ActorCollisionTouchDrcCallback.h>
#include <enemy/Enemy.h>
#include <enemy/EnemyActorScaler.h>

class BossTouchDrcCB : public ActorCollisionTouchDrcCallback    // vtbl Address: 0x10005E2C
{
public:
    // Address: 0x0202b8c0
    bool ccSetTouchNormal(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) override;
};
static_assert(sizeof(BossTouchDrcCB) == sizeof(ActorCollisionTouchDrcCallback));

class Boss : public Enemy   // vtbl Address: 0x1000562C
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9F20
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9F24
    SEAD_RTTI_OVERRIDE(Boss, Enemy)

public:
    // Address: 0x0202B968
    Boss(const ActorCreateParam& param);

protected:
    // Address: 0x0202BB68
    Result create_() override;
    // Address: 0x0202BD0C
    bool preExecute_() override;
    // Address: 0x0202BDDC
    void postExecute_(MainState state) override;

    Result doDelete_() override
    {
        AttentionMgr::instance()->release(mAttentionLookat);
        ActorCollisionCheckMgr::instance()->release(mCollisionCheckDrcTouch);
        return cResult_Success;
    }

    void removeCollisionCheck() override
    {
        ActorCollisionCheckMgr::instance()->release(mCollisionCheck);
        ActorCollisionCheckMgr::instance()->release(mCollisionCheckDrcTouch);
    }

    void reviveCollisionCheck() override
    {
        ActorCollisionCheckMgr::instance()->entry(mCollisionCheck);
        ActorCollisionCheckMgr::instance()->entry(mCollisionCheckDrcTouch);
    }

    // Address: 0x0202CE40
    bool setTouchDrcDamage_(const sead::Vector2f& pos) override;

    void getBox_(sead::BoundBox2f& box) override
    {
        box.set(
            mPos.x - 48.0f, mPos.y,
            mPos.x + 48.0f, mPos.y + 96.0f
        );
    }

    // Address: 0x0202CEAC
    bool createIceActor() override;
    // Address: 0x0202CF64
    void returnState_Ice() override;

    void calcMdl_Ice() override
    {
        calcModel();
    }

    // Address: 0x0202BFDC
    void vsPlayerHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x0202C2B4
    void vsYoshiHitCheck_Normal(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x0202DCC8
    bool hitCallback_Star(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    bool hitCallback_Slip(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override
    {
        return false;
    }

    // Address: 0x0202C5D0
    bool hitCallback_Spin(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;

    bool hitCallback_WireNet(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override
    {
        return false;
    }

    // Address: 0x0202C3AC
    bool hitCallback_HipAttk(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x0202C5E0
    bool hitCallback_PenguinSlide(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x0202C8E0
    bool hitCallback_Shell(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x0202C6D4
    bool hitCallback_Fire(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x0202CBCC
    bool hitCallback_Ice(ActorCollisionCheck* cc_self, ActorCollisionCheck* cc_other) override;
    // Address: 0x0202CCB0
    void setDeathInfo_Quake(s32) override;

    void setDeathInfo_IceBreak() override
    {
        killIce();
        returnState_Ice();
        reviveCollisionCheck();
    }

    // Address: 0x0202CE00
    bool isQuakeDamage() override;

    void fumiScoreSet(Actor*) override
    {
    }

    // StateID_DieFumi          Address: 0x101F09BC
    // initializeState_DieFumi  Address: 0x0202DC9C
    // executeState_DieFumi     Address: 0x0202DCA0
    // finalizeState_DieFumi    Address: 0x0202DCA4
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Boss, DieFumi)

public:
    // StateID_DieFire          Address: 0x101F09E0
    // initializeState_DieFire  Address: 0x0202BECC
    // executeState_DieFire     Address: 0x0202BEDC
    // finalizeState_DieFire    Address: 0x0202BEEC
    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieFire)
    // StateID_DieSlide         Address: 0x101F0A04
    // initializeState_DieSlide Address: 0x0202BEFC
    // executeState_DieSlide    Address: 0x0202BF0C
    // finalizeState_DieSlide   Address: 0x0202BF1C
    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieSlide)
    // StateID_DieShell         Address: 0x101F0A28
    // initializeState_DieShell Address: 0x0202BF2C
    // executeState_DieShell    Address: 0x0202BF3C
    // finalizeState_DieShell   Address: 0x0202BF4C
    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieShell)
    // StateID_DieStar          Address: 0x101F0A4C
    // initializeState_DieStar  Address: 0x0202BF5C
    // executeState_DieStar     Address: 0x0202BF6C
    // finalizeState_DieStar    Address: 0x0202BF7C
    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieStar)
    // StateID_DieQuake         Address: 0x101F0A70
    // initializeState_DieQuake Address: 0x0202BF8C
    // executeState_DieQuake    Address: 0x0202BF9C
    // finalizeState_DieQuake   Address: 0x0202BFAC
    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieQuake)

    virtual void enterDemo()
    {
        mIsDemoWait = true;
    }

    virtual void exitDemo()
    {
        mIsDemoWait = false;
    }

    virtual void vf56C()
    {
    }

    // Address: 0x0202BFBC
    virtual void startBattleEdDemo();

    virtual void vf57C()
    {
    }

    // Address: Deleted
    virtual void iceBreak()
    {
        killIce();
        returnState_Ice();
        reviveCollisionCheck();
    }

    virtual bool isFreezeable() const
    {
        return !mIceMgr.hasIce();
    }

    virtual void onFreeze()
    {
        mIcePos.x = mPos.x;
        mIcePos.y = mPos.y - 2.5f;
        mIcePos.z = mPos.z;

        mIceScale.set(40.0f, 48.0f, 40.0f);
    }

    // ------------------------------------ BossLife ------------------------------------ //

    // Address: Deleted
    virtual bool life_IsNonDamage() const
    {
        return false;
    }

    // Address: Deleted
    virtual bool life_IsOneDamage() const
    {
        return false;
    }

    // Address: Deleted
    virtual bool life_IsTwoDamage() const
    {
        return false;
    }

    virtual bool life_IsDmgSection() const
    {
        return false;
    }

    virtual void life_DamageRev(s32 damage)
    {
        mLifeHP -= damage;
        if (mLifeHP <= 0)
            mLifeHP = 0;
    }

    virtual s32 life_GetDamage_Fire() const = 0;
    virtual s32 life_GetDamage_Fumi() const = 0;
    virtual s32 life_GetDamage_HipAtk() const = 0;
    virtual s32 life_GetDamage_Star() const = 0;
    virtual s32 life_GetDamage_PenguinSlide() const = 0;
    virtual s32 life_GetDamage_BlockHit() const = 0;
    virtual s32 life_GetDamage_Shell() const = 0;
    virtual s32 life_GetDamage_Quake() const = 0;

    // ---------------------------------------------------------------------------------------- //

    virtual void vf604()
    {
    }

    virtual void vf60C()
    {
    }

    virtual void vf614()
    {
    }

    virtual s32 vf61C()
    {
        return 24;
    }

    // Address: Deleted
    virtual s32 vf624()
    {
        return 24;
    }

    virtual s32 vf62C()
    {
        return 24;
    }

    virtual void createCBSmallScoreDamage(Actor* p_actor) const
    {
        createCoinBattleSmallScore_(p_actor, mPos, 3);
    }

    virtual void createCBSmallScoreDead(Actor* p_actor) const
    {
        createCoinBattleSmallScore_(p_actor, mPos, 4);
    }

    // Address: 0x0202D120
    virtual void deadAllKill();

    // Address: 0x0202D214
    virtual void fumiProc(Actor*);

    virtual void setFumiDamage(Actor* p_actor)
    {
    }

    virtual void setFumiDead(Actor* p_actor)
    {
        changeState(StateID_DieFumi);
    }

    virtual void setFireDamage(Actor* p_actor)
    {
    }

    virtual void setFireDead(Actor* p_actor)
    {
        changeState(StateID_DieFire);
    }

    virtual void setHipatkDamage(Actor* p_actor)
    {
        setFumiDamage(p_actor);
    }

    virtual void setHipatkDead(Actor* p_actor)
    {
        setFumiDead(p_actor);
    }

    // Address: Deleted
    virtual void setSlideDamage(Actor* p_actor)
    {
    }

    // Address: Deleted
    virtual void setSlideDead(Actor* p_actor)
    {
        changeState(StateID_DieSlide);
    }

    // Address: Deleted
    virtual void setStarDamage(Actor* p_actor)
    {
    }

    // Address: Deleted
    virtual void setStarDead(Actor* p_actor)
    {
        changeState(StateID_DieStar);
    }

    virtual void setQuakeDamage()
    {
    }

    virtual void setQuakeDead()
    {
        changeState(StateID_DieQuake);
    }

    virtual void setShellDamage(Actor* p_actor)
    {
    }

    virtual void setShellDead(Actor* p_actor)
    {
        changeState(StateID_DieShell);
    }

    // Address: Deleted
    virtual void setBlockHitDamage()    // I think
    {
    }

    // Address: Deleted
    virtual void setBlockHitDead()      // I think
    {
        setQuakeDead();
    }

    virtual u32 vf6D4()
    {
        return 1;
    }

    virtual void damageProc()
    {
    }

    virtual void deadProc()
    {
        startBattleEdDemo();
    }

    virtual bool isFumiInvalid() const
    {
        return false;
    }

    virtual bool isFumiDmgInvalid() const
    {
        return false;
    }

    virtual bool isIceInvalid() const
    {
        return false;
    }

    virtual bool isFireInvalid() const
    {
        return false;
    }

    // Address: Deleted
    virtual bool isSlideInvalid() const
    {
        return true;
    }

    // Address: Deleted
    virtual bool isShellInvalid() const
    {
        return false;
    }

    // Address: Deleted
    virtual bool isStarInvalid() const
    {
        return false;
    }

    virtual void fumideadEffect()
    {
    }

    virtual void fumidmgEffect()
    {
    }

    virtual void hitFireEffect()
    {
    }

    // Address: Deleted
    virtual void hitShellEffect()
    {
    }

    virtual void vf744()
    {
    }

    virtual void fumidmgSE()
    {
        mAudioObj.startSound("SE_BOSS_CMN_STOMPED", mAudioObjSeqVar);
    }

    virtual void fumideadSE()
    {
        mAudioObj.startSound("SE_BOSS_CMN_STOMPED_LAST1", mAudioObjSeqVar);
    }

    // Address: Deleted
    virtual void stardmgSE()
    {
        mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_STAR_DEF", mAudioObjSeqVar);
    }

    virtual void stardeadSE()
    {
        mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_STAR_LAST", mAudioObjSeqVar);
    }

    // Address: Deleted
    virtual void shelldmgSE()
    {
        mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_DEF", mAudioObjSeqVar);
    }

    virtual void shelldeadSE()
    {
        mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_LAST", mAudioObjSeqVar);
    }

    virtual void firedmgSE()
    {
        if (life_IsDmgSection())
            mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_FIRE_DEF", mAudioObjSeqVar);
        else
            mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_FIRE", mAudioObjSeqVar);
    }

    virtual void firedeadSE()
    {
        mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_LAST_F_MODE", mAudioObjSeqVar);
        mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_FIRE_LAST", mAudioObjSeqVar);
    }

    virtual void firedmgSE_Drc()
    {
        if (life_IsDmgSection())
            mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_FIRE_DEF", mAudioObjSeqVar, nw::snd::OUTPUT_LINE_MAIN | nw::snd::OUTPUT_LINE_DRC);
        else
            mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_FIRE", mAudioObjSeqVar, nw::snd::OUTPUT_LINE_MAIN | nw::snd::OUTPUT_LINE_DRC);
    }

    virtual void firedeadSE_Drc()
    {
        mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_LAST_F_MODE", mAudioObjSeqVar);
        mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_FIRE_LAST", mAudioObjSeqVar, nw::snd::OUTPUT_LINE_MAIN | nw::snd::OUTPUT_LINE_DRC);
    }

    virtual void quakedmgSE()
    {
        mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_STAR_DEF", mAudioObjSeqVar);
    }

    virtual void quakedeadSE()
    {
        mAudioObj.startSound("SE_BOSS_CMN_DAMAGE_LAST_F_MODE", mAudioObjSeqVar);
    }

    virtual void fumiDeadVo()
    {
    }

    // Address: Deleted
    virtual void damageSVo()
    {
    }

    // Address: Deleted
    virtual void damageLVo()
    {
    }

    virtual void calcLookatPos()
    {
        mAttentionLookat.getPos().set(
            mPos.x + mCenterOffset.x,
            mPos.y + mCenterOffset.y
        );
    }

    // Address: 0x0202D3BC
    virtual bool vf7CC();

    // Address: 0x0202D3F4
    virtual void initCcDrcTouch();

    virtual void createModel()
    {
    }

    virtual void calcModel()
    {
    }

    virtual void vf7EC()
    {
    }

    virtual void vf7F4()
    {
    }

    virtual bool createInit()
    {
        return true;
    }

protected:
    // Address: 0x0202D0F8
    void createCoinBattleSmallScore_(Actor* p_actor, const sead::Vector3f& pos, u32 type) const;

protected:
    s32                         mLifeHP;
    s32                         _1884;                      // Supposedly the number of fireball hits required to take damage
    s32                         _1888;                      // Unknown counter
    bool                        mIsShock;                   // Is currently shocked from a quake
    bool                        mIsDemoWait;
    sead::SafeArray<s32, 4>     _1890;
    GameAudio::AudioObjctEmy    mAudioObj;
    s16                         mAudioObjSeqVar;
    AttentionLookat             mAttentionLookat;
    EnemyActorScaler            mScaler;
    ActorCollisionCheck         mCollisionCheckDrcTouch;    // Maybe?
    BossTouchDrcCB              mTouchDrcCallback;
    sead::Vector3f              mIcePos;
    sead::Vector3f              mIceScale;
    sead::Vector3f              mPos_PreIce;
    sead::Vector3f              mSpeed_PreIce;
    f32                         mAccelY_PreIce;
    f32                         mAccelF_PreIce;
    u32                         _186c_PreIce;               // 0x1B70
    u32                         _186e_PreIce;               // 0x1B74
};
static_assert(sizeof(Boss) == 0x1B78);
