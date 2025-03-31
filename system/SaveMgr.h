#pragma once

#include <heap/seadDisposer.h>
#include <thread/seadDelegateThread.h>

struct SaveData
{
    struct
    {
        u32 magic;
        u8  version_major;
        u8  version_minor;
        u8  version_patch;
        u8  last_file;
        u8  rdash_state;    // 1 -> The game has notified you about the NSLU DLC.
        u8  set_up;         // AB/XY & AX/BY setup
        u8  padding[2];
        u32 crc32;
    }   header;
    u32 _10[(0xB134 - 0x10) / sizeof(u32)];
};
static_assert(sizeof(SaveData) == 0xB134);

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

    void startSaveGame()
    {
        startSaveGame(mpSavedata->header.last_file);
    }

    void startQuickSaveGame()
    {
        startQuickSaveGame(mpSavedata->header.last_file);
    }

protected:
    sead::DelegateThread*   mpDelegateThread;
    Status                  mStatus;
    ReadError               mReadError;
    WriteError              mWriteError;
    s32                     _20;                    // enum ?
    const SaveData*         mpSavedata;             // rp_savedata
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
