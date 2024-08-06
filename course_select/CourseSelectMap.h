#pragma once

#include <layout/ChangePlayerNum.h>

#include <heap/seadDisposer.h>

class CourseSelectMap   // vtbl Address: 0x10047B48
{
    // createInstance()                             Address: 0x021F8A40
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101CBE14
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x021FCB3C
    // SingletonDisposer_::sStaticDisposer          Address: 0x101CBE18
    // SingletonDisposer_::vtbl                     Address: 0x10047B38
    SEAD_SINGLETON_DISPOSER(CourseSelectMap)

public:
    // Address: 0x021F8590
    CourseSelectMap();
    // Address: 0x021F8AC4
    virtual ~CourseSelectMap();

    ChangePlayerNum& getChangePlayerNum()
    {
        return mChangePlayerNum;
    }

protected:
    u32             _10[(0x2CC88 - 0x10) / sizeof(u32)];
    ChangePlayerNum mChangePlayerNum;
    u32             _3842c[(0x47820 - 0x3842C) / sizeof(u32)];
};
static_assert(sizeof(CourseSelectMap) == 0x47824);
