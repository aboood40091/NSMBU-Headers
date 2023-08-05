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
struct ActorInitArg;
class ModelResource;

typedef ActorBase* (*ClassInit)(const ActorInitArg&);

class Profile
{
public:
    static const u32 cNum = ProfileID::cNum;

public:
    enum ResLoadAt
    {
        cResLoadAt_Boot = 0,
        cResLoadAt_Course,
        cResLoadAt_CourseSelect
    };

public:
    Profile(ClassInit p_class_init, u32 id, const sead::SafeString& name, const ActorCreateInfo* p_create_info, u32 flag);

    ClassInit getClassInit() const
    {
        return mpClassInit;
    }

    u32 getID() const
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

    void loadRes(sead::Heap* heap);
    void unloadRes(sead::Heap* heap);
    ModelResource* getRes(u32 index) const;

    static Profile* get(u32 id);

    static s16 getDrawPriority(u32 id);
    static ResLoadAt getResLoadAt(u32 id);
    static u8 getResNum(u32 id);
    static const sead::SafeString* getResList(u32 id);

protected:
    ClassInit               mpClassInit;
    u32                     mID;
    const ActorCreateInfo*  mpActorCreateInfo;
    bool                    mIsResLoaded;
    u32                     mFlag;

    static sead::SafeArray<Profile*, cNum>  sProfile;

    static const s16                cDrawPriority[cNum];
    static const u8                 cResLoadAt[cNum];
    static const u8                 cResNum[cNum];
    static const sead::SafeString*  cResList[cNum];
};
static_assert(sizeof(Profile) == 0x14);

/* ----------------------------- Haxx ----------------------------- */

class ProfileHaxx : public Profile
{
public:
    struct ReplaceDrawPriority
    {
        ReplaceDrawPriority(const u32 id, const s16 priority)
        {
            if (id < cNum)
                const_cast<s16*>(cDrawPriority)[id] = priority;
        }
    };

    struct ReplaceResLoadAt
    {
        ReplaceResLoadAt(const u32 id, const u8 res_load_at)
        {
            if (id < cNum)
                const_cast<u8*>(cResLoadAt)[id] = res_load_at;
        }
    };

    struct ReplaceResList
    {
        template <s32 N>
        ReplaceResList(const u32 id, const sead::SafeString (&res_list)[N])
        {
            if (id < cNum)
            {
                const_cast<u8*>(cResNum)[id] = N;
                cResList[id] = res_list;
            }
        }
    };

public:
    static const u32 cNumAll = ProfileID::cNumAll;
    static const u32 cNumCustom = cNumAll - cNum;

public:
    static u32 getProfileNumAll();

private:
    static sead::SafeArray<Profile*, cNumCustom>    sProfileCustom;

    static const s16                cDrawPriorityCustom[cNumCustom];
    static const u8                 cResLoadAtCustom[cNumCustom];
    static const u8                 cResNumCustom[cNumCustom];
    static const sead::SafeString*  cResListCustom[cNumCustom];

    friend class Profile;
};
static_assert(sizeof(ProfileHaxx) == sizeof(Profile));
