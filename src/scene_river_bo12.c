#pragma bank 12
#include "scene_river_bo12.h"
#include "scene_elsie_bo4.h"
#include "state.h"

#define DRAW_BKG_ANIMATION_RIVER_TEXT_2(frame) DRAW_BKG_ANIMATION(bg_river_delivery_2_text_bo12_##frame, ELSIE_BG_END, 0, 0)
#include "bg_river_delivery_2_text_bo12_1.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(1)
#include "bg_river_delivery_2_text_bo12_2.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(2)
#include "bg_river_delivery_2_text_bo12_3.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(3)
#include "bg_river_delivery_2_text_bo12_4.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(4)
#include "bg_river_delivery_2_text_bo12_5.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(5)
#include "bg_river_delivery_2_text_bo12_6.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(6)
#include "bg_river_delivery_2_text_bo12_7.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(7)
#include "bg_river_delivery_2_text_bo12_8.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(8)
#include "bg_river_delivery_2_text_bo12_9.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(9)
#include "bg_river_delivery_2_text_bo12_10.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(10)
#include "bg_river_delivery_2_text_bo12_11.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(11)
#include "bg_river_delivery_2_text_bo12_12.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(12)
#include "bg_river_delivery_2_text_bo12_13.h"
DRAW_BKG_ANIMATION_RIVER_TEXT_2(13)

enum PersonID river_2_CharacterToShow()
{
    switch(state.current_scene) {
#define PERSON_CASE(frame, person) \
    case SceneID_River_Delivery_2_##frame: \
        return person;
        PERSON_CASE(1, PersonID_Elsie)
        PERSON_CASE(2, PersonID_WitchTrollAfter)
        PERSON_CASE(3, PersonID_WitchTrollAfter)
        PERSON_CASE(4, PersonID_WitchZombie)
        PERSON_CASE(5, PersonID_WitchZombie)
        PERSON_CASE(6, PersonID_WitchZombie)
        PERSON_CASE(7, PersonID_WitchZombie)
        PERSON_CASE(8, PersonID_WitchZombie)
        PERSON_CASE(9, PersonID_WitchZombie)
        PERSON_CASE(10, PersonID_WitchZombie)
        PERSON_CASE(11, PersonID_WitchZombie)
        PERSON_CASE(12, PersonID_WitchZombie)
        PERSON_CASE(13, PersonID_WitchZombie)
    }
    return PersonID_None;
}
enum ExpressionID river_2_ExpressionToShow()
{
    switch (state.current_scene)
    {
#define EXPRESSION_CASE(num, expression) \
    case SceneID_River_Delivery_2_##num:    \
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
        EXPRESSION_CASE(12, Normal)
        EXPRESSION_CASE(13, Normal)
    }
    return ExpressionID_None;
}
void river_2_ShowText() {
    switch(state.current_scene) {
#define CUTSCENE_CASE(frame) \
    case SceneID_River_Delivery_2_##frame: \
        init_bg_river_delivery_2_text_bo12_##frame(); \
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