#pragma once

#include <heap/seadHeap.h>

#include <nw/ut/ut_Memory.h>

class LayoutAllocator : public nw::ut::IAllocator // vtbl Address: 0x100E38C0
{
public:
    // GetRuntimeTypeInfoStatic()::s_TypeInfo initialization guard variable Address: 0x101E9DC4
    // GetRuntimeTypeInfoStatic()::s_TypeInfo                               Address: 0x101EAF40
    NW_UT_RUNTIME_TYPEINFO(nw::ut::IAllocator)

    LayoutAllocator()
        : mpHeap(nullptr)
    {
    }

    // Address: 0x02679708
    void* Alloc(size_t size, u32 alignment) override;
    // Address: 0x0267971C
    void  Free(void* memory) override;

    // Address: 0x02679730
    void setHeap(sead::Heap* heap);

protected:
    sead::Heap* mpHeap;
};
static_assert(sizeof(LayoutAllocator) == 8);
