#pragma once

#include <basis/seadTypes.h>

class FieldGameMode
{
public:
    enum Mode
    {
        cStory = 0,
        cBoostRush,
        cCoinBattle,
        cCoinEdit,
        cChallenge,
        cNum
    };
    static_assert(sizeof(Mode) == 4);

public:
    Mode getMode() const
    {
        return mMode;
    }

private:
    Mode    mMode;
};
static_assert(sizeof(FieldGameMode) == 4);
