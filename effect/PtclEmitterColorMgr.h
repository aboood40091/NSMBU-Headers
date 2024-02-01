#pragma once

#include <container/seadSafeArray.h>
#include <gfx/seadColor.h>
#include <heap/seadDisposer.h>

namespace nw { namespace eft {

class EmitterController;

} }

class PtclEmitterColorMgr : public sead::IDisposer // vtbl Address: 0x10058888
{
    static const s32 cColorMax = 6;

public:
    // Address: 0x022ABFC0
    PtclEmitterColorMgr();
    virtual ~PtclEmitterColorMgr() {}

    // Address: 0x022AC078
    bool updateAmbientLight(bool update_emitter = true);
    // Address: 0x022AC160
    void setEmitterColor(nw::eft::EmitterController* emitter_controller, u16 user_data_bit);

private:
    sead::UnsafeArray<sead::Color4f, cColorMax> mLightColor;
};
static_assert(sizeof(PtclEmitterColorMgr) == 0x70);
