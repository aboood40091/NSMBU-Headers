#pragma once

#include <graphics/Mii_SlotID.h>
#include <player/PlayerEnum.h>
#include <sound/SndObjectCommon.h>

class SndObjctPly : public NMSndObject
{
public:
    SndObjctPly(ObjType type, nw::snd::OutputLine line_flag)
        : NMSndObject(type, line_flag)
        , mVoice(cVoice_Num)
        , mPlyMode(cPlayerMode_Num)
        , _124(0)
    {
    }

    // Address: 0x029BF2D4
    void startSound(const char* label, nw::snd::OutputLine line_flag) override;
    // Address: 0x029BF2D8
    void holdSound(const char* label, nw::snd::OutputLine line_flag) override;
    
    // Address: 0x029BF2DC
    void startSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag) override;
    // Address: 0x029BF2E0
    void holdSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag) override;
    
    // Address: 0x029BF2E4
    void startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag) override;
    // Address: Deleted
    void holdSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag) override;

    // Address: 0x029BF550
    void startFootSound(const char* label, f32, nw::snd::OutputLine line_flag);

    // Address: 0x029BF7FC
    void startPlyVoiceSound(PlayerVoiceID voice_id, nw::snd::OutputLine line_flag);

    // Address: 0x029BFA9C
    void stopPlyJumpSound();

    static PlayerCharacterVoice getMiiCharacterVoice(const Mii::SlotID& slot_id);

protected:
    PlayerCharacterVoice    mVoice;
    PlayerMode              mPlyMode;
    u8                      _124;
};
static_assert(sizeof(SndObjctPly) == 0x128);
