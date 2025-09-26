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
    bool draw_() override;

public:
    sead::Vector3f getItemCreatePos() const override;
    void executeBlock() override;
};
static_assert(sizeof(ActorBlockAngle) == sizeof(ActorBlockBase));
