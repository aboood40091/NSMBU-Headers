#pragma once

#include <graphics/ModelFFL.h>

#include <container/seadPtrArray.h>
#include <layer/aglDrawMethod.h>
#include <thread/seadCriticalSection.h>
#include <thread/seadEvent.h>

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
    // Address: 0x024E9CB8
    void pushBack(sead::Event* p_event);

    // Address: 0x024E9D6C
    void calc();

private:
    // Address: 0x024E9E08
    void initializeGpu_();

    // Address: 0x024E9EC4
    void initializeGpuDrawMethod_(const agl::lyr::RenderInfo& render_info);

private:
    enum ElementType
    {
        cElementType_ModelFFL = 0,
        cElementType_SeadEvent
    };
    static_assert(sizeof(ElementType) == 4);

    struct Element
    {
        Element(ModelFFL* p_model)
            : type(cElementType_ModelFFL)
            , element(p_model)
        {
        }

        Element(sead::Event* p_event)
            : type(cElementType_SeadEvent)
            , element(p_event)
        {
        }

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
