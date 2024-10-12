#pragma once

#include <sound/Snd2DCalc.h>
#include <sound/SndObjectBase.h>

#include <heap/seadDisposer.h>
#include <math/seadVector.h>

#include <nw/snd/snd_SoundHandle.h>

class NMSndObject : public NMSndObjectBase
{
public:
    static const u32 cPlayableSoundNum = 4;
    static const u32 cHandleNum = cPlayableSoundNum + cExtraHandleNum;

public:
    class SoundHandlePrm : public sead::IDisposer
    {
    public:
        SoundHandlePrm()
            : mVolume(1.0f)
        {
        }

        virtual ~SoundHandlePrm()
        {
        }

    private:
        nw::snd::SoundHandle    mSoundHandle;
        f32                     mVolume;

        friend class NMSndObject;
    };
    static_assert(sizeof(SoundHandlePrm) == 0x18);

public:
    // Address: 0x029BC52C
    NMSndObject(ObjType type, nw::snd::OutputLine line_flag);

    // Address: 0x029BC8C8
    virtual nw::snd::SoundHandle* startSound(const char* label, nw::snd::OutputLine line_flag);
    // Address: 0x029BCC3C
    virtual nw::snd::SoundHandle* startSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag);
    // Address: 0x029BCFA4
    virtual nw::snd::SoundHandle* startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag);

    // Address: 0x029BCAC4
    virtual void holdSound(const char* label, nw::snd::OutputLine line_flag);
    // Address: 0x029BCDE8
    virtual void holdSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag);
    // Address: 0x029BD148
    virtual void holdSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag);

    // Address: 0x029bc850
    virtual void calc(const sead::Vector2f& pos);

protected:
    Snd2DCalc::Param    mSnd2DCalcPrm;
    SoundHandlePrm      mSoundHandlePrm[cHandleNum];
    sead::Vector2f      mPos;
};
static_assert(sizeof(NMSndObject) == 0x11C);

class NMSndObjectCmn : public NMSndObjectBase   // vtbl Address: 0x1017DDEC
{
public:
    static const u32 cPlayableSoundNum = 12;
    static const u32 cHandleNum = cPlayableSoundNum + cExtraHandleNum;

public:
    class SoundHandlePrm    // Name unknown
    {
    public:
        SoundHandlePrm()
            : mID(-1)
            , _c(1.0f)
            , mPriority(64)
        {
        }

    private:
        nw::snd::SoundHandle    mSoundHandle;
        s32                     mID;
        f32                     mVolume;
        f32                     _c;
        s32                     mPriority;

        friend class NMSndObjectCmn;
    };
    static_assert(sizeof(SoundHandlePrm) == 0x14);

public:
    // Address: 0x029BD358
    NMSndObjectCmn(nw::snd::OutputLine line_flag);

    // Address: 0x029BD65C
    virtual nw::snd::SoundHandle* startSound(const char* label, const sead::Vector2f& pos, nw::snd::OutputLine line_flag);
    // Address: 0x029BDA2C
    virtual nw::snd::SoundHandle* startSound(const char* label, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag);

    // Address: 0x029BDE98
    void holdSound(const char* label, s32 handle_id, const sead::Vector2f& pos, nw::snd::OutputLine line_flag);
    // Address: 0x029BE094
    void holdSound(const char* label, s32 handle_id, const sead::Vector2f& pos, s16 seq_var, nw::snd::OutputLine line_flag);

protected:
    SoundHandlePrm  mSoundHandlePrm[cHandleNum];
};
static_assert(sizeof(NMSndObjectCmn) == 0x18C);

class NMNonPosSndObject : public NMSndObjectBase   // vtbl Address: 0x1017DE34
{
public:
    class SoundHandlePrm
    {
    public:
        SoundHandlePrm()
        {
        }

    private:
        nw::snd::SoundHandle    mSoundHandle;

        friend class NMNonPosSndObject;
    };
    static_assert(sizeof(SoundHandlePrm) == 4);

public:
    // Address: 0x029BE2F0
    NMNonPosSndObject(nw::snd::OutputLine line_flag, s32 playable_sound_num);
    // Address: 0x029BE3A4
    virtual ~NMNonPosSndObject();

    // Address: 0x029BE428
    virtual nw::snd::SoundHandle* startSound(const char* label, nw::snd::OutputLine line_flag);
    // Address: Deleted
    virtual nw::snd::SoundHandle* startSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag);

    // Address: 0x029BE578
    virtual void holdSound(const char* label, nw::snd::OutputLine line_flag);
    // Address: 0x029BE648
    virtual void holdSound(const char* label, s16 seq_var, nw::snd::OutputLine line_flag);

protected:
    SoundHandlePrm* mpSoundHandlePrm;
};
static_assert(sizeof(NMNonPosSndObject) == 0x78);
