#pragma once

#include <actor/ActorBase.h>
#include <actor/ActorPtrCache.h>

#include <container/seadOffsetList.h>
#include <container/seadPtrArray.h>
#include <container/seadRingBuffer.h>
#include <heap/seadDisposer.h>
#include <heap/seadUnitHeap.h>

class ActorMgr
{
    SEAD_SINGLETON_DISPOSER(ActorMgr)

public:
    enum CreateOption
    {
        cCreateOption_ActiveNextFrame = 0,
        cCreateOption_ActiveNow,
        // Anything else other than above:
      //cCreateOption_Independent (most likely unintentional)
    };

public:
    typedef ActorPtrCache::iterator iterator;

public:
    ActorMgr();
    ~ActorMgr();

private:
    ActorBase* doConstructActor_(const ActorCreateParam& param, bool create_immediately);
    ActorBase::MainState doCreate_(ActorBase* p_actor);

    static void delete_(ActorBase* p_actor);
    void doDelete_(ActorBase* p_actor);

    void pushExecuteAndDrawList_(ActorBase* p_actor);

    bool deleteNotRequested_(ActorBase* p_actor);

    void moveActorOnCreateListToDestoryList_();
    void doDeleteActors_(bool destroy);

public:
    void initialize(sead::Heap* heap);

    void createAdditionalHeap(sead::Heap** pp_heap);
    void destroyAdditionalHeap(sead::Heap** pp_heap);

    void destroy();

    void createLater(const ActorCreateParam& param);
    ActorBase* createImmediately(const ActorCreateParam& param, CreateOption option = cCreateOption_ActiveNextFrame);

public:
    iterator find(s32 prof_id, iterator pp_start) const;
    iterator find(s32 prof_id) const
    {
        return find(prof_id, begin());
    }

    u32 count(s32 prof_id) const;

    iterator begin() const
    {
        return mActorPtrCache.begin();
    }

    iterator end() const
    {
        return mActorPtrCache.end();
    }

private:
    void calcCreateDelete_();

public:
    void execute();

    void addToFinalUpdate(ActorBase* p_actor);

    void draw();

private:
    sead::UnitHeap*                                 mpPlayerHeap;
    sead::UnitHeap*                                 mpActorHeap;
    sead::FixedRingBuffer<ActorCreateParam, 520>    mDeferredActorCreate;
    ActorBase::List                                 mCreateManage;
    ActorBase::List                                 mDeleteManage;
    ActorBase::List                                 mExecuteManage;
    ActorBase::List                                 mDrawManage;
    sead::FixedPtrArray<sead::Heap, 520>            mActorDeleteHeap;
    sead::FixedPtrArray<ActorBase, 520>             mActorFinalUpdate;
    ActorPtrCache                                   mActorPtrCache;
    u32                                             mActorCreateID;
    bool                                            mActorCreateImmediately;
    u8                                              _6a3d[3];
    bool                                            mActorDrawDone;
    u8                                              _6a41[3];
};
static_assert(sizeof(ActorMgr) == 0x6A44);
