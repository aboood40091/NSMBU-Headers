#pragma once

#include <collision/ActorCollisionDrcTouchCallback.h>

class PairObjChildDrcTouchCB : public ActorCollisionDrcTouchCallback
{
public:
    bool bcSetTouchNormal(BgCollision* p_bg_collision, const sead::Vector2f& pos) override;
    void bcOnTouch(BgCollision* p_bg_collision, const sead::Vector2f& pos) override;
};
static_assert(sizeof(PairObjChildDrcTouchCB) == sizeof(ActorCollisionDrcTouchCallback));

class PairObjChild
{
public:
    static bool checkRevFoot(Actor*, Actor*);
    static bool checkRevHead(Actor*, Actor*);
    static bool checkRevWall(Actor*, Actor*, u8);
};
