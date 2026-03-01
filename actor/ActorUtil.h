#pragma once

#include <utility/Direction.h>

#include <math/seadVector.h>

class Actor;

class ActorUtil
{
public:
    // Address: 0x0200C67C
    static s32 searchNearPlayer_Main(sead::Vector2f& player_pos, const sead::Vector2f& src_pos);

    // Address: 0x0200C7E4
    static DirType getTrgToSrcDir(const Actor& src, const Actor& trg);
    // Address: 0x0200C800
    static DirType getSrcToTrgDir(const Actor& src, const Actor& trg);
};
