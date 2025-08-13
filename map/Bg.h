#pragma once

#include <collision/BgUnitCode.h>

#include <heap/seadDisposer.h>

class Bg
{
    SEAD_SINGLETON_DISPOSER(Bg)

public:
    Bg();
    virtual ~Bg();

    static u16* getUnit(u16 x, u16 y, u32 file, u8 layer, s32* p_block_idx = nullptr);
    static u16* getUnitCurrentCdFile(u16 x, u16 y, u8 layer, s32* p_block_idx = nullptr);

    BgUnitCode getBgCheckData(u16 x, u16 y, u8 layer, bool with_p_sw = true);

    BgUnitCode::HitType getHitType(u16 x, u16 y, u8 layer);
    BgUnitCode::HitType getHitType(f32 x, f32 y, u8 layer)
    {
        return getHitType(u16(x), u16(-y), layer);
    }

    void setWaterInWave(const sead::Vector2f& pos, u8 wave_scale);
};
