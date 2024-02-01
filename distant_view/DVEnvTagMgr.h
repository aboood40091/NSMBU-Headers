#pragma once

#include <basis/seadTypes.h>

class DistantViewMgr;

class DVEnvTagMgr
{
public:
    // Address: 0x022AA4C0
    DVEnvTagMgr(DistantViewMgr* dv_mgr);

    // Address: 0x022AA4EC
    void initialize(const void* file);

private:
    u8  _0;
};
static_assert(sizeof(DVEnvTagMgr) == 1);
