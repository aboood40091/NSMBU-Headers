#pragma once

#include <ptcl/seadPtclSystem.h>

class PtclUserShaderCallback
{
public:
    // Address: 0x022AF710
    static void areaLoopDrawOverrideCallback(nw::eft::ShaderDrawOverrideArg& arg);
    // Address: 0x022AF7F0
    static void areaLoopRenderStateSetCallback(nw::eft::RenderStateSetArg& arg);
};
