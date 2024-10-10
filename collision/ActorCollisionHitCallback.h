#pragma once

#include <math/seadVector.h>

class Actor;
class ActorCollisionCheck;
class BgCollision;

class ActorCollisionHitCallback
{
public:
    // Address: 0x0219E7E8
    virtual bool ccCallback0(ActorCollisionCheck*, const sead::Vector2f&);
    virtual bool ccCallback1(ActorCollisionCheck*, const sead::Vector2f&) { return false; }
    // Address: 0x0219E8A4
    virtual void ccCallback2(ActorCollisionCheck*, const sead::Vector2f&);
    virtual void ccCallback3(ActorCollisionCheck*, const sead::Vector2f&) { }
    virtual void ccCallback4(ActorCollisionCheck*, const sead::Vector2f&) { }

    // Address: 0x0219E8B8
    virtual bool bcCallback0(BgCollision*, const sead::Vector2f&);
    virtual bool bcCallback1(BgCollision*, const sead::Vector2f&) { return false; }
    // Address: 0x0219E974
    virtual void bcCallback2(BgCollision*, const sead::Vector2f&);
    virtual void bcCallback3(BgCollision*, const sead::Vector2f&) { }
    virtual void bcCallback4(BgCollision*, const sead::Vector2f&) { }
};
static_assert(sizeof(ActorCollisionHitCallback) == 4);
