#pragma once

#include <game/SelectCursorType.h>
#include <input/SysControllerWrapper.h>
#include <layout_sys/UtilCursorButtonMgr.h>
#include <state/FStateMgr.h>

#include <container/seadSafeArray.h>
#include <prim/seadSafeString.h>

class PaCursor  // vtbl Address: 0x100D6B34
{
public:
    static const s32 cButtonMax = 41;

public:
    // Address: 0x025F8024
    PaCursor();
    // Address: 0x025F8230
    virtual ~PaCursor();

    bool isNoPadInput() const
    {
        return mIsNoPadInput;
    }

    // Address: 0x025F8788
    void triggerDecide();

    void resetDecideTrig()
    {
        mIsDecideTrig = false;
    }

protected:
    FStateMgr<PaCursor>                 mStateMgr;
    UtilCursorButtonMgr                 mButtonMgr;
    SysControllerWrapper                mController;
    sead::SafeArray<u8, cButtonMax>     _1ec;
    sead::SafeArray<u8, cButtonMax>     _215;
    sead::SafeString                    mParentName;
    sead::Vector2f                      mPointerPos;
    s32                                 mButtonIdx1;        // Current
    s32                                 mButtonIdx2;        // Previous?
    SelectCursorType                    mSelectCursorType;
    bool                                mIsDecideAnime;     // Maybe?
    bool                                _25d;
    bool                                mIsNoPadInput;
    bool                                mIsDecideTrig;
    bool                                _260;
    bool                                _261;
    bool                                mIsDpadTrig;
    bool                                _263[9];
    sead::SafeArray<u32, cButtonMax>    mButtonState;       // Maybe?
};
static_assert(sizeof(PaCursor) == 0x314);
