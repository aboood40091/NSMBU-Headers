#pragma once

#include <system/LineNodeMgr.h>

#include <heap/seadDisposer.h>

class ActorCollisionCheck;

class ActorCollisionCheckMgr
{
    SEAD_SINGLETON_DISPOSER(ActorCollisionCheckMgr)

public:
    const LineNodeMgr<ActorCollisionCheck>& getActiveList() const
    {
        return mActiveList;
    }

    bool isInActiveList(const ActorCollisionCheck& collision_check) const;
    void addToActiveList(const ActorCollisionCheck& collision_check);
    void removeFromActiveList(const ActorCollisionCheck& collision_check);

    const LineNodeMgr<ActorCollisionCheck>& getCreateList() const
    {
        return mCreateList;
    }

    bool isInCreateList(const ActorCollisionCheck& collision_check) const;
    void addToCreateList(const ActorCollisionCheck& collision_check);
    void removeFromCreateList(const ActorCollisionCheck& collision_check);

    const LineNodeMgr<ActorCollisionCheck>& getList3() const
    {
        return _28;
    }

    bool isInList3(const ActorCollisionCheck& collision_check) const;
    void addToList3(const ActorCollisionCheck& collision_check);
    void removeFromList3(const ActorCollisionCheck& collision_check);

    const LineNodeMgr<ActorCollisionCheck>& getList4() const
    {
        return _34;
    }

    bool isInList4(const ActorCollisionCheck& collision_check) const;
    void addToList4(const ActorCollisionCheck& collision_check);
    void removeFromList4(const ActorCollisionCheck& collision_check);

    void entry(const ActorCollisionCheck& collision_check)
    {
        if (!isInActiveList(collision_check) && !isInCreateList(collision_check))
            addToCreateList(collision_check);
    }

    void release(const ActorCollisionCheck& collision_check)
    {
        removeFromActiveList(collision_check);
        removeFromCreateList(collision_check);
        removeFromList3(collision_check);
    }

    void execute();

private:
    void create_();

private:
    LineNodeMgr<ActorCollisionCheck>    mActiveList;
    LineNodeMgr<ActorCollisionCheck>    mCreateList;
    LineNodeMgr<ActorCollisionCheck>    _28;
    LineNodeMgr<ActorCollisionCheck>    _34;
};
static_assert(sizeof(ActorCollisionCheckMgr) == 0x40);
