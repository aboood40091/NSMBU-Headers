#pragma once

#include <actor/ActorUniqueID.h>

class GamesceneBase // vtbl Address: 0x100D3C2C
{
public:
    virtual void create()
    {
    }

    virtual void enterScene()
    {
    }

    virtual void execute()
    {
    }

    virtual void vf24()
    {
    }

    virtual void vf2C()
    {
    }

    // Address: 0x025D8EDC
    virtual void setCoinNumText(s32 coin_num);

    virtual void vf3C()
    {
    }

    // Address: Deleted
    virtual void vf44();

    virtual void vf4C()
    {
    }

    virtual void vf54()
    {
    }

    virtual void vf5C()
    {
    }

    // Address: Deleted
    virtual void vf64();

    // Address: 0x025DA288
    void registerActor(ActorUniqueID id);

protected:
    u32 _0[0x14A0 / sizeof(u32)];
};
