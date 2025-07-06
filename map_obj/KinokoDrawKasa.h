#pragma once

#include <container/seadSafeArray.h>

class AnimModel;

class KinokoDrawKasa
{
public:
    // Address: 0x027A5008
    KinokoDrawKasa();

    // Address: 0x027A5444
    void calc(const sead::Matrixf& mtx, f32 offset_y = 0.0f);

protected:
    sead::SafeArray<AnimModel*, 3>  mAnimModel;
    f32                             mMidHalfWidth;
    bool                            _10;
};
static_assert(sizeof(KinokoDrawKasa) == 0x14);
