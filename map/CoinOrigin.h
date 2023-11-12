#pragma once

#include <utility/Angle.h>

#include <gfx/seadCamera.h>
#include <gfx/seadProjection.h>
#include <heap/seadDisposer.h>
#include <layer/aglDrawMethod.h>

class ModelG3d;

class CoinOrigin : public sead::IDisposer
{
    // createInstance()                             Address: 0x0269873C
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101DB040
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0269928C
    // SingletonDisposer_::sStaticDisposer          Address: 0x101DB044
    // SingletonDisposer_::vtbl                     Address: 0x100E5F74
    SEAD_SINGLETON_DISPOSER(CoinOrigin)

public:
    // Address: 0x02698624
    CoinOrigin();

    // Address: 0x026987C8
    void initialize(sead::Heap* heap = nullptr);

    // Address: 0x02698BEC
    void pushBackDrawMethod();
    // Address: 0x02698DA0
    void removeDrawMethod();

    // Address: 0x02698DB0
    void update();
    // Address: 0x02698DE4
    void draw();

    const Angle& getCoinAngle() const
    {
        return mCoinAngle;
    }

    sead::Vector3u getCoinRotation() const
    {
        return sead::Vector3u(0, mCoinAngle, 0);
    }

private:
    // Address: 0x026988F0
    void calcMdl_();

    // Address: 0x02698EC4
    void apply_(const agl::lyr::RenderInfo& render_info);

private:
    Angle                   mCoinAngle;
    ModelG3d*               mpModelCoin;
    ModelG3d*               mpModelBlueCoin;
    sead::OrthoProjection   mProjection;
    sead::OrthoCamera       mCamera;
    agl::lyr::DrawMethod    mDrawMethod;
};
static_assert(sizeof(CoinOrigin) == 0x170);
