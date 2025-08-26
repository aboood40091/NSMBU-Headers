#pragma once

#include <basis/seadTypes.h>

class MapActor
{
public:
    class Profile
    {
    public:
        Profile(s32 id)
            : mID(id)
        {
        }

    protected:
        s32 mID;
    };

public:
    // Address 0x101ECD8C
    static const Profile    cProfileID[];
};
