#pragma once

#include <collision/BgCheckUnitInfo.h>

#include <heap/seadDisposer.h>

class Bg
{
    SEAD_SINGLETON_DISPOSER(Bg)

public:
    Bg();
    virtual ~Bg();

    static u16* getUnit(u16 x, u16 y, u32 file, u8 layer, s32* p_block_idx = nullptr);
    static u16* getUnitCurrentCdFile(u16 x, u16 y, u8 layer, s32* p_block_idx = nullptr);

    BgCheckUnitInfo getBgCheckData(u16 x, u16 y, u8 layer, bool with_p_sw = true);

    BgCheckUnitInfo::SolidType getUnitSolidType(u16 x, u16 y, u8 layer);
    BgCheckUnitInfo::SolidType getUnitSolidType(f32 x, f32 y, u8 layer)
    {
        return getUnitSolidType(u16(x), u16(-y), layer);
    }
};
