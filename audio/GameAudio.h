#pragma once

#include <sound/SndObjectMap.h>

class GameAudio
{
public:
    // Address: 0x02029368
    static void convertAudioObjctPos(sead::Vector2f* p_screen_pos, const sead::Vector2f& bg_pos);

    static void convertAudioObjctPos(sead::Vector2f* p_screen_pos, const sead::Vector3f& bg_pos)
    {
        convertAudioObjctPos(p_screen_pos, sead::Vector2f(bg_pos.x, bg_pos.y));
    }

public:
    class AudioObjctCmnMap : public SndObjctCmnMap
    {
    public:
        AudioObjctCmnMap(nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
            : SndObjctCmnMap(line_flag)
        {
        }

        void startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnMap::startSound(label, screen_pos, line_flag);
        }

        void startSound(const char* label, const sead::Vector3f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnMap::startSound(label, screen_pos, line_flag);
        }

        void startSound(const char* label, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnMap::startSound(label, screen_pos, seq_var, line_flag);
        }

        void startSound(const char* label, const sead::Vector3f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnMap::startSound(label, screen_pos, seq_var, line_flag);
        }

        void holdSound(const char* label, s32 handle_id, const sead::Vector2f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnMap::holdSound(label, handle_id, screen_pos, line_flag);
        }

        void holdSound(const char* label, s32 handle_id, const sead::Vector3f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnMap::holdSound(label, handle_id, screen_pos, line_flag);
        }

        void holdSound(const char* label, s32 handle_id, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnMap::holdSound(label, handle_id, screen_pos, seq_var, line_flag);
        }

        void holdSound(const char* label, s32 handle_id, const sead::Vector3f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnMap::holdSound(label, handle_id, screen_pos, seq_var, line_flag);
        }
    };
    static_assert(sizeof(AudioObjctCmnMap) == sizeof(SndObjctCmnMap));

public:
    static AudioObjctCmnMap* getAudioObjMap() { return sAudioObjMap; }

private:
    // Address: 0x101C63D0
    static AudioObjctCmnMap* sAudioObjMap;
};
