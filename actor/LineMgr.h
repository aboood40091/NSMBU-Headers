#pragma once

#include <state/FStateMgr.h>
#include <utility/Angle.h>
#include <utility/Direction.h>

#include <container/seadSafeArray.h>
#include <math/seadVector.h>

class LineMgr
{
public:
    enum Type
    {
        cType_ReverseAtEnd = 0, // i.e., Two-way
        cType_StopAtEnd         // i.e., One-way
    };

public:
    // Address: 0x0200DC14
    LineMgr();

    // Address: 0x0200DF60
    void init(const sead::Vector2f& pos, u8 layer, f32 base_speed = 0.0f, Type type = cType_ReverseAtEnd, u8 dir_x = cDirType_Right);

    // Address: 0x0200E0C0
    void setBaseSpeed(f32 speed);

    // Address: 0x0200E178
    void startLineMove(bool exec_fall_down = false);

    void execute()
    {
        mStateMgr.executeState();
    }

    const sead::Vector2f& getPos() const
    {
        return mPos;
    }

protected:
    FStateMgr<LineMgr>                      mStateMgr;
    sead::UnsafeArray<sead::Vector2f, 7>    _24;
    sead::Vector2f                          mSpeed;
    sead::Vector2f                          mPos;
    sead::Vector2f                          mPosPrev;
    sead::Vector2f                          mPosBlock;
    sead::Vector2f                          _7c;
    Angle                                   mAngle;
    f32                                     mBaseSpeed;
    u8                                      mType;          // See Type
    u8                                      mLayer;
    u8                                      mDir;
    bool                                    _8f;            // Set, but never read
};
static_assert(sizeof(LineMgr) == 0x90);
