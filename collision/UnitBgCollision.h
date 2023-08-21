#pragma once

#include <collision/SimpleShapeBgCollision.h>

class UnitBgCollision : public SimpleShapeBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101EA38C
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101EA3C0
    SEAD_RTTI_OVERRIDE(UnitBgCollision, SimpleShapeBgCollision)

public:
    UnitBgCollision()
        : SimpleShapeBgCollision()
    {
    }

    UnitBgCollision(s32 point_num, sead::Vector2f* point_buf, BasicRideLine* line_buf, BasicRideLine* line_prev_buf)
        : SimpleShapeBgCollision(point_num, point_buf, line_buf, line_prev_buf)
    {
    }

    // Address: 0x021B2000
    void vf84() override;

    // Address: 0x021B1EF0
    void vf6C() override;
};
static_assert(sizeof(UnitBgCollision) == sizeof(SimpleShapeBgCollision));
