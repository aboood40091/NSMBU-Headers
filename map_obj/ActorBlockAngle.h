#pragma once

#include <map_obj/ActorBlockBase.h>

class ActorBlockAngle : public ActorBlockBase
{
    SEAD_RTTI_OVERRIDE(ActorBlockAngle, ActorBlockBase)

public:
    ActorBlockAngle(const ActorCreateParam& param);
    virtual ~ActorBlockAngle() { }

    bool init();

protected:
    s32 draw_() override;

public:
    u8 getContent() override;
    void vf2F4(void*) override;
    void executeBlock() override;
};
static_assert(sizeof(ActorBlockAngle) == sizeof(ActorBlockBase));
