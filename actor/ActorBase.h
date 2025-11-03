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
        cState_None = 0,
        cState_Failed,
        cState_Success,
        cState_Wait
    };

    enum Result
    {
        cResult_Wait = 0,
        cResult_Success,
        cResult_Failed
    };

public:
    typedef sead::OffsetList<ActorBase> List;

public:
    bool isActive() const
    {
        return mIsActive;
    }

    void deleteRequest()
    {
        mDeleteRequestFlag = true;
    }

    bool isRequestedDelete() const
    {
        return mDeleteRequestFlag;
    }

    ActorUniqueID getActorUniqueID() const
    {
        return mActorUniqueID;
    }

    // Address: 0x02002C80
    s32 getProfileID() const;

    sead::Heap* getActorHeap() const
    {
        return mpActorHeap;
    }

    ActorBase* getParent() const
    {
        return mpParent;
    }

    // Address: 0x02002C8C
    void removeChild(ActorBase* p_child);

protected:
    // Address: 0x02002CE0
    ActorBase(const ActorCreateParam& param);
    // Address: 0x02002E68
    virtual ~ActorBase();

protected:
    // Address: 0x02002F7C
    virtual bool preCreate_();
    // Address: 0x02002F84
    virtual Result create_();
    // Address: 0x02002F00
    virtual void postCreate_(MainState state);

    // Address: 0x02002F04
    virtual bool preExecute_();
    // Address: 0x02002F8C
    virtual bool execute_();
    // Address: 0x02002F34
    virtual void postExecute_(MainState state);
    // Address: 0x02002F94
    virtual void finalUpdate_();

    // Address: 0x02002F98
    virtual bool preDraw_();
    // Address: 0x02002FA0
    virtual bool draw_();
    // Address: 0x02002F38
    virtual void postDraw_(MainState state);

    // Address: 0x02002FA8
    virtual bool preDelete_();
    // Address: 0x02002FB0
    virtual Result doDelete_();
    // Address: 0x02002F3C
    virtual void postDelete_(MainState state);

protected:
    void setActive_(bool active)
    {
        mIsActive = active;
    }

protected:
    sead::Heap*     mpActorHeap;
    ActorUniqueID   mActorUniqueID;
    Profile*        mpActorProfile;
    bool            mCreateImmediately;
    bool            _d;
    bool            mIsActive;
    bool            mDeleteRequestFlag;
    u32             mParam0;
    u32             mParam1;
    ActorParamEx1   mParamEx;
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
