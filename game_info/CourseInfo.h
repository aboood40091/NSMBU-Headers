#pragma once

#include <heap/seadDisposer.h>

class CourseInfo
{
    // createInstance()                             Address: 0x024D2884
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D18EC
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024D3F08
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D18F0
    // SingletonDisposer_::vtbl                     Address: 0x100B9AA8
    SEAD_SINGLETON_DISPOSER(CourseInfo)

public:
    // Address: 0x024D281C
    CourseInfo();

    u8 getWorldNo() const { return mCourseNow.world_no; }
    u8 getCourseNo() const { return mCourseNow.course_no; }
    u8 getFileNo() const { return mCourseNow.file_no; }
    u8 getNextGotoNo() const { return mCourseNow.next_goto_no; }
    u32 getAreaNo() const { return mCourseNow.area_no; }
    u32 getSceneEnterType() const { return mCourseNow.scene_enter_type; }

    // Address: 0x024D293C
    void setNextWorldNo(u8);
    // Address: 0x024D2954
    void setNextCourseNo(u8);
    // Address: 0x024D296C
    void setNextFileNo(u8);
    // Address: 0x024D2984
    void setNextNextGotoNo(u8);
    // Address: 0x024D299C
    void setNextSceneEnterType(u32);

    // Address: 0x024D3910
    bool isShortPlay() const;

    // Address: 0x024D3940
    bool isTitle() const;

private:
    struct
    {
        u8  world_no;
        u8  course_no;
        u8  file_no;
        u8  next_goto_no;
        u32 area_no;
        u32 scene_enter_type;
    }   mCourseNow;
    struct
    {
        u8  world_no;
        u8  course_no;
        u8  file_no;
        u8  next_goto_no;
        u32 scene_enter_type;
    }   mCourseNext;
};
static_assert(sizeof(CourseInfo) == 0x24);
