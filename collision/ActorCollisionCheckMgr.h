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

    const LineNodeMgr<ActorCollisionCheck>& getTouchDrcHoldList() const
    {
        return mTouchDrcHoldList;
    }

    // Address: 0x0219E098
    bool isInTouchDrcHoldList(const ActorCollisionCheck& collision_check) const;
    // Address: 0x0219E0D4
    void addToTouchDrcHoldList(const ActorCollisionCheck& collision_check);
    // Address: 0x0219E130
    void removeFromTouchDrcHoldList(const ActorCollisionCheck& collision_check);

    const LineNodeMgr<ActorCollisionCheck>& getTouchDrcCheckList() const
    {
        return mTouchDrcCheckList;
    }

    // Address: 0x0219DC20
    bool isInTouchDrcCheckList(const ActorCollisionCheck& collision_check) const;
    // Address: 0x0219DCAC
    void addToTouchDrcCheckList(const ActorCollisionCheck& collision_check);
    // Address: 0x0219DEC0
    void removeFromTouchDrcCheckList(const ActorCollisionCheck& collision_check);

    void entry(const ActorCollisionCheck& collision_check)
    {
        if (!isInActiveList(collision_check) && !isInCreateList(collision_check))
            addToCreateList(collision_check);
    }

    void release(const ActorCollisionCheck& collision_check)
    {
        removeFromActiveList(collision_check);
        removeFromCreateList(collision_check);
        removeFromTouchDrcHoldList(collision_check);
    }

    // Address: 0x0219E228
    void execute();

private:
    // Address: 0x0219DE74
    void create_();

private:
    LineNodeMgr<ActorCollisionCheck>    mActiveList;
    LineNodeMgr<ActorCollisionCheck>    mCreateList;
    LineNodeMgr<ActorCollisionCheck>    mTouchDrcHoldList;
    LineNodeMgr<ActorCollisionCheck>    mTouchDrcCheckList;
};
static_assert(sizeof(ActorCollisionCheckMgr) == 0x40);
