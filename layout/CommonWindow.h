#pragma once

class CommonWindowMgr;

class CommonWindow  // vtbl Address: 0x100CCD58
{
public:
    // Address: 0x02585958
    CommonWindow();
    // Address: 0x02585B90
    virtual ~CommonWindow();

protected:
    u32 _0[0x1AB8 / sizeof(u32)];

    friend class CommonWindowMgr;
};
static_assert(sizeof(CommonWindow) == 0x1ABC);
