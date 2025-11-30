#pragma once

#include <basis/seadTypes.h>

#include <nw/snd/snd_FxDelay.h>
#include <nw/snd/snd_FxReverbHi.h>

class AudFxSocket
{
public:
    nw::snd::FxReverbHi::ReverbHiParam& getReverbHiParam();
    nw::snd::FxDelay::DelayParam&       getDelayParam();
};
