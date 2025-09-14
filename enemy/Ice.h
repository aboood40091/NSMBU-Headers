#pragma once

#include <actor/ActorState.h>

class Ice : public ActorState
{
    // getRuntimeTypeInfoStatic()::typeInfo initialization guard variable   Address: 0x101E9CAC
    // getRuntimeTypeInfoStatic()::typeInfo                                 Address: 0x101E9CB0
    SEAD_RTTI_OVERRIDE(Ice, ActorState)

public:
    // Address: 0x02372800
    void breakReq(s32 direction, s32 player_no);

    void breakReq(const Actor& actor)
    {
        breakReq(mPos.x < actor.getPos().x ? cDirType_Left : cDirType_Right, actor.getPlayerNo());
    }
};
