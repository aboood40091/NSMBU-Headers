#pragma once

#include <sound/SndObjectEnemy.h>
#include <sound/SndObjectMap.h>
#include <sound/SndObjectPlayer.h>

class GameAudio
{
public:
    // Address: 0x02029368
    static void convertAudioObjctPos(sead::Vector2f* p_screen_pos, const sead::Vector2f& bg_pos);

    static void convertAudioObjctPos(sead::Vector2f* p_screen_pos, const sead::Vector3f& bg_pos)
    {
        convertAudioObjctPos(p_screen_pos, sead::Vector2f(bg_pos.x, bg_pos.y));
    }

    // Address: 0x02029ACC
    static void setClapSE();

public:
    class AudioObjctEmy : public SndObjctEmy
    {
    public:
        AudioObjctEmy(ObjType type = ObjType(0), nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
            : SndObjctEmy(type, line_flag)
        {
        }

        void startSound(const char* label, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            SndObjctEmy::startSound(label, line_flag);
        }

        void holdSound(const char* label, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            SndObjctEmy::holdSound(label, line_flag);
        }

        void startSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            SndObjctEmy::startSound(label, seq_var, line_flag);
        }

        void holdSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            SndObjctEmy::holdSound(label, seq_var, line_flag);
        }

        void startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctEmy::startSound(label, screen_pos, line_flag);
        }

        void startSound(const char* label, const sead::Vector3f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctEmy::startSound(label, screen_pos, line_flag);
        }

        void holdSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctEmy::holdSound(label, screen_pos, line_flag);
        }

        void holdSound(const char* label, const sead::Vector3f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctEmy::holdSound(label, screen_pos, line_flag);
        }
    };
    static_assert(sizeof(AudioObjctEmy) == sizeof(SndObjctEmy));

    class AudioObjctCmnEmy : public SndObjctCmnEmy
    {
    public:
        AudioObjctCmnEmy(nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
            : SndObjctCmnEmy(line_flag)
        {
        }

        void startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnEmy::startSound(label, screen_pos, line_flag);
        }

        void startSound(const char* label, const sead::Vector3f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnEmy::startSound(label, screen_pos, line_flag);
        }

        void startSound(const char* label, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnEmy::startSound(label, screen_pos, seq_var, line_flag);
        }

        void startSound(const char* label, const sead::Vector3f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnEmy::startSound(label, screen_pos, seq_var, line_flag);
        }

        void holdSound(const char* label, s32 handle_id, const sead::Vector2f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnEmy::holdSound(label, handle_id, screen_pos, line_flag);
        }

        void holdSound(const char* label, s32 handle_id, const sead::Vector3f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnEmy::holdSound(label, handle_id, screen_pos, line_flag);
        }

        void holdSound(const char* label, s32 handle_id, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnEmy::holdSound(label, handle_id, screen_pos, seq_var, line_flag);
        }

        void holdSound(const char* label, s32 handle_id, const sead::Vector3f& pos, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctCmnEmy::holdSound(label, handle_id, screen_pos, seq_var, line_flag);
        }
    };
    static_assert(sizeof(AudioObjctCmnEmy) == sizeof(SndObjctCmnEmy));

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

    class AudioObjctPly : public SndObjctPly
    {
    public:
        AudioObjctPly(ObjType type = ObjType(0), nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
            : SndObjctPly(type, line_flag)
        {
        }

        void startSound(const char* label, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            SndObjctPly::startSound(label, line_flag);
        }

        void holdSound(const char* label, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            SndObjctPly::holdSound(label, line_flag);
        }

        void startSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            SndObjctPly::startSound(label, seq_var, line_flag);
        }

        void holdSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            SndObjctPly::holdSound(label, seq_var, line_flag);
        }

        void startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctPly::startSound(label, screen_pos, line_flag);
        }

        void startSound(const char* label, const sead::Vector3f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctPly::startSound(label, screen_pos, line_flag);
        }

        void holdSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN) override
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctPly::holdSound(label, screen_pos, line_flag);
        }

        void holdSound(const char* label, const sead::Vector3f& pos, nw::snd::OutputLine line_flag = nw::snd::OUTPUT_LINE_MAIN)
        {
            sead::Vector2f screen_pos;
            convertAudioObjctPos(&screen_pos, pos);
            SndObjctPly::holdSound(label, screen_pos, line_flag);
        }
    };
    static_assert(sizeof(AudioObjctPly) == sizeof(SndObjctPly));

public:
    static AudioObjctCmnEmy* getAudioObjEmy() { return sAudioObjEmy; }
    static AudioObjctCmnMap* getAudioObjMap() { return sAudioObjMap; }

private:
    // Address: 0x101C63CC
    static AudioObjctCmnEmy* sAudioObjEmy;
    // Address: 0x101C63D0
    static AudioObjctCmnMap* sAudioObjMap;
};
