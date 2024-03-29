#pragma once

#include <collision/CollisionCallback.h>

class PairObjChildBaseCB : public CollisionCallback
{
public:
    bool bcCallback1(BgCollision*, const sead::Vector2f&) override;
    void bcCallback2(BgCollision*, const sead::Vector2f&) override;
};
static_assert(sizeof(PairObjChildBaseCB) == sizeof(CollisionCallback));

class PairObjChild
{
public:
    static bool checkRevFoot(Actor*, Actor*);
    static bool checkRevHead(Actor*, Actor*);
    static bool checkRevWall(Actor*, Actor*, u8);
};
