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
    ActorPtrCache(sead::Heap* heap, s32 size);
    ~ActorPtrCache();

    iterator find(ActorFindFunc* p_func, iterator pp_start) const;
    iterator find(ActorFindFunc* p_func) const
    {
        return find(p_func, begin());
    }

    u32 count(ActorFindFunc* p_func) const;

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

    void pushActor(ActorBase* p_actor);
    void popActor(const ActorBase* p_actor);
    ActorBase* getActorPtr(ActorUniqueID id) const;
    ActorBase* getActorPtrIncludingAboutToBeErased(ActorUniqueID id) const; // deleted

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
    u8                          _14;
};
static_assert(sizeof(ActorPtrCache) == 0x18);
