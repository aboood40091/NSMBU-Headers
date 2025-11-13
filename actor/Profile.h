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
        cFlag_Unknown           = 0x0020,
        cFlag_Unknown2          = 0x0100
    };

    s32 offset_x;           // (X) Offset to be added to the initial actor position
    s32 offset_y;           // (Y) ^^^
    struct
    {
        s32 offset_x;       // (X) Offset to center of the spawn range bounding box
        s32 offset_y;       // (Y) ^^^
        s32 half_size_x;    // (X) Half the size of the spawn range bounding box
        s32 half_size_y;    // (Y) ^^^
    }   spawn_range;
    struct {
        u16 up;
        u16 down;
        u16 left;
        u16 right;
    } cull_range;
    u16 flag;               // See enum Flag

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
        cResType_CourseSelect,
        cResType_Num
    };

    enum Flag
    {
        cFlag_DrawCullCheck = 1 <<  1,
        cFlag_Unk3          = 1 <<  3,
        cFlag_Unk4          = 1 <<  4,
        cFlag_Unk7          = 1 <<  7,
        cFlag_Unk8          = 1 <<  8,
        cFlag_NoLoopPosX    = 1 << 10,
        cFlag_Unk12         = 1 << 12,

        cFlag_None          = 0
    };
    static_assert(sizeof(Flag) == 4);

public:
    friend Flag operator|(const Flag& lhs, const Flag& rhs)
    {
        return (Flag)((u32)lhs | (u32)rhs);
    }

    friend Flag& operator|=(Flag& lhs, const Flag& rhs)
    {
        lhs = lhs | rhs;
        return lhs;
    }

    friend Flag operator&(const Flag& lhs, const Flag& rhs)
    {
        return (Flag)((u32)lhs & (u32)rhs);
    }

    friend Flag& operator&=(Flag& lhs, const Flag& rhs)
    {
        lhs = lhs & rhs;
        return lhs;
    }

    friend Flag operator~(const Flag& val)
    {
        return (Flag)(~(u32)val);
    }

public:
    // Address: 0x02019554
    Profile(ActorFactory factory, s32 id, const sead::SafeString& name, const ActorCreateInfo* p_create_info = nullptr, Flag flag = cFlag_None);

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

    Flag getFlag() const
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
    Flag                    mFlag;

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
