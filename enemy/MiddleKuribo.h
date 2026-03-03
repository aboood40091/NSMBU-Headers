#pragma once

#include <basis/seadTypes.h>

class LkuriboBase : public Enemy
{
public:
    u32 _1880[(0x1B08 - 0x1880) / sizeof(u32)];
};
static_assert(sizeof(LkuriboBase) == 0x1B08);

class MiddleKuribo : public LkuriboBase
{
public:
    u32 _1b08;
    u32 _1b0c;
    u32 _1b10;
};
static_assert(sizeof(MiddleKuribo) == 0x1B18);
