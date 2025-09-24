#pragma once

#include <sound/AudAudioMgr.h>

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

#include <nw/snd/snd_SoundArchive.h>
#include <nw/snd/snd_SoundHandle.h>

class SndAudioMgr : public AudAudioMgr
{
    SEAD_SINGLETON_DISPOSER(SndAudioMgr)

public:
    // Address: 0x029B3BA8
    nw::snd::SoundArchive* getSoundArchive();

    // Address: 0x029B3D8C
    bool isSndPlaying(const char* label);

    // Address: 0x029B54C0
    bool startSystemSe(const char* label, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN);

    // Address: 0x029B5434
    bool startSound(nw::snd::SoundHandle* p_handle, const char* label, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN);

    // Address: 0x029B5934
    void startDrcTouchSound(const sead::Vector2f& world_pos, u32 type);
};
