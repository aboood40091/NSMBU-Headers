#pragma once

#include <math/seadVector.h>

class Actor;
class ActorCollisionCheck;
class BgCollision;

// Actual name is ActorCollision{Something}, comes after ActorCollisionCheckMgr
class CollisionCallback
{
public:
    // Address: 0x0219E7E8
    virtual bool ccCallback0(Actor*, ActorCollisionCheck*, const sead::Vector2f&);
    virtual bool ccCallback1(Actor*, ActorCollisionCheck*, const sead::Vector2f&) { return false; }
    // Address: 0x0219E8A4
    virtual void ccCallback2(Actor*, ActorCollisionCheck*, const sead::Vector2f&);
    virtual void ccCallback3(Actor*, ActorCollisionCheck*, const sead::Vector2f&) { }
    virtual void ccCallback4(Actor*, ActorCollisionCheck*, const sead::Vector2f&) { }

    // Address: 0x0219E8B8
    virtual bool bcCallback0(Actor*, BgCollision*, const sead::Vector2f&);
    virtual bool bcCallback1(Actor*, BgCollision*, const sead::Vector2f&) { return false; }
    // Address: 0x0219E974
    virtual void bcCallback2(Actor*, BgCollision*, const sead::Vector2f&);
    virtual void bcCallback3(Actor*, BgCollision*, const sead::Vector2f&) { }
    virtual void bcCallback4(Actor*, BgCollision*, const sead::Vector2f&) { }
};
static_assert(sizeof(CollisionCallback) == 4);
