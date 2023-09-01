#pragma once

#include <basis/seadTypes.h>

class SndSceneMgr
{
public:
    enum EffectType
    {
                            // NSMBW    | NSMBU (Translated)    | NSMBU (Original)
        cEffect_Soto = 0,   // SOTO     | Outside               | 外
        cEffect_Chika,      // CHIKA    | Underground           | 地下
        cEffect_Chika_S,    // CHIKA_S  | Underground Small     | 小地下           | (S = Small)
        cEffect_Water,      // WATER    | Underwater            | 水中
        cEffect_Boss,       // BOSS     | Boss Room             | ボス部屋
        cEffect_Toride,     // TORIDE   | Fortress / Tower      | 砦
        cEffect_Shiro,      // SHIRO    | Castle                | 城
        cEffect_Obake,      // OBAKE    | Ghost House           | お化け屋敷
        cEffect_Dokan,      // DOKAN    | Painting              | 絵画
        cEffect_Gake,       // GAKE     | Cliff / Mountain      | 崖
        cEffect_House,      // HOUSE    | Small Room            | 小部屋
        cEffect_Chika_Sa,   // CHIKA_SA | Desert Underground    | 砂漠地下          | (Sa = Sabaku)
        cEffect_Boss_Jr,    // BOSS_JR  | Jr. Battle            | Jr.戦
        cEffect_Kurayami,   // KURAYAMI | Darkness Underground  | 暗闇地下
        cEffect_Chika_Ka,   // CHIKA_KA | Lava Underground      | 火山内部          | (Ka = Kazan)
        cEffect_Default     // DEFAULT  | Default (non-course)  | デフォルト（コース以外）
    };
};
