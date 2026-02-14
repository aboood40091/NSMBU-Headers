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

    // Address: 0x024C28D8
    void setMode(Mode mode);

    // Address: 0x024C28EC
    bool isMiniGame() const;

    // Address: 0x024C2910
    bool isWmMode() const;

    // Address: 0x024C2924
    bool isDvMiiMode() const;

private:
    Mode    mMode;
};
static_assert(sizeof(FieldGameMode) == 4);
