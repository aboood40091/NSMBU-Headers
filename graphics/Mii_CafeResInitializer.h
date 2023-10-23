#pragma once

#include <heap/seadHeap.h>

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
    void*       mpWorkMemory;
    sead::Heap* mpWorkMemoryHeap;
    sead::Heap* mpGraphicsHeap;
    u8*         mpFFLShaderData;
    bool        _10;
};
static_assert(sizeof(CafeResInitializer) == 0x14);

}
