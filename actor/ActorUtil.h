#pragma once

#include <basis/seadTypes.h>

class Actor;

class ActorUtil
{
public:
    // Address: 0x0200C7E4
    static u8 getTrgToSrcDir(const Actor& src, const Actor& trg);
    // Address: 0x0200C800
    static u8 getSrcToTrgDir(const Actor& src, const Actor& trg);
};
