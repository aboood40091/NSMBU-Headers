#pragma once

#include <collision/ActorCollisionTouchDrcCallback.h>

class PairObjChildBaseTouchDrcCB : public ActorCollisionTouchDrcCallback
{
public:
    bool bcIsTouchEnable(BgCollision* p_bg_collision, const sead::Vector2f& pos) override;
    void bcOnTouch(BgCollision* p_bg_collision, const sead::Vector2f& pos) override;
};
static_assert(sizeof(PairObjChildBaseTouchDrcCB) == sizeof(ActorCollisionTouchDrcCallback));

class PairObjChild
{
public:
    static bool checkRevFoot(Actor*, Actor*);
    static bool checkRevHead(Actor*, Actor*);
    static bool checkRevWall(Actor*, Actor*, u8);
};
