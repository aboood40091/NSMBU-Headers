#pragma once

#include <basis/seadTypes.h>

struct BgCollisionCheckResult;

class BgHitCheckCallback
{
public:
    virtual bool vf0C() = 0;
    virtual bool hit(const BgCollisionCheckResult& hit_res) = 0;
};
static_assert(sizeof(BgHitCheckCallback) == 4);
