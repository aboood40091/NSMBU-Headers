#pragma once

#include <sound/AudAudioMgr.h>

#include <heap/seadDisposer.h>

#include <nw/snd/snd_SoundArchive.h>

class SndAudioMgr : public AudAudioMgr
{
    SEAD_SINGLETON_DISPOSER(SndAudioMgr)

public:
    // Address: 0x029B3BA8
    nw::snd::SoundArchive* getSoundArchive();
};
