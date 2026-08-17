#pragma once

#include <basis/seadTypes.h>

// TODO
class Quad;

class Mask
{
public:
    enum TexName
    {
        cTexName_Cave = 0,
        cTexName_CaveSmall,
        cTexName_Dark,
        cTexName_DeepSea,
        cTexName_FlashlightA,
        cTexName_FlashlightB,
        cTexName_DrcBlock,
        cTexName_DrcTouch,
        cTexName_UserType
    };
    static_assert(sizeof(TexName) == 4);

public:
    // TODO
};
