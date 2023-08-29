#pragma once

#include <basis/seadTypes.h>

#include <container/seadBuffer.h>

class ActorBase;
class ActorFindFunc;
class ActorUniqueID;

class ActorPtrCache
{
public:
    typedef ActorBase* const* iterator;

public:
    // Address: 0x0200A14C
    ActorPtrCache(sead::Heap* heap, s32 i_max_actor_num);
    // Address: 0x0200A278
    ~ActorPtrCache();

    // Address: 0x0200A300
    iterator find(ActorFindFunc* io_find_func, iterator it_start) const;
    iterator find(ActorFindFunc* io_find_func) const
    {
        return find(io_find_func, getActorBegin());
    }

    iterator getActorBegin() const
    {
        // SEAD_ASSERT(mActorPtrArray.isBufferReady());
        return mActorPtrArray.unsafeGet(0);
    }

    iterator getActorEnd() const
    {
        return mLiveActorEnd;
    }

    // Address: 0x0200A3A8
    void pushActor(ActorBase* io_actor);
    // Address: 0x0200A550
    void popActor(const ActorBase* i_actor);
    // Address: 0x0200A5C8
    ActorBase* getActorPtr(ActorUniqueID id) const;
    // Address: Deleted
    ActorBase* getActorPtrIncludingAboutToBeErased(ActorUniqueID id) const;

    // Address: 0x0200A608
    u32 count(ActorFindFunc* p_func) const;

    // Address: 0x0200A6AC
    void forEach(void (*p_callback)(ActorBase* p_actor, u32), u32) const;

    u32 getEmptyHeadIndex() const
    {
        return mEmptyHeadIndex;
    }

    u32 getNextCreateIndex() const
    {
        return mNextCreateIndex;
    }

private:
    sead::Buffer<ActorBase*>    mActorPtrArray;
    u32                         mEmptyHeadIndex;
    iterator                    mLiveActorEnd;
    u32                         mNextCreateIndex;
    bool                        mCreateIndexOverflow;
};
static_assert(sizeof(ActorPtrCache) == 0x18);
