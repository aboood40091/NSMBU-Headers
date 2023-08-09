#pragma once

#include <actor/ProfileID.h>

#include <container/seadSafeArray.h>
#include <heap/seadHeap.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>

struct ActorCreateInfo
{
    enum Flag
    {
        cFlag_IgnoreSpawnRange  = 0x0002,
        cFlag_MapObj            = 0x0008,
        cFlag_Grouped           = 0x0010,
        cFlag_Unknown2          = 0x0100
    };

    sead::Vector2i  offset;
    struct
    {
        sead::Vector2i offset;
        sead::Vector2i size;
    }               spawn_range;
    u16             _18;
    u16             _1a;
    u16             _1c;
    u16             _1e;
    u16             flag;

    static const ActorCreateInfo cDefault;
};
static_assert(sizeof(ActorCreateInfo) == 0x24);

class ActorBase;
struct ActorCreateParam;
class ModelResource;

typedef ActorBase* (*ActorFactory)(const ActorCreateParam&);

class Profile
{
public:
    static const u32 cNum = ProfileID::cNum;

public:
    enum ResType
    {
        cResType_Boot = 0,
        cResType_Course,
        cResType_CourseSelect
    };

public:
    Profile(ActorFactory p_actor_factory, s32 id, const sead::SafeString& name, const ActorCreateInfo* p_create_info, u32 flag);

    ActorFactory getActorFactory() const
    {
        return mpActorFactory;
    }

    s32 getID() const
    {
        return mID;
    }

    const ActorCreateInfo& getActorCreateInfo() const
    {
        return *mpActorCreateInfo;
    }

    bool isResLoaded() const
    {
        return mIsResLoaded;
    }

    u32 getFlag() const
    {
        return mFlag;
    }

    void loadResource(sead::Heap* heap);
    void unloadResource(sead::Heap* heap);
    ModelResource* getResource(u32 index) const;

    static Profile* get(s32 id);

    static s16 getDrawPriority(s32 id);
    static ResType getResType(s32 id);
    static u8 getResNum(s32 id);
    static const sead::SafeString* getResList(s32 id);

protected:
    ActorFactory            mpActorFactory;
    s32                     mID;
    const ActorCreateInfo*  mpActorCreateInfo;
    bool                    mIsResLoaded;
    u32                     mFlag;

    static sead::SafeArray<Profile*, cNum>  sProfile;

    static const s16                cDrawPriority[cNum];
    static const u8                 cResType[cNum];
    static const u8                 cResNum[cNum];
    static const sead::SafeString*  cResList[cNum];
};
static_assert(sizeof(Profile) == 0x14);
