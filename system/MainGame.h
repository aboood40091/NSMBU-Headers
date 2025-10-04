#pragma once

#include <heap/seadDisposer.h>

enum CourseExitType
{
    cCourseExitType_ChallengeRetry = 0,
    cCourseExitType_Exit,                   // e.g., from Pause menu
    cCourseExitType_Beaten,
    cCourseExitType_Dead,
    cCourseExitType_OtehonReplay,
    cCourseExitType_InsideCourse
};
static_assert(sizeof(CourseExitType) == 4);

enum CourseBeatenType
{
    cCourseBeatenType_Normal = 0,
    cCourseBeatenType_Secret,
    cCourseBeatenType_TreasureChest,
    cCourseBeatenType_TreasureChestFail     // Maybe for when Nabbit steals the treasure chest for idling too long on the ambush??
};
static_assert(sizeof(CourseBeatenType) == 4);

class MainGame
{
    // createInstance()                             Address: 0x029CDCAC
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101E7D7C
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x029CEBF0
    // SingletonDisposer_::sStaticDisposer          Address: 0x101E7D80
    // SingletonDisposer_::vtbl                     Address: 0x1018A110
    SEAD_SINGLETON_DISPOSER(MainGame)

public:
    // Address: 0x029CD2E8
    MainGame();

    // Address: 0x029CEAD4
    void initMiiIconRenderBuffer(sead::Heap* heap = nullptr);

    bool isSinglePlayerDRC() const
    {
        return mIsSinglePlayerDRC;
    }

    bool isMultiplayer() const
    {
        return !mIsSinglePlayerDRC;
    }

    bool isStory() const
    {
        return mIsStory;
    }

    CourseExitType getCourseExitType() const
    {
        return mCourseExitType;
    }

    void setCourseExitType(CourseExitType type)
    {
        mCourseExitType = type;
    }

    CourseBeatenType getCourseBeatenType() const
    {
        return mCourseBeatenType;
    }

    void setCourseBeatenType(CourseBeatenType type)
    {
        mCourseBeatenType = type;
    }

protected:
    u32                 _10;
    bool                mIsSinglePlayerDRC;
    u32                 _18;
    u8                  _1c;
    CourseExitType      mCourseExitType;
    CourseBeatenType    mCourseBeatenType;
    u32                 _28[(0x21DDC - 0x28) / sizeof(u32)];
    u8                  _21ddc[30];
    bool                mIsStory;
    u32                 _21dfc[(0x21E18 - 0x21DFC) / sizeof(u32)];
};
static_assert(sizeof(MainGame) == 0x21E18);
