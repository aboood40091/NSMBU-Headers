#pragma once

#include <heap/seadHeap.h>

#include <nn/ffl.h>

namespace Mii {

class CafeResInitializer
{
public:
    // Address: 0x024E7990
    CafeResInitializer(bool param);

    // Address: 0x024E7B7C
    bool initialize();
    // Address: 0x024E7E7C
    void destroy();

private:
    // Address: 0x024E79E8
    bool createHeaps_(const FFLInitDesc* p_init_desc);
    // Address: 0x024E7E08
    void destroyHeaps_();

    // Address: 0x024E7AFC
    bool loadFFLShader_();
    // Address: 0x024E7DF0
    void unloadFFLShader_();

private:
    void*       mpWorkMemory;
    sead::Heap* mpWorkMemoryHeap;
    sead::Heap* mpGraphicsHeap;
    u8*         mpFFLShaderData;
    bool        _10;
};
static_assert(sizeof(CafeResInitializer) == 0x14);

}
