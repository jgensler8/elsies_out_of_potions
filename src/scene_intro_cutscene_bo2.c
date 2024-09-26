#pragma bank 2
#include "scene_intro_cutscene_bo2.h"
#include "scene_elsie_bo4.h"
#include "state.h"

#define DRAW_BKG_ANIMATION_CUTSCENE_TEXT(frame) DRAW_BKG_ANIMATION(bg_intro_cutscene_bo2_##frame, ELSIE_BG_END, 0, 0)
#include "bg_intro_cutscene_bo2_1.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(1)
#include "bg_intro_cutscene_bo2_2.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(2)
#include "bg_intro_cutscene_bo2_3.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(3)
#include "bg_intro_cutscene_bo2_4.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(4)
#include "bg_intro_cutscene_bo2_5.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(5)
#include "bg_intro_cutscene_bo2_6.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(6)
#include "bg_intro_cutscene_bo2_7.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(7)
#include "bg_intro_cutscene_bo2_8.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(8)
#include "bg_intro_cutscene_bo2_9.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(9)
#include "bg_intro_cutscene_bo2_10.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(10)
#include "bg_intro_cutscene_bo2_11.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(11)
#include "bg_intro_cutscene_bo2_12.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(12)
#include "bg_intro_cutscene_bo2_13.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(13)
#include "bg_intro_cutscene_bo2_14.h"
DRAW_BKG_ANIMATION_CUTSCENE_TEXT(14)

enum PersonID intro_CharacterToShow()
{
    return PersonID_Elsie;
}
enum ExpressionID intro_ExpressionToShow()
{
    switch (state.current_scene)
    {
#define EXPRESSION_CASE(num, expression) \
    case SceneID_IntroCutscene_##num:    \
        return ExpressionID_##expression;
        EXPRESSION_CASE(1, Smile)
        EXPRESSION_CASE(2, Smile)
        EXPRESSION_CASE(3, Ecstatic)
        EXPRESSION_CASE(4, Thinking)
        EXPRESSION_CASE(5, Thinking)
        EXPRESSION_CASE(6, Ecstatic)
        EXPRESSION_CASE(7, Smile)
        EXPRESSION_CASE(8, Smile)
        EXPRESSION_CASE(9, Thinking)
        EXPRESSION_CASE(10, Thinking)
        EXPRESSION_CASE(11, Thinking)
        EXPRESSION_CASE(12, Thinking)
        EXPRESSION_CASE(13, Smile)
        EXPRESSION_CASE(14, Ecstatic)
    }
    return ExpressionID_None;
}
void intro_ShowText() {
    switch(state.current_scene) {
#define CUTSCENE_CASE(frame) \
    case SceneID_IntroCutscene_##frame: \
        init_bg_intro_cutscene_bo2_##frame(); \
        return;
        CUTSCENE_CASE(1)
        CUTSCENE_CASE(2)
        CUTSCENE_CASE(3)
        CUTSCENE_CASE(4)
        CUTSCENE_CASE(5)
        CUTSCENE_CASE(6)
        CUTSCENE_CASE(7)
        CUTSCENE_CASE(8)
        CUTSCENE_CASE(9)
        CUTSCENE_CASE(10)
        CUTSCENE_CASE(11)
        CUTSCENE_CASE(12)
        CUTSCENE_CASE(13)
        CUTSCENE_CASE(14)
    }
}