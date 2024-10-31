#pragma once

#include <actor/ActorState.h>

class Yoshi;

class ItemBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(ItemBase, ActorMultiState)

public:
    Yoshi* getEatenByYoshi() const;

protected:
    u32 _17c8[(0x1A90 - 0x17C8) / sizeof(u32)];
};
static_assert(sizeof(ItemBase) == 0x1A90);
