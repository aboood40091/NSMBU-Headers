#pragma once

#include <heap/seadDisposer.h>
#include <thread/seadDelegateThread.h>

struct FFLStoreData;

class SaveMgr
{
    SEAD_SINGLETON_DISPOSER(SaveMgr)

public:
    enum Status
    {
        cStatus_Ready = 0,
        cStatus_Reading,
        cStatus_Writing
    };
    static_assert(sizeof(Status) == 4);

    enum ReadError
    {
        cReadError_OK                       = 0,
        cReadError_FileDeviceUnavailable    = 1,
        cReadError_FileUnavailable          = -1,
        cReadError_FileInvalid              = -2
    };
    static_assert(sizeof(ReadError) == 4);

    enum WriteError
    {
        cWriteError_OK                      = 0,
        cWriteError_FileDeviceUnavailable   = -1,
        cWriteError_FileWriteFailed         = -2
    };
    static_assert(sizeof(WriteError) == 4);

public:
    SaveMgr();
    virtual ~SaveMgr();

    bool isSaving() const
    {
        return mStatus == cStatus_Writing || _30 != -1;
    }

    bool isSavingDone() const
    {
        return mStatus != cStatus_Writing;
    }

    const FFLStoreData& getStoreData(s32 index) const;

    void startSaveGame(u8 file);
    void startQuickSaveGame(u8 file);

protected:
    sead::DelegateThread*   mpDelegateThread;
    Status                  mStatus;
    ReadError               mReadError;
    WriteError              mWriteError;
    s32                     _20;                    // enum ?
    void*                   mpSavedata;             // rp_savedata
    void*                   mpPersonalSavedata;     // rp_personal_savedata
    bool                    mButtonLayoutChanged;
    u8                      _2d;
    u8                      _2e;
    u8                      _2f;
    s32                     _30;
    s64                     mInitTime;              // sead::DateTime
    s64                     mStoryPlayInitTime;     // sead::DateTime

};
static_assert(sizeof(SaveMgr) == 0x50);
