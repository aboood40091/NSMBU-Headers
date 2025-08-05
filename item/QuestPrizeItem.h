#pragma once

#include <actor/ActorState.h>

class QuestPrizeItem : public ActorState
{
    SEAD_RTTI_OVERRIDE(QuestPrizeItem, ActorState)

public:
    void setTargetPos(f32 x, f32 y)
    {
        mTargetPos.set(x, y);
    }

protected:
    u32             _17c8[(0x17D8 - 0x17C8) / sizeof(u32)];
    sead::Vector2f  mTargetPos;
    u32             _17e0[(0x1890 - 0x17E0) / sizeof(u32)];
};
static_assert(sizeof(QuestPrizeItem) == 0x1890);
