#pragma once

#include <basis/seadTypes.h>

class ActorBase;

class ActorFindFunc
{
public:
    virtual bool operator()(const ActorBase& actor) = 0;
};
static_assert(sizeof(ActorFindFunc) == 4);

class ActorProfileFindFunc : public ActorFindFunc
{
public:
    ActorProfileFindFunc(s32 id)
        : mProfID(id)
    {
    }

    virtual bool operator()(const ActorBase& actor);

private:
    s32 mProfID;
};
static_assert(sizeof(ActorProfileFindFunc) == 8);

class ActorNearestFindFunc : public ActorFindFunc
{
public:
    ActorNearestFindFunc(u32 id)
        : mID(id)
    {
    }

    virtual bool operator()(const ActorBase& actor);

private:
    u32 mID;
};
static_assert(sizeof(ActorNearestFindFunc) == 8);
