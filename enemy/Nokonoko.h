#pragma once

#include <enemy/Enemy.h>

class Nokonoko : public /* Shell */ Enemy   // TODO
{
public:
    // Address: 0x10205668
    static FStateVirtualID<Nokonoko> StateID_Kick;

public:
    // Address: 0x02400B08
    bool shouldTurn() const;
};
