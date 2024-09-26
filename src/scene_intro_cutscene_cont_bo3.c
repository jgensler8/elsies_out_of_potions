#pragma bank 3
#include "scene_intro_cutscene_cont_bo3.h"
#include "scene_elsie_bo4.h"
#include "state.h"

#define DRAW_BKG_ANIMATION_CUTSCENE(frame) DRAW_BKG_ANIMATION(bg_intro_cutscene_cont_bo3_##frame, ELSIE_BG_END, 0, 0)
#include "bg_intro_cutscene_cont_bo3_1.h"
DRAW_BKG_ANIMATION_CUTSCENE(1)
#include "bg_intro_cutscene_cont_bo3_2.h"
DRAW_BKG_ANIMATION_CUTSCENE(2)
#include "bg_intro_cutscene_cont_bo3_3.h"
DRAW_BKG_ANIMATION_CUTSCENE(3)
#include "bg_intro_cutscene_cont_bo3_4.h"
DRAW_BKG_ANIMATION_CUTSCENE(4)
#include "bg_intro_cutscene_cont_bo3_5.h"
DRAW_BKG_ANIMATION_CUTSCENE(5)
#include "bg_intro_cutscene_cont_bo3_6.h"
DRAW_BKG_ANIMATION_CUTSCENE(6)
#include "bg_intro_cutscene_cont_bo3_7.h"
DRAW_BKG_ANIMATION_CUTSCENE(7)
#include "bg_intro_cutscene_cont_bo3_8.h"
DRAW_BKG_ANIMATION_CUTSCENE(8)
#include "bg_intro_cutscene_cont_bo3_9.h"
DRAW_BKG_ANIMATION_CUTSCENE(9)
#include "bg_intro_cutscene_cont_bo3_10.h"
DRAW_BKG_ANIMATION_CUTSCENE(10)
#include "bg_intro_cutscene_cont_bo3_11.h"
DRAW_BKG_ANIMATION_CUTSCENE(11)
#include "bg_intro_cutscene_cont_bo3_12.h"
DRAW_BKG_ANIMATION_CUTSCENE(12)
#include "bg_intro_cutscene_cont_bo3_13.h"
DRAW_BKG_ANIMATION_CUTSCENE(13)
#include "bg_intro_cutscene_cont_bo3_14.h"
DRAW_BKG_ANIMATION_CUTSCENE(14)
#include "bg_intro_cutscene_cont_bo3_15.h"
DRAW_BKG_ANIMATION_CUTSCENE(15)
#include "bg_intro_cutscene_cont_bo3_16.h"
DRAW_BKG_ANIMATION_CUTSCENE(16)

enum PersonID intro_cont_CharacterToShow()
{
    return PersonID_Elsie;
}
enum ExpressionID intro_cont_ExpressionToShow()
{
    switch (state.current_scene)
    {
#define EXPRESSION_CASE(num, expression) \
    case SceneID_IntroCutscene_c_##num:    \
        return ExpressionID_##expression;
        EXPRESSION_CASE(1, Thinking)
        EXPRESSION_CASE(2, Thinking)
        EXPRESSION_CASE(3, Smile)
        EXPRESSION_CASE(4, Smile)
        EXPRESSION_CASE(5, Reading)
        EXPRESSION_CASE(6, Reading)
        EXPRESSION_CASE(7, Reading)
        EXPRESSION_CASE(8, Reading)
        EXPRESSION_CASE(9, Reading)
        EXPRESSION_CASE(10, Reading)
        EXPRESSION_CASE(11, Reading)
        EXPRESSION_CASE(12, Reading)
        EXPRESSION_CASE(13, Reading)
        EXPRESSION_CASE(14, Smile)
        EXPRESSION_CASE(15, Smile)
        EXPRESSION_CASE(16, Ecstatic)
    }
    return ExpressionID_None;
}
void intro_cont_ShowText() {
    switch(state.current_scene) {
#define CUTSCENE_CASE(frame) \
    case SceneID_IntroCutscene_c_##frame: \
        init_bg_intro_cutscene_cont_bo3_##frame(); \
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
        CUTSCENE_CASE(15)
        CUTSCENE_CASE(16)
    }
}