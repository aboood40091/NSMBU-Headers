#pragma once

#include <actor/ActorCreateParam.h>

#include <container/seadOffsetList.h>
#include <heap/seadHeap.h>
#include <prim/seadBitFlag.h>
#include <prim/seadRuntimeTypeInfo.h>

class ActorMgr;

class ActorBase // vtbl Address: 0x100006C0
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CC4
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CC8
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

    // Address: 0x02002C80
    s32 getProfileID() const;

    sead::Heap* getActorHeap() const
    {
        return mActorHeap;
    }

    // Address: 0x02002C8C
    void removeChild(ActorBase* child);

protected:
    // Address: 0x02002CE0
    ActorBase(const ActorCreateParam& param);
    // Address: 0x02002E68
    virtual ~ActorBase();

protected:
    // Address: 0x02002F7C
    virtual s32 preCreate_();                   // 0: Cancel,  1: Success
    // Address: 0x02002F84
    virtual s32 create_();                      // 0: Waiting, 1: Success, 2: Error
    // Address: 0x02002F00
    virtual void postCreate_(MainState state);

    // Address: 0x02002F04
    virtual s32 preExecute_();                  // 0: Cancel,  1: Success
    // Address: 0x02002F8C
    virtual s32 execute_();                     // 0: Error,   1: Success
    // Address: 0x02002F34
    virtual void postExecute_(MainState state);
    // Address: 0x02002F94
    virtual void finalUpdate_();

    // Address: 0x02002F98
    virtual s32 preDraw_();                     // 0: Cancel,  1: Success
    // Address: 0x02002FA0
    virtual s32 draw_();                        // 0: Error,   1: Success
    // Address: 0x02002F38
    virtual void postDraw_(MainState state);

    // Address: 0x02002FA8
    virtual s32 preDelete_();                   // 0: Cancel,  1: Success
    // Address: 0x02002FB0
    virtual s32 doDelete_();                    // 0: Waiting, 1: Success, 2: Error
    // Address: 0x02002F3C
    virtual void postDelete_(MainState state);

protected:
    void setActive_(bool active)
    {
        mIsActive = active;
    }

protected:
    sead::Heap*     mActorHeap;
    ActorUniqueID   mActorUniqueID;
    Profile*        mActorProfile;
    bool            mCreateImmediately;
    bool            _d;
    bool            mIsActive;
    bool            mRequestDelete;
    u32             mParam0;
    u32             mParam1;
    ActorParamEx1   mParamEx;
    List            mChildList;
    sead::ListNode  mChildNode;
    ActorBase*      mParent;
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
