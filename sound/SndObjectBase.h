#pragma once

#include <audio/seadAudioPlayer.h>

#include <nw/snd/snd_SoundActor.h>

class Snd2DCalc;

class NMSndObjectBase : public nw::snd::SoundActor  // vtbl Address: 0x1017DA3C
{
public:
    static const u32 cExtraHandleNum = 2;

public:
    enum ObjType
    {
        cObjType_Max = 3
    };

public:
    // Address: 0x029BBC44
    NMSndObjectBase(ObjType type, sead::AudioPlayer* p_player);
    // Address: 0x029BBBD8
    virtual ~NMSndObjectBase();

    // Address: 0x029BBE20
    virtual u8 vf34(const char* label, s32 actor_player_id);

protected:
    u32                 mHandleNum;
    nw::snd::OutputLine mOutputLine;
    Snd2DCalc*          mpSnd2DCalc;
    ObjType             mType;
};
static_assert(sizeof(NMSndObjectBase) == 0x74);
