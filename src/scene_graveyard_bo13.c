#pragma bank 13
#include "scene_graveyard_bo13.h"
#include "scene_elsie_bo4.h"
#include "state.h"

#define DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(frame) DRAW_BKG_ANIMATION(bg_graveyard_delivery_1_text_bo13_##frame, ELSIE_BG_END, 0, 0)
#include "bg_graveyard_delivery_1_text_bo13_1.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(1)
#include "bg_graveyard_delivery_1_text_bo13_2.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(2)
#include "bg_graveyard_delivery_1_text_bo13_3.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(3)
#include "bg_graveyard_delivery_1_text_bo13_4.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(4)
#include "bg_graveyard_delivery_1_text_bo13_5.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(5)
#include "bg_graveyard_delivery_1_text_bo13_6.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(6)
#include "bg_graveyard_delivery_1_text_bo13_7.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(7)
#include "bg_graveyard_delivery_1_text_bo13_8.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(8)
#include "bg_graveyard_delivery_1_text_bo13_9.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(9)
#include "bg_graveyard_delivery_1_text_bo13_10.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(10)
#include "bg_graveyard_delivery_1_text_bo13_11.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(11)
#include "bg_graveyard_delivery_1_text_bo13_12.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(12)
#include "bg_graveyard_delivery_1_text_bo13_13.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(13)
#include "bg_graveyard_delivery_1_text_bo13_14.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(14)
#include "bg_graveyard_delivery_1_text_bo13_15.h"
DRAW_BKG_ANIMATION_GRAVEYARD_TEXT_1(15)

enum PersonID graveyard_1_CharacterToShow()
{
    switch(state.current_scene) {
#define PERSON_CASE(frame, person) \
    case SceneID_Graveyard_Delivery_1_##frame: \
        return person;
        PERSON_CASE(1, PersonID_Elsie)
        PERSON_CASE(2, PersonID_WitchZombie)
        PERSON_CASE(3, PersonID_WitchZombie)
        PERSON_CASE(4, PersonID_Elsie)
        PERSON_CASE(5, PersonID_WitchZombie)
        PERSON_CASE(6, PersonID_WitchNormal)
        PERSON_CASE(7, PersonID_WitchNormal)
        PERSON_CASE(8, PersonID_WitchNormal)
        PERSON_CASE(9, PersonID_WitchNormal)
        PERSON_CASE(10, PersonID_WitchNormal)
        PERSON_CASE(11, PersonID_Elsie)
        PERSON_CASE(12, PersonID_WitchNormal)
        PERSON_CASE(13, PersonID_Elsie)
        PERSON_CASE(14, PersonID_Elsie)
        PERSON_CASE(15, PersonID_Elsie)
    }
    return PersonID_None;
}
enum ExpressionID graveyard_1_ExpressionToShow()
{
    switch (state.current_scene)
    {
#define EXPRESSION_CASE(num, expression) \
    case SceneID_Graveyard_Delivery_1_##num:    \
        return ExpressionID_##expression;
        EXPRESSION_CASE(1, Sigh)
        EXPRESSION_CASE(2, Normal)
        EXPRESSION_CASE(3, Normal)
        EXPRESSION_CASE(4, Sigh)
        EXPRESSION_CASE(5, Normal)
        EXPRESSION_CASE(6, Normal)
        EXPRESSION_CASE(7, Normal)
        EXPRESSION_CASE(8, Normal)
        EXPRESSION_CASE(9, Normal)
        EXPRESSION_CASE(10, Normal)
        EXPRESSION_CASE(11, Sigh)
        EXPRESSION_CASE(12, Normal)
        EXPRESSION_CASE(13, Sigh)
        EXPRESSION_CASE(14, Sigh)
        EXPRESSION_CASE(15, Sigh)
    }
    return ExpressionID_None;
}
void graveyard_1_ShowText() {
    switch(state.current_scene) {
#define CUTSCENE_CASE(frame) \
    case SceneID_Graveyard_Delivery_1_##frame: \
        init_bg_graveyard_delivery_1_text_bo13_##frame(); \
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
    }
}