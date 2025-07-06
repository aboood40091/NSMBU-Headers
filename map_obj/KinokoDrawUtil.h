#pragma once

#include <utility/Angle.h>

#include <math/seadVector.h>

class KinokoLiftDraw;

class KinokoDrawUtil
{
public:
    // Address: 0x027A5C04
    static void calcLift(KinokoLiftDraw& lift_dr, sead::Vector3f* p_kasa_pos, const sead::Vector3f& pos, f32 height, f32 stem_tex_size_y = 16.0f, Angle = 0);
};
