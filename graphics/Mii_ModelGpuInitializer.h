#pragma once

#include <container/seadPtrArray.h>
#include <layer/aglDrawMethod.h>
#include <thread/seadCriticalSection.h>

class ModelFFL;

namespace Mii {

class ModelGpuInitializer
{
public:
    // Address: 0x024E9974
    ModelGpuInitializer();
    // Address: 0x024E9B28
    ~ModelGpuInitializer();

    // Address: 0x024E9BA4
    void initialize(sead::Heap* heap = nullptr);

    // Address: 0x024E9C04
    void pushBack(ModelFFL* p_model);

private:
    enum ElementType
    {
        cElementType_ModelFFL = 0,
        cElementType_SeadEvent
    };
    static_assert(sizeof(ElementType) == 4);

    struct Element
    {
        ElementType type;
        void*       element;
    };
    static_assert(sizeof(Element) == 8);

    sead::Heap*                         mpHeap;
    sead::FixedPtrArray<Element, 64>    mElement;
    sead::FixedPtrArray<Element, 64>    mDoubleBuffer[2];
    s32                                 mDoubleBufferIndex;
    agl::lyr::DrawMethod                mDrawMethod;
    sead::CriticalSection               mCriticalSection;
};
static_assert(sizeof(ModelGpuInitializer) == 0x3A8);

}
