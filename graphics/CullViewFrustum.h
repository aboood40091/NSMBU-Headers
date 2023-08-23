#pragma once

#include <container/seadSafeArray.h>
#include <math/seadVector.h>

#include <nw/g3d/g3d_ShapeObj.h>

namespace sead {

class Camera;
class PerspectiveProjection;

}

class CullViewFrustum
{
    struct Sub
    {
        Sub()
            : _0(sead::Vector3f::ex)
            , _c(0.0f)
        {
        }

        sead::Vector3f  _0;
        f32             _c;
    };
    static_assert(sizeof(Sub) == 0x10);

public:
    // Address: 0x024D78A4
    CullViewFrustum();

    nw::g3d::ViewVolume& getViewVolume() { return mViewVolume; }
    const nw::g3d::ViewVolume& getViewVolume() const { return mViewVolume; }

    // Address: 0x024D7910
    void update(const sead::Camera& camera, const sead::PerspectiveProjection& projection);

    // Address: 0x024D7D8C
    bool testIntersectionSphere(const sead::Vector3f& pos, f32 radius) const;   // I think
    // Address: 0x024D7DDC
    bool testIntersectionAABB(const sead::Vector3f& min, const sead::Vector3f& max) const;

private:
    sead::UnsafeArray<Sub, 4>   _0;
    nw::g3d::ViewVolume         mViewVolume;
};
static_assert(sizeof(CullViewFrustum) == 0xC0);
