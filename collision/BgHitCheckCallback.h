#pragma once

#include <basis/seadTypes.h>

struct BgCollisionCheckResultPoint;
struct BgCollisionCheckResultArea;

class BgHitCheckCallback
{
public:
    virtual bool hit(const BgCollisionCheckResultPoint& hit_res) = 0;
    virtual bool hit(const BgCollisionCheckResultArea& hit_res) = 0;
};
static_assert(sizeof(BgHitCheckCallback) == 4);
