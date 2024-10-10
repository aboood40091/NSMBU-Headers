#pragma once

#include <collision/ActorCollisionHitCallback.h>

class PairObjChildBaseCB : public ActorCollisionHitCallback
{
public:
    bool bcCallback1(BgCollision*, const sead::Vector2f&) override;
    void bcCallback2(BgCollision*, const sead::Vector2f&) override;
};
static_assert(sizeof(PairObjChildBaseCB) == sizeof(ActorCollisionHitCallback));

class PairObjChild
{
public:
    static bool checkRevFoot(Actor*, Actor*);
    static bool checkRevHead(Actor*, Actor*);
    static bool checkRevWall(Actor*, Actor*, u8);
};
