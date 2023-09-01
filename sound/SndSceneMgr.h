#pragma once

#include <basis/seadTypes.h>

class SndSceneMgr
{
public:
    enum EffectType
    {
                            // NSMBW    | NSMBU         | NSMBU (Translated)
        cEffect_Soto = 0,   // SOTO     | 外             | Outside
        cEffect_Chika,      // CHIKA    | 地下            | Underground
        cEffect_Chika_S,    // CHIKA_S  | 小地下           | Underground Small
        cEffect_Water,      // WATER    | 水中            | Underwater
        cEffect_Boss,       // BOSS     | ボス部屋          | Boss Room
        cEffect_Toride,     // TORIDE   | 砦             | Fortress / Tower
        cEffect_Shiro,      // SHIRO    | 城             | Castle
        cEffect_Obake,      // OBAKE    | お化け屋敷         | Ghost House
        cEffect_Dokan,      // DOKAN    | 絵画            | Painting
        cEffect_Gake,       // GAKE     | 崖             | Cliff / Mountain
        cEffect_House,      // HOUSE    | 小部屋           | Small Room
        cEffect_Chika_Sa,   // CHIKA_SA | 砂漠地下          | Desert Underground (Sa = Sabaku)
        cEffect_Boss_Jr,    // BOSS_JR  | Jr.戦          | Jr. Battle
        cEffect_Kurayami,   // KURAYAMI | 暗闇地下          | Darkness Underground
        cEffect_Chika_Ka,   // CHIKA_KA | 火山内部          | Lava Underground (Ka = Kazan)
        cEffect_Default     // DEFAULT  | デフォルト（コース以外）  | Default (non-course)
    };
};
