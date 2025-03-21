#pragma once

#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>

class SelectCursor
{
    // createInstance()                             Address: 0x024C635C
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D17A8
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024C6930
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D17AC
    // SingletonDisposer_::vtbl                     Address: 0x100B8600
    SEAD_SINGLETON_DISPOSER(SelectCursor)

public:
    // Address: 0x024C6298
    SelectCursor();

    // Address: 0x024C63E0
    void create();

    // Address: 0x024C6500
    void execute();

    // Address: 0x024C65A0
    void draw(const agl::lyr::RenderInfo& render_info) const;

    // Address: 0x024C6680
    void drawDRC(const agl::lyr::RenderInfo& render_info) const;

private:
    sead::SafeArray<
        u32[0xECC / sizeof(u32)],   // SelectCursorLayout
        24
    > mLayout;
    sead::SafeArray<
        u32[0xEC8 / sizeof(u32)],   // SelectCursorMiniLayout
        24
    > mMiniLayout;
    u32                             _2c5f0;
    u8                              _2c5f4;
};
static_assert(sizeof(SelectCursor) == 0x2C5F8);
