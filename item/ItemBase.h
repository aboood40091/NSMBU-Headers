#pragma once

#include <actor/ActorState.h>

class YoshiObject;

class ItemBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(ItemBase, ActorMultiState)

public:
    YoshiObject* getEatenByYoshi() const;
};
