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

class ActorCreateIndexFindFunc : public ActorFindFunc
{
public:
    ActorCreateIndexFindFunc(u32 index)
        : mCreateIndex(index)
    {
    }

    virtual bool operator()(const ActorBase& actor);

private:
    u32 mCreateIndex;
};
static_assert(sizeof(ActorCreateIndexFindFunc) == 8);
