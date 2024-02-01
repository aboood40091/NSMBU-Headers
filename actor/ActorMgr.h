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
    // createInstance()                             Address: 0x02008CB4
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101C30C8
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x02009FA8
    // SingletonDisposer_::sStaticDisposer          Address: 0x101C30CC
    // SingletonDisposer_::vtbl                     Address: 0x10000CD0
    SEAD_SINGLETON_DISPOSER(ActorMgr)

public:
    enum CreateOption
    {
        cCreateOption_ActiveLater = 0,
        cCreateOption_ActiveImmediately,
        // Anything else other than above:
      //cCreateOption_Independent (most likely unintentional)
    };

public:
    typedef ActorPtrCache::iterator iterator;

public:
    // Address: 0x02008AB0
    ActorMgr();
    // Address: 0x02009000
    ~ActorMgr();

private:
    // Address: 0x020090CC
    ActorBase* doConstructActor_(const ActorCreateParam& param, bool create_immediately);
    // Address: 0x02009218
    ActorBase::MainState doCreate_(ActorBase* actor);

    // Address: 0x0200932C
    static void delete_(ActorBase* actor);
    // Address: 0x02009338
    void doDelete_(ActorBase* actor);

    // Address: 0x0200940C
    void pushExecuteAndDrawList_(ActorBase* actor);

    // Address: 0x02009590
    bool deleteNotRequested_(ActorBase* actor);

    // Address: 0x02008D34
    void moveActorOnCreateListToDestoryList_();
    // Address: 0x02008DC8
    void doDeleteActors_(bool destroy);

public:
    // Address: 0x0200959C
    void initialize(sead::Heap* heap);

    // Address: 0x02009648
    void createAdditionalHeap(sead::Heap** heap);
    // Address: 0x020096B0
    void destroyAdditionalHeap(sead::Heap** heap);

    // Address: 0x020098A8
    void destroy();

    // Address: 0x02009954
    void createLater(const ActorCreateParam& param);
    // Address: 0x02009A58
    ActorBase* createImmediately(const ActorCreateParam& param, CreateOption option = cCreateOption_ActiveLater);

public:
    // Address: 0x02009B6C
    iterator find(s32 i_profile_id, iterator it_start) const;
    iterator find(s32 i_profile_id) const
    {
        return find(i_profile_id, getActorBegin());
    }

    // Address: 0x02009BA4
    u32 count(s32 i_profile_id) const;

    iterator getActorBegin() const
    {
        return mActorPtrCache.getActorBegin();
    }

    iterator getActorEnd() const
    {
        return mActorPtrCache.getActorEnd();
    }

private:
    // Address: 0x02009BDC
    void calcCreateDelete_();

public:
    // Address: 0x02009D58
    void execute();

    // Address: 0x02009EA0
    void addToFinalUpdate(ActorBase* actor);

    // Address: 0x02009ECC
    void draw();

private:
    sead::UnitHeap*                                 mPlayerUnitHeap;
    sead::UnitHeap*                                 mActorUnitHeap;
    sead::FixedRingBuffer<ActorCreateParam, 520>    mDeferredActorCreate;
    ActorBase::List                                 mCreateManage;
    ActorBase::List                                 mDeleteManage;
    ActorBase::List                                 mExecuteManage;
    ActorBase::List                                 mDrawManage;
    sead::FixedPtrArray<sead::Heap, 520>            mActorDeleteHeap;
    sead::FixedPtrArray<ActorBase, 520>             mActorFinalUpdate;
    ActorPtrCache                                   mActorPtrCache;
    ActorUniqueID                                   mActorCreateID;
    bool                                            mActorCreateImmediately;
    u8                                              _6a3d[3];
    bool                                            mActorDrawDone;
    u8                                              _6a41[3];

    friend class ActorBase;
};
static_assert(sizeof(ActorMgr) == 0x6A44);
