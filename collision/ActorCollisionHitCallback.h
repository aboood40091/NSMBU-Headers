#pragma once

#include <math/seadVector.h>

class Actor;
class ActorCollisionCheck;
class BgCollision;

class ActorCollisionHitCallback
{
public:
    // Address: 0x0219E7E8
    virtual bool ccIsTouchSkipFrame(ActorCollisionCheck* p_cc, const sead::Vector2f& pos);
    virtual bool ccIsTouchEnable(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) { return false; }
    // Address: 0x0219E8A4
    virtual void ccOnTouch(ActorCollisionCheck* p_cc, const sead::Vector2f& pos);
    virtual void ccOnHold(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) { }
    virtual void ccOnRelease(ActorCollisionCheck* p_cc) { }

    // Address: 0x0219E8B8
    virtual bool bcIsTouchSkipFrame(BgCollision* p_bg_collision, const sead::Vector2f& pos);
    virtual bool bcIsTouchEnable(BgCollision* p_bg_collision, const sead::Vector2f& pos) { return false; }
    // Address: 0x0219E974
    virtual void bcOnTouch(BgCollision* p_bg_collision, const sead::Vector2f& pos);
    virtual void bcOnHold(BgCollision* p_bg_collision, const sead::Vector2f& pos) { }
    virtual void bcOnRelease(BgCollision* p_bg_collision) { }
};
static_assert(sizeof(ActorCollisionHitCallback) == 4);
