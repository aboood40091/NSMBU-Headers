#pragma once

#include <container/seadSafeArray.h>
#include <gfx/seadColor.h>
#include <heap/seadDisposer.h>

namespace nw { namespace eft {

class EmitterController;

} }

class PtclEmitterColorMgr : public sead::IDisposer
{
public:
    PtclEmitterColorMgr();
    virtual ~PtclEmitterColorMgr() {}

    bool updateAmbientLight(bool update_emitter = true);
    void setEmitterColor(nw::eft::EmitterController* p_emitter_controller, u16 user_data);

private:
    sead::UnsafeArray<sead::Color4f, 6> mLightColor;
};
static_assert(sizeof(PtclEmitterColorMgr) == 0x70);
