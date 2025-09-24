#pragma once

#include <graphics/Mii_SlotID.h>
#include <player/PlayerModel.h>
#include <player/PlayerModelBaseMgr.h>

#include <heap/seadHeap.h>

class PlayerModelMgr : public PlayerModelBaseMgr    // vtbl Address: 0x1016BF00
{
public:
    // Address: 0x02922F3C
    PlayerModelMgr(PlayerModelBase::Type type, PlayerModelBase::SceneType scene_type, s32 player_no, bool override_lightmap = true);
    // Address: 0x02923190
    PlayerModelMgr(PlayerModelBase::Type type, PlayerMode mode, PlayerModelBase::SceneType scene_type, bool override_lightmap = true);
    // Address: 0x02923394
    PlayerModelMgr(PlayerMode mode, PlayerCharacter mii_color, const Mii::SlotID& slot_id, sead::Heap* p_ffl_tmp_heap, bool override_lightmap = true);

    PlayerMode getPlayerMode()
    {
        return mpModel->getPlayerMode();
    }

    void setPlayerMode(PlayerMode mode)
    {
        mpModel->setPlayerMode(mode);
    }

    bool getHeadPropelJointMtx(sead::Matrixf* p_mtx)
    {
        return mpModel->getHeadPropelJointMtx(p_mtx);
    }

    bool checkChange_MusaPtoNml()
    {
        return mpModel->checkChange_MusaPtoNml();
    }

    void postChange_MusaPtoNml()
    {
        mpModel->postChange_MusaPtoNml();
    }

    bool isFaceRot()
    {
        return mpModel->isFaceRot();
    }

    void setClampFaceRot()
    {
        mpModel->setClampFaceRot();
    }

    void setColorType(PlayerModel::ColorType color_type, bool keep_head_konst3)
    {
        mpModel->setColorType(color_type, keep_head_konst3);
    }

    void setMiiColor(PlayerCharacter mii_color)
    {
        mpModel->setMiiColor(mii_color);
    }

    void setCapMode(PlayerModelBase::CapMode mode) override
    {
        mpModel->setCapMode(mode);
    }

    void setMusaPtoNmlAnm()
    {
        mpModel->setMusaPtoNmlAnm();
    }

    virtual void setMiiCapVisible(bool visible)
    {
        mpModel->setMiiCapVisible(visible);
    }

    virtual bool isMiiCapVisible()
    {
        return mpModel->isMiiCapVisible();
    }

    void setPropelRollAngle(const Angle& angle)
    {
        mpModel->setPropelRollAngle(angle);
    }

    void setPropelRollSpeed(const Angle& speed)
    {
        mpModel->setPropelRollSpeed(speed);
    }

    void setPropelScale(f32 scale)
    {
        mpModel->setPropelScale(scale);
    }

    AnimModel* getBodyModel(PlayerModeModel mode_mdl)
    {
        return mpModel->getBodyModel(mode_mdl);
    }

    AnimModel* getHeadModel(PlayerModeModel mode_mdl)
    {
        return mpModel->getHeadModel(mode_mdl);
    }

private:
    PlayerModel*    mpModel;
};
static_assert(sizeof(PlayerModelMgr) == 0x10);
