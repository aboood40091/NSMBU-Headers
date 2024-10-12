#pragma once

#include <sound/SndObjectMap.h>

class GameAudio
{
public:
    // Address: 0x02029368
    static sead::Vector2f convertAudioObjctPos(const sead::Vector2f& bg_pos);

    static sead::Vector2f convertAudioObjctPos(const sead::Vector3f& bg_pos)
    {
        return convertAudioObjctPos(sead::Vector2f(bg_pos.x, bg_pos.y));
    }

public:
    class AudioObjctCmnMap : public SndObjctCmnMap
    {
    public:
        AudioObjctCmnMap(nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
            : SndObjctCmnMap(line_flag)
        {
        }

        nw::snd::SoundHandle* startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            return SndObjctCmnMap::startSound(label, convertAudioObjctPos(pos), line_flag);
        }

        nw::snd::SoundHandle* startSound(const char* label, const sead::Vector3f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            return SndObjctCmnMap::startSound(label, convertAudioObjctPos(pos), line_flag);
        }

        nw::snd::SoundHandle* startSound(const char* label, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            return SndObjctCmnMap::startSound(label, convertAudioObjctPos(pos), seq_var, line_flag);
        }

        nw::snd::SoundHandle* startSound(const char* label, const sead::Vector3f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            return SndObjctCmnMap::startSound(label, convertAudioObjctPos(pos), seq_var, line_flag);
        }

        void holdSound(const char* label, s32 handle_index, const sead::Vector2f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            return SndObjctCmnMap::holdSound(label, handle_index, convertAudioObjctPos(pos), line_flag);
        }

        void holdSound(const char* label, s32 handle_index, const sead::Vector3f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            return SndObjctCmnMap::holdSound(label, handle_index, convertAudioObjctPos(pos), line_flag);
        }

        void holdSound(const char* label, s32 handle_index, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            return SndObjctCmnMap::holdSound(label, handle_index, convertAudioObjctPos(pos), seq_var, line_flag);
        }

        void holdSound(const char* label, s32 handle_index, const sead::Vector3f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            return SndObjctCmnMap::holdSound(label, handle_index, convertAudioObjctPos(pos), seq_var, line_flag);
        }
    };
    static_assert(sizeof(AudioObjctCmnMap) == sizeof(SndObjctCmnMap));

public:
    // Address: 0x101C63D0
    static AudioObjctCmnMap* sAudioObjMap;
};
