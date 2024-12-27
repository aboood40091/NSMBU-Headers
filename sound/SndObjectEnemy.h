#pragma once

#include <sound/SndObjectCommon.h>

class SndObjctEmy : public NMSndObject
{
public:
    SndObjctEmy(ObjType type, nw::snd::OutputLine line_flag)
        : NMSndObject(type, line_flag)
    {
    }

    // Address: 0x029BE940
    void startSound(const char* label, nw::snd::OutputLine line_flag) override;
    // Address: 0x029BE9E8
    void holdSound(const char* label, nw::snd::OutputLine line_flag) override;
    
    // Address: 0x029BE9EC
    void startSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag) override;
    // Address: 0x029BEA9C
    void holdSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag) override;
    
    // Address: 0x029BEAA0
    void startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag) override;
    // Address: 0x029BEAA4
    void holdSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag) override;
};
static_assert(sizeof(SndObjctEmy) == sizeof(NMSndObject));

class SndObjctCmnEmy : public NMSndObjectCmn
{
public:
    SndObjctCmnEmy(nw::snd::OutputLine line_flag)
        : NMSndObjectCmn(line_flag)
    {
    }

    // Address: 0x029BEB48
    void startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag) override;
    // Address: 0x029BEB4C
    void startSound(const char* label, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag) override;

    // Address: 0x029BEB50
    void holdSound(const char* label, s32 handle_id, const sead::Vector2f& pos, nw::snd::OutputLine line_flag);
    // Address: 0x029BEB54
    void holdSound(const char* label, s32 handle_id, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag);
};
static_assert(sizeof(SndObjctCmnEmy) == sizeof(NMSndObjectCmn));
