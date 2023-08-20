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
    ActorPtrCache(sead::Heap* heap, s32 size);
    // Address: 0x0200A278
    ~ActorPtrCache();

    // Address: 0x0200A300
    iterator find(ActorFindFunc* p_func, iterator pp_start) const;
    iterator find(ActorFindFunc* p_func) const
    {
        return find(p_func, begin());
    }

    iterator begin() const
    {
        return &mActor.front();
    }

    iterator end() const
    {
        return mpActorLast;
    }

    u32 size() const
    {
        return mCount;
    }

    u32 maxSize() const
    {
        return mActor.size();
    }

    // Address: 0x0200A3A8
    void pushActor(ActorBase* p_actor);
    // Address: 0x0200A550
    void popActor(const ActorBase* p_actor);
    // Address: 0x0200A5C8
    ActorBase* getActorPtr(ActorUniqueID id) const;
    // Address: Deleted
    ActorBase* getActorPtrIncludingAboutToBeErased(ActorUniqueID id) const;

    // Address: 0x0200A608
    u32 count(ActorFindFunc* p_func) const;

    // Address: 0x0200A6AC
    void forEach(void (*p_callback)(ActorBase* p_actor, u32), u32) const;

    u32 currentCreateIndex() const
    {
        return mCurrentCreateIndex;
    }

private:
    sead::Buffer<ActorBase*>    mActor;
    u32                         mCount;
    iterator                    mpActorLast;
    u32                         mCurrentCreateIndex;
    bool                        mCreateIndexOverflow;
};
static_assert(sizeof(ActorPtrCache) == 0x18);
