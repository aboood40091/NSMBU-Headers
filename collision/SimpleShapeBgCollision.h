#pragma once

#include <collision/LoopRideLineBgCollision.h>

class SimpleShapeBgCollision : public LoopRideLineBgCollision
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9D34
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9FB8
    SEAD_RTTI_OVERRIDE(SimpleShapeBgCollision, LoopRideLineBgCollision)

public:
    SimpleShapeBgCollision()
        : LoopRideLineBgCollision()
    {
    }

    SimpleShapeBgCollision(s32 point_num, sead::Vector2f* point_buf, BasicRideLine* line_buf, BasicRideLine* line_prev_buf)
        : LoopRideLineBgCollision(point_num, point_buf, line_buf, line_prev_buf)
    {
    }

    // Address: 0x021B096C
    bool vf54(u8*, sead::Vector2f*) override;
};
static_assert(sizeof(SimpleShapeBgCollision) == sizeof(LoopRideLineBgCollision));
