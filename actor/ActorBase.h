#pragma once

#include <actor/ActorUniqueID.h>

#include <container/seadOffsetList.h>
#include <heap/seadHeap.h>
#include <math/seadVector.h>
#include <prim/seadBitFlag.h>
#include <prim/seadRuntimeTypeInfo.h>

class Profile;

struct ActorCreateParam
{
    u32             param_0;
    u32             param_1;
    u32             parent_id;
    Profile*        p_profile;
    sead::Vector3f  position;
    u32             angle;
    u8              layer;
    u8              event_id_0;
    u8              event_id_1;
    u8              _23[1];             // Unused, padding? (Intentionally byte array)
    u8              movement_id;
    u8              link_id;
    u8              init_state_flag;
    u8              _27[1];             // Unused, padding? (Intentionally byte array)
    u8*             _28;

    ActorCreateParam()
        : parent_id(0)
        , angle(0)
    {
        initialize();
    }

    void initialize()
    {
        sead::MemUtil::fillZero(this, sizeof(ActorCreateParam));
    }
};
static_assert(sizeof(ActorCreateParam) == 0x2C);

class ActorMgr;

class ActorBase
{
    SEAD_RTTI_BASE(ActorBase)

public:
    enum MainState
    {
        cState_Cancelled = 0,
        cState_Error,
        cState_Success,
        cState_Waiting
    };

public:
    typedef sead::OffsetList<ActorBase> List;

public:
    ActorBase(const ActorCreateParam& param);
    virtual ~ActorBase();

protected:
    virtual s32 preCreate_();                   // 0: Cancel,  1: Success
    virtual s32 create_();                      // 0: Waiting, 1: Success, 2: Error
    virtual void postCreate_(MainState state);

    virtual s32 preExecute_();                  // 0: Cancel,  1: Success
    virtual s32 execute_();                     // 0: Error,   1: Success
    virtual void postExecute_(MainState state);
    virtual void finalUpdate_();

    virtual s32 preDraw_();                     // 0: Cancel,  1: Success
    virtual s32 draw_();                        // 0: Error,   1: Success
    virtual void postDraw_(MainState state);

    virtual s32 preDelete_();                   // 0: Cancel,  1: Success
    virtual s32 doDelete_();                    // 0: Waiting, 1: Success, 2: Error
    virtual void postDelete_(MainState state);

protected:
    void setActive_(bool active)
    {
        mIsActive = active;
    }

public:
    bool isActive() const
    {
        return mIsActive;
    }

    void requestDelete()
    {
        mRequestDelete = true;
    }

    bool isDeleted() const
    {
        return mRequestDelete;
    }

    ActorUniqueID getActorUniqueID() const
    {
        return mActorUniqueID;
    }

    s32 getProfileID() const;

    sead::Heap* getHeap() const
    {
        return mpHeap;
    }

protected:
    sead::Heap*     mpHeap;
    ActorUniqueID   mActorUniqueID;
    Profile*        mpProfile;
    bool            mCreateImmediately;
    bool            _d;
    bool            mIsActive;
    bool            mRequestDelete;
    u32             mParam0;
    u32             mParam1;
    u8              mMovementID;
    u8              mLinkID;
    u8              mInitStateFlag;
    List            mChildList;
    sead::ListNode  mChildNode;
    ActorBase*      mpParent;
    sead::ListNode  mExecuteNode;
    sead::ListNode  mDrawNode;
    sead::BitFlag32 mFlag;

    friend class ActorMgr;
};
static_assert(sizeof(ActorBase) == 0x50);

template <typename T>
ActorBase* TActorFactory(const ActorCreateParam& param)
{
    return new T(param);
}
