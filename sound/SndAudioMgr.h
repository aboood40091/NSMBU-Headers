#pragma once

#include <sound/AudAudioMgr.h>
#include <sound/SndItemID.h>

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

#include <nw/snd/snd_SoundArchive.h>
#include <nw/snd/snd_SoundHandle.h>

class SndAudioMgr : public AudAudioMgr  // vtbl Address: 0x1017C814
{
    SEAD_SINGLETON_DISPOSER(SndAudioMgr)

public:
    struct Arg;

public:
    // Address: 0x029B41AC
    virtual void initialize(const Arg& arg);
    // Address: 0x029B4FFC
    virtual void calc();
    // Address: Deleted
    virtual void vf1C();
    // Address: 0x029B6B10
    virtual bool startSoundImpl(nw::snd::SoundHandle* p_handle, const char* label);
    // ...

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

    // Address: 0x029B7548
    bool loadData(SndItemID item_id);

private:
    u32 _28[(0x3D0 - 0x28) / sizeof(u32)];
};
static_assert(sizeof(SndAudioMgr) == 0x3D4);
