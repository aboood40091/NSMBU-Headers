#pragma once

#include <system/LineNodeMgr.h>

#include <heap/seadDisposer.h>

class ActorCollisionCheck;

class ActorCollisionCheckMgr
{
    // createInstance()                             Address: 0x0219DAF4
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101C95D8
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0219E6B0
    // SingletonDisposer_::sStaticDisposer          Address: 0x101C95DC
    // SingletonDisposer_::vtbl                     Address: 0x10041D68
    SEAD_SINGLETON_DISPOSER(ActorCollisionCheckMgr)

public:
    const LineNodeMgr<ActorCollisionCheck>& getActiveList() const
    {
        return mActiveList;
    }

    // Address: 0x0219DC5C
    bool isInActiveList(const ActorCollisionCheck& collision_check) const;
    // Address: 0x0219DD08
    void addToActiveList(const ActorCollisionCheck& collision_check);
    // Address: 0x0219DF70
    void removeFromActiveList(const ActorCollisionCheck& collision_check);

    const LineNodeMgr<ActorCollisionCheck>& getCreateList() const
    {
        return mCreateList;
    }

    // Address: 0x0219DD88
    bool isInCreateList(const ActorCollisionCheck& collision_check) const;
    // Address: 0x0219E028
    void addToCreateList(const ActorCollisionCheck& collision_check);
    // Address: 0x0219DDC4
    void removeFromCreateList(const ActorCollisionCheck& collision_check);

    const LineNodeMgr<ActorCollisionCheck>& getList3() const
    {
        return _28;
    }

    // Address: 0x0219E098
    bool isInList3(const ActorCollisionCheck& collision_check) const;
    // Address: 0x0219E0D4
    void addToList3(const ActorCollisionCheck& collision_check);
    // Address: 0x0219E130
    void removeFromList3(const ActorCollisionCheck& collision_check);

    const LineNodeMgr<ActorCollisionCheck>& getList4() const
    {
        return _34;
    }

    // Address: 0x0219DC20
    bool isInList4(const ActorCollisionCheck& collision_check) const;
    // Address: 0x0219DCAC
    void addToList4(const ActorCollisionCheck& collision_check);
    // Address: 0x0219DEC0
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

    // Address: 0x0219E228
    void execute();

private:
    // Address: 0x0219DE74
    void create_();

private:
    LineNodeMgr<ActorCollisionCheck>    mActiveList;
    LineNodeMgr<ActorCollisionCheck>    mCreateList;
    LineNodeMgr<ActorCollisionCheck>    _28;
    LineNodeMgr<ActorCollisionCheck>    _34;
};
static_assert(sizeof(ActorCollisionCheckMgr) == 0x40);
