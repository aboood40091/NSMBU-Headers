#pragma once

#include <basis/seadTypes.h>

#define DIRECTION_RIGHT 0
#define DIRECTION_LEFT  1
#define DIRECTION_UP    2
#define DIRECTION_DOWN  3

#define DIRECTION_NUM_X 2

inline u32 InvDirX(u32 dir)
{
    return dir ^ 1;
}

inline u32 InvDirection(u32 dir)
{
    switch (dir)
    {
    case DIRECTION_RIGHT: dir = DIRECTION_LEFT;  break;
    case DIRECTION_LEFT:  dir = DIRECTION_RIGHT; break;
    case DIRECTION_UP:    dir = DIRECTION_DOWN;  break;
    case DIRECTION_DOWN:  dir = DIRECTION_UP;    break;
    }
    return dir;
}
