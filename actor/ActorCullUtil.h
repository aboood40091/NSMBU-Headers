#pragma once

#include <actor/ActorCullRange.h>

#include <math/seadBoundBox.h>

class ActorCullUtil
{
public:
    // Address: 0x02008838
    static bool screenCullCheck(const sead::BoundBox2f& range, const ActorCullRange& cull_range);
    // Address: 0x0200897C
    static bool areaCullCheck(const sead::BoundBox2f& range, u8 area_no);
};
