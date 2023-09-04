#pragma once

#include <actor/ActorUniqueID.h>
#include <utility/Angle.h>

#include <math/seadVector.h>
#include <prim/seadMemUtil.h>

struct ActorParamEx0
{
    // It is a mystery whether this struct/union originally existed or not,
    // but it would be quite difficult to manage this data without it.

    union
    {
        struct
        {
            u8  _0;
            u8  _1;
            u8  _2;
        }   general;
        struct
        {
            u8  layer;
            u8  event_id_0;
            u8  event_id_1;
        }   course;
        struct
        {
            u8  world_sub_letter;
            u8  _1;
            u8  world;
        }   course_select;
    };

    ActorParamEx0()
    {
    }

    ActorParamEx0(const ActorParamEx0& param)
    {
        general._0 = param.general._0;
        general._1 = param.general._1;
        general._2 = param.general._2;
    }

    ActorParamEx0& operator=(const ActorParamEx0& param)
    {
        general._0 = param.general._0;
        general._1 = param.general._1;
        general._2 = param.general._2;
        return *this;
    }
};
static_assert(sizeof(ActorParamEx0) == 3);

struct ActorParamEx1
{
    // It is a mystery whether this struct/union originally existed or not,
    // but it would be quite difficult to manage this data without it.

    union
    {
        struct
        {
            u8  _0;
            u8  _1;
            u8  _2;
        }   general;
        struct
        {
            u8  movement_id;
            u8  link_id;
            u8  init_state_flag;
        }   course;
        struct
        {
            u8  node_id;
            u8  _1;
            u8  _2;
        }   course_select;
    };

    ActorParamEx1()
    {
    }

    ActorParamEx1(const ActorParamEx1& param)
    {
        general._0 = param.general._0;
        general._1 = param.general._1;
        general._2 = param.general._2;
    }

    ActorParamEx1& operator=(const ActorParamEx1& param)
    {
        general._0 = param.general._0;
        general._1 = param.general._1;
        general._2 = param.general._2;
        return *this;
    }
};
static_assert(sizeof(ActorParamEx1) == 3);

class Profile;

struct ActorCreateParam
{
    u32             param_0;
    u32             param_1;
    ActorUniqueID   parent_id;
    Profile*        p_profile;
    sead::Vector3f  position;
    Angle           angle;
    ActorParamEx0   param_ex_0;
    u8              _pad1[1];
    ActorParamEx1   param_ex_1;
    u8              _pad2[1];
    u8*             _28;

    ActorCreateParam()
    {
        sead::MemUtil::fillZero(this, sizeof(ActorCreateParam));
    }
};
static_assert(sizeof(ActorCreateParam) == 0x2C);
