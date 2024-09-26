#pragma once
#include "scene.h"

#define ELSIE_BANK SWITCH_ROM(4)
#define ELSIE_BG \
    ELSIE_BANK;  \
    init_bg_elsie_bo4();
#define ELSIE_DREAMING init_sp_elsie_dreaming_bo4();
#define ELSIE_SMILE init_sp_elsie_smile_bo4();
#define ELSIE_ECSTATIC init_sp_elsie_ecstatic_bo4();
#define ELSIE_THINKING init_sp_elsie_thinking_bo4();
#define ELSIE_READING init_sp_elsie_reading_bo4();
#define ELSIE_SIGH init_sp_elsie_sigh_bo4();
#define ELSIE_FILL fill_bkg_rect(12, 4, 8, 14, 254);
#define ELSIE_BG_END 115
#define INIT_ELSIE_EXPRESSION(expression_var) \
    ELSIE_BANK;                               \
    switch (expression_var)                   \
    {                                         \
    case ExpressionID_Smile:                  \
        ELSIE_SMILE                           \
        break;                                \
    case ExpressionID_Ecstatic:               \
        ELSIE_ECSTATIC                        \
        break;                                \
    case ExpressionID_Thinking:               \
        ELSIE_THINKING                        \
        break;                                \
    case ExpressionID_Dreaming:               \
        ELSIE_DREAMING                        \
        break;                                \
    case ExpressionID_Reading:                \
        ELSIE_READING                         \
        break;                                \
    case ExpressionID_Sigh:                   \
        ELSIE_SIGH                            \
        break;                                \
    }

SCENE_BKG_HEADER(bg_elsie_bo4)
SCENE_SPRITE_HEADER(sp_elsie_dreaming_bo4)
SCENE_SPRITE_HEADER(sp_elsie_ecstatic_bo4)
SCENE_SPRITE_HEADER(sp_elsie_smile_bo4)
SCENE_SPRITE_HEADER(sp_elsie_thinking_bo4)
SCENE_SPRITE_HEADER(sp_elsie_reading_bo4)
SCENE_SPRITE_HEADER(sp_elsie_sigh_bo4)