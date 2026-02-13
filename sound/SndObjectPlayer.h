#pragma once

#include <graphics/Mii_SlotID.h>
#include <player/PlayerEnum.h>
#include <sound/SndObjectCommon.h>

class SndObjctPly : public NMSndObject
{
public:
    enum PlyMode
    {
        cPlyMode_Small = 0,
        cPlyMode_Normal,
        cPlyMode_Fire,
        cPlyMode_Mini,
        cPlyMode_Propeller,
        cPlyMode_Penguin,
        cPlyMode_Ice,
        cPlyMode_Squirrel,
        cPlyMode_PSquirrel,
        cPlyMode_Num
    };
    static_assert(cPlyMode_Num == 9);
    static_assert(sizeof(PlyMode) == 4);

public:
    SndObjctPly(ObjType type, nw::snd::OutputLine line_flag)
        : NMSndObject(type, line_flag)
        , mVoice(cVoice_Num)
        , mPlyMode(cPlyMode_Num)
        , _124(0)
    {
    }

    void setVoice(PlayerCharacterVoice voice)
    {
        mVoice = voice;
    }

    void setPlyMode(PlyMode mode)
    {
        mPlyMode = mode;
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

    // Address: 0x029BFB18
    static PlayerCharacterVoice getMiiCharacterVoice(const Mii::SlotID& slot_id);

protected:
    PlayerCharacterVoice    mVoice;
    PlyMode                 mPlyMode;
    u8                      _124;
};
static_assert(sizeof(SndObjctPly) == 0x128);
