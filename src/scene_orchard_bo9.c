#pragma bank 9
#include "scene_orchard_bo9.h"
#include "scene_elsie_bo4.h"
#include "state.h"

#define DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(frame) DRAW_BKG_ANIMATION(bg_orchard_delivery_2_text_bo9_##frame, ELSIE_BG_END, 0, 0)
#include "bg_orchard_delivery_2_text_bo9_1.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(1)
#include "bg_orchard_delivery_2_text_bo9_2.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(2)
#include "bg_orchard_delivery_2_text_bo9_3.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(3)
#include "bg_orchard_delivery_2_text_bo9_4.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(4)
#include "bg_orchard_delivery_2_text_bo9_5.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(5)
#include "bg_orchard_delivery_2_text_bo9_6.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(6)
#include "bg_orchard_delivery_2_text_bo9_7.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(7)
#include "bg_orchard_delivery_2_text_bo9_8.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(8)
#include "bg_orchard_delivery_2_text_bo9_9.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(9)
#include "bg_orchard_delivery_2_text_bo9_10.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(10)
#include "bg_orchard_delivery_2_text_bo9_11.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(11)
#include "bg_orchard_delivery_2_text_bo9_12.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(12)
#include "bg_orchard_delivery_2_text_bo9_13.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(13)
#include "bg_orchard_delivery_2_text_bo9_14.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(14)
#include "bg_orchard_delivery_2_text_bo9_15.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(15)
#include "bg_orchard_delivery_2_text_bo9_16.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_2(16)

enum PersonID orchard_2_CharacterToShow()
{
    switch (state.current_scene)
    {
#define PERSON_CASE(num, person)           \
    case SceneID_Orchard_Delivery_2_##num: \
        return person;
        PERSON_CASE(1, PersonID_Elsie)
        PERSON_CASE(2, PersonID_WitchNormal)
        PERSON_CASE(3, PersonID_WitchNormal)
        PERSON_CASE(4, PersonID_WitchNormal)
        PERSON_CASE(5, PersonID_WitchNormal)
        PERSON_CASE(6, PersonID_WitchNormal)
        PERSON_CASE(7, PersonID_WitchNormal)
        PERSON_CASE(8, PersonID_Elsie)
        PERSON_CASE(9, PersonID_Elsie)
        PERSON_CASE(10, PersonID_WitchNormal)
        PERSON_CASE(11, PersonID_WitchNormal)
        PERSON_CASE(12, PersonID_WitchNormal)
        PERSON_CASE(13, PersonID_Elsie)
        PERSON_CASE(14, PersonID_WitchNormal)
        PERSON_CASE(15, PersonID_WitchNormal)
        PERSON_CASE(16, PersonID_Elsie)
    }
    return PersonID_None;
}
enum ExpressionID orchard_2_ExpressionToShow()
{
    switch (state.current_scene)
    {
#define EXPRESSION_CASE(num, expression)   \
    case SceneID_Orchard_Delivery_2_##num: \
        return ExpressionID_##expression;
        EXPRESSION_CASE(1, Smile)
        EXPRESSION_CASE(2, Normal)
        EXPRESSION_CASE(3, Normal)
        EXPRESSION_CASE(4, Normal)
        EXPRESSION_CASE(5, Normal)
        EXPRESSION_CASE(6, Normal)
        EXPRESSION_CASE(7, Normal)
        EXPRESSION_CASE(8, Smile)
        EXPRESSION_CASE(9, Smile)
        EXPRESSION_CASE(10, Normal)
        EXPRESSION_CASE(11, Normal)
        EXPRESSION_CASE(12, Normal)
        EXPRESSION_CASE(13, Smile)
        EXPRESSION_CASE(14, Normal)
        EXPRESSION_CASE(15, Normal)
        EXPRESSION_CASE(16, Smile)
    }
    return ExpressionID_None;
}
void orchard_2_ShowText()
{
    switch (state.current_scene)
    {
#define CUTSCENE_CASE(frame)                           \
    case SceneID_Orchard_Delivery_2_##frame:           \
        init_bg_orchard_delivery_2_text_bo9_##frame(); \
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