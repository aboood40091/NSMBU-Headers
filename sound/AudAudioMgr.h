#pragma once

#include <basis/seadTypes.h>

class AudFxSocket;

class AudAudioMgr
{
public:
    AudFxSocket* getFxSocket();

protected:
    u32 _0[0x18 / sizeof(u32)];
};
static_assert(sizeof(AudAudioMgr) == 0x18);
