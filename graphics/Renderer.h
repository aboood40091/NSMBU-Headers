#pragma once

#include <graphics/RenderObjLayer.h>

#include <gfx/seadCamera.h>
#include <gfx/seadProjection.h>
#include <layer/aglLayer.h>
#include <layer/aglRenderer.h>
#include <math/seadBoundBox.h>

class   Angle;
class   BasicModel;
class   Model;
class   ModelFFL;
enum    UnitID;

class Renderer
{
    SEAD_SINGLETON_DISPOSER(Renderer)

public:
    enum GatherType
    {
        cGatherType_0 = 0,  // AreaTask
        cGatherType_1,      // CourseSelectTask, DarkCloudDemoScene, GameSetupScene, MultiPlayCourseSelectScene, ResultScene
        cGatherType_2,      // DemoTestScene
        cGatherType_3       // CourseTask, ChallengeResultScene, WithMiiPackSelectScene
    };

public:
    class LayerSetter
    {
    public:
        LayerSetter(s32 layer_id, GatherType type)
        {
            Renderer::instance()->setLayer(sead::DynamicCast<RenderObjLayerBase>(agl::lyr::Renderer::instance()->getLayer(layer_id)), type);
        }

        LayerSetter(RenderObjLayerBase* p_layer, GatherType type)
        {
            Renderer::instance()->setLayer(p_layer, type);
        }

        ~LayerSetter()
        {
            Renderer::instance()->resetLayer();
        }
    };

public:
    Renderer();
    ~Renderer();

    void setViewBoundBox(const sead::BoundBox2f& box);

    void calcForAreaTask();

    void setLayer(agl::lyr::Layer* p_layer, GatherType type);
    void resetLayer();

    void drawModel(Model* p_model);
    void drawModel(const BasicModel* p_model);
    void drawModel(ModelFFL* p_model);

    void drawActorBgUnit(UnitID unit, const sead::Vector3f& pos, Angle angle, const sead::Vector3f& scale);
    void drawActorBgUnitLayer0(UnitID unit, const sead::Vector3f& pos, Angle angle, const sead::Vector3f& scale);

private:
    sead::BoundBox2f        mViewBoundBox;
    sead::OrthoProjection   mProjection3D;
    sead::OrthoCamera       mCamera3D;
    RenderObjLayerBase*     mpLayer;
    s32                     mDefaultOpaBufferIdx;
    s32                     mDefaultXluBufferIdx;
    sead::OrthoProjection   mProjectionFinalKoopa;
    sead::OrthoCamera       mCameraFinalKoopa;
};
static_assert(sizeof(Renderer) == 0x234);
