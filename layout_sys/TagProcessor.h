#pragma once

#include <basis/seadTypes.h>

#include <nw/font/font_TagProcessorBase.h>
#include <nw/lyt/lyt_TextBox.h>

class TagProcessor : public nw::lyt::TextBox::TagProcessor
{
public:
    TagProcessor()
        : mFontSize(1.0f)
    {
    }

protected:
    f32 mFontSize;
};
static_assert(sizeof(TagProcessor) == 0x8);
