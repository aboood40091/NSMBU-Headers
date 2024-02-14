#pragma once

#include <audio/cafe/seadAudioPlayerCafe.h>

class AudAudioPlayer : public sead::AudioPlayerCafe
{
public:
    AudAudioPlayer();
    virtual ~AudAudioPlayer();

    void initialize() override;
    void finalize() override;
    void calc() override;
};
static_assert(sizeof(AudAudioPlayer) == sizeof(sead::AudioPlayerCafe));
