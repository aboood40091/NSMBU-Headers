#pragma once

#include <basis/seadTypes.h>

#include <nw/snd.h>

class AudFxSocket
{
public:
    nw::snd::FxReverbHi::ReverbHiParam& getReverbHiParam();
    nw::snd::FxDelay::DelayParam&       getDelayParam();
};
