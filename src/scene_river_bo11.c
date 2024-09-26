#pragma bank 11
#include "scene_river_bo11.h"
#include "scene_elsie_bo4.h"
#include "state.h"

#define DRAW_BKG_ANIMATION_RIVER_TEXT_1(frame) DRAW_BKG_ANIMATION(bg_river_delivery_1_text_bo11_##frame, ELSIE_BG_END, 0, 0)
#include "bg_river_delivery_1_text_bo11_1.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(1)
#include "bg_river_delivery_1_text_bo11_2.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(2)
#include "bg_river_delivery_1_text_bo11_3.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(3)
#include "bg_river_delivery_1_text_bo11_4.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(4)
#include "bg_river_delivery_1_text_bo11_5.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(5)
#include "bg_river_delivery_1_text_bo11_6.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(6)
#include "bg_river_delivery_1_text_bo11_7.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(7)
#include "bg_river_delivery_1_text_bo11_8.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(8)
#include "bg_river_delivery_1_text_bo11_9.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(9)
#include "bg_river_delivery_1_text_bo11_10.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(10)
#include "bg_river_delivery_1_text_bo11_11.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(11)
#include "bg_river_delivery_1_text_bo11_12.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(12)
#include "bg_river_delivery_1_text_bo11_13.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_1(13)

enum PersonID river_1_CharacterToShow()
{
    switch(state.current_scene) {
#define PERSON_CASE(frame, person) \
    case SceneID_River_Delivery_1_##frame: \
        return person;
        PERSON_CASE(1, PersonID_Elsie)
        PERSON_CASE(2, PersonID_WitchTrollBefore)
        PERSON_CASE(3, PersonID_WitchTrollBefore)
        PERSON_CASE(4, PersonID_WitchTrollBefore)
        PERSON_CASE(5, PersonID_WitchTrollAfter)
        PERSON_CASE(6, PersonID_WitchTrollAfter)
        PERSON_CASE(7, PersonID_WitchTrollAfter)
        PERSON_CASE(8, PersonID_WitchTrollAfter)
        PERSON_CASE(9, PersonID_WitchTrollAfter)
        PERSON_CASE(10, PersonID_WitchTrollAfter)
        PERSON_CASE(11, PersonID_WitchTrollAfter)
        PERSON_CASE(12, PersonID_Elsie)
        PERSON_CASE(13, PersonID_WitchTrollAfter)
    }
    return PersonID_None;
}
enum ExpressionID river_1_ExpressionToShow()
{
    switch (state.current_scene)
    {
#define EXPRESSION_CASE(num, expression) \
    case SceneID_River_Delivery_1_##num:    \
        return ExpressionID_##expression;
        EXPRESSION_CASE(1, Sigh)
        EXPRESSION_CASE(2, Normal)
        EXPRESSION_CASE(3, Normal)
        EXPRESSION_CASE(4, Normal)
        EXPRESSION_CASE(5, Normal)
        EXPRESSION_CASE(6, Normal)
        EXPRESSION_CASE(7, Normal)
        EXPRESSION_CASE(8, Normal)
        EXPRESSION_CASE(9, Normal)
        EXPRESSION_CASE(10, Normal)
        EXPRESSION_CASE(11, Normal)
        EXPRESSION_CASE(12, Sigh)
        EXPRESSION_CASE(13, Normal)
    }
    return ExpressionID_None;
}
void river_1_ShowText() {
    switch(state.current_scene) {
#define CUTSCENE_CASE(frame) \
    case SceneID_River_Delivery_1_##frame: \
        init_bg_river_delivery_1_text_bo11_##frame(); \
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
    }
}