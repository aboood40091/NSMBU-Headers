#pragma once

#include <basis/seadTypes.h>

class PlayerModelBase;

class PlayerModelBaseMgr    // vtbl Address: 0x1016BE5C
{
public:
    // Address: 0x02922A38
    PlayerModelBaseMgr();

    virtual void setCapDrawMode(u32 mode)
    {
    }

protected:
    PlayerModelBase*    mpModelBase;
    u32                 _4;
};
static_assert(sizeof(PlayerModelBaseMgr) == 0xC);
