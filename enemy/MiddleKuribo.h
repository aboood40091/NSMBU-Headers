#pragma once

#include <basis/seadTypes.h>

class MiddleKuribo
{
public:
    u64 _0[0x1B08 / sizeof(u64)];   // LkuriboBase
    u32 _1b08;
    u32 _1b0c;
    u32 _1b10;
};
static_assert(sizeof(MiddleKuribo) == 0x1B18);
