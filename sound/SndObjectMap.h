#pragma once

#include <sound/SndObjectCommon.h>

class SndObjctCmnMap : public NMSndObjectCmn
{
public:
    SndObjctCmnMap(nw::snd::OutputLine line_flag)
        : NMSndObjectCmn(line_flag)
    {
    }

    // Address: 0x029BECD4
    virtual ~SndObjctCmnMap();

    // Address: 0x029BED48
    void startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag) override;
    // Address: 0x029BED4C
    void startSound(const char* label, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag) override;

    // Address: 0x029BED50
    void holdSound(const char* label, s32 handle_id, const sead::Vector2f& pos, nw::snd::OutputLine line_flag);
    // Address: 0x029BEE18
    void holdSound(const char* label, s32 handle_id, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag);
};
static_assert(sizeof(SndObjctCmnMap) == sizeof(NMSndObjectCmn));
