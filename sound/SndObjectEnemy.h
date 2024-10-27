#pragma once

#include <sound/SndObjectCommon.h>

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
