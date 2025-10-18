#pragma once

#include <container/seadStrTreeMap.h>
#include <heap/seadDisposer.h>
#include <prim/seadSafeString.h>

class ModelResource;

class ModelResourceMgr
{
    // createInstance()                             Address: 0x024F5EF4
    // deleteInstance()                             Address: Deleted
    // sInstance                                    Address: 0x101D2D50
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x024F7348
    // SingletonDisposer_::sStaticDisposer          Address: 0x101D2D54
    // SingletonDisposer_::vtbl                     Address: 0x100BD354
    SEAD_SINGLETON_DISPOSER(ModelResourceMgr)

private:
    class ModelResourceHolder : public sead::IDisposer  // vtbl Address: 0x100BD364
    {
    public:
        // Address: 0x024F5F88
        ModelResourceHolder(const sead::SafeString& key, ModelResource* p_mdl_res);

        virtual ~ModelResourceHolder()
        {
            if (ModelResourceMgr::instance() != nullptr)
                ModelResourceMgr::instance()->remove(mKey);
        }

    private:
        sead::FixedSafeString<32>   mKey;
        ModelResource*              mpModelResource;

        friend class ModelResourceMgr;
    };
    static_assert(sizeof(ModelResourceHolder) == 0x40);

public:
    // Address: 0x024F5E4C
    ModelResourceMgr();
    // Address: 0x024F5F74
    ~ModelResourceMgr();

    // Address: 0x024F60EC
    ModelResource* getResource(const sead::SafeString& key) const;

    // Address: 0x024F6140
    bool loadResFile(const sead::SafeString& key, const sead::SafeString& archive_name, sead::Heap* heap = nullptr);

    // Address: 0x024F638C
    s32 loadDemoResFile(const sead::SafeString& archive_name, ModelResource** out_mdl_res, s32 mdl_res_max_num, const sead::SafeString& base_key, sead::Heap* heap = nullptr);

    // Address: Deleted
    bool unload(const sead::SafeString& key);

    // Address: Deleted
    void add(const sead::SafeString& key, ModelResource* p_mdl_res, sead::Heap* heap = nullptr);
    // Address: 0x024F72D0
    void remove(const sead::SafeString& key);

private:
    sead::FixedStrTreeMap<32, ModelResourceHolder*, 256>    mResHolderTreeMap;
    u32                                                     _4424;
};
static_assert(sizeof(ModelResourceMgr) == 0x4428);
