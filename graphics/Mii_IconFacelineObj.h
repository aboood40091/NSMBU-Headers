#pragma once

#include <graphics/RenderObj.h>

#include <common/aglIndexStream.h>
#include <common/aglVertexAttribute.h>
#include <common/aglVertexBuffer.h>

namespace Mii {

class IconRenderBuffer;

class IconFacelineObj : public RenderObj    // vtbl Address: 0x100BBF7C
{
public:
    struct Vertex
    {
        sead::Vector3f  position;
        sead::Vector2f  tex_coord;
        sead::Vector4f  vertex_color;
    };
    static_assert(sizeof(Vertex) == 0x24);

public:
    // Address: 0x024E8A78
    IconFacelineObj();

public:
    // Address: 0x024E9074
    void calc() override;
    // Address: 0x024E8B58
    void updateView(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;
    // Address: 0x024E8B5C
    void calcGPU(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;
    // Address: 0x024E8B60
    void drawOpa(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;
    // Address: 0x024E8B64
    void drawXlu(s32 view_index, const sead::Matrix34f& view_mtx, const sead::Matrix44f& proj_mtx, RenderMgr* p_render_mgr) override;

public:
    virtual ~IconFacelineObj()
    {
        destroy();
    }

    // Address: 0x024E8DE8
    bool initialize(const IconRenderBuffer* p_render_buffer);
    // Address: 0x024E9070
    void destroy();

    // Address: 0x024E8E50
    void setPosition(const sead::Vector3f& position);

    // Address: 0x024E8EB0
    void setVertex(const Vertex* p_vertex, u32 num);

private:
    // Address: 0x024E89FC
    void clearVertex_();

    // Address: 0x024E8D0C
    void setupVertex_();
    // Address: 0x024E8CA0
    void setupIndex_();

private:
    agl::VertexBuffer               mVertexBuffer;
    agl::VertexAttribute            mVertexAttribute;
    agl::IndexStream                mIndexStream;
    sead::UnsafeArray<Vertex,   4>  mVertex;
    sead::UnsafeArray<u32,      6>  mIndex;
    u32                             _398;   // Unused?
    u32                             _39c;   // ^^^
    const IconRenderBuffer*         mpRenderBuffer;
    sead::Matrix34f                 mWorldMtx;
};
static_assert(sizeof(IconFacelineObj) == 0x3D4);

}
