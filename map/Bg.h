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

    u64 getBgCheckData(u16 x, u16 y, u8 layer, bool with_p_sw = true);  // See BgUnitCode
    u64 getBgCheckData(f32 x, f32 y, u8 layer, bool with_p_sw = true)   // ^^^
    {
        return getBgCheckData(u16(x), u16(-y), layer, with_p_sw);
    }

    BgUnitCode::HitType getUnitHitType(u16 x, u16 y, u8 layer);
    BgUnitCode::HitType getUnitHitType(f32 x, f32 y, u8 layer)
    {
        return getUnitHitType(u16(x), u16(-y), layer);
    }

    BgUnitCode::Type getUnitType(u16 x, u16 y, u8 layer);
    BgUnitCode::Type getUnitType(f32 x, f32 y, u8 layer)
    {
        return getUnitType(u16(x), u16(-y), layer);
    }

    BgUnitCode::TypeInfo getUnitTypeInfo(u16 x, u16 y, u8 layer);
    BgUnitCode::TypeInfo getUnitTypeInfo(f32 x, f32 y, u8 layer)
    {
        return getUnitTypeInfo(u16(x), u16(-y), layer);
    }

    void setWaterInWave(const sead::Vector2f& pos, u8 wave_scale);
};
