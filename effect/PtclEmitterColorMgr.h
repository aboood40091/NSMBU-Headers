#pragma once

#include <container/seadSafeArray.h>
#include <gfx/seadColor.h>
#include <heap/seadDisposer.h>

namespace nw { namespace eft {

class EmitterController;

} }

class PtclEmitterColorMgr : public sead::IDisposer // vtbl Address: 0x10058888
{
public:
    // Address: 0x022ABFC0
    PtclEmitterColorMgr();
    virtual ~PtclEmitterColorMgr() {}

    // Address: 0x022AC078
    bool updateAmbientLight(bool update_emitter = true);
    // Address: 0x022AC160
    void setEmitterColor(nw::eft::EmitterController* p_emitter_controller, u16 user_data);

private:
    sead::UnsafeArray<sead::Color4f, 6> mLightColor;
};
static_assert(sizeof(PtclEmitterColorMgr) == 0x70);
