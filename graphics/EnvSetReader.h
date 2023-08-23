#pragma once

#include <prim/seadSafeString.h>

namespace sead {

class ReadStream;

}

class EnvSetReader
{
public:
    // Address: 0x024DD29C
    static void read(const sead::SafeString& path, sead::Heap* heap = nullptr);

private:
    // Address: 0x024DD1C0
    static void read_(sead::ReadStream& stream, sead::Heap* heap);
};
