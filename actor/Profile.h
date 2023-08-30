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

    // Address: 0x100018F4
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
    enum ResType
    {
        cResType_Boot = 0,
        cResType_Course,
        cResType_CourseSelect
    };

public:
    // Address: 0x02019554
    Profile(ActorFactory factory, s32 id, const sead::SafeString& name, const ActorCreateInfo* p_create_info, u32 flag);

    ActorFactory getActorFactory() const
    {
        // SEAD_ASSERT(mFactory);
        return mFactory;
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

    // Address: 0x020195FC
    void loadResource(sead::Heap* heap);
    // Address: 0x020196CC
    void unloadResource(sead::Heap* heap);
    // Address: 0x020196E4
    ModelResource* getResource(u32 index) const;

    // Address: 0x02019774
    static Profile* get(s32 id);

    // Address: 0x02019988
    static s16 getDrawPriority(s32 id);
    // Address: 0x020199A8
    static ResType getResType(s32 id);
    // Address: 0x020199CC
    static u32 getResNum(s32 id);
    // Address: 0x020199EC
    static const sead::SafeString* getResList(s32 id);

protected:
    ActorFactory            mFactory;
    s32                     mID;
    const ActorCreateInfo*  mpActorCreateInfo;
    bool                    mIsResLoaded;
    u32                     mFlag;

    // Address: 0x101ED8DC
    static sead::SafeArray<Profile*, cProfileID_Max>    sProfile;

    // Address: 0x10001940
    static const s16                cDrawPriority[cProfileID_Max];
    // Address: 0x10002064
    static const s8                 cResType[cProfileID_Max];
    // Address: 0x100023F8
    static const u8                 cResNum[cProfileID_Max];
    // Address: 0x101C321C
    static const sead::SafeString*  cResList[cProfileID_Max];
};
static_assert(sizeof(Profile) == 0x14);
