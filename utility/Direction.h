#pragma once

#include <basis/seadTypes.h>

enum DirType
{
    cDirType_Right = 0,
    cDirType_Left,
    cDirType_Up,
    cDirType_Down,
    cDirType_Num,

    cDirType_NumX = 2
};
static_assert(sizeof(DirType) == 4);

inline u32 InvDirX(u32 dir)
{
    return dir ^ 1;
}

inline u32 InvDirection(u32 dir)
{
    switch (dir)
    {
    case cDirType_Right: dir = cDirType_Left;  break;
    case cDirType_Left:  dir = cDirType_Right; break;
    case cDirType_Up:    dir = cDirType_Down;  break;
    case cDirType_Down:  dir = cDirType_Up;    break;
    }
    return dir;
}
