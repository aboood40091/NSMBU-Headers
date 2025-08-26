#pragma once

#include <math/seadVector.h>

class Actor;
class ActorCollisionCheck;
class BgCollision;

class ActorCollisionDrcTouchCallback
{
public:
    // Address: 0x0219E7E8
    virtual bool ccSetTouchDamage(ActorCollisionCheck* p_cc, const sead::Vector2f& pos);
    virtual bool ccSetTouchNormal(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) { return false; }
    // Address: 0x0219E8A4
    virtual void ccOnTouch(ActorCollisionCheck* p_cc, const sead::Vector2f& pos);
    virtual void ccOnHold(ActorCollisionCheck* p_cc, const sead::Vector2f& pos) { }
    virtual void ccOnRelease(ActorCollisionCheck* p_cc) { }

    // Address: 0x0219E8B8
    virtual bool bcSetTouchDamage(BgCollision* p_bg_collision, const sead::Vector2f& pos);
    virtual bool bcSetTouchNormal(BgCollision* p_bg_collision, const sead::Vector2f& pos) { return false; }
    // Address: 0x0219E974
    virtual void bcOnTouch(BgCollision* p_bg_collision, const sead::Vector2f& pos);
    virtual void bcOnHold(BgCollision* p_bg_collision, const sead::Vector2f& pos) { }
    virtual void bcOnRelease(BgCollision* p_bg_collision) { }
};
static_assert(sizeof(ActorCollisionDrcTouchCallback) == 4);
