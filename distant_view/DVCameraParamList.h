#pragma once

#include <system/Parameter.h>

class DVCameraParamList : public ParameterListBase
{
public:
    DVCameraParamList()
    {
    }

    // Address: 0x022AA0D0
    void read(const void* file, u32 size) override;

    // Address: 0x022A9ED8
    ParameterBase* getParam(const char* name) const;

private:
    // Address: 0x022A9FD4
    void read_(sead::ReadStream& stream);
};
static_assert(sizeof(DVCameraParamList) == sizeof(ParameterListBase));
