#pragma once
#include "heap/seadHeap.h"
#include "heap/seadDisposer.h"
#include "thread/seadDelegateThread.h"
#include <save/RPSaveData.h>
#include <types.h>

class SaveMgr
{
    SEAD_SINGLETON_DISPOSER(SaveMgr)
public:
    SaveMgr(sead::Heap* heap);

    enum ReadError
    {
        cReadError_Ok                          = 0x0,
        cReadError_ErrorFileDeviceUnavailable  = 0x1,
        cReadError_FileInvalid                 = 0xfffffffe,
        cReadError_ErrorFileUnavailable        = 0xffffffff,
    };

    enum WriteError
    {
        cWriteError_Ok                           = 0x0,
        cWriteError_ErrorFileWriteFailed         = 0xfffffffe,
        cWriteError_ErrorFileDeviceUnavailable   = 0xffffffff,
    };

private:
    sead::DelegateThread*   mThread;
    u32                     mSaveStatus;
    u32                     mReadError;
    u32                     mWriteError;
    u32                     mUnk;
    RPSaveData*             mSaveData;
    u32                     mRP_Personal_SaveData;
    u8                      _2C[0x50 - 0x2C];
};
static_assert(sizeof(SaveMgr) == 0x50);